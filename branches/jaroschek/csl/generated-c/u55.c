
/* $destdir\u55.c        Machine generated C code */

/* $Id: $ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <time.h>
#ifndef _cplusplus
#include <setjmp.h>
#endif

#include "config.h"

#ifndef header_machine_h
#define header_machine_h 1
#if !defined UNDER_CE && !defined EMBEDDED
#if ((defined HAVE_SOCKET && defined HAVE_SYS_SOCKET_H) || defined WIN32)
#define SOCKETS                  1
#endif
#endif
#ifndef MS_CDECL
#ifdef _MSC_VER
#  define MS_CDECL __cdecl
#else
#  define MS_CDECL
#endif
#endif
#ifdef WIN32
#  if defined WIN64 || defined __WIN64__
#     define OPSYS           "win64"
#     define IMPNAME         "win64"
#  else
#     define OPSYS           "win32"
#     define IMPNAME         "win32"
#  endif
#else
#  ifdef HOST_OS
#     define OPSYS           HOST_OS
#     ifdef HOST_CPU
#        define IMPNAME      HOST_OS ":" HOST_CPU
#     else
#        define IMPNAME      HOST_OS
#     endif
#  else
#     define OPSYS           "Unknown"
#     define IMPNAME         "Generic"
#  endif
#endif
#ifdef HAVE_STDINT_H
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef  HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef  HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef  HAVE_U_INTPTR_T
typedef u_intptr_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_INT && (SIZEOF_INT == 4)
typedef unsigned int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef short int int32_t;
#define HAVE_INT32_T 1
#endif
#if !defined HAVE_UINT32_T && defined SIZEOF_SHORT_INT && (SIZEOF_SHORT_INT == 4)
typedef unsigned short int uint32_t;
#define HAVE_UINT32_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG && (SIZEOF_LONG == 8)
typedef unsigned long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef long long int64_t;
#define HAVE_INT64_T 1
#endif
#if !defined HAVE_UINT64_T && defined SIZEOF_LONG_LONG && (SIZEOF_LONG_LONG == 8)
typedef unsigned long long uint64_t;
#define HAVE_UINT64_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_INT32_T
typedef int32_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_INTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_INT64_T
typedef int64_t intptr_t;
#define HAVE_INTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 4) && defined HAVE_UINT32_T
typedef uint32_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#if !defined HAVE_UINTPTR_T && defined SIZEOF_VOID_P && (SIZEOF_VOID_P == 8) && defined HAVE_UINT64_T
typedef uint64_t uintptr_t;
#define HAVE_UINTPTR_T 1
#endif
#endif 
#endif 
#ifndef header_tags_h
#define header_tags_h 1
#if !defined HAVE_STDINT_H || !defined HAVE_INT32_T
#error This system needs a 32-bit integer type.
#endif
#define SIXTY_FOUR_BIT (sizeof(intptr_t) == 8)
typedef int                 CSLbool;
#define YES                 1
#define NO                  0
#ifndef PAGE_BITS
#  define PAGE_BITS             22
#endif 
#define PAGE_POWER_OF_TWO       (((uint32_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE           (PAGE_POWER_OF_TWO - 256U)
#ifndef MAX_HEAPSIZE
#  define MAX_HEAPSIZE       (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
#  define MAX_BPSSIZE           64
#endif 
#define MEGABYTE                ((uint32_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES               (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES           (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES               (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES           (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES        MAX_BPS_PAGES
#define CSL_IGNORE(x)           (x = x)
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK       0xff
typedef intptr_t Lisp_Object;
#define CELL sizeof(Lisp_Object)
#define TAG_BITS        7
#define TAG_CONS        0   
                            
#define TAG_FIXNUM      1   
#define TAG_ODDS        2   
#ifdef COMMON
#define TAG_SFLOAT      3   
#endif 
#define TAG_SYMBOL      4   
#define TAG_NUMBERS     5   
#define TAG_VECTOR      6   
#define TAG_BOXFLOAT    7   
#define fixnum_of_int(x)    ((Lisp_Object)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) < 0 ?           \
                             (((int32_t)(x))>>4) | (-0x10000000) :  \
                             (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x)    ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I        8               
#define GC_BIT_H        8               
#define GC_BIT_P        ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w)      (((int)(w) & GC_BIT_I) != 0)
extern Lisp_Object address_sign;  
#define is_marked_p(w)      (((Lisp_Object)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((Lisp_Object)(w) & ~GC_BIT_P) + \
                              address_sign)
#define flip_mark_bit_i(w)  ((Lisp_Object)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w)  ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w)  ((Lisp_Object)(w) ^ GC_BIT_P)
#define is_marked_h(w)      (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception()    (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
   do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h)   ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h)   ((Lisp_Object)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((Lisp_Object)(h) & ~GC_BIT_I)
#define is_cons(p)   ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p)   ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#ifdef COMMON
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#endif 
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p)     (is_cons(p) && (p) != nil)
#define symbolp(p)   (is_symbol(p) || (p) == nil)
#else 
#define consp(p)     is_cons(p)
#define symbolp(p)   is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p)  ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{
    Lisp_Object car;
    Lisp_Object cdr;
} Cons_Cell;
#ifdef MEMORY_TRACE
extern Cons_Cell *memory_reference(intptr_t p);
extern char *cmemory_reference(intptr_t p);
extern void identify_page_types();
extern long int car_counter;
extern unsigned long int car_low, car_high;
#define qcar(p) (memory_reference((intptr_t)p)->car)
#define qcdr(p) (memory_reference((intptr_t)p)->cdr)
#else 
#define qcar(p) (((Cons_Cell *) (p))->car)
#define qcdr(p) (((Cons_Cell *) (p))->cdr)
#endif 
#define car32(p) (*(int32_t *)(p))
#define cdr32(p) (*(int32_t *)(p))[1])
typedef Lisp_Object Special_Form(Lisp_Object, Lisp_Object);
typedef Lisp_Object one_args(Lisp_Object, Lisp_Object);
typedef Lisp_Object two_args(Lisp_Object, Lisp_Object, Lisp_Object);
typedef Lisp_Object MS_CDECL n_args(Lisp_Object, int, ...);
typedef uintptr_t Header;
#define header_mask          0x3f0
#define type_of_header(h)    (((unsigned int)(h)) & header_mask)
#define length_of_header(h)  (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL         0x00000010
#define  SYM_SPECIAL_VAR    0x00000040  
#define  SYM_GLOBAL_VAR     0x00000080  
#define  SYM_SPECIAL_FORM   0x00000100  
#define  SYM_MACRO          0x00000200  
#define  SYM_C_DEF          0x00000400  
#define  SYM_CODEPTR        0x00000800  
#define  SYM_ANY_GENSYM     0x00001000  
#define  SYM_TRACED         0x00002000
#define  SYM_FASTGET_MASK   0x000fc000  
#define  SYM_FASTGET_SHIFT  14
#ifdef COMMON
#define  SYM_EXTERN_IN_HOME 0x00100000  
#define  SYM_IN_PACKAGE     0xffe00000  
#define  SYM_IN_PKG_SHIFT   23
#define  SYM_IN_PKG_COUNT   11
#else 
#define  SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length       ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h)   (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM         0x020   
#ifdef COMMON
#define TYPE_RATNUM         0x060
#define TYPE_COMPLEX_NUM    0x0a0
#define TYPE_SINGLE_FLOAT   0x120
#endif 
#define TYPE_DOUBLE_FLOAT   0x160
#ifdef COMMON
#define TYPE_LONG_FLOAT     0x1a0
#endif 
#ifdef MEMORY_TRACE
#define numhdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_NUMBERS)))
#define flthdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                                               TAG_BOXFLOAT)))
#else
#define numhdr(v) (*(Header *)((char *)(v) - TAG_NUMBERS))
#define flthdr(v) (*(Header *)((char *)(v) - TAG_BOXFLOAT))
#endif
#define is_numbers_header(h) (((int)(h) & 0x330) == 0x020)
#define is_boxfloat_header(h)(((int)(h) & 0x330) == 0x120)
#ifdef COMMON
#define is_ratio(n) \
    (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
    (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#endif 
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v)  (*(Header *)memory_reference((intptr_t)((char *)(v) - \
                               TAG_VECTOR)))
#define elt(v, n)  (*(Lisp_Object *)memory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT))))
#define celt(v, n) (*cmemory_reference((intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define ucelt(v, n) (*(unsigned char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#define scelt(v, n) (*(signed char *)cmemory_reference( \
                               (intptr_t)((char *)(v) + \
                               (CELL-TAG_VECTOR)+((intptr_t)(n)))))
#else 
#define vechdr(v)  (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n)  (*(Lisp_Object *)((char *)(v) + \
                               (CELL-TAG_VECTOR) + \
                               (((intptr_t)(n))<<ADDRESS_SHIFT)))
#define celt(v, n) (*((char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define ucelt(v, n) (*((unsigned char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#define scelt(v, n) (*((signed char *)(v) + (CELL-TAG_VECTOR)+((intptr_t)(n))))
#endif 
#define helt(v, n) \
   ((*(unsigned char *)((v) + (CELL-TAG_VECTOR) + (2*(intptr_t)(n))) | \
    (*(signed char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n)))) << 8))
#define sethelt(v, n, x) \
   do { \
      *(char *)((v) + (CELL-TAG_VECTOR+0) + (2*(intptr_t)(n))) = (x); \
      *(char *)((v) + (CELL-TAG_VECTOR+1) + (2*(intptr_t)(n))) = (x)>>8; \
      } while (0)
#define ielt(v, n)  (*(intptr_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n)  (*(int32_t *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n)  (*(float *)((char *)(v) + \
                           (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n)  (*(double *)((char *)(v) + \
                           (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#ifdef COMMON
#define TYPE_BITVEC1        0x030   
#define TYPE_BITVEC2        0x0b0   
#define TYPE_BITVEC3        0x130
#define TYPE_BITVEC4        0x1b0   
#define TYPE_BITVEC5        0x230   
#define TYPE_BITVEC6        0x2b0   
#define TYPE_BITVEC7        0x330   
#define TYPE_BITVEC8        0x3b0   
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#endif 
#define TYPE_STRING         0x070   
#define TYPE_BPS            0x170   
#define TYPE_SPARE          0x270   
#define TYPE_MAPLEREF       TYPE_SPARE 
#define TYPE_FOREIGN        TYPE_SPARE 
#define TYPE_SP             0x370   
#ifdef COMMON
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#else
#define vector_holds_binary(h) (((h) & 0x80) == 0)
#endif
#define TYPE_SIMPLE_VEC     0x0f0   
#define TYPE_HASH           0x1f0   
#define TYPE_ARRAY          0x2f0   
#define TYPE_STRUCTURE      0x3f0   
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8           TYPE_BPS
#define TYPE_VEC16          0x220   
#define TYPE_VEC32          0x260   
#define TYPE_MIXED1         0x2a0   
#define TYPE_MIXED2         0x2e0   
#define TYPE_FLOAT32        0x320   
#define TYPE_FLOAT64        0x360   
#define TYPE_MIXED3         0x3a0   
#define TYPE_STREAM         0x3e0   
#define ODDS_MASK           0xff
#define TAG_CHAR            0x02    
#define TAG_BPS             0x42
#define TAG_SPID            0xc2    
#define SPID_NIL            (TAG_SPID+0x0000)  
#define SPID_FBIND          (TAG_SPID+0x0100)  
#define SPID_CATCH          (TAG_SPID+0x0200)  
#define SPID_PROTECT        (TAG_SPID+0x0300)  
#define SPID_HASH0          (TAG_SPID+0x0400)  
#define SPID_HASH1          (TAG_SPID+0x0500)  
#define SPID_GCMARK         (TAG_SPID+0x0600)  
#define SPID_NOINPUT        (TAG_SPID+0x0700)  
#define SPID_ERROR          (TAG_SPID+0x0800)  
#define SPID_PVBIND         (TAG_SPID+0x0900)  
#define SPID_NOARG          (TAG_SPID+0x0a00)  
#define SPID_NOPROP         (TAG_SPID+0x0b00)  
#define SPID_LIBRARY        (TAG_SPID+0x0c00)  
#define is_header(x) (((int)(x) & 0x30) != 0)     
#define is_char(x)   (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x)    (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x)   (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff)    == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n)  (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n)  (0)
#define code_of_char(n)  (((int32_t)(n) >>  8) & 0x001fffff)
#define pack_char(font, code)                                      \
    ((Lisp_Object)((((uint32_t)(font)) << 29) |                    \
                   (((uint32_t)(code)) << 8) | TAG_CHAR))
    
#define CHAR_EOF pack_char(0, 0x001fffff)
#define data_of_bps(v)                                        \
  ((char *)(doubleword_align_up((intptr_t)                    \
               bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) +   \
            (SIXTY_FOUR_BIT ?                                 \
               (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
                          PAGE_POWER_OF_TWO) :                \
               0) +                                           \
            (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk;      
typedef intptr_t junkxx;   
typedef struct Symbol_Head
{
    Header header;      
    Lisp_Object value;   
    Lisp_Object env;     
    intptr_t function1;  
    intptr_t function2;  
    intptr_t functionn;  
    Lisp_Object pname;   
    Lisp_Object plist;   
    Lisp_Object fastgets;
    uintptr_t count;     
#ifdef COMMON
    Lisp_Object package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE  63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
     ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
     (n)
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p)     (*(Header *)     symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p)      (*(Lisp_Object *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p)        (*(Lisp_Object *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p)        ((one_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (3*CELL - TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *((intptr_t *)symalign((char *)(p) + \
                                         (4*CELL - TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *((intptr_t *)symalign((char *)(p) + \
                                         (5*CELL - TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p)        (*(intptr_t *)      symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p)        (*(intptr_t *)      symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p)      (*(Lisp_Object *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p)      (*(Lisp_Object *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p)   (*(Lisp_Object *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p)      (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p)     (*(Header *)     memory_reference((intptr_t) \
                                         symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p)        (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p)        ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p)        ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p)        ((n_args *)   *(intptr_t *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p)        (*(intptr_t *)      memory_reference((intptr_t) \
                                         symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p)      (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p)   (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p)      (*(uintptr_t *) memory_reference((intptr_t) \
                                         symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p)    (*(Lisp_Object *)memory_reference((intptr_t) \
                                         symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
#ifdef COMMON
typedef union Float_union
{
    float f;
    int32_t i;
} Float_union;
#endif
typedef struct Big_Number
{
    Header h;
    uint32_t d[1];  
} Big_Number;
#define bignum_length(b)  length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b)  ((uint32_t *)memory_reference((intptr_t)((char *)b + \
                                         (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b)  ((uint32_t *)((char *)b  + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n)    (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
#ifdef COMMON
typedef struct Rational_Number
{
    Header header;
    Lisp_Object num;
    Lisp_Object den;
} Rational_Number;
#define numerator(r)    (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r)  (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{
    Header header;
    Lisp_Object real;
    Lisp_Object imag;
} Complex_Number;
#define real_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r)    (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{
    Header header;
    union float_or_int {
       float f;
       int32_t i;
    } f;
} Single_Float;
#define single_float_val(v) \
    (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#endif 
#define SIZEOF_DOUBLE_FLOAT     16
#define double_float_addr(v)    ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define double_float_val(v)     (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#ifdef COMMON
#define SIZEOF_LONG_FLOAT       16
#define long_float_addr(v)      ((double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#define long_float_val(v)       (*(double *)((char *)(v) + \
                                   (8-TAG_BOXFLOAT)))
#endif
#define word_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((Lisp_Object)(((intptr_t)(n) + \
                            sizeof(Lisp_Object) - 1) & (-sizeof(Lisp_Object))))
#define quadword_align_up(n) ((Lisp_Object)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((Lisp_Object)((intptr_t)(n) & (-16)))
#define UNWIND_NULL       0x0         
#define UNWIND_GO         0x1         
#define UNWIND_RETURN     0x2         
#define UNWIND_THROW      0x3         
#define UNWIND_RESTART    0x4         
#define UNWIND_RESOURCE   0x5         
#define UNWIND_FNAME      0x100       
#define UNWIND_ARGS       0x200       
#define UNWIND_ERROR      (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND     0x400       
#ifdef DEBUG
#define SHOW_FNAME  (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   (exit_reason == UNWIND_THROW || \
                     (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME  ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS   ((exit_reason & UNWIND_ARGS) != 0)
#endif
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern Lisp_Object interrupted(Lisp_Object p);
extern Lisp_Object MS_CDECL error(int nargs, int code, ...);
extern Lisp_Object MS_CDECL cerror(int nargs, int code1, int code2, ...);
extern Lisp_Object too_few_2(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object too_many_1(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_0a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_0b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_3a(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_3b(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object wrong_no_na(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object wrong_no_nb(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object MS_CDECL wrong_no_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL wrong_no_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bad_specialn(Lisp_Object env, int nargs, ...);
extern Lisp_Object aerror(char *s);         
extern Lisp_Object aerror0(char *s);
extern Lisp_Object aerror1(char *s, Lisp_Object a);
extern Lisp_Object aerror2(char *s, Lisp_Object a, Lisp_Object b);
extern void MS_CDECL fatal_error(int code, ...);
#define GC_MESSAGES   0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS  0x04
#define GC_MSG_BITS   0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG    0x10
#define ARGS_FLAG     0x20
#define BACKTRACE_MSG_BITS 0x38
 
#define err_bad_car               0      
#define err_bad_cdr               1      
#define err_no_store              2      
#define err_undefined_function_1  3      
#define err_undefined_function_2  4      
#define err_undefined_function_n  5      
#define err_wrong_no_args         6      
#define err_unbound_lexical       7      
#define err_bad_rplac             8      
#define err_bad_arith             9      
#define err_redef_special        10      
#define err_bad_arg              11      
#define err_bad_declare          12      
#define err_bad_fn               13      
#define err_unset_var            14      
#define err_too_many_args1       15      
#define err_too_many_args2       16      
#define err_bad_apply            17      
#define err_macroex_hook         18      
#define err_block_tag            19      
#define err_go_tag               20      
#define err_excess_args          21
#define err_insufficient_args    22
#define err_bad_bvl              23      
#define err_bad_keyargs          24
#define err_write_err            25
#define err_bad_endp             26      
#define err_no_fasldir           27
#define err_no_fasl              28      
#define err_open_failed          29      
#define err_pipe_failed          30      
#define err_stack_overflow       31
#define err_top_bit              32
#define err_mem_spans_zero       33
#define err_no_longer_used       34      
#define err_no_tempdir           35
    
#ifdef INCLUDE_ERROR_STRING_TABLE
static char *error_message_table[] =
{
    "attempt to take car of an atom",
    "attempt to take cdr of an atom",
    "insufficient freestore to run this package",
    "undefined function (1 arg)",
    "undefined function (2 args)",
    "undefined function",
    "wrong number of arguments",
    "unbound lexical variable",
    "bad rplaca/rplacd",
    "bad argument for an arithmetic function",
    "attempt to redefine a special form",
    "not a variable",
    "bad use of declare",
    "attempt to apply non-function",
    "unset variable",
    "too many arguments",
    "too many arguments",
    "object not valid as a function (apply,",
    "macroexpand-hook failure",
    "block tag not found",
    "go tag not found",
    "too many arguments provided",
    "not enough arguments provided",
    "bad item in bound variable list",
    "bad keyword arguments",
    "write-error on file",
    "endp used on badly terminated list",
    "environment parameter 'fasldir' not set",
    "loadable module not found for loading",
    "file could not be opened",
    "unable to establish pipe",
    "stack overflow",
    "top bit of address has unexpected value",
    "memory block spans the zero address",
    "this error code available for re-use",
    "unable to find a directory for temporary files",
    "dummy final error message"
};
#endif
#endif 
#ifndef header_externs_h
#define header_externs_h 1
#ifdef __cplusplus
extern "C" {
#endif
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
          fflush(stderr); \
          } while (0)
#define DS(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
          fflush(stderr); \
          } while (0)
#define DX(s) do { \
          char *fffff = strrchr(__FILE__, '/'); \
          if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
          if (fffff == NULL) fffff = __FILE__; else fffff++; \
          fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, fffff, \
                          (long long unsigned)(s)); \
          fflush(stderr); \
          } while (0)
extern void **pages,
            **heap_pages, **vheap_pages,
            **bps_pages, **native_pages;
extern void **new_heap_pages, **new_vheap_pages,
            **new_bps_pages, **new_native_pages;
#ifdef CONSERVATIVE
#define PAGE_TYPE_CONS   0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS    2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{
    void *start;
    void *end;
    int type;
} page_map_t;
#endif
extern int32_t pages_count,
               heap_pages_count, vheap_pages_count,
               bps_pages_count, native_pages_count;
extern int32_t new_heap_pages_count, new_vheap_pages_count,
               new_bps_pages_count, new_native_pages_count;
extern int32_t native_pages_changed;
extern int32_t native_fringe;
extern Lisp_Object *nilsegment, *stacksegment;
extern Lisp_Object *stackbase;
extern int32_t stack_segsize;  
extern Lisp_Object *C_stack;
#define stack C_stack
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern Lisp_Object *C_stackbase, *C_stacktop;
#endif
extern Lisp_Object multiplication_buffer;
#ifdef MEMORY_TRACE
#define push(a)         do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); } while (0)
#define push2(a,b)      do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c)    do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d)  do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); } while (0)
#define push5(a,b,c,d,e)do { \
                          *++stack = (a); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (b); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (c); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (d); \
                          memory_reference((intptr_t)stack); \
                          *++stack = (e); \
                          memory_reference((intptr_t)stack); } while (0)
#define push6(a,b,c,d,e,f) do {push3(a,b,c); push3(d,e,f); } while (0)
#define my_pop()        (memory_reference((int32_t)stack), (*stack--))
#define pop(a)          { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b)       { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c)     { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d)   { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
                          memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n)           stack -= (n)
#else 
#define push(a)         { *++stack = (a); }
#define push2(a,b)      { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c)    { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack += 3; }
#define push4(a,b,c,d)  { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) {                                              \
                          stack[1] = (a); stack[2] = (b); stack[3] = (c); \
                          stack[4] = (d); stack[5] = (e); stack[6] = (f); \
                          stack += 6; }
#define pop(a)          { (a) = *stack--; }
#define pop2(a,b)       { stack -= 2;     (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c)     { stack -= 3;     (a) = stack[3]; (b) = stack[2]; \
                          (c) = stack[1]; }
#define pop4(a,b,c,d)   { stack -= 4;     (a) = stack[4]; (b) = stack[3]; \
                          (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5;     (a) = stack[5]; (b) = stack[4]; \
                          (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6;                                  \
                          (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
                          (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n)           stack -= (n)
#endif 
#define errexit()    { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n)  { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return nil; } }
#define errexitv()   { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil;                                      \
                       if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK     2
#define GC_CONS      3
#define GC_VEC       4
#define GC_BPS       5
#define GC_PRESERVE  6
#define GC_NATIVE    7
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(char *file, int line);
extern void show_stack();
#define if_check_stack \
   if (check_stack("@" __FILE__,__LINE__)) \
   {   show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
   {   char *p = (char *)&p; \
       if (p < C_stack_limit) return aerror("stack overflow"); \
   }
#endif
extern int32_t software_ticks, countdown;
#ifdef DEBUG
extern char debug_trail[32][32];
extern char debug_trail_file[32][32];
extern int debug_trail_line[32];
extern int debug_trailp;
extern void debug_record_raw(const char *data, const char *file, int line);
extern void debug_record_int_raw(const char *s, int n, const char *file, int line);
extern void debug_show_trail_raw(const char *msg, const char *file, int line);
#define debug_record(data) debug_record_raw(data, __FILE__, __LINE__)
#define debug_record_int(s, n) debug_record_int_raw(s, n, __FILE__, __LINE__)
#define debug_record_string(s) debug_record(&celt(s, 0))
#define debug_record_symbol(x) debug_record_string(qpname(x))
#define debug_show_trail(data) debug_show_trail_raw(data, __FILE__, __LINE__)
#define debug_assert(x) \
  if (!(x)) { debug_show_trail("Assertion failed"); exit(7); }
#else
#define debug_record(data)
#define debug_record_int(s, n)
#define debug_record_string(s)
#define debug_record_symbol(x)
#define debug_show_trail(x)
#define debug_assert(x)
#endif
extern volatile int blipflag;
extern int64_t blipcount, startblip;
#if defined __linux__ && defined DEBUG
#define HANDLE_BLIP                                                       \
    if (blipflag)                                                         \
    {   blipflag = 0;                                                     \
        if (startblip >= 0 && ++blipcount > startblip)                    \
        {   fprintf(stderr, "Line %d of file %s\n", __LINE__, __FILE__);  \
            fflush(stderr);                                               \
        }                                                                 \
    }
#else
#define HANDLE_BLIP
#endif
#define stackcheck0(k)                                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   reclaim(nil, "stack", GC_STACK, 0);                 \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck1(k, a1)                                  \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck2(k, a1, a2)                              \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push(a2);                                           \
        a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2);    \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck3(k, a1, a2, a3)                          \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push2(a2, a3);                                      \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop2(a3, a2);                                       \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
#define stackcheck4(k, a1, a2, a3, a4)                      \
    if_check_stack                                          \
    if ((--countdown < 0 && deal_with_tick()) ||            \
        stack >= stacklimit)                                \
    {   push3(a2, a3, a4);                                  \
        a1 = reclaim(a1, "stack", GC_STACK, 0);             \
        pop3(a4, a3, a2);                                   \
        nil = C_nil;                                        \
        if (exception_pending()) { popv(k); return nil; }   \
    }
extern Lisp_Object C_nil;
#define first_nil_offset         50     
#define work_0_offset           200
#define last_nil_offset         251
#define NIL_SEGMENT_SIZE    (last_nil_offset*sizeof(Lisp_Object) + 32)
#define SPARE                   512
#ifdef COMMON
#define BASE ((Lisp_Object *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((Lisp_Object *)(nil+4)): ((Lisp_Object *)nil))
#endif
#ifdef NILSEG_EXTERNS
#define nil_as_base
extern intptr_t byteflip;
extern Lisp_Object codefringe;
extern Lisp_Object volatile codelimit;
extern Lisp_Object * volatile stacklimit;
extern Lisp_Object fringe;
extern Lisp_Object volatile heaplimit;
extern Lisp_Object volatile vheaplimit;
extern Lisp_Object vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern Lisp_Object lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern Lisp_Object quote_symbol, function_symbol, comma_symbol;
extern Lisp_Object comma_at_symbol, cons_symbol, eval_symbol;
extern Lisp_Object work_symbol, evalhook, applyhook, macroexpand_hook;
extern Lisp_Object append_symbol, exit_tag, exit_value, catch_tags;
extern Lisp_Object current_package, startfn;
extern Lisp_Object gensym_base, string_char_sym, boffo;
extern Lisp_Object err_table;
extern Lisp_Object progn_symbol;
extern Lisp_Object lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern Lisp_Object echo_symbol, codevec, litvec, supervisor, B_reg;
extern Lisp_Object savedef, comp_symbol, compiler_symbol, faslvec;
extern Lisp_Object tracedfn, lisp_terminal_io;
extern Lisp_Object lisp_standard_output, lisp_standard_input, lisp_error_output;
extern Lisp_Object lisp_trace_output, lisp_debug_io, lisp_query_io;
extern Lisp_Object prompt_thing, faslgensyms;
extern Lisp_Object prinl_symbol, emsg_star, redef_msg;
extern Lisp_Object expr_symbol, fexpr_symbol, macro_symbol;
extern Lisp_Object cl_symbols, active_stream, current_module;
extern Lisp_Object native_defs, features_symbol, lisp_package;
extern Lisp_Object sys_hash_table, help_index, cfunarg, lex_words;
extern Lisp_Object get_counts, fastget_names, input_libraries;
extern Lisp_Object output_library, current_file, break_function;
extern Lisp_Object standard_output, standard_input, debug_io;
extern Lisp_Object error_output, query_io, terminal_io;
extern Lisp_Object trace_output, fasl_stream;
extern Lisp_Object native_code, native_symbol, traceprint_symbol;
extern Lisp_Object loadsource_symbol;
extern Lisp_Object hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern Lisp_Object gchook, resources, callstack, procstack, procmem, trap_time;
#ifdef COMMON
extern Lisp_Object keyword_package;
extern Lisp_Object all_packages, package_symbol, internal_symbol;
extern Lisp_Object external_symbol, inherited_symbol;
extern Lisp_Object key_key, allow_other_keys, aux_key;
extern Lisp_Object format_symbol;
extern Lisp_Object expand_def_symbol, allow_key_key;
#endif
extern Lisp_Object declare_symbol, special_symbol, large_modulus;
extern Lisp_Object used_space, avail_space, eof_symbol, call_stack;
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
extern Lisp_Object workbase[51];
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0              workbase[0]
#define work_1              workbase[1]
#define mv_1                workbase[1]
#define mv_2                workbase[2]
#define mv_3                workbase[3]
#define work_50             workbase[50]
#else 
#define nil_as_base  Lisp_Object nil = C_nil;
#define byteflip              BASE[12]
#define codefringe            BASE[13]
#define codelimit             (*(Lisp_Object volatile *)&BASE[14])
extern Lisp_Object * volatile stacklimit;
#define fringe                BASE[18]
#define heaplimit             (*(Lisp_Object volatile *)&BASE[19])
#define vheaplimit            (*(Lisp_Object volatile *)&BASE[20])
#define vfringe               BASE[21]
#define miscflags             BASE[22]
#define nwork                 BASE[24]
#define exit_count            BASE[26]
#define gensym_ser            BASE[27]
#define print_precision       BASE[28]
#define current_modulus       BASE[29]
#define fastget_size          BASE[30]
#define package_bits          BASE[31]
#define modulus_is_large      BASE[32]
#define current_package       BASE[52]
#define B_reg                 BASE[53]
#define codevec               BASE[54]
#define litvec                BASE[55]
#define exit_tag              BASE[56]
#define exit_value            BASE[57]
#define catch_tags            BASE[58]
#define lisp_package          BASE[59]
#define boffo                 BASE[60]
#define charvec               BASE[61]
#define sys_hash_table        BASE[62]
#define help_index            BASE[63]
#define gensym_base           BASE[64]
#define err_table             BASE[65]
#define supervisor            BASE[66]
#define startfn               BASE[67]
#define faslvec               BASE[68]
#define tracedfn              BASE[69]
#define prompt_thing          BASE[70]
#define faslgensyms           BASE[71]
#define cl_symbols            BASE[72]
#define active_stream         BASE[73]
#define current_module        BASE[74]
#define native_defs           BASE[75]
#define append_symbol         BASE[90]
#define applyhook             BASE[91]
#define cfunarg               BASE[92]
#define comma_at_symbol       BASE[93]
#define comma_symbol          BASE[94]
#define compiler_symbol       BASE[95]
#define comp_symbol           BASE[96]
#define cons_symbol           BASE[97]
#define echo_symbol           BASE[98]
#define emsg_star             BASE[99]
#define evalhook              BASE[100]
#define eval_symbol           BASE[101]
#define expr_symbol           BASE[102]
#define features_symbol       BASE[103]
#define fexpr_symbol          BASE[104]
#define funarg                BASE[105]
#define function_symbol       BASE[106]
#define lambda                BASE[107]
#define lisp_true             BASE[108]
#define lower_symbol          BASE[109]
#define macroexpand_hook      BASE[110]
#define macro_symbol          BASE[111]
#define opt_key               BASE[112]
#define prinl_symbol          BASE[113]
#define progn_symbol          BASE[114]
#define quote_symbol          BASE[115]
#define raise_symbol          BASE[116]
#define redef_msg             BASE[117]
#define rest_key              BASE[118]
#define savedef               BASE[119]
#define string_char_sym       BASE[120]
#define unset_var             BASE[121]
#define work_symbol           BASE[122]
#define lex_words             BASE[123]
#define get_counts            BASE[124]
#define fastget_names         BASE[125]
#define input_libraries       BASE[126]
#define output_library        BASE[127]
#define current_file          BASE[128]
#define break_function        BASE[129]
#define lisp_work_stream      BASE[130]
#define lisp_standard_output  BASE[131]
#define lisp_standard_input   BASE[132]
#define lisp_debug_io         BASE[133]
#define lisp_error_output     BASE[134]
#define lisp_query_io         BASE[135]
#define lisp_terminal_io      BASE[136]
#define lisp_trace_output     BASE[137]
#define standard_output       BASE[138]
#define standard_input        BASE[139]
#define debug_io              BASE[140]
#define error_output          BASE[141]
#define query_io              BASE[142]
#define terminal_io           BASE[143]
#define trace_output          BASE[144]
#define fasl_stream           BASE[145]
#define native_code           BASE[146]
#define native_symbol         BASE[147]
#define traceprint_symbol     BASE[148]
#define loadsource_symbol     BASE[149]
#define hankaku_symbol        BASE[150]
#define bytecoded_symbol      BASE[151]
#define nativecoded_symbol    BASE[152]
#define gchook                BASE[153]
#define resources             BASE[154]
#define callstack             BASE[155]
#define procstack             BASE[156]
#define procmem               BASE[157]
#define trap_time             BASE[158]
#ifdef COMMON
#define keyword_package       BASE[170]
#define all_packages          BASE[171]
#define package_symbol        BASE[172]
#define internal_symbol       BASE[173]
#define external_symbol       BASE[174]
#define inherited_symbol      BASE[175]
#define key_key               BASE[176]
#define allow_other_keys      BASE[177]
#define aux_key               BASE[178]
#define format_symbol         BASE[179]
#define expand_def_symbol     BASE[180]
#define allow_key_key         BASE[181]
#endif
#define declare_symbol        BASE[182]
#define special_symbol        BASE[183]
#define large_modulus         BASE[184]
#define used_space            BASE[185]
#define avail_space           BASE[186]
#define eof_symbol            BASE[187]
#define call_stack            BASE[188]
extern Lisp_Object user_base_0, user_base_1, user_base_2;
extern Lisp_Object user_base_3, user_base_4, user_base_5;
extern Lisp_Object user_base_6, user_base_7, user_base_8;
extern Lisp_Object user_base_9;
#define work_0                BASE[200]
#define work_1                BASE[201]
#define mv_1                  work_1
#define mv_2                  BASE[202]
#define mv_3                  BASE[203]
#define work_50               BASE[250]
#endif 
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list     BASE[50] 
#define equal_hash_table_list  BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(Lisp_Object v);
extern Lisp_Object eq_hash_tables, equal_hash_tables;
extern Lisp_Object volatile savecodelimit;
extern Lisp_Object * volatile savestacklimit;
extern Lisp_Object volatile saveheaplimit;
extern Lisp_Object volatile savevheaplimit;
extern char *exit_charvec;
extern intptr_t exit_reason;
extern int procstackp;
#ifdef DEBUG
extern int trace_all;
#endif
#ifndef NO_BYTECOUNT
extern const char *name_of_caller;
#endif
extern int garbage_collection_permitted;
#define MAX_INPUT_FILES         40  
#define MAX_SYMBOLS_TO_DEFINE   40
#define MAX_FASL_PATHS          20
extern char *files_to_read[MAX_INPUT_FILES],
     *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
     *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern char **csl_argv;
extern int fasl_output_file, output_directory;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern int boffop;
extern void packbyte(int c);
#ifndef COMMON
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
#endif
#endif
#ifdef SOCKETS
extern int sockets_ready;
extern void flush_socket(void);
#endif
extern void report_file(const char *s);
extern CSLbool undefine_this_one[MAX_SYMBOLS_TO_DEFINE];
extern int errorset_min, errorset_max;
extern int number_of_input_files,
    number_of_symbols_to_define,
    number_of_fasl_paths,
    init_flags;
extern int native_code_tag;
extern char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
#define INIT_QUIET      1
#define INIT_VERBOSE    2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p)  ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{
    FILE *f;        
    long int o;     
    long int n;     
    uint32_t chk;   
    int status;     
    int nativedir;  
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE                0x1000
typedef struct entry_point1
{
    one_args *p;
    char *s;
} entry_point1;
typedef struct entry_point2
{
    two_args *p;
    char *s;
} entry_point2;
typedef struct entry_pointn
{
    n_args *p;
    char *s;
} entry_pointn;
extern entry_point1 entries_table1[];
extern entry_point2 entries_table2[];
extern entry_pointn entries_tablen[];
extern entry_pointn entries_table_io[];
extern void set_up_entry_lookup(void);
extern int32_t code_up_fn1(one_args *e);
extern int32_t code_up_fn2(two_args *e);
extern int32_t code_up_fnn(n_args *e);
extern int32_t code_up_io(void *e);
extern int doubled_execution;
extern char *linker_type;
extern char *compiler_command[], *import_data[],
            *config_header[], *csl_headers[];
extern Lisp_Object encapsulate_pointer(void *);
extern void *extract_pointer(Lisp_Object a);
extern Lisp_Object Lencapsulatedp(Lisp_Object nil, Lisp_Object a);
typedef void initfn(Lisp_Object *, Lisp_Object **, Lisp_Object * volatile *);
extern int load_dynamic(char *objname, char *modname,
                        Lisp_Object name, Lisp_Object fns);
extern Lisp_Object Linstate_c_code(Lisp_Object nil,
                                   Lisp_Object name, Lisp_Object fns);
extern Lisp_Object characterify(Lisp_Object a);
extern Lisp_Object char_to_id(int ch);
#ifdef MEMORY_TRACE
extern intptr_t memory_base, memory_size;
extern unsigned char *memory_map;
extern FILE *memory_file;
extern void memory_comment(int n);
#endif
#define ARG_CUT_OFF 25
extern void push_args(va_list a, int nargs);
extern void push_args_1(va_list a, int nargs);
extern void Iinit(void);
extern void IreInit(void);
extern void Icontext(Ihandle *);
extern void Irestore_context(Ihandle);
extern void Ilist(void);
extern CSLbool open_output(char *s, int len);
#define IOPEN_OUT       0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED   2
extern CSLbool Iopen(char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(char *name, int len, char *datestamp, int32_t *size,
                                 char *expanded_name);
extern CSLbool Icopy(char *name, int len);
extern CSLbool Idelete(char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int  Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(void *buff, int32_t size);
extern long int Ioutsize(void);
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(char *suffix, int32_t suffixlen);
extern int Cmkdir(char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(Lisp_Object a);
extern unsigned char unpredictable[256];
extern void inject_randomness(int n);
extern void ensure_screen(void);
extern int window_heading;
extern void my_exit(int n);
extern void *my_malloc(size_t n);
extern clock_t base_time;
extern double *clock_stack;
extern void push_clock(void);
extern double pop_clock(void);
extern double consolidated_time[10], gc_time;
extern CSLbool volatile already_in_gc, tick_on_gc_exit;
extern CSLbool volatile interrupt_pending, tick_pending;
extern int deal_with_tick(void);
extern int current_fp_rep;
#ifndef __cplusplus
#ifdef USE_SIGALTSTACK
extern sigjmp_buf *errorset_buffer;
extern sigjmp_buf my_exit_buffer;
#else
extern jmp_buf *errorset_buffer;
extern jmp_buf my_exit_buffer;
#endif
#endif
extern char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(Lisp_Object *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void MS_CDECL low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern void MS_CDECL sigint_handler(int code);
extern void record_get(Lisp_Object tag, CSLbool found);
extern int         primep(int32_t);
extern void        adjust_all(void);
extern void        set_up_functions(CSLbool restartp);
extern void        get_user_files_checksum(unsigned char *);
extern Lisp_Object acons(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object bytestream_interpret(Lisp_Object code, Lisp_Object lit,
                                        Lisp_Object *entry_stack);
extern CSLbool        complex_stringp(Lisp_Object a);
extern void        freshline_trace(void);
extern void        freshline_debug(void);
extern Lisp_Object cons(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_no_gc(Lisp_Object a, Lisp_Object b);
extern Lisp_Object cons_gc_test(Lisp_Object a);
extern void        convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern Lisp_Object Ceval(Lisp_Object u, Lisp_Object env);
extern Lisp_Object noisy_Ceval(Lisp_Object u, Lisp_Object env);
extern uint32_t  Crand(void);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern void        Csrand(uint32_t a, uint32_t b);
extern void        discard(Lisp_Object a);
extern CSLbool eql_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool cl_equal_fn(Lisp_Object a, Lisp_Object b);
extern CSLbool equal_fn(Lisp_Object a, Lisp_Object b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(Lisp_Object a, Lisp_Object b,
                                      char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern CSLbool equalp(Lisp_Object a, Lisp_Object b);
extern Lisp_Object apply(Lisp_Object fn, int nargs,
                         Lisp_Object env, Lisp_Object fname, int noisy);
extern Lisp_Object apply_lambda(Lisp_Object def, int nargs,
                         Lisp_Object env, Lisp_Object name, int noisy);
extern void        deallocate_pages(void);
extern void        drop_heap_segments(void);
extern Lisp_Object gcd(Lisp_Object a, Lisp_Object b);
extern Lisp_Object get_pname(Lisp_Object a);
#ifdef COMMON
extern Lisp_Object get(Lisp_Object a, Lisp_Object b, Lisp_Object c);
#else
extern Lisp_Object get(Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object getvector(int tag, int type, int32_t length);
extern Lisp_Object getvector_init(int32_t n, Lisp_Object v);
extern Lisp_Object getcodevector(int type, int32_t size);
extern uint32_t  hash_lisp_string(Lisp_Object s);
extern void lose_C_def(Lisp_Object a);
extern CSLbool        geq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        greaterp2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lesseq2(Lisp_Object a, Lisp_Object b);
extern CSLbool        lessp2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object list2star(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3(Lisp_Object a, Lisp_Object b, Lisp_Object c);
extern Lisp_Object list3star(Lisp_Object a, Lisp_Object b,
                             Lisp_Object c, Lisp_Object d);
extern Lisp_Object list4(Lisp_Object a, Lisp_Object b,
                         Lisp_Object c, Lisp_Object d);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object macroexpand(Lisp_Object form, Lisp_Object env);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_package(Lisp_Object name);
extern Lisp_Object make_string(const char *b);
extern Lisp_Object make_nstring(char *b, int32_t n);
extern Lisp_Object make_undefined_symbol(char const *s);
extern Lisp_Object make_symbol(char const *s, int restartp,
                               one_args *f1, two_args *f2, n_args *fn);
extern void MS_CDECL  stdout_printf(char *fmt, ...);
extern void MS_CDECL  term_printf(char *fmt, ...);
extern void MS_CDECL  err_printf(char *fmt, ...);
extern void MS_CDECL  debug_printf(char *fmt, ...);
extern void MS_CDECL  trace_printf(char *fmt, ...);
extern char        *my_getenv(char *name);
extern Lisp_Object ncons(Lisp_Object a);
extern Lisp_Object ndelete(Lisp_Object a, Lisp_Object b);
extern Lisp_Object negate(Lisp_Object a);
extern Lisp_Object nreverse(Lisp_Object a);
extern FILE        *open_file(char *filename, char *original_name,
                              size_t n, const char *dirn, FILE *old_file);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern void        preserve(char *msg, int len);
extern void        preserve_native_code(void);
extern void        relocate_native_function(unsigned char *bps);
extern Lisp_Object prin(Lisp_Object u);
extern char *get_string_data(Lisp_Object a, char *why, int32_t *len);
extern void prin_to_stdout(Lisp_Object u);
extern void prin_to_terminal(Lisp_Object u);
extern void prin_to_debug(Lisp_Object u);
extern void prin_to_query(Lisp_Object u);
extern void prin_to_trace(Lisp_Object u);
extern void prin_to_error(Lisp_Object u);
extern void loop_print_stdout(Lisp_Object o);
extern void loop_print_terminal(Lisp_Object o);
extern void loop_print_debug(Lisp_Object o);
extern void loop_print_query(Lisp_Object o);
extern void loop_print_trace(Lisp_Object o);
extern void loop_print_error(Lisp_Object o);
extern void internal_prin(Lisp_Object u, int prefix);
extern Lisp_Object princ(Lisp_Object u);
extern Lisp_Object print(Lisp_Object u);
extern Lisp_Object printc(Lisp_Object u);
extern void        print_bignum(Lisp_Object u, CSLbool blankp, int nobreak);
extern void        print_bighexoctbin(Lisp_Object u,
                       int radix, int width, CSLbool blankp, int nobreak);
extern Lisp_Object putprop(Lisp_Object a, Lisp_Object b,
                       Lisp_Object c);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern void        read_eval_print(int noisy);
extern Lisp_Object reclaim(Lisp_Object value_to_return, char *why,
                           int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(char *why, int line, char *file);
extern int check_env(Lisp_Object env);
#endif
extern CSLbool do_not_kill_native_code;
extern void        set_fns(Lisp_Object sym, one_args *f1,
                                            two_args *f2, n_args *fn);
extern void        setup(int restartp, double storesize);
extern Lisp_Object simplify_string(Lisp_Object s);
extern CSLbool        stringp(Lisp_Object a);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern int32_t       thirty_two_bits(Lisp_Object a);
#ifdef HAVE_INT64_T
extern int64_t       sixty_four_bits(Lisp_Object a);
#endif
#ifdef DEBUG
extern void validate_string_fn(Lisp_Object a, char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
#ifdef COMMON
#define onevalue(r)   (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r)   (r)
#define nvalues(r, n) (r)
#endif
#ifdef COMMON
#define eval(a, b) Ceval(a, b)
#define voideval(a, b) Ceval(a, b)
#define noisy_eval(a, b) noisy_Ceval(a, b)
#define noisy_voideval(a, b) noisy_Ceval(a, b)
#else
#define eval(a, b) \
    (is_cons(a) ? Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define voideval(a, b) \
    if (is_cons(a)) Ceval(a, b) 
#define noisy_eval(a, b) \
    (is_cons(a) ? noisy_Ceval(a, b) : \
     is_symbol(a) ? (qvalue(a) == unset_var ? error(1, err_unset_var, a) : \
                     onevalue(qvalue(a))) : \
     onevalue(a))
#define noisy_voideval(a, b) \
    if (is_cons(a)) noisy_Ceval(a, b) 
#endif
#define equal(a, b)                                \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      equal_fn(a, b)))
#define cl_equal(a, b)                             \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      cl_equal_fn(a, b)))
#define eql(a, b)                                  \
    ((a) == (b) ||                                 \
     (((((a) ^ (b)) & TAG_BITS) == 0) &&           \
      ((unsigned)(((a) & TAG_BITS) - 1) > 3) &&    \
      eql_fn(a, b)))
#ifndef IMULTIPLY
extern uint32_t Imultiply(uint32_t *rlow, uint32_t a,
                            uint32_t b, uint32_t c);
#endif
#ifndef IDIVIDE
extern uint32_t Idivide(uint32_t *qp, uint32_t a,
                          uint32_t b, uint32_t c);
extern uint32_t Idiv10_9(uint32_t *qp, uint32_t a, uint32_t b);
#endif
#define argcheck(var, n, msg) if ((var)!=(n)) return aerror(msg);
extern n_args   *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args   *three_arg_functions[];
extern void     *useful_functions[];
extern char     *address_of_var(int n);
typedef struct setup_type
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
} setup_type;
typedef struct setup_type_1
{
    char *name;
    one_args *one;
    two_args *two;
    n_args *n;
    uint32_t c1;
    uint32_t c2;
} setup_type_1;
extern setup_type const
       arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
       char_setup[], eval1_setup[], eval2_setup[], eval3_setup[],
       funcs1_setup[], funcs2_setup[], funcs3_setup[], print_setup[],
       read_setup[], mpi_setup[];
extern setup_type const
                    u01_setup[], u02_setup[], u03_setup[], u04_setup[],
       u05_setup[], u06_setup[], u07_setup[], u08_setup[], u09_setup[],
       u10_setup[], u11_setup[], u12_setup[], u13_setup[], u14_setup[],
       u15_setup[], u16_setup[], u17_setup[], u18_setup[], u19_setup[],
       u20_setup[], u21_setup[], u22_setup[], u23_setup[], u24_setup[],
       u25_setup[], u26_setup[], u27_setup[], u28_setup[], u29_setup[],
       u30_setup[], u31_setup[], u32_setup[], u33_setup[], u34_setup[],
       u35_setup[], u36_setup[], u37_setup[], u38_setup[], u39_setup[],
       u40_setup[], u41_setup[], u42_setup[], u43_setup[], u44_setup[],
       u45_setup[], u46_setup[], u47_setup[], u48_setup[], u49_setup[],
       u50_setup[], u51_setup[], u52_setup[], u53_setup[], u54_setup[],
       u55_setup[], u56_setup[], u57_setup[], u58_setup[], u59_setup[],
       u60_setup[];
extern setup_type const *setup_tables[];
#ifdef NAG
extern setup_type const nag_setup[], asp_setup[];
extern setup_type const socket_setup[], xdr_setup[], grep_setup[];
extern setup_type const gr_setup[], axfns_setup[];
#endif
#ifdef OPENMATH
extern setup_type const om_setup[];
extern setup_type const om_parse_setup[];
#endif
extern char *find_image_directory(int argc, char *argv[]);
extern char program_name[64];
extern Lisp_Object declare_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object function_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object let_fn_1(Lisp_Object bvl, Lisp_Object body,
                            Lisp_Object env, int compilerp, int noisy);
extern Lisp_Object mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_mv_call_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_progn_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object quote_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object noisy_tagbody_fn(Lisp_Object args, Lisp_Object env);
extern Lisp_Object resource_exceeded();
extern int64_t time_base,  space_base,  io_base,  errors_base;
extern int64_t time_now,   space_now,   io_now,   errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(Lisp_Object def, Lisp_Object env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#ifdef __cplusplus
}
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32    4294967296.0      
#define TWO_31    2147483648.0      
#define TWO_24    16777216.0        
#define TWO_22    4194304.0         
#define TWO_21    2097152.0         
#define TWO_20    1048576.0         
#define M2_31_1   -2147483649.0     
#define _pi       ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi  ((12868.0 - 0.036490896206895257)/8192.0)
#define boole_clr   0
#define boole_and   1
#define boole_andc2 2
#define boole_1     3
#define boole_andc1 4
#define boole_2     5
#define boole_xor   6
#define boole_ior   7
#define boole_nor   8
#define boole_eqv   9
#define boole_c2    10
#define boole_orc2  11
#define boole_c1    12
#define boole_orc1  13
#define boole_nand  14
#define boole_set   15
#define top_bit_set(n)     (((int32_t)(n)) < 0)
#define top_bit(n)         (((uint32_t)(n)) >> 31)
#define set_top_bit(n)     ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n)   ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1      
#define Dmultiply(hi, lo, a, b, c)                          \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) +  \
                     (uint32_t)(c);                       \
      (lo) = 0x7fffffffu & (uint32_t)r64;                 \
      (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE   1
#define Ddivide(r, q, a, b, c)                                      \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
      uint64_t c64 = (uint64_t)(uint32_t)(c);                 \
      q = (uint32_t)(r64 / c64);                                  \
      r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b)   ((r) = Idiv10_9(&(q), (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
    ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern Lisp_Object negateb(Lisp_Object);
extern Lisp_Object copyb(Lisp_Object);
extern Lisp_Object negate(Lisp_Object);
extern Lisp_Object plus2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object difference2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object times2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object CLquot2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object quotbn(Lisp_Object a, int32_t n);
extern Lisp_Object quotbn1(Lisp_Object a, int32_t n);
extern Lisp_Object quotbb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object Cremainder(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembi(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rembb(Lisp_Object a, Lisp_Object b);
extern Lisp_Object shrink_bignum(Lisp_Object a, int32_t lena);
extern Lisp_Object modulus(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rational(Lisp_Object a);
extern Lisp_Object rationalize(Lisp_Object a);
extern Lisp_Object lcm(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lengthen_by_one_bit(Lisp_Object a, int32_t msd);
extern CSLbool numeq2(Lisp_Object a, Lisp_Object b);
extern CSLbool zerop(Lisp_Object a);
extern CSLbool onep(Lisp_Object a);
extern CSLbool minusp(Lisp_Object a);
extern CSLbool plusp(Lisp_Object a);
extern CSLbool lesspbd(Lisp_Object a, double b);
extern CSLbool lessprd(Lisp_Object a, double b);
extern CSLbool lesspdb(double a, Lisp_Object b);
extern CSLbool lesspdr(double a, Lisp_Object b);
extern Lisp_Object make_one_word_bignum(int32_t n);
extern Lisp_Object make_two_word_bignum(int32_t a, uint32_t b);
extern Lisp_Object make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern Lisp_Object make_n_word_bignum(int32_t a1, uint32_t a2,
                                      uint32_t a3, int32_t n);
extern Lisp_Object make_lisp_integer32(int32_t n);
extern Lisp_Object make_lisp_integer64(int64_t n);
extern Lisp_Object make_sfloat(double d);
extern double float_of_integer(Lisp_Object a);
extern Lisp_Object add1(Lisp_Object p);
extern Lisp_Object sub1(Lisp_Object p);
extern Lisp_Object integerp(Lisp_Object p);
extern double float_of_number(Lisp_Object a);
extern Lisp_Object make_boxfloat(double a, int32_t type);
extern Lisp_Object make_complex(Lisp_Object r, Lisp_Object i);
extern Lisp_Object make_ratio(Lisp_Object p, Lisp_Object q);
extern Lisp_Object ash(Lisp_Object a, Lisp_Object b);
extern Lisp_Object lognot(Lisp_Object a);
extern Lisp_Object logior2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logxor2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logand2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object logeqv2(Lisp_Object a, Lisp_Object b);
extern Lisp_Object rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(Lisp_Object a, Lisp_Object b);
extern CSLbool lesspib(Lisp_Object a, Lisp_Object b);
#ifdef COMMON
typedef struct Complex
{
    double real;
    double imag;
} Complex;
extern Complex MS_CDECL Cln(Complex a);
extern Complex MS_CDECL Ccos(Complex a);
extern Complex MS_CDECL Cexp(Complex a);
extern Complex MS_CDECL Cpow(Complex a, Complex b);
extern double MS_CDECL Cabs(Complex a);
#endif
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG    LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG    void *
#define WINAPI
extern KARARESULT kara_worker1(KARAARG p);
extern KARARESULT kara_worker2(KARAARG p);
#endif
#ifdef MACINTOSH
extern sem_t *kara_sem1a, *kara_sem1b, *kara_sem1c,
             *kara_sem2a, *kara_sem2b, *kara_sem2c;
#else
extern sem_t kara_sem1a, kara_sem1b, kara_sem1c,
             kara_sem2a, kara_sem2b, kara_sem2c;
#endif
extern int karatsuba_parallel;
#ifndef KARATSUBA_PARALLEL_CUTOFF
#  define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
#ifdef __cplusplus
extern "C" {
#endif
extern Lisp_Object MS_CDECL Lbatchp(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecounts(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ldate(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ldatestamp(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Leject(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerror0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lflush(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgc0(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgctime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgensym(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist_modules(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llibrary_members0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmapstore0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lnext_random(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lposn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lread(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lreadch(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lrtell(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lterpri(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltime(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Ltmpnam(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Ltyi(Lisp_Object env, int nargs, ...);
extern Lisp_Object autoload1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object bytecounts1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_bytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object double_byteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_byteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object double_hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object double_interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object funarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracefunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracesetfunarged1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object hardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object hardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object interpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracesetbytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object jitcompileme1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracebyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesetbyteopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesetbyteoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracebytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object tracesetbytecoded1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object traceinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracesetinterpreted1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object tracehardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesethardopt1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracehardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object tracesethardoptrest1(Lisp_Object def, Lisp_Object a);
extern Lisp_Object undefined1(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object f1_as_0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object f1_as_1(Lisp_Object env, Lisp_Object a);
#ifdef CJAVA
extern Lisp_Object java1(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object Labsval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ladd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lalpha_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply0(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lapply_1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Latan(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Latom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbanner(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lboundp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lbpsp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lbpsupbv(Lisp_Object nil, Lisp_Object v);
extern Lisp_Object Lcaaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdaddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddaar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddadr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcddr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcdr(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lchar_code(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lclose(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcodep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcompress(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconsp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lconstantp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lcopy_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldefine_in_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldelete_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ldigitp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lendp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lerror1(Lisp_Object nil, Lisp_Object a1);
extern Lisp_Object Lerrorset1(Lisp_Object nil, Lisp_Object form);
extern Lisp_Object Leval(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levenp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Levlis(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplode2lcn(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexplode2n(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodec(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodecn(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodehex(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lexploden(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lexplodeoctal(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfixp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloat(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfloatp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lfrexp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lfuncall1(Lisp_Object env, Lisp_Object fn);
extern Lisp_Object Lgc(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lgensym1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgensym2(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lgetenv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lget_bps(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lhelp(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Liadd1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lidentity(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Liminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lindirect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintegerp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lionep(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lisub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lizerop(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llengthc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llibrary_members(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llinelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_string(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llist_to_vector(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lload_source(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llognot(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Llog_1(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Llsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacroexpand_1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmacro_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmapstore(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmd5(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lmd60(Lisp_Object env, Lisp_Object a1);
extern Lisp_Object Lminus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lminusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkevect(Lisp_Object nil, Lisp_Object n);
extern Lisp_Object Lmkquote(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_minus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_number(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodular_reciprocal(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmodule_exists(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmsd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lmv_list(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lncons(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnull(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lnumberp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Loddp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lonep(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lpagelength(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplist(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lplusp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprin2a(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprinc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprint(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lprintc(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrandom(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrational(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrdf1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lrds(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lremd(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lreverse(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsetpchar(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lset_small_modulus(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsmkvect(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_char(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspecial_form_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lspool(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstart_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstop(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lstringp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsub1(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbolp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcount(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_argcode(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_env(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_function(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_globalp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_name(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_restore_fns(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_specialp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsymbol_value(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsystem(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthreevectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lthrow_nil(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltraceset(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltruncate(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lttab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Ltyo(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunintern(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_global(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lunmake_special(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Luntrace(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lupbv(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lsimple_vectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lvectorp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lverbos(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwhitespace_char_p(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwritable_libraryp(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrite_module(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lwrs(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lxtab(Lisp_Object env, Lisp_Object a);
extern Lisp_Object Lzerop(Lisp_Object env, Lisp_Object a);
#ifdef COMMON
extern Lisp_Object Lfind_symbol_1(Lisp_Object nil, Lisp_Object str);
extern Lisp_Object Llistp(Lisp_Object env, Lisp_Object a);
#endif
extern Lisp_Object autoload2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_bytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_byteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object double_hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object double_interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object funarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracefunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracesetfunarged2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object hardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object hardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object interpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracebyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbyteopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbyteoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracebytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesetbytecoded2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object jitcompileme2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object traceinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracesetinterpreted2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object tracehardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesethardopt2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracehardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object tracesethardoptrest2(Lisp_Object def, Lisp_Object a, Lisp_Object b);
extern Lisp_Object undefined2(Lisp_Object env, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object f2_as_0(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object f2_as_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef CJAVA
extern Lisp_Object java2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object Lappend(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lapply_2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lapply1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lash1(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lassoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan2d(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latsoc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lbpsgetv(Lisp_Object nil, Lisp_Object v, Lisp_Object n);
extern Lisp_Object Lcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcopy_native(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldeleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldelete(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldifference2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ldivide(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequalcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leql(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Leqn(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lcl_equal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lequal(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lerror2(Lisp_Object nil, Lisp_Object a1, Lisp_Object a2);
extern Lisp_Object Lerrorset2(Lisp_Object nil, Lisp_Object form, Lisp_Object ffg1);
extern Lisp_Object Lexpt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lflagpcar(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfuncall2(Lisp_Object env, Lisp_Object fn, Lisp_Object a1);
extern Lisp_Object Lgcd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgeq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lget_hash_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lgreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lhelp_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lidifference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligeq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ligreaterp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lileq(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lilessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limax(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Limin(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Linorm(Lisp_Object nil, Lisp_Object a, Lisp_Object k);
extern Lisp_Object Linstate_c_code(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintersect(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Liremainder(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lirightshift(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Litimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llcm(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lleq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llessp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llist2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Llog_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmake_random_state(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmax2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmember(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmin2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmod(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_difference(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_expt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_plus(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_quotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmodular_times(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnconc(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lneq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lnreverse2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lorderp(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lpair(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lplus2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lquotient(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrem(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremflag(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lremprop(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lresource_limit2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplaca(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrplacd(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrseek(Lisp_Object nil, Lisp_Object a);
extern Lisp_Object Lset(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lset_help_file(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsgetv(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsmemq(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsubla(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsublis(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_protect(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_definition(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lsymbol_set_env(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lthrow_one_value(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltimes2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunion(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lwrite_help_module(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lxcons(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#ifdef COMMON
extern Lisp_Object Laref2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Latan_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lelt(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lfloat_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_1_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lmacroexpand_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lrandom_2(Lisp_Object nil, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Ltruncate_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
extern Lisp_Object Lunintern_2(Lisp_Object env, Lisp_Object a, Lisp_Object b);
#endif
extern Lisp_Object MS_CDECL autoloadn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_bytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_byteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL double_interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL funargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracefunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetfunargedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL hardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL interpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbyteoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbyteoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecoded0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecoded3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracebytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetbytecodedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompileme3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL jitcompilemen(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL traceinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracesetinterpretedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesethardoptn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracehardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL tracesethardoptrestn(Lisp_Object def, int nargs, ...);
extern Lisp_Object MS_CDECL undefinedn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f0_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_1(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL f3_as_3(Lisp_Object env, int nargs, ...);
#ifdef CJAVA
extern Lisp_Object MS_CDECL java0(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL java3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL javan(Lisp_Object env, int nargs, ...);
#endif
extern Lisp_Object MS_CDECL Lacons(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply2(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lapply3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lbpsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorset3(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lerrorsetn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lfuncalln(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lhelp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llist(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist2star(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llist3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogand(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogeqv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Llogxor(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmax(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmin(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lmkhash(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lput_hash(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputprop(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lresource_limitn(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsputv(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lsubst(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lvalues(Lisp_Object env, int nargs, ...);
#ifdef COMMON
extern Lisp_Object MS_CDECL Lappend_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Laref(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Laset(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Leqn_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lgcd_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgeq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lget_3(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lgreaterp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llcm_n(Lisp_Object env, int nargs, ...);
extern Lisp_Object MS_CDECL Lleq_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Llessp_n(Lisp_Object nil, int nargs, ...);
extern Lisp_Object MS_CDECL Lquotient_n(Lisp_Object nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern Lisp_Object MS_CDECL om_openFileDev(Lisp_Object env, int nargs, ...);
extern Lisp_Object om_openStringDev(Lisp_Object nil, Lisp_Object lstr, Lisp_Object lenc);
extern Lisp_Object om_closeDev(Lisp_Object env, Lisp_Object dev);
extern Lisp_Object om_setDevEncoding(Lisp_Object nil, Lisp_Object ldev, Lisp_Object lenc);
extern Lisp_Object om_makeConn(Lisp_Object nil, Lisp_Object ltimeout);
extern Lisp_Object om_closeConn(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnInDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object om_getConnOutDevice(Lisp_Object nil, Lisp_Object lconn);
extern Lisp_Object MS_CDECL om_connectTCP(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_bindTCP(Lisp_Object nil, Lisp_Object lconn, Lisp_Object lport);
extern Lisp_Object om_putApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_putInt(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putFloat(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putByteArray(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putVar(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putString(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object om_putSymbol(Lisp_Object nil, Lisp_Object ldev, Lisp_Object val);
extern Lisp_Object MS_CDECL om_putSymbol2(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_getApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndApp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAtp(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndAttr(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBind(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndBVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndError(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getEndObject(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getInt(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getFloat(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getByteArray(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getVar(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getString(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getSymbol(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_getType(Lisp_Object nil, Lisp_Object ldev);
extern Lisp_Object om_stringToStringPtr(Lisp_Object nil, Lisp_Object lstr);
extern Lisp_Object om_stringPtrToString(Lisp_Object nil, Lisp_Object lpstr);
extern Lisp_Object om_read(Lisp_Object nil, Lisp_Object dev);
extern Lisp_Object om_supportsCD(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_supportsSymbol(Lisp_Object nil, Lisp_Object lcd, Lisp_Object lsym);
extern Lisp_Object MS_CDECL om_listCDs(Lisp_Object nil, int nargs, ...);
extern Lisp_Object om_listSymbols(Lisp_Object nil, Lisp_Object lcd);
extern Lisp_Object om_whichCDs(Lisp_Object nil, Lisp_Object lsym);
#endif
#ifdef __cplusplus
}
#endif
#endif 


/* Code for !*addsq */

