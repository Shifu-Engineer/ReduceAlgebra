//  cslmpi.cpp

//
// Interfaces for mpi from CSL. The bulk of this code was written by
// M O Seymour (1997-98) who has released it for inclusion as part of
// this Lisp system.
//

/**************************************************************************
 * Copyright (C) 2015, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/


// $Id$

#include "headers.h"



#ifdef USE_MPI

#include "mpipack.c"

#define check_fix(v) if (!is_fixnum(v)) return aerror1(fun_name, v)
#define get_arg(v) v = va_arg(a,LispObject)
#define get_fix_arg(v) get_arg(v); check_fix(v); v=int_of_fixnum(v)


/************************ Environmental functions *******************/

// Returns process rank
// (mpi_comm_rank comm)
//
// For now, I assume that comm will fit into a fixnum.
// This appears to be the case with MPICH (values in the hundreds),
// but assumptions like this should not be made.
//
static LispObject Lmpi_comm_rank(LispObject, LispObject comm)
{   int rank;
    static char fun_name[] = "mpi_comm_rank";
    check_fix(comm);
    MPI_Comm_rank(int_of_fixnum(comm),&rank);
    return onevalue(fixnum_of_int(rank));
}

// returns size of communicator
// (mpi_comm_size comm)
//
// Same assumption about comm.
static LispObject Lmpi_comm_size(LispObject, LispObject comm)
{   int size;
    static char fun_name[] = "mpi_comm_size";
    check_fix(comm);
    MPI_Comm_size(int_of_fixnum(comm),&size);
    return onevalue(fixnum_of_int(size));
}

/********************** Blocking point-to-point functions *************/

// Standard blocking send
// (mpi_send message dest tag comm)
// returns nil.
//
//  Same assumption about comm.
static LispObject Lmpi_send(LispObject nil, int nargs, ...)
{   static char fun_name[] = "mpi_send";

    LispObject message;
    int dest,tag,comm;
    va_list a;
    argcheck(nargs,4,fun_name);
    va_start(a,nargs);
    get_arg(message);
    get_fix_arg(dest); get_fix_arg(tag); get_fix_arg(comm);

    pack_object(message);
    MPI_Send(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
             dest, tag, comm);
    free(mpi_pack_buffer);
    return onevalue(nil);
}

// Standard blocking receive
// (mpi_recv source tag comm)
// returns (message (source tag error)).
//
static LispObject Lmpi_recv(LispObject, int nargs, ...)
{   static char fun_name[] = "mpi_recv";

    MPI_Status status;
    int source,tag,comm;
    LispObject Lstatus;
    va_list a;

    argcheck(nargs,3,fun_name);
    va_start(a,nargs);
    get_fix_arg(source); get_fix_arg(tag); get_fix_arg(comm);

    MPI_Probe(source, tag, comm, &status);
    MPI_Get_count(&status, MPI_PACKED, &mpi_pack_size);
    mpi_pack_buffer = (char*)malloc(mpi_pack_size);

    MPI_Recv(mpi_pack_buffer, mpi_pack_size, MPI_PACKED,
             source, tag, comm, &status);

    // The only relevant status things are the 3 public fields, so I'll
    // stick them in a list and return them as the 2nd value
    //
    push(unpack_object());
    free(mpi_pack_buffer);
    Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                    fixnum_of_int(status.MPI_TAG),
                    fixnum_of_int(status.MPI_ERROR));

    return onevalue(list2(my_pop(),Lstatus));
}

// Standard blocking simultaneous send and receive
// (mpi_sendrecv send_message dest send_tag source recv_tag comm)
// returns (recv_message (source recv_tag error))
//
// THERE IS A LIMIT OF 1024 BYTES FOR THE RECEIVE BUFFER (sorry.)
// THIS WILL BE REMOVED ASAP.
//
static LispObject Lmpi_sendrecv(LispObject, int nargs, ...)
{   static char fun_name[] = "mpi_sendrecv";

    MPI_Status status;
    LispObject Lstatus;
    LispObject s_mess;
    int s_tag, r_tag, dest, source, comm;
    char r_buffer[1024];

    va_list a;
    argcheck(nargs,6,fun_name);
    va_start(a,nargs);
    get_arg(s_mess);
    get_fix_arg(dest); get_fix_arg(s_tag);
    get_fix_arg(source); get_fix_arg(r_tag); get_fix_arg(comm);

    pack_object(s_mess);
    MPI_Sendrecv(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
                 dest, s_tag,
                 r_buffer, 1024, MPI_PACKED,
                 source, r_tag, comm, &status);
    free(mpi_pack_buffer);
    mpi_pack_buffer = r_buffer;
    push(unpack_object());
    Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                    fixnum_of_int(status.MPI_TAG),
                    fixnum_of_int(status.MPI_ERROR));

    return onevalue(list2(my_pop(),Lstatus));
}

