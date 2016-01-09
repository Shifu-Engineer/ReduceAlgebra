
// $destdir/u40.c        Machine generated C code

// $Id$

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
#define SOCKETS 1
#endif
#endif
#ifdef WIN32
# if defined WIN64 || defined __WIN64__
# define OPSYS "win64"
# define IMPNAME "win64"
# else
# define OPSYS "win32"
# define IMPNAME "win32"
# endif
#else
# ifdef HOST_OS
# define OPSYS HOST_OS
# ifdef HOST_CPU
# define IMPNAME HOST_OS ":" HOST_CPU
# else
# define IMPNAME HOST_OS
# endif
# else
# define OPSYS "Unknown"
# define IMPNAME "Generic"
# endif
#endif
#ifdef HAVE_STDINT_H
#if defined __cplusplus && !defined __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS 1
#endif
#include <stdint.h>
#else 
#ifndef HAVE_UINT32_T
#ifdef HAVE_U_INT32_T
typedef u_int32_t uint32_t;
#define HAVE_UINT32_T 1
#endif
#endif
#ifndef HAVE_UINT64_T
#ifdef HAVE_U_INT64_T
typedef u_int64_t uint64_t;
#define HAVE_UINT64_T 1
#endif
#endif
#ifndef HAVE_UINTPTR_T
#ifdef HAVE_U_INTPTR_T
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
typedef int CSLbool;
#define YES 1
#define NO 0
#define CSL_IGNORE(x) ((void)(x))
#ifndef PAGE_BITS
# define PAGE_BITS 22
#endif 
#define PAGE_POWER_OF_TWO (((intptr_t)1) << PAGE_BITS)
#define CSL_PAGE_SIZE (PAGE_POWER_OF_TWO - 256)
#ifndef MAX_HEAPSIZE
# define MAX_HEAPSIZE (SIXTY_FOUR_BIT ? (512*1024) : 2048)
#endif 
#ifndef MAX_BPSSIZE
# define MAX_BPSSIZE 64
#endif 
#define MEGABYTE ((intptr_t)0x100000U)
#if PAGE_BITS >= 20
#define MAX_PAGES (MAX_HEAPSIZE >> (PAGE_BITS-20))
#define MAX_BPS_PAGES (MAX_BPSSIZE >> (PAGE_BITS-20))
#else
#define MAX_PAGES (MAX_HEAPSIZE << (20-PAGE_BITS))
#define MAX_BPS_PAGES (MAX_BPSSIZE << (20-PAGE_BITS))
#endif
#define MAX_NATIVE_PAGES MAX_BPS_PAGES
#define LONGEST_LEGAL_FILENAME 1024
#define FP_WORD_ORDER 0x01
#define FP_BYTE_ORDER 0x02
#define FP_MASK 0xff
typedef intptr_t LispObject;
#define CELL ((intptr_t)sizeof(LispObject))
#define TAG_BITS 7
#define TAG_CONS 0 
#define TAG_FIXNUM 1 
#define TAG_ODDS 2 
#define TAG_SFLOAT 3 
#define TAG_SYMBOL 4 
#define TAG_NUMBERS 5 
#define TAG_VECTOR 6 
#define TAG_BOXFLOAT 7 
#define fixnum_of_int(x) ((LispObject)(TAG_FIXNUM + (((int32_t)(x)) << 4)))
#ifdef SIGNED_SHIFTS_ARE_LOGICAL
#define int_of_fixnum(x) ((int32_t)(((int32_t)(x)) < 0 ? \
 (((int32_t)(x))>>4) | (-0x10000000) : \
 (((int32_t)(x))>>4)))
#else 
#define int_of_fixnum(x) ((int32_t)(((int32_t)(x)) >> 4))
#endif 
#define GC_BIT_I 8 
#define GC_BIT_H 8 
#define GC_BIT_P ((intptr_t)~((~(uintptr_t)0) >> 1))
#define is_marked_i(w) (((int)(w) & GC_BIT_I) != 0)
extern LispObject address_sign; 
#define is_marked_p(w) (((LispObject)(w) - address_sign) < 0)
#define clear_mark_bit_p(w) (((LispObject)(w) & ~GC_BIT_P) + \
 address_sign)
#define flip_mark_bit_i(w) ((LispObject)(w) ^ GC_BIT_I)
#define flip_mark_bit_h(w) ((Header)(w) ^ GC_BIT_H)
#define flip_mark_bit_p(w) ((LispObject)(w) ^ GC_BIT_P)
#define is_marked_h(w) (((int)(w) & GC_BIT_H) != 0)
#define exception_pending() (((int)nil & 1) != 0)
#define flip_exception() (nil = C_nil = (nil ^ 1))
#define ignore_exception() \
 do { nil = C_nil; if (exception_pending()) flip_exception(); } while (0)
#define set_mark_bit_h(h) ((Header)(h) | GC_BIT_H)
#define clear_mark_bit_h(h) ((Header)(h) & ~GC_BIT_H)
#define set_mark_bit_i(h) ((LispObject)(h) | GC_BIT_I)
#define clear_mark_bit_i(h) ((LispObject)(h) & ~GC_BIT_I)
#define is_cons(p) ((((int)(p)) & TAG_BITS) == TAG_CONS)
#define is_fixnum(p) ((((int)(p)) & TAG_BITS) == TAG_FIXNUM)
#define is_odds(p) ((((int)(p)) & TAG_BITS) == TAG_ODDS) 
#define is_sfloat(p) ((((int)(p)) & TAG_BITS) == TAG_SFLOAT)
#define is_symbol(p) ((((int)(p)) & TAG_BITS) == TAG_SYMBOL)
#define is_numbers(p)((((int)(p)) & TAG_BITS) == TAG_NUMBERS)
#define is_vector(p) ((((int)(p)) & TAG_BITS) == TAG_VECTOR)
#define is_bfloat(p) ((((int)(p)) & TAG_BITS) == TAG_BOXFLOAT)
#ifdef COMMON
#define consp(p) (is_cons(p) && (p) != nil)
#define symbolp(p) (is_symbol(p) || (p) == nil)
#else 
#define consp(p) is_cons(p)
#define symbolp(p) is_symbol(p)
#endif 
#define car_legal(p) is_cons(p)
#define is_number(p) ((((int)(p)) & 1) != 0) 
#define is_float(p) ((((int)(p)) & 3) == 3) 
#define is_immed_or_cons(p) ((((int)(p)) & 4) == 0)
typedef struct Cons_Cell
{ LispObject car;
 LispObject cdr;
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
typedef LispObject Special_Form(LispObject, LispObject);
typedef LispObject one_args(LispObject, LispObject);
typedef LispObject two_args(LispObject, LispObject, LispObject);
typedef LispObject n_args(LispObject, int, ...);
typedef uintptr_t Header;
#define header_mask 0x3f0
#define type_of_header(h) (((unsigned int)(h)) & header_mask)
#define length_of_header(h) (((uint32_t)(h)) >> 10)
#define TYPE_SYMBOL 0x00000010
#define SYM_SPECIAL_VAR 0x00000040 
#define SYM_GLOBAL_VAR 0x00000080 
#define SYM_SPECIAL_FORM 0x00000100 
#define SYM_MACRO 0x00000200 
#define SYM_C_DEF 0x00000400 
#define SYM_CODEPTR 0x00000800 
#define SYM_ANY_GENSYM 0x00001000 
#define SYM_TRACED 0x00002000
#define SYM_FASTGET_MASK 0x000fc000 
#define SYM_FASTGET_SHIFT 14
#ifdef COMMON
#define SYM_EXTERN_IN_HOME 0x00100000 
#define SYM_IN_PACKAGE 0xffe00000 
#define SYM_IN_PKG_SHIFT 23
#define SYM_IN_PKG_COUNT 11
#else 
#define SYM_UNPRINTED_GENSYM 0x00100000
#endif 
#define symhdr_length ((sizeof(Symbol_Head) + 7) & ~7)
#define is_symbol_header(h) (((int)h & 0x30) == TYPE_SYMBOL)
#define header_fastget(h) (((h) >> SYM_FASTGET_SHIFT) & 0x3f)
#define TYPE_BIGNUM 0x020 
#define TYPE_RATNUM 0x060
#define TYPE_COMPLEX_NUM 0x0a0
#define TYPE_SINGLE_FLOAT 0x120
#define TYPE_DOUBLE_FLOAT 0x160
#define TYPE_LONG_FLOAT 0x1a0
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
#define is_ratio(n) \
 (type_of_header(numhdr(n)) == TYPE_RATNUM)
#define is_complex(n) \
 (type_of_header(numhdr(n)) == TYPE_COMPLEX_NUM)
#define is_bignum_header(h) (type_of_header(h) == TYPE_BIGNUM)
#define is_bignum(n) is_bignum_header(numhdr(n))
#define ADDRESS_SHIFT (SIXTY_FOUR_BIT ? 3 : 2)
#ifdef MEMORY_TRACE
#define vechdr(v) (*(Header *)memory_reference((intptr_t)((char *)(v) - \
 TAG_VECTOR)))
#define elt(v, n) (*(LispObject *)memory_reference((intptr_t)((char *)(v) + \
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
#define vechdr(v) (*(Header *)((char *)(v) - TAG_VECTOR))
#define elt(v, n) (*(LispObject *)((char *)(v) + \
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
#define ielt(v, n) (*(intptr_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<ADDRESS_SHIFT)))
#define ielt32(v, n) (*(int32_t *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define felt(v, n) (*(float *)((char *)(v) + \
 (CELL-TAG_VECTOR)+(((intptr_t)(n))<<2)))
#define delt(v, n) (*(double *)((char *)(v) + \
 (2*CELL-TAG_VECTOR)+(((intptr_t)(n))<<3)))
#define TYPE_BITVEC1 0x030 
#define TYPE_BITVEC2 0x0b0 
#define TYPE_BITVEC3 0x130
#define TYPE_BITVEC4 0x1b0 
#define TYPE_BITVEC5 0x230 
#define TYPE_BITVEC6 0x2b0 
#define TYPE_BITVEC7 0x330 
#define TYPE_BITVEC8 0x3b0 
#define header_of_bitvector(h) (((h) & 0x70) == TYPE_BITVEC1)
#define TYPE_STRING 0x070 
#define TYPE_BPS 0x170 
#define TYPE_SPARE 0x270 
#define TYPE_MAPLEREF TYPE_SPARE 
#define TYPE_FOREIGN TYPE_SPARE 
#define TYPE_SP 0x370 
#define vector_holds_binary(h) (((h) & 0x80) == 0 || header_of_bitvector(h))
#define TYPE_SIMPLE_VEC 0x0f0 
#define TYPE_HASH 0x1f0 
#define TYPE_ARRAY 0x2f0 
#define TYPE_STRUCTURE 0x3f0 
#define is_mixed_header(h) (((h) & 0x2b0) == TYPE_MIXED1)
#define TYPE_VEC8 TYPE_BPS
#define TYPE_VEC16 0x220 
#define TYPE_VEC32 0x260 
#define TYPE_MIXED1 0x2a0 
#define TYPE_MIXED2 0x2e0 
#define TYPE_FLOAT32 0x320 
#define TYPE_FLOAT64 0x360 
#define TYPE_MIXED3 0x3a0 
#define TYPE_STREAM 0x3e0 
#define ODDS_MASK 0xff
#define TAG_CHAR 0x02 
#define TAG_BPS 0x42
#define TAG_SPID 0xc2 
#define SPID_NIL (TAG_SPID+0x0000) 
#define SPID_FBIND (TAG_SPID+0x0100) 
#define SPID_CATCH (TAG_SPID+0x0200) 
#define SPID_PROTECT (TAG_SPID+0x0300) 
#define SPID_HASH0 (TAG_SPID+0x0400) 
#define SPID_HASH1 (TAG_SPID+0x0500) 
#define SPID_GCMARK (TAG_SPID+0x0600) 
#define SPID_NOINPUT (TAG_SPID+0x0700) 
#define SPID_ERROR (TAG_SPID+0x0800) 
#define SPID_PVBIND (TAG_SPID+0x0900) 
#define SPID_NOARG (TAG_SPID+0x0a00) 
#define SPID_NOPROP (TAG_SPID+0x0b00) 
#define SPID_LIBRARY (TAG_SPID+0x0c00) 
#define is_header(x) (((int)(x) & 0x30) != 0) 
#define is_char(x) (((int)(x) & ODDS_MASK) == TAG_CHAR)
#define is_bps(x) (((int)(x) & ODDS_MASK) == TAG_BPS)
#define is_spid(x) (((int)(x) & ODDS_MASK) == TAG_SPID)
#define is_library(x)(((int)(x) & 0xffff) == SPID_LIBRARY)
#define library_number(x) (((x) >> 20) & 0xfff)
#define font_of_char(n) (((int32_t)(n) >> 29) & 0x03)
#define bits_of_char(n) (0)
#define code_of_char(n) (((int32_t)(n) >> 8) & 0x001fffff)
#define pack_char(font, code) \
 ((LispObject)((((uint32_t)(font)) << 29) | \
 (((uint32_t)(code)) << 8) | TAG_CHAR))
#define CHAR_EOF pack_char(0, 0x0010ffff)
#define data_of_bps(v) \
 ((char *)(doubleword_align_up((intptr_t) \
 bps_pages[((uint32_t)(v))>>(PAGE_BITS+6)]) + \
 (SIXTY_FOUR_BIT ? \
 (intptr_t)((((uint64_t)(v))>>(32-PAGE_BITS)) & \
 PAGE_POWER_OF_TWO) : \
 0) + \
 (((v) >> 6) & (PAGE_POWER_OF_TWO-4))))
typedef int32_t junk; 
typedef intptr_t junkxx; 
typedef struct Symbol_Head
{
 Header header; 
 LispObject value; 
 LispObject env; 
 intptr_t function1; 
 intptr_t function2; 
 intptr_t functionn; 
 LispObject pname; 
 LispObject plist; 
 LispObject fastgets;
 uintptr_t count; 
#ifdef COMMON
 LispObject package;
#endif 
} Symbol_Head;
#define MAX_FASTGET_SIZE 63
#ifdef COMMON
#define symalign(n) (SIXTY_FOUR_BIT ? \
 ((char *)((intptr_t)(n) & ~(intptr_t)TAG_SYMBOL)) : \
 (n))
#else
#define symalign(n) (n)
#endif
#ifndef MEMORY_TRACE
#define qheader(p) (*(Header *) symalign((char *)(p) - TAG_SYMBOL))
#define qvalue(p) (*(LispObject *)symalign((char *)(p) + (CELL - TAG_SYMBOL)))
#define qenv(p) (*(LispObject *)symalign((char *)(p) + (2*CELL - TAG_SYMBOL)))
#define qfn1(p) ((one_args *) *((intptr_t *)symalign((char *)(p) + \
 (3*CELL - TAG_SYMBOL))))
#define qfn2(p) ((two_args *) *((intptr_t *)symalign((char *)(p) + \
 (4*CELL - TAG_SYMBOL))))
#define qfnn(p) ((n_args *) *((intptr_t *)symalign((char *)(p) + \
 (5*CELL - TAG_SYMBOL))))
#define ifn1(p) (*(intptr_t *)symalign((char *)(p) + (3*CELL-TAG_SYMBOL)))
#define ifn2(p) (*(intptr_t *)symalign((char *)(p) + (4*CELL-TAG_SYMBOL)))
#define ifnn(p) (*(intptr_t *)symalign((char *)(p) + (5*CELL-TAG_SYMBOL)))
#define qpname(p) (*(LispObject *)symalign((char *)(p) + (6*CELL-TAG_SYMBOL)))
#define qplist(p) (*(LispObject *)symalign((char *)(p) + (7*CELL-TAG_SYMBOL)))
#define qfastgets(p) (*(LispObject *)symalign((char *)(p) + (8*CELL-TAG_SYMBOL)))
#define qcount(p) (*(uintptr_t *) symalign((char *)(p) + (9*CELL-TAG_SYMBOL)))
#ifdef COMMON
#define qpackage(p) (*(LispObject *)symalign((char *)(p) + (10*CELL-TAG_SYMBOL)))
#endif
#else 
#define qheader(p) (*(Header *) memory_reference((intptr_t) \
 symalign((char *)(p) - TAG_SYMBOL)))
#define qvalue(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (CELL-TAG_SYMBOL))))
#define qenv(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (2*CELL-TAG_SYMBOL))))
#define qfn1(p) ((one_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define qfn2(p) ((two_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define qfnn(p) ((n_args *) *(intptr_t *)memory_reference((intptr_t) \
 symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define ifn1(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (3*CELL-TAG_SYMBOL))))
#define ifn2(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (4*CELL-TAG_SYMBOL))))
#define ifnn(p) (*(intptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (5*CELL-TAG_SYMBOL))))
#define qpname(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (6*CELL-TAG_SYMBOL))))
#define qplist(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (7*CELL-TAG_SYMBOL))))
#define qfastgets(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (8*CELL-TAG_SYMBOL))))
#define qcount(p) (*(uintptr_t *) memory_reference((intptr_t) \
 symalign((char *)(p) + (9*CELL-TAG_SYMBOL))))
#ifdef COMMON
#define qpackage(p) (*(LispObject *)memory_reference((intptr_t) \
 symalign((char *)(p) + (10*CELL-TAG_SYMBOL))))
#endif
#endif 
typedef union Float_union
{ float f;
 int32_t i;
} Float_union;
typedef struct Big_Number
{
 Header h;
 uint32_t d[1]; 
} Big_Number;
#define bignum_length(b) length_of_header(numhdr(b))
#ifdef MEMORY_TRACE
#define bignum_digits(b) ((uint32_t *)memory_reference((intptr_t)((char *)b + \
 (CELL-TAG_NUMBERS))))
#else
#define bignum_digits(b) ((uint32_t *)((char *)b + (CELL-TAG_NUMBERS)))
#endif
#define make_bighdr(n) (TAG_ODDS+TYPE_BIGNUM+(((intptr_t)(n))<<12))
#define pack_hdrlength(n) (((intptr_t)(n))<<12)
typedef struct Rational_Number
{ Header header;
 LispObject num;
 LispObject den;
} Rational_Number;
#define numerator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->num)
#define denominator(r) (((Rational_Number *)((char *)(r)-TAG_NUMBERS))->den)
typedef struct Complex_Number
{ Header header;
 LispObject real;
 LispObject imag;
} Complex_Number;
#define real_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->real)
#define imag_part(r) (((Complex_Number *)((char *)(r)-TAG_NUMBERS))->imag)
typedef struct Single_Float
{ Header header;
 union float_or_int
 { float f;
 int32_t i;
 } f;
} Single_Float;
#define single_float_val(v) \
 (((Single_Float *)((char *)(v)-TAG_BOXFLOAT))->f.f)
#define SIZEOF_DOUBLE_FLOAT 16
#define double_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define double_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define SIZEOF_LONG_FLOAT 16
#define long_float_addr(v) ((double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define long_float_val(v) (*(double *)((char *)(v) + \
 (8-TAG_BOXFLOAT)))
#define word_align_up(n) ((LispObject)(((intptr_t)(n) + 3) & (-4)))
#define doubleword_align_up(n) ((LispObject)(((intptr_t)(n) + 7) & (-8)))
#define doubleword_align_down(n) ((LispObject)((intptr_t)(n) & (-8)))
#define object_align_up(n) ((LispObject)(((intptr_t)(n) + \
 sizeof(LispObject) - 1) & (-sizeof(LispObject))))
#define quadword_align_up(n) ((LispObject)(((intptr_t)(n) + 15) & (-16)))
#define quadword_align_down(n) ((LispObject)((intptr_t)(n) & (-16)))
#define UNWIND_NULL 0x0 
#define UNWIND_GO 0x1 
#define UNWIND_RETURN 0x2 
#define UNWIND_THROW 0x3 
#define UNWIND_RESTART 0x4 
#define UNWIND_RESOURCE 0x5 
#define UNWIND_FNAME 0x100 
#define UNWIND_ARGS 0x200 
#define UNWIND_ERROR (UNWIND_FNAME|UNWIND_ARGS)
#define UNWIND_UNWIND 0x400 
#if 0 && defined DEBUG
#define SHOW_FNAME (exit_reason == UNWIND_THROW || \
 (exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS (exit_reason == UNWIND_THROW || \
 (exit_reason & UNWIND_ARGS) != 0)
#else
#define SHOW_FNAME ((exit_reason & UNWIND_FNAME) != 0)
#define SHOW_ARGS ((exit_reason & UNWIND_ARGS) != 0)
#endif
#endif 
#ifndef header_cslerror_h
#define header_cslerror_h 1
extern "C" LispObject interrupted(LispObject p);
extern "C" LispObject error(int nargs, int code, ...);
extern "C" LispObject cerror(int nargs, int code1, int code2, ...);
extern "C" LispObject too_few_2(LispObject env, LispObject a1);
extern "C" LispObject too_many_1(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_0a(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_0b(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_3a(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_3b(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_na(LispObject env, LispObject a1);
extern "C" LispObject wrong_no_nb(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject wrong_no_1(LispObject env, int nargs, ...);
extern "C" LispObject wrong_no_2(LispObject env, int nargs, ...);
extern "C" LispObject bad_specialn(LispObject env, int nargs, ...);
extern "C" LispObject aerror(const char *s); 
extern "C" LispObject aerror0(const char *s);
extern "C" LispObject aerror1(const char *s, LispObject a);
extern "C" LispObject aerror2(const char *s, LispObject a, LispObject b);
extern "C" void fatal_error(int code, ...);
#define GC_MESSAGES 0x01
#define FASL_MESSAGES 0x02
#define VERBOSE_MSGS 0x04
#define GC_MSG_BITS 0x07
#define verbos_flag (miscflags & GC_MSG_BITS)
#define HEADLINE_FLAG 0x08
#define FNAME_FLAG 0x10
#define ARGS_FLAG 0x20
#define BACKTRACE_MSG_BITS 0x38
#define err_bad_car 0 
#define err_bad_cdr 1 
#define err_no_store 2 
#define err_undefined_function_1 3 
#define err_undefined_function_2 4 
#define err_undefined_function_n 5 
#define err_wrong_no_args 6 
#define err_unbound_lexical 7 
#define err_bad_rplac 8 
#define err_bad_arith 9 
#define err_redef_special 10 
#define err_bad_arg 11 
#define err_bad_declare 12 
#define err_bad_fn 13 
#define err_unset_var 14 
#define err_too_many_args1 15 
#define err_too_many_args2 16 
#define err_bad_apply 17 
#define err_macroex_hook 18 
#define err_block_tag 19 
#define err_go_tag 20 
#define err_excess_args 21
#define err_insufficient_args 22
#define err_bad_bvl 23 
#define err_bad_keyargs 24
#define err_write_err 25
#define err_bad_endp 26 
#define err_no_fasldir 27
#define err_no_fasl 28 
#define err_open_failed 29 
#define err_pipe_failed 30 
#define err_stack_overflow 31
#define err_top_bit 32
#define err_mem_spans_zero 33
#define err_no_longer_used 34 
#define err_no_tempdir 35
#ifdef INCLUDE_ERROR_STRING_TABLE
static const char *error_message_table[] =
{ "attempt to take car of an atom",
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
#ifdef USE_MPI
#include "mpi.h"
extern int32_t mpi_rank,mpi_size;
#endif
#define D do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s\n", __LINE__, fffff); \
 fflush(stderr); \
 } while (0)
#define DS(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
 if (fffff == NULL) fffff = strrchr(__FILE__, '\\'); \
 if (fffff == NULL) fffff = __FILE__; else fffff++; \
 fprintf(stderr, "Line %d File %s: %s\n", __LINE__, fffff, (s)); \
 fflush(stderr); \
 } while (0)
#define DX(s) do { \
 const char *fffff = strrchr(__FILE__, '/'); \
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
#define PAGE_TYPE_CONS 0
#define PAGE_TYPE_VECTOR 1
#define PAGE_TYPE_BPS 2
#define PAGE_TYPE_NATIVE 3
typedef struct page_map_t
{ void *start;
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
extern LispObject *nilsegment, *stacksegment;
extern LispObject *stackbase;
extern int32_t stack_segsize; 
extern LispObject *C_stack;
#define stack C_stack
extern char *C_stack_base, *C_stack_limit;
extern double max_store_size;
extern CSLbool restartp;
extern char *big_chunk_start, *big_chunk_end;
#ifdef CONSERVATIVE
extern LispObject *C_stackbase, *C_stacktop;
#endif
extern LispObject multiplication_buffer;
#ifdef MEMORY_TRACE
#define push(a) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); } while (0)
#define push2(a,b) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); } while (0)
#define push3(a,b,c) do { \
 *++stack = (a); \
 memory_reference((intptr_t)stack); \
 *++stack = (b); \
 memory_reference((intptr_t)stack); \
 *++stack = (c); \
 memory_reference((intptr_t)stack); } while (0)
#define push4(a,b,c,d) do { \
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
#define my_pop() (memory_reference((int32_t)stack), (*stack--))
#define pop(a) { memory_reference((intptr_t)stack); (a) = *stack--; }
#define pop2(a,b) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; }
#define pop3(a,b,c) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; }
#define pop4(a,b,c,d) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
 memory_reference((intptr_t)stack); (d) = *stack--; }
#define pop5(a,b,c,d,e) { memory_reference((intptr_t)stack); (a) = *stack--; memory_reference((intptr_t)stack); (b) = *stack--; memory_reference((intptr_t)stack); (c) = *stack--; \
 memory_reference((intptr_t)stack); (d) = *stack--; memory_reference((intptr_t)stack); (e) = *stack--; }
#define pop6(a,b,c,d,e,f) {pop3(a,b,c); pop3(d,e,f)}
#define popv(n) stack -= (n)
#else 
#define push(a) { *++stack = (a); }
#define push2(a,b) { stack[1] = (a); stack[2] = (b); stack += 2; }
#define push3(a,b,c) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack += 3; }
#define push4(a,b,c,d) { stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack += 4; }
#define push5(a,b,c,d,e){ stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack += 5; }
#define push6(a,b,c,d,e,f) { \
 stack[1] = (a); stack[2] = (b); stack[3] = (c); \
 stack[4] = (d); stack[5] = (e); stack[6] = (f); \
 stack += 6; }
#define pop(a) { (a) = *stack--; }
#define pop2(a,b) { stack -= 2; (a) = stack[2]; (b) = stack[1]; }
#define pop3(a,b,c) { stack -= 3; (a) = stack[3]; (b) = stack[2]; \
 (c) = stack[1]; }
#define pop4(a,b,c,d) { stack -= 4; (a) = stack[4]; (b) = stack[3]; \
 (c) = stack[2]; (d) = stack[1]; }
#define pop5(a,b,c,d,e) { stack -= 5; (a) = stack[5]; (b) = stack[4]; \
 (c) = stack[3]; (d) = stack[2]; (e) = stack[1]; }