static Lisp_Object CC_Haddsq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0044, v0045;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *addsq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    v0044 = stack[-3];
    v0044 = qcar(v0044);
    if (v0044 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    v0044 = stack[-2];
    v0044 = qcar(v0044);
    if (v0044 == nil) { Lisp_Object res = stack[-3]; popv(6); return onevalue(res); }
    v0044 = stack[-3];
    v0045 = qcdr(v0044);
    v0044 = (Lisp_Object)17; /* 1 */
    if (v0045 == v0044) goto v0046;
    v0044 = qvalue(elt(env, 1)); /* nil */
    goto v0047;

v0047:
    if (v0044 == nil) goto v0048;
    v0044 = stack[-3];
    v0045 = qcar(v0044);
    v0044 = stack[-2];
    v0044 = qcar(v0044);
    fn = elt(env, 2); /* addf */
    v0045 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    v0044 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0045, v0044);

v0048:
    v0044 = stack[-3];
    v0045 = qcdr(v0044);
    stack[-4] = v0045;
    v0044 = stack[-2];
    v0044 = qcdr(v0044);
    stack[-1] = v0044;
    fn = elt(env, 3); /* gcdf */
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    stack[0] = v0044;
    v0045 = stack[-4];
    v0044 = stack[0];
    fn = elt(env, 4); /* quotf */
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    stack[-4] = v0044;
    v0045 = stack[-1];
    v0044 = stack[0];
    fn = elt(env, 4); /* quotf */
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    stack[-1] = v0044;
    v0045 = stack[-1];
    v0044 = stack[-3];
    v0044 = qcar(v0044);
    fn = elt(env, 5); /* !*multf */
    stack[0] = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    v0045 = stack[-4];
    v0044 = stack[-2];
    v0044 = qcar(v0044);
    fn = elt(env, 5); /* !*multf */
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    fn = elt(env, 2); /* addf */
    v0044 = (*qfn2(fn))(qenv(fn), stack[0], v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    stack[-2] = v0044;
    v0044 = stack[-2];
    if (v0044 == nil) goto v0050;
    v0044 = stack[-3];
    v0045 = qcdr(v0044);
    v0044 = stack[-1];
    fn = elt(env, 5); /* !*multf */
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    stack[-1] = v0044;
    v0044 = stack[-1];
    fn = elt(env, 6); /* minusf */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    if (v0044 == nil) goto v0051;
    v0044 = stack[-2];
    fn = elt(env, 7); /* negf */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    stack[-2] = v0044;
    v0044 = stack[-1];
    fn = elt(env, 7); /* negf */
    v0044 = (*qfn1(fn))(qenv(fn), v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    stack[-1] = v0044;
    goto v0051;

v0051:
    v0045 = stack[-2];
    v0044 = stack[-1];
    fn = elt(env, 3); /* gcdf */
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    stack[0] = v0044;
    v0045 = stack[0];
    v0044 = (Lisp_Object)17; /* 1 */
    if (v0045 == v0044) goto v0052;
    v0045 = stack[-2];
    v0044 = stack[0];
    fn = elt(env, 4); /* quotf */
    stack[-2] = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-5];
    v0045 = stack[-1];
    v0044 = stack[0];
    fn = elt(env, 4); /* quotf */
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    {
        Lisp_Object v0053 = stack[-2];
        popv(6);
        return cons(v0053, v0044);
    }

v0052:
    v0045 = stack[-2];
    v0044 = stack[-1];
    popv(6);
    return cons(v0045, v0044);

v0050:
    v0045 = qvalue(elt(env, 1)); /* nil */
    v0044 = (Lisp_Object)17; /* 1 */
    popv(6);
    return cons(v0045, v0044);

v0046:
    v0044 = stack[-2];
    v0045 = qcdr(v0044);
    v0044 = (Lisp_Object)17; /* 1 */
    v0044 = (v0045 == v0044 ? lisp_true : nil);
    goto v0047;
/* error exit handlers */
v0049:
    popv(6);
    return nil;
}