/************** Non-Blocking point-to-point functions ***********/

// Standard non-blocking send post
// (mpi_isend message dest tag comm)
// returns request handle
//
static LispObject Lmpi_isend(LispObject, int nargs, ...)
{   static char fun_name[] = "mpi_isend";

    LispObject message, request;
    int dest, tag, comm;

    va_list a;

    // For now, we assume type MPI_Request to be 32 bits.
    request = Lmkvect32(nil,fixnum_of_int(2));

    argcheck(nargs,4,fun_name);
    va_start(a,nargs);
    get_arg(message);
    get_fix_arg(dest); get_fix_arg(tag); get_fix_arg(comm);

    pack_object(message);
    MPI_Isend(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
              dest, tag, comm,  (MPI_Request*)&elt(request,0));
    elt(request,1) = (int)mpi_pack_buffer;
    return onevalue(request);
}

// Standard non-blocking receive post
// (mpi_irecv source tag comm)
// returns request handle
//
// I actually cheat horribly by not posting the request at all (at least
// not via MPI), but rather create my own "dummy" request structure.
// Then, to complete the request, I MPI_(I)Probe for a matching message,
// and receive it if it is there.
// This is unsatisfactory since the operation is only non-blocking until the
// first lump of the message arrives; for a long message, there may by
// a lot of latency after this.
//
struct dummy_request
{   int source;
    int tag;
    int comm;
};

static LispObject Lmpi_irecv(LispObject, int nargs, ...)
{   static char fun_name[] = "mpi_irecv";

    int source,tag,comm;
    LispObject request;
    va_list a;
    char* buffer;

    // For now, we assume type MPI_Request to be 32 bits.
    request = Lmkvect32(nil,fixnum_of_int(2));

    argcheck(nargs,3,fun_name);
    va_start(a,nargs);
    get_fix_arg(source); get_fix_arg(tag); get_fix_arg(comm);

    elt(request,1) = 0; // There is no buffer yet
    elt(request,0) = (int)malloc(sizeof(struct dummy_request));
    ((struct dummy_request*)elt(request,0))->source = source;
    ((struct dummy_request*)elt(request,0))->tag = tag;
    ((struct dummy_request*)elt(request,0))->comm = comm;

    return onevalue(request);
}

// Wait to complete operation, and deallocate buffer.
// (mpi_wait request)
// for send, returns nil
// for recv, returns (message (source tag error))
//
static LispObject Lmpi_wait(LispObject nil, LispObject request)
{   MPI_Status status;
    LispObject message, Lstatus;
    if ( !(is_vector(request) && type_of_header(vechdr(request)) == TYPE_VEC32 &&
           length_of_header(vechdr(request)) == 3*CELL) )
        return aerror1("mpi_wait",request);
    if ( elt(request,1))
    {   status.MPI_ERROR = MPI_UNDEFINED;
        mpi_pack_buffer = (void*)elt(request,1);
        MPI_Wait( (MPI_Request*)&elt(request,0), &status);
        if (status.MPI_ERROR == MPI_UNDEFINED)        // i.e. send request
        {   free(mpi_pack_buffer);
            return onevalue(nil);
        }
        else     // old-style receive
        {   push(unpack_object());
            free(mpi_pack_buffer);
            Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                            fixnum_of_int(status.MPI_TAG),
                            fixnum_of_int(status.MPI_ERROR));
            return onevalue(list2(my_pop(),Lstatus));
        }
    }
    else       // new-style receive
    {   int source = ((struct dummy_request*)elt(request,0))->source,
                tag = ((struct dummy_request*)elt(request,0))->tag,
                comm = ((struct dummy_request*)elt(request,0))->comm;
        MPI_Probe(source, tag, comm, &status);
        free((struct dummy_request*)elt(request,0));
        MPI_Get_count(&status, MPI_PACKED, &mpi_pack_size);
        mpi_pack_buffer = (char*)malloc(mpi_pack_size);

        MPI_Recv(mpi_pack_buffer, mpi_pack_size, MPI_PACKED,
                 source, tag, comm, &status);

        // The only relevant status things are the 3 public fields, so I'll
        // stick them in a list and return them as the 2nd value
        //
        push(unpack_object());
        free(mpi_pack_buffer);
        Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                        fixnum_of_int(status.MPI_TAG),
                        fixnum_of_int(status.MPI_ERROR));

        return onevalue(list2(my_pop(),Lstatus));
    }
}


