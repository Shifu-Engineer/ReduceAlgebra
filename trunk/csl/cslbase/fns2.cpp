// fns2.cpp                                Copyright (C) 1989-2017 Codemist    

//
// Basic functions part 2.
//

/**************************************************************************
 * Copyright (C) 2017, Codemist.                         A C Norman       *
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

// $Id: fns2.cpp 5179 2019-10-31 16:20:08Z arthurcnorman $

#include "headers.h"

LispObject Lget_bps(LispObject env, LispObject n)
{   if (!is_fixnum(n) || (std::intptr_t)n<0) aerror1("get-bps", n);
    std::intptr_t n1 = int_of_fixnum(n);
// Size limited
    n = get_basic_vector(TAG_VECTOR, TYPE_BPS_4, n1+CELL);
    return onevalue(n);
}

void set_fns(LispObject a, no_args *f0, one_arg *f1, two_args *f2, three_args *f3, fourup_args *f4up)
{   if ((qheader(a) & (SYM_C_DEF | SYM_CODEPTR)) ==
        (SYM_C_DEF | SYM_CODEPTR))
    {   if (symbol_protect_flag)
        {   if (warn_about_protected_symbols)
            {   trace_printf("+++ WARNING: protected function ");
                prin_to_trace(a);
                trace_printf(" not redefined\n");
            }
            return;
        }
        else
        {   if (warn_about_protected_symbols)
            {   trace_printf("+++ WARNING: protected function ");
                prin_to_trace(a);
                trace_printf(" *has* been redefined\n");
            }
            Lsymbol_protect(nil, a, nil);
        }
    }
    ifn0(a) = (std::intptr_t)f0;
    ifn1(a) = (std::intptr_t)f1;
    ifn2(a) = (std::intptr_t)f2;
    ifn3(a) = (std::intptr_t)f3;
    ifn4up(a) = (std::intptr_t)f4up;
}

#ifdef HIDE_USELESS_SYMBOL_ENVIRONMENTS

static bool interpreter_entry(LispObject a)
//
// If a function will be handled by the interpreter, including the case
// of it being undefined, then the fn1() cell will tell me so.
//
{   return (   qfn1(a) == interpreted_1 ||
               qfn1(a) == funarged_1 ||
               qfn1(a) == undefined_1);
}

#endif


static const char *c_fn0(no_args *p, setup_type const s[])
{   int i;
    for (i=0; s[i].name!=NULL; i++)
        if (s[i].zero == p) return s[i].name;
    return NULL;
}

static const char *c_fn1(one_arg *p, setup_type const s[])
{   int i;
    for (i=0; s[i].name!=NULL; i++)
        if (s[i].one == p) return s[i].name;
    return NULL;
}

static const char *c_fn2(two_args *p, setup_type const s[])
{   int i;
    for (i=0; s[i].name!=NULL; i++)
        if (s[i].two == p) return s[i].name;
    return NULL;
}

static const char *c_fn3(three_args *p, setup_type const s[])
{   int i;
    for (i=0; s[i].name!=NULL; i++)
        if (s[i].three == p) return s[i].name;
    return NULL;
}

static const char *c_fn4up(fourup_args *p, setup_type const s[])
{   int i;
    for (i=0; s[i].name!=NULL; i++)
        if (s[i].fourup == p) return s[i].name;
    return NULL;
}

static const char *show_fn0(no_args *p)
{   int i;
    const char *r;
    for (i=0; entries_table0[i].s!=NULL; i++)
        if (entries_table0[i].p == p) return entries_table0[i].s;
    for (i=0; setup_tables[i]!=NULL; i++)
        if ((r = c_fn0(p, setup_tables[i])) != NULL) return r;
// There are more entries in setup_tables after the first NULL!
    for (i++; setup_tables[i]!=NULL; i++)
        if ((r = c_fn0(p, setup_tables[i])) != NULL) return r;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

static const char *show_fn1(one_arg *p)
{   int i;
    const char *r;
    for (i=0; entries_table1[i].s!=NULL; i++)
        if (entries_table1[i].p == p) return entries_table1[i].s;
    for (i=0; setup_tables[i]!=NULL; i++)
        if ((r = c_fn1(p, setup_tables[i])) != NULL) return r;
// There are more entries in setup_tables after the first NULL!
    for (i++; setup_tables[i]!=NULL; i++)
        if ((r = c_fn1(p, setup_tables[i])) != NULL) return r;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

static const char *show_fn2(two_args *p)
{   int i;
    const char *r;
    for (i=0; entries_table2[i].s!=NULL; i++)
        if (entries_table2[i].p == p) return entries_table2[i].s;
    for (i=0; setup_tables[i]!=NULL; i++)
        if ((r = c_fn2(p, setup_tables[i])) != NULL) return r;
    for (i++; setup_tables[i]!=NULL; i++)
        if ((r = c_fn2(p, setup_tables[i])) != NULL) return r;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

static const char *show_fn3(three_args *p)
{   int i;
    const char *r;
    for (i=0; entries_table3[i].s!=NULL; i++)
        if (entries_table3[i].p == p) return entries_table3[i].s;
    for (i=0; setup_tables[i]!=NULL; i++)
        if ((r = c_fn3(p, setup_tables[i])) != NULL) return r;
    for (i++; setup_tables[i]!=NULL; i++)
        if ((r = c_fn3(p, setup_tables[i])) != NULL) return r;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

static const char *show_fn4up(fourup_args *p)
{   int i;
    const char *r;
    for (i=0; entries_table4up[i].s!=NULL; i++)
        if (entries_table4up[i].p == p) return entries_table4up[i].s;
    for (i=0; setup_tables[i]!=NULL; i++)
        if ((r = c_fn4up(p, setup_tables[i])) != NULL) return r;
    for (i++; setup_tables[i]!=NULL; i++)
        if ((r = c_fn4up(p, setup_tables[i])) != NULL) return r;
    trace_printf("+++ Unknown function pointer = %p\n", p);
    return "unknown";
}

LispObject Lsymbol_fn_cell(LispObject env, LispObject a)
//
// For debugging... This looks in the 5 function cells that any
// symbol has and attempts to display the name of the function there.
// There are enough tables for me to find the names of MANY things, but I
// do not guarantee everything.
//
{   const char *s0, *s1, *s2, *s3, *s4up;
    if (!symbolp(a)) return onevalue(nil);
    s0 = show_fn0(qfn0(a));
    s1 = show_fn1(qfn1(a));
    s2 = show_fn2(qfn2(a));
    s3 = show_fn3(qfn3(a));
    s4up = show_fn4up(qfn4up(a));
    trace_printf("%s %s %s %s %s\n", s0, s1, s2, s3, s4up);
    return onevalue(nil);
}

// This should show the header of any symbol, any vector or
// any numeric value that has a header... It is JUST for debugging, and it
// prints information but does not return a useful value.

LispObject Lobject_header(LispObject env, LispObject a)
{   if (is_symbol(a))
    {   Header h = qheader(a);
        trace_printf("Symbol: (%" PRIxPTR ") ", h);
        if ((h & SYM_SPECIAL_VAR) != 0)
            if ((h & SYM_GLOBAL_VAR) != 0) trace_printf(" keyword");
            else trace_printf(" fluid");
        else if ((h & SYM_GLOBAL_VAR) != 0) trace_printf(" global");
        if ((h & SYM_SPECIAL_FORM) != 0) trace_printf(" special-form");
        if ((h & SYM_MACRO) != 0) trace_printf(" macro");
        if ((h & SYM_C_DEF) != 0) trace_printf(" C-def");
        if ((h & SYM_CODEPTR) != 0) trace_printf(" codeptr");
        if ((h & SYM_ANY_GENSYM) != 0) trace_printf(" any-gensym");
        if ((h & SYM_TRACED) != 0) trace_printf(" traced");
        if ((h & SYM_TRACESET) != 0) trace_printf(" traceset");
        if ((h & SYM_FASTGET_MASK) != 0) trace_printf(" fastget");
        trace_printf("\n");
    }
    else if (is_vector(a))
    {   Header h = vechdr(a);
        trace_printf("Symbol: (%" PRIxPTR ") ", h);
        trace_printf("Rounded up length in bytes units = %" PRIuPTR "\n",
                     length_of_header(h));
        if (!vector_holds_binary(h))
            trace_printf("Holds %" PRIuPTR " pointers\n",
                         length_of_header(h)/CELL);
        else if (is_bitvec_header(h))
            trace_printf("Bits %" PRIuPTR "\n", length_of_bitheader(h));
        else if (vector_i8(h))
            trace_printf("Bytes %" PRIuPTR "\n", length_of_byteheader(h));
        else if (vector_i16(h))
            trace_printf("Halfwords %" PRIuPTR "\n", length_of_hwordheader(h));
        else if (vector_i32(h))
            trace_printf("32-bit data " PRIuPTR "\n",
                length_of_header(h)/4);
        else if (vector_i64(h))
            trace_printf("64-bit data " PRIuPTR "\n",
                length_of_header(h)/8);
        else if (vector_i128(h))
            trace_printf("128-bit data " PRIuPTR "\n",
                length_of_header(h)/16);
        else if (vector_f32(h))
            trace_printf("32-bit floating point data " PRIuPTR "\n",
                length_of_header(h)/4);
        else if (vector_f64(h))
            trace_printf("64-bit floating point data " PRIuPTR "\n",
                length_of_header(h)/8);
        else if (vector_f128(h))
            trace_printf("128-bit floating point data " PRIuPTR "\n",
                length_of_header(h)/16);
        else trace_printf("Unknown vector type\n");
    }
// I will expand the following two cases if at some stage my debugging needs
// make that important.
    else if (is_numbers(a))
    {   Header h = numhdr(a);
        trace_printf("Number: (%" PRIxPTR ") ", h);
        trace_printf("\n");
    }
    else if (is_bfloat(a))
    {   Header h = flthdr(a);
        trace_printf("Floating point: (%" PRIxPTR ") ", h);
        trace_printf("\n");
    }
    return onevalue(nil);
}

LispObject Lsymbol_argcount(LispObject env, LispObject a)
//
// For debugging use. Only valid if the function involved
// is byte-coded. For simple functions taking a fixed number of args the
// result is an integer. Otherwise it is a list of 3 items
//   (fewest-legal-args most-args-before-&rest flags)
// where the flags has a 1 bit if missing &optional args are to be left
// for the bytecoded stuff to unpick, otherwise they should be mapped to nil
// somewhere. The 2 bit is present if a &rest argument is present.
//
{   no_args *f0;
    one_arg *f1;
    two_args *f2;
    three_args *f3;
    fourup_args *f4up;
    int low, high, hardrest;
    LispObject r;
    unsigned char *b;
    if (!symbolp(a)) return onevalue(nil);
    f0 = qfn0(a);
    f1 = qfn1(a);
    f2 = qfn2(a);
    f3 = qfn3(a);
    f4up = qfn4up(a);
    r = qenv(a);
    if (!consp(r)) return onevalue(nil);
    r = car(r);
    if (!is_bps(r)) return onevalue(nil);
    b = (unsigned char *)data_of_bps(r);
    if (f0 == bytecoded_0 ||
        f0 == f0_as_0
        ) return onevalue(fixnum_of_int(1));
    if (f1 == bytecoded_1 ||
        f1 == f1_as_0 ||
        f1 == f1_as_1
        ) return onevalue(fixnum_of_int(1));
    if (f2 == bytecoded_2 ||
        f2 == f2_as_0 ||
        f2 == f2_as_1 ||
        f2 == f2_as_2
        ) return onevalue(fixnum_of_int(2));
    if (f3 == bytecoded_3 ||
        f3 == f3_as_0 ||
        f3 == f3_as_1 ||
        f3 == f3_as_2 ||
        f3 == f3_as_3
        ) return onevalue(fixnum_of_int(2));
    if (f4up == bytecoded_4up) return onevalue(fixnum_of_int(b[0]));
    low = b[0];          // smallest number of valid args
    high = low + b[1];   // largest number before &rest is accounted for
    hardrest = 0;
// byteopt - optional arguments, with default of NIL
    if (f1 == byteopt_1) hardrest = 0;
// hardopt - optional arguments but default is passed as a SPID so that
// the user can follow up and apply cleverer default processing
    else if (f1 == hardopt_1) hardrest = 1;
// byteoptrest - anything with a &rest argument on the end.
    else if (f1 == byteoptrest_1) hardrest = 1;
// hardoptrest - some &optional args with non-nil default value, plus &rest
    else if (f1 == hardoptrest_1) hardrest = 3;
    else return onevalue(nil);
    r = list3(fixnum_of_int(low),
              fixnum_of_int(high), fixnum_of_int(hardrest));
    return onevalue(r);
}

LispObject Lsymbol_argcode(LispObject env, LispObject a)
//
// This hands back a single integer that encodes what must be in the
// five function cells for anything byte-coded.
// Or nil if the argument did not name a bytecoded function.
//
{
#define BYTE_ARGMASK 0x007    // 0, 1, 2, 3 or 4. 4 means "4 or more"
#define BYTE_OPT     0x008    // &optional present
#define BYTE_HARDOPT 0x010    // "hard" case of &optional
#define BYTE_REST    0x020    // &rest present
//#define BYTE_TRACED  0x040
#define BYTE_CALLAS  0x100    // link to some other function
//
// I can not see any way much better than a grim sequence of explicit
// tests to achieve what I want here.
//
    no_args *f0;
    one_arg *f1;
    two_args *f2;
    three_args *f3;
    fourup_args *f4up;
    LispObject r;
    int val;
    if (!symbolp(a)) return onevalue(nil);
    f0 = qfn0(a);
    f1 = qfn1(a);
    f2 = qfn2(a);
    f3 = qfn3(a);
    f4up = qfn4up(a);
    r = qenv(a);
    if (!consp(r)) return onevalue(nil);
    r = car(r);
    if (!is_bps(r)) return onevalue(nil);
    if (f0 == bytecoded_0) val = 0;
    else if (f1 == bytecoded_1) val = 1;
    else if (f2 == bytecoded_2) val = 2;
    else if (f3 == bytecoded_3) val = 3;
    else if (f4up == bytecoded_4up) val = 4;
    else if (f1 == byteopt_1) val = BYTE_OPT;
    else if (f1 == hardopt_1) val = BYTE_HARDOPT;
    else if (f1 == byteoptrest_1) val = BYTE_OPT + BYTE_REST;
    else if (f1 == hardoptrest_1) val = BYTE_HARDOPT + BYTE_REST;
    else if (f3 == f3_as_0) val = BYTE_CALLAS + 0;
    else if (f3 == f3_as_1) val = BYTE_CALLAS + 1;
    else if (f3 == f3_as_2) val = BYTE_CALLAS + 2;
    else if (f3 == f3_as_3) val = BYTE_CALLAS + 3;
    else if (f0 == f0_as_0) val = BYTE_CALLAS + 4;
    else if (f2 == f2_as_0) val = BYTE_CALLAS + 5;
    else if (f2 == f2_as_1) val = BYTE_CALLAS + 6;
    else if (f2 == f2_as_2) val = BYTE_CALLAS + 7;
// The next two intrude on the BYTE_OPT bit-position...
    else if (f1 == f1_as_0) val = BYTE_CALLAS + 8;
    else if (f1 == f1_as_1) val = BYTE_CALLAS + 9;
    else return onevalue(nil);
    return onevalue(fixnum_of_int(val));
}

LispObject Lsymbol_env(LispObject env, LispObject a)
//
// Not Common Lisp - read the 'environment' cell associated with a
// symbol.  This cell is deemed empty unless the symbol-function is
// compiled code.  For use mainly for debugging.
//
{   if (!symbolp(a)) return onevalue(nil);
#ifdef HIDE_USELESS_SYMBOL_ENVIRONMENTS
    else if ((qheader(a) & (SYM_SPECIAL_FORM | SYM_MACRO)) != 0 ||
             interpreter_entry(a)) return onevalue(nil);
#endif
    return onevalue(qenv(a));
}

LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b)
{   if (!is_symbol(a)) aerror1("symbol-set-env", a);
    if ((qheader(a) & (SYM_C_DEF | SYM_CODEPTR)) ==
        (SYM_C_DEF | SYM_CODEPTR)) return onevalue(nil);
    setenv(a, b);
    return onevalue(b);
}

LispObject Lsymbol_fastgets(LispObject env, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    return onevalue(qfastgets(a));
}

//
// (protect 'name t) arranges that the function indicated (which is
// expected to have been defined in the C kernel) can not be redefined.
// (protect 'name nil) restores the usual state of affairs.
//

LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b)
{   Header h;
    if (!is_symbol(a)) return onevalue(nil);
    h = qheader(a);
    if (b == nil) setheader(a, h & ~(SYM_CODEPTR | SYM_C_DEF));
    else setheader(a, h | SYM_CODEPTR | SYM_C_DEF);
    h &= (SYM_CODEPTR | SYM_C_DEF);
    return onevalue(Lispify_predicate(h == (SYM_CODEPTR | SYM_C_DEF)));
}

//
// (symbol-make-fastget 'xxx nil)   returns current information, nil if no
//                                  fastget usage set.
// (symbol-make-fastget 'xxx n)     sets it to n (0 <= n < 63)
// (symbol-make-fastget 'xxx -1)    sets the option off
//

LispObject Lsymbol_make_fastget1(LispObject env, LispObject a)
{
//
// Originally I had thought I would let people change the fastget size here,
// but I think that is dangerous and unnecessary so I will not do so any
// more. Anybody who tries will get a cryptic message!
//
    term_printf("+++ symbol-make-fastget called with only 1 argument\n");
    return onevalue(nil);
}

LispObject Lsymbol_make_fastget(LispObject env, LispObject a, LispObject n)
{   std::intptr_t n1, p, q;
    Header h;
    if (!symbolp(a)) return onevalue(nil);
    h = qheader(a);
    p = header_fastget(h);
    if (is_fixnum(n))
    {   n1 = int_of_fixnum(n);
        if (n1 < -1 || n1 >= fastget_size)
            aerror1("symbol-make-fastget", n);
//
//      trace_printf("+++ Use fastget slot %d for ", n1);
//      loop_print_trace(a);
//      trace_printf("\n");
//
        if (p != 0) elt(fastget_names, p-1) = SPID_NOPROP;
        q = (n1 + 1) & 0x3f;
        h = (h & ~SYM_FASTGET_MASK) | (q << SYM_FASTGET_SHIFT);
        setheader(a, h);
        if (q != 0) elt(fastget_names, q-1) = a;
    }
    if (p == 0) return onevalue(nil);
    else return onevalue(fixnum_of_int(p - 1));
}

static LispObject deleqip(LispObject a, LispObject l)
//
// This deletes the item a (tested for using EQ) from the list l,
// assuming that the list is nil-terminated and that the item a
// occurs at most once. It overwrites the list l in the process.
//
{   LispObject w, r;
    if (l == nil) return nil;
    if (car(l) == a) return cdr(l);
    r = l;
    while (w = l, (l = cdr(l)) != nil)
    {   if (car(l) == a)
        {   setcdr(w, cdr(l));
            write_barrier(cdraddr(w));
            return r;
        }
    }
    return r;
}

void lose_C_def(LispObject a)
{
//
// None of the code here can cause garbage collection.
//
    LispObject b = get(a, unset_var, nil), c;
    Lremprop(nil, a, unset_var);
    setheader(a, qheader(a) & ~SYM_C_DEF);
    c = get(b, work_symbol, nil);
    c = deleqip(a, c);
    if (c == nil) Lremprop(nil, b, work_symbol);
    else putprop(b, work_symbol, c);
}

static bool restore_fn_cell(LispObject a, char *name,
                               std::size_t len, setup_type const s[])
{   std::size_t i;
    for (i=0; s[i].name != NULL; i++)
    {   if (std::strlen(s[i].name) == (std::size_t)len &&
            std::memcmp(name, s[i].name, len) == 0) break;
    }
    if (s[i].name == NULL) return false;
    set_fns(a, s[i].zero, s[i].one, s[i].two, s[i].three, s[i].fourup);
    return true;
}

//
// This gets called by the compiler if it is asked to compile something
// into a fasl file where that thing has a definition as C code. In such a
// case what it puts into the fasl file is a call to this to instate the
// version coded in C. If a LOT of stuff has been turning into C this could
// become a bottleneck - and in such a case I should make a table of C
// entrypoints as a hash table or something sorted for use with binary
// search!
//

static LispObject Lrestore_c_code(LispObject env, LispObject a)
{   char *name;
    std::size_t len;
    std::size_t i;
    LispObject pn;
    if (!symbolp(a)) aerror1("restore-c-code", a);
    push(a);
    pn = get_pname(a);
    pop(a);
    name = (char *)&celt(pn, 0);
    len = length_of_byteheader(vechdr(pn)) - CELL;
//
// This is a potential time-sink in that it does a linear scan of all the
// definitions in the tables that are in u01.c to u60.c.
//
    for (i=0; setup_tables[i]!=NULL; i++)
    {   if (restore_fn_cell(a, name, len, setup_tables[i]))
        {   LispObject env;
            push(a);
            env = get(a, funarg, nil);
            pop(a);
            setenv(a, env);
            return onevalue(a);
        }
    }
    return onevalue(nil);
}

LispObject Lsymbol_set_definition(LispObject env,
                                  LispObject a, LispObject b)
//
// The odd case here is where the second argument represents a freshly
// created bit of compiled code. In which case the structure is
//   (nargs . codevec . envvec)
// where nargs is an integer indicating the number of arguments, codevec
// is a vector of bytecodes, and envvec is something to go in the
// environment cell of the symbol.
// Here the low 8 bits of nargs indicate the number of required arguments.
// The next 8 bits give the number of optional arguments, and the next
// two bits are flags. Of these, the first is set if any of the optional
// arguments has an initform or supplied-p associate, and the other
// indicates that a "&rest" argument is required.
// Bits beyond that (if non-zero) indicate that the function definition
// is of the form (defun f1 (a b c) (f2 a b)) and the number coded is the
// length of the function body.
// Standard Lisp does not need &optional or &rest arguments, but it turned
// out to be pretty easy to make the bytecode compiler support them.
//
{   if (!is_symbol(a) ||
//
// Something flagged with the CODEPTR bit is a gensym manufactured to
// stand for a compiled-code object. It should NOT be reset!
//
        (qheader(a) & (SYM_SPECIAL_FORM | SYM_CODEPTR)) != 0)
    {   if (qheader(a) & SYM_C_DEF) return onevalue(nil);
        aerror1("symbol-set-definition", a);
    }
    set_fns(a, undefined_0, undefined_1, undefined_2, undefined_3, undefined_4up); // Tidy up first
    setenv(a, a);
    if ((qheader(a) & SYM_C_DEF) != 0) lose_C_def(a);
    if (b == nil) return onevalue(b); // set defn to nil to undefine
    else if (symbolp(b))
    {
//
// One could imagine a view that the second arg to symbol-set-definition
// had to be a codepointer object. I will be kind (?) and permit the NAME
// of a function too.  However for the second arg to be a macro or a
// special form would still be a calamity.
//      if ((qheader(b) & SYM_CODEPTR) == 0)
//          aerror1("symbol-set-definition", b);
//
        if ((qheader(b) & (SYM_SPECIAL_FORM | SYM_MACRO)) != 0)
            aerror1("symbol-set-definition", b);
        setheader(a, qheader(a) & ~SYM_MACRO);
        {   set_fns(a, qfn0(b), qfn1(b), qfn2(b), qfn3(b), qfn4up(b));
            setenv(a, qenv(b));
//
// In order that checkpoint files can be made there is some very
// ugly fooling around here for functions that are defined in the C coded
// kernel.  Sorry.
//
            if ((qheader(b) & SYM_C_DEF) != 0)
            {
                LispObject c = get(b, unset_var, nil);
                if (c == nil) c = b;
                push(c, a);
                putprop(a, unset_var, c);
                pop(a);
                a = cons(a, get(stack[0], work_symbol, nil));
                putprop(stack[0], work_symbol, a);
                pop(b);
            }
        }
    }
    else if (!consp(b)) aerror1("symbol-set-definition", b);
    else if (is_fixnum(car(b)))
    {   std::int32_t nargs = (std::int32_t)int_of_fixnum(car(b)),
                nopts, flagbits, ntail;
        nopts = nargs >> 8;
        flagbits = nopts >> 8;
        ntail = flagbits >> 2;
        nargs &= 0xff;
        nopts &= 0xff;
        flagbits &= 3;
        if (ntail != 0)
        {   switch (100*nargs + ntail-1)
            {   case 300: set_fns(a, G0W3, G1W3, G2W3, f3_as_0, G4W3); break;
                case 301: set_fns(a, G0W3, G1W3, G2W3, f3_as_1, G4W3); break;
                case 302: set_fns(a, G0W3, G1W3, G2W3, f3_as_2, G4W3); break;
                case 303: set_fns(a, G0W3, G1W3, G2W3, f3_as_3, G4W3); break;
                case 200: set_fns(a, G0W2, G1W2, f2_as_0, G3W2, G4W2); break;
                case 201: set_fns(a, G0W2, G1W2, f2_as_1, G3W2, G4W2); break;
                case 202: set_fns(a, G0W2, G1W2, f2_as_2, G3W2, G4W2); break;
                case 100: set_fns(a, G0W1, f1_as_0, G2W1, G3W1, G4W1); break;
                case 101: set_fns(a, G0W1, f1_as_1, G2W1, G3W1, G4W1); break;
                case 000: set_fns(a, f0_as_0, G1W0, G2W0, G3W0, G4W0); break;
            }
            b = cdr(b);
        }
        else if (flagbits != 0 || nopts != 0)
        {   switch(flagbits)
            {   default:
                case 0:  // easy case optional arguments
                    set_fns(a, byteopt_0, byteopt_1, byteopt_2, byteopt_3, byteopt_4up); break;
                case 1:  // optional args, but non-nil default, or supplied-p extra
                    set_fns(a, hardopt_0, hardopt_1, hardopt_2, hardopt_3, hardopt_4up); break;
                case 2:  // easy opt args, but also a &rest arg
                    set_fns(a, byteoptrest_0, byteoptrest_1, byteoptrest_2, byteoptrest_3, byteoptrest_4up); break;
                case 3:  // complicated &options and &rest
                    set_fns(a, hardoptrest_0, hardoptrest_1, hardoptrest_2, hardoptrest_3, hardoptrest_4up); break;
            }
        }
        else
        {   if (nargs > 4) nargs = 4;
            setheader(a, qheader(a) & ~SYM_MACRO);
            switch (nargs)
            {   case 0:   set_fns(a, bytecoded_0, G1W0, G2W0, G3W0, G4W0);
                    break;
                case 1:   set_fns(a, G0W1, bytecoded_1, G2W1, G3W1, G4W1);
                    break;
                case 2:   set_fns(a, G0W2, G1W2, bytecoded_2, G3W2, G4W2);
                    break;
                case 3:   set_fns(a, G0W3, G1W3, G2W3, bytecoded_3, G4W3);
                    break;
                default:
                case 4:   set_fns(a, G0W4up, G1W4up, G2W4up, G3W4up, bytecoded_4up);
                    break;
            }
        }
        setenv(a, cdr(b));
    }
    else if (car(b) == lambda)
    {   LispObject bvl = car(cdr(b));
        int nargs = 0;
        while (consp(bvl)) nargs++, bvl = cdr(bvl);
        setheader(a, qheader(a) & ~SYM_MACRO);
        set_fns(a, interpreted_0, interpreted_1, interpreted_2, interpreted_3, interpreted_4up);
        setenv(a, cdr(b));
        if (qvalue(comp_symbol) != nil &&
            qfn1(compiler_symbol) != undefined_1)
        {   push(a);
            a = ncons(a);
            (*qfn1(compiler_symbol))(compiler_symbol, a);
            pop(a);
        }
    }
    else if (car(b) == funarg)
    {   LispObject bvl = car(cdr(b));
        int nargs = 0;
        while (consp(bvl)) nargs++, bvl = cdr(bvl);
        setheader(a, qheader(a) & ~SYM_MACRO);
        set_fns(a, funarged_0, funarged_1, funarged_2, funarged_3, funarged_4up);
        setenv(a, cdr(b));
    }
    else aerror1("symbol-set-definition", b);
    return onevalue(b);
}

LispObject Lgetd(LispObject env, LispObject a)
{   Header h;
    LispObject type;
    if (a == nil) return onevalue(nil);
    else if (!is_symbol(a)) return onevalue(nil);
    h = qheader(a);
    if ((h & SYM_SPECIAL_FORM) != 0) type = fexpr_symbol;
    else if ((h & SYM_MACRO) != 0)
    {   a = cons(lambda, qenv(a));
        type = macro_symbol;
    }
    else
    {   a = Lsymbol_function(nil, a);
        if (a == nil) return onevalue(nil);
        type = expr_symbol;
    }
    a = cons(type, a);
    return onevalue(a);
}

LispObject Lremd(LispObject env, LispObject a)
{   LispObject res;
    if (!is_symbol(a) ||
        (qheader(a) & SYM_SPECIAL_FORM) != 0)
        aerror1("remd", a);
    if ((qheader(a) & (SYM_C_DEF | SYM_CODEPTR)) ==
        (SYM_C_DEF | SYM_CODEPTR)) return onevalue(nil);
    res = Lgetd(nil, a);
    if (res == nil) return onevalue(nil); // no definition to remove
//
// I treat an explicit use of remd as a redefinition, and ensure that
// restarting a preserved image will not put the definition back.
//
    setheader(a, qheader(a) & ~SYM_MACRO);
    if ((qheader(a) & SYM_C_DEF) != 0) lose_C_def(a);
    set_fns(a, undefined_0, undefined_1, undefined_2, undefined_3, undefined_4up);
    setenv(a, a);
    return onevalue(res);
}

//
// For set-autoload the first argument must be a symbol that will name
// a function, the second arg is either an atom or a list of atoms, each
// of which specified a module to be loaded if the names function is
// called.  Loading the modules is expected to instate a definition for the
// function involved.  This function is arranged so it does NOT do anything
// if the function being set for autoloading is already defined. This is
// on the supposition that the existing definition is in fact the desired
// one, say because the relevant module happens to have been loaded already.
// An explicit use of remd first can be used to ensure that no previous
// definition is present and thus that a real autoload stub will be instated,
// if that is what you really want.
//

LispObject Lset_autoload(LispObject env, LispObject a, LispObject b)
{   LispObject res;
    if (!is_symbol(a) ||
        (qheader(a) & SYM_SPECIAL_FORM) != 0)
        aerror1("set-autoload", a);
    if (!(qfn0(a) == undefined_0 && qfn1(a) == undefined_1 &&
          qfn2(a) == undefined_2 && qfn3(a) == undefined_3 &&
          qfn4up(a) == undefined_4up)) return onevalue(nil);
    if ((qheader(a) & (SYM_C_DEF | SYM_CODEPTR)) ==
        (SYM_C_DEF | SYM_CODEPTR)) return onevalue(nil);
    push(a, b);
    if (consp(b)) res = cons(a, b);
    else res = list2(a, b);
    pop(b, a);
//
// I treat an explicit use of set-autoload as a redefinition, and ensure that
// restarting a preserved image will not put the definition back.  Note that
// I will not allow autoloadable macros...
//
    setheader(a, qheader(a) & ~SYM_MACRO);
    if ((qheader(a) & SYM_C_DEF) != 0) lose_C_def(a);
    set_fns(a, autoload_0, autoload_1, autoload_2, autoload_3, autoload_4up);
    setenv(a, res);
    return onevalue(res);
}

// If the compiler will support the symbol s as a "built-in" function
// set or clear an associated trace flag.

static void trace_builtin(LispObject s, bool state)
{   LispObject w = get(s, builtin0_symbol, nil);
    if (is_fixnum(w)) no_arg_traceflags[int_of_fixnum(w)] = state;
    w = get(s, builtin1_symbol, nil);
    if (is_fixnum(w)) one_arg_traceflags[int_of_fixnum(w)] = state;
    w = get(s, builtin2_symbol, nil);
    if (is_fixnum(w)) two_arg_traceflags[int_of_fixnum(w)] = state;
    w = get(s, builtin3_symbol, nil);
    if (is_fixnum(w)) three_arg_traceflags[int_of_fixnum(w)] = state;
    w = get(s, builtin4_symbol, nil);
    if (is_fixnum(w)) fourup_arg_traceflags[int_of_fixnum(w)] = state;
}

// The arrangements here are such that traceset always includes trace.

LispObject Ltrace(LispObject env, LispObject a)
{   LispObject w = a;
    if (symbolp(a))
    {   a = ncons(a);
        w = a;
    }
    while (consp(w))
    {   LispObject s = car(w);
        w = cdr(w);
        if (symbolp(s))
        {   one_arg *f1 = qfn1(s);
            if (f1 == undefined_1)
            {   freshline_debug();
// If you trace a function that is not defined I will issue a warning, since
// there is a chance that you made a mistake in the name of the function
// concerned, but I will set the trace flag and with luck if it gets defined
// later then tracing will occur.
                debug_printf("+++ ");
                loop_print_debug(s);
                debug_printf(" not yet defined, was this a mistake?\n");
                continue;
            }
            setheader(s, qheader(s) | SYM_TRACED);
            trace_builtin(s, true);
        }
    }
    return onevalue(a);
}

// untrace switches off trace and also any traceset.

LispObject Luntrace(LispObject env, LispObject a)
{   LispObject w = a;
    if (symbolp(a))
    {   a = ncons(a);
        w = a;
    }
    while (consp(w))
    {   LispObject s = car(w);
        w = cdr(w);
        if (symbolp(s))
        {   setheader(s, qheader(s) & ~SYM_TRACED & ~SYM_TRACESET);
            trace_builtin(s, false);
        }
    }
    return onevalue(a);
}

// traceset forces on trace as well as traceset.

LispObject Ltraceset(LispObject env, LispObject a)
{   LispObject w = a;
    if (symbolp(a))
    {   a = ncons(a);
        w = a;
    }
    while (consp(w))
    {   LispObject s = car(w);
        w = cdr(w);
        if (symbolp(s)) setheader(s, qheader(s) | SYM_TRACESET | SYM_TRACED);
    }
    return onevalue(a);
}

LispObject Luntraceset(LispObject env, LispObject a)
{   LispObject w = a;
    if (symbolp(a))
    {   a = ncons(a);
        w = a;
    }
    while (consp(w))
    {   LispObject s = car(w);
        w = cdr(w);
        if (symbolp(s)) setheader(s, qheader(s) & ~SYM_TRACESET);
    }
    return onevalue(a);
}

LispObject Lmacro_function(LispObject env, LispObject a)
{   if (!symbolp(a)) return onevalue(nil);
    else if ((qheader(a) & SYM_MACRO) == 0) return onevalue(nil);
// If the MACRO bit is set in the header I know there is a definition
    else return onevalue(cons(lambda, qenv(a)));
}


LispObject get_pname(LispObject a)
{   LispObject name = qpname(a);
#ifndef COMMON
//
// When a gensym is first created its pname field points at a string that
// will form the base of its name, and a magic bit is set in its header.
// If at some stage it is necessary to inspect the print name (mainly in
// order to print the symbol) it becomes necessary to create a new string
// and insert a serial number.  Doing things this way means that the serial
// numbers that users see will tend to be smaller, and space for per-gensym
// strings does not get allocated unless really needed.  The down side is
// that every time I want to grab the pname of anything I have to check for
// this case and admit the possibility of garbage collection or even
// failure.
//
    if (qheader(a) & SYM_UNPRINTED_GENSYM)
    {   std::uintptr_t len;
        char *p;
        char genname[80];
        len = length_of_byteheader(vechdr(name)) - CELL;
        if (len > 60) len = 60;     // Unpublished truncation of the string
// I will make the first 10K names g0000 to g9999 with exactly 4 digits
// at the end. After that I will use
// g9999_999, g9999_999_999, g9999_999_999_999 with underscores separating
// off each trailing group of 3 digits. This scheme has two separate
// motivations. The first is that putting digits in blocks of 3 might
// make the names easier to read. The second is that this arrangement
// will let me look at the full name of a printed gensym and separate off
// the "numeric" suffix. The code I have here would allow for up to 10^13
// distinct gensyms, and after that it wraps round. Well on a 32-bit
// system it counts up to 2^32 and wraps there.
        std::sprintf(genname, "%.*s", (int)len, (const char *)&celt(name, 0));
        p = genname+len;
        if (gensym_ser <= 9999) std::sprintf(p, "%.4d", (int)gensym_ser);
        else if (gensym_ser <= 9999999)
            std::sprintf(p, "%.4d_%.3d",
                (int)(gensym_ser/1000),
                (int)(gensym_ser%1000));
        else if (!SIXTY_FOUR_BIT || gensym_ser <= UINT64_C(99999999999))
            std::sprintf(p, "%.4d_%.3d_%.3d",
                (int)(gensym_ser/1000000),
                (int)((gensym_ser/1000)%1000),
                (int)(gensym_ser%1000));
        else
            std::sprintf(p, "%.4d_%.3d_%.3d_%.3d",
                (int)((gensym_ser/1000000000)%10000),
                (int)((gensym_ser/1000000)%1000),
                (int)((gensym_ser/1000)%1000),
                (int)(gensym_ser%1000));
        gensym_ser++;
        push(a);
        name = make_string(genname);
        pop(a);
        setpname(a, name);
        setheader(a, qheader(a) & ~SYM_UNPRINTED_GENSYM);
    }
#endif
    return name;
}

LispObject Lsymbol_name(LispObject env, LispObject a)
{   if (!symbolp(a)) aerror1("symbol-name", a);
    a = get_pname(a);
    return onevalue(a);
}

LispObject Lsymbol_package(LispObject env, LispObject a)
{   if (!symbolp(a)) aerror1("symbol-package", a);
    a = qpackage(a);
    return onevalue(a);
}

static LispObject Lrestart_lisp2(LispObject env,
                                 LispObject a, LispObject b)
//
// If the argument is given as nil then this is a cold-start, and when
// I begin again it would be a VERY good idea to do a (load!-module 'compat)
// rather promptly (otherwise some Lisp functions will not work at all).
// I do not automate that because this function is intended for use in
// delicate system rebuilding contexts and I want the user to have ultimate
// control.  (restart!-lisp t) reloads a heap-image in the normal way.
// (restart!-lisp 'xx) where xx is neither nil nor t starts by reloading a
// heap image, but then it looks for a function with the same name as xx
// (since a heap image is reloaded it is NOT easy (possible?) to keep the
// symbol) and calls it as a function. Finally the case
// (restart!-lisp '(module xx)) reloads the heap image, calls load-module
// on the named module and finally calls the given restart function.
// This last option can be useful since otherwise the function to be called
// in (restart!-lisp 'xx) would need to be in the base image as re-loaded.
// There is no provision here to force a cold start followed by a reload
// of some particular module.
//
// The second argument (if provided) is passed through (via serialization
// as a string of characters) and remade as a Lisp object to be passed to
// the custom restart function as an argument. Thus in (restart!-lisp 'xx) the
// function xx should not take any arguments, while in the call
// (restart!-list 'xx 'argument) the function xx must accept one argument.
//
// The expectation is that when this function is called Lisp will be reading
// from its initial default input source, and that will be preserved across
// the restart. A log file and the standard output should also be safe,
// but no other files should be active when restart!-lisp is called.
//
{   int n;
    char *v;
    ensure_screen();
    n = 0;
    v = NULL;
//
// A comment seems in order here. The case b==SPID_NOARG should only
// arise if I came from Lrestart_lisp: it indicates that there was
// no second argument provided.
//
    if (b != SPID_NOARG)
    {   LispObject b1;
        push(a);
//
// I will need to pack the data into a character vector using utf-8
// encoding... exploden can hand back character codes up to 0x0010ffff.
//
        b1 = b = Lexploden(nil, b);
        pop(a);
        while (b1 != nil)
        {   int ch = int_of_fixnum(car(b1));
            n++;            // number of chars of arg
            if (ch > 0x7f) n++; // extra byte
            if (ch > 0x7ff) n++;
            if (ch > 0xffff) n++; // Now have enough bytes for utf8
            b1 = cdr(b1);
        }
        v = (char *)std::malloc(n+1);
        if (v == NULL) aerror("space exhausted in restart-csl");
        n = 0;
        while (b != nil)
        {   int ch = int_of_fixnum(car(b));
            if (ch <= 0x7f) v[n++] = ch;
            else if (ch < 0x7ff)
            {   v[n++] = 0xc0 | ((ch >> 6) & 0x1f);
                v[n++] = 0x80 | (ch & 0x3f);
            }
            else if (ch < 0xffff)
            {   v[n++] = 0xe0 | ((ch >> 12) & 0x0f);
                v[n++] = 0x80 | ((ch >> 6) & 0x3f);
                v[n++] = 0x80 | (ch & 0x3f);
            }
            else
            {   v[n++] = 0xf0 | ((ch >> 18) & 0x07);
                v[n++] = 0x80 | ((ch >> 12) & 0x3f);
                v[n++] = 0x80 | ((ch >> 6) & 0x3f);
                v[n++] = 0x80 | (ch & 0x3f);
            }
            b = cdr(b);
        }
        v[n] = 0;
    }
    term_printf("\nThe system is about to do a restart...\n");
// Almost all unpicking of the argument is done back in csl.c
    exit_value = a;
    exit_tag = fixnum_of_int(2);   // Flag to say "restart"
    exit_reason = UNWIND_RESTART;
    exit_charvec = v;
    throw LispRestart();
}

static LispObject Lrestart_lisp(LispObject env, LispObject a)
{   return Lrestart_lisp2(env, a, SPID_NOARG);
}

static LispObject Lpreserve_3(LispObject env, LispObject startup,
        LispObject banner, LispObject resume)
{   char filename[LONGEST_LEGAL_FILENAME];
    bool failed;
    std::memset(filename, 0, sizeof(filename));
    if (startup != nil) supervisor = startup;
    failed = Iwriterootp(filename);  // Can I open image file for writing?
    term_printf("\nThe system will be preserved on file \"%s\"\n", filename);
    if (failed) aerror("preserve");
    ensure_screen();
    exit_count = 0;  // no value at all returned
    exit_value = banner;
    exit_tag = resume == nil ? fixnum_of_int(1) : // Flag to say "preserve"
               fixnum_of_int(3);                  // preserve and restart
    exit_reason = UNWIND_RESTART;
    throw LispRestart();
}

static LispObject Lpreserve_2(LispObject env,
                              LispObject startup, LispObject banner)
//
// (preserve <startup-fn>) saves a Lisp image in a standard place
// and arranges that when restarted the saved image will call the specified
// startup function.  In the process of doing all this it unwinds down to
// the top level of Lisp. If a startup function is not given then the
// previously active one is used.  If nil is specified then the previously
// active startup function is retained.  If banner is non-nil (well really
// I want a string) is is a message of up to 40 characters to display
// when the system restart.
//
{   return Lpreserve_3(env, startup, banner, nil);
}

static LispObject Lpreserve_1(LispObject env, LispObject startup)
{   return Lpreserve_3(env, startup, nil, nil);
}

static LispObject Lpreserve_0(LispObject env)
{   return Lpreserve_3(env, nil, nil, nil);
}


#if 0
//
// This is an experimental addition - a version of PRESERVE that allows
// CSL to continue executing after it has written out an image file. I am
// now removing it because I have arranged that if PRESERVE is given a
// non-nil third argument it reloads the image that it creates rather than
// quitting lisp.
//

// ++++ With the new serialization-based scheme for preserve() this would
//      all become almost trivial to reinstate if I thought it was useful!


static LispObject Lcheckpoint(LispObject env,
                              LispObject startup, LispObject banner)
{   char filename[LONGEST_LEGAL_FILENAME];
    char *msg = "";
    int len = 0;
    std::memset(filename, 0, sizeof(filename));
    ensure_screen();
    if (startup != nil) supervisor = startup;
    bool failed = Iwriterootp(filename);  // Can I open image file for writing?
    term_printf("\nThe system will be preserved on file \"%s\"\n", filename);
    if (failed) aerror("checkpoint");
    if (is_vector(banner) && is_string(banner))
    {   msg = (char *)&celt(banner, 0);
        len = length_of_byteheader(vechdr(banner)) - CELL;
    }
//
// Note, with some degree of nervousness, that things on the C stack will
// be updated by the garbage collection that happens during the processing
// of the call to preserve(), but they will be neither adjusted into
// relative addresses nor unadjusted (and hence restored) by in the
// image-writing. But the image writing will not actually move any data
// around so all is still OK, I hope!
//
    push(catch_tags, faslvec, faslgensyms);
    preserve(msg, len);
    pop(faslgensyms, faslvec, catch_tags);
    set_up_functions(true);
    return onevalue(nil);
}

static LispObject Lcheckpoint_0(LispObject env)
{   return Lcheckpoint(env, nil, nil);
}

static LispObject Lcheckpoint_1(LispObject env, LispObject startup)
{   return Lcheckpoint(env, startup, nil);
}

#endif


//
// Drop out to the next enclosing code that limits resources, as if there had
// been an overflow.
//

[[noreturn]] static LispObject Lresource_exceeded(LispObject env)
{   resource_exceeded();
}

static bool eql_numbers(LispObject a, LispObject b)
//
// This is only called from eql, and then only when a and b are both tagged
// as ratios or complex numbers.
//
{   LispObject p, q;
    p = *(LispObject *)(a + (CELL - TAG_NUMBERS));
    q = *(LispObject *)(b + (CELL - TAG_NUMBERS));
    if (!eql(p, q)) return false;
    p = *(LispObject *)(a + (2*CELL - TAG_NUMBERS));
    q = *(LispObject *)(b + (2*CELL - TAG_NUMBERS));
    return eql(p, q);
}

bool eql_fn(LispObject a, LispObject b)
//
// This seems incredible - all the messing about that is needed to
// check that numeric values compare properly.  Ugh.
//
{
//
// (these tests done before eql_fn is called).
//  if (a == b) return true;
//  if ((((intptr_t)a ^ (intptr_t)b) & TAG_BITS) != 0) return false;
//
// Actually in Common Lisp mode where I have short floats as immediate data
// I have further pain here with (eql 0.0s -0.0s), and (eql NaN NaN) might
// improperly return true because of the early EQ test. For Standard Lisp
// I am going to make +0.0 and -0.0 equal.
//
    if (SIXTY_FOUR_BIT)
    {   if (a == XTAG_SFLOAT &&
            b == (LispObject)(XTAG_SFLOAT|((std::uint64_t)1<<63))) return true;
        if (b == XTAG_SFLOAT &&
            a == (LispObject)(XTAG_SFLOAT|((std::uint64_t)1<<63))) return true;
// Here I need to deal with single as well as short floats.
        if (a == (XTAG_SFLOAT|XTAG_FLOAT32) &&
            b == (LispObject)(XTAG_SFLOAT|XTAG_FLOAT32|((std::uint64_t)1<<63)))
            return true;
        if (b == (XTAG_SFLOAT|XTAG_FLOAT32) &&
            a == (LispObject)(XTAG_SFLOAT|XTAG_FLOAT32|((std::uint64_t)1<<63)))
            return true;
    }
    else if ((a == XTAG_SFLOAT && b == (XTAG_SFLOAT|(std::intptr_t)0x80000000U)) ||
        (a == (XTAG_SFLOAT|(std::intptr_t)0x80000000U) && b == XTAG_SFLOAT))
        return true;
    if (!is_number(a) || is_immed_or_cons(a)) return false;
    if (is_bfloat(a))
    {   Header h = flthdr(a);
        if (h != flthdr(b)) return false;
// Boxed single floats should not arise on a 64-bit system, so I will
// avoid checking for them there.
        if (!SIXTY_FOUR_BIT && type_of_header(h) == TYPE_SINGLE_FLOAT)
            return (single_float_val(a) == single_float_val(b));
        else if (type_of_header(h) == TYPE_DOUBLE_FLOAT)
            return (double_float_val(a) == double_float_val(b));
#ifdef HAVE_SOFTFLOAT
// Here I must have a long float.
        return f128_eq(float128_of_number(a), float128_of_number(b));
#else
        return false;
#endif // HAVE_SOFTFLOAT
    }
    else    // ratio, complex or bignum
    {   Header h = numhdr(a);
        if (h != numhdr(b)) return false;
        if (type_of_header(h) == TYPE_BIGNUM)
        {   std::intptr_t hh = (std::intptr_t)length_of_header(h) - TAG_NUMBERS;
            while (hh > (std::intptr_t)(CELL - TAG_NUMBERS))
            {   hh -= 4;
                if (*(std::uint32_t *)((char *)a + hh) !=
                    *(std::uint32_t *)((char *)b + hh))
                    return false;
            }
            return true;
        }
        else return eql_numbers(a, b);
    }
}

#ifdef COMMON
#define eqcheck(a, b) eql(a, b)
#else
#define eqcheck(a, b) ((a) == (b))
#endif

static bool cl_vec_equal(LispObject a, LispObject b)
//
// here a and b are known to be vectors or arrays.  This should compare
// them following the Common Lisp recipe, where strings or bitvectors
// (simple or complex) have their contents compared, while all other types of
// vector or array are tested using EQ.
//
{   Header ha = vechdr(a), hb = vechdr(b);
    std::intptr_t offa = 0, offb = 0;
    int ta = type_of_header(ha), tb = type_of_header(hb);
    std::intptr_t la = length_of_header(ha), lb = length_of_header(hb);
    if (is_bitvec_header(ha)) ta = TYPE_BITVEC_1;
    if (is_bitvec_header(hb)) tb = TYPE_BITVEC_1;
    switch (ta)
    {
//
//case TYPE_ARRAY:
///  My moan here is that, as noted above, I ought to process even
// non-simple strings and bit-vectors by comparing contents, but as a
// matter of idleness I have not yet got around to that. In fact if I get
// arrays to compare here I will pretend that they are not strings or
// bit-vectors and compare using EQ...
//
        case TYPE_STRING_1:
        case TYPE_STRING_2:
        case TYPE_STRING_3:
        case TYPE_STRING_4:
            switch (tb)
            {
// /*
//  case TYPE_ARRAY:
//
                case TYPE_STRING_1:
                case TYPE_STRING_2:
                case TYPE_STRING_3:
                case TYPE_STRING_4:
                    goto compare_strings;
                default:return false;
            }
        case TYPE_BITVEC_1:
        case TYPE_BITVEC_2:
        case TYPE_BITVEC_3:
        case TYPE_BITVEC_4:
        case TYPE_BITVEC_5:
        case TYPE_BITVEC_6:
        case TYPE_BITVEC_7:
        case TYPE_BITVEC_8:
        case TYPE_BITVEC_9:
        case TYPE_BITVEC_10:
        case TYPE_BITVEC_11:
        case TYPE_BITVEC_12:
        case TYPE_BITVEC_13:
        case TYPE_BITVEC_14:
        case TYPE_BITVEC_15:
        case TYPE_BITVEC_16:
        case TYPE_BITVEC_17:
        case TYPE_BITVEC_18:
        case TYPE_BITVEC_19:
        case TYPE_BITVEC_20:
        case TYPE_BITVEC_21:
        case TYPE_BITVEC_22:
        case TYPE_BITVEC_23:
        case TYPE_BITVEC_24:
        case TYPE_BITVEC_25:
        case TYPE_BITVEC_26:
        case TYPE_BITVEC_27:
        case TYPE_BITVEC_28:
        case TYPE_BITVEC_29:
        case TYPE_BITVEC_30:
        case TYPE_BITVEC_31:
        case TYPE_BITVEC_32:
            switch (tb)
            {
// /*
//  case TYPE_ARRAY:
//
                case TYPE_BITVEC_1:
                case TYPE_BITVEC_2:
                case TYPE_BITVEC_3:
                case TYPE_BITVEC_4:
                case TYPE_BITVEC_5:
                case TYPE_BITVEC_6:
                case TYPE_BITVEC_7:
                case TYPE_BITVEC_8:
                case TYPE_BITVEC_9:
                case TYPE_BITVEC_10:
                case TYPE_BITVEC_11:
                case TYPE_BITVEC_12:
                case TYPE_BITVEC_13:
                case TYPE_BITVEC_14:
                case TYPE_BITVEC_15:
                case TYPE_BITVEC_16:
                case TYPE_BITVEC_17:
                case TYPE_BITVEC_18:
                case TYPE_BITVEC_19:
                case TYPE_BITVEC_20:
                case TYPE_BITVEC_21:
                case TYPE_BITVEC_22:
                case TYPE_BITVEC_23:
                case TYPE_BITVEC_24:
                case TYPE_BITVEC_25:
                case TYPE_BITVEC_26:
                case TYPE_BITVEC_27:
                case TYPE_BITVEC_28:
                case TYPE_BITVEC_29:
                case TYPE_BITVEC_30:
                case TYPE_BITVEC_31:
                case TYPE_BITVEC_32:
                    goto compare_bits;
                default:return false;
            }
        default: return (a == b);
    }
compare_strings:
    la = length_of_byteheader(ha);
    lb = length_of_byteheader(hb);
    if (la != lb) return false;
    while (la > 0)
    {   la--;
        if (*((char *)a + la + offa - TAG_VECTOR) !=
            *((char *)b + la + offb - TAG_VECTOR)) return false;
    }
    return true;
compare_bits:
    la = length_of_bitheader(ha);
    lb = length_of_bitheader(hb);
    if (la != lb) return false;
// I will insist that the bitvectors have zero bits in any unused space
// in their final byte. 
    la = (la + 7)/8;
    lb = (lb + 7)/8;
    while (la > 0)
    {   la--;
        if (*((char *)a + la + offa - TAG_VECTOR) !=
            *((char *)b + la + offb - TAG_VECTOR)) return false;
    }
    return true;
}

bool cl_equal_fn(LispObject a, LispObject b)
//
// a and b are not EQ at this stage.. I guarantee to have checked that
// before entering this general purpose code.
// I will only view short and possibly single floats as EQUAL here if they
// has been EQ. In particular that has implications for +0.0 vs. -0.0 and
// also NaN values...
{
//
// The for loop at the top here is so that cl_equal can iterate along the
// length of linear lists.
//
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("Stack too deep in cl_equal\n");
        return false;
    }
#endif
    for (;;)
    {   std::int32_t ta = (std::int32_t)a & TAG_BITS;
        if (ta == TAG_CONS && a != nil)
        {   if (!consp(b) || b == nil) return false;
            else
            {   LispObject ca = car(a), cb = car(b);
                if (ca == cb)
                {   a = cdr(a);
                    b = cdr(b);
                    if (a == b) return true;
                    continue;
                }
//
// And here, because cl_equal() seems to be a very important low-level
// primitive, I unwind one level of the recursion that would arise
// with nested lists.
//
                for (;;)
                {   std::int32_t tca = (std::int32_t)ca & TAG_BITS;
                    if (tca == TAG_CONS && ca != nil)
                    {   if (!consp(cb) || cb == nil) return false;
                        else
                        {   LispObject cca = car(ca), ccb = car(cb);
                            if (cca == ccb)
                            {   ca = cdr(ca);
                                cb = cdr(cb);
                                if (ca == cb) break;
                                continue;
                            }
//
// Do a real recursion when I get down to args like
// ((x ...) ...) ((y ...) ...)
//
                            if (!cl_equal(cca, ccb)) return false;
                            ca = cdr(ca);
                            cb = cdr(cb);
                            if (ca == cb) break;
                            continue;
                        }
                    }
                    else if (is_immed_cons_sym(tca) ||
                             ((std::int32_t)cb & TAG_BITS) != tca) return false;
                    else switch (tca)
                        {   case TAG_NUMBERS:
                            {   Header h = numhdr(ca);
                                if (h != numhdr(cb)) return false;
                                if (type_of_header(h) == TYPE_BIGNUM)
                                {   std::intptr_t hh = (std::intptr_t)length_of_header(h) - TAG_NUMBERS;
                                    while (hh > (std::intptr_t)(CELL - TAG_NUMBERS))
                                    {   hh -= 4;
                                        if (*(std::uint32_t *)((char *)ca + hh) !=
                                            *(std::uint32_t *)((char *)cb + hh))
                                            return false;
                                    }
                                    break;
                                }
                                else if (!eql_numbers(ca, cb)) return false;
                                else break;
                            }
                            case TAG_VECTOR:
                                if (!cl_vec_equal(ca, cb)) return false;
                                break;
                            default:
                            case TAG_BOXFLOAT:
                            {   Header h = flthdr(ca);
                                if (h != flthdr(cb)) return false;
                                if (!SIXTY_FOUR_BIT &&
                                    type_of_header(h) == TYPE_SINGLE_FLOAT)
                                {   if (single_float_val(ca) !=
                                        single_float_val(cb)) return false;
                                    else break;
                                }
                                else if (type_of_header(ca) == TYPE_DOUBLE_FLOAT)
                                {   if (double_float_val(ca) !=
                                        double_float_val(cb)) return false;
                                    else break;
                                }
#ifdef HAVE_SOFTFLOAT
                                else if (!f128_eq(
                                    float128_of_number(ca),
                                    float128_of_number(cb))) return false;
                                else break;
#else
                                else return false;
#endif // HAVE_SOFTFLOAT
                            }
                        }
                    break;  // out of the for (;;) loop
                }
                a = cdr(a);
                b = cdr(b);
                if (a == b) return true;
                continue;
            }
        }
        else if (is_immed_cons_sym(ta) ||
                 ((std::int32_t)b & TAG_BITS) != ta) return false;
//
// OK - now a and b both have the same type and neither are immediate data
// conses or symbols. That leaves vectors (including strings) and boxed
// numbers.
//
        else switch (ta)
            {   case TAG_NUMBERS:
                {   Header h = numhdr(a);
                    if (h != numhdr(b)) return false;
                    if (type_of_header(h) == TYPE_BIGNUM)
                    {   std::intptr_t hh = (std::intptr_t)length_of_header(h) - TAG_NUMBERS;
                        while (hh > (std::intptr_t)(CELL - TAG_NUMBERS))
                        {   hh -= 4;
                            if (*(std::uint32_t *)((char *)a + hh) !=
                                *(std::uint32_t *)((char *)b + hh))
                                return false;
                        }
                        return true;
                    }
                    else return eql_numbers(a, b);
                }
                case TAG_VECTOR:
                    return cl_vec_equal(a, b);
                default:
                case TAG_BOXFLOAT:
                {   Header h = flthdr(a);
                    if (h != flthdr(b)) return false;
                    if (!SIXTY_FOUR_BIT &&
                        type_of_header(h) == TYPE_SINGLE_FLOAT)
                    {   if (single_float_val(a) != single_float_val(b))
                            return false;
                        else return true;
                    }
                    else if(type_of_header(h) == TYPE_DOUBLE_FLOAT)
                    {   if (double_float_val(a) != double_float_val(b))
                            return false;
                        else return true;
                    }
#ifdef HAVE_SOFTFLOAT
                    else return f128_eq(
                        float128_of_number(a),
                        float128_of_number(b));
#else
                    else return false;
#endif // HAVE_SOFTFLOAT
                }
            }
    }
}

static bool vec_equal(LispObject a, LispObject b);

//
// Hmmm - EQUAL could be re-implemented to be non-recursive via pointer
// reversing and if that was done then there could not possibly be any
// concerns about stck overflow in it. Furthermore since EQUAL traverses
// the two input lists in lockstep and only dived into structures that
// are not EQ, and since a larger part of one list can not be EQUAL to
// a smaller part of the other it may be that the temporary rearrangement
// to one list can never confuse traversal of the other. I might want to
// think about recovery in the case that cyclic (and partially shared) lists
// are presented. Until I implement this I do not know what the performance
// would be as compared agsinst a regular recursive version.
//
// For performance I might wish to consider an implementation that
// defers pointer reversal via a small local stack of depth (say) three.
// Oh what a jolly and messy project it will be if I get round to implementing
// and measuring that!
//

#ifdef TRACED_EQUAL
#define LOG_SIZE 10000
typedef struct equal_record
{   char file[24];
    int line;
    int depth;
    int count;
} equal_record;

static equal_record equal_counts[LOG_SIZE];

static void record_equal(char *file, int line, int depth)
{   int hash = 169*line + depth;
    char *p = file;
    while (*p != 0) hash = 169*hash + (*p++ & 0xff);
    hash = ((169*hash) & 0x7fffffff) % LOG_SIZE;
    while (equal_counts[hash].count != 0)
    {   if (equal_counts[hash].line == line &&
            equal_counts[hash].depth == depth &&
            std::strncmp(equal_counts[hash].file, file, 24) == 0)
        {   equal_counts[hash].count++;
            return;
        }
        hash = (hash + 1) % LOG_SIZE;
    }
    std::strncpy(equal_counts[hash].file, file, 24);
    equal_counts[hash].line = line;
    equal_counts[hash].depth = depth;
    equal_counts[hash].count = 1;
    return;
}

void dump_equals()
{   int i;
    std::FILE *std::log = std::fopen("equal.log", "w");
    if (std::log == NULL) std::log = stdout;
    std::fprintf(std::log, "\nCalls to equal...\n");
    for (i=0; i<LOG_SIZE; i++)
        if (equal_counts[i].count != 0)
            std::fprintf(std::log, "%24.24s %5d %5d %10d\n",
                    equal_counts[i].file, equal_counts[i].line,
                    equal_counts[i].depth, equal_counts[i].count);
    std::fprintf(std::log, "end of counts\n");
    if (std::log != stdout) std::fclose(std::log);
}

bool traced_equal_fn(LispObject a, LispObject b,
                        char *file, int line, int depth)
//
// a and b are not EQ at this stage.. I guarantee to have checked that
// before entering this general purpose code.
//
{   record_equal(file, line, depth);
#undef equal_fn
#define equal_fn(a, b) traced_equal_fn(a, b, file, line, depth+1)
#else
bool equal_fn(LispObject a, LispObject b)
//
// a and b are not EQ at this stage.. I guarantee to have checked that
// before entering this general purpose code. I will also have checked that
// the types of the two args agree, and that they are not both immediate
// data.
//
{
#endif
//
// The for loop at the top here is so that equal can iterate along the
// length of linear lists. For MANY MANY cases in a Lisp world data
// structures will be long but not so terribly deep and so one hopes that
// stack requirements here will not be excessive. Hahaha - if I had a
// non-recursive version of the code too but it proved generally slower
// I could trigger a transfer into it at the stage that stack use became
// excessive...
//
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("Stack too deep in equal\n");
        return false;
    }
#endif
    for (;;)
    {   std::int32_t ta = (std::int32_t)a & TAG_BITS;
        if (ta == TAG_CONS && a != nil)
        {   if (!consp(b) || b == nil) return false;
            else
            {   LispObject ca = car(a), cb = car(b);
                if (ca == cb)
                {   a = cdr(a);
                    b = cdr(b);
                    if (a == b) return true;
                    continue;
                }
//
// And here, because equal() seems to be a very important low-level
// primitive, I unwind one level of the recursion that would arise
// with nested lists.
//
                for (;;)
                {   std::int32_t tca = (std::int32_t)ca & TAG_BITS;
                    if (tca == TAG_CONS && ca != nil)
                    {   if (!consp(cb) || cb == nil) return false;
                        else
                        {   LispObject cca = car(ca), ccb = car(cb);
                            if (cca == ccb)
                            {   ca = cdr(ca);
                                cb = cdr(cb);
                                if (ca == cb) break;
                                continue;
                            }
//
// Do a real recursion when I get down to args like
// ((x ...) ...) ((y ...) ...)
//
                            if (!equal(cca, ccb)) return false;
                            ca = cdr(ca);
                            cb = cdr(cb);
                            if (ca == cb) break;
                            continue;
                        }
                    }
                    else if (is_immed_cons_sym(tca) ||
                             ((std::int32_t)cb & TAG_BITS) != tca) return false;
                    else switch (tca)
                        {   case TAG_NUMBERS:
                            {   Header h = numhdr(ca);
                                if (h != numhdr(cb)) return false;
                                if (type_of_header(h) == TYPE_BIGNUM)
                                {   std::intptr_t hh = (std::intptr_t)length_of_header(h) - TAG_NUMBERS;
                                    while (hh > (std::intptr_t)(CELL - TAG_NUMBERS))
                                    {   hh -= 4;
                                        if (*(std::uint32_t *)((char *)ca + hh) !=
                                            *(std::uint32_t *)((char *)cb + hh))
                                            return false;
                                    }
                                    break;
                                }
                                else if (!eql_numbers(ca, cb)) return false;
                                else break;
                            }
                            case TAG_VECTOR:
                                if (!vec_equal(ca, cb)) return false;
                                break;
                            default:
                            case TAG_BOXFLOAT:
                            {   Header h = flthdr(ca);
                                if (h != flthdr(cb)) return false;
                                if (!SIXTY_FOUR_BIT &&
                                    type_of_header(h) == TYPE_SINGLE_FLOAT)                                    
                                {   if (single_float_val(ca) !=
                                        single_float_val(cb)) return false;
                                    else break;
                                }
                                else if (type_of_header(h) == TYPE_DOUBLE_FLOAT)
                                {   if (double_float_val(ca) !=
                                        double_float_val(cb)) return false;
                                    else break;
                                }
#ifdef HAVE_SOFTFLOAT
                                else if (!f128_eq(
                                    float128_of_number(ca),
                                    float128_of_number(cb))) return false;
                                else break;
#else
                                else return false;
#endif // HAVE_SOFTFLOAT
                            }
                        }
                    break;  // out of the for (;;) loop
                }
                a = cdr(a);
                b = cdr(b);
                if (a == b) return true;
                continue;
            }
        }
        else if (is_immed_cons_sym(ta) ||
                 ((std::int32_t)b & TAG_BITS) != ta) return false;
        else switch (ta)
            {   case TAG_NUMBERS:
                {   Header h = numhdr(a);
                    if (h != numhdr(b)) return false;
                    if (type_of_header(h) == TYPE_BIGNUM)
                    {   std::intptr_t hh = (std::intptr_t)length_of_header(h) - TAG_NUMBERS;
                        while (hh > (std::intptr_t)(CELL - TAG_NUMBERS))
                        {   hh -= 4;
                            if (*(std::uint32_t *)((char *)a + hh) !=
                                *(std::uint32_t *)((char *)b + hh))
                                return false;
                        }
                        return true;
                    }
                    else return eql_numbers(a, b);
                }
                case TAG_VECTOR:
                    return vec_equal(a, b);
                default:
                case TAG_BOXFLOAT:
                {   Header h = flthdr(a);
                    if (h != flthdr(b)) return false;
                    if (!SIXTY_FOUR_BIT &&
                        type_of_header(h) == TYPE_SINGLE_FLOAT)
                    {   if (single_float_val(a) != single_float_val(b))
                            return false;
                        else return true;
                    }
                    else if (type_of_header(h) == TYPE_DOUBLE_FLOAT)
                    {   if (double_float_val(a) != double_float_val(b))
                            return false;
                        else return true;
                    }
#ifdef HAVE_SOFTFLOAT
                    else return f128_eq(
                        float128_of_number(a),
                        float128_of_number(b));
#else
                    else return false;
#endif // HAVE_SOFTFLOAT
                }
            }
    }
}

#ifdef TRACED_EQUAL
#undef equal_fn
#define equal_fn(a, b) traced_equal(a, b, __FILE__, __LINE__, 0)
#endif

static bool vec_equal(LispObject a, LispObject b)
//
// Here a and b are known to be vectors. Compare using recursive calls to
// EQUAL on all components.
//
{   Header ha = vechdr(a), hb = vechdr(b);
    std::size_t l;
    if (ha != hb) return false;
//
// This used to check all the way up to the end of the final doubleword
// that the vector was padded to. This means that it was VITAL that any
// vector needed any final padding word put in a definite and good state.
// Checking only the words that matter is just marginally quicker and
// will fail less often if I do not pad properly!
//
    l = (std::size_t)word_align_up(length_of_header(ha));
    if (vector_holds_binary(ha))
    {   while ((l -= 4) != 0)
            if (*((std::uint32_t *)((char *)a + l - TAG_VECTOR)) !=
                *((std::uint32_t *)((char *)b + l - TAG_VECTOR))) return false;
        return true;
    }
    else
    {   if (is_mixed_header(ha))
        {   while (l > 16)
            {   std::uint32_t ea = *((std::uint32_t *)((char *)a + l - TAG_VECTOR - 4)),
                         eb = *((std::uint32_t *)((char *)b + l - TAG_VECTOR - 4));
                if (ea != eb) return false;
                l -= 4;
            }
        }
        while ((l -= CELL) != 0)
        {   LispObject ea = *((LispObject *)((char *)a + l - TAG_VECTOR)),
                       eb = *((LispObject *)((char *)b + l - TAG_VECTOR));
            if (ea == eb) continue;
            if (!equal(ea, eb)) return false;
        }
        return true;
    }
}

bool equalp(LispObject a, LispObject b)
//
// a and b are not EQ at this stage.. I guarantee to have checked that
// before entering this general purpose code.
//
{
//
// The for loop at the top here is so that equalp can iterate along the
// length of linear lists.
//
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("Stack too deep in equalp\n");
        return false;
    }
#endif
    for (;;)
    {   std::int32_t ta = (std::int32_t)a & TAG_BITS;
        if (ta == TAG_CONS && a != nil)
        {   if (!consp(b) || b == nil) return false;
            else
            {   LispObject ca = car(a), cb = car(b);
                if (ca == cb)
                {   a = cdr(a);
                    b = cdr(b);
                    if (a == b) return true;
                    continue;
                }
//
// And here, because equalp() seems to be a very important low-level
// primitive, I unwind one level of the recursion that would arise
// with nested lists.
//
                for (;;)
                {   std::int32_t tca = (std::int32_t)ca & TAG_BITS;
                    if (tca == TAG_CONS && ca != nil)
                    {   if (!consp(cb) || cb == nil) return false;
                        else
                        {   LispObject cca = car(ca), ccb = car(cb);
                            if (cca == ccb)
                            {   ca = cdr(ca);
                                cb = cdr(cb);
                                if (ca == cb) break;
                                continue;
                            }
//
// Do a real recursion when I get down to args like
// ((x ...) ...) ((y ...) ...)
//
                            if (!equalp(cca, ccb)) return false;
                            ca = cdr(ca);
                            cb = cdr(cb);
                            if (ca == cb) break;
                            continue;
                        }
                    }
                    else if (is_immed_cons_sym(tca) ||
                             ((std::int32_t)cb & TAG_BITS) != tca) return false;
                    else switch (tca)
                        {   case TAG_NUMBERS:
                            {   Header h = numhdr(ca);
                                if (h != numhdr(cb)) return false;
                                if (type_of_header(h) == TYPE_BIGNUM)
                                {   std::intptr_t hh = (std::intptr_t)length_of_header(h) - TAG_NUMBERS;
                                    while (hh > (std::intptr_t)(CELL - TAG_NUMBERS))
                                    {   hh -= 4;
                                        if (*(std::uint32_t *)((char *)ca + hh) !=
                                            *(std::uint32_t *)((char *)cb + hh))
                                            return false;
                                    }
                                    break;
                                }
                                else if (!eql_numbers(ca, cb)) return false;
                                else break;
                            }
                            case TAG_VECTOR:
// /* At present vec_equal() is not right here
                                if (!vec_equal(ca, cb)) return false;
                                break;
                            default:
                            case TAG_BOXFLOAT:
                            {   Header h = flthdr(ca);
                                if (h != flthdr(cb)) return false;
                                if (!SIXTY_FOUR_BIT &&
                                    type_of_header(h) == TYPE_SINGLE_FLOAT)
                                {   if (single_float_val(ca) !=
                                        single_float_val(cb)) return false;
                                    else break;
                                }
                                else if (type_of_header(h) == TYPE_DOUBLE_FLOAT)
                                {   if (double_float_val(ca) !=
                                        double_float_val(cb)) return false;
                                    else break;
                                }
#ifdef HAVE_SOFTFLOAT
                                else if (!f128_eq(
                                    float128_of_number(ca),
                                    float128_of_number(cb))) return false;
                                else break;
#else
                                else return false;
#endif // HAVE_SOFTFLOAT
                            }
                        }
                    break;  // out of the for (;;) loop
                }
                a = cdr(a);
                b = cdr(b);
                if (a == b) return true;
                continue;
            }
        }
        else if (is_immed_cons_sym(ta) ||
                 ((std::int32_t)b & TAG_BITS) != ta) return false;
// What is left is vectors, strings and boxed numbers
        else switch (ta)
            {   case TAG_NUMBERS:
                {   Header h = numhdr(a);
                    if (h != numhdr(b)) return false;
                    if (type_of_header(h) == TYPE_BIGNUM)
                    {   std::intptr_t hh = (std::intptr_t)length_of_header(h) - TAG_NUMBERS;
                        while (hh > (std::intptr_t)(CELL - TAG_NUMBERS))
                        {   hh -= 4;
                            if (*(std::uint32_t *)((char *)a + hh) !=
                                *(std::uint32_t *)((char *)b + hh))
                                return false;
                        }
                        return true;
                    }
                    else return eql_numbers(a, b);
                }
                case TAG_VECTOR:
// /* wrong for Common Lisp
                    return vec_equal(a, b);
                default:
                case TAG_BOXFLOAT:
                {   Header h = flthdr(a);
                    if (h != flthdr(b)) return false;
                    if (!SIXTY_FOUR_BIT &&
                        type_of_header(h) == TYPE_SINGLE_FLOAT)
                    {   if (single_float_val(a) != single_float_val(b))
                            return false;
                        else return true;
                    }
                    else if (type_of_header(h) == TYPE_DOUBLE_FLOAT)
                    {   if (double_float_val(a) != double_float_val(b))
                            return false;
                        else return true;
                    }
#ifdef HAVE_SOFTFLOAT
                    else return f128_eq(
                        float128_of_number(a),
                        float128_of_number(b));
#else
                    else return false;
#endif // HAVE_SOFTFLOAT
                }
            }
    }
}

LispObject Leq(LispObject env, LispObject a, LispObject b)
{   return onevalue(Lispify_predicate(a == b));
}

LispObject Leql(LispObject env,
                LispObject a, LispObject b)
{   return onevalue(Lispify_predicate(eql(a, b)));
}

LispObject Leqcar(LispObject env, LispObject a, LispObject b)
{   if (!consp(a)) return onevalue(nil);
    a = car(a);
    return onevalue(Lispify_predicate(eqcheck(a, b)));
}

LispObject Lequalcar(LispObject env, LispObject a, LispObject b)
{   if (!consp(a)) return onevalue(nil);
    a = car(a);
    if (a == b) return lisp_true;
    else return onevalue(Lispify_predicate(equal(a, b)));
}

LispObject Lcl_equal(LispObject env, LispObject a, LispObject b)
{   if (a == b) return onevalue(lisp_true);
    else return onevalue(Lispify_predicate(cl_equal(a, b)));
}

LispObject Lequal(LispObject env, LispObject a, LispObject b)
{   if (a == b) return onevalue(lisp_true);
    else return onevalue(Lispify_predicate(equal(a, b)));
}

LispObject Lequalp(LispObject env, LispObject a, LispObject b)
{   if (a == b) return onevalue(lisp_true);
    else return onevalue(Lispify_predicate(equalp(a, b)));
}

LispObject Lneq_2(LispObject env, LispObject a, LispObject b)
{   bool r;
#ifdef COMMON
    r = cl_equal(a, b);
#else
//
// Note that "equal" here is a macro that expands to something that
// checks the EQ case in-line, so there is no merit in putting
//   if (a == b) return onevalue(nil);
// first.
//
    r = equal(a, b);
#endif
    return onevalue(Lispify_predicate(!r));
}

LispObject Lnull(LispObject env, LispObject a)
{   return onevalue(Lispify_predicate(a == nil));
}

LispObject Lendp(LispObject env, LispObject a)
{   if (a == nil) return onevalue(lisp_true);
    else if (is_cons(a)) return onevalue(nil);
    else error(1, err_bad_endp, a);
}

LispObject Lnreverse(LispObject env, LispObject a)
{   LispObject b = nil;
    if (is_vector(a))
    {   std::intptr_t n = Llength(nil, a) - 0x10;
        std::intptr_t i = TAG_FIXNUM;
        while (n > i)
        {   LispObject w = Laref_2(nil, a, i);
            Laset_3(nil, a, i, Laref_2(nil, a, n));
            Laset_3(nil, a, n, w);
            i += 0x10;
            n -= 0x10;
        }
        return onevalue(a);
    }
    while (consp(a))
    {   LispObject c = a;
        a = cdr(a);
        setcdr(c, b);
        write_barrier(cdraddr(c));
        b = c;
    }
    return onevalue(b);
}

LispObject Lnreverse2(LispObject env, LispObject a, LispObject b)
{   while (consp(a))
    {   LispObject c = a;
        a = cdr(a);
        setcdr(c, b);
        write_barrier(cdraddr(c));
        b = c;
    }
    return onevalue(b);
}

LispObject Lnrevlist_2(LispObject env, LispObject b, LispObject a)
{   push(a);
    b = ncons(b);
    pop(a);
    while (consp(a))
    {   LispObject c = a;
        a = cdr(a);
        setcdr(c, b);
        write_barrier(cdraddr(c));
        b = c;
    }
    return onevalue(b);
}

LispObject Lnrevlist_3(LispObject env, LispObject a, LispObject b, LispObject c)
{   push(a);
    b = list2(b, c);
    pop(a);
    while (consp(a))
    {   LispObject d = a;
        a = cdr(a);
        setcdr(d, b);
        write_barrier(cdraddr(d));
        b = d;
    }
    return onevalue(b);
}

//
// nreverse0 is like nreverse except that if its input is atomic it gets
// returned intact rather than being converted to nil.
//

LispObject Lnreverse0(LispObject env, LispObject a)
{   LispObject b = nil;
    if (!consp(a)) return onevalue(a);
    b = a;
    a = cdr(a);
    setcdr(b, nil);
    while (consp(a))
    {   LispObject c = a;
        a = cdr(a);
        setcdr(c, b);
        write_barrier(cdraddr(c));
        b = c;
    }
    return onevalue(b);
}

LispObject Lreverse(LispObject env, LispObject a)
{   LispObject r;
    stackcheck(a);
    r = nil;
    while (consp(a))
    {   push(a);
        r = cons(car(a), r);
        pop(a);
        a = cdr(a);
    }
    return onevalue(r);
}

#ifdef DEBUG_ASSOC
static std::int64_t assoc_calls = 0, assoc_length = 0, assoc_max = 0; //@@
#endif

LispObject Lassoc(LispObject env, LispObject a, LispObject b)
{
#ifdef TRACED_EQUAL
    LispObject save_b = b;
    int pos = 0;
#endif
#ifdef DEBUG_ASSOC
    std::int64_t this_assoc = 0;
    if ((assoc_calls % 1000) == 999)
        term_printf("Assoc %.3f av length %.1f max %.1f calls\n",
                    (double)assoc_length/(double)assoc_calls,
                    (double)assoc_max,
                    (double)assoc_calls);
    assoc_calls++;
#endif
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   LispObject c = car(b);
#ifdef DEBUG_ASSOC
            assoc_length++;
            if (assoc_length > 100*assoc_calls) aerror("average search for assoc");
            if (++this_assoc > assoc_max) assoc_max = this_assoc;
//!!        if (assoc_max > 1000) aerror("length for assoc");
#endif
            if (consp(c) && a == car(c)) return onevalue(c);
            b = cdr(b);
        }
        return onevalue(nil);
    }
    while (consp(b))
    {   LispObject c = car(b);
        if (consp(c))
        {   LispObject cc = car(c);
#ifdef DEBUG_ASSOC
            assoc_length++;
            if (++this_assoc > assoc_max) assoc_max = this_assoc;
//!!        if (assoc_max > 1000) aerror("length for assoc");
#endif
#ifdef COMMON
            if (cl_equal(a, cc)) return onevalue(c);
#else
            if (equal(a, cc))
            {
#ifdef TRACED_EQUAL
//
// In silly cases the length might not be a fixnum!
//
                trace_printf("Assoc true %3d %3d ", pos, int_of_fixnum(Llength(nil,save_b)));
                prin_to_stdout(a); trace_printf("\n");
#endif
                return onevalue(c);
            }
#endif
        }
        b = cdr(b);
#ifdef TRACED_EQUAL
        pos++;
#endif
    }
#ifdef TRACED_EQUAL
// beware stupidly long lists...
    trace_printf("Assoc false  %3d %3d ", pos, int_of_fixnum(Llength(nil,save_b)));
    prin_to_stdout(a); trace_printf("\n");
#endif
    return onevalue(nil);
}

LispObject Latsoc(LispObject env, LispObject a, LispObject b)
{
#ifdef COMMON
//
// See comments under atsoc...
//
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   LispObject c = car(b);
            if (consp(c) && a == car(c)) return onevalue(c);
            b = cdr(b);
        }
        return onevalue(nil);
    }
#endif
    while (consp(b))
    {   LispObject c = car(b);
//
// As for memq I unroll the loop a little...
// eql() can neither fail nor call the garbage collector, so I do
// not need to stack things here.
//
        if (consp(c) && eqcheck(a, car(c))) return onevalue(c);
        b = cdr(b);
        if (!consp(b)) return onevalue(nil);
        c = car(b);
        if (consp(c) && eqcheck(a, car(c))) return onevalue(c);
        b = cdr(b);
        if (!consp(b)) return onevalue(nil);
        c = car(b);
        if (consp(c) && eqcheck(a, car(c))) return onevalue(c);
        b = cdr(b);
        if (!consp(b)) return onevalue(nil);
        c = car(b);
        if (consp(c) && eqcheck(a, car(c))) return onevalue(c);
        b = cdr(b);
    }
    return onevalue(nil);
}

LispObject Lmember(LispObject env, LispObject a, LispObject b)
{   if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   if (a == car(b)) return onevalue(b);
            b = cdr(b);
            if (!consp(b)) return onevalue(nil);
            if (a == car(b)) return onevalue(b);
            b = cdr(b);
            if (!consp(b)) return onevalue(nil);
            if (a == car(b)) return onevalue(b);
            b = cdr(b);
            if (!consp(b)) return onevalue(nil);
            if (a == car(b)) return onevalue(b);
            b = cdr(b);
        }
        return onevalue(nil);
    }
    while (consp(b))
    {   LispObject cb = car(b);
#ifdef COMMON
        if (cl_equal(a, cb)) return onevalue(b);
#else
        if (equal(a, cb)) return onevalue(b);
#endif
        b = cdr(b);
    }
    return onevalue(nil);
}

LispObject Lmemq(LispObject env, LispObject a, LispObject b)
{
#ifdef COMMON
//
// I think it is possible that the test I need here is more along the
// lines of "is it a number that is not a fixnum" since EQL only
// diverges from EQ in that case... However I will not adjust this right
// now since I am not at present too concerned about Common Lisp mode...
//
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   if (a == car(b)) return onevalue(b);
            b = cdr(b);
        }
        return onevalue(nil);
    }
#endif
    while (consp(b))
    {
//
// I have unrolled this loop a bit because I found that in one of the
// Reduce tests it was a serious hot-spot.
//
        if (eqcheck(a, car(b))) return onevalue(b);
        b = cdr(b);
        if (!consp(b)) return onevalue(nil);
        if (eqcheck(a, car(b))) return onevalue(b);
        b = cdr(b);
        if (!consp(b)) return onevalue(nil);
        if (eqcheck(a, car(b))) return onevalue(b);
        b = cdr(b);
        if (!consp(b)) return onevalue(nil);
        if (eqcheck(a, car(b))) return onevalue(b);
        b = cdr(b);
    }
    return onevalue(nil);
}

static bool smemq(LispObject a, LispObject b)
{
//
// /* This is a bit worrying - it can use C recursion to arbitrary
// depth without any checking for overflow, and hence it can ESCAPE
// if (e.g.) given cyclic structures.  Some alteration is needed.  As
// things stand the code can never give wrong answers via GC rearrangement -
// the problem is closer to being that it can never call the GC.
//
    while (consp(b))
    {   LispObject w = car(b);
        if (w == quote_symbol) return false;
        else if (smemq(a, w)) return true;
        else b = cdr(b);
    }
    return (a == b);
}

LispObject Lsmemq(LispObject env, LispObject a, LispObject b)
{   bool r;
    r = smemq(a, b);
    return onevalue(Lispify_predicate(r));
}

//
//  (defun contained (x y)
//     (cond ((atom y) (equal x y))
//           ((equal x y) 't)
//           ('t (or (contained x (car y)) (contained x (cdr y))))))
//

static bool containedeq(LispObject env, LispObject x, LispObject y)
{   while (consp(y))
    {   if (containedeq(nil, x, car(y))) return true;
        y = cdr(y);
    }
    return (x == y);
}

static bool containedequal(LispObject env, LispObject x, LispObject y)
{   while (consp(y))
    {   if (equal(x, y)) return true;
        if (containedequal(nil, x, car(y))) return true;
        y = cdr(y);
    }
    return equal(x, y);
}

static LispObject Lcontained(LispObject env, LispObject x, LispObject y)
{   bool r;
    if (is_symbol(x) || is_fixnum(x)) r = containedeq(nil, x, y);
    else r = containedequal(nil, x, y);
    return onevalue(Lispify_predicate(r));
}

LispObject Llast(LispObject env, LispObject a)
{   LispObject b;
    if (!consp(a)) aerror1("last", a);
    while (b = cdr(a), consp(b)) a = b;
    return onevalue(car(a));
}

LispObject Llastpair(LispObject env, LispObject a)
{   LispObject b;
    if (!consp(a)) return onevalue(a); // aerror1("lastpair", a);
    while (b = cdr(a), consp(b)) a = b;
    return onevalue(a);
}

LispObject Llength(LispObject env, LispObject a)
{   if (a == nil) return onevalue(fixnum_of_int(0));
    if (is_cons(a))
    {   std::size_t n = 1;
//
// Possibly I should do something to trap cyclic lists.. But doing so
// would tend to be extra cost so unless it becomes a vital issue because
// of some bug I will not worry.
//
// I have unrolled the loop here 4 times since I expect length to be
// tolerably heavily used. Look at the assembly code generated for
// this to see if it was useful or counterproductive!
//
        for (;;)
        {   a = cdr(a);
            if (!consp(a)) break;
            a = cdr(a);
            if (!consp(a))
            {   n += 1;
                break;
            }
            a = cdr(a);
            if (!consp(a))
            {   n += 2;
                break;
            }
            a = cdr(a);
            if (!consp(a))
            {   n += 3;
                break;
            }
            n += 4;
        }
        a = make_lisp_unsigned64(n);
        return onevalue(a);
    }
//
// Common Lisp expects length to find the length of vectors
// as well as lists. I might as well do that in Standard Lisp mode
// too. Otherwise length of atoms (except NIL) lead to zero.
//
    else if (is_vector(a))
    {   Header h = vechdr(a);
        std::size_t n = length_of_header(h) - CELL;
// If at any stage I move to a segmented representation for huge vectors I
// will need to re-work this!
        if (type_of_header(h) == TYPE_ARRAY)
        {   LispObject dims = elt(a, 1);
            LispObject fillp = elt(a, 5);
            if (consp(dims) && !consp(cdr(dims))) dims = car(dims);
            else aerror1("length", a);  // Not one-dimensional
            if (is_fixnum(fillp)) dims = fillp;
            return onevalue(dims);
        }
        if (is_bitvec_header(h)) n = length_of_bitheader(h) - 8*CELL;
        else if (is_string_header(h)) n = length_of_byteheader(h) - CELL;
        else n = (length_of_header(h) - CELL)/CELL;
        a = make_lisp_unsigned64(n);
        return onevalue(a);
    }
    else return onevalue(fixnum_of_int(0));
}

LispObject Lappend_1(LispObject, LispObject a)
{   return onevalue(a);
}

LispObject Lappend_2(LispObject env, LispObject a, LispObject b)
{   LispObject r = nil;
    push(b);
    stackcheck(a, r);
    while (consp(a))
    {   push(cdr(a));
        r = cons(car(a), r);
        pop(a);
    }
    pop(b);
    while (r != nil)
    {   a = cdr(r);
        setcdr(r, b);
        write_barrier(cdraddr(r));
        b = r;
        r = a;
    }
    return onevalue(b);
}

LispObject Lappend_3(LispObject env, LispObject a, LispObject b, LispObject c)
{   push(a);
    b = Lappend_2(nil, b, c);
    pop(a);
    return Lappend_2(nil, a, b);
}

LispObject Lappend_4up(LispObject env, LispObject a1, LispObject a2,
        LispObject a3, LispObject a4up)
{   push(a1, a2, a3);
// Note that the list of arguments from a4 upwards will be freshly consed
// and so I am entitled to overwrite it as I go.
    a4up = nreverse(a4up);
    LispObject r = car(a4up);
    a4up = cdr(a4up);
    while (a4up != nil)
    {   LispObject w = car(a4up);
        push(cdr(a4up));
        r = Lappend_2(nil, w, r);
        pop(a4up);
    }
    pop(a3);
    r = Lappend_2(nil, a3, r);
    pop(a2);
    r = Lappend_2(nil, a2, r);
    pop(a1);
    return onevalue(Lappend_2(nil, a1, r));
}

LispObject Ldelete(LispObject env, LispObject a, LispObject b)
{   LispObject r;
    push(a, b);
    r = nil;
    if (is_symbol(a) || is_fixnum(a))
    {   while (consp(b))
        {   LispObject q = car(b);
            if (q == stack[-1])
            {   b = cdr(b);
                break;
            }
            stack[0] = cdr(b);
            r = cons(car(b), r);
            b = stack[0];
        }
    }
    else
    {   while (consp(b))
        {   LispObject q = car(b);
#ifdef COMMON
            if (cl_equal(q, a))
#else
            if (equal(q, a))
#endif
            {   b = cdr(b);
                break;
            }
            stack[0] = cdr(b);
            r = cons(car(b), r);
            b = stack[0];
            a = stack[-1];
        }
    }
    popv(2);
    while (r != nil)
    {   LispObject w = cdr(r);
        setcdr(r, b);
        write_barrier(cdraddr(r));
        b = r;
        r = w;
    }
    return onevalue(b);
}


LispObject Ldeleq(LispObject env, LispObject a, LispObject b)
{   LispObject r;
    push(a, b);
    r = nil;
    while (consp(b))
    {   LispObject q = car(b);
        if (q == stack[-1])
        {   b = cdr(b);
            break;
        }
        stack[0] = cdr(b);
        r = cons(car(b), r);
        b = stack[0];
    }
    popv(2);
    while (r != nil)
    {   LispObject w = cdr(r);
        setcdr(r, b);
        write_barrier(cdraddr(r));
        b = r;
        r = w;
    }
    return onevalue(b);
}

LispObject Lnconc(LispObject env, LispObject a, LispObject b)
{   LispObject c;
    if (!consp(a)) return onevalue(b);
    c = a;
    for (;;)
    {   LispObject next = cdr(c);
        if (!consp(next))
        {   setcdr(c, b);
            write_barrier(cdraddr(c));
            return onevalue(a);
        }
        else c = next;
    }
}

// If the versions of SUBST and friends as implemented here work by
// (temporarily) overwriting their input then they are probably not
// suitable for use in a multi-thread version of this system. So
// all the complication here will need to be revisited. Oh dear. Well
// when I have a conservative garbage collection at least the replacement
// code will not have to include the messy mapping of names onto stack
// locations!

//
// All the comments that follow are the signature of me needing to think
// carefully while implementing a version of the code here that will
// not recurse in the CDR direction.
//
// subst(a, b, c)
//   if b = c then a
//   else if atom c then c
//   else subst(a, b, car c) . subst(a, b, cdr c);
//
// Now the logic of a version that iterates along the list...
//
//
//  orig                                      R             C
//   |                                        |             |
//   V                                        V             V
//  ---------    ---------    ---------     ---------     ---------
//  | X1|   +--->| X2|   +--->|X' | / |     |X' | : |     | Z |   +--->
//  =========    =========    =========     ======+==     =========
//                              ^                 |
//                              L-----------------J
//
//
//                    RX
//                     |
//                     V
//     ---------     ---------
//     | Y1| / |     | Y2| : |
//     ---------     ------+--
//       ^                 |
//       L-----------------J
//
//
// The original list C started at orig, and the cells X contain their original
// content there, while the result of substitution on them gives the values Y
// shown in the list accessed via RX.
//
// The reversed section of the original list from R back has values where
// substitution leaves them unaltered, so they are suitable for inclusion
// in the result. The reversed chains ends in cells marked "/" in the
// diagram - that can be any non-pair. I will use the fixnum zero. You might
// have expected me to use nil, but I will not because the nil variable is
// used at times to hold an error flag. The reversed chain at RX contains
// data that has needed to be copied, and so Y2 NEQ X2.
//
// The fragment of the original starting from C contains original data (Z) that
// has not yet been inspected.
//
// There is a procedure referred to here as "normalising"  that restores the
// pointers from R backwars to be forward pointers, and as it does so correspoding
// new items are placed on the RX list. It leaves R=nil.
//
//  orig                                          R:0       C
//   |                                                      |
//   V                                                      V
//  ---------    ---------    ---------     ---------     ---------
//  | X |   +--->| X |   +--->| X |   +---->| X |   +---->| Z |   +--->
//  =========    =========    =========     =========     =========
//
//                                                 RX
//                                                  |
//                                                  V
//     ---------     ---------      ---------     ---------
//     | Y | / |     | Y | : |      | Y | : |     | Y | : |
//     ---------     ------+--      ------+--     ------+--
//       ^            ^    |          ^   |             |
//       |            |    |          |   |             |
//       L------------+----J          L---+-------------J
//                    |                   |
//                    L-------------------J
//
// There is a futher procedure known here as "unwinding" that can be
// performed after normalisation. It takes a value in C and reverses
// pointers back from R (thereby restoring the original list). It then
// reverses the RX list onto the front to deliver a final result.
//
// The very initial situation is
//
//   C       RX:0  R:0
//   |
//   V
//  ---------
//  | X |   +--->
//  =========
//
//
// Each step first checks if C as a whole is to be replaced.
//     "if b = c then a"
// from the first line of the simple version. If so and if a!=c then
// you normalise, set c=a then unwind.
//
// If the above substitution occurs but a=c or if c is atomic
// just unwind.
//
// Now c is non-atomic. Recurse to process car(c). If this
// is unchanged then extent the reversed list ar R. This may need
// special care when the list is empty to start with.
//
// If the substitution on car c proceed something that differeed
// then normalise and push the new result onto rx.
//
//


//
// The above treatment is required for four functions
//     subst, substq
//     sublis, subla
//


static LispObject substq(LispObject a, LispObject b, LispObject c)
{   LispObject w;
    stackcheck(a, b, c);
    push(TAG_FIXNUM, TAG_FIXNUM); // rx and r
    push(a, b, c);
// Perhaps I could replace the use of "#define" here with code like
//    LispObject &c = stack[0];
//    LispObject &b = stack[-1];
//    etc.
// which would perhaps be cleaner.
//
#define c   stack[0]
#define b   stack[-1]
#define a   stack[-2]
#define r   stack[-3]
#define rx  stack[-4]
    for (;;)
    {   if (c == b)
        {   if (c == a) break; // substitute by leaving unchanged
//
// Here I need to restore the part of the list from R backwards and
// then copy it to RX.
//
            LispObject cc = c;
            while (r != TAG_FIXNUM)
            {   w = cdr(r);
                setcdr(r, cc);
                write_barrier(cdraddr(r));
                cc = r;
                r = w;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   w = cons(car(r), rx);
                rx = w;
                r = cdr(r);
            }
            c = a;
            r = TAG_FIXNUM;
            break;
        }
        if (!consp(c)) break;
// Recurse in CAR direction
        on_backtrace(
            w = substq(a, b, car(c)),
// If the recursive call fails I need to unshare before exit.
            while (r != TAG_FIXNUM)
            {   w = cdr(r);
                setcdr(r, c);
                write_barrier(cdraddr(r));
                c = r;
                r = w;
            });
//
// If the replacement is in fact identical to the original I will
// need to pend any copy operations
//
        if (w == car(c))
        {   w = cdr(c);
            setcdr(c, r);
            write_barrier(cdraddr(c));
            r = c;
            c = w;
            continue;
        }
// Otherwise I may need to unpend any pending copy operations...
        else
        {   LispObject cc = c, ww;
            while (r != TAG_FIXNUM)
            {   ww = cdr(r);
                setcdr(r, cc);
                write_barrier(cdraddr(r));
                cc = r;
                r = ww;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   LispObject u = car(r), v = rx;
                push(w);
                ww = cons(u, v);
                pop(w);
                rx = ww;
                r = cdr(r);
            }
            w = cons(w, rx);
            rx = w;
            c = cdr(c);
            r = TAG_FIXNUM;
        }
    }
#undef c
#undef b
#undef a
#undef r
#undef rx
    pop(c, b, a);
    {   LispObject r, rx;
        pop(r, rx);
        while (r != TAG_FIXNUM)
        {   w = cdr(r);
            setcdr(r, c);
            write_barrier(cdraddr(r));
            c = r;
            r = w;
        }
//
// I have now restored the input list, so if I was taking an early exit
// because EQUAL had failed on me I can give up now.
//
        while (rx != TAG_FIXNUM)
        {   w = cdr(rx);
            setcdr(rx, c);
            write_barrier(cdraddr(rx));
            c = rx;
            rx = w;
        }
    }
    return onevalue(c);
}



LispObject subst(LispObject a, LispObject b, LispObject c)
{   LispObject w;
    stackcheck(a, b, c);
    push(TAG_FIXNUM, TAG_FIXNUM); // rx and r
    push(a, b, c);
#define c   stack[0]
#define b   stack[-1]
#define a   stack[-2]
#define r   stack[-3]
#define rx  stack[-4]
    for (;;)
    {
#ifdef COMMON
        if (cl_equal(c, b))
#else
        if (equal(c, b))
#endif
        {
// if EQUAL said "yes" then it can not have failed.
            if (c == a) break; // substitute by leaving unchanged
//
// Here I need to restore the part of the list from R backwards and
// then copy it to RX.
//
            LispObject cc = c;
            while (r != TAG_FIXNUM)
            {   w = cdr(r);
                setcdr(r, cc);
                write_barrier(cdraddr(r));
                cc = r;
                r = w;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   w = cons(car(r), rx);
                rx = w;
                r = cdr(r);
            }
            c = a;
            r = TAG_FIXNUM;
            break;
        }
// equal may fail with a stack overflow, and if it does it will return
// false (and set the exception marker). In that case I must recover and
// undo any damage I have done to input lists.
        if (!consp(c)) break;
// Recurse in CAR direction
        on_backtrace(
            w = subst(a, b, car(c)),
// If the recursive call fails I need to unshare before exit.
            while (r != TAG_FIXNUM)
            {   w = cdr(r);
                setcdr(r, c);
                write_barrier(cdraddr(r));
                c = r;
                r = w;
            });
//
// If the replacement is in fact identical to the original I will
// need to pend any copy operations
//
        if (w == car(c))
        {   w = cdr(c);
            setcdr(c, r);
            write_barrier(cdraddr(c));
            r = c;
            c = w;
            continue;
        }
// Otherwise I may need to unpend any pending copy operations...
        else
        {   LispObject cc = c, ww;
            while (r != TAG_FIXNUM)
            {   ww = cdr(r);
                setcdr(r, cc);
                write_barrier(cdraddr(r));
                cc = r;
                r = ww;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   LispObject u = car(r), v = rx;
                push(w);
                ww = cons(u, v);
                pop(w);
                rx = ww;
                r = cdr(r);
            }
            w = cons(w, rx);
            rx = w;
            c = cdr(c);
            r = TAG_FIXNUM;
        }
    }
#undef c
#undef b
#undef a
#undef r
#undef rx
    pop(c, b, a);
    {   LispObject r, rx;
        pop(r, rx);
        while (r != TAG_FIXNUM)
        {   w = cdr(r);
            setcdr(r, c);
            write_barrier(cdraddr(r));
            c = r;
            r = w;
        }
//
// I have now restored the input list, so if I was taking an early exit
// because EQUAL had failed on me I can give up now.
//
        while (rx != TAG_FIXNUM)
        {   w = cdr(rx);
            setcdr(rx, c);
            write_barrier(cdraddr(rx));
            c = rx;
            rx = w;
        }
    }
    return onevalue(c);
}


LispObject subla(LispObject a, LispObject c)
{   LispObject w;
    stackcheck(a, c);
    push(TAG_FIXNUM, TAG_FIXNUM); // rx and r
    push(a, c);
#define c   stack[0]
#define a   stack[-1]
#define r   stack[-2]
#define rx  stack[-3]
    for (;;)
    {   LispObject tt = a;
        bool found = false;
        while (consp(tt))
        {   LispObject tta = car(tt);
            if (consp(tta) && c == car(tta))
            {   tt = cdr(tta);
                found = true;
                break;
            }
            tt = cdr(tt);
        }
        if (found)
        {   if (c == tt) break; // substitute by leaving unchanged
//
// Here I need to restore the part of the list from R backwards and
// then copy it to RX.
//
            LispObject cc = c;
            while (r != TAG_FIXNUM)
            {   w = cdr(r);
                setcdr(r, cc);
                write_barrier(cdraddr(r));
                cc = r;
                r = w;
            }
// The input data is now restored
            a = tt;
            r = cc;
            while (r != c)
            {   w = cons(car(r), rx);
                rx = w;
                r = cdr(r);
            }
            c = a;
            r = TAG_FIXNUM;
            break;
        }
        if (!consp(c)) break;
// Recurse in CAR direction
        on_backtrace(
            w = subla(a, car(c)),
// If the recursive call fails I need to unshare before exit.
            while (r != TAG_FIXNUM)
            {   w = cdr(r);
                setcdr(r, c);
                write_barrier(cdraddr(r));
                c = r;
                r = w;
            });
//
// If the replacement is in fact identical to the original I will
// need to pend any copy operations
//
        if (w == car(c))
        {   w = cdr(c);
            setcdr(c, r);
            write_barrier(cdraddr(c));
            r = c;
            c = w;
            continue;
        }
// Otherwise I may need to unpend any pending copy operations...
        else
        {   LispObject cc = c, ww;
            while (r != TAG_FIXNUM)
            {   ww = cdr(r);
                setcdr(r, cc);
                write_barrier(cdraddr(r));
                cc = r;
                r = ww;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   LispObject u = car(r), v = rx;
                push(w);
                ww = cons(u, v);
                pop(w);
                rx = ww;
                r = cdr(r);
            }
            w = cons(w, rx);
            rx = w;
            c = cdr(c);
            r = TAG_FIXNUM;
        }
    }
#undef c
#undef a
#undef r
#undef rx
    pop(c, a);
    {   LispObject r, rx;
        pop(r, rx);
        while (r != TAG_FIXNUM)
        {   w = cdr(r);
            setcdr(r, c);
            write_barrier(cdraddr(r));
            c = r;
            r = w;
        }
//
// I have now restored the input list, so if I was taking an early exit
// because EQUAL had failed on me I can give up now.
//
        while (rx != TAG_FIXNUM)
        {   w = cdr(rx);
            setcdr(rx, c);
            write_barrier(cdraddr(rx));
            c = rx;
            rx = w;
        }
    }
    return onevalue(c);
}


LispObject sublis(LispObject a, LispObject c)
{   LispObject w;
    stackcheck(a, c);
    push(TAG_FIXNUM, TAG_FIXNUM); // rx and r
    push(a, c);
#define c   stack[0]
#define a   stack[-1]
#define r   stack[-2]
#define rx  stack[-3]
    for (;;)
    {   LispObject tt = a;
        bool found = false;
        while (consp(tt))
        {   LispObject tta = car(tt);
#ifdef COMMON
            if (consp(tta) && cl_equal(c, car(tta)))
#else
            if (consp(tta) && equal(c, car(tta)))
#endif
            {   tt = cdr(tta);
                found = true;
                break;
            }
            tt = cdr(tt);
        }
        if (found)
        {
// if EQUAL had said "yes" then it can not have failed.
            if (c == tt) break; // substitute by leaving unchanged
//
// Here I need to restore the part of the list from R backwards and
// then copy it to RX.
//
            LispObject cc = c;
            while (r != TAG_FIXNUM)
            {   w = cdr(r);
                setcdr(r, cc);
                write_barrier(cdraddr(r));
                cc = r;
                r = w;
            }
// The input data is now restored
            a = tt;
            r = cc;
            while (r != c)
            {   w = cons(car(r), rx);
                rx = w;
                r = cdr(r);
            }
            c = a;
            r = TAG_FIXNUM;
            break;
        }
// equal may fail with a stack overflow, and if it does it will return
// false (and set the exception marker). In that case I must recover and
// undo any damage I have done to input lists.
        if (!consp(c)) break;
// Recurse in CAR direction
        on_backtrace(
            w = sublis(a, car(c)),
// If the recursive call fails I need to unshare before exit.
            while (r != TAG_FIXNUM)
            {   w = cdr(r);
                setcdr(r, c);
                write_barrier(cdraddr(r));
                c = r;
                r = w;
            });
//
// If the replacement is in fact identical to the original I will
// need to pend any copy operations
//
        if (w == car(c))
        {   w = cdr(c);
            setcdr(c, r);
            write_barrier(cdraddr(c));
            r = c;
            c = w;
            continue;
        }
// Otherwise I may need to unpend any pending copy operations...
        else
        {   LispObject cc = c, ww;
            while (r != TAG_FIXNUM)
            {   ww = cdr(r);
                setcdr(r, cc);
                write_barrier(cdraddr(r));
                cc = r;
                r = ww;
            }
// The input data is now restored
            r = cc;
            while (r != c)
            {   LispObject u = car(r), v = rx;
                push(w);
                ww = cons(u, v);
                pop(w);
                rx = ww;
                r = cdr(r);
            }
            w = cons(w, rx);
            rx = w;
            c = cdr(c);
            r = TAG_FIXNUM;
        }
    }
#undef c
#undef a
#undef r
#undef rx
    pop(c, a);
    {   LispObject r, rx;
        pop(r, rx);
        while (r != TAG_FIXNUM)
        {   w = cdr(r);
            setcdr(r, c);
            write_barrier(cdraddr(r));
            c = r;
            r = w;
        }
//
// I have now restored the input list, so if I was taking an early exit
// because EQUAL had failed on me I can give up now.
//
        while (rx != TAG_FIXNUM)
        {   w = cdr(rx);
            setcdr(rx, c);
            write_barrier(cdraddr(rx));
            c = rx;
            rx = w;
        }
    }
    return onevalue(c);
}



LispObject Lsubstq(LispObject env, LispObject a, LispObject b, LispObject c)
{
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("subst");
    }
#endif
    return substq(a, b, c);
}

LispObject Lsubst(LispObject env, LispObject a, LispObject b, LispObject c)
{
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("subst");
    }
#endif
    if (c == b) return onevalue(a);
    else if (is_symbol(b) || is_fixnum(b)) return substq(a, b, c);
    else return subst(a, b, c);
}

LispObject Lsublis(LispObject env, LispObject al, LispObject x)
{   stackcheck(al, x);
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("sublis");
    }
#endif
    if (!consp(al)) return onevalue(x);
    else return sublis(al, x);
}


LispObject Lsubla(LispObject env, LispObject al, LispObject x)
//
// as sublis, but uses eq test rather than equal
//
{   stackcheck(al, x);
#ifdef CHECK_STACK
    if (check_stack("@" __FILE__,__LINE__))
    {   show_stack();
        aerror("subla");
    }
#endif
    if (!consp(al)) return onevalue(x);
    else return subla(al, x);
}


setup_type const funcs2_setup[] =
{   {"all-symbols",             Lall_symbols0, Lall_symbols, G2Wother, G3Wother, G4Wother},
    {"assoc",                   G0W1, G1W2, Lassoc, G3W2, G4W2},
//
// assoc** is expected to remain as the Standard Lisp version even if in
// a Common Lisp world I redefine assoc to be something messier. xassoc was
// an earlier name I used for the same purpose, and is being withdrawn.
//
    {"assoc**",                 G0W1, G1W2, Lassoc, G3W2, G4W2},
    {"xassoc",                  G0W1, G1W2, Lassoc, G3W2, G4W2},
    {"atsoc",                   G0W1, G1W2, Latsoc, G3W2, G4W2},
    {"member",                  G0W1, G1W2, Lmember, G3W2, G4W2},
    {"member**",                G0W1, G1W2, Lmember, G3W2, G4W2},
    {"memq",                    G0W1, G1W2, Lmemq, G3W2, G4W2},
    {"contained",               G0W1, G1W2, Lcontained, G3W2, G4W2},
//
// I originally called this restart!-csl but I am now changing the name
// to be restart!-lisp to be a little less specific about exactly which
// implementation of Lisp is involved. IN the fullness of time I will
// remove the name restart!-csl...
//
    {"restart-lisp",            G0Wother, Lrestart_lisp, Lrestart_lisp2, G3Wother, G4Wother},
    {"restart-csl",             G0Wother, Lrestart_lisp, Lrestart_lisp2, G3Wother, G4Wother},
    {"eq",                      G0W1, G1W2, Leq, G3W2, G4W2},
    {"iequal",                  G0W1, G1W2, Leq, G3W2, G4W2},
    {"eqcar",                   G0W1, G1W2, Leqcar, G3W2, G4W2},
    {"equalcar",                G0W1, G1W2, Lequalcar, G3W2, G4W2},
    {"eql",                     G0W1, G1W2, Leql, G3W2, G4W2},
    {"equalp",                  G0W1, G1W2, Lequalp, G3W2, G4W2},
    {"endp",                    G0W1, Lendp, G2W1, G3W1, G4W1},
    {"getd",                    G0W1, Lgetd, G2W1, G3W1, G4W1},
    {"last",                    G0W1, Llast, G2W1, G3W1, G4W1},
    {"lastpair",                G0W1, Llastpair, G2W1, G3W1, G4W1},
    {"length",                  G0W1, Llength, G2W1, G3W1, G4W1},
    {"make-bps",                G0W1, Lget_bps, G2W1, G3W1, G4W1},
    {"symbol-env",              G0W1, Lsymbol_env, G2W1, G3W1, G4W1},
    {"symbol-make-fastget",     G0Wother, Lsymbol_make_fastget1, Lsymbol_make_fastget, G3Wother, G4Wother},
    {"symbol-fastgets",         G0W1, Lsymbol_fastgets, G2W1, G3W1, G4W1},
    {"object-header",           G0W1, Lobject_header, G2W1, G3W1, G4W1},
    {"symbol-fn-cell",          G0W1, Lsymbol_fn_cell, G2W1, G3W1, G4W1},
    {"symbol-argcode",          G0W1, Lsymbol_argcount, G2W1, G3W1, G4W1},
    {"symbol-argcount",         G0W1, Lsymbol_argcount, G2W1, G3W1, G4W1},
    {"symbol-set-env",          G0W1, G1W2, Lsymbol_set_env, G3W2, G4W2},
    {"symbol-set-definition",   G0W1, G1W2, Lsymbol_set_definition, G3W2, G4W2},
    {"restore-c-code",          G0W1, Lrestore_c_code, G2W1, G3W1, G4W1},
    {"set-autoload",            G0W1, G1W2, Lset_autoload, G3W2, G4W2},
    {"remd",                    G0W1, Lremd, G2W1, G3W1, G4W1},
    {"trace",                   G0W1, Ltrace, G2W1, G3W1, G4W1},
    {"untrace",                 G0W1, Luntrace, G2W1, G3W1, G4W1},
    {"traceset",                G0W1, Ltraceset, G2W1, G3W1, G4W1},
    {"untraceset",              G0W1, Luntraceset, G2W1, G3W1, G4W1},
    {"macro-function",          G0W1, Lmacro_function, G2W1, G3W1, G4W1},
    {"symbol-name",             G0W1, Lsymbol_name, G2W1, G3W1, G4W1},
    {"id2string",               G0W1, Lsymbol_name, G2W1, G3W1, G4W1},
    {"plist",                   G0W1, Lplist, G2W1, G3W1, G4W1},
    {"prop",                    G0W1, Lplist, G2W1, G3W1, G4W1},
    {"delete",                  G0W1, G1W2, Ldelete, G3W2, G4W2},
    {"deleq",                   G0W1, G1W2, Ldeleq, G3W2, G4W2},
    {"preserve",                Lpreserve_0, Lpreserve_1, Lpreserve_2, Lpreserve_3, G4Wother},
    {"mkvect",                  G0W1, Lmkvect, G2W1, G3W1, G4W1},
    {"nconc",                   G0W1, G1W2, Lnconc, G3W2, G4W2},
    {"neq",                     G0W1, G1W2, Lneq_2, G3W2, G4W2},
    {"not",                     G0W1, Lnull, G2W1, G3W1, G4W1},
    {"null",                    G0W1, Lnull, G2W1, G3W1, G4W1},
    {"resource-exceeded",       Lresource_exceeded, G1W0, G2W0, G3W0, G4W0},
    {"reverse",                 G0W1, Lreverse, G2W1, G3W1, G4W1},
    {"reversip",                G0Wother, Lnreverse, Lnreverse2, G3Wother, G4Wother},
// I make the name nreverse generally available as well as reversip
    {"nreverse",                G0Wother, Lnreverse, Lnreverse2, G3Wother, G4Wother},
// also reversip2 for the 2-arg varient
    {"reversip2",               G0W2, G1W2, Lnreverse2, G3W2, G4W2},
    {"nrevlist",                G0Wother, G1Wother, Lnrevlist_2, Lnrevlist_3, G4Wother},
    {"smemq",                   G0W1, G1W2, Lsmemq, G3W2, G4W2},
    {"subla",                   G0W1, G1W2, Lsubla, G3W2, G4W2},
    {"sublis",                  G0W1, G1W2, Lsublis, G3W2, G4W2},
    {"subst",                   G0W3, G1W3, G2W3, Lsubst, G4W3},
    {"substq",                  G0W3, G1W3, G2W3, Lsubstq, G4W3},
    {"symbol-protect",          G0W1, G1W2, Lsymbol_protect, G3W2, G4W2},
    {"symbol-plist",            G0W1, Lplist, G2W1, G3W1, G4W1},
    {"append",                  Lnilfn, Lappend_1, Lappend_2, Lappend_3, Lappend_4up},
//
// In Common Lisp mode I make EQUAL do what Common Lisp says it should, but
// also have EQUALS that is much the same but which also descends vectors.
//
//  {"equal",                   G0W1, G1W2, Lcl_equal, G3W2, G4W2},
//  {"equals",                  G0W1, G1W2, Lequal, G3W2, G4W2},
//  {"nreverse0",               G0W1, Lnreverse0, G2W1, G3W1, G4W1},
// In Standard Lisp mode EQUAL descends vectors (but does not case fold)
// I provide cl-equal to do what Common Lisp does.
    {"cl-equal",                G0W1, G1W2, Lcl_equal, G3W2, G4W2},
    {"equal",                   G0W1, G1W2, Lequal, G3W2, G4W2},
    {"member",                  G0W1, G1W2, Lmember, G3W2, G4W2},
    {"symbol-package",          G0W1, Lsymbol_package, G2W1, G3W1, G4W1},
    {"serialize",               G0W1, Lserialize, G2W1, G3W1, G4W1},
    {"full-serialize",          G0W1, Lserialize1, G2W1, G3W1, G4W1},
    {"unserialize",             Lunserialize, G1W0, G2W0, G3W0, G4W0},
    {NULL,                      0, 0, 0, 0, 0}
};

// end of fns2.cpp