#define pop6(a,b,c,d,e, f) { stack -= 6; \
 (a) = stack[6]; (b) = stack[5]; (c) = stack[4]; \
 (d) = stack[3]; (e) = stack[2]; (f) = stack[1]; }
#define popv(n) stack -= (n)
#endif 
#define errexit() { nil = C_nil; if (exception_pending()) return nil; }
#define errexitn(n) { nil = C_nil; \
 if (exception_pending()) { popv(n); return nil; } }
#define errexitv() { nil = C_nil; if (exception_pending()) return; }
#define errexitvn(n) { nil = C_nil; \
 if (exception_pending()) { popv(n); return; } }
#define GC_USER_SOFT 0
#define GC_USER_HARD 1
#define GC_STACK 2
#define GC_CONS 3
#define GC_VEC 4
#define GC_BPS 5
#define GC_PRESERVE 6
#define GC_NATIVE 7
extern volatile char stack_contents_temp;
#ifdef CHECK_STACK
extern int check_stack(const char *file, int line);
extern void show_stack();
#define if_check_stack \
 if (check_stack("@" __FILE__,__LINE__)) \
 { show_stack(); return aerror("stack overflow"); }
#else
#define if_check_stack \
 { const char *p = (char *)&p; \
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
#define HANDLE_BLIP \
 if (blipflag) \
 { blipflag = 0; \
 if (startblip >= 0 && ++blipcount > startblip) \
 { fprintf(stderr, "Line %d of file %s\n", __LINE__, __FILE__); \
 fflush(stderr); \
 } \
 }
#else
#define HANDLE_BLIP
#endif
#define stackcheck0(k) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { reclaim(nil, "stack", GC_STACK, 0); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck1(k, a1) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { a1 = reclaim(a1, "stack", GC_STACK, 0); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck2(k, a1, a2) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push(a2); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); pop(a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck3(k, a1, a2, a3) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push2(a2, a3); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop2(a3, a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
#define stackcheck4(k, a1, a2, a3, a4) \
 if_check_stack \
 if ((--countdown < 0 && deal_with_tick()) || \
 stack >= stacklimit) \
 { push3(a2, a3, a4); \
 a1 = reclaim(a1, "stack", GC_STACK, 0); \
 pop3(a4, a3, a2); \
 nil = C_nil; \
 if (exception_pending()) { popv(k); return nil; } \
 }
extern LispObject C_nil;
#define first_nil_offset 50 
#define work_0_offset 200
#define last_nil_offset 251
#define NIL_SEGMENT_SIZE (last_nil_offset*sizeof(LispObject) + 32)
#define SPARE 512
#ifdef COMMON
#define BASE ((LispObject *)nil)
#else
#define BASE (SIXTY_FOUR_BIT ? ((LispObject *)(nil+4)): ((LispObject *)nil))
#endif
extern intptr_t byteflip;
extern LispObject codefringe;
extern LispObject volatile codelimit;
extern LispObject * volatile stacklimit;
extern LispObject fringe;
extern LispObject volatile heaplimit;
extern LispObject volatile vheaplimit;
extern LispObject vfringe;
extern intptr_t nwork;
extern intptr_t exit_count;
extern intptr_t gensym_ser, print_precision, miscflags;
extern intptr_t current_modulus, fastget_size, package_bits;
extern intptr_t modulus_is_large;
extern LispObject lisp_true, lambda, funarg, unset_var, opt_key, rest_key;
extern LispObject quote_symbol, function_symbol, comma_symbol;
extern LispObject comma_at_symbol, cons_symbol, eval_symbol;
extern LispObject work_symbol, evalhook, applyhook, macroexpand_hook;
extern LispObject append_symbol, exit_tag, exit_value, catch_tags;
extern LispObject current_package, startfn;
extern LispObject gensym_base, string_char_sym, boffo;
extern LispObject err_table;
extern LispObject progn_symbol;
extern LispObject lisp_work_stream, charvec, raise_symbol, lower_symbol;
extern LispObject echo_symbol, codevec, litvec, supervisor, B_reg;
extern LispObject savedef, comp_symbol, compiler_symbol, faslvec;
extern LispObject tracedfn, lisp_terminal_io;
extern LispObject lisp_standard_output, lisp_standard_input, lisp_error_output;
extern LispObject lisp_trace_output, lisp_debug_io, lisp_query_io;
extern LispObject prompt_thing, faslgensyms;
extern LispObject prinl_symbol, emsg_star, redef_msg;
extern LispObject expr_symbol, fexpr_symbol, macro_symbol;
extern LispObject cl_symbols, active_stream, current_module;
extern LispObject native_defs, features_symbol, lisp_package;
extern LispObject sys_hash_table, help_index, cfunarg, lex_words;
extern LispObject get_counts, fastget_names, input_libraries;
extern LispObject output_library, current_file, break_function;
extern LispObject standard_output, standard_input, debug_io;
extern LispObject error_output, query_io, terminal_io;
extern LispObject trace_output, fasl_stream;
extern LispObject native_code, native_symbol, traceprint_symbol;
extern LispObject loadsource_symbol;
extern LispObject hankaku_symbol, bytecoded_symbol, nativecoded_symbol;
extern LispObject gchook, resources, callstack, procstack, procmem;
extern LispObject trap_time, count_high;
#ifdef COMMON
extern LispObject keyword_package;
extern LispObject all_packages, package_symbol, internal_symbol;
extern LispObject external_symbol, inherited_symbol;
extern LispObject key_key, allow_other_keys, aux_key;
extern LispObject format_symbol;
extern LispObject expand_def_symbol, allow_key_key;
#endif
extern LispObject declare_symbol, special_symbol, large_modulus;
extern LispObject used_space, avail_space, eof_symbol, call_stack;
#ifdef OPENMATH
extern LispObject om_openFileDev(LispObject env, int nargs, ...);
extern LispObject om_openStringDev(LispObject nil, LispObject lstr, LispObject lenc);
extern LispObject om_closeDev(LispObject env, LispObject dev);
extern LispObject om_setDevEncoding(LispObject nil, LispObject ldev, LispObject lenc);
extern LispObject om_makeConn(LispObject nil, LispObject ltimeout);
extern LispObject om_closeConn(LispObject nil, LispObject lconn);
extern LispObject om_getConnInDevice(LispObject nil, LispObject lconn);
extern LispObject om_getConnOutDevice(LispObject nil, LispObject lconn);
extern LispObject om_connectTCP(LispObject nil, int nargs, ...);
extern LispObject om_bindTCP(LispObject nil, LispObject lconn, LispObject lport);
extern LispObject om_putApp(LispObject nil, LispObject ldev);
extern LispObject om_putEndApp(LispObject nil, LispObject ldev);
extern LispObject om_putAtp(LispObject nil, LispObject ldev);
extern LispObject om_putEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_putAttr(LispObject nil, LispObject ldev);
extern LispObject om_putEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_putBind(LispObject nil, LispObject ldev);
extern LispObject om_putEndBind(LispObject nil, LispObject ldev);
extern LispObject om_putBVar(LispObject nil, LispObject ldev);
extern LispObject om_putEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_putError(LispObject nil, LispObject ldev);
extern LispObject om_putEndError(LispObject nil, LispObject ldev);
extern LispObject om_putObject(LispObject nil, LispObject ldev);
extern LispObject om_putEndObject(LispObject nil, LispObject ldev);
extern LispObject om_putInt(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putFloat(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putByteArray(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putVar(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putString(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol(LispObject nil, LispObject ldev, LispObject val);
extern LispObject om_putSymbol2(LispObject nil, int nargs, ...);
extern LispObject om_getApp(LispObject nil, LispObject ldev);
extern LispObject om_getEndApp(LispObject nil, LispObject ldev);
extern LispObject om_getAtp(LispObject nil, LispObject ldev);
extern LispObject om_getEndAtp(LispObject nil, LispObject ldev);
extern LispObject om_getAttr(LispObject nil, LispObject ldev);
extern LispObject om_getEndAttr(LispObject nil, LispObject ldev);
extern LispObject om_getBind(LispObject nil, LispObject ldev);
extern LispObject om_getEndBind(LispObject nil, LispObject ldev);
extern LispObject om_getBVar(LispObject nil, LispObject ldev);
extern LispObject om_getEndBVar(LispObject nil, LispObject ldev);
extern LispObject om_getError(LispObject nil, LispObject ldev);
extern LispObject om_getEndError(LispObject nil, LispObject ldev);
extern LispObject om_getObject(LispObject nil, LispObject ldev);
extern LispObject om_getEndObject(LispObject nil, LispObject ldev);
extern LispObject om_getInt(LispObject nil, LispObject ldev);
extern LispObject om_getFloat(LispObject nil, LispObject ldev);
extern LispObject om_getByteArray(LispObject nil, LispObject ldev);
extern LispObject om_getVar(LispObject nil, LispObject ldev);
extern LispObject om_getString(LispObject nil, LispObject ldev);
extern LispObject om_getSymbol(LispObject nil, LispObject ldev);
extern LispObject om_getType(LispObject nil, LispObject ldev);
extern LispObject om_stringToStringPtr(LispObject nil, LispObject lstr);
extern LispObject om_stringPtrToString(LispObject nil, LispObject lpstr);
extern LispObject om_read(LispObject nil, LispObject dev);
extern LispObject om_supportsCD(LispObject nil, LispObject lcd);
extern LispObject om_supportsSymbol(LispObject nil, LispObject lcd, LispObject lsym);
extern LispObject om_listCDs(LispObject nil, int nargs, ...);
extern LispObject om_listSymbols(LispObject nil, LispObject lcd);
extern LispObject om_whichCDs(LispObject nil, LispObject lsym);
#endif
extern LispObject workbase[51];
extern LispObject user_base_0, user_base_1, user_base_2;
extern LispObject user_base_3, user_base_4, user_base_5;
extern LispObject user_base_6, user_base_7, user_base_8;
extern LispObject user_base_9;
#define work_0 workbase[0]
#define work_1 workbase[1]
#define mv_1 workbase[1]
#define mv_2 workbase[2]
#define mv_3 workbase[3]
#define work_50 workbase[50]
extern void copy_into_nilseg(int fg);
extern void copy_out_of_nilseg(int fg);
#define eq_hash_table_list BASE[50] 
#define equal_hash_table_list BASE[51] 
#define current_package_offset 52
extern void rehash_this_table(LispObject v);
extern LispObject eq_hash_tables, equal_hash_tables;
extern LispObject volatile savecodelimit;
extern LispObject * volatile savestacklimit;
extern LispObject volatile saveheaplimit;
extern LispObject volatile savevheaplimit;
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
#define MAX_INPUT_FILES 40 
#define MAX_SYMBOLS_TO_DEFINE 40
#define MAX_FASL_PATHS 20
extern const char *files_to_read[MAX_INPUT_FILES],
 *symbols_to_define[MAX_SYMBOLS_TO_DEFINE],
 *fasl_paths[MAX_FASL_PATHS];
extern int csl_argc;
extern const char **csl_argv;
extern int fasl_output_file, output_directory;
#ifdef BUILTIN_IMAGE
const unsigned char *binary_read_filep;
#else
extern FILE *binary_read_file;
#endif
extern int boffop;
extern void packbyte(int c);
#ifdef HAVE_FWIN
extern char **loadable_packages;
extern char **switches;
extern void review_switch_settings();
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
extern const char *standard_directory;
extern int gc_number;
extern CSLbool gc_method_is_copying;
extern int force_reclaim_method, reclaim_trap_count, reclaim_stack_limit;
#define INIT_QUIET 1
#define INIT_VERBOSE 2
#define INIT_EXPANDABLE 4
#define Lispify_predicate(p) ((p) ? lisp_true : nil)
extern int tty_count;
extern FILE *spool_file;
extern char spool_file_name[32];
typedef struct Ihandle
{ FILE *f; 
 long int o; 
 long int n; 
 uint32_t chk; 
 int status; 
 int nativedir; 
} Ihandle;
extern int32_t compression_worth_while;
#define CODESIZE 0x1000
typedef struct entry_point1
{ one_args *p;
 const char *s;
} entry_point1;
typedef struct entry_point2
{ two_args *p;
 const char *s;
} entry_point2;
typedef struct entry_pointn
{ n_args *p;
 const char *s;
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
extern const char *linker_type;
extern const char *compiler_command[], *import_data[],
 *config_header[], *csl_headers[];
extern LispObject encapsulate_pointer(void *);
extern void *extract_pointer(LispObject a);
extern LispObject Lencapsulatedp(LispObject nil, LispObject a);
typedef void initfn(LispObject *, LispObject **, LispObject * volatile *);
extern int load_dynamic(const char *objname, const char *modname,
 LispObject name, LispObject fns);
extern "C" LispObject Linstate_c_code(LispObject nil,
 LispObject name, LispObject fns);
extern LispObject characterify(LispObject a);
extern LispObject char_to_id(int ch);
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
extern CSLbool open_output(const char *s, int len);
#define IOPEN_OUT 0
#define IOPEN_UNCHECKED 1
#define IOPEN_CHECKED 2
extern CSLbool Iopen(const char *name, int len, int dirn, char *expanded_name);
extern CSLbool Iopen_from_stdin(void), Iopen_to_stdout(void);
extern CSLbool IopenRoot(char *expanded_name, int hard, int sixtyfour);
extern CSLbool Iwriterootp(char *expanded);
extern CSLbool Iopen_help(int32_t offset);
extern CSLbool Iopen_banner(int code);
extern CSLbool Imodulep(const char *name, int len, char *datestamp, int32_t *size,
 char *expanded_name);
extern CSLbool Icopy(const char *name, int len);
extern CSLbool Idelete(const char *name, int len);
extern CSLbool IcloseInput(int check_checksum);
extern CSLbool IcloseOutput(int write_checksum);
extern CSLbool Ifinished(void);
extern int Igetc(void);
extern int32_t Iread(void *buff, int32_t size);
extern CSLbool Iputc(int ch);
extern CSLbool Iwrite(const void *buff, int32_t size);
extern long int Ioutsize(void);
extern const char *CSLtmpdir();
extern const char *CSLtmpnam(const char *suffix, int32_t suffixlen);
extern int Cmkdir(const char *s);
extern char *look_in_lisp_variable(char *o, int prefix);
extern void CSL_MD5_Init(void);
extern void CSL_MD5_Update(const unsigned char *data, int len);
extern void CSL_MD5_Final(unsigned char *md);
extern CSLbool CSL_MD5_busy;
extern unsigned char *CSL_MD5(unsigned char *data, int n, unsigned char *md);
extern void checksum(LispObject a);
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
extern const char *errorset_msg;
extern int errorset_code;
extern void unwind_stack(LispObject *, CSLbool findcatch);
extern CSLbool segvtrap;
extern CSLbool batch_flag;
extern int escaped_printing;
extern void low_level_signal_handler(int code);
extern int async_interrupt(int a);
extern "C" void sigint_handler(int code);
extern "C" void record_get(LispObject tag, CSLbool found);
extern int primep(int32_t);
extern void adjust_all(void);
extern void set_up_functions(CSLbool restartp);
extern void get_user_files_checksum(unsigned char *);
extern "C" LispObject acons(LispObject a, LispObject b, LispObject c);
extern "C" LispObject ash(LispObject a, LispObject b);
extern LispObject bytestream_interpret(LispObject code, LispObject lit,
 LispObject *entry_stack);
extern CSLbool complex_stringp(LispObject a);
extern void freshline_trace(void);
extern void freshline_debug(void);
extern "C" LispObject cons(LispObject a, LispObject b);
extern LispObject cons_no_gc(LispObject a, LispObject b);
extern LispObject cons_gc_test(LispObject a);
extern void convert_fp_rep(void *p, int old_rep, int new_rep, int type);
extern LispObject Ceval(LispObject u, LispObject env);
extern LispObject noisy_Ceval(LispObject u, LispObject env);
extern uint32_t Crand(void);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern void Csrand(uint32_t a, uint32_t b);
extern void discard(LispObject a);
extern "C" CSLbool eql_fn(LispObject a, LispObject b);
extern "C" CSLbool cl_equal_fn(LispObject a, LispObject b);
extern "C" CSLbool equal_fn(LispObject a, LispObject b);
#ifdef TRACED_EQUAL
extern CSLbool traced_equal_fn(LispObject a, LispObject b,
 const char *, int, int);
#define equal_fn(a, b) traced_equal_fn(a, b, __FILE__, __LINE__, 0)
extern void dump_equals();
#endif
extern "C" CSLbool equalp(LispObject a, LispObject b);
extern LispObject apply(LispObject fn, int nargs,
 LispObject env, LispObject fname, int noisy);
extern LispObject apply_lambda(LispObject def, int nargs,
 LispObject env, LispObject name, int noisy);
extern void deallocate_pages(void);
extern void drop_heap_segments(void);
extern LispObject gcd(LispObject a, LispObject b);
extern LispObject get_pname(LispObject a);
#ifdef COMMON
extern "C" LispObject get(LispObject a, LispObject b, LispObject c);
#else
extern "C" LispObject get(LispObject a, LispObject b);
#endif
extern LispObject getvector(int tag, int type, size_t length);
extern LispObject getvector_init(size_t n, LispObject v);
extern LispObject getcodevector(int type, size_t size);
extern uint32_t hash_lisp_string(LispObject s);
extern void lose_C_def(LispObject a);
extern "C" CSLbool geq2(LispObject a, LispObject b);
extern "C" CSLbool greaterp2(LispObject a, LispObject b);
extern "C" CSLbool lesseq2(LispObject a, LispObject b);
extern "C" CSLbool lessp2(LispObject a, LispObject b);
extern "C" LispObject list2(LispObject a, LispObject b);
extern "C" LispObject list2star(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3(LispObject a, LispObject b, LispObject c);
extern "C" LispObject list3star(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject list4(LispObject a, LispObject b,
 LispObject c, LispObject d);
extern "C" LispObject lognot(LispObject a);
extern LispObject macroexpand(LispObject form, LispObject env);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_package(LispObject name);
extern LispObject make_string(const char *b);
extern LispObject make_nstring(const char *b, int32_t n);
extern LispObject make_undefined_symbol(const char *s);
extern LispObject make_symbol(char const *s, int restartp,
 one_args *f1, two_args *f2, n_args *fn);
extern void stdout_printf(const char *fmt, ...);
extern void term_printf(const char *fmt, ...);
extern void err_printf(const char *fmt, ...);
extern void debug_printf(const char *fmt, ...);
extern void trace_printf(const char *fmt, ...);
extern const char *my_getenv(const char *name);
extern "C" LispObject ncons(LispObject a);
extern LispObject ndelete(LispObject a, LispObject b);
extern "C" LispObject negate(LispObject a);
extern LispObject nreverse(LispObject a);
extern FILE *open_file(char *filename, const char *original_name,
 size_t n, const char *dirn, FILE *old_file);
extern "C" LispObject plus2(LispObject a, LispObject b);
extern void preserve(const char *msg, int len);
extern void preserve_native_code(void);
extern void relocate_native_function(unsigned char *bps);
extern LispObject prin(LispObject u);
extern const char *get_string_data(LispObject a, const char *why, size_t *len);
extern void prin_to_stdout(LispObject u);
extern void prin_to_terminal(LispObject u);
extern void prin_to_debug(LispObject u);
extern void prin_to_query(LispObject u);
extern void prin_to_trace(LispObject u);
extern void prin_to_error(LispObject u);
extern void loop_print_stdout(LispObject o);
extern void loop_print_terminal(LispObject o);
extern void loop_print_debug(LispObject o);
extern void loop_print_query(LispObject o);
extern void loop_print_trace(LispObject o);
extern void loop_print_error(LispObject o);
extern void internal_prin(LispObject u, int prefix);
extern LispObject princ(LispObject u);
extern LispObject print(LispObject u);
extern LispObject printc(LispObject u);
extern void print_bignum(LispObject u, CSLbool blankp, int nobreak);
extern void print_bighexoctbin(LispObject u,
 int radix, int width, CSLbool blankp, int nobreak);
extern LispObject putprop(LispObject a, LispObject b,
 LispObject c);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern "C" LispObject rational(LispObject a);
extern void read_eval_print(int noisy);
extern "C" LispObject reclaim(LispObject value_to_return, const char *why,
 int stg_class, intptr_t size);
#ifdef DEBUG
extern void validate_all(const char *why, int line, const char *file);
extern int check_env(LispObject env);
#endif
extern CSLbool do_not_kill_native_code;
extern void set_fns(LispObject sym, one_args *f1,
 two_args *f2, n_args *fn);
extern void setup(int restartp, double storesize);
extern LispObject simplify_string(LispObject s);
extern CSLbool stringp(LispObject a);
extern "C" LispObject times2(LispObject a, LispObject b);
extern int32_t thirty_two_bits(LispObject a);
#ifdef HAVE_INT64_T
extern int64_t sixty_four_bits(LispObject a);
#endif
#ifdef DEBUG
extern void validate_string_fn(LispObject a, const char *f, int l);
#define validate_string(a) validate_string_fn(a, __FILE__, __LINE__)
#else
#define validate_string(a) 
#endif
#ifdef COMMON
#define onevalue(r) (exit_count=1, (r))
#define nvalues(r, n) (exit_count=(n), (r))
#else
#define onevalue(r) (r)
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
#define equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 equal_fn(a, b)))
#define cl_equal(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
 cl_equal_fn(a, b)))
#define eql(a, b) \
 ((a) == (b) || \
 (((((a) ^ (b)) & TAG_BITS) == 0) && \
 ((unsigned)(((a) & TAG_BITS) - 1) > 3) && \
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
extern n_args *zero_arg_functions[];
extern one_args *one_arg_functions[];
extern two_args *two_arg_functions[];
extern n_args *three_arg_functions[];
extern void *useful_functions[];
extern char *address_of_var(int n);
typedef struct setup_type
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
} setup_type;
typedef struct setup_type_1
{ const char *name;
 one_args *one;
 two_args *two;
 n_args *n;
 uint32_t c1;
 uint32_t c2;
} setup_type_1;
extern setup_type const
arith06_setup[], arith08_setup[], arith10_setup[], arith12_setup[],
 arith13_setup[], char_setup[], eval1_setup[], eval2_setup[],
 eval3_setup[], funcs1_setup[], funcs2_setup[], funcs3_setup[],
 print_setup[], read_setup[], mpi_setup[];
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
extern const char *find_image_directory(int argc, const char *argv[]);
extern char program_name[64];
extern LispObject declare_fn(LispObject args, LispObject env);
extern LispObject function_fn(LispObject args, LispObject env);
extern LispObject let_fn_1(LispObject bvl, LispObject body,
 LispObject env, int compilerp, int noisy);
extern LispObject mv_call_fn(LispObject args, LispObject env);
extern LispObject noisy_mv_call_fn(LispObject args, LispObject env);
extern LispObject progn_fn(LispObject args, LispObject env);
extern LispObject noisy_progn_fn(LispObject args, LispObject env);
extern LispObject quote_fn(LispObject args, LispObject env);
extern LispObject tagbody_fn(LispObject args, LispObject env);
extern LispObject noisy_tagbody_fn(LispObject args, LispObject env);
extern LispObject resource_exceeded();
extern int64_t time_base, space_base, io_base, errors_base;
extern int64_t time_now, space_now, io_now, errors_now;
extern int64_t time_limit, space_limit, io_limit, errors_limit;
extern CSLbool symbol_protect_flag, warn_about_protected_symbols;
#ifdef JIT
extern char *Jcompile(LispObject def, LispObject env);
extern unsigned long jit_size;
#define JIT_INIT_SIZE 8192
#endif
#endif 
#ifndef header_arith_h
#define header_arith_h 1
#define TWO_32 4294967296.0 
#define TWO_31 2147483648.0 
#define TWO_24 16777216.0 
#define TWO_22 4194304.0 
#define TWO_21 2097152.0 
#define TWO_20 1048576.0 
#define M2_31_1 -2147483649.0 
#define _pi ((12868.0 - 0.036490896206895257)/4096.0)
#define _half_pi ((12868.0 - 0.036490896206895257)/8192.0)
#define boole_clr 0
#define boole_and 1
#define boole_andc2 2
#define boole_1 3
#define boole_andc1 4
#define boole_2 5
#define boole_xor 6
#define boole_ior 7
#define boole_nor 8
#define boole_eqv 9
#define boole_c2 10
#define boole_orc2 11
#define boole_c1 12
#define boole_orc1 13
#define boole_nand 14
#define boole_set 15
#define top_bit_set(n) (((int32_t)(n)) < 0)
#define top_bit(n) (((uint32_t)(n)) >> 31)
#define set_top_bit(n) ((n) | (uint32_t)0x80000000)
#define clear_top_bit(n) ((n) & 0x7fffffff)
#define signed_overflow(n) top_bit_set((n) ^ (((int32_t)(n))<<1))
#ifdef HAVE_UINT64_T
#define IMULTIPLY 1 
#define Dmultiply(hi, lo, a, b, c) \
 do { uint64_t r64 = (uint64_t)(a) * (uint64_t)(b) + \
 (uint32_t)(c); \
 (lo) = 0x7fffffffu & (uint32_t)r64; \
 (hi) = (uint32_t)(r64 >> 31); } while (0)
#define IDIVIDE 1
#define Ddivide(r, q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9(r, q, a, b) Ddivide(r, q, a, b, 1000000000u)
#define Ddivideq(q, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 q = (uint32_t)(r64 / c64); } while (0)
#define Ddiv10_9q(r, q, a, b) Ddivideq(q, a, b, 1000000000u)
#define Ddivider(r, a, b, c) \
 do { uint64_t r64 = (((uint64_t)(a)) << 31) | (uint64_t)(b); \
 uint64_t c64 = (uint64_t)(uint32_t)(c); \
 r = (uint32_t)(r64 % c64); } while (0)
#define Ddiv10_9r(r, q, a, b) Ddivider(r, a, b, 1000000000u)
#else
#define Dmultiply(hi, lo, a, b, c) ((hi) = Imultiply(&(lo), (a), (b), (c)))
#define Ddivide(r, q, a, b, c) ((r) = Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9(r, q, a, b) ((r) = Idiv10_9(&(q), (a), (b)))
#define Ddivideq(q, a, b, c) (Idivide(&(q), (a), (b), (c)))
#define Ddiv10_9q(q, a, b) (Idiv10_9(&(q), (a), (b)))
#define Ddivider(r, a, b, c) ((r) = Idivide(NULL, (a), (b), (c)))
#define Ddiv10_9r(r, a, b) ((r) = Idiv10_9(NULL, (a), (b)))
#endif
#define fix_mask (-0x08000000)
#define fixnum_minusp(a) ((int32_t)(a) < 0)
#define bignum_minusp(a) \
 ((int32_t)bignum_digits(a)[((bignum_length(a)-CELL)/4)-1]<0)
extern LispObject negateb(LispObject);
extern LispObject copyb(LispObject);
extern LispObject negate(LispObject);
extern LispObject plus2(LispObject a, LispObject b);
extern "C" LispObject difference2(LispObject a, LispObject b);
extern LispObject times2(LispObject a, LispObject b);
extern "C" LispObject quot2(LispObject a, LispObject b);
extern LispObject CLquot2(LispObject a, LispObject b);
extern LispObject quotbn(LispObject a, int32_t n);
extern LispObject quotbn1(LispObject a, int32_t n);
extern LispObject quotbb(LispObject a, LispObject b);
extern "C" LispObject Cremainder(LispObject a, LispObject b);
extern LispObject rembi(LispObject a, LispObject b);
extern LispObject rembb(LispObject a, LispObject b);
extern LispObject shrink_bignum(LispObject a, int32_t lena);
extern LispObject modulus(LispObject a, LispObject b);
extern LispObject rational(LispObject a);
extern LispObject rationalize(LispObject a);
extern LispObject lcm(LispObject a, LispObject b);
extern LispObject lengthen_by_one_bit(LispObject a, int32_t msd);
extern CSLbool numeq2(LispObject a, LispObject b);
extern "C" CSLbool zerop(LispObject a);
extern CSLbool onep(LispObject a);
extern CSLbool minusp(LispObject a);
extern CSLbool plusp(LispObject a);
extern CSLbool lesspbd(LispObject a, double b);
extern CSLbool lessprd(LispObject a, double b);
extern CSLbool lesspdb(double a, LispObject b);
extern CSLbool lesspdr(double a, LispObject b);
extern LispObject make_one_word_bignum(int32_t n);
extern LispObject make_two_word_bignum(int32_t a, uint32_t b);
extern LispObject make_three_word_bignum(int32_t a, uint32_t b, uint32_t c);
extern LispObject make_n_word_bignum(int32_t a1, uint32_t a2,
 uint32_t a3, int32_t n);
extern LispObject make_lisp_integer32(int32_t n);
extern LispObject make_lisp_integer64(int64_t n);
extern LispObject make_sfloat(double d);
extern double float_of_integer(LispObject a);
extern "C" LispObject add1(LispObject p);
extern "C" LispObject sub1(LispObject p);
extern "C" LispObject integerp(LispObject p);
extern double float_of_number(LispObject a);
extern LispObject make_boxfloat(double a, int32_t type);
extern LispObject make_complex(LispObject r, LispObject i);
extern LispObject make_ratio(LispObject p, LispObject q);
extern "C" LispObject ash(LispObject a, LispObject b);
extern "C" LispObject lognot(LispObject a);
extern LispObject logior2(LispObject a, LispObject b);
extern LispObject logxor2(LispObject a, LispObject b);
extern LispObject logand2(LispObject a, LispObject b);
extern LispObject logeqv2(LispObject a, LispObject b);
extern LispObject rationalf(double d);
extern int _reduced_exp(double, double *);
extern CSLbool lesspbi(LispObject a, LispObject b);
extern CSLbool lesspib(LispObject a, LispObject b);
typedef struct Complex
{ double real;
 double imag;
} Complex;
extern Complex Cln(Complex a);
extern Complex Ccos(Complex a);
extern Complex Cexp(Complex a);
extern Complex Cpow(Complex a, Complex b);
extern double Cabs(Complex a);
#if defined HAVE_LIBPTHREAD || defined WIN32
#include <semaphore.h>
#ifdef WIN32
#include <windows.h>
extern HANDLE kara_thread1, kara_thread2;
#define KARARESULT DWORD
#define KARAARG LPVOID
extern KARARESULT WINAPI kara_worker1(KARAARG p);
extern KARARESULT WINAPI kara_worker2(KARAARG p);
#else
#include <pthread.h>
extern pthread_t kara_thread1, kara_thread2;
#define KARARESULT void *
#define KARAARG void *
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
# define KARATSUBA_PARALLEL_CUTOFF 120
#endif
#endif 
#ifndef KARATSUBA_CUTOFF
#define KARATSUBA_CUTOFF 12
#endif
#endif 
#ifndef header_entries_h
#define header_entries_h 1
extern "C" LispObject Lbatchp(LispObject env, int nargs, ...);
extern "C" LispObject bytecounts(LispObject nil, int nargs, ...);
extern "C" LispObject Ldate(LispObject env, int nargs, ...);
extern "C" LispObject Ldatestamp(LispObject nil, int nargs, ...);
extern "C" LispObject Leject(LispObject env, int nargs, ...);
extern "C" LispObject Lerror(LispObject env, int nargs, ...);
extern "C" LispObject Lerror0(LispObject env, int nargs, ...);
extern "C" LispObject Lflush(LispObject nil, int nargs, ...);
extern "C" LispObject Lgc0(LispObject nil, int nargs, ...);
extern "C" LispObject Lgctime(LispObject env, int nargs, ...);
extern "C" LispObject Lgensym(LispObject env, int nargs, ...);
extern "C" LispObject Llist_modules(LispObject env, int nargs, ...);
extern "C" LispObject Llibrary_members0(LispObject env, int nargs, ...);
extern "C" LispObject Llposn(LispObject env, int nargs, ...);
extern "C" LispObject Lmapstore0(LispObject env, int nargs, ...);
extern "C" LispObject Lnext_random(LispObject env, int nargs, ...);
extern "C" LispObject Lposn(LispObject env, int nargs, ...);
extern "C" LispObject Lread(LispObject env, int nargs, ...);
extern "C" LispObject Lreadch(LispObject env, int nargs, ...);
extern "C" LispObject Lrtell(LispObject nil, int nargs, ...);
extern "C" LispObject Lterpri(LispObject env, int nargs, ...);
extern "C" LispObject Ltime(LispObject env, int nargs, ...);
extern "C" LispObject Ltmpnam(LispObject nil, int nargs, ...);
extern "C" LispObject Ltyi(LispObject env, int nargs, ...);
extern "C" LispObject autoload1(LispObject env, LispObject a1);
extern "C" LispObject bytecoded1(LispObject env, LispObject a);
extern "C" LispObject bytecounts1(LispObject env, LispObject a);
extern "C" LispObject byteopt1(LispObject def, LispObject a);
extern "C" LispObject byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_bytecoded1(LispObject env, LispObject a);
extern "C" LispObject double_byteopt1(LispObject def, LispObject a);
extern "C" LispObject double_byteoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_funarged1(LispObject env, LispObject a1);
extern "C" LispObject double_hardopt1(LispObject def, LispObject a);
extern "C" LispObject double_hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject double_interpreted1(LispObject env, LispObject a1);
extern "C" LispObject funarged1(LispObject env, LispObject a1);
extern "C" LispObject tracefunarged1(LispObject env, LispObject a1);
extern "C" LispObject tracesetfunarged1(LispObject env, LispObject a1);
extern "C" LispObject hardopt1(LispObject def, LispObject a);
extern "C" LispObject hardoptrest1(LispObject def, LispObject a);
extern "C" LispObject interpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracesetbytecoded1(LispObject env, LispObject a);
extern "C" LispObject jitcompileme1(LispObject env, LispObject a);
extern "C" LispObject tracebyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracesetbyteopt1(LispObject def, LispObject a);
extern "C" LispObject tracebyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracesetbyteoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracebytecoded1(LispObject env, LispObject a);
extern "C" LispObject tracesetbytecoded1(LispObject env, LispObject a);
extern "C" LispObject traceinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracesetinterpreted1(LispObject env, LispObject a1);
extern "C" LispObject tracehardopt1(LispObject def, LispObject a);
extern "C" LispObject tracesethardopt1(LispObject def, LispObject a);
extern "C" LispObject tracehardoptrest1(LispObject def, LispObject a);
extern "C" LispObject tracesethardoptrest1(LispObject def, LispObject a);
extern "C" LispObject undefined1(LispObject env, LispObject a1);
extern "C" LispObject f1_as_0(LispObject env, LispObject a);
extern "C" LispObject f1_as_1(LispObject env, LispObject a);
#ifdef CJAVA
extern "C" LispObject java1(LispObject env, LispObject a);
#endif
extern "C" LispObject Labsval(LispObject env, LispObject a);
extern "C" LispObject Ladd1(LispObject env, LispObject a);
extern "C" LispObject Lalpha_char_p(LispObject env, LispObject a);
extern "C" LispObject Lapply0(LispObject env, LispObject a);
extern "C" LispObject Lapply_1(LispObject env, LispObject fn);
extern "C" LispObject Latan(LispObject env, LispObject a);
extern "C" LispObject Latom(LispObject env, LispObject a);
extern "C" LispObject Lbanner(LispObject env, LispObject a);
extern "C" LispObject Lboundp(LispObject env, LispObject a);
extern "C" LispObject Lbpsp(LispObject nil, LispObject a);
extern "C" LispObject Lbpsupbv(LispObject nil, LispObject v);
extern "C" LispObject Lcaaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaaar(LispObject env, LispObject a);
extern "C" LispObject Lcaadar(LispObject env, LispObject a);
extern "C" LispObject Lcaaddr(LispObject env, LispObject a);
extern "C" LispObject Lcaadr(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcaar(LispObject env, LispObject a);
extern "C" LispObject Lcadaar(LispObject env, LispObject a);
extern "C" LispObject Lcadadr(LispObject env, LispObject a);
extern "C" LispObject Lcadar(LispObject env, LispObject a);
extern "C" LispObject Lcaddar(LispObject env, LispObject a);
extern "C" LispObject Lcadddr(LispObject env, LispObject a);
extern "C" LispObject Lcaddr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcadr(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcar(LispObject env, LispObject a);
extern "C" LispObject Lcdaaar(LispObject env, LispObject a);
extern "C" LispObject Lcdaadr(LispObject env, LispObject a);
extern "C" LispObject Lcdaar(LispObject env, LispObject a);
extern "C" LispObject Lcdadar(LispObject env, LispObject a);
extern "C" LispObject Lcdaddr(LispObject env, LispObject a);
extern "C" LispObject Lcdadr(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcdar(LispObject env, LispObject a);
extern "C" LispObject Lcddaar(LispObject env, LispObject a);
extern "C" LispObject Lcddadr(LispObject env, LispObject a);
extern "C" LispObject Lcddar(LispObject env, LispObject a);
extern "C" LispObject Lcdddar(LispObject env, LispObject a);
extern "C" LispObject Lcddddr(LispObject env, LispObject a);
extern "C" LispObject Lcdddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcddr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lcdr(LispObject env, LispObject a);
extern "C" LispObject Lchar_code(LispObject env, LispObject a);
extern "C" LispObject Lclose(LispObject env, LispObject a);
extern "C" LispObject Lcodep(LispObject env, LispObject a);
extern "C" LispObject Lcompress(LispObject env, LispObject a);
extern "C" LispObject Lconsp(LispObject env, LispObject a);
extern "C" LispObject Lconstantp(LispObject env, LispObject a);
extern "C" LispObject Lcopy_module(LispObject env, LispObject a);
extern "C" LispObject Ldefine_in_module(LispObject env, LispObject a);
extern "C" LispObject Ldelete_module(LispObject env, LispObject a);
extern "C" LispObject Ldigitp(LispObject env, LispObject a);
extern "C" LispObject Lendp(LispObject env, LispObject a);
extern "C" LispObject Lerror1(LispObject nil, LispObject a1);
extern "C" LispObject Lerrorset1(LispObject nil, LispObject form);
extern "C" LispObject Leval(LispObject env, LispObject a);
extern "C" LispObject Levenp(LispObject env, LispObject a);
extern "C" LispObject Levlis(LispObject env, LispObject a);
extern "C" LispObject Lexplode(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lc(LispObject env, LispObject a);
extern "C" LispObject Lexplode2lcn(LispObject nil, LispObject a);
extern "C" LispObject Lexplode2n(LispObject env, LispObject a);
extern "C" LispObject Lexplodec(LispObject env, LispObject a);
extern "C" LispObject Lexplodecn(LispObject env, LispObject a);
extern "C" LispObject Lexplodehex(LispObject nil, LispObject a);
extern "C" LispObject Lexploden(LispObject env, LispObject a);
extern "C" LispObject Lexplodeoctal(LispObject nil, LispObject a);
extern "C" LispObject Lfixp(LispObject env, LispObject a);
extern "C" LispObject Lfloat(LispObject env, LispObject a);
extern "C" LispObject Lfloatp(LispObject env, LispObject a);
extern "C" LispObject Lfrexp(LispObject nil, LispObject a);
extern "C" LispObject Lfuncall1(LispObject env, LispObject fn);
extern "C" LispObject Lgc(LispObject nil, LispObject a);
extern "C" LispObject Lgensym1(LispObject env, LispObject a);
extern "C" LispObject Lgensym2(LispObject env, LispObject a);
extern "C" LispObject Lgetd(LispObject env, LispObject a);
extern "C" LispObject Lgetenv(LispObject env, LispObject a);
extern "C" LispObject Lget_bps(LispObject env, LispObject a);
extern "C" LispObject Lhelp(LispObject nil, LispObject a);
extern "C" LispObject Liadd1(LispObject env, LispObject a);
extern "C" LispObject Lidentity(LispObject env, LispObject a);
extern "C" LispObject Liminus(LispObject env, LispObject a);
extern "C" LispObject Liminusp(LispObject env, LispObject a);
extern "C" LispObject Lindirect(LispObject env, LispObject a);
extern "C" LispObject Lintegerp(LispObject env, LispObject a);
extern "C" LispObject Lintern(LispObject env, LispObject a);
extern "C" LispObject Lionep(LispObject nil, LispObject a);
extern "C" LispObject Lisub1(LispObject env, LispObject a);
extern "C" LispObject Lizerop(LispObject nil, LispObject a);
extern "C" LispObject Llength(LispObject env, LispObject a);
extern "C" LispObject Llengthc(LispObject env, LispObject a);
extern "C" LispObject Llibrary_members(LispObject nil, LispObject a);
extern "C" LispObject Llinelength(LispObject env, LispObject a);
extern "C" LispObject Llist_to_string(LispObject env, LispObject a);
extern "C" LispObject Llist_to_vector(LispObject env, LispObject a);
extern "C" LispObject Lload_module(LispObject env, LispObject a);
extern "C" LispObject Lload_source(LispObject env, LispObject a);
extern "C" LispObject Llognot(LispObject env, LispObject a);
extern "C" LispObject Llog_1(LispObject nil, LispObject a);
extern "C" LispObject Llsd(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand(LispObject env, LispObject a);
extern "C" LispObject Lmacroexpand_1(LispObject env, LispObject a);
extern "C" LispObject Lmacro_function(LispObject env, LispObject a);
extern "C" LispObject Lmake_global(LispObject env, LispObject a);
extern "C" LispObject Lmake_special(LispObject env, LispObject a);
extern "C" LispObject Lmapstore(LispObject env, LispObject a);
extern "C" LispObject Lmd5(LispObject env, LispObject a1);
extern "C" LispObject Lmd60(LispObject env, LispObject a1);
extern "C" LispObject Lminus(LispObject env, LispObject a);
extern "C" LispObject Lminusp(LispObject env, LispObject a);
extern "C" LispObject Lmkevect(LispObject nil, LispObject n);
extern "C" LispObject Lmkquote(LispObject env, LispObject a);
extern "C" LispObject Lmkvect(LispObject env, LispObject a);
extern "C" LispObject Lmodular_minus(LispObject env, LispObject a);
extern "C" LispObject Lmodular_number(LispObject env, LispObject a);
extern "C" LispObject Lmodular_reciprocal(LispObject env, LispObject a);
extern "C" LispObject Lmodule_exists(LispObject env, LispObject a);
extern "C" LispObject Lmsd(LispObject env, LispObject a);
extern "C" LispObject Lmv_list(LispObject nil, LispObject a);
extern "C" LispObject Lncons(LispObject env, LispObject a);
extern "C" LispObject Lnreverse(LispObject env, LispObject a);
extern "C" LispObject Lnull(LispObject env, LispObject a);
extern "C" LispObject Lnumberp(LispObject env, LispObject a);
extern "C" LispObject Loddp(LispObject env, LispObject a);
extern "C" LispObject Lonep(LispObject env, LispObject a);
extern "C" LispObject Lpagelength(LispObject env, LispObject a);
extern "C" LispObject Lplist(LispObject env, LispObject a);
extern "C" LispObject Lplusp(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin(LispObject env, LispObject a);
extern "C" LispObject Lprin2a(LispObject nil, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprinc(LispObject env, LispObject a);
extern "C" LispObject Lprint(LispObject env, LispObject a);
extern "C" LispObject Lprintc(LispObject env, LispObject a);
extern "C" LispObject Lrandom(LispObject env, LispObject a);
extern "C" LispObject Lrational(LispObject env, LispObject a);
extern "C" LispObject Lrdf1(LispObject env, LispObject a);
extern "C" LispObject Lrds(LispObject env, LispObject a);
extern "C" LispObject Lremd(LispObject env, LispObject a);
extern "C" LispObject Lreverse(LispObject env, LispObject a);
extern "C" LispObject Lsetpchar(LispObject env, LispObject a);
extern "C" LispObject Lset_small_modulus(LispObject env, LispObject a);
extern "C" LispObject Lsmkvect(LispObject env, LispObject a);
extern "C" LispObject Lspecial_char(LispObject env, LispObject a);
extern "C" LispObject Lspecial_form_p(LispObject env, LispObject a);
extern "C" LispObject Lspool(LispObject env, LispObject a);
extern "C" LispObject Lstart_module(LispObject env, LispObject a);
extern "C" LispObject Lstop(LispObject env, LispObject a);
extern "C" LispObject Lstringp(LispObject env, LispObject a);
extern "C" LispObject Lsub1(LispObject env, LispObject a);
extern "C" LispObject Lsymbolp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcount(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_argcode(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_env(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_function(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_globalp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_name(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_restore_fns(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_specialp(LispObject env, LispObject a);
extern "C" LispObject Lsymbol_value(LispObject env, LispObject a);
extern "C" LispObject Lsystem(LispObject env, LispObject a);
extern "C" LispObject Lthreevectorp(LispObject env, LispObject a);
extern "C" LispObject Lthrow_nil(LispObject env, LispObject a);
extern "C" LispObject Ltrace(LispObject env, LispObject a);
extern "C" LispObject Ltraceset(LispObject env, LispObject a);
extern "C" LispObject Ltruncate(LispObject env, LispObject a);
extern "C" LispObject Lttab(LispObject env, LispObject a);
extern "C" LispObject Ltyo(LispObject env, LispObject a);
extern "C" LispObject Lunintern(LispObject env, LispObject a);
extern "C" LispObject Lunmake_global(LispObject env, LispObject a);
extern "C" LispObject Lunmake_special(LispObject env, LispObject a);
extern "C" LispObject Luntrace(LispObject env, LispObject a);
extern "C" LispObject Lupbv(LispObject env, LispObject a);
extern "C" LispObject Lsimple_vectorp(LispObject env, LispObject a);
extern "C" LispObject Lvectorp(LispObject env, LispObject a);
extern "C" LispObject Lverbos(LispObject env, LispObject a);
extern "C" LispObject Lwhitespace_char_p(LispObject env, LispObject a);
extern "C" LispObject Lwritable_libraryp(LispObject env, LispObject a);
extern "C" LispObject Lwrite_module(LispObject env, LispObject a);
extern "C" LispObject Lwrs(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lxtab(LispObject env, LispObject a);
extern "C" LispObject Lzerop(LispObject env, LispObject a);
#ifdef COMMON
extern "C" LispObject Lfind_symbol_1(LispObject nil, LispObject str);
extern "C" LispObject Llistp(LispObject env, LispObject a);
#endif
extern "C" LispObject autoload2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_bytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject double_byteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_byteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject double_hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject double_interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject funarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracefunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracesetfunarged2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject hardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject hardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject interpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracebyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesetbyteopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesetbyteoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracebytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject tracesetbytecoded2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject jitcompileme2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject traceinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracesetinterpreted2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject tracehardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesethardopt2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracehardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject tracesethardoptrest2(LispObject def, LispObject a, LispObject b);
extern "C" LispObject undefined2(LispObject env, LispObject a1, LispObject a2);
extern "C" LispObject f2_as_0(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject f2_as_2(LispObject env, LispObject a, LispObject b);
#ifdef CJAVA
extern "C" LispObject java2(LispObject env, LispObject a, LispObject b);
#endif
extern "C" LispObject Lappend(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lapply_2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lapply1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lash1(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lassoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan2d(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latsoc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lbpsgetv(LispObject nil, LispObject v, LispObject n);
extern "C" LispObject Lcons(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lcopy_native(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldeleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldelete(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldifference2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ldivide(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequalcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leql(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Leqn(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lcl_equal(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lequal(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lerror2(LispObject nil, LispObject a1, LispObject a2);
extern "C" LispObject Lerrorset2(LispObject nil, LispObject form, LispObject ffg1);
extern "C" LispObject Lexpt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lflagpcar(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfuncall2(LispObject env, LispObject fn, LispObject a1);
extern "C" LispObject Lgcd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgeq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lget_hash_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lgreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lhelp_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lidifference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ligeq(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Ligreaterp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lileq(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lilessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limax(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Limin(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Linorm(LispObject nil, LispObject a, LispObject k);
extern "C" LispObject Linstate_c_code(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lintersect(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Liplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Liremainder(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lirightshift(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Litimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llcm(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lleq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llessp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llist2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Llog_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmake_random_state(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lmax2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmember(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmin2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmod(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_difference(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_expt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_plus(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_quotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmodular_times(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnconc(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lneq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lnreverse2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lorderp(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lpair(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lplus2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lquotient(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrem(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremflag(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lremprop(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lresource_limit2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplaca(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrplacd(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrseek(LispObject nil, LispObject a);
extern "C" LispObject Lset(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lset_help_file(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lsgetv(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsmemq(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsubla(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsublis(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_protect(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_definition(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lsymbol_set_env(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lthrow_one_value(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Ltimes2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunion(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lwrite_help_module(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lxcons(LispObject env, LispObject a, LispObject b);
#ifdef COMMON
extern "C" LispObject Laref2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Latan_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lelt(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lfloat_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Lintern_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_1_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lmacroexpand_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lrandom_2(LispObject nil, LispObject a, LispObject b);
extern "C" LispObject Ltruncate_2(LispObject env, LispObject a, LispObject b);
extern "C" LispObject Lunintern_2(LispObject env, LispObject a, LispObject b);
#endif
extern "C" LispObject autoloadn(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_bytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject double_bytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject double_bytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject double_byteoptn(LispObject def, int nargs, ...);
extern "C" LispObject double_byteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_funargedn(LispObject env, int nargs, ...);
extern "C" LispObject double_hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject double_hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject double_interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject funargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracefunargedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetfunargedn(LispObject env, int nargs, ...);
extern "C" LispObject hardoptn(LispObject def, int nargs, ...);
extern "C" LispObject hardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject interpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracebyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracesetbyteoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracebyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracesetbyteoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracebytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecoded0(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecoded3(LispObject env, int nargs, ...);
extern "C" LispObject tracebytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetbytecodedn(LispObject env, int nargs, ...);
extern "C" LispObject jitcompileme0(LispObject env, int nargs, ...);
extern "C" LispObject jitcompileme3(LispObject env, int nargs, ...);
extern "C" LispObject jitcompilemen(LispObject env, int nargs, ...);
extern "C" LispObject traceinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracesetinterpretedn(LispObject env, int nargs, ...);
extern "C" LispObject tracehardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracesethardoptn(LispObject def, int nargs, ...);
extern "C" LispObject tracehardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject tracesethardoptrestn(LispObject def, int nargs, ...);
extern "C" LispObject undefinedn(LispObject env, int nargs, ...);
extern "C" LispObject f0_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_0(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_1(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_2(LispObject env, int nargs, ...);
extern "C" LispObject f3_as_3(LispObject env, int nargs, ...);
#ifdef CJAVA
extern "C" LispObject java0(LispObject env, int nargs, ...);
extern "C" LispObject java3(LispObject env, int nargs, ...);
extern "C" LispObject javan(LispObject env, int nargs, ...);
#endif
extern "C" LispObject Lacons(LispObject env, int nargs, ...);
extern "C" LispObject Lapply_n(LispObject env, int nargs, ...);
extern "C" LispObject Lapply2(LispObject env, int nargs, ...);
extern "C" LispObject Lapply3(LispObject env, int nargs, ...);
extern "C" LispObject Lbpsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lerrorset3(LispObject nil, int nargs, ...);
extern "C" LispObject Lerrorsetn(LispObject env, int nargs, ...);
extern "C" LispObject Lfuncalln(LispObject env, int nargs, ...);
extern "C" LispObject Lhelp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llist(LispObject env, int nargs, ...);
extern "C" LispObject Llist2star(LispObject env, int nargs, ...);
extern "C" LispObject Llist3(LispObject env, int nargs, ...);
extern "C" LispObject Llogand(LispObject env, int nargs, ...);
extern "C" LispObject Llogeqv(LispObject env, int nargs, ...);
extern "C" LispObject Llogor(LispObject env, int nargs, ...);
extern "C" LispObject Llogxor(LispObject env, int nargs, ...);
extern "C" LispObject Lmax(LispObject env, int nargs, ...);
extern "C" LispObject Lmin(LispObject env, int nargs, ...);
extern "C" LispObject Lmkhash(LispObject nil, int nargs, ...);
extern "C" LispObject Lput_hash(LispObject env, int nargs, ...);
extern "C" LispObject Lputprop(LispObject env, int nargs, ...);
extern "C" LispObject Lputv(LispObject env, int nargs, ...);
extern "C" LispObject Lresource_limitn(LispObject env, int nargs, ...);
extern "C" LispObject Lsputv(LispObject env, int nargs, ...);
extern "C" LispObject Lsubst(LispObject env, int nargs, ...);
extern "C" LispObject Lvalues(LispObject env, int nargs, ...);
#ifdef COMMON
extern "C" LispObject Lappend_n(LispObject nil, int nargs, ...);
extern "C" LispObject Laref(LispObject env, int nargs, ...);
extern "C" LispObject Laset(LispObject env, int nargs, ...);
extern "C" LispObject Leqn_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lgcd_n(LispObject env, int nargs, ...);
extern "C" LispObject Lgeq_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lget_3(LispObject env, int nargs, ...);
extern "C" LispObject Lgreaterp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llcm_n(LispObject env, int nargs, ...);
extern "C" LispObject Lleq_n(LispObject nil, int nargs, ...);
extern "C" LispObject Llessp_n(LispObject nil, int nargs, ...);
extern "C" LispObject Lquotient_n(LispObject nil, int nargs, ...);
#endif
#ifdef OPENMATH
extern "C" LispObject om_openFileDev(LispObject env, int nargs, ...);
extern "C" LispObject om_openStringDev(LispObject nil, LispObject lstr, LispObject lenc);
extern "C" LispObject om_closeDev(LispObject env, LispObject dev);
extern "C" LispObject om_setDevEncoding(LispObject nil, LispObject ldev, LispObject lenc);
extern "C" LispObject om_makeConn(LispObject nil, LispObject ltimeout);
extern "C" LispObject om_closeConn(LispObject nil, LispObject lconn);
extern "C" LispObject om_getConnInDevice(LispObject nil, LispObject lconn);
extern "C" LispObject om_getConnOutDevice(LispObject nil, LispObject lconn);
extern "C" LispObject om_connectTCP(LispObject nil, int nargs, ...);
extern "C" LispObject om_bindTCP(LispObject nil, LispObject lconn, LispObject lport);
extern "C" LispObject om_putApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_putAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_putBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_putBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_putError(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndError(LispObject nil, LispObject ldev);
extern "C" LispObject om_putObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_putEndObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_putInt(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putFloat(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putByteArray(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putVar(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putString(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol(LispObject nil, LispObject ldev, LispObject val);
extern "C" LispObject om_putSymbol2(LispObject nil, int nargs, ...);
extern "C" LispObject om_getApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndApp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndAtp(LispObject nil, LispObject ldev);
extern "C" LispObject om_getAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndAttr(LispObject nil, LispObject ldev);
extern "C" LispObject om_getBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndBind(LispObject nil, LispObject ldev);
extern "C" LispObject om_getBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndBVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getError(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndError(LispObject nil, LispObject ldev);
extern "C" LispObject om_getObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_getEndObject(LispObject nil, LispObject ldev);
extern "C" LispObject om_getInt(LispObject nil, LispObject ldev);
extern "C" LispObject om_getFloat(LispObject nil, LispObject ldev);
extern "C" LispObject om_getByteArray(LispObject nil, LispObject ldev);
extern "C" LispObject om_getVar(LispObject nil, LispObject ldev);
extern "C" LispObject om_getString(LispObject nil, LispObject ldev);
extern "C" LispObject om_getSymbol(LispObject nil, LispObject ldev);
extern "C" LispObject om_getType(LispObject nil, LispObject ldev);
extern "C" LispObject om_stringToStringPtr(LispObject nil, LispObject lstr);
extern "C" LispObject om_stringPtrToString(LispObject nil, LispObject lpstr);
extern "C" LispObject om_read(LispObject nil, LispObject dev);
extern "C" LispObject om_supportsCD(LispObject nil, LispObject lcd);
extern "C" LispObject om_supportsSymbol(LispObject nil, LispObject lcd, LispObject lsym);
extern "C" LispObject om_listCDs(LispObject nil, int nargs, ...);
extern "C" LispObject om_listSymbols(LispObject nil, LispObject lcd);
extern "C" LispObject om_whichCDs(LispObject nil, LispObject lsym);
#endif
#endif 



// Code for inszzz

static LispObject CC_inszzz(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0022, v0023;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for inszzz");
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
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0001;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0024;

v0024:
    v0022 = stack[-1];
    if (v0022 == nil) goto v0025;
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0023 = qcar(v0022);
    v0022 = stack[-2];
    v0022 = qcar(v0022);
    v0022 = (LispObject)lessp2(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    v0022 = v0022 ? lisp_true : nil;
    env = stack[-4];
    goto v0027;

v0027:
    if (v0022 == nil) goto v0028;
    stack[0] = stack[-3];
    v0023 = stack[-2];
    v0022 = stack[-1];
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    {
        LispObject v0029 = stack[0];
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0029, v0022);
    }

v0028:
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0023 = qcar(v0022);
    v0022 = stack[-2];
    v0022 = qcar(v0022);
    if (equal(v0023, v0022)) goto v0030;
    v0022 = stack[-1];
    v0023 = qcar(v0022);
    v0022 = stack[-3];
    v0022 = cons(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    stack[-3] = v0022;
    v0022 = stack[-1];
    v0022 = qcdr(v0022);
    stack[-1] = v0022;
    goto v0024;

v0030:
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    stack[0] = qcdr(v0022);
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0022 = qcdr(v0022);
    v0023 = qcar(v0022);
    v0022 = stack[-2];
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    fn = elt(env, 3); // dm!-plus
    v0022 = (*qfn2(fn))(qenv(fn), v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0022 = Lrplaca(nil, stack[0], v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    v0022 = stack[-1];
    v0022 = qcar(v0022);
    v0022 = qcdr(v0022);
    v0022 = qcar(v0022);
    fn = elt(env, 4); // zeropp
    v0022 = (*qfn1(fn))(qenv(fn), v0022);
    nil = C_nil;
    if (exception_pending()) goto v0026;
    env = stack[-4];
    if (v0022 == nil) goto v0031;
    v0023 = stack[-3];
    v0022 = stack[-1];
    v0022 = qcdr(v0022);
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0023, v0022);
    }

v0031:
    v0023 = stack[-3];
    v0022 = stack[-1];
    {
        popv(5);
        fn = elt(env, 2); // nreverse
        return (*qfn2(fn))(qenv(fn), v0023, v0022);
    }

v0025:
    v0022 = qvalue(elt(env, 1)); // t
    goto v0027;
// error exit handlers
v0026:
    popv(5);
    return nil;
}



// Code for listpri

static LispObject CC_listpri(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0040, v0041;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listpri");
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
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0000;
// end of prologue
    v0040 = stack[-2];
    stack[0] = v0040;
    v0040 = stack[-2];
    v0040 = qcdr(v0040);
    stack[-2] = v0040;
    v0040 = elt(env, 1); // !*lcbkt!*
    if (!symbolp(v0040)) v0040 = nil;
    else { v0040 = qfastgets(v0040);
           if (v0040 != nil) { v0040 = elt(v0040, 37); // prtch
#ifdef RECORD_GET
             if (v0040 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0040 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0040 == SPID_NOPROP) v0040 = nil; }}
#endif
    fn = elt(env, 7); // prin2!*
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0040 = qvalue(elt(env, 2)); // orig!*
    stack[-3] = v0040;
    v0041 = qvalue(elt(env, 3)); // posn!*
    v0040 = (LispObject)289; // 18
    v0040 = (LispObject)lessp2(v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    v0040 = v0040 ? lisp_true : nil;
    env = stack[-4];
    if (v0040 == nil) goto v0043;
    v0040 = qvalue(elt(env, 3)); // posn!*
    goto v0044;

v0044:
    qvalue(elt(env, 2)) = v0040; // orig!*
    v0040 = stack[-2];
    if (v0040 == nil) goto v0045;
    v0041 = stack[-2];
    v0040 = (LispObject)641; // 40
    fn = elt(env, 8); // treesizep
    v0040 = (*qfn2(fn))(qenv(fn), v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    stack[-1] = v0040;
    goto v0046;

v0046:
    v0040 = stack[-2];
    v0040 = qcar(v0040);
    fn = elt(env, 9); // negnumberchk
    v0041 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0040 = (LispObject)1; // 0
    fn = elt(env, 10); // maprint
    v0040 = (*qfn2(fn))(qenv(fn), v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0040 = stack[-2];
    v0040 = qcdr(v0040);
    stack[-2] = v0040;
    v0040 = stack[-2];
    if (v0040 == nil) goto v0045;
    v0040 = elt(env, 4); // !*comma!*
    fn = elt(env, 11); // oprin
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0040 = stack[-1];
    if (v0040 == nil) goto v0046;
    v0040 = qvalue(elt(env, 5)); // t
    fn = elt(env, 12); // terpri!*
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    goto v0046;

v0045:
    v0040 = elt(env, 6); // !*rcbkt!*
    if (!symbolp(v0040)) v0040 = nil;
    else { v0040 = qfastgets(v0040);
           if (v0040 != nil) { v0040 = elt(v0040, 37); // prtch
#ifdef RECORD_GET
             if (v0040 != SPID_NOPROP)
                record_get(elt(fastget_names, 37), 1);
             else record_get(elt(fastget_names, 37), 0),
                v0040 = nil; }
           else record_get(elt(fastget_names, 37), 0); }
#else
             if (v0040 == SPID_NOPROP) v0040 = nil; }}
#endif
    fn = elt(env, 7); // prin2!*
    v0040 = (*qfn1(fn))(qenv(fn), v0040);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    v0040 = stack[-3];
    qvalue(elt(env, 2)) = v0040; // orig!*
    { LispObject res = stack[0]; popv(5); return onevalue(res); }

v0043:
    v0041 = qvalue(elt(env, 2)); // orig!*
    v0040 = (LispObject)49; // 3
    v0040 = plus2(v0041, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-4];
    goto v0044;
// error exit handlers
v0042:
    popv(5);
    return nil;
}



// Code for gfdiffer

static LispObject CC_gfdiffer(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0020, v0049, v0021;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gfdiffer");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0049 = v0001;
    v0021 = v0000;
// end of prologue
    v0020 = v0021;
    v0020 = qcar(v0020);
    if (!consp(v0020)) goto v0050;
    v0020 = v0021;
    {
        fn = elt(env, 1); // gbfdiff
        return (*qfn2(fn))(qenv(fn), v0020, v0049);
    }

v0050:
    v0020 = v0021;
    {
        fn = elt(env, 2); // gffdiff
        return (*qfn2(fn))(qenv(fn), v0020, v0049);
    }
}



// Code for evalwhereexp

static LispObject CC_evalwhereexp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0057, v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evalwhereexp");
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
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0017 = v0000;
// end of prologue
    v0057 = v0017;
    v0057 = qcar(v0057);
    stack[-2] = qcdr(v0057);
    stack[-1] = elt(env, 1); // aeval
    stack[0] = elt(env, 1); // aeval
    v0057 = v0017;
    v0017 = qcdr(v0057);
    v0057 = elt(env, 2); // where
    fn = elt(env, 4); // carx
    v0057 = (*qfn2(fn))(qenv(fn), v0017, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0057 = list2(stack[0], v0057);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0057 = Lmkquote(nil, v0057);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0057 = list2(stack[-1], v0057);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0017 = list2(stack[-2], v0057);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-3];
    v0057 = qvalue(elt(env, 3)); // nil
    {
        popv(4);
        fn = elt(env, 5); // evalletsub
        return (*qfn2(fn))(qenv(fn), v0017, v0057);
    }
// error exit handlers
v0028:
    popv(4);
    return nil;
}



// Code for splitup

static LispObject CC_splitup(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0011, v0066, v0067;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for splitup");
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
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0067 = v0001;
    stack[0] = v0000;
// end of prologue
    v0011 = stack[0];
    if (v0011 == nil) goto v0068;
    v0011 = stack[0];
    v0011 = qcar(v0011);
    v0011 = qcar(v0011);
    v0011 = qcar(v0011);
    v0066 = v0011;
    v0011 = v0066;
    if (v0011 == nil) goto v0047;
    v0011 = v0067;
    v0011 = Lmemq(nil, v0066, v0011);
    goto v0053;

v0053:
    if (v0011 == nil) goto v0035;
    v0066 = qvalue(elt(env, 1)); // nil
    v0011 = stack[0];
    popv(3);
    return list2(v0066, v0011);

v0035:
    v0011 = stack[0];
    v0011 = qcdr(v0011);
    v0066 = v0067;
    v0011 = CC_splitup(env, v0011, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-2];
    v0066 = v0011;
    v0011 = stack[0];
    stack[-1] = qcar(v0011);
    v0011 = v0066;
    stack[0] = qcar(v0011);
    v0011 = v0066;
    v0011 = qcdr(v0011);
    v0011 = qcar(v0011);
    v0011 = ncons(v0011);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    {
        LispObject v0070 = stack[-1];
        LispObject v0071 = stack[0];
        popv(3);
        return acons(v0070, v0071, v0011);
    }

v0047:
    v0011 = qvalue(elt(env, 2)); // t
    goto v0053;

v0068:
    v0011 = qvalue(elt(env, 1)); // nil
    v0066 = qvalue(elt(env, 1)); // nil
    popv(3);
    return list2(v0011, v0066);
// error exit handlers
v0069:
    popv(3);
    return nil;
}



// Code for simpdfp

static LispObject CC_simpdfp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0123, v0124, v0125, v0126, v0127;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpdfp");
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
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0123 = stack[0];
    v0124 = Llength(nil, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0123 = (LispObject)33; // 2
    v0123 = (LispObject)lessp2(v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    v0123 = v0123 ? lisp_true : nil;
    env = stack[-6];
    if (v0123 == nil) goto v0027;
    v0124 = elt(env, 2); // dfp
    v0123 = stack[0];
    v0124 = cons(v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0123 = elt(env, 11); // "generic differential"
    fn = elt(env, 12); // typerr
    v0123 = (*qfn2(fn))(qenv(fn), v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    v0123 = nil;
    { popv(7); return onevalue(v0123); }

v0027:
    v0123 = stack[0];
    v0123 = qcar(v0123);
    fn = elt(env, 13); // reval
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    stack[-5] = v0123;
    v0123 = stack[-5];
    v0123 = Lconsp(nil, v0123);
    env = stack[-6];
    if (v0123 == nil) goto v0016;
    v0123 = stack[-5];
    v0123 = qcar(v0123);
    stack[-1] = v0123;
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    v0123 = qcar(v0123);
    fn = elt(env, 13); // reval
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0127 = v0123;
    v0124 = v0127;
    v0123 = qvalue(elt(env, 1)); // frlis!*
    v0123 = Lmember(nil, v0124, v0123);
    if (v0123 == nil) goto v0129;
    v0123 = qvalue(elt(env, 4)); // nil
    goto v0042;

v0042:
    if (v0123 == nil) goto v0130;
    stack[-4] = v0127;
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    v0123 = qcdr(v0123);
    stack[-3] = v0123;
    v0123 = stack[-3];
    if (v0123 == nil) goto v0131;
    v0123 = stack[-3];
    v0123 = qcar(v0123);
    fn = elt(env, 13); // reval
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0123 = ncons(v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    stack[-1] = v0123;
    stack[-2] = v0123;
    goto v0132;

v0132:
    v0123 = stack[-3];
    v0123 = qcdr(v0123);
    stack[-3] = v0123;
    v0123 = stack[-3];
    if (v0123 == nil) goto v0133;
    stack[0] = stack[-1];
    v0123 = stack[-3];
    v0123 = qcar(v0123);
    fn = elt(env, 13); // reval
    v0123 = (*qfn1(fn))(qenv(fn), v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0123 = ncons(v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0123 = Lrplacd(nil, stack[0], v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0123 = stack[-1];
    v0123 = qcdr(v0123);
    stack[-1] = v0123;
    goto v0132;

v0133:
    v0123 = stack[-2];
    goto v0002;

v0002:
    v0123 = cons(stack[-4], v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0127 = v0123;
    stack[0] = elt(env, 3); // list
    v0124 = v0127;
    v0123 = qvalue(elt(env, 4)); // nil
    fn = elt(env, 14); // dfp!-normalize
    v0123 = (*qfn2(fn))(qenv(fn), v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0123 = cons(stack[0], v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0127 = v0123;
    v0124 = elt(env, 2); // dfp
    v0123 = stack[-5];
    v0125 = v0127;
    v0123 = list3(v0124, v0123, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 15); // simp
        return (*qfn1(fn))(qenv(fn), v0123);
    }

v0131:
    v0123 = qvalue(elt(env, 4)); // nil
    goto v0002;

v0130:
    v0124 = stack[-1];
    v0123 = elt(env, 5); // generic_function
    v0123 = get(v0124, v0123);
    env = stack[-6];
    v0126 = v0123;
    v0123 = qvalue(elt(env, 6)); // t
    v0124 = v0126;
    if (v0124 == nil) goto v0134;
    v0125 = v0127;
    v0124 = elt(env, 3); // list
    if (!consp(v0125)) goto v0134;
    v0125 = qcar(v0125);
    if (!(v0125 == v0124)) goto v0134;
    v0124 = v0127;
    v0124 = qcdr(v0124);
    v0125 = v0124;
    goto v0135;

v0135:
    v0124 = v0125;
    if (v0124 == nil) goto v0134;
    v0124 = v0125;
    v0124 = qcar(v0124);
    if (v0123 == nil) goto v0136;
    v0123 = v0126;
    v0123 = Lmember(nil, v0124, v0123);
    goto v0137;

v0137:
    v0124 = v0125;
    v0124 = qcdr(v0124);
    v0125 = v0124;
    goto v0135;

v0136:
    v0123 = qvalue(elt(env, 4)); // nil
    goto v0137;

v0134:
    if (v0123 == nil) goto v0138;
    v0124 = v0127;
    v0123 = elt(env, 7); // (list)
    if (equal(v0124, v0123)) goto v0139;
    v0123 = v0126;
    if (v0123 == nil) goto v0140;
    v0124 = stack[-1];
    v0123 = elt(env, 8); // dfp_commute
    v0123 = Lflagp(nil, v0124, v0123);
    env = stack[-6];
    if (v0123 == nil) goto v0140;
    v0123 = v0126;
    stack[-1] = qvalue(elt(env, 9)); // kord!*
    qvalue(elt(env, 9)) = v0123; // kord!*
    stack[0] = elt(env, 3); // list
    v0123 = v0127;
    v0124 = qcdr(v0123);
    v0123 = elt(env, 10); // ordp
    fn = elt(env, 16); // sort
    v0123 = (*qfn2(fn))(qenv(fn), v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-6];
    v0123 = cons(stack[0], v0123);
    nil = C_nil;
    if (exception_pending()) goto v0141;
    env = stack[-6];
    v0127 = v0123;
    qvalue(elt(env, 9)) = stack[-1]; // kord!*
    goto v0140;

v0140:
    v0124 = elt(env, 2); // dfp
    v0123 = stack[-5];
    v0125 = v0127;
    v0123 = list3(v0124, v0123, v0125);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    stack[0] = v0123;
    v0124 = stack[0];
    v0123 = (LispObject)17; // 1
    {
        popv(7);
        fn = elt(env, 17); // mksq
        return (*qfn2(fn))(qenv(fn), v0124, v0123);
    }

v0139:
    v0124 = stack[-5];
    v0123 = (LispObject)17; // 1
    {
        popv(7);
        fn = elt(env, 17); // mksq
        return (*qfn2(fn))(qenv(fn), v0124, v0123);
    }

v0138:
    v0124 = qvalue(elt(env, 4)); // nil
    v0123 = (LispObject)17; // 1
    popv(7);
    return cons(v0124, v0123);

v0129:
    v0124 = v0127;
    v0123 = elt(env, 3); // list
    v0123 = Leqcar(nil, v0124, v0123);
    env = stack[-6];
    v0123 = (v0123 == nil ? lisp_true : nil);
    goto v0042;

v0016:
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    v0124 = qcar(v0123);
    v0123 = qvalue(elt(env, 1)); // frlis!*
    v0123 = Lmember(nil, v0124, v0123);
    if (v0123 == nil) goto v0010;
    v0124 = elt(env, 2); // dfp
    v0123 = stack[0];
    v0124 = cons(v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    v0123 = (LispObject)17; // 1
    {
        popv(7);
        fn = elt(env, 17); // mksq
        return (*qfn2(fn))(qenv(fn), v0124, v0123);
    }

v0010:
    v0124 = stack[-5];
    v0123 = stack[0];
    v0123 = qcdr(v0123);
    v0123 = qcar(v0123);
    v0123 = qcdr(v0123);
    v0123 = cons(v0124, v0123);
    nil = C_nil;
    if (exception_pending()) goto v0128;
    env = stack[-6];
    {
        popv(7);
        fn = elt(env, 18); // simpdf
        return (*qfn1(fn))(qenv(fn), v0123);
    }
// error exit handlers
v0141:
    env = stack[-6];
    qvalue(elt(env, 9)) = stack[-1]; // kord!*
    popv(7);
    return nil;
v0128:
    popv(7);
    return nil;
}



// Code for list2vect!*

static LispObject CC_list2vectH(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0143, v0011;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for list2vect*");
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
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    v0143 = stack[-4];
    v0143 = Llength(nil, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    v0143 = sub1(v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    v0143 = Lmkvect(nil, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    stack[-5] = v0143;
    v0143 = (LispObject)17; // 1
    stack[-2] = v0143;
    goto v0118;

v0118:
    v0143 = stack[-5];
    v0143 = Lupbv(nil, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    v0011 = add1(v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    v0143 = stack[-2];
    v0143 = difference2(v0011, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    v0143 = Lminusp(nil, v0143);
    env = stack[-6];
    if (!(v0143 == nil)) { LispObject res = stack[-5]; popv(7); return onevalue(res); }
    stack[-1] = stack[-5];
    v0143 = stack[-2];
    stack[0] = sub1(v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    v0011 = stack[-3];
    v0143 = elt(env, 2); // algebraic
    if (v0011 == v0143) goto v0013;
    v0011 = stack[-4];
    v0143 = stack[-2];
    fn = elt(env, 3); // nth
    v0143 = (*qfn2(fn))(qenv(fn), v0011, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    goto v0015;

v0015:
    *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)stack[0]/(16/CELL))) = v0143;
    v0143 = stack[-2];
    v0143 = add1(v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    stack[-2] = v0143;
    goto v0118;

v0013:
    v0011 = stack[-4];
    v0143 = stack[-2];
    fn = elt(env, 3); // nth
    v0143 = (*qfn2(fn))(qenv(fn), v0011, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    fn = elt(env, 4); // symb_to_alg
    v0143 = (*qfn1(fn))(qenv(fn), v0143);
    nil = C_nil;
    if (exception_pending()) goto v0071;
    env = stack[-6];
    goto v0015;
// error exit handlers
v0071:
    popv(7);
    return nil;
}



// Code for random!-teeny!-prime

static LispObject CC_randomKteenyKprime(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0010, v0146, v0059;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for random-teeny-prime");
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
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0146 = stack[0];
    v0010 = elt(env, 1); // all
    if (v0146 == v0010) goto v0045;
    v0010 = stack[0];
    v0146 = Llength(nil, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0010 = (LispObject)161; // 10
    v0010 = (v0146 == v0010 ? lisp_true : nil);
    goto v0086;

v0086:
    if (v0010 == nil) goto v0038;
    v0010 = qvalue(elt(env, 3)); // nil
    { popv(3); return onevalue(v0010); }

v0038:
    stack[-1] = qvalue(elt(env, 4)); // teeny!-primes
    fn = elt(env, 5); // next!-random!-number
    v0146 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0010 = (LispObject)161; // 10
    v0010 = Cremainder(v0146, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0060;
    env = stack[-2];
    v0010 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0010/(16/CELL)));
    v0059 = v0010;
    v0146 = v0059;
    v0010 = stack[0];
    v0010 = Lmember(nil, v0146, v0010);
    if (v0010 == nil) { popv(3); return onevalue(v0059); }
    else goto v0038;

v0045:
    v0010 = qvalue(elt(env, 2)); // t
    goto v0086;
// error exit handlers
v0060:
    popv(3);
    return nil;
}



// Code for subtractinds

static LispObject CC_subtractinds(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0145, v0151;
    LispObject v0032, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "subtractinds");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0032 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subtractinds");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0032,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0032);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0032;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue

v0045:
    v0145 = stack[-2];
    if (v0145 == nil) goto v0019;
    v0145 = stack[-3];
    v0151 = qcar(v0145);
    v0145 = stack[-2];
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0151 = difference2(v0151, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0145 = (LispObject)1; // 0
    v0145 = (LispObject)lessp2(v0151, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    v0145 = v0145 ? lisp_true : nil;
    env = stack[-5];
    if (v0145 == nil) goto v0016;
    v0145 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0145); }

v0016:
    v0145 = stack[-3];
    v0145 = qcdr(v0145);
    stack[-4] = v0145;
    v0145 = stack[-2];
    v0145 = qcdr(v0145);
    stack[0] = v0145;
    v0145 = stack[-3];
    v0151 = qcar(v0145);
    v0145 = stack[-2];
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0151 = difference2(v0151, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    v0145 = stack[-1];
    v0145 = cons(v0151, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-5];
    stack[-1] = v0145;
    v0145 = stack[0];
    stack[-2] = v0145;
    v0145 = stack[-4];
    stack[-3] = v0145;
    goto v0045;

v0019:
    v0145 = stack[-1];
        popv(6);
        return Lnreverse(nil, v0145);
// error exit handlers
v0058:
    popv(6);
    return nil;
}



// Code for cl_sacatlp

static LispObject CC_cl_sacatlp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject v0033, v0150;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_sacatlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0033 = v0001;
    v0150 = v0000;
// end of prologue
    v0033 = qvalue(elt(env, 1)); // t
    return onevalue(v0033);
}



// Code for ciom

static LispObject CC_ciom(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0145, v0151;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ciom");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0145 = elt(env, 1); // "<OMATTR>"
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = qvalue(elt(env, 2)); // t
    fn = elt(env, 12); // indent!*
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = elt(env, 3); // "<OMATP>"
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = qvalue(elt(env, 2)); // t
    fn = elt(env, 12); // indent!*
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = elt(env, 4); // "<OMS cd=""typmml"" name=""type"">"
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = elt(env, 5); // "<OMS cd=""typmml"" name="""
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = stack[0];
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    v0151 = Lintern(nil, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = qvalue(elt(env, 6)); // mmltypes!*
    v0145 = Lassoc(nil, v0151, v0145);
    v0145 = Lprinc(nil, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = stack[0];
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    v0145 = qcar(v0145);
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    v0151 = Lintern(nil, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = qvalue(elt(env, 6)); // mmltypes!*
    v0145 = Lassoc(nil, v0151, v0145);
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    v0145 = Lprinc(nil, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = elt(env, 7); // """>"
    v0145 = Lprinc(nil, v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 12); // indent!*
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = elt(env, 9); // "</OMATP>"
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = stack[0];
    v0145 = qcdr(v0145);
    v0145 = qcdr(v0145);
    v0145 = qcar(v0145);
    fn = elt(env, 13); // objectom
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = qvalue(elt(env, 8)); // nil
    fn = elt(env, 12); // indent!*
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-1];
    v0145 = elt(env, 10); // "</OMATTR>"
    fn = elt(env, 11); // printout
    v0145 = (*qfn1(fn))(qenv(fn), v0145);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    v0145 = nil;
    { popv(2); return onevalue(v0145); }
// error exit handlers
v0010:
    popv(2);
    return nil;
}



// Code for insertocc

static LispObject CC_insertocc(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0154, v0046, v0013;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for insertocc");
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
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0013 = v0001;
    stack[-1] = v0000;
// end of prologue
    v0046 = v0013;
    v0154 = stack[-1];
    v0154 = Lassoc(nil, v0046, v0154);
    stack[-2] = v0154;
    if (v0154 == nil) goto v0017;
    stack[0] = v0013;
    v0154 = stack[-2];
    v0154 = qcdr(v0154);
    v0154 = add1(v0154);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-3];
    v0013 = cons(stack[0], v0154);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    env = stack[-3];
    v0046 = stack[-2];
    v0154 = stack[-1];
    v0154 = Lsubst(nil, 3, v0013, v0046, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    stack[-1] = v0154;
    { LispObject res = stack[-1]; popv(4); return onevalue(res); }

v0017:
    v0046 = (LispObject)17; // 1
    v0154 = stack[-1];
    v0154 = acons(v0013, v0046, v0154);
    nil = C_nil;
    if (exception_pending()) goto v0030;
    stack[-1] = v0154;
    { LispObject res = stack[-1]; popv(4); return onevalue(res); }
// error exit handlers
v0030:
    popv(4);
    return nil;
}



// Code for new_simpexpt

static LispObject CC_new_simpexpt(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0129, v0157;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for new_simpexpt");
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
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push2(nil, nil);
// copy arguments values to proper place
    stack[-5] = v0000;
// end of prologue
    stack[-6] = qvalue(elt(env, 1)); // !*precise
    qvalue(elt(env, 1)) = nil; // !*precise
    stack[-4] = qvalue(elt(env, 2)); // !*factor
    qvalue(elt(env, 2)) = nil; // !*factor
    stack[-3] = qvalue(elt(env, 3)); // !*exp
    qvalue(elt(env, 3)) = nil; // !*exp
    stack[-2] = qvalue(elt(env, 4)); // !*mcd
    qvalue(elt(env, 4)) = nil; // !*mcd
    stack[-1] = qvalue(elt(env, 5)); // !*allfac
    qvalue(elt(env, 5)) = nil; // !*allfac
    v0157 = elt(env, 6); // exp
    v0129 = elt(env, 7); // mcd
    v0129 = list2(v0157, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    fn = elt(env, 15); // on
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    v0157 = elt(env, 8); // precise
    v0129 = elt(env, 9); // allfac
    v0129 = list2(v0157, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    fn = elt(env, 16); // off
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    v0129 = stack[-5];
    v0157 = qcar(v0129);
    v0129 = elt(env, 10); // minus
    if (!consp(v0157)) goto v0021;
    v0157 = qcar(v0157);
    if (!(v0157 == v0129)) goto v0021;
    v0157 = elt(env, 10); // minus
    v0129 = (LispObject)17; // 1
    v0157 = list2(v0157, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    v0129 = stack[-5];
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    v0129 = list2(v0157, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    fn = elt(env, 14); // original_simpexpt
    stack[0] = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    v0129 = stack[-5];
    v0129 = qcar(v0129);
    v0129 = qcdr(v0129);
    v0157 = qcar(v0129);
    v0129 = stack[-5];
    v0129 = qcdr(v0129);
    v0129 = qcar(v0129);
    v0129 = list2(v0157, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    v0129 = CC_new_simpexpt(env, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    fn = elt(env, 17); // multsq
    v0129 = (*qfn2(fn))(qenv(fn), stack[0], v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    goto v0068;

v0068:
    qvalue(elt(env, 5)) = stack[-1]; // !*allfac
    qvalue(elt(env, 4)) = stack[-2]; // !*mcd
    qvalue(elt(env, 3)) = stack[-3]; // !*exp
    qvalue(elt(env, 2)) = stack[-4]; // !*factor
    qvalue(elt(env, 1)) = stack[-6]; // !*precise
    { popv(8); return onevalue(v0129); }

v0021:
    v0129 = qvalue(elt(env, 11)); // !*redefmsg
    stack[0] = v0129;
    v0129 = qvalue(elt(env, 12)); // nil
    qvalue(elt(env, 11)) = v0129; // !*redefmsg
    v0157 = elt(env, 13); // simpexpt
    v0129 = elt(env, 14); // original_simpexpt
    fn = elt(env, 18); // copyd
    v0129 = (*qfn2(fn))(qenv(fn), v0157, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    v0129 = stack[-5];
    fn = elt(env, 13); // simpexpt
    v0129 = (*qfn1(fn))(qenv(fn), v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    stack[-5] = v0129;
    v0157 = elt(env, 13); // simpexpt
    v0129 = elt(env, 0); // new_simpexpt
    fn = elt(env, 18); // copyd
    v0129 = (*qfn2(fn))(qenv(fn), v0157, v0129);
    nil = C_nil;
    if (exception_pending()) goto v0158;
    env = stack[-7];
    v0129 = stack[0];
    qvalue(elt(env, 11)) = v0129; // !*redefmsg
    v0129 = stack[-5];
    goto v0068;
// error exit handlers
v0158:
    env = stack[-7];
    qvalue(elt(env, 5)) = stack[-1]; // !*allfac
    qvalue(elt(env, 4)) = stack[-2]; // !*mcd
    qvalue(elt(env, 3)) = stack[-3]; // !*exp
    qvalue(elt(env, 2)) = stack[-4]; // !*factor
    qvalue(elt(env, 1)) = stack[-6]; // !*precise
    popv(8);
    return nil;
}



// Code for a2vdp

static LispObject CC_a2vdp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0159, v0069, v0070;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for a2vdp");
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
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0070 = v0000;
// end of prologue
    v0069 = v0070;
    v0159 = (LispObject)1; // 0
    if (v0069 == v0159) goto v0045;
    v0159 = v0070;
    v0159 = (v0159 == nil ? lisp_true : nil);
    goto v0086;

v0086:
    if (v0159 == nil) goto v0035;
    stack[-2] = elt(env, 2); // vdp
    stack[-1] = qvalue(elt(env, 3)); // nil
    v0069 = qvalue(elt(env, 3)); // nil
    v0159 = (LispObject)17; // 1
    stack[0] = cons(v0069, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-3];
    v0069 = qvalue(elt(env, 3)); // nil
    v0159 = qvalue(elt(env, 3)); // nil
    v0159 = list2(v0069, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    {
        LispObject v0161 = stack[-2];
        LispObject v0155 = stack[-1];
        LispObject v0112 = stack[0];
        popv(4);
        return list3star(v0161, v0155, v0112, v0159);
    }

v0035:
    v0159 = v0070;
    fn = elt(env, 4); // a2dip
    v0159 = (*qfn1(fn))(qenv(fn), v0159);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    env = stack[-3];
    v0069 = v0159;
    stack[-2] = elt(env, 2); // vdp
    v0159 = v0069;
    stack[-1] = qcar(v0159);
    v0159 = v0069;
    v0159 = qcdr(v0159);
    stack[0] = qcar(v0159);
    v0159 = qvalue(elt(env, 3)); // nil
    v0159 = list2(v0069, v0159);
    nil = C_nil;
    if (exception_pending()) goto v0160;
    {
        LispObject v0042 = stack[-2];
        LispObject v0162 = stack[-1];
        LispObject v0163 = stack[0];
        popv(4);
        return list3star(v0042, v0162, v0163, v0159);
    }

v0045:
    v0159 = qvalue(elt(env, 1)); // t
    goto v0086;
// error exit handlers
v0160:
    popv(4);
    return nil;
}



// Code for xreadlist

static LispObject CC_xreadlist(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0166, v0132;
    LispObject fn;
    argcheck(nargs, 0, "xreadlist");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xreadlist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// end of prologue
    stack[-2] = nil;
    stack[-1] = nil;
    stack[0] = nil;
    fn = elt(env, 10); // scan
    v0132 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    v0166 = elt(env, 1); // !*rcbkt!*
    if (!(v0132 == v0166)) goto v0086;
    fn = elt(env, 10); // scan
    v0166 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    v0166 = elt(env, 2); // list
    popv(5);
    return ncons(v0166);

v0086:
    v0166 = stack[-1];
    if (v0166 == nil) goto v0049;
    v0166 = elt(env, 3); // group
    fn = elt(env, 11); // xread1
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    v0166 = ncons(v0166);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    fn = elt(env, 12); // nconc2
    v0166 = (*qfn2(fn))(qenv(fn), stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    stack[0] = v0166;
    goto v0052;

v0052:
    v0166 = qvalue(elt(env, 4)); // cursym!*
    stack[-3] = v0166;
    v0132 = stack[-3];
    v0166 = elt(env, 5); // !*semicol!*
    if (v0132 == v0166) goto v0034;
    fn = elt(env, 10); // scan
    v0132 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    v0166 = elt(env, 1); // !*rcbkt!*
    if (v0132 == v0166) goto v0070;
    v0166 = qvalue(elt(env, 7)); // nil
    goto v0060;

v0060:
    if (v0166 == nil) goto v0168;
    v0132 = elt(env, 9); // "Syntax error: invalid comma in list"
    v0166 = qvalue(elt(env, 7)); // nil
    fn = elt(env, 13); // symerr
    v0166 = (*qfn2(fn))(qenv(fn), v0132, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    goto v0168;

v0168:
    v0132 = stack[-3];
    v0166 = elt(env, 1); // !*rcbkt!*
    if (v0132 == v0166) goto v0169;
    v0166 = stack[-2];
    if (!(v0166 == nil)) goto v0086;
    v0166 = stack[-3];
    stack[-2] = v0166;
    goto v0086;

v0169:
    v0132 = elt(env, 2); // list
    v0166 = stack[-1];
    popv(5);
    return cons(v0132, v0166);

v0070:
    v0132 = stack[-3];
    v0166 = elt(env, 8); // !*comma!*
    v0166 = (v0132 == v0166 ? lisp_true : nil);
    goto v0060;

v0034:
    v0132 = elt(env, 6); // "Syntax error: semicolon in list"
    v0166 = qvalue(elt(env, 7)); // nil
    fn = elt(env, 13); // symerr
    v0166 = (*qfn2(fn))(qenv(fn), v0132, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    goto v0168;

v0049:
    stack[0] = stack[-1];
    v0166 = elt(env, 3); // group
    fn = elt(env, 11); // xread1
    v0166 = (*qfn1(fn))(qenv(fn), v0166);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    fn = elt(env, 14); // aconc
    v0166 = (*qfn2(fn))(qenv(fn), stack[0], v0166);
    nil = C_nil;
    if (exception_pending()) goto v0167;
    env = stack[-4];
    stack[0] = v0166;
    stack[-1] = v0166;
    goto v0052;
// error exit handlers
v0167:
    popv(5);
    return nil;
}



// Code for physoppri

static LispObject CC_physoppri(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0085, v0199, v0140, v0200;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physoppri");
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
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-8] = v0000;
// end of prologue
    stack[-6] = nil;
    v0085 = stack[-8];
    if (symbolp(v0085)) goto v0019;
    v0085 = stack[-8];
    v0085 = qcar(v0085);
    goto v0050;

v0050:
    stack[-9] = v0085;
    v0085 = stack[-8];
    if (symbolp(v0085)) goto v0118;
    v0085 = stack[-8];
    v0085 = qcdr(v0085);
    goto v0201;

v0201:
    stack[-7] = v0085;
    stack[-5] = elt(env, 0); // physoppri
    stack[-4] = elt(env, 2); // "x= "
    stack[-3] = stack[-9];
    stack[-2] = elt(env, 3); // " y= "
    stack[-1] = stack[-7];
    stack[0] = elt(env, 4); // "nat= "
    v0140 = elt(env, 5); // !*nat
    v0199 = elt(env, 6); // " contract= "
    v0085 = elt(env, 7); // !*contract
    v0085 = list3(v0140, v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = list3star(stack[-2], stack[-1], stack[0], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = list3star(stack[-5], stack[-4], stack[-3], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    fn = elt(env, 20); // trwrite
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = qvalue(elt(env, 5)); // !*nat
    if (v0085 == nil) goto v0040;
    v0085 = qvalue(elt(env, 7)); // !*contract
    if (!(v0085 == nil)) goto v0040;
    v0085 = stack[-9];
    v0085 = Lexplode(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lreverse(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    stack[-9] = v0085;
    v0085 = stack[-9];
    v0199 = Llength(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = (LispObject)33; // 2
    v0085 = (LispObject)greaterp2(v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    v0085 = v0085 ? lisp_true : nil;
    env = stack[-10];
    if (v0085 == nil) goto v0203;
    v0085 = stack[-9];
    v0085 = qcdr(v0085);
    v0199 = qcar(v0085);
    v0085 = elt(env, 14); // !-
    if (v0199 == v0085) goto v0204;
    v0085 = stack[-9];
    v0199 = qcar(v0085);
    v0085 = elt(env, 16); // !+
    if (v0199 == v0085) goto v0205;
    v0085 = stack[-9];
    v0085 = Lreverse(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lcompress(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    stack[-9] = v0085;
    goto v0206;

v0206:
    stack[0] = elt(env, 8); // !"
    v0085 = stack[-9];
    v0085 = Lexplode(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    stack[0] = cons(stack[0], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = elt(env, 8); // !"
    v0085 = ncons(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lappend(nil, stack[0], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lcompress(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    stack[-9] = v0085;
    v0085 = stack[-7];
    if (v0085 == nil) goto v0119;
    v0199 = stack[-9];
    v0085 = stack[-7];
    v0085 = cons(v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    goto v0135;

v0135:
    stack[-3] = v0085;
    stack[-2] = elt(env, 0); // physoppri
    stack[-1] = elt(env, 2); // "x= "
    stack[0] = stack[-9];
    v0200 = elt(env, 17); // " z= "
    v0140 = stack[-6];
    v0199 = elt(env, 18); // " x1= "
    v0085 = stack[-3];
    v0085 = list4(v0200, v0140, v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = list3star(stack[-2], stack[-1], stack[0], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    fn = elt(env, 20); // trwrite
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = stack[-6];
    if (v0085 == nil) goto v0207;
    v0140 = elt(env, 19); // expt
    v0199 = stack[-3];
    v0085 = stack[-6];
    v0199 = list3(v0140, v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = elt(env, 19); // expt
    if (!symbolp(v0085)) v0085 = nil;
    else { v0085 = qfastgets(v0085);
           if (v0085 != nil) { v0085 = elt(v0085, 23); // infix
#ifdef RECORD_GET
             if (v0085 != SPID_NOPROP)
                record_get(elt(fastget_names, 23), 1);
             else record_get(elt(fastget_names, 23), 0),
                v0085 = nil; }
           else record_get(elt(fastget_names, 23), 0); }
#else
             if (v0085 == SPID_NOPROP) v0085 = nil; }}
#endif
    fn = elt(env, 21); // exptpri
    v0085 = (*qfn2(fn))(qenv(fn), v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    { LispObject res = stack[-8]; popv(11); return onevalue(res); }

v0207:
    v0085 = stack[-9];
    fn = elt(env, 22); // prin2!*
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = stack[-7];
    if (v0085 == nil) { LispObject res = stack[-8]; popv(11); return onevalue(res); }
    v0085 = elt(env, 9); // "("
    fn = elt(env, 22); // prin2!*
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 10)) = v0085; // obrkp!*
    v0140 = elt(env, 11); // !*comma!*
    v0199 = (LispObject)1; // 0
    v0085 = stack[-7];
    fn = elt(env, 23); // inprint
    v0085 = (*qfnn(fn))(qenv(fn), 3, v0140, v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = qvalue(elt(env, 12)); // t
    qvalue(elt(env, 10)) = v0085; // obrkp!*
    v0085 = elt(env, 13); // ")"
    fn = elt(env, 22); // prin2!*
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    { LispObject res = stack[-8]; popv(11); return onevalue(res); }

v0119:
    v0085 = stack[-9];
    goto v0135;

v0205:
    v0085 = elt(env, 16); // !+
    stack[-6] = v0085;
    v0199 = stack[-9];
    v0085 = (LispObject)49; // 3
    fn = elt(env, 24); // pnth
    v0085 = (*qfn2(fn))(qenv(fn), v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lreverse(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lcompress(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    stack[-9] = v0085;
    goto v0206;

v0204:
    v0199 = elt(env, 14); // !-
    v0085 = elt(env, 15); // !1
    v0085 = list2(v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lcompress(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    stack[-6] = v0085;
    v0199 = stack[-9];
    v0085 = (LispObject)65; // 4
    fn = elt(env, 24); // pnth
    v0085 = (*qfn2(fn))(qenv(fn), v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lreverse(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lcompress(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    stack[-9] = v0085;
    goto v0206;

v0203:
    v0085 = stack[-9];
    v0085 = Lreverse(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lcompress(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    stack[-9] = v0085;
    goto v0206;

v0040:
    stack[0] = elt(env, 8); // !"
    v0085 = stack[-9];
    v0085 = Lexplode(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    stack[0] = cons(stack[0], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = elt(env, 8); // !"
    v0085 = ncons(v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lappend(nil, stack[0], v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = Lcompress(nil, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    stack[-9] = v0085;
    v0085 = stack[-9];
    fn = elt(env, 22); // prin2!*
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = stack[-7];
    if (v0085 == nil) { LispObject res = stack[-8]; popv(11); return onevalue(res); }
    v0085 = elt(env, 9); // "("
    fn = elt(env, 22); // prin2!*
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = qvalue(elt(env, 1)); // nil
    qvalue(elt(env, 10)) = v0085; // obrkp!*
    v0140 = elt(env, 11); // !*comma!*
    v0199 = (LispObject)1; // 0
    v0085 = stack[-7];
    fn = elt(env, 23); // inprint
    v0085 = (*qfnn(fn))(qenv(fn), 3, v0140, v0199, v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    env = stack[-10];
    v0085 = qvalue(elt(env, 12)); // t
    qvalue(elt(env, 10)) = v0085; // obrkp!*
    v0085 = elt(env, 13); // ")"
    fn = elt(env, 22); // prin2!*
    v0085 = (*qfn1(fn))(qenv(fn), v0085);
    nil = C_nil;
    if (exception_pending()) goto v0202;
    { LispObject res = stack[-8]; popv(11); return onevalue(res); }

v0118:
    v0085 = qvalue(elt(env, 1)); // nil
    goto v0201;

v0019:
    v0085 = stack[-8];
    goto v0050;
// error exit handlers
v0202:
    popv(11);
    return nil;
}



// Code for consrecip

static LispObject CC_consrecip(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0057, v0017, v0018;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for consrecip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0018 = v0000;
// end of prologue
    v0057 = v0018;
    v0017 = qcar(v0057);
    v0057 = (LispObject)17; // 1
    if (v0017 == v0057) goto v0045;
    v0057 = v0018;
    v0017 = qcar(v0057);
    v0057 = (LispObject)-15; // -1
    v0057 = (v0017 == v0057 ? lisp_true : nil);
    goto v0086;

v0086:
    if (v0057 == nil) goto v0148;
    v0057 = v0018;
    v0057 = qcar(v0057);
    return onevalue(v0057);

v0148:
    v0057 = elt(env, 2); // recip
    v0017 = v0018;
    return cons(v0057, v0017);

v0045:
    v0057 = qvalue(elt(env, 1)); // t
    goto v0086;
}



// Code for nonmult

static LispObject CC_nonmult(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0118, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nonmult");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0118 = qvalue(elt(env, 1)); // vjets!*
    v0064 = Lreverse(nil, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0118 = stack[0];
    fn = elt(env, 2); // nth
    stack[0] = (*qfn2(fn))(qenv(fn), v0064, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    env = stack[-1];
    v0118 = qvalue(elt(env, 1)); // vjets!*
    v0118 = Lreverse(nil, v0118);
    nil = C_nil;
    if (exception_pending()) goto v0053;
    v0118 = Lmember(nil, stack[0], v0118);
    v0118 = qcdr(v0118);
        popv(2);
        return Lreverse(nil, v0118);
// error exit handlers
v0053:
    popv(2);
    return nil;
}



// Code for extadd

static LispObject CC_extadd(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0212, v0213;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for extadd");
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
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0212 = stack[-3];
    if (v0212 == nil) { LispObject res = stack[-2]; popv(6); return onevalue(res); }
    v0212 = stack[-2];
    if (v0212 == nil) { LispObject res = stack[-3]; popv(6); return onevalue(res); }
    v0212 = qvalue(elt(env, 1)); // nil
    v0212 = ncons(v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    stack[-1] = v0212;
    stack[-4] = v0212;
    goto v0053;

v0053:
    v0212 = stack[-3];
    if (v0212 == nil) goto v0215;
    v0212 = stack[-2];
    if (v0212 == nil) goto v0215;
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0213 = qcar(v0212);
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    if (equal(v0213, v0212)) goto v0013;
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0213 = qcar(v0212);
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0212 = qcar(v0212);
    fn = elt(env, 2); // ordexp
    v0212 = (*qfn2(fn))(qenv(fn), v0213, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    if (v0212 == nil) goto v0022;
    stack[0] = stack[-1];
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = ncons(v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    fn = elt(env, 3); // setcdr
    v0212 = (*qfn2(fn))(qenv(fn), stack[0], v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    v0212 = stack[-2];
    v0212 = qcdr(v0212);
    stack[-2] = v0212;
    v0212 = stack[-1];
    v0212 = qcdr(v0212);
    stack[-1] = v0212;
    goto v0053;

v0022:
    stack[0] = stack[-1];
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0212 = ncons(v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    fn = elt(env, 3); // setcdr
    v0212 = (*qfn2(fn))(qenv(fn), stack[0], v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    v0212 = stack[-3];
    v0212 = qcdr(v0212);
    stack[-3] = v0212;
    v0212 = stack[-1];
    v0212 = qcdr(v0212);
    stack[-1] = v0212;
    goto v0053;

v0013:
    v0212 = stack[-3];
    v0212 = qcar(v0212);
    v0213 = qcdr(v0212);
    v0212 = stack[-2];
    v0212 = qcar(v0212);
    v0212 = qcdr(v0212);
    fn = elt(env, 4); // addf
    v0213 = (*qfn2(fn))(qenv(fn), v0213, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    v0212 = v0213;
    if (v0213 == nil) goto v0035;
    stack[0] = stack[-1];
    v0213 = stack[-3];
    v0213 = qcar(v0213);
    v0213 = qcar(v0213);
    v0212 = cons(v0213, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    v0212 = ncons(v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    fn = elt(env, 3); // setcdr
    v0212 = (*qfn2(fn))(qenv(fn), stack[0], v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-5];
    v0212 = stack[-1];
    v0212 = qcdr(v0212);
    stack[-1] = v0212;
    goto v0035;

v0035:
    v0212 = stack[-3];
    v0212 = qcdr(v0212);
    stack[-3] = v0212;
    v0212 = stack[-2];
    v0212 = qcdr(v0212);
    stack[-2] = v0212;
    goto v0053;

v0215:
    v0213 = stack[-1];
    v0212 = stack[-3];
    if (v0212 == nil) goto v0191;
    v0212 = stack[-3];
    goto v0216;

v0216:
    fn = elt(env, 3); // setcdr
    v0212 = (*qfn2(fn))(qenv(fn), v0213, v0212);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    v0212 = stack[-4];
    v0212 = qcdr(v0212);
    { popv(6); return onevalue(v0212); }

v0191:
    v0212 = stack[-2];
    goto v0216;
// error exit handlers
v0214:
    popv(6);
    return nil;
}



// Code for xnp

static LispObject CC_xnp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0043, v0153, v0149, v0148;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xnp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0153 = v0001;
    v0149 = v0000;
// end of prologue

v0218:
    v0043 = v0149;
    if (v0043 == nil) goto v0150;
    v0043 = v0149;
    v0148 = qcar(v0043);
    v0043 = v0153;
    v0043 = Lmemq(nil, v0148, v0043);
    if (!(v0043 == nil)) return onevalue(v0043);
    v0043 = v0149;
    v0149 = qcdr(v0043);
    v0043 = v0153;
    v0153 = v0043;
    goto v0218;

v0150:
    v0043 = qvalue(elt(env, 1)); // nil
    return onevalue(v0043);
}



// Code for super_vectorfield

static LispObject CC_super_vectorfield(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0120, v0121, v0180, v0178, v0179;
    LispObject fn;
    LispObject v0032, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "super_vectorfield");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0032 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for super_vectorfield");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0032,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0032);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0032;
    stack[-2] = v0001;
    stack[-3] = v0000;
// end of prologue
    v0120 = stack[-3];
    if (symbolp(v0120)) goto v0217;
    v0179 = elt(env, 1); // "SUPER_VECTORFIELD:"
    v0178 = stack[-3];
    v0180 = elt(env, 2); // "is not an identifier"
    v0121 = qvalue(elt(env, 3)); // nil
    v0120 = qvalue(elt(env, 4)); // t
    fn = elt(env, 16); // msgpri
    v0120 = (*qfnn(fn))(qenv(fn), 5, v0179, v0178, v0180, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    goto v0217;

v0217:
    v0180 = stack[-3];
    v0121 = elt(env, 5); // simpfn
    v0120 = elt(env, 6); // super_der_simp
    v0120 = Lputprop(nil, 3, v0180, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0120 = stack[-3];
    v0121 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0120 = elt(env, 7); // full
    v0120 = Lflag(nil, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0120 = stack[-2];
    if (v0120 == nil) goto v0036;
    v0120 = stack[-2];
    if (!consp(v0120)) goto v0197;
    v0120 = stack[-2];
    v0121 = qcar(v0120);
    v0120 = elt(env, 8); // list
    if (v0121 == v0120) goto v0117;
    v0120 = stack[-2];
    goto v0035;

v0035:
    stack[-2] = v0120;
    v0120 = stack[0];
    if (v0120 == nil) goto v0067;
    v0120 = stack[0];
    if (!consp(v0120)) goto v0070;
    v0120 = stack[0];
    v0121 = qcar(v0120);
    v0120 = elt(env, 8); // list
    if (v0121 == v0120) goto v0161;
    v0120 = stack[0];
    goto v0066;

v0066:
    stack[0] = v0120;
    v0120 = (LispObject)1; // 0
    stack[-4] = v0120;
    v0120 = stack[0];
    stack[-1] = v0120;
    goto v0005;

v0005:
    v0120 = stack[-1];
    if (v0120 == nil) goto v0102;
    v0120 = stack[-1];
    v0120 = qcar(v0120);
    stack[0] = v0120;
    v0120 = stack[0];
    v0121 = Llength(nil, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0120 = (LispObject)33; // 2
    if (v0121 == v0120) goto v0208;
    v0120 = qvalue(elt(env, 4)); // t
    goto v0023;

v0023:
    if (v0120 == nil) goto v0188;
    v0179 = elt(env, 1); // "SUPER_VECTORFIELD:"
    v0178 = stack[0];
    v0180 = elt(env, 10); // "not a valid odd variable"
    v0121 = qvalue(elt(env, 3)); // nil
    v0120 = qvalue(elt(env, 4)); // t
    fn = elt(env, 16); // msgpri
    v0120 = (*qfnn(fn))(qenv(fn), 5, v0179, v0178, v0180, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    goto v0003;

v0003:
    v0120 = stack[-1];
    v0120 = qcdr(v0120);
    stack[-1] = v0120;
    goto v0005;

v0188:
    v0121 = stack[-4];
    v0120 = stack[0];
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    fn = elt(env, 17); // max
    v0120 = (*qfn2(fn))(qenv(fn), v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    stack[-4] = v0120;
    goto v0003;

v0208:
    v0120 = stack[0];
    v0121 = qcar(v0120);
    v0120 = elt(env, 9); // ext
    if (v0121 == v0120) goto v0234;
    v0120 = qvalue(elt(env, 4)); // t
    goto v0023;

v0234:
    v0120 = stack[0];
    v0120 = qcdr(v0120);
    v0120 = qcar(v0120);
    v0120 = integerp(v0120);
    v0120 = (v0120 == nil ? lisp_true : nil);
    goto v0023;

v0102:
    v0180 = stack[-3];
    v0121 = elt(env, 11); // variables
    v0120 = stack[-2];
    v0120 = Lputprop(nil, 3, v0180, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    stack[-1] = stack[-3];
    stack[0] = elt(env, 12); // even_dimension
    v0120 = stack[-2];
    v0120 = Llength(nil, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0120 = Lputprop(nil, 3, stack[-1], stack[0], v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0180 = stack[-3];
    v0121 = elt(env, 13); // odd_dimension
    v0120 = stack[-4];
    v0120 = Lputprop(nil, 3, v0180, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    v0180 = stack[-3];
    v0121 = elt(env, 14); // setkfn
    v0120 = elt(env, 15); // setk_super_vectorfield
    v0120 = Lputprop(nil, 3, v0180, v0121, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    stack[0] = elt(env, 8); // list
    v0120 = stack[-2];
    v0121 = Llength(nil, v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    v0120 = stack[-4];
    {
        LispObject v0138 = stack[0];
        popv(6);
        return list3(v0138, v0121, v0120);
    }

v0161:
    v0120 = stack[0];
    v0120 = qcdr(v0120);
    goto v0066;

v0070:
    v0120 = stack[0];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    goto v0066;

v0067:
    v0120 = stack[0];
    goto v0066;

v0117:
    v0120 = stack[-2];
    v0120 = qcdr(v0120);
    goto v0035;

v0197:
    v0120 = stack[-2];
    v0120 = ncons(v0120);
    nil = C_nil;
    if (exception_pending()) goto v0233;
    env = stack[-5];
    goto v0035;

v0036:
    v0120 = stack[-2];
    goto v0035;
// error exit handlers
v0233:
    popv(6);
    return nil;
}



// Code for rl_sacatlp

static LispObject CC_rl_sacatlp(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0156, v0198;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rl_sacatlp");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0156 = v0001;
    v0198 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // rl_sacatlp!*
    v0156 = list2(v0198, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    {
        LispObject v0064 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0064, v0156);
    }
// error exit handlers
v0118:
    popv(2);
    return nil;
}



// Code for cgp_greenp

static LispObject CC_cgp_greenp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0150;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cgp_greenp");
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
// copy arguments values to proper place
    v0150 = v0000;
// end of prologue
    fn = elt(env, 1); // cgp_rp
    v0150 = (*qfn1(fn))(qenv(fn), v0150);
    errexit();
    v0150 = (v0150 == nil ? lisp_true : nil);
    return onevalue(v0150);
}



// Code for prsubsetrd

static LispObject CC_prsubsetrd(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007, v0232;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prsubsetrd");
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
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    v0007 = qvalue(elt(env, 1)); // t
    stack[-1] = v0007;
    goto v0048;

v0048:
    v0007 = stack[-3];
    v0232 = Llength(nil, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    v0007 = (LispObject)17; // 1
    v0007 = (LispObject)greaterp2(v0232, v0007);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    v0007 = v0007 ? lisp_true : nil;
    env = stack[-4];
    if (v0007 == nil) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0007 = stack[-3];
    stack[0] = qcar(v0007);
    v0007 = stack[-3];
    v0007 = qcar(v0007);
    fn = elt(env, 4); // reval
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    if (equal(stack[0], v0007)) goto v0217;
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    stack[0] = qcar(v0007);
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    fn = elt(env, 4); // reval
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    v0007 = (equal(stack[0], v0007) ? lisp_true : nil);
    goto v0021;

v0021:
    if (v0007 == nil) goto v0059;
    v0007 = nil;
    stack[-3] = v0007;
    stack[0] = elt(env, 3); // prsubset
    v0007 = stack[-2];
    fn = elt(env, 5); // eval_list_sets
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    v0007 = cons(stack[0], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    stack[-1] = v0007;
    goto v0048;

v0059:
    v0007 = stack[-1];
    if (v0007 == nil) goto v0211;
    v0007 = stack[-3];
    v0007 = qcar(v0007);
    fn = elt(env, 4); // reval
    stack[0] = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    v0007 = qcar(v0007);
    fn = elt(env, 4); // reval
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    fn = elt(env, 6); // alg_prsubset
    v0007 = (*qfn2(fn))(qenv(fn), stack[0], v0007);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-4];
    goto v0060;

v0060:
    stack[-1] = v0007;
    v0007 = stack[-3];
    v0007 = qcdr(v0007);
    stack[-3] = v0007;
    goto v0048;

v0211:
    v0007 = qvalue(elt(env, 2)); // nil
    goto v0060;

v0217:
    v0007 = qvalue(elt(env, 1)); // t
    goto v0021;
// error exit handlers
v0031:
    popv(5);
    return nil;
}



// Code for f4

static LispObject CC_f4(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0235, v0220;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for f4");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0220 = stack[0];
    v0235 = elt(env, 1); // pi
    if (v0220 == v0235) goto v0024;
    v0220 = stack[0];
    v0235 = elt(env, 3); // euler_gamma
    if (v0220 == v0235) goto v0044;
    v0220 = stack[0];
    v0235 = elt(env, 5); // true
    if (v0220 == v0235) goto v0049;
    v0220 = stack[0];
    v0235 = elt(env, 7); // false
    if (v0220 == v0235) goto v0055;
    v0220 = stack[0];
    v0235 = elt(env, 9); // !Na!N
    if (v0220 == v0235) goto v0035;
    v0220 = stack[0];
    v0235 = elt(env, 11); // infinity
    if (v0220 == v0235) goto v0034;
    v0220 = stack[0];
    v0235 = elt(env, 17); // e
    if (v0220 == v0235) goto v0042;
    v0220 = stack[0];
    v0235 = elt(env, 19); // i
    if (v0220 == v0235) goto v0003;
    v0235 = stack[0];
    if (!(is_number(v0235))) goto v0133;
    v0235 = elt(env, 21); // "<cn"
    fn = elt(env, 34); // printout
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    v0235 = stack[0];
    v0235 = Lfloatp(nil, v0235);
    env = stack[-1];
    if (v0235 == nil) goto v0237;
    v0235 = qvalue(elt(env, 12)); // !*web
    if (v0235 == nil) goto v0214;
    v0235 = elt(env, 23); // " type=&quot;real&quot;>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0212;

v0212:
    v0235 = stack[0];
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    v0235 = elt(env, 16); // "</cn>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0133;

v0133:
    v0235 = stack[0];
    if (!(symbolp(v0235))) goto v0150;
    v0235 = elt(env, 27); // "<ci"
    fn = elt(env, 34); // printout
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    v0235 = stack[0];
    fn = elt(env, 35); // listp
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    if (v0235 == nil) goto v0238;
    v0235 = qvalue(elt(env, 12)); // !*web
    if (v0235 == nil) goto v0223;
    v0235 = elt(env, 29); // " type=&quot;list&quot;>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0099;

v0099:
    v0235 = stack[0];
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    v0235 = elt(env, 32); // "</ci>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0150;

v0150:
    v0235 = nil;
    { popv(2); return onevalue(v0235); }

v0223:
    v0235 = elt(env, 28); // " type=""list"">"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0099;

v0238:
    v0235 = stack[0];
    v0235 = Lsimple_vectorp(nil, v0235);
    env = stack[-1];
    if (v0235 == nil) goto v0122;
    v0235 = qvalue(elt(env, 12)); // !*web
    if (v0235 == nil) goto v0239;
    v0235 = elt(env, 31); // " type=&quot;vector&quot;>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0099;

v0239:
    v0235 = elt(env, 30); // " type=""vector"">"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0099;

v0122:
    v0235 = elt(env, 26); // ">"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0099;

v0214:
    v0235 = elt(env, 22); // " type=""real"">"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0212;

v0237:
    v0235 = stack[0];
    v0235 = integerp(v0235);
    if (v0235 == nil) goto v0240;
    v0235 = qvalue(elt(env, 12)); // !*web
    if (v0235 == nil) goto v0241;
    v0235 = elt(env, 25); // " type=&quot;integer&quot;>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0212;

v0241:
    v0235 = elt(env, 24); // " type=""integer"">"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0212;

v0240:
    v0235 = elt(env, 26); // ">"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0212;

v0003:
    v0235 = qvalue(elt(env, 12)); // !*web
    if (v0235 == nil) goto v0242;
    v0235 = elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = elt(env, 34); // printout
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0029;

v0029:
    v0235 = elt(env, 20); // "&ImaginaryI;"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    v0235 = elt(env, 16); // "</cn>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0150;

v0242:
    v0235 = elt(env, 13); // "<cn type=""constant"">"
    fn = elt(env, 34); // printout
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0029;

v0042:
    v0235 = qvalue(elt(env, 12)); // !*web
    if (v0235 == nil) goto v0031;
    v0235 = elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = elt(env, 34); // printout
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0165;

v0165:
    v0235 = elt(env, 18); // "&ExponentialE;"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    v0235 = elt(env, 16); // "</cn>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0150;

v0031:
    v0235 = elt(env, 13); // "<cn type=""constant"">"
    fn = elt(env, 34); // printout
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0165;

v0034:
    v0235 = qvalue(elt(env, 12)); // !*web
    if (v0235 == nil) goto v0211;
    v0235 = elt(env, 14); // "<cn type=&quot;constant&quot;>"
    fn = elt(env, 34); // printout
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0060;

v0060:
    v0235 = elt(env, 15); // "&infin;"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    v0235 = elt(env, 16); // "</cn>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0150;

v0211:
    v0235 = elt(env, 13); // "<cn type=""constant"">"
    fn = elt(env, 34); // printout
    v0235 = (*qfn1(fn))(qenv(fn), v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    env = stack[-1];
    goto v0060;

v0035:
    v0235 = elt(env, 10); // "<notanumber/>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0150;

v0055:
    v0235 = elt(env, 8); // "<false/>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0150;

v0049:
    v0235 = elt(env, 6); // "<true/>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0150;

v0044:
    v0235 = elt(env, 4); // "<eulergamma/>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0150;

v0024:
    v0235 = elt(env, 2); // "<pi/>"
    v0235 = Lprinc(nil, v0235);
    nil = C_nil;
    if (exception_pending()) goto v0236;
    goto v0150;
// error exit handlers
v0236:
    popv(2);
    return nil;
}



// Code for findoptrow

static LispObject CC_findoptrow(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0102, v0100, v0101, v0251;
    LispObject fn;
    LispObject v0032, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "findoptrow");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0032 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for findoptrow");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0032,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0032);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-5] = v0032;
    stack[0] = v0001;
    stack[-6] = v0000;
// end of prologue
    stack[-7] = nil;
    stack[-2] = stack[0];
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0100 = qvalue(elt(env, 2)); // maxvar
    v0102 = stack[-6];
    v0102 = plus2(v0100, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-8];
    v0100 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    v0102 = (LispObject)65; // 4
    v0102 = *(LispObject *)((char *)v0100 + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    fn = elt(env, 8); // pnthxzz
    v0102 = (*qfn2(fn))(qenv(fn), stack[-2], v0102);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-8];
    v0102 = qcar(v0102);
    v0102 = qcdr(v0102);
    v0102 = qcar(v0102);
    stack[-3] = v0102;
    stack[-1] = qvalue(elt(env, 1)); // codmat
    v0100 = qvalue(elt(env, 2)); // maxvar
    v0102 = stack[0];
    v0102 = plus2(v0100, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-8];
    v0100 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    v0102 = (LispObject)65; // 4
    v0102 = *(LispObject *)((char *)v0100 + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    stack[-2] = v0102;
    goto v0062;

v0062:
    v0102 = stack[-2];
    if (v0102 == nil) { LispObject res = stack[-7]; popv(9); return onevalue(res); }
    v0102 = stack[-2];
    v0102 = qcar(v0102);
    stack[-1] = v0102;
    stack[0] = qvalue(elt(env, 1)); // codmat
    v0100 = qvalue(elt(env, 2)); // maxvar
    v0102 = stack[-1];
    v0102 = qcar(v0102);
    stack[-4] = v0102;
    v0102 = plus2(v0100, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-8];
    v0100 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    v0102 = (LispObject)1; // 0
    v0102 = *(LispObject *)((char *)v0100 + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    if (v0102 == nil) goto v0159;
    v0251 = stack[-4];
    v0101 = stack[-6];
    v0102 = stack[-1];
    v0102 = qcdr(v0102);
    v0100 = qcar(v0102);
    v0102 = stack[-3];
    fn = elt(env, 9); // testpr
    v0102 = (*qfnn(fn))(qenv(fn), 4, v0251, v0101, v0100, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-8];
    stack[0] = v0102;
    v0102 = qcdr(v0102);
    if (v0102 == nil) goto v0029;
    v0102 = stack[0];
    v0100 = Llength(nil, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-8];
    stack[-1] = v0100;
    v0102 = stack[-5];
    v0102 = (LispObject)greaterp2(v0100, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    v0102 = v0102 ? lisp_true : nil;
    env = stack[-8];
    if (v0102 == nil) goto v0237;
    v0102 = stack[-1];
    stack[-5] = v0102;
    qvalue(elt(env, 5)) = v0102; // newnjsi
    v0102 = stack[-4];
    stack[-7] = v0102;
    v0102 = stack[0];
    qvalue(elt(env, 6)) = v0102; // newjsi
    goto v0237;

v0237:
    v0100 = stack[-4];
    v0102 = qvalue(elt(env, 7)); // roccup2
    v0102 = cons(v0100, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-8];
    qvalue(elt(env, 7)) = v0102; // roccup2
    goto v0205;

v0205:
    stack[0] = qvalue(elt(env, 1)); // codmat
    v0100 = qvalue(elt(env, 2)); // maxvar
    v0102 = stack[-4];
    v0102 = plus2(v0100, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-8];
    v0101 = *(LispObject *)((char *)stack[0] + (CELL-TAG_VECTOR) + ((int32_t)v0102/(16/CELL)));
    v0100 = (LispObject)1; // 0
    v0102 = qvalue(elt(env, 3)); // nil
    *(LispObject *)((char *)v0101 + (CELL-TAG_VECTOR) + ((int32_t)v0100/(16/CELL))) = v0102;
    goto v0159;

v0159:
    v0102 = stack[-2];
    v0102 = qcdr(v0102);
    stack[-2] = v0102;
    goto v0062;

v0029:
    v0100 = stack[-4];
    v0102 = qvalue(elt(env, 4)); // roccup1
    v0102 = cons(v0100, v0102);
    nil = C_nil;
    if (exception_pending()) goto v0252;
    env = stack[-8];
    qvalue(elt(env, 4)) = v0102; // roccup1
    goto v0205;
// error exit handlers
v0252:
    popv(9);
    return nil;
}



// Code for reduce!-columns

static LispObject CC_reduceKcolumns(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0234, v0204;
    LispObject fn;
    LispObject v0032, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "reduce-columns");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0032 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce-columns");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0032,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0032);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-4] = v0032;
    stack[-5] = v0001;
    stack[-6] = v0000;
// end of prologue
    v0234 = stack[-6];
    stack[-3] = v0234;
    v0234 = stack[-5];
    stack[-2] = v0234;
    stack[0] = stack[-6];
    v0204 = stack[-6];
    v0234 = stack[-4];
    fn = elt(env, 3); // red!-weight
    v0234 = (*qfn2(fn))(qenv(fn), v0204, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-8];
    v0234 = cons(stack[0], v0234);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-8];
    stack[-7] = v0234;
    goto v0019;

v0019:
    v0234 = stack[-3];
    if (v0234 == nil) goto v0054;
    v0234 = stack[-3];
    v0204 = qcar(v0234);
    v0234 = (LispObject)1; // 0
    if (v0204 == v0234) goto v0056;
    v0234 = stack[-2];
    v0204 = qcar(v0234);
    v0234 = (LispObject)1; // 0
    v0234 = (v0204 == v0234 ? lisp_true : nil);
    goto v0055;

v0055:
    if (!(v0234 == nil)) goto v0217;
    v0234 = stack[-3];
    v0204 = qcar(v0234);
    v0234 = stack[-2];
    v0234 = qcar(v0234);
    v0234 = Ldivide(nil, v0204, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-8];
    stack[-1] = v0234;
    v0204 = qcdr(v0234);
    v0234 = (LispObject)1; // 0
    if (!(v0204 == v0234)) goto v0217;
    stack[0] = stack[-6];
    v0234 = stack[-1];
    v0204 = qcar(v0234);
    v0234 = stack[-5];
    fn = elt(env, 4); // mv!-domainlist!-!*
    v0234 = (*qfn2(fn))(qenv(fn), v0204, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-8];
    fn = elt(env, 5); // mv!-domainlist!-!-
    v0234 = (*qfn2(fn))(qenv(fn), stack[0], v0234);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-8];
    stack[-1] = v0234;
    v0204 = stack[-1];
    v0234 = stack[-4];
    fn = elt(env, 3); // red!-weight
    v0234 = (*qfn2(fn))(qenv(fn), v0204, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-8];
    stack[0] = v0234;
    v0204 = stack[0];
    v0234 = stack[-7];
    v0234 = qcdr(v0234);
    fn = elt(env, 6); // red!-weight!-less!-p
    v0234 = (*qfn2(fn))(qenv(fn), v0204, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-8];
    if (v0234 == nil) goto v0217;
    v0204 = stack[-1];
    v0234 = stack[0];
    v0204 = cons(v0204, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-8];
    v0234 = stack[-7];
    fn = elt(env, 7); // more!-apartp
    v0234 = (*qfn2(fn))(qenv(fn), v0204, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-8];
    if (!(v0234 == nil)) goto v0217;
    v0204 = stack[-1];
    v0234 = stack[0];
    v0234 = cons(v0204, v0234);
    nil = C_nil;
    if (exception_pending()) goto v0214;
    env = stack[-8];
    stack[-7] = v0234;
    goto v0217;

v0217:
    v0234 = stack[-3];
    v0234 = qcdr(v0234);
    stack[-3] = v0234;
    v0234 = stack[-2];
    v0234 = qcdr(v0234);
    stack[-2] = v0234;
    goto v0019;

v0056:
    v0234 = qvalue(elt(env, 1)); // t
    goto v0055;

v0054:
    v0234 = stack[-7];
    v0234 = qcar(v0234);
    { popv(9); return onevalue(v0234); }
// error exit handlers
v0214:
    popv(9);
    return nil;
}



// Code for gadd

static LispObject CC_gadd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0166, v0132, v0210;
    LispObject fn;
    LispObject v0032, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "gadd");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0032 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for gadd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0032,v0001,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0001,v0032);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-2] = v0032;
    stack[-3] = v0001;
    stack[-4] = v0000;
// end of prologue
    stack[-5] = nil;
    v0166 = (LispObject)1; // 0
    stack[0] = v0166;
    v0132 = stack[-2];
    v0166 = stack[-3];
    v0166 = Latsoc(nil, v0132, v0166);
    stack[-1] = v0166;
    if (v0166 == nil) goto v0068;
    v0132 = stack[-1];
    v0166 = stack[-3];
    v0166 = Ldelete(nil, v0132, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-6];
    stack[-3] = v0166;
    v0166 = stack[-1];
    v0166 = qcdr(v0166);
    v0166 = qcdr(v0166);
    stack[-5] = v0166;
    v0166 = stack[-1];
    v0166 = qcdr(v0166);
    v0166 = qcar(v0166);
    stack[-1] = v0166;
    goto v0068;

v0068:
    v0166 = stack[-4];
    if (v0166 == nil) goto v0062;
    v0166 = stack[-4];
    v0132 = qcar(v0166);
    v0166 = elt(env, 1); // a
    if (v0132 == v0166) goto v0007;
    v0166 = stack[-4];
    v0132 = qcar(v0166);
    v0166 = stack[-5];
    v0166 = cons(v0132, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-6];
    stack[-5] = v0166;
    goto v0050;

v0050:
    v0166 = stack[-4];
    v0166 = qcdr(v0166);
    stack[-4] = v0166;
    goto v0068;

v0007:
    v0132 = qvalue(elt(env, 2)); // ndims!*
    v0166 = (LispObject)65; // 4
    if (v0132 == v0166) goto v0163;
    v0210 = elt(env, 3); // hephys
    v0132 = (LispObject)129; // 8
    v0166 = elt(env, 4); // "Gamma5 not allowed unless vecdim is 4"
    fn = elt(env, 5); // rerror
    v0166 = (*qfnn(fn))(qenv(fn), 3, v0210, v0132, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-6];
    goto v0163;

v0163:
    v0166 = stack[-1];
    v0166 = (v0166 == nil ? lisp_true : nil);
    stack[-1] = v0166;
    v0166 = stack[-5];
    v0132 = Llength(nil, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-6];
    v0166 = stack[0];
    v0166 = plus2(v0132, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    env = stack[-6];
    stack[0] = v0166;
    goto v0050;

v0062:
    v0166 = stack[0];
    stack[0] = Levenp(nil, v0166);
    env = stack[-6];
    v0210 = stack[-2];
    v0132 = stack[-1];
    v0166 = stack[-5];
    v0132 = list2star(v0210, v0132, v0166);
    nil = C_nil;
    if (exception_pending()) goto v0247;
    v0166 = stack[-3];
    {
        LispObject v0194 = stack[0];
        popv(7);
        return list2star(v0194, v0132, v0166);
    }
// error exit handlers
v0247:
    popv(7);
    return nil;
}



// Code for cl_nnfnot

static LispObject CC_cl_nnfnot(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0019;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_nnfnot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0050 = v0000;
// end of prologue
    v0019 = v0050;
    v0050 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // cl_nnf1
        return (*qfn2(fn))(qenv(fn), v0019, v0050);
    }
}



// Code for rtypepart

static LispObject CC_rtypepart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0027;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rtypepart");
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
// copy arguments values to proper place
    v0027 = v0000;
// end of prologue
    fn = elt(env, 3); // getrtypecar
    v0027 = (*qfn1(fn))(qenv(fn), v0027);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[0];
    if (v0027 == nil) goto v0068;
    v0027 = elt(env, 1); // yetunknowntype
    { popv(1); return onevalue(v0027); }

v0068:
    v0027 = qvalue(elt(env, 2)); // nil
    { popv(1); return onevalue(v0027); }
// error exit handlers
v0025:
    popv(1);
    return nil;
}



// Code for mk!+equation

static LispObject CC_mkLequation(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0037, v0044, v0156;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mk+equation");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0037 = v0001;
    v0044 = v0000;
// end of prologue
    v0156 = elt(env, 1); // equal
    return list3(v0156, v0044, v0037);
}



// Code for freeof!-dfl

static LispObject CC_freeofKdfl(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0015, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for freeof-dfl");
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
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue

v0218:
    v0015 = stack[-1];
    if (!consp(v0015)) goto v0150;
    v0015 = stack[-1];
    v0016 = qcar(v0015);
    v0015 = stack[0];
    fn = elt(env, 3); // freeof!-df
    v0015 = (*qfn2(fn))(qenv(fn), v0016, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0056;
    env = stack[-2];
    if (v0015 == nil) goto v0025;
    v0015 = stack[-1];
    v0016 = qcdr(v0015);
    v0015 = stack[0];
    stack[-1] = v0016;
    stack[0] = v0015;
    goto v0218;

v0025:
    v0015 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0015); }

v0150:
    v0015 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0015); }
// error exit handlers
v0056:
    popv(3);
    return nil;
}



// Code for pasf_or

static LispObject CC_pasf_or(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0287, v0288;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_or");
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
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0288 = stack[0];
    v0287 = elt(env, 1); // true
    if (v0288 == v0287) goto v0048;
    v0288 = stack[0];
    v0287 = elt(env, 3); // false
    v0287 = (v0288 == v0287 ? lisp_true : nil);
    goto v0065;

v0065:
    if (v0287 == nil) goto v0036;
    v0287 = qvalue(elt(env, 2)); // t
    goto v0050;

v0050:
    if (!(v0287 == nil)) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    v0287 = qcar(v0287);
    fn = elt(env, 10); // pasf_deci
    v0287 = (*qfn1(fn))(qenv(fn), v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    stack[-1] = v0287;
    v0288 = stack[0];
    v0287 = elt(env, 1); // true
    if (v0288 == v0287) goto v0164;
    v0288 = stack[0];
    v0287 = elt(env, 3); // false
    v0287 = (v0288 == v0287 ? lisp_true : nil);
    goto v0290;

v0290:
    if (v0287 == nil) goto v0006;
    v0287 = stack[0];
    v0288 = v0287;
    goto v0031;

v0031:
    v0287 = elt(env, 5); // lessp
    if (v0288 == v0287) goto v0133;
    v0287 = qvalue(elt(env, 6)); // nil
    goto v0232;

v0232:
    if (v0287 == nil) goto v0099;
    stack[-1] = elt(env, 7); // leq
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    stack[0] = qcar(v0287);
    v0287 = (LispObject)17; // 1
    fn = elt(env, 11); // simp
    v0287 = (*qfn1(fn))(qenv(fn), v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    v0287 = qcar(v0287);
    fn = elt(env, 12); // addf
    v0287 = (*qfn2(fn))(qenv(fn), stack[0], v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    v0288 = qvalue(elt(env, 6)); // nil
    {
        LispObject v0291 = stack[-1];
        popv(3);
        return list3(v0291, v0287, v0288);
    }

v0099:
    v0288 = stack[0];
    v0287 = elt(env, 1); // true
    if (v0288 == v0287) goto v0225;
    v0288 = stack[0];
    v0287 = elt(env, 3); // false
    v0287 = (v0288 == v0287 ? lisp_true : nil);
    goto v0224;

v0224:
    if (v0287 == nil) goto v0292;
    v0287 = stack[0];
    v0288 = v0287;
    goto v0102;

v0102:
    v0287 = elt(env, 7); // leq
    if (v0288 == v0287) goto v0137;
    v0287 = qvalue(elt(env, 6)); // nil
    goto v0240;

v0240:
    if (v0287 == nil) goto v0293;
    stack[-1] = elt(env, 5); // lessp
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    stack[0] = qcar(v0287);
    v0287 = (LispObject)17; // 1
    fn = elt(env, 11); // simp
    v0287 = (*qfn1(fn))(qenv(fn), v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    v0287 = qcar(v0287);
    fn = elt(env, 13); // negf
    v0287 = (*qfn1(fn))(qenv(fn), v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    fn = elt(env, 12); // addf
    v0287 = (*qfn2(fn))(qenv(fn), stack[0], v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    v0288 = qvalue(elt(env, 6)); // nil
    {
        LispObject v0294 = stack[-1];
        popv(3);
        return list3(v0294, v0287, v0288);
    }

v0293:
    v0288 = stack[0];
    v0287 = elt(env, 1); // true
    if (v0288 == v0287) goto v0295;
    v0288 = stack[0];
    v0287 = elt(env, 3); // false
    v0287 = (v0288 == v0287 ? lisp_true : nil);
    goto v0174;

v0174:
    if (v0287 == nil) goto v0175;
    v0287 = stack[0];
    v0288 = v0287;
    goto v0296;

v0296:
    v0287 = elt(env, 8); // greaterp
    if (v0288 == v0287) goto v0297;
    v0287 = qvalue(elt(env, 6)); // nil
    goto v0092;

v0092:
    if (v0287 == nil) goto v0298;
    stack[-1] = elt(env, 9); // geq
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    stack[0] = qcar(v0287);
    v0287 = (LispObject)17; // 1
    fn = elt(env, 11); // simp
    v0287 = (*qfn1(fn))(qenv(fn), v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    v0287 = qcar(v0287);
    fn = elt(env, 13); // negf
    v0287 = (*qfn1(fn))(qenv(fn), v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    fn = elt(env, 12); // addf
    v0287 = (*qfn2(fn))(qenv(fn), stack[0], v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    v0288 = qvalue(elt(env, 6)); // nil
    {
        LispObject v0299 = stack[-1];
        popv(3);
        return list3(v0299, v0287, v0288);
    }

v0298:
    v0288 = stack[0];
    v0287 = elt(env, 1); // true
    if (v0288 == v0287) goto v0300;
    v0288 = stack[0];
    v0287 = elt(env, 3); // false
    v0287 = (v0288 == v0287 ? lisp_true : nil);
    goto v0301;

v0301:
    if (v0287 == nil) goto v0302;
    v0287 = stack[0];
    v0288 = v0287;
    goto v0303;

v0303:
    v0287 = elt(env, 9); // geq
    if (v0288 == v0287) goto v0304;
    v0287 = qvalue(elt(env, 6)); // nil
    goto v0128;

v0128:
    if (v0287 == nil) { LispObject res = stack[0]; popv(3); return onevalue(res); }
    stack[-1] = elt(env, 8); // greaterp
    v0287 = stack[0];
    v0287 = qcdr(v0287);
    stack[0] = qcar(v0287);
    v0287 = (LispObject)17; // 1
    fn = elt(env, 11); // simp
    v0287 = (*qfn1(fn))(qenv(fn), v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    v0287 = qcar(v0287);
    fn = elt(env, 12); // addf
    v0287 = (*qfn2(fn))(qenv(fn), stack[0], v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    env = stack[-2];
    v0288 = qvalue(elt(env, 6)); // nil
    {
        LispObject v0305 = stack[-1];
        popv(3);
        return list3(v0305, v0287, v0288);
    }

v0304:
    v0287 = stack[-1];
    v0288 = qcdr(v0287);
    v0287 = (LispObject)1; // 0
    v0287 = (LispObject)lessp2(v0288, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0287 = v0287 ? lisp_true : nil;
    env = stack[-2];
    goto v0128;

v0302:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = Lconsp(nil, v0287);
    env = stack[-2];
    if (v0287 == nil) goto v0306;
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = qcar(v0287);
    v0288 = v0287;
    goto v0303;

v0306:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0288 = v0287;
    goto v0303;

v0300:
    v0287 = qvalue(elt(env, 2)); // t
    goto v0301;

v0297:
    v0287 = stack[-1];
    v0288 = qcdr(v0287);
    v0287 = (LispObject)1; // 0
    v0287 = (LispObject)greaterp2(v0288, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0287 = v0287 ? lisp_true : nil;
    env = stack[-2];
    goto v0092;

v0175:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = Lconsp(nil, v0287);
    env = stack[-2];
    if (v0287 == nil) goto v0199;
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = qcar(v0287);
    v0288 = v0287;
    goto v0296;

v0199:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0288 = v0287;
    goto v0296;

v0295:
    v0287 = qvalue(elt(env, 2)); // t
    goto v0174;

v0137:
    v0287 = stack[-1];
    v0288 = qcdr(v0287);
    v0287 = (LispObject)1; // 0
    v0287 = (LispObject)greaterp2(v0288, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0287 = v0287 ? lisp_true : nil;
    env = stack[-2];
    goto v0240;

v0292:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = Lconsp(nil, v0287);
    env = stack[-2];
    if (v0287 == nil) goto v0307;
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = qcar(v0287);
    v0288 = v0287;
    goto v0102;

v0307:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0288 = v0287;
    goto v0102;

v0225:
    v0287 = qvalue(elt(env, 2)); // t
    goto v0224;

v0133:
    v0287 = stack[-1];
    v0288 = qcdr(v0287);
    v0287 = (LispObject)1; // 0
    v0287 = (LispObject)lessp2(v0288, v0287);
    nil = C_nil;
    if (exception_pending()) goto v0289;
    v0287 = v0287 ? lisp_true : nil;
    env = stack[-2];
    goto v0232;

v0006:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = Lconsp(nil, v0287);
    env = stack[-2];
    if (v0287 == nil) goto v0308;
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = qcar(v0287);
    v0288 = v0287;
    goto v0031;

v0308:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0288 = v0287;
    goto v0031;

v0164:
    v0287 = qvalue(elt(env, 2)); // t
    goto v0290;

v0036:
    v0288 = stack[0];
    v0287 = elt(env, 1); // true
    if (v0288 == v0287) goto v0147;
    v0288 = stack[0];
    v0287 = elt(env, 3); // false
    v0287 = (v0288 == v0287 ? lisp_true : nil);
    goto v0152;

v0152:
    if (v0287 == nil) goto v0062;
    v0287 = stack[0];
    v0288 = v0287;
    goto v0056;

v0056:
    v0287 = elt(env, 4); // (lessp greaterp leq geq)
    v0287 = Lmemq(nil, v0288, v0287);
    v0287 = (v0287 == nil ? lisp_true : nil);
    goto v0050;

v0062:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = Lconsp(nil, v0287);
    env = stack[-2];
    if (v0287 == nil) goto v0012;
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0287 = qcar(v0287);
    v0288 = v0287;
    goto v0056;

v0012:
    v0287 = stack[0];
    v0287 = qcar(v0287);
    v0288 = v0287;
    goto v0056;

v0147:
    v0287 = qvalue(elt(env, 2)); // t
    goto v0152;

v0048:
    v0287 = qvalue(elt(env, 2)); // t
    goto v0065;
// error exit handlers
v0289:
    popv(3);
    return nil;
}



// Code for integralir

static LispObject CC_integralir(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0070, v0071;
    LispObject fn;
    argcheck(nargs, 0, "integralir");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for integralir");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// end of prologue
    v0071 = qvalue(elt(env, 1)); // atts
    v0070 = elt(env, 2); // name
    fn = elt(env, 7); // find
    v0070 = (*qfn2(fn))(qenv(fn), v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    v0070 = Lintern(nil, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    stack[-1] = v0070;
    v0070 = elt(env, 3); // (bvar x 1)
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    stack[0] = v0070;
    v0071 = stack[-1];
    v0070 = elt(env, 5); // defint
    if (!(v0071 == v0070)) goto v0201;
    fn = elt(env, 8); // lex
    v0070 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    fn = elt(env, 9); // omobj
    v0070 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    goto v0201;

v0201:
    fn = elt(env, 8); // lex
    v0070 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    fn = elt(env, 9); // omobj
    v0070 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    stack[-2] = v0070;
    v0070 = stack[-2];
    v0070 = Lconsp(nil, v0070);
    env = stack[-3];
    if (v0070 == nil) goto v0009;
    v0070 = stack[-2];
    v0071 = qcar(v0070);
    v0070 = elt(env, 6); // lambda
    if (!(v0071 == v0070)) goto v0009;
    v0070 = stack[-2];
    fn = elt(env, 10); // lambdavar
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    stack[0] = v0070;
    v0070 = stack[-2];
    fn = elt(env, 11); // lambdafun
    v0070 = (*qfn1(fn))(qenv(fn), v0070);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    stack[-2] = v0070;
    goto v0009;

v0009:
    v0071 = stack[-1];
    v0070 = qvalue(elt(env, 4)); // nil
    stack[-1] = list2(v0071, v0070);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    v0070 = stack[-2];
    v0070 = ncons(v0070);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    env = stack[-3];
    v0070 = Lappend(nil, stack[0], v0070);
    nil = C_nil;
    if (exception_pending()) goto v0161;
    {
        LispObject v0155 = stack[-1];
        popv(4);
        return Lappend(nil, v0155, v0070);
    }
// error exit handlers
v0161:
    popv(4);
    return nil;
}



// Code for plusrd

static LispObject CC_plusrd(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0064, v0052;
    LispObject fn;
    argcheck(nargs, 0, "plusrd");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for plusrd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        env = reclaim(env, "stack", GC_STACK, 0);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// end of prologue
    fn = elt(env, 2); // mathml
    v0064 = (*qfnn(fn))(qenv(fn), 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    v0052 = v0064;
    v0064 = v0052;
    if (v0064 == nil) goto v0045;
    stack[0] = v0052;
    v0064 = CC_plusrd(env, 0);
    nil = C_nil;
    if (exception_pending()) goto v0047;
    env = stack[-1];
    {
        LispObject v0039 = stack[0];
        popv(2);
        fn = elt(env, 3); // alg_plus
        return (*qfn2(fn))(qenv(fn), v0039, v0064);
    }

v0045:
    v0064 = (LispObject)1; // 0
    { popv(2); return onevalue(v0064); }
// error exit handlers
v0047:
    popv(2);
    return nil;
}



// Code for simpu

static LispObject CC_simpu(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055, v0056;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpu");
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
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    v0056 = v0000;
// end of prologue
    stack[-1] = elt(env, 1); // u
    v0055 = v0056;
    stack[0] = qcar(v0055);
    v0055 = v0056;
    v0055 = qcdr(v0055);
    fn = elt(env, 2); // ordn
    v0055 = (*qfn1(fn))(qenv(fn), v0055);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-2];
    v0055 = Lreverse(nil, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-2];
    v0056 = list2star(stack[-1], stack[0], v0055);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-2];
    v0055 = (LispObject)17; // 1
    fn = elt(env, 3); // mksp
    v0056 = (*qfn2(fn))(qenv(fn), v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-2];
    v0055 = (LispObject)17; // 1
    v0055 = cons(v0056, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    env = stack[-2];
    v0056 = ncons(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0017;
    v0055 = (LispObject)17; // 1
    popv(3);
    return cons(v0056, v0055);
// error exit handlers
v0017:
    popv(3);
    return nil;
}



// Code for o!-nextarg

static LispObject CC_oKnextarg(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0285, v0189;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for o-nextarg");
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
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0000;
// end of prologue
    v0285 = qvalue(elt(env, 1)); // !*udebug
    if (v0285 == nil) goto v0201;
    v0285 = qvalue(elt(env, 2)); // nil
    fn = elt(env, 12); // uprint
    v0285 = (*qfn1(fn))(qenv(fn), v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    goto v0201;

v0201:
    v0189 = qvalue(elt(env, 3)); // i
    v0285 = (LispObject)17; // 1
    if (v0189 == v0285) goto v0049;
    v0285 = qvalue(elt(env, 2)); // nil
    goto v0044;

v0044:
    if (v0285 == nil) goto v0063;
    v0285 = stack[-1];
    goto v0025;

v0025:
    stack[0] = v0285;
    v0285 = qvalue(elt(env, 3)); // i
    v0285 = add1(v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    qvalue(elt(env, 3)) = v0285; // i
    { LispObject res = stack[0]; popv(4); return onevalue(res); }

v0063:
    v0189 = qvalue(elt(env, 3)); // i
    v0285 = (LispObject)1; // 0
    if (v0189 == v0285) goto v0046;
    v0285 = qvalue(elt(env, 2)); // nil
    goto v0057;

v0057:
    if (v0285 == nil) goto v0056;
    v0189 = elt(env, 5); // (null!-fn)
    v0285 = stack[-1];
    v0285 = cons(v0189, v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    goto v0025;

v0056:
    v0285 = qvalue(elt(env, 6)); // acontract
    if (v0285 == nil) goto v0211;
    v0189 = qvalue(elt(env, 3)); // i
    v0285 = qvalue(elt(env, 4)); // upb
    v0285 = (LispObject)lesseq2(v0189, v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    v0285 = v0285 ? lisp_true : nil;
    env = stack[-3];
    if (v0285 == nil) goto v0211;
    stack[-2] = qvalue(elt(env, 7)); // op
    v0189 = stack[-1];
    v0285 = qvalue(elt(env, 3)); // i
    fn = elt(env, 13); // first0
    stack[0] = (*qfn2(fn))(qenv(fn), v0189, v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    v0189 = stack[-1];
    v0285 = qvalue(elt(env, 3)); // i
    fn = elt(env, 14); // last0
    v0285 = (*qfn2(fn))(qenv(fn), v0189, v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    v0285 = acons(stack[-2], stack[0], v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    fn = elt(env, 15); // mval
    v0285 = (*qfn1(fn))(qenv(fn), v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    goto v0025;

v0211:
    v0285 = qvalue(elt(env, 8)); // mcontract
    if (v0285 == nil) goto v0196;
    v0189 = qvalue(elt(env, 3)); // i
    v0285 = qvalue(elt(env, 4)); // upb
    v0285 = (LispObject)lesseq2(v0189, v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    v0285 = v0285 ? lisp_true : nil;
    env = stack[-3];
    if (v0285 == nil) goto v0196;
    stack[-2] = elt(env, 9); // null!-fn
    v0189 = stack[-1];
    v0285 = qvalue(elt(env, 3)); // i
    fn = elt(env, 13); // first0
    stack[0] = (*qfn2(fn))(qenv(fn), v0189, v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    v0189 = stack[-1];
    v0285 = qvalue(elt(env, 3)); // i
    fn = elt(env, 14); // last0
    v0285 = (*qfn2(fn))(qenv(fn), v0189, v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    v0285 = acons(stack[-2], stack[0], v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    goto v0025;

v0196:
    v0285 = qvalue(elt(env, 10)); // expand
    if (v0285 == nil) goto v0204;
    v0285 = qvalue(elt(env, 2)); // nil
    qvalue(elt(env, 10)) = v0285; // expand
    v0189 = qvalue(elt(env, 11)); // identity
    v0285 = stack[-1];
    v0285 = cons(v0189, v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    env = stack[-3];
    goto v0025;

v0204:
    v0285 = nil;
    goto v0025;

v0046:
    v0189 = qvalue(elt(env, 3)); // i
    v0285 = qvalue(elt(env, 4)); // upb
    v0285 = (LispObject)lesseq2(v0189, v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    v0285 = v0285 ? lisp_true : nil;
    env = stack[-3];
    goto v0057;

v0049:
    v0189 = qvalue(elt(env, 3)); // i
    v0285 = qvalue(elt(env, 4)); // upb
    v0285 = (LispObject)lesseq2(v0189, v0285);
    nil = C_nil;
    if (exception_pending()) goto v0230;
    v0285 = v0285 ? lisp_true : nil;
    env = stack[-3];
    goto v0044;
// error exit handlers
v0230:
    popv(4);
    return nil;
}



// Code for find_bubles_coeff

static LispObject CC_find_bubles_coeff(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0156, v0198, v0201, v0118;
    LispObject fn;
    LispObject v0032, v0001, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "find_bubles_coeff");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0001 = va_arg(aa, LispObject);
    v0032 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find_bubles_coeff");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0156 = v0032;
    v0198 = v0001;
    v0201 = v0000;
// end of prologue
    v0118 = v0201;
    v0201 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // find_bubles1_coeff
        return (*qfnn(fn))(qenv(fn), 4, v0118, v0201, v0198, v0156);
    }
}



// Code for lieninstruc

static LispObject CC_lieninstruc(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0283, v0284, v0223, v0185;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lieninstruc");
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
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-4] = v0000;
// end of prologue
    v0283 = (LispObject)17; // 1
    stack[-5] = v0283;
    goto v0048;

v0048:
    stack[0] = elt(env, 1); // difference
    v0223 = elt(env, 1); // difference
    v0284 = stack[-4];
    v0283 = (LispObject)17; // 1
    v0283 = list3(v0223, v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 7); // aeval!*
    v0284 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0283 = stack[-5];
    v0283 = list3(stack[0], v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 8); // aminusp!:
    v0283 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    if (v0283 == nil) goto v0050;
    v0283 = nil;
    { popv(7); return onevalue(v0283); }

v0050:
    v0283 = stack[-5];
    v0283 = add1(v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[-3] = v0283;
    goto v0147;

v0147:
    stack[0] = elt(env, 1); // difference
    v0283 = stack[-4];
    fn = elt(env, 7); // aeval!*
    v0284 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0283 = stack[-3];
    v0283 = list3(stack[0], v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 8); // aminusp!:
    v0283 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    if (v0283 == nil) goto v0018;
    v0283 = stack[-5];
    v0223 = elt(env, 6); // plus
    v0284 = v0283;
    v0283 = (LispObject)17; // 1
    v0283 = list3(v0223, v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 7); // aeval!*
    v0283 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[-5] = v0283;
    goto v0048;

v0018:
    v0283 = (LispObject)17; // 1
    stack[-2] = v0283;
    goto v0211;

v0211:
    stack[0] = elt(env, 1); // difference
    v0283 = stack[-4];
    fn = elt(env, 7); // aeval!*
    v0284 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0283 = stack[-2];
    v0283 = list3(stack[0], v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 8); // aminusp!:
    v0283 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    if (v0283 == nil) goto v0163;
    v0283 = stack[-3];
    v0223 = elt(env, 6); // plus
    v0284 = v0283;
    v0283 = (LispObject)17; // 1
    v0283 = list3(v0223, v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 7); // aeval!*
    v0283 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[-3] = v0283;
    goto v0147;

v0163:
    v0185 = elt(env, 3); // lie_cc
    v0223 = stack[-5];
    v0284 = stack[-3];
    v0283 = stack[-2];
    stack[0] = list4(v0185, v0223, v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0185 = elt(env, 4); // lienstrucin
    v0223 = stack[-5];
    v0284 = stack[-3];
    v0283 = stack[-2];
    v0283 = list4(v0185, v0223, v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 7); // aeval!*
    v0283 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 9); // setk
    v0283 = (*qfn2(fn))(qenv(fn), stack[0], v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0185 = elt(env, 3); // lie_cc
    v0223 = stack[-3];
    v0284 = stack[-5];
    v0283 = stack[-2];
    stack[-1] = list4(v0185, v0223, v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[0] = elt(env, 5); // minus
    v0185 = elt(env, 4); // lienstrucin
    v0223 = stack[-5];
    v0284 = stack[-3];
    v0283 = stack[-2];
    v0283 = list4(v0185, v0223, v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0283 = list2(stack[0], v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 7); // aeval!*
    v0283 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 9); // setk
    v0283 = (*qfn2(fn))(qenv(fn), stack[-1], v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    v0283 = stack[-2];
    v0223 = elt(env, 6); // plus
    v0284 = v0283;
    v0283 = (LispObject)17; // 1
    v0283 = list3(v0223, v0284, v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    fn = elt(env, 7); // aeval!*
    v0283 = (*qfn1(fn))(qenv(fn), v0283);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[-6];
    stack[-2] = v0283;
    goto v0211;
// error exit handlers
v0097:
    popv(7);
    return nil;
}



// Code for balance_mod

static LispObject CC_balance_mod(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0153, v0149;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for balance_mod");
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
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0149 = stack[-1];
    v0153 = stack[-1];
    v0149 = plus2(v0149, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    env = stack[-2];
    v0153 = stack[0];
    v0153 = (LispObject)greaterp2(v0149, v0153);
    nil = C_nil;
    if (exception_pending()) goto v0016;
    v0153 = v0153 ? lisp_true : nil;
    if (v0153 == nil) { LispObject res = stack[-1]; popv(3); return onevalue(res); }
    v0149 = stack[-1];
    v0153 = stack[0];
    popv(3);
    return difference2(v0149, v0153);
// error exit handlers
v0016:
    popv(3);
    return nil;
}



// Code for appr

static LispObject CC_appr(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0020, v0049, v0021;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for appr");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0020 = v0001;
    v0049 = v0000;
// end of prologue

v0024:
    v0021 = v0049;
    if (v0021 == nil) { popv(2); return onevalue(v0020); }
    v0021 = v0049;
    v0021 = qcdr(v0021);
    stack[0] = v0021;
    v0049 = qcar(v0049);
    v0020 = cons(v0049, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    v0049 = stack[0];
    goto v0024;
// error exit handlers
v0054:
    popv(2);
    return nil;
}



// Code for co_hfn

static LispObject CC_co_hfn(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for co_hfn");
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
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    fn = elt(env, 1); // cl_fvarl1
    stack[-1] = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-2];
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    fn = elt(env, 2); // rl_atnum
    v0065 = (*qfn1(fn))(qenv(fn), v0065);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    {
        LispObject v0156 = stack[-1];
        popv(3);
        return list2(v0156, v0065);
    }
// error exit handlers
v0044:
    popv(3);
    return nil;
}



// Code for cl_sordpl

static LispObject CC_cl_sordpl(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0017, v0018, v0063, v0062;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_sordpl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0018 = v0001;
    v0063 = v0000;
// end of prologue

v0150:
    v0017 = v0018;
    if (v0017 == nil) goto v0045;
    v0017 = v0063;
    if (v0017 == nil) goto v0027;
    v0017 = v0063;
    v0062 = qcar(v0017);
    v0017 = v0018;
    v0017 = qcar(v0017);
    if (equal(v0062, v0017)) goto v0016;
    v0017 = v0063;
    v0017 = qcar(v0017);
    v0018 = qcar(v0018);
    {
        fn = elt(env, 3); // cl_sordp
        return (*qfn2(fn))(qenv(fn), v0017, v0018);
    }

v0016:
    v0017 = v0063;
    v0017 = qcdr(v0017);
    v0063 = v0017;
    v0017 = v0018;
    v0017 = qcdr(v0017);
    v0018 = v0017;
    goto v0150;

v0027:
    v0017 = qvalue(elt(env, 2)); // t
    return onevalue(v0017);

v0045:
    v0017 = qvalue(elt(env, 1)); // nil
    return onevalue(v0017);
}



// Code for expf

static LispObject CC_expf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0183, v0135, v0222;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expf");
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
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0001;
    stack[-1] = v0000;
// end of prologue
    v0183 = stack[-1];
    if (v0183 == nil) goto v0150;
    v0135 = stack[-1];
    v0183 = (LispObject)17; // 1
    if (v0135 == v0183) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0183 = stack[-1];
    if (!consp(v0183)) goto v0052;
    v0183 = stack[-1];
    if (!consp(v0183)) goto v0057;
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0183 = (consp(v0183) ? nil : lisp_true);
    goto v0051;

v0051:
    if (v0183 == nil) goto v0055;
    v0135 = stack[-1];
    v0183 = stack[0];
    {
        popv(4);
        fn = elt(env, 5); // !:expt
        return (*qfn2(fn))(qenv(fn), v0135, v0183);
    }

v0055:
    v0183 = stack[-1];
    v0183 = qcdr(v0183);
    if (v0183 == nil) goto v0320;
    v0135 = stack[-1];
    v0183 = stack[0];
    {
        popv(4);
        fn = elt(env, 6); // mksp!*
        return (*qfn2(fn))(qenv(fn), v0135, v0183);
    }

v0320:
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0183 = qcar(v0183);
    v0135 = qcdr(v0183);
    v0183 = qvalue(elt(env, 3)); // frlis!*
    v0183 = Lmemq(nil, v0135, v0183);
    if (v0183 == nil) goto v0131;
    v0222 = elt(env, 4); // expt
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0183 = qcar(v0183);
    v0135 = qcar(v0183);
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0183 = qcar(v0183);
    v0183 = qcdr(v0183);
    v0183 = list3(v0222, v0135, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    fn = elt(env, 7); // fkern
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    v0135 = qcar(v0183);
    v0183 = stack[0];
    fn = elt(env, 8); // to
    stack[-2] = (*qfn2(fn))(qenv(fn), v0135, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0135 = qcdr(v0183);
    v0183 = stack[0];
    v0183 = CC_expf(env, v0135, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    v0183 = cons(stack[-2], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    popv(4);
    return ncons(v0183);

v0131:
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0183 = qcar(v0183);
    v0135 = qcdr(v0183);
    v0183 = stack[0];
    v0183 = times2(v0135, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    stack[-2] = v0183;
    v0135 = stack[-2];
    v0183 = (LispObject)1; // 0
    v0183 = (LispObject)greaterp2(v0135, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    v0183 = v0183 ? lisp_true : nil;
    env = stack[-3];
    if (v0183 == nil) goto v0098;
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0183 = qcar(v0183);
    v0183 = qcar(v0183);
    fn = elt(env, 9); // sfp
    v0183 = (*qfn1(fn))(qenv(fn), v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    if (v0183 == nil) goto v0098;
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0183 = qcar(v0183);
    v0135 = qcar(v0183);
    v0183 = stack[-2];
    fn = elt(env, 10); // exptf
    stack[-2] = (*qfn2(fn))(qenv(fn), v0135, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0135 = qcdr(v0183);
    v0183 = stack[0];
    v0183 = CC_expf(env, v0135, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    {
        LispObject v0322 = stack[-2];
        popv(4);
        fn = elt(env, 11); // multf
        return (*qfn2(fn))(qenv(fn), v0322, v0183);
    }

v0098:
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0183 = qcar(v0183);
    v0135 = qcar(v0183);
    v0183 = stack[-2];
    fn = elt(env, 8); // to
    stack[-2] = (*qfn2(fn))(qenv(fn), v0135, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    v0183 = stack[-1];
    v0183 = qcar(v0183);
    v0135 = qcdr(v0183);
    v0183 = stack[0];
    v0183 = CC_expf(env, v0135, v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    v0183 = cons(stack[-2], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    popv(4);
    return ncons(v0183);

v0057:
    v0183 = qvalue(elt(env, 2)); // t
    goto v0051;

v0052:
    stack[-2] = (LispObject)17; // 1
    v0183 = stack[0];
    v0183 = negate(v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    v0183 = Lexpt(nil, stack[-1], v0183);
    nil = C_nil;
    if (exception_pending()) goto v0321;
    env = stack[-3];
    {
        LispObject v0307 = stack[-2];
        popv(4);
        fn = elt(env, 12); // mkrn
        return (*qfn2(fn))(qenv(fn), v0307, v0183);
    }

v0150:
    v0183 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0183); }
// error exit handlers
v0321:
    popv(4);
    return nil;
}



// Code for pasf_premf

static LispObject CC_pasf_premf(LispObject env,
                         LispObject v0000, LispObject v0001)
{
    LispObject nil = C_nil;
    LispObject v0156, v0198;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pasf_premf");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0001;
    v0156 = v0000;
// end of prologue
    v0198 = v0156;
    v0156 = stack[0];
    fn = elt(env, 1); // remf
    v0198 = (*qfn2(fn))(qenv(fn), v0198, v0156);
    nil = C_nil;
    if (exception_pending()) goto v0118;
    env = stack[-1];
    v0156 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // pasf_premf1
        return (*qfn2(fn))(qenv(fn), v0198, v0156);
    }
// error exit handlers
v0118:
    popv(2);
    return nil;
}



// Code for lto_sgnchg1

static LispObject CC_lto_sgnchg1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0017;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_sgnchg1");
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
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue

v0033:
    v0017 = stack[0];
    if (v0017 == nil) goto v0019;
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    v0017 = (v0017 == nil ? lisp_true : nil);
    goto v0050;

v0050:
    if (v0017 == nil) goto v0052;
    v0017 = (LispObject)1; // 0
    { popv(3); return onevalue(v0017); }

v0052:
    v0017 = stack[0];
    v0017 = qcar(v0017);
    fn = elt(env, 2); // sgn
    stack[-1] = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-2];
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    v0017 = qcar(v0017);
    fn = elt(env, 2); // sgn
    v0017 = (*qfn1(fn))(qenv(fn), v0017);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    env = stack[-2];
    if (stack[-1] == v0017) goto v0118;
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    v0017 = CC_lto_sgnchg1(env, v0017);
    nil = C_nil;
    if (exception_pending()) goto v0062;
    popv(3);
    return add1(v0017);

v0118:
    v0017 = stack[0];
    v0017 = qcdr(v0017);
    stack[0] = v0017;
    goto v0033;

v0019:
    v0017 = qvalue(elt(env, 1)); // t
    goto v0050;
// error exit handlers
v0062:
    popv(3);
    return nil;
}



// Code for conditionml

static LispObject CC_conditionml(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0048;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for conditionml");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0000;
// end of prologue
    v0048 = elt(env, 1); // "<condition>"
    fn = elt(env, 5); // printout
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0048 = qvalue(elt(env, 2)); // t
    fn = elt(env, 6); // indent!*
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0048 = stack[0];
    v0048 = qcar(v0048);
    fn = elt(env, 7); // expression
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0048 = qvalue(elt(env, 3)); // nil
    fn = elt(env, 6); // indent!*
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    v0048 = elt(env, 4); // "</condition>"
    fn = elt(env, 5); // printout
    v0048 = (*qfn1(fn))(qenv(fn), v0048);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    v0048 = nil;
    { popv(2); return onevalue(v0048); }
// error exit handlers
v0044:
    popv(2);
    return nil;
}



// Code for rnfix!*

static LispObject CC_rnfixH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0065, v0048;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnfix*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0065 = v0000;
// end of prologue
    v0048 = v0065;
    v0048 = qcdr(v0048);
    v0048 = qcar(v0048);
    v0065 = qcdr(v0065);
    v0065 = qcdr(v0065);
    return quot2(v0048, v0065);
}



// Code for dip2a

static LispObject CC_dip2a(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0025, v0065;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dip2a");
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
// copy arguments values to proper place
    v0065 = v0000;
// end of prologue
    v0025 = v0065;
    if (v0025 == nil) goto v0033;
    v0025 = v0065;
    fn = elt(env, 1); // dip2a1
    v0025 = (*qfn1(fn))(qenv(fn), v0025);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // dipreplus
        return (*qfn1(fn))(qenv(fn), v0025);
    }

v0033:
    v0025 = (LispObject)1; // 0
    { popv(1); return onevalue(v0025); }
// error exit handlers
v0048:
    popv(1);
    return nil;
}



// Code for mkexdf

static LispObject CC_mkexdf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0047, v0039;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkexdf");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0047 = v0000;
// end of prologue
    v0039 = elt(env, 1); // d
    v0047 = list2(v0039, v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    stack[0] = v0047;
    fn = elt(env, 2); // opmtch
    v0047 = (*qfn1(fn))(qenv(fn), v0047);
    nil = C_nil;
    if (exception_pending()) goto v0049;
    env = stack[-1];
    v0039 = v0047;
    if (v0047 == nil) goto v0118;
    v0047 = v0039;
    {
        popv(2);
        fn = elt(env, 3); // partitop
        return (*qfn1(fn))(qenv(fn), v0047);
    }

v0118:
    v0047 = stack[0];
    {
        popv(2);
        fn = elt(env, 4); // mkupf
        return (*qfn1(fn))(qenv(fn), v0047);
    }
// error exit handlers
v0049:
    popv(2);
    return nil;
}



setup_type const u40_setup[] =
{
    {"inszzz",                  too_few_2,      CC_inszzz,     wrong_no_2},
    {"listpri",                 CC_listpri,     too_many_1,    wrong_no_1},
    {"gfdiffer",                too_few_2,      CC_gfdiffer,   wrong_no_2},
    {"evalwhereexp",            CC_evalwhereexp,too_many_1,    wrong_no_1},
    {"splitup",                 too_few_2,      CC_splitup,    wrong_no_2},
    {"simpdfp",                 CC_simpdfp,     too_many_1,    wrong_no_1},
    {"list2vect*",              too_few_2,      CC_list2vectH, wrong_no_2},
    {"random-teeny-prime",      CC_randomKteenyKprime,too_many_1,wrong_no_1},
    {"subtractinds",            wrong_no_na,    wrong_no_nb,   (n_args *)CC_subtractinds},
    {"cl_sacatlp",              too_few_2,      CC_cl_sacatlp, wrong_no_2},
    {"ciom",                    CC_ciom,        too_many_1,    wrong_no_1},
    {"insertocc",               too_few_2,      CC_insertocc,  wrong_no_2},
    {"new_simpexpt",            CC_new_simpexpt,too_many_1,    wrong_no_1},
    {"a2vdp",                   CC_a2vdp,       too_many_1,    wrong_no_1},
    {"xreadlist",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_xreadlist},
    {"physoppri",               CC_physoppri,   too_many_1,    wrong_no_1},
    {"consrecip",               CC_consrecip,   too_many_1,    wrong_no_1},
    {"nonmult",                 CC_nonmult,     too_many_1,    wrong_no_1},
    {"extadd",                  too_few_2,      CC_extadd,     wrong_no_2},
    {"xnp",                     too_few_2,      CC_xnp,        wrong_no_2},
    {"super_vectorfield",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_super_vectorfield},
    {"rl_sacatlp",              too_few_2,      CC_rl_sacatlp, wrong_no_2},
    {"cgp_greenp",              CC_cgp_greenp,  too_many_1,    wrong_no_1},
    {"prsubsetrd",              CC_prsubsetrd,  too_many_1,    wrong_no_1},
    {"f4",                      CC_f4,          too_many_1,    wrong_no_1},
    {"findoptrow",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_findoptrow},
    {"reduce-columns",          wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduceKcolumns},
    {"gadd",                    wrong_no_na,    wrong_no_nb,   (n_args *)CC_gadd},
    {"cl_nnfnot",               CC_cl_nnfnot,   too_many_1,    wrong_no_1},
    {"rtypepart",               CC_rtypepart,   too_many_1,    wrong_no_1},
    {"mk+equation",             too_few_2,      CC_mkLequation,wrong_no_2},
    {"freeof-dfl",              too_few_2,      CC_freeofKdfl, wrong_no_2},
    {"pasf_or",                 CC_pasf_or,     too_many_1,    wrong_no_1},
    {"integralir",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_integralir},
    {"plusrd",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_plusrd},
    {"simpu",                   CC_simpu,       too_many_1,    wrong_no_1},
    {"o-nextarg",               CC_oKnextarg,   too_many_1,    wrong_no_1},
    {"find_bubles_coeff",       wrong_no_na,    wrong_no_nb,   (n_args *)CC_find_bubles_coeff},
    {"lieninstruc",             CC_lieninstruc, too_many_1,    wrong_no_1},
    {"balance_mod",             too_few_2,      CC_balance_mod,wrong_no_2},
    {"appr",                    too_few_2,      CC_appr,       wrong_no_2},
    {"co_hfn",                  CC_co_hfn,      too_many_1,    wrong_no_1},
    {"cl_sordpl",               too_few_2,      CC_cl_sordpl,  wrong_no_2},
    {"expf",                    too_few_2,      CC_expf,       wrong_no_2},
    {"pasf_premf",              too_few_2,      CC_pasf_premf, wrong_no_2},
    {"lto_sgnchg1",             CC_lto_sgnchg1, too_many_1,    wrong_no_1},
    {"conditionml",             CC_conditionml, too_many_1,    wrong_no_1},
    {"rnfix*",                  CC_rnfixH,      too_many_1,    wrong_no_1},
    {"dip2a",                   CC_dip2a,       too_many_1,    wrong_no_1},
    {"mkexdf",                  CC_mkexdf,      too_many_1,    wrong_no_1},
    {NULL, (one_args *)"u40", (two_args *)"15299 577433 4230038", 0}
};

// end of generated code