// Test for completion, deallocate buffer if so
// (mpi_test request)
// for send, returns flag
// for recv, returns nil or (message (source tag error))
//
static LispObject Lmpi_test(LispObject nil, LispObject request)
{   MPI_Status status;
    LispObject message, Lstatus;
    int flag;
    if ( !(is_vector(request) && type_of_header(vechdr(request)) == TYPE_VEC32 &&
           length_of_header(vechdr(request)) == 3*CELL) )
        return aerror1("mpi_wait",request);
    if (elt(request,1))
    {   status.MPI_ERROR = MPI_UNDEFINED;
        mpi_pack_buffer = (void*)elt(request,1);
        MPI_Test( (MPI_Request*)&elt(request,0), &flag, &status);
        if (!flag) return onevalue(nil);
        if (status.MPI_ERROR == MPI_UNDEFINED)        // send request
        {   free(mpi_pack_buffer);
            return onevalue(Lispify_predicate(YES));
        }
        else    // old-style receive
        {   push(unpack_object());
            free(mpi_pack_buffer);
            Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                            fixnum_of_int(status.MPI_TAG),
                            fixnum_of_int(status.MPI_ERROR));

            return onevalue(list2(my_pop(),Lstatus));
        }
    }
    else          // new-style receive
    {   int source = ((struct dummy_request*)elt(request,0))->source,
                tag = ((struct dummy_request*)elt(request,0))->tag,
                comm = ((struct dummy_request*)elt(request,0))->comm,   flag;
        MPI_Iprobe(source, tag, comm, &flag, &status);

        if (!flag) return onevalue(nil);

        free((struct dummy_request*)elt(request,0));
        MPI_Get_count(&status, MPI_PACKED, &mpi_pack_size);
        mpi_pack_buffer = (char*)malloc(mpi_pack_size);

        MPI_Recv(mpi_pack_buffer, mpi_pack_size, MPI_PACKED,
                 source, tag, comm, &status);

        // The only relevant status things are the 3 public fields, so I'll
        // stick them in a list and return them as the 2nd value
        //
        push(unpack_object());
        free(mpi_pack_buffer);
        Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                        fixnum_of_int(status.MPI_TAG),
                        fixnum_of_int(status.MPI_ERROR));

        return onevalue(list2(my_pop(),Lstatus));
    }
}

/************** Probe functions *******************/
// Non-blocking probe
// (mpi_iprobe source tag comm)
// returns (flag (source tag error))
//
static LispObject Lmpi_iprobe(LispObject, int nargs, ...)
{   static char fun_name[] = "impi_probe";

    MPI_Status status;
    int source, tag, comm, flag;
    LispObject Lstatus;
    va_list a;

    argcheck(nargs,3,fun_name);
    va_start(a,nargs);
    get_fix_arg(source); get_fix_arg(tag); get_fix_arg(comm);

    MPI_Iprobe(source, tag, comm, &flag, &status);
    Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                    fixnum_of_int(status.MPI_TAG),
                    fixnum_of_int(status.MPI_ERROR));
    return onevalue(list2(Lispify_predicate(flag), Lstatus));
}

// Blocking probe
// (mpi_probe source tag comm)
// returns (source tag error)
//
static LispObject Lmpi_probe(LispObject, int nargs, ...)
{   static char fun_name[] = "mpi_probe";

    MPI_Status status;
    int source, tag, comm;
    LispObject Lstatus;
    va_list a;

    argcheck(nargs,3,fun_name);
    va_start(a,nargs);
    get_fix_arg(source); get_fix_arg(tag); get_fix_arg(comm);

    MPI_Probe(source, tag, comm, &status);
    Lstatus = list3(fixnum_of_int(status.MPI_SOURCE),
                    fixnum_of_int(status.MPI_TAG),
                    fixnum_of_int(status.MPI_ERROR));
    return onevalue(Lstatus);
}

/************** Collective Communications *********/

