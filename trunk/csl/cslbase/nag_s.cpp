// This code was contributed to CSL by NAG Ltd

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


// $Id: nag_s.cpp 5179 2019-10-31 16:20:08Z arthurcnorman $


#if 1
LispObject Ls01eaf(LispObject env, int nargs, ...)
{   std::va_list args;
    LispObject Lzr, Lzi, Lifail, Lwr, Lwi;
    double z[2], w[2];
    std::int32_t ifail;

    //
    // Returning DOUBLE COMPLEX objects via the function name is not portable
    // so we use a dummy subroutine as glue.
    //

#ifdef LOADLIB
    typedef void (__stdcall *PSXXEAF) (double *, double *, std::int32_t *);
    HINSTANCE hLib;
    PSXXEAF sxxeaf_proc;
#else
    extern void __stdcall SXXEAF (double *, double *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,3,"Ls01eaf");
    va_start(args,nargs);
    Lzr = va_arg(args, LispObject);
    Lzi = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lzr,Lzi,Lifail);
    z[0] = float_of_number(Lzr);
    pop(Lifail,Lzi,Lzr);
    push(Lzr,Lzi,Lifail);
    z[1] = float_of_number(Lzi);
    pop(Lifail,Lzi,Lzr);
    push(Lzr,Lzi,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lzi,Lzr);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfasj")) == NULL )   // FIXME (jackets)
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (sxxeaf_proc = (PSXXEAF) GetProcAddress (hLib, "_SXXEAF@12"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*sxxeaf_proc) (z, w, &ifail);
        }
    }

    currlib = hLib;
#else
    SXXEAF(z,w,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lwr = make_boxfloat(w[0],TYPE_DOUBLE_FLOAT);
    push(Lwr);
    Lwi = make_boxfloat(w[1],TYPE_DOUBLE_FLOAT);
    pop(Lwr);
    push(Lwr,Lwi);
    Lifail = int2ccl(ifail);
    pop(Lwi,Lwr);

    return Llist(nil,3,Lwr,Lwi,Lifail);
}