/* Code for find!-expts */

static Lisp_Object CC_findKexpts(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0012, v0011, v0075;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find-expts");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0012 = stack[-2];
    if (!consp(v0012)) goto v0076;
    v0012 = stack[-2];
    v0012 = qcar(v0012);
    v0012 = (consp(v0012) ? nil : lisp_true);
    goto v0077;

v0077:
    if (!(v0012 == nil)) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0012 = stack[-2];
    v0012 = qcar(v0012);
    stack[0] = qcdr(v0012);
    v0012 = stack[-2];
    v0011 = qcdr(v0012);
    v0012 = stack[-1];
    v0012 = CC_findKexpts(env, v0011, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    v0012 = CC_findKexpts(env, stack[0], v0012);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    stack[-1] = v0012;
    v0012 = stack[-2];
    v0012 = qcar(v0012);
    v0012 = qcar(v0012);
    v0012 = qcar(v0012);
    stack[-2] = v0012;
    v0011 = stack[-2];
    v0012 = elt(env, 2); /* sqrt */
    if (!consp(v0011)) goto v0034;
    v0011 = qcar(v0011);
    if (!(v0011 == v0012)) goto v0034;
    v0075 = elt(env, 3); /* expt */
    v0012 = stack[-2];
    v0012 = qcdr(v0012);
    v0011 = qcar(v0012);
    v0012 = elt(env, 4); /* (quotient 1 2) */
    v0012 = list3(v0075, v0011, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v0034:
    v0011 = stack[-2];
    v0012 = elt(env, 3); /* expt */
    if (!consp(v0011)) goto v0079;
    v0011 = qcar(v0011);
    if (!(v0011 == v0012)) goto v0079;
    v0012 = stack[-2];
    v0012 = qcdr(v0012);
    v0012 = qcdr(v0012);
    v0011 = qcar(v0012);
    v0012 = elt(env, 5); /* quotient */
    if (!consp(v0011)) goto v0080;
    v0011 = qcar(v0011);
    if (!(v0011 == v0012)) goto v0080;
    v0012 = stack[-2];
    v0012 = qcdr(v0012);
    v0012 = qcdr(v0012);
    v0012 = qcar(v0012);
    v0012 = qcdr(v0012);
    v0012 = qcdr(v0012);
    v0012 = qcar(v0012);
    v0012 = (is_number(v0012) ? lisp_true : nil);
    goto v0081;

v0081:
    if (v0012 == nil) { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }
    v0012 = stack[-2];
    v0012 = qcdr(v0012);
    v0011 = qcar(v0012);
    v0012 = stack[-1];
    v0012 = Lassoc(nil, v0011, v0012);
    stack[-3] = v0012;
    v0012 = stack[-3];
    if (!(v0012 == nil)) goto v0051;
    v0012 = stack[-2];
    v0012 = qcdr(v0012);
    stack[0] = qcar(v0012);
    v0012 = elt(env, 7); /* g */
    v0011 = Lgensym1(nil, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    v0012 = (Lisp_Object)17; /* 1 */
    v0012 = list2star(stack[0], v0011, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    stack[-3] = v0012;
    v0011 = stack[-3];
    v0012 = stack[-1];
    v0012 = cons(v0011, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    stack[-1] = v0012;
    goto v0051;

v0051:
    v0012 = stack[-3];
    stack[0] = qcdr(v0012);
    v0012 = stack[-3];
    v0012 = qcdr(v0012);
    v0011 = qcdr(v0012);
    v0012 = stack[-2];
    v0012 = qcdr(v0012);
    v0012 = qcdr(v0012);
    v0012 = qcar(v0012);
    v0012 = qcdr(v0012);
    v0012 = qcdr(v0012);
    v0012 = qcar(v0012);
    fn = elt(env, 8); /* lcm */
    v0012 = (*qfn2(fn))(qenv(fn), v0011, v0012);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    env = stack[-4];
    v0012 = Lrplacd(nil, stack[0], v0012);
    nil = C_nil;
    if (exception_pending()) goto v0078;
    { Lisp_Object res = stack[-1]; popv(5); return onevalue(res); }

v0080:
    v0012 = qvalue(elt(env, 6)); /* nil */
    goto v0081;

v0079:
    v0012 = qvalue(elt(env, 6)); /* nil */
    goto v0081;

v0076:
    v0012 = qvalue(elt(env, 1)); /* t */
    goto v0077;
/* error exit handlers */
v0078:
    popv(5);
    return nil;
}



/* Code for ps!:minus!-erule */

static Lisp_Object CC_psTminusKerule(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0083, v0084;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ps:minus-erule");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0083 = v0001;
    v0084 = v0000;
/* end of prologue */
    v0084 = qcdr(v0084);
    v0084 = qcar(v0084);
    fn = elt(env, 1); /* ps!:evaluate */
    v0083 = (*qfn2(fn))(qenv(fn), v0084, v0083);
    nil = C_nil;
    if (exception_pending()) goto v0085;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); /* negsq */
        return (*qfn1(fn))(qenv(fn), v0083);
    }
/* error exit handlers */
v0085:
    popv(1);
    return nil;
}



/* Code for compex */

static Lisp_Object CC_compex(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0088;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    v0088 = v0000;
/* end of prologue */
    stack[-3] = v0088;
    v0088 = stack[-3];
    if (v0088 == nil) goto v0077;
    v0088 = stack[-3];
    v0088 = qcar(v0088);
    fn = elt(env, 2); /* constrexp */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    stack[-1] = v0088;
    stack[-2] = v0088;
    goto v0090;

v0090:
    v0088 = stack[-3];
    v0088 = qcdr(v0088);
    stack[-3] = v0088;
    v0088 = stack[-3];
    if (v0088 == nil) { Lisp_Object res = stack[-2]; popv(5); return onevalue(res); }
    stack[0] = stack[-1];
    v0088 = stack[-3];
    v0088 = qcar(v0088);
    fn = elt(env, 2); /* constrexp */
    v0088 = (*qfn1(fn))(qenv(fn), v0088);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0088 = ncons(v0088);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0088 = Lrplacd(nil, stack[0], v0088);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-4];
    v0088 = stack[-1];
    v0088 = qcdr(v0088);
    stack[-1] = v0088;
    goto v0090;

v0077:
    v0088 = qvalue(elt(env, 1)); /* nil */
    { popv(5); return onevalue(v0088); }
/* error exit handlers */
v0089:
    popv(5);
    return nil;
}



/* Code for xreduce1 */

static Lisp_Object MS_CDECL CC_xreduce1(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0072, v0073, v0094;
    Lisp_Object fn;
    Lisp_Object v0086, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "xreduce1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0086 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xreduce1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0086,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0086);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0086;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0082;

v0082:
    v0094 = stack[-2];
    v0073 = stack[-1];
    v0072 = stack[0];
    fn = elt(env, 1); /* weak_xreduce1 */
    v0072 = (*qfnn(fn))(qenv(fn), 3, v0094, v0073, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    stack[-2] = v0072;
    if (v0072 == nil) goto v0096;
    v0072 = stack[-2];
    v0073 = qcar(v0072);
    v0072 = stack[-3];
    v0072 = cons(v0073, v0072);
    nil = C_nil;
    if (exception_pending()) goto v0095;
    env = stack[-4];
    stack[-3] = v0072;
    v0072 = stack[-2];
    v0072 = qcdr(v0072);
    stack[-2] = v0072;
    goto v0082;

v0096:
    v0072 = stack[-3];
    {
        popv(5);
        fn = elt(env, 2); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0072);
    }
/* error exit handlers */
v0095:
    popv(5);
    return nil;
}



/* Code for forttab */

static Lisp_Object CC_forttab(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for forttab");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0036 = qvalue(elt(env, 1)); /* fortlinelen!* */
    v0101 = qvalue(elt(env, 2)); /* minfortlinelen!* */
    v0101 = difference2(v0036, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    fn = elt(env, 5); /* min0 */
    v0036 = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    v0101 = (Lisp_Object)97; /* 6 */
    fn = elt(env, 6); /* max */
    v0101 = (*qfn2(fn))(qenv(fn), v0036, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0101; /* !*fortcurrind!* */
    v0036 = qvalue(elt(env, 3)); /* !*fortcurrind!* */
    v0101 = qvalue(elt(env, 4)); /* !*posn!* */
    v0036 = difference2(v0036, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    stack[0] = v0036;
    v0101 = (Lisp_Object)1; /* 0 */
    v0101 = (Lisp_Object)greaterp2(v0036, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    v0101 = v0101 ? lisp_true : nil;
    env = stack[-1];
    if (v0101 == nil) goto v0042;
    v0101 = stack[0];
    fn = elt(env, 7); /* nspaces */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0089;
    env = stack[-1];
    {
        popv(2);
        fn = elt(env, 8); /* pprin2 */
        return (*qfn1(fn))(qenv(fn), v0101);
    }

v0042:
    v0101 = nil;
    { popv(2); return onevalue(v0101); }
/* error exit handlers */
v0089:
    popv(2);
    return nil;
}



/* Code for dpropagator */

static Lisp_Object MS_CDECL CC_dpropagator(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0022, v0108, v0109;
    Lisp_Object fn;
    Lisp_Object v0086, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "dpropagator");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0086 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dpropagator");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0086,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0086);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0086;
    v0022 = v0001;
    v0108 = v0000;
/* end of prologue */
    fn = elt(env, 2); /* propagator */
    v0022 = (*qfn2(fn))(qenv(fn), v0108, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-5];
    v0109 = v0022;
    v0108 = v0109;
    v0022 = (Lisp_Object)1; /* 0 */
    if (v0108 == v0022) { popv(6); return onevalue(v0109); }
    v0108 = v0109;
    v0022 = (Lisp_Object)17; /* 1 */
    if (v0108 == v0022) goto v0040;
    v0022 = v0109;
    v0022 = qcdr(v0022);
    stack[-4] = v0022;
    v0022 = stack[-4];
    if (v0022 == nil) goto v0037;
    v0022 = stack[-4];
    v0022 = qcar(v0022);
    v0108 = v0022;
    v0022 = stack[-3];
    fn = elt(env, 3); /* mod!-index */
    v0022 = (*qfn2(fn))(qenv(fn), v0108, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-5];
    v0022 = ncons(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-5];
    stack[-1] = v0022;
    stack[-2] = v0022;
    goto v0089;

v0089:
    v0022 = stack[-4];
    v0022 = qcdr(v0022);
    stack[-4] = v0022;
    v0022 = stack[-4];
    if (v0022 == nil) { Lisp_Object res = stack[-2]; popv(6); return onevalue(res); }
    stack[0] = stack[-1];
    v0022 = stack[-4];
    v0022 = qcar(v0022);
    v0108 = v0022;
    v0022 = stack[-3];
    fn = elt(env, 3); /* mod!-index */
    v0022 = (*qfn2(fn))(qenv(fn), v0108, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-5];
    v0022 = ncons(v0022);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-5];
    v0022 = Lrplacd(nil, stack[0], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-5];
    v0022 = stack[-1];
    v0022 = qcdr(v0022);
    stack[-1] = v0022;
    goto v0089;

v0037:
    v0022 = qvalue(elt(env, 1)); /* nil */
    { popv(6); return onevalue(v0022); }

v0040:
    v0108 = qvalue(elt(env, 1)); /* nil */
    v0022 = stack[-3];
    popv(6);
    return cons(v0108, v0022);
/* error exit handlers */
v0028:
    popv(6);
    return nil;
}



/* Code for revalpart */

static Lisp_Object CC_revalpart(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0156, v0157, v0158, v0159, v0160;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revalpart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0156 = stack[0];
    if (v0156 == nil) goto v0099;
    stack[-7] = qvalue(elt(env, 3)); /* !*intstr */
    qvalue(elt(env, 3)) = nil; /* !*intstr */
    stack[-6] = nil;
    v0156 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 3)) = v0156; /* !*intstr */
    v0156 = stack[0];
    v0156 = qcar(v0156);
    fn = elt(env, 12); /* getrtype */
    v0157 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[-3] = v0157;
    v0156 = elt(env, 5); /* list */
    if (v0157 == v0156) goto v0070;
    v0156 = stack[0];
    v0156 = qcar(v0156);
    fn = elt(env, 13); /* reval */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    goto v0046;

v0046:
    stack[-5] = v0156;
    v0156 = qvalue(elt(env, 7)); /* nil */
    qvalue(elt(env, 3)) = v0156; /* !*intstr */
    v0156 = stack[0];
    v0156 = qcdr(v0156);
    stack[-4] = v0156;
    goto v0066;

v0066:
    v0156 = stack[-4];
    if (v0156 == nil) goto v0067;
    stack[-2] = nil;
    stack[-1] = nil;
    v0157 = stack[-5];
    v0156 = elt(env, 8); /* !*hold */
    v0156 = Leqcar(nil, v0157, v0156);
    env = stack[-8];
    stack[0] = v0156;
    v0156 = stack[-5];
    if (!consp(v0156)) goto v0023;
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    fn = elt(env, 13); /* reval */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[-2] = v0156;
    if (is_number(v0156)) goto v0162;
    v0160 = elt(env, 9); /* "Invalid argument" */
    v0156 = stack[-4];
    v0159 = qcar(v0156);
    v0158 = elt(env, 10); /* "to part" */
    v0157 = qvalue(elt(env, 7)); /* nil */
    v0156 = qvalue(elt(env, 4)); /* t */
    fn = elt(env, 14); /* msgpri */
    v0156 = (*qfnn(fn))(qenv(fn), 5, v0160, v0159, v0158, v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    goto v0163;

v0163:
    v0156 = stack[0];
    if (v0156 == nil) goto v0164;
    v0156 = stack[-1];
    v0156 = qcar(v0156);
    stack[-1] = v0156;
    v0156 = stack[-1];
    if (!consp(v0156)) goto v0165;
    v0156 = stack[-1];
    v0156 = qcdr(v0156);
    stack[-1] = v0156;
    goto v0164;

v0164:
    v0156 = stack[-6];
    if (!(v0156 == nil)) goto v0166;
    v0156 = stack[-1];
    v0157 = Llength(nil, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    v0156 = stack[-2];
    v0156 = (Lisp_Object)lessp2(v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    v0156 = v0156 ? lisp_true : nil;
    env = stack[-8];
    if (v0156 == nil) goto v0167;
    v0157 = stack[-5];
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    fn = elt(env, 15); /* parterr2 */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    v0156 = qvalue(elt(env, 4)); /* t */
    stack[-6] = v0156;
    goto v0166;

v0166:
    v0156 = stack[-6];
    if (v0156 == nil) goto v0168;
    v0156 = qvalue(elt(env, 7)); /* nil */
    goto v0169;

v0169:
    stack[-4] = v0156;
    goto v0066;

v0168:
    v0156 = stack[-4];
    v0156 = qcdr(v0156);
    goto v0169;

v0167:
    v0156 = stack[0];
    if (v0156 == nil) goto v0170;
    v0157 = stack[-1];
    v0156 = stack[-2];
    fn = elt(env, 16); /* nth */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[-5] = v0156;
    v0156 = stack[-5];
    if (!consp(v0156)) goto v0171;
    v0157 = stack[-5];
    v0156 = elt(env, 8); /* !*hold */
    v0156 = Leqcar(nil, v0157, v0156);
    env = stack[-8];
    v0156 = (v0156 == nil ? lisp_true : nil);
    goto v0172;

v0172:
    if (v0156 == nil) goto v0166;
    v0157 = elt(env, 8); /* !*hold */
    v0156 = stack[-5];
    v0156 = list2(v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[-5] = v0156;
    goto v0166;

v0171:
    v0156 = qvalue(elt(env, 7)); /* nil */
    goto v0172;

v0170:
    v0157 = stack[-1];
    v0156 = stack[-2];
    fn = elt(env, 16); /* nth */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[0] = v0156;
    v0156 = stack[0];
    fn = elt(env, 12); /* getrtype */
    v0157 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    v0156 = elt(env, 5); /* list */
    if (v0157 == v0156) goto v0173;
    v0156 = qvalue(elt(env, 7)); /* nil */
    goto v0174;

v0174:
    if (v0156 == nil) goto v0175;
    v0156 = stack[0];
    fn = elt(env, 17); /* listeval0 */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    goto v0176;

v0176:
    stack[-5] = v0156;
    goto v0166;

v0175:
    v0157 = stack[-3];
    v0156 = elt(env, 5); /* list */
    if (v0157 == v0156) goto v0177;
    v0156 = stack[0];
    goto v0176;

v0177:
    v0156 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 3)) = v0156; /* !*intstr */
    v0156 = stack[0];
    fn = elt(env, 13); /* reval */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[0] = v0156;
    v0156 = qvalue(elt(env, 7)); /* nil */
    stack[-3] = v0156;
    qvalue(elt(env, 3)) = v0156; /* !*intstr */
    v0156 = stack[0];
    goto v0176;

v0173:
    v0156 = elt(env, 5); /* list */
    stack[-3] = v0156;
    goto v0174;

v0165:
    v0157 = stack[-5];
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    fn = elt(env, 15); /* parterr2 */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    v0156 = qvalue(elt(env, 4)); /* t */
    stack[-6] = v0156;
    goto v0164;

v0162:
    v0156 = stack[-5];
    v0157 = qcar(v0156);
    v0156 = elt(env, 11); /* partop */
    v0156 = get(v0157, v0156);
    env = stack[-8];
    stack[-1] = v0156;
    if (v0156 == nil) goto v0013;
    v0158 = stack[-1];
    v0157 = stack[-5];
    v0156 = stack[-2];
    v0156 = Lapply2(nil, 3, v0158, v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[-5] = v0156;
    v0156 = stack[-4];
    v0156 = qcdr(v0156);
    stack[-4] = v0156;
    goto v0066;

v0013:
    v0157 = stack[-2];
    v0156 = (Lisp_Object)1; /* 0 */
    if (v0157 == v0156) goto v0178;
    v0157 = stack[-2];
    v0156 = (Lisp_Object)1; /* 0 */
    v0156 = (Lisp_Object)lessp2(v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    v0156 = v0156 ? lisp_true : nil;
    env = stack[-8];
    if (v0156 == nil) goto v0179;
    v0156 = stack[-2];
    v0156 = negate(v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[-2] = v0156;
    v0156 = stack[-5];
    v0156 = qcdr(v0156);
    v0156 = Lreverse(nil, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[-1] = v0156;
    goto v0163;

v0179:
    v0156 = stack[-5];
    v0156 = qcdr(v0156);
    stack[-1] = v0156;
    goto v0163;

v0178:
    v0156 = stack[-5];
    v0156 = qcar(v0156);
    stack[0] = v0156;
    v0156 = stack[0];
    fn = elt(env, 12); /* getrtype */
    v0157 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    v0156 = elt(env, 5); /* list */
    if (v0157 == v0156) goto v0180;
    v0156 = qvalue(elt(env, 7)); /* nil */
    goto v0078;

v0078:
    if (v0156 == nil) goto v0044;
    v0156 = stack[0];
    fn = elt(env, 17); /* listeval0 */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    goto v0181;

v0181:
    stack[-5] = v0156;
    v0156 = qvalue(elt(env, 7)); /* nil */
    stack[-4] = v0156;
    goto v0066;

v0044:
    v0157 = stack[-3];
    v0156 = elt(env, 5); /* list */
    if (v0157 == v0156) goto v0004;
    v0156 = stack[0];
    goto v0181;

v0004:
    v0156 = qvalue(elt(env, 4)); /* t */
    qvalue(elt(env, 3)) = v0156; /* !*intstr */
    v0156 = stack[0];
    fn = elt(env, 13); /* reval */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    stack[0] = v0156;
    v0156 = qvalue(elt(env, 7)); /* nil */
    stack[-3] = v0156;
    qvalue(elt(env, 3)) = v0156; /* !*intstr */
    v0156 = stack[0];
    goto v0181;

v0180:
    v0156 = elt(env, 5); /* list */
    stack[-3] = v0156;
    goto v0078;

v0023:
    v0157 = stack[-5];
    v0156 = stack[-4];
    v0156 = qcar(v0156);
    fn = elt(env, 15); /* parterr2 */
    v0156 = (*qfn2(fn))(qenv(fn), v0157, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    v0156 = qvalue(elt(env, 4)); /* t */
    stack[-6] = v0156;
    goto v0163;

v0067:
    v0156 = stack[-6];
    if (v0156 == nil) goto v0182;
    v0156 = (Lisp_Object)1; /* 0 */
    goto v0183;

v0183:
    qvalue(elt(env, 3)) = stack[-7]; /* !*intstr */
    { popv(9); return onevalue(v0156); }

v0182:
    v0156 = stack[-5];
    fn = elt(env, 13); /* reval */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    goto v0183;

v0070:
    v0156 = stack[0];
    v0156 = qcar(v0156);
    if (!consp(v0156)) goto v0019;
    v0156 = stack[0];
    v0156 = qcar(v0156);
    v0157 = qcar(v0156);
    v0156 = elt(env, 6); /* listfn */
    v0156 = get(v0157, v0156);
    env = stack[-8];
    goto v0101;

v0101:
    if (v0156 == nil) goto v0068;
    v0156 = stack[0];
    v0156 = qcar(v0156);
    fn = elt(env, 13); /* reval */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    goto v0046;

v0068:
    v0156 = stack[0];
    v0156 = qcar(v0156);
    fn = elt(env, 17); /* listeval0 */
    v0156 = (*qfn1(fn))(qenv(fn), v0156);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-8];
    goto v0046;

v0019:
    v0156 = qvalue(elt(env, 7)); /* nil */
    goto v0101;

v0099:
    v0158 = elt(env, 1); /* alg */
    v0157 = (Lisp_Object)3217; /* 201 */
    v0156 = elt(env, 2); /* "part called without arguments" */
    {
        popv(9);
        fn = elt(env, 18); /* rerror */
        return (*qfnn(fn))(qenv(fn), 3, v0158, v0157, v0156);
    }
/* error exit handlers */
v0161:
    env = stack[-8];
    qvalue(elt(env, 3)) = stack[-7]; /* !*intstr */
    popv(9);
    return nil;
}



/* Code for formclear */

static Lisp_Object MS_CDECL CC_formclear(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0100, v0115, v0110;
    Lisp_Object fn;
    Lisp_Object v0086, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "formclear");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0086 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for formclear");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0086,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0086);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0100 = v0086;
    v0115 = v0001;
    v0110 = v0000;
/* end of prologue */
    stack[0] = elt(env, 1); /* clear */
    v0110 = qcdr(v0110);
    fn = elt(env, 2); /* formclear1 */
    v0100 = (*qfnn(fn))(qenv(fn), 3, v0110, v0115, v0100);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    {
        Lisp_Object v0043 = stack[0];
        popv(1);
        return list2(v0043, v0100);
    }
/* error exit handlers */
v0042:
    popv(1);
    return nil;
}



/* Code for dv_skelsplit */

static Lisp_Object CC_dv_skelsplit(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0120, v0112, v0155;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dv_skelsplit");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push(nil);
/* copy arguments values to proper place */
    stack[-9] = v0000;
/* end of prologue */
    v0120 = (Lisp_Object)1; /* 0 */
    stack[-5] = v0120;
    v0120 = stack[-9];
    fn = elt(env, 9); /* listp */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    if (v0120 == nil) goto v0047;
    v0120 = stack[-9];
    v0112 = qcar(v0120);
    v0120 = elt(env, 3); /* symtree */
    v0120 = get(v0112, v0120);
    env = stack[-11];
    stack[-10] = v0120;
    v0120 = stack[-10];
    if (!(v0120 == nil)) goto v0033;
    v0120 = (Lisp_Object)17; /* 1 */
    stack[-3] = v0120;
    v0120 = stack[-9];
    v0120 = qcdr(v0120);
    v0112 = Llength(nil, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = stack[-3];
    v0120 = difference2(v0112, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = Lminusp(nil, v0120);
    env = stack[-11];
    if (v0120 == nil) goto v0217;
    v0120 = qvalue(elt(env, 4)); /* nil */
    goto v0066;

v0066:
    stack[-10] = v0120;
    v0120 = stack[-9];
    v0120 = qcar(v0120);
    if (!symbolp(v0120)) v0120 = nil;
    else { v0120 = qfastgets(v0120);
           if (v0120 != nil) { v0120 = elt(v0120, 43); /* symmetric */
#ifdef RECORD_GET
             if (v0120 == SPID_NOPROP)
                record_get(elt(fastget_names, 43), 0),
                v0120 = nil;
             else record_get(elt(fastget_names, 43), 1),
                v0120 = lisp_true; }
           else record_get(elt(fastget_names, 43), 0); }
#else
             if (v0120 == SPID_NOPROP) v0120 = nil; else v0120 = lisp_true; }}
#endif
    if (v0120 == nil) goto v0051;
    v0112 = elt(env, 5); /* !+ */
    v0120 = stack[-10];
    v0120 = cons(v0112, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-10] = v0120;
    goto v0033;

v0033:
    v0120 = stack[-9];
    v0120 = qcdr(v0120);
    v0120 = Llength(nil, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = sub1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = Lmkvect(nil, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-8] = v0120;
    v0120 = (Lisp_Object)1; /* 0 */
    stack[-7] = v0120;
    v0120 = stack[-9];
    v0120 = qcdr(v0120);
    stack[-4] = v0120;
    goto v0218;

v0218:
    v0120 = stack[-4];
    if (v0120 == nil) goto v0219;
    v0120 = stack[-4];
    v0120 = qcar(v0120);
    stack[-1] = v0120;
    v0120 = stack[-7];
    v0120 = add1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-7] = v0120;
    v0120 = stack[-1];
    fn = elt(env, 9); /* listp */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    if (v0120 == nil) goto v0220;
    stack[-2] = stack[-8];
    v0120 = stack[-7];
    stack[0] = sub1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = stack[-1];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0120;
    goto v0044;

v0044:
    v0120 = stack[-4];
    v0120 = qcdr(v0120);
    stack[-4] = v0120;
    goto v0218;

v0220:
    v0120 = stack[-1];
    fn = elt(env, 10); /* dummyp */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-6] = v0120;
    if (v0120 == nil) goto v0134;
    v0112 = stack[-5];
    v0120 = stack[-6];
    fn = elt(env, 11); /* max */
    v0120 = (*qfn2(fn))(qenv(fn), v0112, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-5] = v0120;
    stack[-3] = stack[-8];
    v0120 = stack[-7];
    stack[-2] = sub1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-1] = elt(env, 1); /* !~dv */
    stack[0] = elt(env, 2); /* !* */
    v0120 = stack[-6];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = list2star(stack[-1], stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-3] + (CELL-TAG_VECTOR) + ((int32_t)stack[-2]/(16/CELL))) = v0120;
    goto v0044;

v0134:
    stack[-2] = stack[-8];
    v0120 = stack[-7];
    stack[0] = sub1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = stack[-1];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    *(Lisp_Object *)((char *)stack[-2] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0120;
    goto v0044;

v0219:
    v0155 = stack[-10];
    v0112 = stack[-8];
    v0120 = elt(env, 8); /* skp_ordp */
    fn = elt(env, 12); /* st_sorttree */
    v0120 = (*qfnn(fn))(qenv(fn), 3, v0155, v0112, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-10] = v0120;
    v0120 = stack[-10];
    if (v0120 == nil) goto v0221;
    v0120 = stack[-10];
    v0112 = qcar(v0120);
    v0120 = (Lisp_Object)1; /* 0 */
    if (!(v0112 == v0120)) goto v0221;
    v0120 = qvalue(elt(env, 4)); /* nil */
    { popv(12); return onevalue(v0120); }

v0221:
    v0120 = stack[-10];
    v0120 = qcar(v0120);
    stack[0] = v0120;
    v0120 = stack[-10];
    v0112 = qcdr(v0120);
    v0120 = stack[-8];
    fn = elt(env, 13); /* dv_skelsplit1 */
    v0120 = (*qfn2(fn))(qenv(fn), v0112, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-1] = v0120;
    v0120 = stack[-1];
    v0120 = qcdr(v0120);
    fn = elt(env, 14); /* st_consolidate */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-10] = v0120;
    v0120 = stack[-9];
    v0112 = qcar(v0120);
    v0120 = stack[-1];
    v0120 = qcar(v0120);
    v0120 = cons(v0112, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-1] = v0120;
    stack[-2] = stack[-5];
    v0112 = stack[-1];
    v0120 = stack[-10];
    v0120 = cons(v0112, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    {
        Lisp_Object v0117 = stack[0];
        Lisp_Object v0222 = stack[-2];
        popv(12);
        return list3(v0117, v0222, v0120);
    }

v0051:
    v0120 = stack[-9];
    v0112 = qcar(v0120);
    v0120 = elt(env, 6); /* antisymmetric */
    v0120 = Lflagp(nil, v0112, v0120);
    env = stack[-11];
    if (v0120 == nil) goto v0052;
    v0112 = elt(env, 7); /* !- */
    v0120 = stack[-10];
    v0120 = cons(v0112, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-10] = v0120;
    goto v0033;

v0052:
    v0112 = elt(env, 2); /* !* */
    v0120 = stack[-10];
    v0120 = cons(v0112, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-10] = v0120;
    goto v0033;

v0217:
    v0120 = stack[-3];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-1] = v0120;
    stack[-2] = v0120;
    goto v0031;

v0031:
    v0120 = stack[-3];
    v0120 = add1(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-3] = v0120;
    v0120 = stack[-9];
    v0120 = qcdr(v0120);
    v0112 = Llength(nil, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = stack[-3];
    v0120 = difference2(v0112, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = Lminusp(nil, v0120);
    env = stack[-11];
    if (v0120 == nil) goto v0223;
    v0120 = stack[-2];
    goto v0066;

v0223:
    stack[0] = stack[-1];
    v0120 = stack[-3];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = Lrplacd(nil, stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = stack[-1];
    v0120 = qcdr(v0120);
    stack[-1] = v0120;
    goto v0031;

v0047:
    v0120 = stack[-9];
    fn = elt(env, 10); /* dummyp */
    v0120 = (*qfn1(fn))(qenv(fn), v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    stack[-6] = v0120;
    if (v0120 == nil) goto v0224;
    stack[-3] = (Lisp_Object)17; /* 1 */
    stack[-2] = stack[-6];
    stack[-1] = elt(env, 1); /* !~dv */
    stack[0] = elt(env, 2); /* !* */
    v0120 = stack[-6];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    env = stack[-11];
    v0120 = list2star(stack[-1], stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    {
        Lisp_Object v0118 = stack[-3];
        Lisp_Object v0225 = stack[-2];
        popv(12);
        return list3(v0118, v0225, v0120);
    }

v0224:
    stack[-1] = (Lisp_Object)17; /* 1 */
    stack[0] = (Lisp_Object)1; /* 0 */
    v0120 = stack[-9];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0216;
    {
        Lisp_Object v0226 = stack[-1];
        Lisp_Object v0227 = stack[0];
        popv(12);
        return list3(v0226, v0227, v0120);
    }
/* error exit handlers */
v0216:
    popv(12);
    return nil;
}



/* Code for allbkern */

static Lisp_Object CC_allbkern(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0036;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for allbkern");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    stack[-1] = nil;
    goto v0203;

v0203:
    v0101 = stack[0];
    if (v0101 == nil) goto v0090;
    v0101 = stack[0];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    fn = elt(env, 2); /* kernels */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-2];
    fn = elt(env, 3); /* basic!-kern */
    v0036 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-2];
    v0101 = stack[-1];
    v0101 = cons(v0036, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-2];
    stack[-1] = v0101;
    v0101 = stack[0];
    v0101 = qcdr(v0101);
    stack[0] = v0101;
    goto v0203;

v0090:
    v0101 = qvalue(elt(env, 1)); /* nil */
    v0036 = v0101;
    goto v0099;

v0099:
    v0101 = stack[-1];
    if (v0101 == nil) { popv(3); return onevalue(v0036); }
    v0101 = stack[-1];
    v0101 = qcar(v0101);
    fn = elt(env, 4); /* union */
    v0101 = (*qfn2(fn))(qenv(fn), v0101, v0036);
    nil = C_nil;
    if (exception_pending()) goto v0229;
    env = stack[-2];
    v0036 = v0101;
    v0101 = stack[-1];
    v0101 = qcdr(v0101);
    stack[-1] = v0101;
    goto v0099;
/* error exit handlers */
v0229:
    popv(3);
    return nil;
}



/* Code for flatten */

static Lisp_Object CC_flatten(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0019, v0006;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for flatten");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0006 = nil;
    goto v0198;

v0198:
    v0019 = stack[-1];
    if (v0019 == nil) goto v0099;
    v0019 = stack[-1];
    if (!consp(v0019)) goto v0039;
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    if (!consp(v0019)) goto v0070;
    stack[-2] = v0006;
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    stack[0] = CC_flatten(env, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    v0019 = CC_flatten(env, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0019 = Lnconc(nil, stack[0], v0019);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    {
        Lisp_Object v0068 = stack[-2];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0068, v0019);
    }

v0070:
    v0019 = stack[-1];
    v0019 = qcar(v0019);
    v0019 = cons(v0019, v0006);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    v0006 = v0019;
    v0019 = stack[-1];
    v0019 = qcdr(v0019);
    stack[-1] = v0019;
    goto v0198;

v0039:
    stack[0] = v0006;
    v0019 = stack[-1];
    v0019 = ncons(v0019);
    nil = C_nil;
    if (exception_pending()) goto v0231;
    env = stack[-3];
    {
        Lisp_Object v0048 = stack[0];
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn2(fn))(qenv(fn), v0048, v0019);
    }

v0099:
    v0019 = v0006;
    {
        popv(4);
        fn = elt(env, 1); /* nreverse */
        return (*qfn1(fn))(qenv(fn), v0019);
    }
/* error exit handlers */
v0231:
    popv(4);
    return nil;
}



/* Code for addlc */

static Lisp_Object CC_addlc(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0233, v0034, v0234, v0212;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addlc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0212 = v0001;
    v0234 = v0000;
/* end of prologue */
    v0034 = v0234;
    v0233 = (Lisp_Object)17; /* 1 */
    if (v0034 == v0233) return onevalue(v0212);
    v0233 = v0234;
    v0233 = qcar(v0233);
    v0233 = qcdr(v0233);
    v0234 = v0233;
    v0034 = v0234;
    v0233 = (Lisp_Object)17; /* 1 */
    if (v0034 == v0233) goto v0042;
    v0034 = v0234;
    v0233 = (Lisp_Object)-15; /* -1 */
    if (v0034 == v0233) goto v0098;
    v0233 = v0234;
    if (!consp(v0233)) goto v0019;
    v0233 = v0234;
    v0233 = qcar(v0233);
    if (!symbolp(v0233)) v0233 = nil;
    else { v0233 = qfastgets(v0233);
           if (v0233 != nil) { v0233 = elt(v0233, 3); /* field */
#ifdef RECORD_GET
             if (v0233 == SPID_NOPROP)
                record_get(elt(fastget_names, 3), 0),
                v0233 = nil;
             else record_get(elt(fastget_names, 3), 1),
                v0233 = lisp_true; }
           else record_get(elt(fastget_names, 3), 0); }
#else
             if (v0233 == SPID_NOPROP) v0233 = nil; else v0233 = lisp_true; }}
#endif
    goto v0183;

v0183:
    if (!(v0233 == nil)) return onevalue(v0212);
    v0233 = v0234;
    v0034 = v0212;
    return cons(v0233, v0034);

v0019:
    v0233 = qvalue(elt(env, 2)); /* nil */
    goto v0183;

v0098:
    v0233 = qvalue(elt(env, 1)); /* t */
    goto v0183;

v0042:
    v0233 = qvalue(elt(env, 1)); /* t */
    goto v0183;
}



/* Code for ofsf_chsimpat1 */

static Lisp_Object CC_ofsf_chsimpat1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0104, v0121, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_chsimpat1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    stack[0] = nil;
    stack[-3] = nil;
    v0104 = stack[-2];
    v0104 = qcdr(v0104);
    v0104 = qcar(v0104);
    stack[-1] = v0104;
    v0104 = stack[-1];
    v0104 = Lconsp(nil, v0104);
    env = stack[-4];
    if (v0104 == nil) goto v0076;
    v0104 = stack[-1];
    v0121 = qcar(v0104);
    v0104 = elt(env, 1); /* (lessp leq equal neq geq greaterp) */
    v0104 = Lmemq(nil, v0121, v0104);
    if (v0104 == nil) goto v0076;
    v0104 = stack[-1];
    v0104 = CC_ofsf_chsimpat1(env, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-4];
    stack[0] = v0104;
    v0104 = stack[0];
    fn = elt(env, 2); /* lastcar */
    v0104 = (*qfn1(fn))(qenv(fn), v0104);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-4];
    v0104 = qcdr(v0104);
    v0104 = qcdr(v0104);
    v0104 = qcar(v0104);
    stack[-1] = v0104;
    goto v0076;

v0076:
    v0104 = stack[-2];
    v0104 = qcdr(v0104);
    v0104 = qcdr(v0104);
    v0104 = qcar(v0104);
    v0121 = v0104;
    v0121 = Lconsp(nil, v0121);
    env = stack[-4];
    if (v0121 == nil) goto v0034;
    v0121 = v0104;
    v0122 = qcar(v0121);
    v0121 = elt(env, 1); /* (lessp leq equal neq geq greaterp) */
    v0121 = Lmemq(nil, v0122, v0121);
    if (v0121 == nil) goto v0034;
    v0104 = CC_ofsf_chsimpat1(env, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-4];
    stack[-3] = v0104;
    v0104 = stack[-3];
    v0104 = qcar(v0104);
    v0104 = qcdr(v0104);
    v0104 = qcar(v0104);
    goto v0034;

v0034:
    v0121 = stack[-2];
    v0122 = qcar(v0121);
    v0121 = stack[-1];
    v0121 = list3(v0122, v0121, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-4];
    v0104 = stack[-3];
    v0104 = cons(v0121, v0104);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    {
        Lisp_Object v0065 = stack[0];
        popv(5);
        return Lnconc(nil, v0065, v0104);
    }
/* error exit handlers */
v0103:
    popv(5);
    return nil;
}



/* Code for dependsl */

static Lisp_Object CC_dependsl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0106, v0107;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dependsl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */

v0236:
    v0106 = stack[0];
    if (v0106 == nil) goto v0198;
    v0107 = stack[-1];
    v0106 = stack[0];
    v0106 = qcar(v0106);
    fn = elt(env, 2); /* depends */
    v0106 = (*qfn2(fn))(qenv(fn), v0107, v0106);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-2];
    if (!(v0106 == nil)) { popv(3); return onevalue(v0106); }
    v0107 = stack[-1];
    v0106 = stack[0];
    v0106 = qcdr(v0106);
    stack[-1] = v0107;
    stack[0] = v0106;
    goto v0236;

v0198:
    v0106 = qvalue(elt(env, 1)); /* nil */
    { popv(3); return onevalue(v0106); }
/* error exit handlers */
v0041:
    popv(3);
    return nil;
}



/* Code for mri_irsplit */

static Lisp_Object CC_mri_irsplit(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0067, v0066, v0031;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mri_irsplit");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0031 = v0000;
/* end of prologue */
    v0066 = v0031;
    v0067 = elt(env, 1); /* floor */
    if (!consp(v0066)) goto v0183;
    v0066 = qcar(v0066);
    if (!(v0066 == v0067)) goto v0183;
    v0067 = v0031;
    v0067 = qcdr(v0067);
    v0067 = qcar(v0067);
    fn = elt(env, 2); /* simp */
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0067 = qcar(v0067);
    fn = elt(env, 3); /* mri_simplfloor */
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    fn = elt(env, 4); /* mri_irsplit1 */
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0066 = v0067;
    v0067 = v0066;
    stack[-1] = qcar(v0067);
    v0067 = v0066;
    v0067 = qcdr(v0067);
    if (v0067 == nil) goto v0237;
    stack[0] = elt(env, 1); /* floor */
    v0067 = v0066;
    v0067 = qcdr(v0067);
    fn = elt(env, 5); /* prepf */
    v0067 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0067 = list2(stack[0], v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    fn = elt(env, 6); /* !*a2k */
    v0066 = (*qfn1(fn))(qenv(fn), v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0067 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 7); /* to */
    v0066 = (*qfn2(fn))(qenv(fn), v0066, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0067 = (Lisp_Object)17; /* 1 */
    v0067 = cons(v0066, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0067 = ncons(v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    goto v0095;

v0095:
    {
        Lisp_Object v0235 = stack[-1];
        popv(3);
        return cons(v0235, v0067);
    }

v0237:
    v0067 = nil;
    goto v0095;

v0183:
    v0066 = v0031;
    v0067 = (Lisp_Object)17; /* 1 */
    fn = elt(env, 7); /* to */
    v0066 = (*qfn2(fn))(qenv(fn), v0066, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0067 = (Lisp_Object)17; /* 1 */
    v0067 = cons(v0066, v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    env = stack[-2];
    v0067 = ncons(v0067);
    nil = C_nil;
    if (exception_pending()) goto v0217;
    popv(3);
    return ncons(v0067);
/* error exit handlers */
v0217:
    popv(3);
    return nil;
}



/* Code for rl_b2atl */

static Lisp_Object CC_rl_b2atl(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0047, v0239;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_b2atl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0047 = v0001;
    v0239 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_b2atl!* */
    v0047 = list2(v0239, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0091;
    env = stack[-1];
    {
        Lisp_Object v0092 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0092, v0047);
    }
/* error exit handlers */
v0091:
    popv(2);
    return nil;
}



/* Code for subsqnew */

static Lisp_Object MS_CDECL CC_subsqnew(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0101, v0036;
    Lisp_Object fn;
    Lisp_Object v0086, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subsqnew");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0086 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subsqnew");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0086,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0086);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0086;
    v0101 = v0001;
    stack[-1] = v0000;
/* end of prologue */
    fn = elt(env, 1); /* prepsq */
    v0101 = (*qfn1(fn))(qenv(fn), v0101);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    v0036 = stack[0];
    v0101 = cons(v0036, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    stack[-2] = v0101;
    v0101 = stack[-1];
    stack[0] = qcar(v0101);
    v0101 = stack[-2];
    v0101 = ncons(v0101);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    fn = elt(env, 2); /* subf */
    stack[0] = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    v0101 = stack[-1];
    stack[-1] = qcdr(v0101);
    v0101 = stack[-2];
    v0101 = ncons(v0101);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    fn = elt(env, 2); /* subf */
    v0101 = (*qfn2(fn))(qenv(fn), stack[-1], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0240;
    env = stack[-3];
    {
        Lisp_Object v0237 = stack[0];
        popv(4);
        fn = elt(env, 3); /* quotsq */
        return (*qfn2(fn))(qenv(fn), v0237, v0101);
    }
/* error exit handlers */
v0240:
    popv(4);
    return nil;
}



/* Code for lengthf */

static Lisp_Object CC_lengthf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0259, v0260;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lengthf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    v0259 = stack[-1];
    if (v0259 == nil) goto v0087;
    v0259 = stack[-1];
    if (!consp(v0259)) goto v0099;
    v0260 = stack[-1];
    v0259 = elt(env, 1); /* plus */
    if (!consp(v0260)) goto v0229;
    v0260 = qcar(v0260);
    if (!(v0260 == v0259)) goto v0229;
    stack[0] = (Lisp_Object)49; /* 3 */
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = Llength(nil, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0259 = sub1(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    stack[0] = times2(stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = CC_lengthf(env, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    {
        Lisp_Object v0262 = stack[0];
        popv(4);
        return plus2(v0262, v0259);
    }

v0229:
    v0260 = stack[-1];
    v0259 = elt(env, 2); /* times */
    if (!consp(v0260)) goto v0019;
    v0260 = qcar(v0260);
    if (!(v0260 == v0259)) goto v0019;
    v0259 = qvalue(elt(env, 3)); /* t */
    goto v0101;

v0101:
    if (v0259 == nil) goto v0032;
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = Llength(nil, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    stack[0] = sub1(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = CC_lengthf(env, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    {
        Lisp_Object v0263 = stack[0];
        popv(4);
        return plus2(v0263, v0259);
    }

v0032:
    v0260 = stack[-1];
    v0259 = elt(env, 5); /* quotient */
    if (!consp(v0260)) goto v0148;
    v0260 = qcar(v0260);
    if (!(v0260 == v0259)) goto v0148;
    v0259 = qvalue(elt(env, 6)); /* !*rational */
    if (v0259 == nil) goto v0264;
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    fn = elt(env, 16); /* flatsizec */
    stack[0] = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    fn = elt(env, 16); /* flatsizec */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    fn = elt(env, 17); /* max */
    v0259 = (*qfn2(fn))(qenv(fn), stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0259 = add1(v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    popv(4);
    return add1(v0259);

v0264:
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    fn = elt(env, 16); /* flatsizec */
    stack[0] = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    fn = elt(env, 16); /* flatsizec */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0259 = plus2(stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    popv(4);
    return add1(v0259);

v0148:
    v0260 = stack[-1];
    v0259 = elt(env, 7); /* expt */
    if (!consp(v0260)) goto v0265;
    v0260 = qcar(v0260);
    if (!(v0260 == v0259)) goto v0265;
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    fn = elt(env, 16); /* flatsizec */
    v0259 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    popv(4);
    return add1(v0259);

v0265:
    v0260 = stack[-1];
    v0259 = elt(env, 8); /* dx */
    if (!consp(v0260)) goto v0178;
    v0260 = qcar(v0260);
    if (!(v0260 == v0259)) goto v0178;
    v0259 = qvalue(elt(env, 3)); /* t */
    goto v0146;

v0146:
    if (v0259 == nil) goto v0141;
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    fn = elt(env, 16); /* flatsizec */
    v0260 = (*qfn1(fn))(qenv(fn), v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    v0259 = (Lisp_Object)65; /* 4 */
    popv(4);
    return plus2(v0260, v0259);

v0141:
    v0260 = stack[-1];
    v0259 = elt(env, 10); /* xi */
    if (!consp(v0260)) goto v0266;
    v0260 = qcar(v0260);
    if (!(v0260 == v0259)) goto v0266;
    v0259 = qvalue(elt(env, 3)); /* t */
    goto v0218;

v0218:
    if (v0259 == nil) goto v0267;
    stack[0] = (Lisp_Object)33; /* 2 */
    v0259 = stack[-1];
    v0259 = Llength(nil, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    {
        Lisp_Object v0126 = stack[0];
        popv(4);
        return times2(v0126, v0259);
    }

v0267:
    v0260 = stack[-1];
    v0259 = elt(env, 15); /* df */
    if (!consp(v0260)) goto v0268;
    v0260 = qcar(v0260);
    if (!(v0260 == v0259)) goto v0268;
    stack[-2] = (Lisp_Object)65; /* 4 */
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = qcar(v0259);
    stack[0] = CC_lengthf(env, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = qcdr(v0259);
    v0259 = CC_lengthf(env, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0259 = plus2(stack[0], v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    {
        Lisp_Object v0127 = stack[-2];
        popv(4);
        return plus2(v0127, v0259);
    }

v0268:
    v0259 = stack[-1];
    v0259 = qcar(v0259);
    stack[0] = CC_lengthf(env, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    env = stack[-3];
    v0259 = stack[-1];
    v0259 = qcdr(v0259);
    v0259 = CC_lengthf(env, v0259);
    nil = C_nil;
    if (exception_pending()) goto v0261;
    {
        Lisp_Object v0187 = stack[0];
        popv(4);
        return plus2(v0187, v0259);
    }

v0266:
    v0260 = stack[-1];
    v0259 = elt(env, 11); /* eta */
    if (!consp(v0260)) goto v0269;
    v0260 = qcar(v0260);
    if (!(v0260 == v0259)) goto v0269;
    v0259 = qvalue(elt(env, 3)); /* t */
    goto v0218;

v0269:
    v0260 = stack[-1];
    v0259 = elt(env, 12); /* c */
    if (!consp(v0260)) goto v0270;
    v0260 = qcar(v0260);
    if (!(v0260 == v0259)) goto v0270;
    v0259 = qvalue(elt(env, 3)); /* t */
    goto v0218;

v0270:
    v0260 = stack[-1];
    v0259 = elt(env, 13); /* x */
    if (!consp(v0260)) goto v0271;
    v0260 = qcar(v0260);
    if (!(v0260 == v0259)) goto v0271;
    v0259 = qvalue(elt(env, 3)); /* t */
    goto v0218;

v0271:
    v0260 = stack[-1];
    v0259 = elt(env, 14); /* u */
    v0259 = Leqcar(nil, v0260, v0259);
    env = stack[-3];
    goto v0218;

v0178:
    v0260 = stack[-1];
    v0259 = elt(env, 9); /* du */
    v0259 = Leqcar(nil, v0260, v0259);
    env = stack[-3];
    goto v0146;

v0019:
    v0260 = stack[-1];
    v0259 = elt(env, 4); /* minus */
    v0259 = Leqcar(nil, v0260, v0259);
    env = stack[-3];
    goto v0101;

v0099:
    v0259 = stack[-1];
    {
        popv(4);
        fn = elt(env, 16); /* flatsizec */
        return (*qfn1(fn))(qenv(fn), v0259);
    }

v0087:
    v0259 = (Lisp_Object)1; /* 0 */
    { popv(4); return onevalue(v0259); }
/* error exit handlers */
v0261:
    popv(4);
    return nil;
}



/* Code for functionp */

static Lisp_Object CC_functionp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0238, v0074;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for functionp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0238 = v0000;
/* end of prologue */
    v0074 = v0238;
    v0074 = Lcodep(nil, v0074);
    env = stack[0];
    if (!(v0074 == nil)) { popv(1); return onevalue(v0074); }
    {
        popv(1);
        fn = elt(env, 1); /* lambdap */
        return (*qfn1(fn))(qenv(fn), v0238);
    }
}



/* Code for requote1 */

static Lisp_Object CC_requote1(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0108, v0109;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for requote1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0000;
/* end of prologue */
    stack[-2] = nil;
    stack[0] = nil;
    goto v0203;

v0203:
    v0108 = stack[-1];
    if (v0108 == nil) goto v0238;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    if (is_number(v0108)) goto v0070;
    v0108 = stack[-1];
    v0109 = qcar(v0108);
    v0108 = elt(env, 1); /* (nil t) */
    v0108 = Lmemq(nil, v0109, v0108);
    if (!(v0108 == nil)) goto v0070;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    if (!consp(v0108)) goto v0072;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0109 = qcar(v0108);
    v0108 = elt(env, 3); /* quote */
    if (v0109 == v0108) goto v0069;
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0109 = qcar(v0108);
    v0108 = elt(env, 4); /* list */
    if (v0109 == v0108) goto v0105;
    v0108 = qvalue(elt(env, 2)); /* nil */
    goto v0048;

v0048:
    if (v0108 == nil) goto v0103;
    v0109 = stack[0];
    v0108 = stack[-2];
    v0108 = cons(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    stack[-2] = v0108;
    goto v0099;

v0099:
    v0108 = stack[-1];
    v0108 = qcdr(v0108);
    stack[-1] = v0108;
    goto v0203;

v0103:
    v0108 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0108); }

v0105:
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0108 = CC_requote1(env, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    stack[0] = v0108;
    goto v0048;

v0069:
    v0108 = stack[-1];
    v0108 = qcar(v0108);
    v0108 = qcdr(v0108);
    v0109 = qcar(v0108);
    v0108 = stack[-2];
    v0108 = cons(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    stack[-2] = v0108;
    goto v0099;

v0072:
    v0108 = qvalue(elt(env, 2)); /* nil */
    { popv(4); return onevalue(v0108); }

v0070:
    v0108 = stack[-1];
    v0109 = qcar(v0108);
    v0108 = stack[-2];
    v0108 = cons(v0109, v0108);
    nil = C_nil;
    if (exception_pending()) goto v0027;
    env = stack[-3];
    stack[-2] = v0108;
    goto v0099;

v0238:
    v0108 = stack[-2];
        popv(4);
        return Lnreverse(nil, v0108);
/* error exit handlers */
v0027:
    popv(4);
    return nil;
}



/* Code for actual_world */

static Lisp_Object CC_actual_world(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0093, v0091, v0092;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for actual_world");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0091 = v0001;
    v0092 = v0000;
/* end of prologue */
    v0093 = v0092;
    stack[0] = qcar(v0093);
    v0093 = v0091;
    v0091 = v0092;
    v0091 = qcdr(v0091);
    fn = elt(env, 1); /* exclude_edges */
    v0093 = (*qfn2(fn))(qenv(fn), v0093, v0091);
    nil = C_nil;
    if (exception_pending()) goto v0115;
    env = stack[-1];
    {
        Lisp_Object v0110 = stack[0];
        popv(2);
        fn = elt(env, 2); /* union_edges */
        return (*qfn2(fn))(qenv(fn), v0110, v0093);
    }
/* error exit handlers */
v0115:
    popv(2);
    return nil;
}



/* Code for split!-wrt!-variables */

static Lisp_Object MS_CDECL CC_splitKwrtKvariables(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0103, v0065, v0064;
    Lisp_Object v0086, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "split-wrt-variables");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0086 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for split-wrt-variables");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0086,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0086);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0086;
    stack[-1] = v0001;
    v0065 = v0000;
/* end of prologue */

v0090:
    v0103 = v0065;
    if (v0103 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0103 = stack[0];
    if (v0103 == nil) goto v0070;
    v0103 = stack[0];
    v0064 = qcar(v0103);
    v0103 = (Lisp_Object)17; /* 1 */
    v0103 = (v0064 == v0103 ? lisp_true : nil);
    goto v0039;

v0039:
    if (!(v0103 == nil)) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0103 = v0065;
    if (!consp(v0103)) goto v0072;
    v0103 = v0065;
    v0103 = qcar(v0103);
    v0103 = (consp(v0103) ? nil : lisp_true);
    goto v0153;

v0153:
    if (v0103 == nil) goto v0230;
    v0103 = v0065;
    v0065 = Labsval(nil, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    v0103 = stack[0];
    popv(4);
    return cons(v0065, v0103);

v0230:
    v0103 = v0065;
    v0103 = qcar(v0103);
    v0103 = qcar(v0103);
    v0064 = qcar(v0103);
    v0103 = stack[-1];
    v0103 = Lmember(nil, v0064, v0103);
    if (v0103 == nil) goto v0122;
    v0103 = v0065;
    v0103 = qcdr(v0103);
    stack[-2] = v0103;
    v0103 = v0065;
    v0103 = qcar(v0103);
    v0064 = qcdr(v0103);
    v0065 = stack[-1];
    v0103 = stack[0];
    v0103 = CC_splitKwrtKvariables(env, 3, v0064, v0065, v0103);
    nil = C_nil;
    if (exception_pending()) goto v0109;
    env = stack[-3];
    stack[0] = v0103;
    v0103 = stack[-2];
    v0065 = v0103;
    goto v0090;

v0122:
    v0103 = stack[0];
    popv(4);
    return cons(v0065, v0103);

v0072:
    v0103 = qvalue(elt(env, 2)); /* t */
    goto v0153;

v0070:
    v0103 = qvalue(elt(env, 1)); /* nil */
    goto v0039;
/* error exit handlers */
v0109:
    popv(4);
    return nil;
}



/* Code for inormmat */

static Lisp_Object CC_inormmat(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0276, v0277;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inormmat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    v0276 = v0000;
/* end of prologue */
    stack[-6] = nil;
    stack[-5] = v0276;
    goto v0074;

v0074:
    v0276 = stack[-5];
    if (v0276 == nil) goto v0238;
    v0276 = stack[-5];
    v0276 = qcar(v0276);
    stack[-1] = v0276;
    v0276 = (Lisp_Object)17; /* 1 */
    stack[-7] = v0276;
    v0276 = stack[-1];
    stack[0] = v0276;
    goto v0110;

v0110:
    v0276 = stack[0];
    if (v0276 == nil) goto v0215;
    v0276 = stack[0];
    v0276 = qcar(v0276);
    v0277 = stack[-7];
    v0276 = qcdr(v0276);
    fn = elt(env, 2); /* ilcm */
    v0276 = (*qfn2(fn))(qenv(fn), v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-8];
    stack[-7] = v0276;
    v0276 = stack[0];
    v0276 = qcdr(v0276);
    stack[0] = v0276;
    goto v0110;

v0215:
    v0276 = stack[-1];
    stack[-4] = v0276;
    v0276 = stack[-4];
    if (v0276 == nil) goto v0006;
    v0276 = stack[-4];
    v0276 = qcar(v0276);
    v0277 = v0276;
    stack[0] = qcar(v0277);
    v0277 = stack[-7];
    v0276 = qcdr(v0276);
    v0276 = quot2(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-8];
    v0276 = times2(stack[0], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-8];
    v0276 = ncons(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-8];
    stack[-2] = v0276;
    stack[-3] = v0276;
    goto v0230;

v0230:
    v0276 = stack[-4];
    v0276 = qcdr(v0276);
    stack[-4] = v0276;
    v0276 = stack[-4];
    if (v0276 == nil) goto v0029;
    stack[-1] = stack[-2];
    v0276 = stack[-4];
    v0276 = qcar(v0276);
    v0277 = v0276;
    stack[0] = qcar(v0277);
    v0277 = stack[-7];
    v0276 = qcdr(v0276);
    v0276 = quot2(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-8];
    v0276 = times2(stack[0], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-8];
    v0276 = ncons(v0276);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-8];
    v0276 = Lrplacd(nil, stack[-1], v0276);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-8];
    v0276 = stack[-2];
    v0276 = qcdr(v0276);
    stack[-2] = v0276;
    goto v0230;

v0029:
    v0276 = stack[-3];
    v0277 = v0276;
    goto v0229;

v0229:
    v0276 = stack[-6];
    v0276 = cons(v0277, v0276);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-8];
    stack[-6] = v0276;
    v0276 = stack[-5];
    v0276 = qcdr(v0276);
    stack[-5] = v0276;
    goto v0074;

v0006:
    v0276 = qvalue(elt(env, 1)); /* nil */
    v0277 = v0276;
    goto v0229;

v0238:
    v0276 = stack[-6];
        popv(9);
        return Lreverse(nil, v0276);
/* error exit handlers */
v0060:
    popv(9);
    return nil;
}



/* Code for modroots1 */

static Lisp_Object CC_modroots1(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0134, v0293, v0135;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modroots1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-10] = v0000;
/* end of prologue */
    v0134 = stack[-1];
    v0134 = qcdr(v0134);
    if (v0134 == nil) goto v0074;
    stack[-7] = nil;
    v0134 = stack[-1];
    v0134 = qcar(v0134);
    stack[-11] = v0134;
    v0134 = stack[-1];
    v0134 = qcdr(v0134);
    stack[-1] = v0134;
    v0293 = stack[-10];
    v0134 = stack[-1];
    v0134 = CC_modroots1(env, v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    stack[0] = v0134;
    v0134 = stack[0];
    if (v0134 == nil) goto v0036;
    v0134 = stack[-10];
    v0134 = qcar(v0134);
    v0134 = qcar(v0134);
    v0134 = qcar(v0134);
    stack[-6] = v0134;
    v0134 = elt(env, 2); /* g */
    v0134 = Lgensym1(nil, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    stack[-5] = v0134;
    v0134 = stack[-1];
    stack[-1] = v0134;
    v0134 = (Lisp_Object)17; /* 1 */
    v0293 = v0134;
    goto v0019;

v0019:
    v0134 = stack[-1];
    if (v0134 == nil) goto v0231;
    v0134 = stack[-1];
    v0134 = qcar(v0134);
    v0134 = times2(v0134, v0293);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    v0293 = v0134;
    v0134 = stack[-1];
    v0134 = qcdr(v0134);
    stack[-1] = v0134;
    goto v0019;

v0231:
    v0134 = v0293;
    stack[-9] = v0134;
    v0293 = stack[-11];
    v0134 = stack[-9];
    v0134 = times2(v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    stack[-8] = v0134;
    v0134 = stack[0];
    stack[-4] = v0134;
    goto v0273;

v0273:
    v0134 = stack[-4];
    if (v0134 == nil) { Lisp_Object res = stack[-7]; popv(13); return onevalue(res); }
    v0134 = stack[-4];
    v0134 = qcar(v0134);
    stack[-3] = v0134;
    stack[-2] = stack[-10];
    stack[-1] = stack[-6];
    stack[0] = elt(env, 3); /* plus */
    v0135 = elt(env, 4); /* times */
    v0293 = stack[-5];
    v0134 = stack[-9];
    v0293 = list3(v0135, v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    v0134 = stack[-3];
    v0134 = list2(v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    v0134 = list2star(stack[-1], stack[0], v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    v0134 = ncons(v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    fn = elt(env, 6); /* subf */
    v0134 = (*qfn2(fn))(qenv(fn), stack[-2], v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    v0134 = qcar(v0134);
    v0293 = v0134;
    v0134 = stack[-11];
    fn = elt(env, 7); /* reduce!-mod!-p!* */
    v0135 = (*qfn2(fn))(qenv(fn), v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    v0293 = stack[-11];
    v0134 = qvalue(elt(env, 5)); /* t */
    fn = elt(env, 8); /* modroots2 */
    v0134 = (*qfnn(fn))(qenv(fn), 3, v0135, v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    stack[-2] = v0134;
    goto v0209;

v0209:
    v0134 = stack[-2];
    if (v0134 == nil) goto v0294;
    v0134 = stack[-2];
    v0134 = qcar(v0134);
    stack[-1] = v0134;
    v0293 = stack[-1];
    v0134 = stack[-9];
    v0293 = times2(v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    v0134 = stack[-3];
    v0293 = plus2(v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    v0134 = stack[-8];
    fn = elt(env, 9); /* modp */
    v0134 = (*qfn2(fn))(qenv(fn), v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    stack[-1] = v0134;
    stack[0] = stack[-10];
    v0293 = stack[-6];
    v0134 = stack[-1];
    v0134 = cons(v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    v0134 = ncons(v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    fn = elt(env, 6); /* subf */
    v0134 = (*qfn2(fn))(qenv(fn), stack[0], v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    v0293 = qcar(v0134);
    v0134 = stack[-8];
    fn = elt(env, 7); /* reduce!-mod!-p!* */
    v0134 = (*qfn2(fn))(qenv(fn), v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    if (v0134 == nil) goto v0204;
    v0134 = qvalue(elt(env, 1)); /* nil */
    goto v0044;

v0044:
    if (v0134 == nil) goto v0197;
    v0293 = stack[-1];
    v0134 = stack[-7];
    v0134 = cons(v0293, v0134);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-12];
    stack[-7] = v0134;
    goto v0197;

v0197:
    v0134 = stack[-2];
    v0134 = qcdr(v0134);
    stack[-2] = v0134;
    goto v0209;

v0204:
    v0293 = stack[-1];
    v0134 = stack[-7];
    v0134 = Lmember(nil, v0293, v0134);
    v0134 = (v0134 == nil ? lisp_true : nil);
    goto v0044;

v0294:
    v0134 = stack[-4];
    v0134 = qcdr(v0134);
    stack[-4] = v0134;
    goto v0273;

v0036:
    v0134 = qvalue(elt(env, 1)); /* nil */
    { popv(13); return onevalue(v0134); }

v0074:
    v0135 = stack[-10];
    v0134 = stack[-1];
    v0293 = qcar(v0134);
    v0134 = qvalue(elt(env, 1)); /* nil */
    {
        popv(13);
        fn = elt(env, 8); /* modroots2 */
        return (*qfnn(fn))(qenv(fn), 3, v0135, v0293, v0134);
    }
/* error exit handlers */
v0167:
    popv(13);
    return nil;
}



/* Code for simpsqrt */

static Lisp_Object CC_simpsqrt(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0298, v0265, v0289;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpsqrt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    v0289 = v0000;
/* end of prologue */
    v0265 = v0289;
    v0298 = (Lisp_Object)1; /* 0 */
    if (v0265 == v0298) goto v0083;
    v0298 = qvalue(elt(env, 2)); /* !*keepsqrts */
    if (v0298 == nil) goto v0110;
    v0298 = v0289;
    v0298 = qcar(v0298);
    fn = elt(env, 7); /* xsimp */
    v0298 = (*qfn1(fn))(qenv(fn), v0298);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    stack[-1] = v0298;
    v0298 = stack[-1];
    v0298 = qcar(v0298);
    if (v0298 == nil) goto v0224;
    v0298 = stack[-1];
    v0265 = qcdr(v0298);
    v0298 = (Lisp_Object)17; /* 1 */
    if (v0265 == v0298) goto v0007;
    v0298 = qvalue(elt(env, 1)); /* nil */
    goto v0010;

v0010:
    if (v0298 == nil) goto v0299;
    v0298 = stack[-1];
    v0265 = qcar(v0298);
    v0298 = (Lisp_Object)-15; /* -1 */
    if (v0265 == v0298) goto v0275;
    v0298 = elt(env, 5); /* i */
    fn = elt(env, 8); /* simp */
    stack[0] = (*qfn1(fn))(qenv(fn), v0298);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0298 = stack[-1];
    v0298 = qcar(v0298);
    fn = elt(env, 9); /* !:minus */
    v0298 = (*qfn1(fn))(qenv(fn), v0298);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    fn = elt(env, 10); /* prepd */
    v0298 = (*qfn1(fn))(qenv(fn), v0298);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0298 = ncons(v0298);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0298 = CC_simpsqrt(env, v0298);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    {
        Lisp_Object v0256 = stack[0];
        popv(3);
        fn = elt(env, 11); /* multsq */
        return (*qfn2(fn))(qenv(fn), v0256, v0298);
    }

v0275:
    v0298 = elt(env, 5); /* i */
    {
        popv(3);
        fn = elt(env, 8); /* simp */
        return (*qfn1(fn))(qenv(fn), v0298);
    }

v0299:
    stack[0] = elt(env, 6); /* sqrt */
    v0298 = stack[-1];
    v0298 = ncons(v0298);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    fn = elt(env, 12); /* domainvalchk */
    v0298 = (*qfn2(fn))(qenv(fn), stack[0], v0298);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0265 = v0298;
    if (!(v0298 == nil)) { popv(3); return onevalue(v0265); }
    v0265 = stack[-1];
    v0298 = (Lisp_Object)33; /* 2 */
    {
        popv(3);
        fn = elt(env, 13); /* simprad */
        return (*qfn2(fn))(qenv(fn), v0265, v0298);
    }

v0007:
    v0298 = stack[-1];
    v0298 = qcar(v0298);
    if (!consp(v0298)) goto v0213;
    v0298 = stack[-1];
    v0298 = qcar(v0298);
    v0298 = qcar(v0298);
    v0298 = (consp(v0298) ? nil : lisp_true);
    goto v0214;

v0214:
    if (v0298 == nil) goto v0273;
    v0298 = stack[-1];
    v0298 = qcar(v0298);
    fn = elt(env, 14); /* !:minusp */
    v0298 = (*qfn1(fn))(qenv(fn), v0298);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    goto v0010;

v0273:
    v0298 = qvalue(elt(env, 1)); /* nil */
    goto v0010;

v0213:
    v0298 = qvalue(elt(env, 4)); /* t */
    goto v0214;

v0224:
    v0265 = qvalue(elt(env, 1)); /* nil */
    v0298 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0265, v0298);

v0110:
    v0298 = v0289;
    stack[0] = qcar(v0298);
    v0298 = elt(env, 3); /* (quotient 1 2) */
    fn = elt(env, 15); /* simpexpon */
    v0265 = (*qfn1(fn))(qenv(fn), v0298);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-2];
    v0298 = qvalue(elt(env, 1)); /* nil */
    {
        Lisp_Object v0145 = stack[0];
        popv(3);
        fn = elt(env, 16); /* simpexpt1 */
        return (*qfnn(fn))(qenv(fn), 3, v0145, v0265, v0298);
    }

v0083:
    v0265 = qvalue(elt(env, 1)); /* nil */
    v0298 = (Lisp_Object)17; /* 1 */
    popv(3);
    return cons(v0265, v0298);
/* error exit handlers */
v0054:
    popv(3);
    return nil;
}



/* Code for cl_gaussintersection */

static Lisp_Object CC_cl_gaussintersection(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0121, v0122;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_gaussintersection");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0121 = stack[-1];
    v0122 = qcar(v0121);
    v0121 = elt(env, 1); /* gignore */
    if (v0122 == v0121) goto v0239;
    v0121 = qvalue(elt(env, 2)); /* nil */
    goto v0099;

v0099:
    if (v0121 == nil) goto v0069;
    v0121 = stack[-1];
    v0121 = qcdr(v0121);
    v0121 = qcdr(v0121);
    stack[-2] = Llength(nil, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-3];
    v0121 = stack[0];
    v0121 = qcdr(v0121);
    v0121 = qcdr(v0121);
    v0121 = Llength(nil, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    env = stack[-3];
    v0121 = (Lisp_Object)lessp2(stack[-2], v0121);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    v0121 = v0121 ? lisp_true : nil;
    if (v0121 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0069:
    v0121 = stack[-1];
    v0122 = qcar(v0121);
    v0121 = elt(env, 1); /* gignore */
    if (v0122 == v0121) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    v0121 = stack[0];
    v0122 = qcar(v0121);
    v0121 = elt(env, 1); /* gignore */
    if (v0122 == v0121) { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }
    v0122 = stack[-1];
    v0121 = stack[0];
    fn = elt(env, 3); /* rl_bettergaussp */
    v0121 = (*qfn2(fn))(qenv(fn), v0122, v0121);
    nil = C_nil;
    if (exception_pending()) goto v0273;
    if (v0121 == nil) { Lisp_Object res = stack[0]; popv(4); return onevalue(res); }
    else { Lisp_Object res = stack[-1]; popv(4); return onevalue(res); }

v0239:
    v0121 = stack[0];
    v0122 = qcar(v0121);
    v0121 = elt(env, 1); /* gignore */
    v0121 = (v0122 == v0121 ? lisp_true : nil);
    goto v0099;
/* error exit handlers */
v0273:
    popv(4);
    return nil;
}



/* Code for ofsf_simplneq */

static Lisp_Object CC_ofsf_simplneq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0030, v0272, v0273;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ofsf_simplneq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0030 = stack[-2];
    fn = elt(env, 8); /* ofsf_posdefp */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    stack[-3] = v0030;
    v0272 = stack[-3];
    v0030 = elt(env, 1); /* stsq */
    if (v0272 == v0030) goto v0076;
    v0030 = stack[-2];
    fn = elt(env, 9); /* sfto_sqfpartf */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    stack[0] = v0030;
    v0030 = stack[0];
    fn = elt(env, 8); /* ofsf_posdefp */
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    v0273 = v0030;
    v0272 = v0273;
    v0030 = elt(env, 1); /* stsq */
    if (v0272 == v0030) goto v0043;
    v0030 = qvalue(elt(env, 3)); /* !*rlsitsqspl */
    if (v0030 == nil) goto v0102;
    v0030 = qvalue(elt(env, 4)); /* !*rlsiexpla */
    if (!(v0030 == nil)) goto v0006;
    v0030 = qvalue(elt(env, 5)); /* !*rlsiexpl */
    if (v0030 == nil) goto v0102;
    v0272 = stack[-1];
    v0030 = elt(env, 6); /* or */
    if (!(v0272 == v0030)) goto v0102;

v0006:
    v0272 = v0273;
    v0030 = elt(env, 7); /* tsq */
    if (v0272 == v0030) goto v0026;
    v0272 = stack[-3];
    v0030 = elt(env, 7); /* tsq */
    if (!(v0272 == v0030)) goto v0102;
    v0030 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_tsqsplneq */
        return (*qfn1(fn))(qenv(fn), v0030);
    }

v0102:
    v0272 = stack[0];
    v0030 = stack[-1];
    {
        popv(5);
        fn = elt(env, 11); /* ofsf_facneq!* */
        return (*qfn2(fn))(qenv(fn), v0272, v0030);
    }

v0026:
    v0030 = stack[0];
    {
        popv(5);
        fn = elt(env, 10); /* ofsf_tsqsplneq */
        return (*qfn1(fn))(qenv(fn), v0030);
    }

v0043:
    v0030 = elt(env, 2); /* true */
    { popv(5); return onevalue(v0030); }

v0076:
    v0030 = elt(env, 2); /* true */
    { popv(5); return onevalue(v0030); }
/* error exit handlers */
v0022:
    popv(5);
    return nil;
}



/* Code for let0 */

static Lisp_Object CC_let0(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0203, v0090;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for let0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0090 = v0000;
/* end of prologue */
    v0203 = qvalue(elt(env, 1)); /* nil */
    stack[0] = qvalue(elt(env, 2)); /* frasc!* */
    qvalue(elt(env, 2)) = v0203; /* frasc!* */
    v0203 = v0090;
    fn = elt(env, 3); /* let00 */
    v0203 = (*qfn1(fn))(qenv(fn), v0203);
    nil = C_nil;
    if (exception_pending()) goto v0238;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* frasc!* */
    { popv(2); return onevalue(v0203); }
/* error exit handlers */
v0238:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; /* frasc!* */
    popv(2);
    return nil;
}



/* Code for rl_atl */

static Lisp_Object CC_rl_atl(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0077;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_atl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push(nil);
/* copy arguments values to proper place */
    v0077 = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* rl_atl!* */
    v0077 = ncons(v0077);
    nil = C_nil;
    if (exception_pending()) goto v0082;
    env = stack[-1];
    {
        Lisp_Object v0083 = stack[0];
        popv(2);
        fn = elt(env, 2); /* apply */
        return (*qfn2(fn))(qenv(fn), v0083, v0077);
    }
/* error exit handlers */
v0082:
    popv(2);
    return nil;
}



/* Code for evalgeq */

static Lisp_Object CC_evalgeq(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0076, v0082;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalgeq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0076 = v0001;
    v0082 = v0000;
/* end of prologue */
    fn = elt(env, 1); /* evallessp */
    v0076 = (*qfn2(fn))(qenv(fn), v0082, v0076);
    errexit();
    v0076 = (v0076 == nil ? lisp_true : nil);
    return onevalue(v0076);
}



/* Code for tstpolyarg */

static Lisp_Object CC_tstpolyarg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0096, v0040, v0041;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tstpolyarg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* copy arguments values to proper place */
    v0041 = v0001;
    v0040 = v0000;
/* end of prologue */
    v0096 = qvalue(elt(env, 1)); /* !*ratarg */
    if (v0096 == nil) goto v0083;
    v0096 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v0096); }

v0083:
    v0096 = (Lisp_Object)17; /* 1 */
    if (v0040 == v0096) goto v0043;
    v0096 = v0041;
    fn = elt(env, 4); /* prepsq */
    v0040 = (*qfn1(fn))(qenv(fn), v0096);
    nil = C_nil;
    if (exception_pending()) goto v0153;
    env = stack[0];
    v0096 = elt(env, 2); /* "polynomial" */
    {
        popv(1);
        fn = elt(env, 5); /* typerr */
        return (*qfn2(fn))(qenv(fn), v0040, v0096);
    }

v0043:
    v0096 = qvalue(elt(env, 3)); /* nil */
    { popv(1); return onevalue(v0096); }
/* error exit handlers */
v0153:
    popv(1);
    return nil;
}



/* Code for lchk */

static Lisp_Object CC_lchk(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0010, v0007;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push2(nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0000;
/* end of prologue */
    v0010 = stack[0];
    if (v0010 == nil) goto v0076;
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0010 = (consp(v0010) ? nil : lisp_true);
    goto v0077;

v0077:
    if (v0010 == nil) goto v0090;
    v0010 = qvalue(elt(env, 2)); /* nil */
    { popv(3); return onevalue(v0010); }

v0090:
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0010 = Llength(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-2];
    stack[-1] = v0010;
    goto v0042;

v0042:
    v0010 = stack[0];
    v0010 = qcdr(v0010);
    stack[0] = v0010;
    v0010 = stack[0];
    if (v0010 == nil) goto v0041;
    v0010 = stack[0];
    v0010 = qcar(v0010);
    if (!consp(v0010)) goto v0088;
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0007 = Llength(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-2];
    v0010 = stack[-1];
    v0010 = Lneq(nil, v0007, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0068;
    env = stack[-2];
    goto v0040;

v0040:
    if (v0010 == nil) goto v0042;
    v0010 = stack[0];
    v0010 = (v0010 == nil ? lisp_true : nil);
    { popv(3); return onevalue(v0010); }

v0088:
    v0010 = qvalue(elt(env, 1)); /* t */
    goto v0040;

v0041:
    v0010 = qvalue(elt(env, 1)); /* t */
    goto v0040;

v0076:
    v0010 = qvalue(elt(env, 1)); /* t */
    goto v0077;
/* error exit handlers */
v0068:
    popv(3);
    return nil;
}



/* Code for exdfpf */

static Lisp_Object CC_exdfpf(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0027, v0080, v0028;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exdfpf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push(v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop(v0000);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-2] = v0000;
/* end of prologue */
    stack[-3] = nil;
    goto v0203;

v0203:
    v0027 = stack[-2];
    if (v0027 == nil) goto v0090;
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0080 = qcar(v0027);
    v0027 = (Lisp_Object)17; /* 1 */
    if (v0080 == v0027) goto v0092;
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0027 = qcar(v0027);
    fn = elt(env, 2); /* exdfk */
    v0080 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0027 = qcdr(v0027);
    fn = elt(env, 3); /* multpfsq */
    stack[-1] = (*qfn2(fn))(qenv(fn), v0080, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0027 = qcdr(v0027);
    fn = elt(env, 4); /* exdf0 */
    stack[0] = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0027 = qcar(v0027);
    v0028 = ncons(v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    v0080 = (Lisp_Object)17; /* 1 */
    v0027 = (Lisp_Object)17; /* 1 */
    v0027 = list2star(v0028, v0080, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    v0027 = ncons(v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    fn = elt(env, 5); /* wedgepf2 */
    v0027 = (*qfn2(fn))(qenv(fn), stack[0], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    fn = elt(env, 6); /* mkuniquewedge */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    fn = elt(env, 7); /* addpf */
    v0027 = (*qfn2(fn))(qenv(fn), stack[-1], v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    v0080 = v0027;
    goto v0039;

v0039:
    v0027 = stack[-3];
    v0027 = cons(v0080, v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    stack[-3] = v0027;
    v0027 = stack[-2];
    v0027 = qcdr(v0027);
    stack[-2] = v0027;
    goto v0203;

v0092:
    v0027 = stack[-2];
    v0027 = qcar(v0027);
    v0027 = qcdr(v0027);
    fn = elt(env, 4); /* exdf0 */
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    v0080 = v0027;
    goto v0039;

v0090:
    v0027 = qvalue(elt(env, 1)); /* nil */
    v0080 = v0027;
    goto v0099;

v0099:
    v0027 = stack[-3];
    if (v0027 == nil) { popv(5); return onevalue(v0080); }
    v0027 = stack[-3];
    v0027 = qcar(v0027);
    fn = elt(env, 7); /* addpf */
    v0027 = (*qfn2(fn))(qenv(fn), v0027, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0291;
    env = stack[-4];
    v0080 = v0027;
    v0027 = stack[-3];
    v0027 = qcdr(v0027);
    stack[-3] = v0027;
    goto v0099;
/* error exit handlers */
v0291:
    popv(5);
    return nil;
}



/* Code for lispstmtp */

static Lisp_Object CC_lispstmtp(Lisp_Object env,
                         Lisp_Object v0000)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0234, v0212, v0214;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lispstmtp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    CSL_IGNORE(env);
/* copy arguments values to proper place */
    v0214 = v0000;
/* end of prologue */
    v0234 = v0214;
    if (!consp(v0234)) goto v0087;
    v0234 = v0214;
    v0212 = qcar(v0234);
    v0234 = qvalue(elt(env, 2)); /* !*lispstmtops!* */
    v0234 = Lmemq(nil, v0212, v0234);
    if (!(v0234 == nil)) return onevalue(v0234);
    v0234 = v0214;
    v0234 = qcar(v0234);
    if (!consp(v0234)) goto v0071;
    v0234 = qvalue(elt(env, 7)); /* nil */
    return onevalue(v0234);

v0071:
    v0234 = v0214;
    v0212 = qcar(v0234);
    v0234 = qvalue(elt(env, 3)); /* !*lisparithexpops!* */
    v0234 = Lmemq(nil, v0212, v0234);
    if (!(v0234 == nil)) goto v0046;
    v0234 = v0214;
    v0212 = qcar(v0234);
    v0234 = qvalue(elt(env, 4)); /* !*lisplogexpops!* */
    v0234 = Lmemq(nil, v0212, v0234);
    if (!(v0234 == nil)) goto v0046;
    v0234 = v0214;
    v0212 = qcar(v0234);
    v0234 = qvalue(elt(env, 5)); /* !*lispstmtgpops!* */
    v0234 = Lmemq(nil, v0212, v0234);
    if (!(v0234 == nil)) goto v0046;
    v0234 = v0214;
    v0234 = qcar(v0234);
    v0212 = qvalue(elt(env, 6)); /* !*lispdefops!* */
    v0234 = Lmemq(nil, v0234, v0212);
    goto v0046;

v0046:
    v0234 = (v0234 == nil ? lisp_true : nil);
    return onevalue(v0234);

v0087:
    v0234 = qvalue(elt(env, 1)); /* t */
    return onevalue(v0234);
}



/* Code for gi */

static Lisp_Object CC_gi(Lisp_Object env,
                         Lisp_Object v0001, Lisp_Object v0086)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0089, v0229;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gi");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0086,v0001);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0001,v0086);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-3] = v0086;
    v0089 = v0001;
/* end of prologue */
    stack[-4] = qvalue(elt(env, 1)); /* gg!* */
    qvalue(elt(env, 1)) = nil; /* gg!* */
    qvalue(elt(env, 1)) = v0089; /* gg!* */
    stack[-2] = nil;
    v0089 = qvalue(elt(env, 1)); /* gg!* */
    stack[-1] = v0089;
    goto v0083;

v0083:
    v0089 = stack[-1];
    if (v0089 == nil) goto v0082;
    v0089 = stack[-1];
    v0089 = qcar(v0089);
    stack[0] = v0089;
    v0089 = stack[0];
    v0089 = qcdr(v0089);
    fn = elt(env, 3); /* class */
    v0229 = (*qfn1(fn))(qenv(fn), v0089);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-5];
    v0089 = stack[-3];
    if (!(equal(v0229, v0089))) goto v0183;
    v0229 = stack[0];
    v0089 = stack[-2];
    v0089 = cons(v0229, v0089);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-5];
    stack[-2] = v0089;
    goto v0183;

v0183:
    v0089 = stack[-1];
    v0089 = qcdr(v0089);
    stack[-1] = v0089;
    goto v0083;

v0082:
    v0089 = stack[-2];
    qvalue(elt(env, 1)) = stack[-4]; /* gg!* */
    { popv(6); return onevalue(v0089); }
/* error exit handlers */
v0038:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[-4]; /* gg!* */
    popv(6);
    return nil;
}



/* Code for deg */

static Lisp_Object CC_deg(Lisp_Object env,
                         Lisp_Object v0000, Lisp_Object v0001)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0115, v0110;
    Lisp_Object fn;
    CSL_IGNORE(nil);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for deg");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0001);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push3(nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0001;
    stack[-1] = v0000;
/* end of prologue */
    v0115 = qvalue(elt(env, 1)); /* gdmode!* */
    stack[-2] = qvalue(elt(env, 2)); /* dmode!* */
    qvalue(elt(env, 2)) = v0115; /* dmode!* */
    v0115 = stack[-1];
    fn = elt(env, 3); /* simp!* */
    v0115 = (*qfn1(fn))(qenv(fn), v0115);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    stack[-1] = v0115;
    v0110 = stack[-1];
    v0115 = stack[0];
    fn = elt(env, 4); /* tstpolyarg2 */
    v0115 = (*qfn2(fn))(qenv(fn), v0110, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    v0115 = stack[-1];
    v0110 = qcar(v0115);
    v0115 = stack[0];
    fn = elt(env, 5); /* numrdeg */
    v0115 = (*qfn2(fn))(qenv(fn), v0110, v0115);
    nil = C_nil;
    if (exception_pending()) goto v0046;
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    { popv(4); return onevalue(v0115); }
/* error exit handlers */
v0046:
    env = stack[-3];
    qvalue(elt(env, 2)) = stack[-2]; /* dmode!* */
    popv(4);
    return nil;
}



/* Code for count!-linear!-factors!-mod!-p */

static Lisp_Object MS_CDECL CC_countKlinearKfactorsKmodKp(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0316, v0317, v0123, v0124, v0184;
    Lisp_Object fn;
    Lisp_Object v0086, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "count-linear-factors-mod-p");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0086 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for count-linear-factors-mod-p");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0086,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0086);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[-1] = v0086;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[0] = qvalue(elt(env, 1)); /* linear!-factors */
    qvalue(elt(env, 1)) = nil; /* linear!-factors */
    v0316 = (Lisp_Object)1; /* 0 */
    v0184 = v0316;
    goto v0047;

v0047:
    v0317 = qvalue(elt(env, 2)); /* dpoly */
    v0316 = v0184;
    v0316 = (Lisp_Object)(int32_t)((int32_t)v0317 - (int32_t)v0316 + TAG_FIXNUM);
    v0316 = ((intptr_t)(v0316) < 0 ? lisp_true : nil);
    if (v0316 == nil) goto v0043;
    v0123 = qvalue(elt(env, 5)); /* current!-modulus */
    v0317 = stack[-3];
    v0316 = stack[-1];
    fn = elt(env, 6); /* make!-x!-to!-p */
    v0316 = (*qfnn(fn))(qenv(fn), 3, v0123, v0317, v0316);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-5];
    stack[-4] = v0316;
    v0316 = (Lisp_Object)1; /* 0 */
    v0184 = v0316;
    goto v0068;

v0068:
    v0317 = stack[-4];
    v0316 = v0184;
    v0316 = (Lisp_Object)(int32_t)((int32_t)v0317 - (int32_t)v0316 + TAG_FIXNUM);
    v0316 = ((intptr_t)(v0316) < 0 ? lisp_true : nil);
    if (v0316 == nil) goto v0234;
    v0317 = stack[-4];
    v0316 = (Lisp_Object)17; /* 1 */
    if (((int32_t)(v0317)) < ((int32_t)(v0316))) goto v0290;
    v0124 = stack[-3];
    v0123 = (Lisp_Object)17; /* 1 */
    v0317 = stack[-3];
    v0316 = (Lisp_Object)17; /* 1 */
    v0317 = *(Lisp_Object *)((char *)v0317 + (CELL-TAG_VECTOR) + ((int32_t)v0316/(16/CELL)));
    v0316 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v0317) - int_of_fixnum(v0316);
        if (w < 0) w += current_modulus;
        v0316 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0124 + (CELL-TAG_VECTOR) + ((int32_t)v0123/(16/CELL))) = v0316;
    v0317 = stack[-4];
    v0316 = (Lisp_Object)17; /* 1 */
    if (v0317 == v0316) goto v0319;
    v0316 = qvalue(elt(env, 3)); /* nil */
    goto v0142;

v0142:
    if (v0316 == nil) goto v0137;
    v0317 = stack[-3];
    v0316 = (Lisp_Object)1; /* 0 */
    v0317 = *(Lisp_Object *)((char *)v0317 + (CELL-TAG_VECTOR) + ((int32_t)v0316/(16/CELL)));
    v0316 = (Lisp_Object)1; /* 0 */
    if (v0317 == v0316) goto v0045;
    v0316 = (Lisp_Object)1; /* 0 */
    stack[-4] = v0316;
    goto v0137;

v0137:
    v0317 = stack[-4];
    v0316 = (Lisp_Object)1; /* 0 */
    if (((int32_t)(v0317)) < ((int32_t)(v0316))) goto v0280;
    v0124 = stack[-3];
    v0123 = stack[-4];
    v0317 = stack[-2];
    v0316 = qvalue(elt(env, 2)); /* dpoly */
    fn = elt(env, 7); /* gcd!-in!-vector */
    v0316 = (*qfnn(fn))(qenv(fn), 4, v0124, v0123, v0317, v0316);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-5];
    stack[-1] = v0316;
    goto v0320;

v0320:
    v0316 = stack[-1];
    v0316 = Lmkvect(nil, v0316);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-5];
    qvalue(elt(env, 1)) = v0316; /* linear!-factors */
    v0316 = (Lisp_Object)1; /* 0 */
    v0184 = v0316;
    goto v0243;

v0243:
    v0317 = stack[-1];
    v0316 = v0184;
    v0316 = (Lisp_Object)(int32_t)((int32_t)v0317 - (int32_t)v0316 + TAG_FIXNUM);
    v0316 = ((intptr_t)(v0316) < 0 ? lisp_true : nil);
    if (v0316 == nil) goto v0221;
    v0124 = qvalue(elt(env, 4)); /* poly!-vector */
    v0123 = qvalue(elt(env, 2)); /* dpoly */
    v0317 = qvalue(elt(env, 1)); /* linear!-factors */
    v0316 = stack[-1];
    fn = elt(env, 8); /* quotfail!-in!-vector */
    v0316 = (*qfnn(fn))(qenv(fn), 4, v0124, v0123, v0317, v0316);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-5];
    qvalue(elt(env, 2)) = v0316; /* dpoly */
    v0123 = stack[-1];
    v0317 = qvalue(elt(env, 1)); /* linear!-factors */
    v0316 = stack[-4];
    v0316 = list3(v0123, v0317, v0316);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[0]; /* linear!-factors */
    { popv(6); return onevalue(v0316); }

v0221:
    v0124 = qvalue(elt(env, 1)); /* linear!-factors */
    v0123 = v0184;
    v0317 = stack[-3];
    v0316 = v0184;
    v0316 = *(Lisp_Object *)((char *)v0317 + (CELL-TAG_VECTOR) + ((int32_t)v0316/(16/CELL)));
    *(Lisp_Object *)((char *)v0124 + (CELL-TAG_VECTOR) + ((int32_t)v0123/(16/CELL))) = v0316;
    v0316 = v0184;
    v0316 = (Lisp_Object)((int32_t)(v0316) + 0x10);
    v0184 = v0316;
    goto v0243;

v0280:
    v0123 = stack[-2];
    v0317 = qvalue(elt(env, 2)); /* dpoly */
    v0316 = stack[-3];
    fn = elt(env, 9); /* copy!-vector */
    v0316 = (*qfnn(fn))(qenv(fn), 3, v0123, v0317, v0316);
    nil = C_nil;
    if (exception_pending()) goto v0318;
    env = stack[-5];
    stack[-1] = v0316;
    goto v0320;

v0045:
    v0316 = (Lisp_Object)-15; /* -1 */
    stack[-4] = v0316;
    goto v0137;

v0319:
    v0317 = stack[-3];
    v0316 = (Lisp_Object)17; /* 1 */
    v0317 = *(Lisp_Object *)((char *)v0317 + (CELL-TAG_VECTOR) + ((int32_t)v0316/(16/CELL)));
    v0316 = (Lisp_Object)1; /* 0 */
    v0316 = (v0317 == v0316 ? lisp_true : nil);
    goto v0142;

v0290:
    v0317 = stack[-4];
    v0316 = (Lisp_Object)1; /* 0 */
    if (!(((int32_t)(v0317)) < ((int32_t)(v0316)))) goto v0021;
    v0123 = stack[-3];
    v0317 = (Lisp_Object)1; /* 0 */
    v0316 = (Lisp_Object)1; /* 0 */
    *(Lisp_Object *)((char *)v0123 + (CELL-TAG_VECTOR) + ((int32_t)v0317/(16/CELL))) = v0316;
    goto v0021;

v0021:
    v0123 = stack[-3];
    v0317 = (Lisp_Object)17; /* 1 */
    v0316 = (Lisp_Object)17; /* 1 */
    {   int32_t w = int_of_fixnum(v0316);
        if (w != 0) w = current_modulus - w;
        v0316 = fixnum_of_int(w);
    }
    *(Lisp_Object *)((char *)v0123 + (CELL-TAG_VECTOR) + ((int32_t)v0317/(16/CELL))) = v0316;
    v0316 = (Lisp_Object)17; /* 1 */
    stack[-4] = v0316;
    goto v0137;

v0234:
    v0124 = stack[-3];
    v0123 = v0184;
    v0317 = stack[-1];
    v0316 = v0184;
    v0316 = *(Lisp_Object *)((char *)v0317 + (CELL-TAG_VECTOR) + ((int32_t)v0316/(16/CELL)));
    *(Lisp_Object *)((char *)v0124 + (CELL-TAG_VECTOR) + ((int32_t)v0123/(16/CELL))) = v0316;
    v0316 = v0184;
    v0316 = (Lisp_Object)((int32_t)(v0316) + 0x10);
    v0184 = v0316;
    goto v0068;

v0043:
    v0124 = stack[-2];
    v0123 = v0184;
    v0317 = qvalue(elt(env, 4)); /* poly!-vector */
    v0316 = v0184;
    v0316 = *(Lisp_Object *)((char *)v0317 + (CELL-TAG_VECTOR) + ((int32_t)v0316/(16/CELL)));
    *(Lisp_Object *)((char *)v0124 + (CELL-TAG_VECTOR) + ((int32_t)v0123/(16/CELL))) = v0316;
    v0316 = v0184;
    v0316 = (Lisp_Object)((int32_t)(v0316) + 0x10);
    v0184 = v0316;
    goto v0047;
/* error exit handlers */
v0318:
    env = stack[-5];
    qvalue(elt(env, 1)) = stack[0]; /* linear!-factors */
    popv(6);
    return nil;
}



/* Code for bibasis */

static Lisp_Object MS_CDECL CC_bibasis(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0250, v0312;
    Lisp_Object fn;
    Lisp_Object v0057, v0086, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 4, "bibasis");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0086 = va_arg(aa, Lisp_Object);
    v0057 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for bibasis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0057,v0086,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0001,v0086,v0057);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push5(nil, nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0057;
    stack[-1] = v0086;
    stack[-2] = v0001;
    stack[-3] = v0000;
/* end of prologue */
    stack[-4] = nil;
    v0250 = stack[-3];
    if (v0250 == nil) goto v0074;
    v0250 = stack[-3];
    v0312 = qcar(v0250);
    v0250 = elt(env, 1); /* list */
    if (v0312 == v0250) goto v0074;
    v0250 = stack[-3];
    fn = elt(env, 17); /* mathprint */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = elt(env, 2); /* "is not a polynomial list" */
    fn = elt(env, 18); /* rederr */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    goto v0074;

v0074:
    v0250 = stack[-3];
    v0250 = qcdr(v0250);
    if (!(v0250 == nil)) goto v0070;
    v0250 = stack[-3];
    fn = elt(env, 17); /* mathprint */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = elt(env, 4); /* "polynomial list is empty" */
    fn = elt(env, 18); /* rederr */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    goto v0070;

v0070:
    v0250 = stack[-2];
    if (v0250 == nil) goto v0098;
    v0250 = stack[-2];
    v0312 = qcar(v0250);
    v0250 = elt(env, 1); /* list */
    if (v0312 == v0250) goto v0098;
    v0250 = stack[-2];
    fn = elt(env, 17); /* mathprint */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = elt(env, 5); /* "is not a variable list" */
    fn = elt(env, 18); /* rederr */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    goto v0098;

v0098:
    v0250 = stack[-2];
    v0250 = qcdr(v0250);
    if (!(v0250 == nil)) goto v0214;
    v0250 = stack[-2];
    fn = elt(env, 17); /* mathprint */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = elt(env, 6); /* "variable list is empty" */
    fn = elt(env, 18); /* rederr */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    goto v0214;

v0214:
    v0312 = stack[-1];
    v0250 = elt(env, 7); /* lex */
    if (v0312 == v0250) goto v0023;
    v0312 = stack[-1];
    v0250 = elt(env, 8); /* deglex */
    if (v0312 == v0250) goto v0027;
    v0312 = stack[-1];
    v0250 = elt(env, 9); /* degrevlex */
    v0250 = Lneq(nil, v0312, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    goto v0034;

v0034:
    if (v0250 == nil) goto v0081;
    v0250 = stack[-1];
    fn = elt(env, 17); /* mathprint */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = elt(env, 10); /* " is unsupported monomial ordering" */
    fn = elt(env, 18); /* rederr */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    goto v0081;

v0081:
    v0250 = stack[-2];
    v0250 = qcdr(v0250);
    qvalue(elt(env, 11)) = v0250; /* fluidbibasisvariables */
    v0250 = stack[-1];
    qvalue(elt(env, 12)) = v0250; /* fluidbibasismonomialorder */
    fn = elt(env, 19); /* init */
    v0250 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = qvalue(elt(env, 3)); /* nil */
    v0250 = ncons(v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    stack[-2] = v0250;
    v0250 = stack[-3];
    if (v0250 == nil) goto v0050;
    v0250 = stack[-3];
    v0250 = qcdr(v0250);
    stack[-3] = v0250;
    goto v0276;

v0276:
    v0250 = stack[-3];
    if (v0250 == nil) goto v0050;
    v0250 = stack[-3];
    v0250 = qcar(v0250);
    stack[-1] = stack[-2];
    fn = elt(env, 20); /* reval */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    fn = elt(env, 21); /* simp */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = qcar(v0250);
    fn = elt(env, 22); /* polynomread */
    v0250 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    fn = elt(env, 23); /* sortedpolynomlistinsert */
    v0250 = (*qfn2(fn))(qenv(fn), stack[-1], v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = stack[-3];
    v0250 = qcdr(v0250);
    stack[-3] = v0250;
    goto v0276;

v0050:
    v0250 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    qvalue(elt(env, 13)) = v0250; /* fluidbibasisrunningtime */
    v0250 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    qvalue(elt(env, 14)) = v0250; /* fluidbibasisgctime */
    v0312 = stack[-2];
    v0250 = stack[0];
    fn = elt(env, 24); /* constructinvolutivebasis */
    v0250 = (*qfn2(fn))(qenv(fn), v0312, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    stack[-2] = v0250;
    v0312 = Lgctime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = qvalue(elt(env, 14)); /* fluidbibasisgctime */
    v0250 = difference2(v0312, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    qvalue(elt(env, 14)) = v0250; /* fluidbibasisgctime */
    v0312 = Ltime(nil, 0);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = qvalue(elt(env, 13)); /* fluidbibasisrunningtime */
    v0312 = difference2(v0312, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = qvalue(elt(env, 14)); /* fluidbibasisgctime */
    v0250 = difference2(v0312, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    qvalue(elt(env, 13)) = v0250; /* fluidbibasisrunningtime */
    goto v0285;

v0285:
    v0250 = stack[-2];
    v0250 = qcar(v0250);
    if (v0250 == nil) goto v0279;
    stack[0] = elt(env, 15); /* !*sq */
    v0250 = stack[-2];
    v0250 = qcar(v0250);
    fn = elt(env, 25); /* polynomwrite */
    v0312 = (*qfn1(fn))(qenv(fn), v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = (Lisp_Object)17; /* 1 */
    v0312 = cons(v0312, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = qvalue(elt(env, 16)); /* t */
    v0312 = list3(stack[0], v0312, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    v0250 = stack[-4];
    v0250 = cons(v0312, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-5];
    stack[-4] = v0250;
    v0250 = stack[-2];
    v0250 = qcdr(v0250);
    stack[-2] = v0250;
    goto v0285;

v0279:
    stack[0] = elt(env, 1); /* list */
    v0250 = stack[-4];
    v0250 = Lreverse(nil, v0250);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    {
        Lisp_Object v0165 = stack[0];
        popv(6);
        return cons(v0165, v0250);
    }

v0027:
    v0250 = qvalue(elt(env, 3)); /* nil */
    goto v0034;

v0023:
    v0250 = qvalue(elt(env, 3)); /* nil */
    goto v0034;
/* error exit handlers */
v0202:
    popv(6);
    return nil;
}



/* Code for subst!-cn */

static Lisp_Object MS_CDECL CC_substKcn(Lisp_Object env, int nargs, ...)
{
    Lisp_Object nil = C_nil;
    Lisp_Object v0235, v0104;
    Lisp_Object fn;
    Lisp_Object v0086, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    CSL_IGNORE(nil);
    argcheck(nargs, 3, "subst-cn");
    va_start(aa, nargs);
    v0000 = va_arg(aa, Lisp_Object);
    v0001 = va_arg(aa, Lisp_Object);
    v0086 = va_arg(aa, Lisp_Object);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subst-cn");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0086,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0086);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
/* space for vars preserved across procedure calls */
    push4(nil, nil, nil, nil);
/* copy arguments values to proper place */
    stack[0] = v0086;
    stack[-1] = v0001;
    stack[-2] = v0000;
/* end of prologue */
    v0235 = stack[-1];
    v0235 = ncons(v0235);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-4];
    fn = elt(env, 3); /* setkorder */
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-4];
    stack[-3] = v0235;
    v0235 = stack[-2];
    fn = elt(env, 4); /* reorder */
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-4];
    stack[-2] = v0235;
    v0235 = stack[-2];
    if (!consp(v0235)) goto v0092;
    v0235 = stack[-2];
    v0235 = qcar(v0235);
    v0235 = (consp(v0235) ? nil : lisp_true);
    goto v0091;

v0091:
    if (v0235 == nil) goto v0071;
    v0235 = qvalue(elt(env, 2)); /* nil */
    goto v0039;

v0039:
    if (v0235 == nil) goto v0082;
    v0235 = stack[0];
    if (v0235 == nil) goto v0214;
    v0235 = stack[-2];
    v0235 = qcar(v0235);
    stack[-1] = qcdr(v0235);
    v0235 = stack[0];
    v0235 = qcar(v0235);
    fn = elt(env, 4); /* reorder */
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-4];
    fn = elt(env, 5); /* multf */
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[-1], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-4];
    v0235 = stack[-2];
    stack[-2] = qcdr(v0235);
    v0235 = stack[0];
    v0235 = qcdr(v0235);
    fn = elt(env, 4); /* reorder */
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-4];
    fn = elt(env, 5); /* multf */
    v0235 = (*qfn2(fn))(qenv(fn), stack[-2], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-4];
    fn = elt(env, 6); /* addf */
    v0235 = (*qfn2(fn))(qenv(fn), stack[-1], v0235);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-4];
    stack[-2] = v0235;
    goto v0082;

v0082:
    v0235 = stack[-3];
    fn = elt(env, 3); /* setkorder */
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0272;
    env = stack[-4];
    v0235 = stack[-2];
    {
        popv(5);
        fn = elt(env, 4); /* reorder */
        return (*qfn1(fn))(qenv(fn), v0235);
    }

v0214:
    v0235 = stack[-2];
    v0235 = qcdr(v0235);
    stack[-2] = v0235;
    goto v0082;

v0071:
    v0235 = stack[-2];
    v0235 = qcar(v0235);
    v0235 = qcar(v0235);
    v0104 = qcar(v0235);
    v0235 = stack[-1];
    v0235 = (v0104 == v0235 ? lisp_true : nil);
    goto v0039;

v0092:
    v0235 = qvalue(elt(env, 1)); /* t */
    goto v0091;
/* error exit handlers */
v0272:
    popv(5);
    return nil;
}



setup_type const u55_setup[] =
{
    {"*addsq",                  too_few_2,      CC_Haddsq,     wrong_no_2},
    {"find-expts",              too_few_2,      CC_findKexpts, wrong_no_2},
    {"ps:minus-erule",          too_few_2,      CC_psTminusKerule,wrong_no_2},
    {"compex",                  CC_compex,      too_many_1,    wrong_no_1},
    {"xreduce1",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreduce1},
    {"forttab",                 CC_forttab,     too_many_1,    wrong_no_1},
    {"dpropagator",             wrong_no_na,    wrong_no_nb,   (n_args *)CC_dpropagator},
    {"revalpart",               CC_revalpart,   too_many_1,    wrong_no_1},
    {"formclear",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_formclear},
    {"dv_skelsplit",            CC_dv_skelsplit,too_many_1,    wrong_no_1},
    {"allbkern",                CC_allbkern,    too_many_1,    wrong_no_1},
    {"flatten",                 CC_flatten,     too_many_1,    wrong_no_1},
    {"addlc",                   too_few_2,      CC_addlc,      wrong_no_2},
    {"ofsf_chsimpat1",          CC_ofsf_chsimpat1,too_many_1,  wrong_no_1},
    {"dependsl",                too_few_2,      CC_dependsl,   wrong_no_2},
    {"mri_irsplit",             CC_mri_irsplit, too_many_1,    wrong_no_1},
    {"rl_b2atl",                too_few_2,      CC_rl_b2atl,   wrong_no_2},
    {"subsqnew",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_subsqnew},
    {"lengthf",                 CC_lengthf,     too_many_1,    wrong_no_1},
    {"functionp",               CC_functionp,   too_many_1,    wrong_no_1},
    {"requote1",                CC_requote1,    too_many_1,    wrong_no_1},
    {"actual_world",            too_few_2,      CC_actual_world,wrong_no_2},
    {"split-wrt-variables",     wrong_no_na,    wrong_no_nb,   (n_args *)CC_splitKwrtKvariables},
    {"inormmat",                CC_inormmat,    too_many_1,    wrong_no_1},
    {"modroots1",               too_few_2,      CC_modroots1,  wrong_no_2},
    {"simpsqrt",                CC_simpsqrt,    too_many_1,    wrong_no_1},
    {"cl_gaussintersection",    too_few_2,      CC_cl_gaussintersection,wrong_no_2},
    {"ofsf_simplneq",           too_few_2,      CC_ofsf_simplneq,wrong_no_2},
    {"let0",                    CC_let0,        too_many_1,    wrong_no_1},
    {"rl_atl",                  CC_rl_atl,      too_many_1,    wrong_no_1},
    {"evalgeq",                 too_few_2,      CC_evalgeq,    wrong_no_2},
    {"tstpolyarg",              too_few_2,      CC_tstpolyarg, wrong_no_2},
    {"lchk",                    CC_lchk,        too_many_1,    wrong_no_1},
    {"exdfpf",                  CC_exdfpf,      too_many_1,    wrong_no_1},
    {"lispstmtp",               CC_lispstmtp,   too_many_1,    wrong_no_1},
    {"gi",                      too_few_2,      CC_gi,         wrong_no_2},
    {"deg",                     too_few_2,      CC_deg,        wrong_no_2},
    {"count-linear-factors-mod-p",wrong_no_na,  wrong_no_nb,   (n_args *)CC_countKlinearKfactorsKmodKp},
    {"bibasis",                 wrong_no_na,    wrong_no_nb,   (n_args *)CC_bibasis},
    {"subst-cn",                wrong_no_na,    wrong_no_nb,   (n_args *)CC_substKcn},
    {NULL, (one_args *)"u55", (two_args *)"2357 8219699 5011858", 0}
};

/* end of generated code */