// Barrier; blocks until all processes have called
// (mpi_barrier comm)
// returns nil
//
static LispObject Lmpi_barrier(LispObject nil, LispObject comm)
{   int rank;
    static char fun_name[] = "mpi_barrier";
    check_fix(comm);
    MPI_Barrier(int_of_fixnum(comm));
    return onevalue(nil);
}

// Broadcast; sends buffer of root to buffers of others.
// (mpi_bcast message root comm)  [message ignored if not root]
// returns message
//
static LispObject Lmpi_bcast(LispObject, int nargs, ...)
{   static char fun_name[] = "mpi_bcast";

    LispObject message;
    int root,comm,rank;
    va_list a;

    argcheck(nargs,3,fun_name);
    va_start(a,nargs);
    get_arg(message); get_fix_arg(root); get_fix_arg(comm);

    MPI_Comm_rank(comm,&rank);
    if (rank == root)
    {   pack_object(message);
        MPI_Bcast(&mpi_pack_position, 1, MPI_LONG, root, comm);
        MPI_Bcast(mpi_pack_buffer, mpi_pack_position, MPI_PACKED, root, comm);
        free(mpi_pack_buffer);
    }
    else
    {   MPI_Bcast(&mpi_pack_size, 1, MPI_LONG, root, comm);
        mpi_pack_buffer = (char*)malloc(mpi_pack_size);
        MPI_Bcast(mpi_pack_buffer, mpi_pack_size, MPI_PACKED, root, comm);
        message = unpack_object();
        free(mpi_pack_buffer);
    }
    return onevalue(message);
}

// Gather: root receives messages from others.
// (mpi_gather message root comm)
// returns vector of messages if root, else nil.
//
static LispObject Lmpi_gather(LispObject, int nargs, ...)
{   static char fun_name[] = "mpi_gather";

    LispObject message;
    int root,comm,rank;
    va_list a;

    argcheck(nargs,3,fun_name);
    va_start(a,nargs);
    get_arg(message); get_fix_arg(root); get_fix_arg(comm);

    MPI_Comm_rank(comm,&rank);
    pack_object(message);
    if (rank == root)
    {   int commsize, count;
        int *recvcounts, *displs;
        char *recvbuffer;

        MPI_Comm_size(comm,&commsize);
        recvcounts = (int*)calloc(commsize, sizeof(int));
        displs = (int*)calloc(commsize+1, sizeof(int));
        MPI_Gather(&mpi_pack_position, 1, MPI_LONG,
                   recvcounts, 1, MPI_LONG, root, comm);

        displs[0] = 0;
        for (count = 0; count < commsize; ++count)
            displs[count+1] = displs[count] + recvcounts[count];

        recvbuffer = (char*)malloc(displs[commsize]);

        MPI_Gatherv(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
                    recvbuffer, recvcounts, displs, MPI_PACKED, root, comm);
        free(mpi_pack_buffer);

        message = Lmkvect(nil, fixnum_of_int(commsize-1));
        for (count = 0; count < commsize; ++count)
        {   mpi_pack_buffer = recvbuffer + displs[count];
            mpi_pack_size = recvcounts[count];
            elt(message, count) = unpack_object();
        }
        free(recvbuffer); free(recvcounts); free(displs);
    }
    else
    {   MPI_Gather(&mpi_pack_position, 1, MPI_LONG, 0, 0, MPI_LONG, root, comm);
        MPI_Gatherv(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
                    0,0,0,MPI_PACKED, root, comm);
        free(mpi_pack_buffer);
        message = nil;
    }
    return onevalue(message);
}