LispObject Ls13aaf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS13AAF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS13AAF s13aaf_proc;
#else
    extern double __stdcall S13AAF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s13aaf_proc = (PS13AAF) GetProcAddress (hLib, "_S13AAF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s13aaf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S13AAF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}
#endif

LispObject Ls13acf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS13ACF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS13ACF s13acf_proc;
#else
    extern double __stdcall S13ACF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s13acf_proc = (PS13ACF) GetProcAddress (hLib, "_S13ACF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s13acf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S13ACF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls13adf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS13ADF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS13ADF s13adf_proc;
#else
    extern double __stdcall S13ADF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s13adf_proc = (PS13ADF) GetProcAddress (hLib, "_S13ADF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s13adf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S13ADF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls14aaf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS14AAF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS14AAF s14aaf_proc;
#else
    extern double __stdcall S14AAF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s14aaf_proc = (PS14AAF) GetProcAddress (hLib, "_S14AAF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s14aaf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S14AAF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls14abf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS14ABF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS14ABF s14abf_proc;
#else
    extern double __stdcall S14ABF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s14abf_proc = (PS14ABF) GetProcAddress (hLib, "_S14ABF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s14abf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S14ABF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls14baf(LispObject env, int nargs, ...)
{   std::va_list args;
    LispObject La, Lx, Ltol, Lp, Lq, Lifail;
    double a, x, tol, p, q;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef void (__stdcall *PS14BAF) (double *, double *, double *, double *,
                                       double *, std::int32_t *);
    HINSTANCE hLib;
    PS14BAF s14baf_proc;
#else
    extern void __stdcall S14BAF (double *, double *, double *, double *,
                                  double *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,4,"Ls14baf");
    va_start(args,nargs);
    La = va_arg(args, LispObject);
    Lx = va_arg(args, LispObject);
    Ltol = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(La,Lx,Ltol,Lifail);
    a = float_of_number(La);
    pop(Lifail,Ltol,Lx,La);
    push(La,Lx,Ltol,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Ltol,Lx,La);
    push(La,Lx,Ltol,Lifail);
    tol = float_of_number(Ltol);
    pop(Lifail,Ltol,Lx,La);
    push(La,Lx,Ltol,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Ltol,Lx,La);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s14baf_proc = (PS14BAF) GetProcAddress (hLib, "_S14BAF@24"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*s14baf_proc) (&a, &x, &tol, &p, &q, &ifail);
        }
    }

    currlib = hLib;
#else
    S14BAF (&a, &x, &tol, &p, &q, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lp = make_boxfloat(p,TYPE_DOUBLE_FLOAT);
    push(Lp);
    Lq = make_boxfloat(q,TYPE_DOUBLE_FLOAT);
    pop(Lp);
    push(Lp,Lq);
    Lifail = int2ccl(ifail);
    pop(Lq,Lp);

    return Llist(nil,3,Lp,Lq,Lifail);
}

LispObject Ls15adf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS15ADF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS15ADF s15adf_proc;
#else
    extern double __stdcall S15ADF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s15adf_proc = (PS15ADF) GetProcAddress (hLib, "_S15ADF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s15adf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S15ADF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls15aef(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS15AEF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS15AEF s15aef_proc;
#else
    extern double __stdcall S15AEF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s15aef_proc = (PS15AEF) GetProcAddress (hLib, "_S15AEF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s15aef_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S15AEF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls17acf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS17ACF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS17ACF s17acf_proc;
#else
    extern double __stdcall S17ACF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17acf_proc = (PS17ACF) GetProcAddress (hLib, "_S17ACF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s17acf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S17ACF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls17adf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS17ADF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS17ADF s17adf_proc;
#else
    extern double __stdcall S17ADF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17adf_proc = (PS17ADF) GetProcAddress (hLib, "_S17ADF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s17adf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S17ADF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls17aef(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS17AEF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS17AEF s17aef_proc;
#else
    extern double __stdcall S17AEF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17aef_proc = (PS17AEF) GetProcAddress (hLib, "_S17AEF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s17aef_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S17AEF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls17aff(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS17AFF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS17AFF s17aff_proc;
#else
    extern double __stdcall S17AFF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17aff_proc = (PS17AFF) GetProcAddress (hLib, "_S17AFF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s17aff_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S17AFF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls17agf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS17AGF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS17AGF s17agf_proc;
#else
    extern double __stdcall S17AGF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17agf_proc = (PS17AGF) GetProcAddress (hLib, "_S17AGF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s17agf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S17AGF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls17ahf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS17AHF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS17AHF s17ahf_proc;
#else
    extern double __stdcall S17AHF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17ahf_proc = (PS17AHF) GetProcAddress (hLib, "_S17AHF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s17ahf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S17AHF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls17ajf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS17AJF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS17AJF s17ajf_proc;
#else
    extern double __stdcall S17AJF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17ajf_proc = (PS17AJF) GetProcAddress (hLib, "_S17AJF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s17ajf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S17AJF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls17akf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS17AKF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS17AKF s17akf_proc;
#else
    extern double __stdcall S17AKF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17akf_proc = (PS17AKF) GetProcAddress (hLib, "_S17AKF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s17akf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S17AKF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

#if 1
LispObject Ls17dcf(LispObject env, int nargs, ...)
{   // FIXME: strings
    std::va_list args;
    LispObject Lzr, Lzi, Lscale, Lifail, Ln, Lnz, Lfnu, Lcy;
    fstring1 scale;
    double z[2], *cy, *cwrk, fnu;
    std::int32_t n, nz, ifail;
    char sscale[2];

#ifdef LOADLIB
    typedef void (__stdcall *PS17DCF) (double *, double *, std::int32_t *, fstring1,
                                       double *, std::int32_t *, double *, std::int32_t *);
    HINSTANCE hLib;
    PS17DCF s17dcf_proc;
#else
    extern void __stdcall S17DCF (double *, double *, std::int32_t *, fstring1,
                                  double *, std::int32_t *, double *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,6,"Ls17dcf");
    va_start(args,nargs);
    Lfnu = va_arg(args, LispObject);
    Lzr = va_arg(args, LispObject);
    Lzi = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Lscale = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    fnu = float_of_number(Lfnu);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    z[0] = float_of_number(Lzr);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    z[1] = float_of_number(Lzi);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
    sscale[0] = celt(Lscale,0);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    sscale[1] = '\0';
    scale.str = sscale;
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);

    scale.len = 1;

    // Setup workspace arrays etc.
    cy = (double *)std::malloc(n*2*sizeof(double));    // "complex" array
    cwrk = (double *)std::malloc(n*2*sizeof(double));  // "complex" array

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17dcf_proc = (PS17DCF) GetProcAddress (hLib, "_S17DCF@36"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*s17dcf_proc) (&fnu, z, &n, scale, cy, &nz, cwrk, &ifail);
        }
    }

    currlib = hLib;
#else
    S17DCF(&fnu, z, &n, scale, cy, &nz, cwrk, &ifail);
#endif
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);

    // Translate return values to CCL
    // Copy result
    Lcy = mkComplexVector(cy,n,1);
    push(Lcy);
    Lifail = int2ccl(ifail);
    pop(Lcy);
    push(Lcy,Lifail);
    Lnz = int2ccl(nz);
    pop(Lifail,Lcy);

    std::free (cy);
    std::free (cwrk);

    return Llist(nil,3,Lcy,Lifail,Lnz);
}
#else
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ls17def(LispObject env, int nargs, ...)
{   // FIXME: strings
    std::va_list args;
    LispObject Lzr, Lzi, Lscale, Lifail, Ln, Lnz, Lfnu, Lcy;
    fstring1 scale;
    double z[2], *cy, fnu;
    std::int32_t n, nz, ifail;
    char sscale[2];

#ifdef LOADLIB
    typedef void (__stdcall *PS17DEF) (double *, double *, std::int32_t *, fstring1,
                                       double *, std::int32_t *, std::int32_t *);
    HINSTANCE hLib;
    PS17DEF s17def_proc;
#else
    extern void __stdcall S17DEF (double *, double *, std::int32_t *, fstring1,
                                  double *, std::int32_t *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,6,"Ls17def");
    va_start(args,nargs);
    Lfnu = va_arg(args, LispObject);
    Lzr = va_arg(args, LispObject);
    Lzi = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Lscale = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    fnu = float_of_number(Lfnu);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    z[0] = float_of_number(Lzr);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    z[1] = float_of_number(Lzi);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
    sscale[0] = celt(Lscale,0);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    sscale[1] = '\0';
    scale.str = sscale;
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);

    scale.len = 1;

    // Setup workspace arrays etc.
    cy = (double *)std::malloc(n*2*sizeof(double));    // "complex" array

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17def_proc = (PS17DEF) GetProcAddress (hLib, "_S17DEF@32"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*s17def_proc) (&fnu, z, &n, scale, cy, &nz, &ifail);
        }
    }

    currlib = hLib;
#else
    S17DEF(&fnu, z, &n, scale, cy, &nz, &ifail);
#endif
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);

    // Translate return values to CCL
    // Copy result
    Lcy = mkComplexVector(cy,n,1);
    push(Lcy);
    Lifail = int2ccl(ifail);
    pop(Lcy);
    push(Lcy,Lifail);
    Lnz = int2ccl(nz);
    pop(Lifail,Lcy);

    std::free (cy);

    return Llist(nil,3,Lcy,Lifail,Lnz);
}
#else
{   return Llist(nil, 0);
}
#endif

LispObject Ls17dgf(LispObject env, int nargs, ...)
{   // FIXME: strings
    std::va_list args;
    LispObject Lderiv, Lzr, Lzi, Lscale, Lifail, Lair, Laii, Lnz;
    fstring1 deriv, scale;
    double z[2], ai[2];
    std::int32_t nz, ifail;
    char sderiv[2], sscale[2];

#ifdef LOADLIB
    typedef void (__stdcall *PS17DGF) (fstring1, double *, fstring1, double *,
                                       std::int32_t *, std::int32_t *);
    HINSTANCE hLib;
    PS17DGF s17dgf_proc;
#else
    extern void __stdcall S17DGF (fstring1, double *, fstring1, double *,
                                  std::int32_t *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,5,"Ls17dgf");
    va_start(args,nargs);
    Lderiv = va_arg(args, LispObject);
    Lzr = va_arg(args, LispObject);
    Lzi = va_arg(args, LispObject);
    Lscale = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lderiv,Lzr,Lzi,Lscale,Lifail);
//  strncpy (sderiv, &celt(Lderiv,0), 1);
    sderiv[0] = celt(Lderiv,0);
    pop(Lifail,Lscale,Lzi,Lzr,Lderiv);
    sderiv[1] = '\0';
    deriv.str = sderiv;
    push(Lderiv,Lzr,Lzi,Lscale,Lifail);
    z[0] = float_of_number(Lzr);
    pop(Lifail,Lscale,Lzi,Lzr,Lderiv);
    push(Lderiv,Lzr,Lzi,Lscale,Lifail);
    z[1] = float_of_number(Lzi);
    pop(Lifail,Lscale,Lzi,Lzr,Lderiv);
    push(Lderiv,Lzr,Lzi,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
    sscale[0] = celt(Lscale,0);
    pop(Lifail,Lscale,Lzi,Lzr,Lderiv);
    sscale[1] = '\0';
    scale.str = sscale;
    push(Lderiv,Lzr,Lzi,Lscale,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lscale,Lzi,Lzr,Lderiv);

    deriv.len = 1;
    scale.len = 1;

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17dgf_proc = (PS17DGF) GetProcAddress (hLib, "_S17DGF@32"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*s17dgf_proc) (deriv, z, scale, ai, &nz, &ifail);
        }
    }

    currlib = hLib;
#else
    S17DGF(deriv, z, scale, ai, &nz, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lair = make_boxfloat(ai[0],TYPE_DOUBLE_FLOAT);
    push(Lair);
    Laii = make_boxfloat(ai[1],TYPE_DOUBLE_FLOAT);
    pop(Lair);
    push(Lair,Laii);
    Lifail = int2ccl(ifail);
    pop(Laii,Lair);
    push(Lair,Laii,Lifail);
    Lnz = int2ccl(nz);
    pop(Lifail,Laii,Lair);

    return Llist(nil,4,Lair,Laii,Lifail,Lnz);
}

LispObject Ls17dhf(LispObject env, int nargs, ...)
{   // FIXME: strings
    std::va_list args;
    LispObject Lderiv, Lzr, Lzi, Lscale, Lifail, Lbir, Lbii;
    fstring1 deriv, scale;
    double z[2], bi[2];
    std::int32_t ifail;
    char sderiv[2], sscale[2];

#ifdef LOADLIB
    typedef void (__stdcall *PS17DHF) (fstring1, double *, fstring1, double *,
                                       std::int32_t *);
    HINSTANCE hLib;
    PS17DHF s17dhf_proc;
#else
    extern void __stdcall S17DHF (fstring1, double *, fstring1, double *,
                                  std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,5,"Ls17dhf");
    va_start(args,nargs);
    Lderiv = va_arg(args, LispObject);
    Lzr = va_arg(args, LispObject);
    Lzi = va_arg(args, LispObject);
    Lscale = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lderiv,Lzr,Lzi,Lscale,Lifail);
//  strncpy (sderiv, &celt(Lderiv,0), 1);
    sderiv[0] = celt(Lderiv,0);
    pop(Lifail,Lscale,Lzi,Lzr,Lderiv);
    sderiv[1] = '\0';
    deriv.str = sderiv;
    push(Lderiv,Lzr,Lzi,Lscale,Lifail);
    z[0] = float_of_number(Lzr);
    pop(Lifail,Lscale,Lzi,Lzr,Lderiv);
    push(Lderiv,Lzr,Lzi,Lscale,Lifail);
    z[1] = float_of_number(Lzi);
    pop(Lifail,Lscale,Lzi,Lzr,Lderiv);
    push(Lderiv,Lzr,Lzi,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
    sscale[0] = celt(Lscale,0);
    pop(Lifail,Lscale,Lzi,Lzr,Lderiv);
    sscale[1] = '\0';
    scale.str = sscale;
    push(Lderiv,Lzr,Lzi,Lscale,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lscale,Lzi,Lzr,Lderiv);

    deriv.len = 1;
    scale.len = 1;

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17dhf_proc = (PS17DHF) GetProcAddress (hLib, "_S17DHF@28"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*s17dhf_proc) (deriv, z, scale, bi, &ifail);
        }
    }

    currlib = hLib;
#else
    S17DHF(deriv, z, scale, bi, &ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lbir = make_boxfloat(bi[0],TYPE_DOUBLE_FLOAT);
    push(Lbir);
    Lbii = make_boxfloat(bi[1],TYPE_DOUBLE_FLOAT);
    pop(Lbir);
    push(Lbir,Lbii);
    Lifail = int2ccl(ifail);
    pop(Lbii,Lbir);

    return Llist(nil,3,Lbir,Lbii,Lifail);
}

#if 1
LispObject Ls17dlf(LispObject env, int nargs, ...)
{   // FIXME: strings
    std::va_list args;
    LispObject Lzr, Lzi, Lscale, Lifail, Ln, Lnz, Lfnu, Lcy, Lm;
    fstring1 scale;
    double z[2], *cy, fnu;
    std::int32_t n, nz, ifail, m;
    char sscale[2];

#ifdef LOADLIB
    typedef void (__stdcall *PS17DLF) (std::int32_t *, double *, double *, std::int32_t *,
                                       fstring1, double *, std::int32_t *, std::int32_t *);
    HINSTANCE hLib;
    PS17DLF s17dlf_proc;
#else
    extern void __stdcall S17DLF (std::int32_t *, double *, double *, std::int32_t *,
                                  fstring1, double *, std::int32_t *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,7,"Ls17dlf");
    va_start(args,nargs);
    Lm = va_arg(args, LispObject);
    Lfnu = va_arg(args, LispObject);
    Lzr = va_arg(args, LispObject);
    Lzi = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Lscale = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lm,Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    m = thirty_two_bits(Lm);
    pop(Lifail,Lscale,Ln,Lzi);
    pop(Lzr,Lfnu,Lm);
    push(Lm,Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    fnu = float_of_number(Lfnu);
    pop(Lifail,Lscale,Ln,Lzi);
    pop(Lzr,Lfnu,Lm);
    push(Lm,Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    z[0] = float_of_number(Lzr);
    pop(Lifail,Lscale,Ln,Lzi);
    pop(Lzr,Lfnu,Lm);
    push(Lm,Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    z[1] = float_of_number(Lzi);
    pop(Lifail,Lscale,Ln,Lzi);
    pop(Lzr,Lfnu,Lm);
    push(Lm,Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Lscale,Ln,Lzi);
    pop(Lzr,Lfnu,Lm);
    push(Lm,Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
    sscale[0] = celt(Lscale,0);
    pop(Lifail,Lscale,Ln,Lzi);
    pop(Lzr,Lfnu,Lm);
    sscale[1] = '\0';
    scale.str = sscale;
    push(Lm,Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lscale,Ln,Lzi);
    pop(Lzr,Lfnu,Lm);
    push(Lm,Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);

    scale.len = 1;

    // Setup workspace arrays etc.
    cy = (double *)std::malloc(n*2*sizeof(double));    // "complex" array

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s17dlf_proc = (PS17DLF) GetProcAddress (hLib, "_S17DLF@36"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*s17dlf_proc) (&m, &fnu, z, &n, scale, cy, &nz, &ifail);
        }
    }

    currlib = hLib;
#else
    S17DLF(&m, &fnu, z, &n, scale, cy, &nz, &ifail);
#endif
    pop(Lifail,Lscale,Ln,Lzi);
    pop(Lzr,Lfnu,Lm);

    // Translate return values to CCL
    // Copy result
    Lcy = mkComplexVector(cy,n,1);
    push(Lcy);
    Lifail = int2ccl(ifail);
    pop(Lcy);
    push(Lcy,Lifail);
    Lnz = int2ccl(nz);
    pop(Lifail,Lcy);

    std::free (cy);

    return Llist(nil,3,Lcy,Lifail,Lnz);
}
#else
{   return Llist(nil, 0);
}
#endif

LispObject Ls18acf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS18ACF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS18ACF s18acf_proc;
#else
    extern double __stdcall S18ACF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s18acf_proc = (PS18ACF) GetProcAddress (hLib, "_S18ACF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s18acf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S18ACF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls18adf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS18ADF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS18ADF s18adf_proc;
#else
    extern double __stdcall S18ADF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s18adf_proc = (PS18ADF) GetProcAddress (hLib, "_S18ADF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s18adf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S18ADF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls18aef(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS18AEF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS18AEF s18aef_proc;
#else
    extern double __stdcall S18AEF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s18aef_proc = (PS18AEF) GetProcAddress (hLib, "_S18AEF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s18aef_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S18AEF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls18aff(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS18AFF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS18AFF s18aff_proc;
#else
    extern double __stdcall S18AFF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s18aff_proc = (PS18AFF) GetProcAddress (hLib, "_S18AFF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s18aff_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S18AFF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

#if 1
LispObject Ls18dcf(LispObject env, int nargs, ...)
{   // FIXME: strings
    std::va_list args;
    LispObject Lzr, Lzi, Lscale, Lifail, Ln, Lnz, Lfnu, Lcy;
    fstring1 scale;
    double z[2], *cy, fnu;
    std::int32_t n, nz, ifail;
    char sscale[2];

#ifdef LOADLIB
    typedef void (__stdcall *PS18DCF) (double *, double *, std::int32_t *, fstring1,
                                       double *, std::int32_t *, std::int32_t *);
    HINSTANCE hLib;
    PS18DCF s18dcf_proc;
#else
    extern void __stdcall S18DCF (double *, double *, std::int32_t *, fstring1,
                                  double *, std::int32_t *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,6,"Ls18dcf");
    va_start(args,nargs);
    Lfnu = va_arg(args, LispObject);
    Lzr = va_arg(args, LispObject);
    Lzi = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Lscale = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    fnu = float_of_number(Lfnu);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    z[0] = float_of_number(Lzr);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    z[1] = float_of_number(Lzi);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
    sscale[0] = celt(Lscale,0);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    sscale[1] = '\0';
    scale.str = sscale;
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);

    scale.len = 1;

    // Setup workspace arrays etc.
    cy = (double *)std::malloc(n*2*sizeof(double));    // "complex" array

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s18dcf_proc = (PS18DCF) GetProcAddress (hLib, "_S18DCF@32"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*s18dcf_proc) (&fnu, z, &n, scale, cy, &nz, &ifail);
        }
    }

    currlib = hLib;
#else
    S18DCF(&fnu, z, &n, scale, cy, &nz, &ifail);
#endif
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);

    // Translate return values to CCL
    // Copy result
    Lcy = mkComplexVector(cy,n,1);
    push(Lcy);
    Lifail = int2ccl(ifail);
    pop(Lcy);
    push(Lcy,Lifail);
    Lnz = int2ccl(nz);
    pop(Lifail,Lcy);

    std::free (cy);

    return Llist(nil,3,Lcy,Lifail,Lnz);
}
#else
{   return Llist(nil, 0);
}
#endif

#if 1
LispObject Ls18def(LispObject env, int nargs, ...)
{   // FIXME: strings
    std::va_list args;
    LispObject Lzr, Lzi, Lscale, Lifail, Ln, Lnz, Lfnu, Lcy;
    fstring1 scale;
    double z[2], *cy, fnu;
    std::int32_t n, nz, ifail;
    char sscale[2];

#ifdef LOADLIB
    typedef void (__stdcall *PS18DEF) (double *, double *, std::int32_t *, fstring1,
                                       double *, std::int32_t *, std::int32_t *);
    HINSTANCE hLib;
    PS18DEF s18def_proc;
#else
    extern void __stdcall S18DEF (double *, double *, std::int32_t *, fstring1,
                                  double *, std::int32_t *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,6,"Ls18def");
    va_start(args,nargs);
    Lfnu = va_arg(args, LispObject);
    Lzr = va_arg(args, LispObject);
    Lzi = va_arg(args, LispObject);
    Ln = va_arg(args, LispObject);
    Lscale = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    fnu = float_of_number(Lfnu);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    z[0] = float_of_number(Lzr);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    z[1] = float_of_number(Lzi);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    n = thirty_two_bits(Ln);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
//  strncpy (sscale, &celt(Lscale,0), 1);
    sscale[0] = celt(Lscale,0);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    sscale[1] = '\0';
    scale.str = sscale;
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);
    push(Lfnu,Lzr,Lzi);
    push(Ln,Lscale,Lifail);

    scale.len = 1;

    // Setup workspace arrays etc.
    cy = (double *)std::malloc(n*2*sizeof(double));    // "complex" array

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s18def_proc = (PS18DEF) GetProcAddress (hLib, "_S18DEF@32"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   (*s18def_proc) (&fnu, z, &n, scale, cy, &nz, &ifail);
        }
    }

    currlib = hLib;
#else
    S18DEF(&fnu, z, &n, scale, cy, &nz, &ifail);
#endif
    pop(Lifail,Lscale,Ln);
    pop(Lzi,Lzr,Lfnu);

    // Translate return values to CCL
    // Copy result
    Lcy = mkComplexVector(cy,n,1);
    push(Lcy);
    Lifail = int2ccl(ifail);
    pop(Lcy);
    push(Lcy,Lifail);
    Lnz = int2ccl(nz);
    pop(Lifail,Lcy);

    std::free (cy);

    return Llist(nil,3,Lcy,Lifail,Lnz);
}
#else
{   return Llist(nil, 0);
}
#endif

LispObject Ls19aaf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS19AAF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS19AAF s19aaf_proc;
#else
    extern double __stdcall S19AAF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s19aaf_proc = (PS19AAF) GetProcAddress (hLib, "_S19AAF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s19aaf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S19AAF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls19abf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS19ABF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS19ABF s19abf_proc;
#else
    extern double __stdcall S19ABF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s19abf_proc = (PS19ABF) GetProcAddress (hLib, "_S19ABF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s19abf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S19ABF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls19acf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS19ACF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS19ACF s19acf_proc;
#else
    extern double __stdcall S19ACF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s19acf_proc = (PS19ACF) GetProcAddress (hLib, "_S19ACF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s19acf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S19ACF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls19adf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS19ADF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS19ADF s19adf_proc;
#else
    extern double __stdcall S19ADF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s19adf_proc = (PS19ADF) GetProcAddress (hLib, "_S19ADF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s19adf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S19ADF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls20acf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS20ACF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS20ACF s20acf_proc;
#else
    extern double __stdcall S20ACF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s20acf_proc = (PS20ACF) GetProcAddress (hLib, "_S20ACF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s20acf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S20ACF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}

LispObject Ls20adf(LispObject env, LispObject Lx, LispObject Lifail)
{   LispObject Ly;
    double x, y;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS20ADF) (double *, std::int32_t *);
    HINSTANCE hLib;
    PS20ADF s20adf_proc;
#else
    extern double __stdcall S20ADF (double *, std::int32_t *);
#endif

    // Translate arguments into C objects
    push(Lx,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lx);
    push(Lx,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s20adf_proc = (PS20ADF) GetProcAddress (hLib, "_S20ADF@8"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   y = (*s20adf_proc) (&x, &ifail);
        }
    }

    currlib = hLib;
#else
    y = S20ADF(&x,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Ly = make_boxfloat(y,TYPE_DOUBLE_FLOAT);
    push(Ly);
    Lifail = int2ccl(ifail);
    pop(Ly);

    return Llist(nil,2,Ly,Lifail);
}


LispObject Ls21baf(LispObject env, int nargs, ...)
{   std::va_list args;
    LispObject Lx, Ly, Lifail, Lrc;
    double x, y, rc;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS21BAF) (double *, double *, std::int32_t *);
    HINSTANCE hLib;
    PS21BAF s21baf_proc;
#else
    extern double __stdcall S21BAF (double *, double *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,3,"Ls21baf");
    va_start(args,nargs);
    Lx = va_arg(args, LispObject);
    Ly = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lx,Ly,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Ly,Lx);
    push(Lx,Ly,Lifail);
    y = float_of_number(Ly);
    pop(Lifail,Ly,Lx);
    push(Lx,Ly,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Ly,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s21baf_proc = (PS21BAF) GetProcAddress (hLib, "_S21BAF@12"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   rc = (*s21baf_proc) (&x, &y, &ifail);
        }
    }

    currlib = hLib;
#else
    rc = S21BAF(&x,&y,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lrc = make_boxfloat(rc,TYPE_DOUBLE_FLOAT);
    push(Lrc);
    Lifail = int2ccl(ifail);
    pop(Lrc);

    return Llist(nil,2,Lrc,Lifail);
}

LispObject Ls21bbf(LispObject env, int nargs, ...)
{   std::va_list args;
    LispObject Lx, Ly, Lz, Lifail, Lrf;
    double x, y, z, rf;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS21BBF) (double *, double *, double *, std::int32_t *);
    HINSTANCE hLib;
    PS21BBF s21bbf_proc;
#else
    extern double __stdcall S21BBF (double *, double *, double *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,4,"Ls21bbf");
    va_start(args,nargs);
    Lx = va_arg(args, LispObject);
    Ly = va_arg(args, LispObject);
    Lz = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lx,Ly,Lz,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lz,Ly,Lx);
    push(Lx,Ly,Lz,Lifail);
    y = float_of_number(Ly);
    pop(Lifail,Lz,Ly,Lx);
    push(Lx,Ly,Lz,Lifail);
    z = float_of_number(Lz);
    pop(Lifail,Lz,Ly,Lx);
    push(Lx,Ly,Lz,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lz,Ly,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s21bbf_proc = (PS21BBF) GetProcAddress (hLib, "_S21BBF@16"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   rf = (*s21bbf_proc) (&x, &y, &z, &ifail);
        }
    }

    currlib = hLib;
#else
    rf = S21BBF(&x,&y,&z,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lrf = make_boxfloat(rf,TYPE_DOUBLE_FLOAT);
    push(Lrf);
    Lifail = int2ccl(ifail);
    pop(Lrf);

    return Llist(nil,2,Lrf,Lifail);
}

LispObject Ls21bcf(LispObject env, int nargs, ...)
{   std::va_list args;
    LispObject Lx, Ly, Lz, Lifail, Lrd;
    double x, y, z, rd;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS21BCF) (double *, double *, double *, std::int32_t *);
    HINSTANCE hLib;
    PS21BCF s21bcf_proc;
#else
    extern double __stdcall S21BCF (double *, double *, double *, std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,4,"Ls21bcf");
    va_start(args,nargs);
    Lx = va_arg(args, LispObject);
    Ly = va_arg(args, LispObject);
    Lz = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lx,Ly,Lz,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lz,Ly,Lx);
    push(Lx,Ly,Lz,Lifail);
    y = float_of_number(Ly);
    pop(Lifail,Lz,Ly,Lx);
    push(Lx,Ly,Lz,Lifail);
    z = float_of_number(Lz);
    pop(Lifail,Lz,Ly,Lx);
    push(Lx,Ly,Lz,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lz,Ly,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s21bcf_proc = (PS21BCF) GetProcAddress (hLib, "_S21BCF@16"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   rd = (*s21bcf_proc) (&x, &y, &z, &ifail);
        }
    }

    currlib = hLib;
#else
    rd = S21BCF(&x,&y,&z,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lrd = make_boxfloat(rd,TYPE_DOUBLE_FLOAT);
    push(Lrd);
    Lifail = int2ccl(ifail);
    pop(Lrd);

    return Llist(nil,2,Lrd,Lifail);
}

LispObject Ls21bdf(LispObject env, int nargs, ...)
{   std::va_list args;
    LispObject Lx, Ly, Lz, Lr, Lifail, Lrj;
    double x, y, z, r, rj;
    std::int32_t ifail;

#ifdef LOADLIB
    typedef double (__stdcall *PS21BDF) (double *, double *, double *, double *,
                                         std::int32_t *);
    HINSTANCE hLib;
    PS21BDF s21bdf_proc;
#else
    extern double __stdcall S21BDF (double *, double *, double *, double *,
                                    std::int32_t *);
#endif

    // Set up arguments as Lisp Objects
    argcheck(nargs,5,"Ls21bdf");
    va_start(args,nargs);
    Lx = va_arg(args, LispObject);
    Ly = va_arg(args, LispObject);
    Lz = va_arg(args, LispObject);
    Lr = va_arg(args, LispObject);
    Lifail = va_arg(args, LispObject);
    va_end(args);

    // Translate arguments into C objects
    push(Lx,Ly,Lz,Lr,Lifail);
    x = float_of_number(Lx);
    pop(Lifail,Lr,Lz,Ly,Lx);
    push(Lx,Ly,Lz,Lr,Lifail);
    y = float_of_number(Ly);
    pop(Lifail,Lr,Lz,Ly,Lx);
    push(Lx,Ly,Lz,Lr,Lifail);
    z = float_of_number(Lz);
    pop(Lifail,Lr,Lz,Ly,Lx);
    push(Lx,Ly,Lz,Lr,Lifail);
    r = float_of_number(Lr);
    pop(Lifail,Lr,Lz,Ly,Lx);
    push(Lx,Ly,Lz,Lr,Lifail);
    ifail = thirty_two_bits(Lifail);
    pop(Lifail,Lr,Lz,Ly,Lx);

    // Call NAG routine
#ifdef LOADLIB
    free_prevlib ();

    if ( (hLib = LoadLibrary ("nagfas")) == NULL )
    {   // couldn't find DLL -- error handling here
        ifail = -999;
    }
    else  // OK so far
    {   if ( (s21bdf_proc = (PS21BDF) GetProcAddress (hLib, "_S21BDF@20"))
             == NULL )
        {   // couldn't find function within DLL -- error handling here
            ifail = -998;
        }
        else    // have found function in DLL
        {   rj = (*s21bdf_proc) (&x, &y, &z, &r, &ifail);
        }
    }

    currlib = hLib;
#else
    rj = S21BDF(&x,&y,&z,&r,&ifail);
#endif

    // Translate return values to CCL
    // Copy result
    Lrj = make_boxfloat(rj,TYPE_DOUBLE_FLOAT);
    push(Lrj);
    Lifail = int2ccl(ifail);
    pop(Lrj);

    return Llist(nil,2,Lrj,Lifail);
}

// end of nag_s.cpp