// Scatter: inverse of gather.
// (mpi_scatter vector_of_messages root comm)  [messages ignored if not root]
// returns message
//
static LispObject Lmpi_scatter(LispObject, int nargs, ...)
{   static char fun_name[] = "mpi_scatter";

    LispObject messages, message;
    int root, comm, rank;
    va_list a;

    argcheck(nargs,3,fun_name);
    va_start(a,nargs);
    get_arg(messages); get_fix_arg(root); get_fix_arg(comm);

    MPI_Comm_rank(comm,&rank);
    if (rank == root)
    {   int commsize, count, *sendcounts, *displs, recvcount;
        char* recvbuffer;

        MPI_Comm_size(comm,&commsize);
        sendcounts = (int*)calloc(commsize, sizeof(int));
        displs = (int*)calloc(commsize+1, sizeof(int));
        displs[0] = 0;

        // Call private functions in mpi_packing for consecutive packs
        check_buffer = scatter_check_buffer;
        mpi_pack_offset = 0;
        mpi_pack_position = 0;
        mpi_pack_size = 0;
        mpi_buffer_bottom = 0;
        mpi_real_size = 0;
        for (count = 0; count < commsize; ++count)
        {   pack_cell(elt(messages,count));
            sendcounts[count] = mpi_pack_position;
            mpi_pack_size -= mpi_pack_position;
            mpi_pack_offset += mpi_pack_position;
            mpi_pack_buffer += mpi_pack_position;
            displs[count+1] = mpi_pack_offset;
            mpi_pack_position = 0;
        }
        check_buffer = default_check_buffer;
        MPI_Scatter(sendcounts, 1, MPI_LONG, &recvcount, 1, MPI_LONG, root, comm);
        recvbuffer = (char*)malloc(recvcount);
        MPI_Scatterv(mpi_buffer_bottom, sendcounts, displs, MPI_PACKED,
                     recvbuffer, recvcount, MPI_PACKED, root, comm);
        free(recvbuffer);
        free(sendcounts);
        free(displs);
        free(mpi_buffer_bottom);
        message = elt(messages, root);
    }
    else
    {   MPI_Scatter(0,0,MPI_LONG,&mpi_pack_size,1,MPI_LONG,root,comm);
        mpi_pack_buffer = (char*)malloc(mpi_pack_size);
        MPI_Scatterv(0,0,0,MPI_PACKED,
                     mpi_pack_buffer,mpi_pack_size,MPI_PACKED,root,comm);
        message = unpack_object();
        free(mpi_pack_buffer);
    }
    return onevalue(message);
}


// Allgather: just like gather, only everyone gets the result.
// (mpi_allgather message comm)
// returns vector of messages
//
static LispObject Lmpi_allgather(LispObject,
                                 LispObject message,
                                 LispObject comm)
{   static char fun_name[] = "mpi_gather";
    int commsize, buffersize, count;
    int *recvcounts, *displs;
    char *recvbuffer;

    check_fix(comm);
    comm = int_of_fixnum(comm);

    pack_object(message);

    MPI_Comm_size(comm,&commsize);
    recvcounts = (int*)calloc(commsize, sizeof(int));
    displs = (int*)calloc(commsize+1, sizeof(int));
    MPI_Allgather(&mpi_pack_position, 1, MPI_LONG, recvcounts, 1, MPI_LONG, comm);

    displs[0] = 0;
    for (count = 0; count < commsize; ++count)
        displs[count+1] = displs[count] + recvcounts[count];

    recvbuffer = (char*)malloc(displs[commsize]);

    MPI_Allgatherv(mpi_pack_buffer, mpi_pack_position, MPI_PACKED,
                   recvbuffer, recvcounts, displs, MPI_PACKED, comm);
    free(mpi_pack_buffer); free(recvcounts); free(displs);

    message = Lmkvect(nil, fixnum_of_int(commsize-1));
    for (count = 0; count < commsize; ++count)
    {   mpi_pack_buffer = recvbuffer + displs[count];
        mpi_pack_size = recvcounts[count];
        elt(message, count) = unpack_object();
    }
    free(recvbuffer);
    return onevalue(message);
}

// All to all scatter/gather.
// (mpi_alltoall vector_of_messages comm)
// returns vector of messages.
//
static LispObject Lmpi_alltoall(LispObject,
                                LispObject smessages, LispObject Lcomm)
{   static char fun_name[] = "mpi_alltoall";

    LispObject rmessages;
    int rank,comm, commsize, count;
    int *sendcounts, *recvcounts, *sdispls, *rdispls;
    char* recvbuffer;

    check_fix(Lcomm);
    comm = int_of_fixnum(Lcomm);

    MPI_Comm_size(comm,&commsize);
    sendcounts = (int*)calloc(commsize, sizeof(int));
    recvcounts = (int*)calloc(commsize, sizeof(int));
    sdispls = (int*)calloc(commsize+1, sizeof(int));
    rdispls = (int*)calloc(commsize+1, sizeof(int));

    // Call private functions in mpi_packing for consecutive packs
    check_buffer = scatter_check_buffer;
    mpi_pack_offset = 0;
    mpi_pack_position = 0;
    mpi_pack_size = 0;
    mpi_buffer_bottom = 0;
    mpi_real_size = 0;
    for (count = 0; count < commsize; ++count)
    {   pack_cell(elt(smessages,count));
        sendcounts[count] = mpi_pack_position;
        mpi_pack_size -= mpi_pack_position;
        mpi_pack_offset += mpi_pack_position;
        mpi_pack_buffer += mpi_pack_position;
        sdispls[count+1] = mpi_pack_offset;
        mpi_pack_position = 0;
    }
    check_buffer = default_check_buffer;

    MPI_Comm_rank(comm,&rank);

    MPI_Alltoall(sendcounts, 1, MPI_LONG, recvcounts, 1, MPI_LONG, comm);

    rdispls[0] = 0;
    for (count = 0; count < commsize; ++count)
        rdispls[count+1] = rdispls[count] + recvcounts[count];

    recvbuffer = (char*)malloc(rdispls[commsize]);

    MPI_Alltoallv(mpi_buffer_bottom, sendcounts, sdispls, MPI_PACKED,
                  recvbuffer, recvcounts, rdispls, MPI_PACKED, comm);

    free(mpi_buffer_bottom); free(sendcounts); free(sdispls);

    rmessages = Lmkvect(nil, fixnum_of_int(commsize-1));
    for (count = 0; count < commsize; ++count)
    {   mpi_pack_buffer = recvbuffer + rdispls[count];
        mpi_pack_size = recvcounts[count];
        elt(rmessages, count) = unpack_object();
    }
    free(recvbuffer); free(recvcounts); free(rdispls);
    return onevalue(rmessages);
}

#else  // USE_MPI

static LispObject Lmpi_comm_rank(LispObject, LispObject)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_comm_size(LispObject, LispObject)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_send(LispObject, int, ...)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_recv(LispObject, int, ...)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_sendrecv(LispObject, int, ...)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_isend(LispObject, int, ...)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_irecv(LispObject, int, ...)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_wait(LispObject, LispObject)
{   return aerror0("mpi support not built into this version of CSL");
}


static LispObject Lmpi_test(LispObject, LispObject)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_iprobe(LispObject, int, ...)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_probe(LispObject, int, ...)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_barrier(LispObject, LispObject)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_bcast(LispObject, int, ...)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_gather(LispObject, int, ...)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_scatter(LispObject, int, ...)
{   return aerror0("mpi support not built into this version of CSL");
}


static LispObject Lmpi_allgather(LispObject,
                                 LispObject,
                                 LispObject)
{   return aerror0("mpi support not built into this version of CSL");
}

static LispObject Lmpi_alltoall(LispObject,
                                LispObject, LispObject)
{   return aerror0("mpi support not built into this version of CSL");
}

#endif // USE_MPI


setup_type const mpi_setup[] =
{   {"mpi_comm_rank",         Lmpi_comm_rank, too_many_1,   wrong_no_1},
    {"mpi_comm_size",         Lmpi_comm_size, too_many_1,   wrong_no_1},
    {"mpi_send",              wrong_no_0a,    wrong_no_0b,  Lmpi_send},
    {"mpi_recv",              wrong_no_0a,    wrong_no_0b,  Lmpi_recv},
    {"mpi_sendrecv",          wrong_no_0a,    wrong_no_0b,  Lmpi_sendrecv},
    {"mpi_isend",             wrong_no_0a,    wrong_no_0b,  Lmpi_isend},
    {"mpi_irecv",             wrong_no_0a,    wrong_no_0b,  Lmpi_irecv},
    {"mpi_barrier",           Lmpi_barrier,   too_many_1,   wrong_no_1},
    {"mpi_wait",              Lmpi_wait,      too_many_1,   wrong_no_1},
    {"mpi_test",              Lmpi_test,      too_many_1,   wrong_no_1},
    {"mpi_probe",             wrong_no_0a,    wrong_no_0b,  Lmpi_probe},
    {"mpi_iprobe",            wrong_no_0a,    wrong_no_0b,  Lmpi_iprobe},
    {"mpi_bcast",             wrong_no_0a,    wrong_no_0b,  Lmpi_bcast},
    {"mpi_gather",            wrong_no_0a,    wrong_no_0b,  Lmpi_gather},
    {"mpi_allgather",         wrong_no_0a,    Lmpi_allgather, wrong_no_2},
    {"mpi_scatter",           wrong_no_0a,    wrong_no_0b,  Lmpi_scatter},
    {"mpi_alltoall",          wrong_no_0a,    Lmpi_alltoall, wrong_no_2},
    {NULL,                    0, 0, 0}
};


// end of cslmpi.cpp