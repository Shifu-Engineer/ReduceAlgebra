
// $destdir/u01.c        Machine generated C code

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



// Code for reval

static LispObject CC_reval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0004 = v0003;
    v0003 = qvalue(elt(env, 1)); // t
    {
        fn = elt(env, 2); // reval1
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



// Code for simpcar

static LispObject CC_simpcar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for simpcar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0005 = v0000;
// end of prologue
    v0005 = qcar(v0005);
    {
        fn = elt(env, 1); // simp
        return (*qfn1(fn))(qenv(fn), v0005);
    }
}



// Code for noncomp

static LispObject CC_noncomp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0000;
// end of prologue
    v0006 = qvalue(elt(env, 1)); // !*ncmp
    if (v0006 == nil) goto v0008;
    v0006 = v0007;
    {
        fn = elt(env, 3); // noncomp1
        return (*qfn1(fn))(qenv(fn), v0006);
    }

v0008:
    v0006 = qvalue(elt(env, 2)); // nil
    return onevalue(v0006);
}



// Code for num!-exponents

static LispObject CC_numKexponents(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0010;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for num-exponents");
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

v0011:
    v0010 = stack[0];
    if (!consp(v0010)) goto v0001;
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0010 = (consp(v0010) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0010 == nil) goto v0013;
    v0010 = qvalue(elt(env, 1)); // t
    { popv(2); return onevalue(v0010); }

v0013:
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0010 = qcar(v0010);
    v0010 = qcdr(v0010);
    v0010 = integerp(v0010);
    if (v0010 == nil) goto v0014;
    v0010 = stack[0];
    v0010 = qcar(v0010);
    v0010 = qcdr(v0010);
    v0010 = CC_numKexponents(env, v0010);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    if (v0010 == nil) goto v0016;
    v0010 = stack[0];
    v0010 = qcdr(v0010);
    stack[0] = v0010;
    goto v0011;

v0016:
    v0010 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0010); }

v0014:
    v0010 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0010); }

v0001:
    v0010 = qvalue(elt(env, 1)); // t
    goto v0012;
// error exit handlers
v0015:
    popv(2);
    return nil;
}



// Code for argsofopr

static LispObject CC_argsofopr(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0008;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for argsofopr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0008 = v0000;
// end of prologue
    if (!symbolp(v0008)) v0008 = nil;
    else { v0008 = qfastgets(v0008);
           if (v0008 != nil) { v0008 = elt(v0008, 42); // number!-of!-args
#ifdef RECORD_GET
             if (v0008 != SPID_NOPROP)
                record_get(elt(fastget_names, 42), 1);
             else record_get(elt(fastget_names, 42), 0),
                v0008 = nil; }
           else record_get(elt(fastget_names, 42), 0); }
#else
             if (v0008 == SPID_NOPROP) v0008 = nil; }}
#endif
    return onevalue(v0008);
}



// Code for smember

static LispObject CC_smember(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0022, v0023;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smember");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue

v0012:
    v0023 = stack[-1];
    v0022 = stack[0];
    if (equal(v0023, v0022)) goto v0005;
    v0022 = stack[0];
    if (!consp(v0022)) goto v0024;
    v0023 = stack[-1];
    v0022 = stack[0];
    v0022 = qcar(v0022);
    v0022 = CC_smember(env, v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0010;
    env = stack[-2];
    if (!(v0022 == nil)) { popv(3); return onevalue(v0022); }
    v0023 = stack[-1];
    v0022 = stack[0];
    v0022 = qcdr(v0022);
    stack[-1] = v0023;
    stack[0] = v0022;
    goto v0012;

v0024:
    v0022 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0022); }

v0005:
    v0022 = qvalue(elt(env, 1)); // t
    { popv(3); return onevalue(v0022); }
// error exit handlers
v0010:
    popv(3);
    return nil;
}



// Code for !*n2f

static LispObject CC_Hn2f(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *n2f");
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
    v0006 = v0000;
// end of prologue
    v0007 = v0006;
    v0007 = (LispObject)zerop(v0007);
    v0007 = v0007 ? lisp_true : nil;
    env = stack[0];
    if (v0007 == nil) { popv(1); return onevalue(v0006); }
    v0006 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0006); }
}



// Code for lalr_move_dot

static LispObject CC_lalr_move_dot(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0035, v0036, v0037;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_move_dot");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0007;

v0007:
    v0035 = stack[-1];
    v0036 = qcar(v0035);
    v0035 = elt(env, 1); // !.
    if (v0036 == v0035) goto v0012;
    v0035 = stack[-1];
    v0036 = qcar(v0035);
    v0035 = stack[-2];
    v0035 = cons(v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-3];
    stack[-2] = v0035;
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    goto v0007;

v0012:
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    v0035 = stack[-1];
    if (v0035 == nil) goto v0039;
    v0035 = stack[-1];
    v0036 = qcar(v0035);
    v0035 = stack[0];
    if (!(equal(v0036, v0035))) goto v0039;
    v0035 = stack[-1];
    v0037 = qcar(v0035);
    v0036 = elt(env, 1); // !.
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    v0035 = list2star(v0037, v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-3];
    stack[-1] = v0035;
    goto v0040;

v0040:
    v0035 = stack[-2];
    if (v0035 == nil) { LispObject res = stack[-1]; popv(4); return onevalue(res); }
    v0035 = stack[-2];
    v0036 = qcar(v0035);
    v0035 = stack[-1];
    v0035 = cons(v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-3];
    stack[-1] = v0035;
    v0035 = stack[-2];
    v0035 = qcdr(v0035);
    stack[-2] = v0035;
    goto v0040;

v0039:
    v0035 = qvalue(elt(env, 2)); // nil
    { popv(4); return onevalue(v0035); }
// error exit handlers
v0038:
    popv(4);
    return nil;
}



// Code for mkvar

static LispObject CC_mkvar(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject v0008, v0005;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkvar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0008 = v0017;
    v0005 = v0000;
// end of prologue
    return onevalue(v0005);
}



// Code for multf

static LispObject CC_multf(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0044, v0045, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0045 = v0017;
    v0046 = v0000;
// end of prologue
    v0044 = qvalue(elt(env, 1)); // !*physop!-loaded
    if (v0044 == nil) goto v0033;
    v0044 = v0046;
    {
        fn = elt(env, 2); // physop!-multf
        return (*qfn2(fn))(qenv(fn), v0044, v0045);
    }

v0033:
    v0044 = v0046;
    {
        fn = elt(env, 3); // poly!-multf
        return (*qfn2(fn))(qenv(fn), v0044, v0045);
    }
}



// Code for monomgetvariabledegree

static LispObject CC_monomgetvariabledegree(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0030, v0028;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomgetvariabledegree");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    v0030 = v0000;
// end of prologue
    v0028 = v0030;
    v0030 = (LispObject)17; // 1
    v0030 = *(LispObject *)((char *)v0028 + (CELL-TAG_VECTOR) + ((int32_t)v0030/(16/CELL)));
    stack[-1] = v0030;
    goto v0050;

v0050:
    v0030 = stack[-1];
    v0030 = qcar(v0030);
    if (v0030 == nil) goto v0024;
    v0030 = stack[-1];
    v0028 = qcar(v0030);
    v0030 = stack[0];
    v0030 = (LispObject)greaterp2(v0028, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0051;
    v0030 = v0030 ? lisp_true : nil;
    env = stack[-2];
    if (v0030 == nil) goto v0024;
    v0030 = stack[-1];
    v0030 = qcdr(v0030);
    stack[-1] = v0030;
    goto v0050;

v0024:
    v0030 = stack[-1];
    v0030 = qcar(v0030);
    if (v0030 == nil) goto v0052;
    v0030 = stack[-1];
    v0028 = qcar(v0030);
    v0030 = stack[0];
    if (!(equal(v0028, v0030))) goto v0052;
    v0030 = (LispObject)17; // 1
    { popv(3); return onevalue(v0030); }

v0052:
    v0030 = (LispObject)1; // 0
    { popv(3); return onevalue(v0030); }
// error exit handlers
v0051:
    popv(3);
    return nil;
}



// Code for quotelist

static LispObject CC_quotelist(LispObject env,
                         LispObject v0000)
{
    LispObject v0027;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0027 = v0000;
// end of prologue
    v0027 = elt(env, 1); // list
    return onevalue(v0027);
}



// Code for wuconstantp

static LispObject CC_wuconstantp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0019, v0049;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wuconstantp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0049 = v0000;
// end of prologue
    v0019 = v0049;
    if (!consp(v0019)) goto v0001;
    v0019 = v0049;
    v0019 = qcar(v0019);
    v0019 = (consp(v0019) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0019 == nil) goto v0034;
    v0019 = qvalue(elt(env, 1)); // t
    return onevalue(v0019);

v0034:
    v0019 = v0049;
    v0019 = qcar(v0019);
    v0019 = qcar(v0019);
    v0019 = qcar(v0019);
    v0049 = qvalue(elt(env, 2)); // wuvarlist!*
    v0019 = Lmemq(nil, v0019, v0049);
    v0019 = (v0019 == nil ? lisp_true : nil);
    return onevalue(v0019);

v0001:
    v0019 = qvalue(elt(env, 1)); // t
    goto v0012;
}



// Code for mkcopy

static LispObject CC_mkcopy(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0049, v0016;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkcopy");
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
    stack[-1] = nil;
    goto v0005;

v0005:
    v0049 = stack[0];
    if (!consp(v0049)) goto v0006;
    v0049 = stack[0];
    v0049 = qcar(v0049);
    v0016 = CC_mkcopy(env, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    v0049 = stack[-1];
    v0049 = cons(v0016, v0049);
    nil = C_nil;
    if (exception_pending()) goto v0039;
    env = stack[-2];
    stack[-1] = v0049;
    v0049 = stack[0];
    v0049 = qcdr(v0049);
    stack[0] = v0049;
    goto v0005;

v0006:
    v0016 = stack[-1];
    v0049 = stack[0];
    {
        popv(3);
        fn = elt(env, 1); // nreverse
        return (*qfn2(fn))(qenv(fn), v0016, v0049);
    }
// error exit handlers
v0039:
    popv(3);
    return nil;
}



// Code for mchkopt

static LispObject CC_mchkopt(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0056, v0041, v0042, v0044;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchkopt");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0042 = v0017;
    v0044 = v0000;
// end of prologue
    v0056 = v0042;
    v0056 = qcar(v0056);
    if (!symbolp(v0056)) v0056 = nil;
    else { v0056 = qfastgets(v0056);
           if (v0056 != nil) { v0056 = elt(v0056, 6); // optional
#ifdef RECORD_GET
             if (v0056 != SPID_NOPROP)
                record_get(elt(fastget_names, 6), 1);
             else record_get(elt(fastget_names, 6), 0),
                v0056 = nil; }
           else record_get(elt(fastget_names, 6), 0); }
#else
             if (v0056 == SPID_NOPROP) v0056 = nil; }}
#endif
    v0041 = v0056;
    v0056 = v0041;
    if (v0056 == nil) goto v0003;
    v0056 = v0044;
    {
        fn = elt(env, 1); // mchkopt1
        return (*qfnn(fn))(qenv(fn), 3, v0056, v0042, v0041);
    }

v0003:
    v0056 = nil;
    return onevalue(v0056);
}



// Code for revpr

static LispObject CC_revpr(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for revpr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0000;
// end of prologue
    v0007 = v0006;
    v0007 = qcdr(v0007);
    v0006 = qcar(v0006);
    return cons(v0007, v0006);
}



// Code for nth

static LispObject CC_nth(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for nth");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0006 = v0017;
    v0007 = v0000;
// end of prologue
    fn = elt(env, 1); // pnth
    v0006 = (*qfn2(fn))(qenv(fn), v0007, v0006);
    errexit();
    v0006 = qcar(v0006);
    return onevalue(v0006);
}



// Code for kernels

static LispObject CC_kernels(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernels");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0004 = v0003;
    v0003 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // kernels1
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



// Code for qqe_rqopp

static LispObject CC_qqe_rqopp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_rqopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0004 = elt(env, 1); // (qequal qneq)
    v0003 = Lmemq(nil, v0003, v0004);
    return onevalue(v0003);
}



// Code for ibalp_clmember

static LispObject CC_ibalp_clmember(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0019, v0049;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_clmember");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue

v0011:
    v0019 = stack[0];
    if (v0019 == nil) goto v0005;
    v0049 = stack[-1];
    v0019 = stack[0];
    v0019 = qcar(v0019);
    fn = elt(env, 2); // ibalp_cequal
    v0019 = (*qfn2(fn))(qenv(fn), v0049, v0019);
    nil = C_nil;
    if (exception_pending()) goto v0058;
    env = stack[-2];
    if (!(v0019 == nil)) { popv(3); return onevalue(v0019); }
    v0049 = stack[-1];
    v0019 = stack[0];
    v0019 = qcdr(v0019);
    stack[-1] = v0049;
    stack[0] = v0019;
    goto v0011;

v0005:
    v0019 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0019); }
// error exit handlers
v0058:
    popv(3);
    return nil;
}



// Code for noncomfp

static LispObject CC_noncomfp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomfp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0000;
// end of prologue
    v0006 = qvalue(elt(env, 1)); // !*ncmp
    if (v0006 == nil) goto v0008;
    v0006 = v0007;
    {
        fn = elt(env, 3); // noncomfp1
        return (*qfn1(fn))(qenv(fn), v0006);
    }

v0008:
    v0006 = qvalue(elt(env, 2)); // nil
    return onevalue(v0006);
}



// Code for delall

static LispObject CC_delall(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0060, v0061;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delall");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue

v0005:
    v0060 = stack[0];
    if (v0060 == nil) goto v0001;
    v0061 = stack[-1];
    v0060 = stack[0];
    v0060 = qcar(v0060);
    if (equal(v0061, v0060)) goto v0006;
    v0060 = stack[0];
    v0060 = qcar(v0060);
    stack[-2] = ncons(v0060);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    env = stack[-3];
    v0061 = stack[-1];
    v0060 = stack[0];
    v0060 = qcdr(v0060);
    v0060 = CC_delall(env, v0061, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0031;
    {
        LispObject v0062 = stack[-2];
        popv(4);
        return Lappend(nil, v0062, v0060);
    }

v0006:
    v0060 = stack[0];
    v0060 = qcdr(v0060);
    stack[0] = v0060;
    goto v0005;

v0001:
    v0060 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0060); }
// error exit handlers
v0031:
    popv(4);
    return nil;
}



// Code for terminalp

static LispObject CC_terminalp(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0004;
    argcheck(nargs, 0, "terminalp");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for terminalp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0004 = qvalue(elt(env, 1)); // !*int
    if (v0004 == nil) goto v0027;
    v0004 = qvalue(elt(env, 3)); // ifl!*
    v0004 = (v0004 == nil ? lisp_true : nil);
    return onevalue(v0004);

v0027:
    v0004 = qvalue(elt(env, 2)); // nil
    return onevalue(v0004);
}



// Code for ordop

static LispObject CC_ordop(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0030, v0028, v0064, v0029, v0051;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordop");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0029 = v0017;
    v0051 = v0000;
// end of prologue
    v0030 = qvalue(elt(env, 1)); // !*physop!-loaded
    if (v0030 == nil) goto v0050;
    v0030 = v0051;
    v0028 = v0029;
    {
        fn = elt(env, 5); // physop!-ordop
        return (*qfn2(fn))(qenv(fn), v0030, v0028);
    }

v0050:
    v0030 = qvalue(elt(env, 2)); // kord!*
    v0064 = v0030;
    goto v0055;

v0055:
    v0030 = v0064;
    if (v0030 == nil) goto v0032;
    v0028 = v0051;
    v0030 = v0064;
    v0030 = qcar(v0030);
    if (v0028 == v0030) goto v0058;
    v0028 = v0029;
    v0030 = v0064;
    v0030 = qcar(v0030);
    if (v0028 == v0030) goto v0065;
    v0030 = v0064;
    v0030 = qcdr(v0030);
    v0064 = v0030;
    goto v0055;

v0065:
    v0030 = qvalue(elt(env, 4)); // nil
    return onevalue(v0030);

v0058:
    v0030 = qvalue(elt(env, 3)); // t
    return onevalue(v0030);

v0032:
    v0030 = v0051;
    v0028 = v0029;
    {
        fn = elt(env, 6); // ordp
        return (*qfn2(fn))(qenv(fn), v0030, v0028);
    }
}



// Code for prepf

static LispObject CC_prepf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepf");
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
    v0004 = v0000;
// end of prologue
    v0006 = v0004;
    v0004 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // prepf1a
    v0004 = (*qfn2(fn))(qenv(fn), v0006, v0004);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 3); // replus1
        return (*qfn1(fn))(qenv(fn), v0004);
    }
// error exit handlers
v0007:
    popv(1);
    return nil;
}



// Code for c!:ordxp

static LispObject CC_cTordxp(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0023, v0060, v0061;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c:ordxp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0023 = v0017;
    v0060 = v0000;
// end of prologue
    v0061 = v0060;
    v0061 = Lconsp(nil, v0061);
    env = stack[0];
    if (v0061 == nil) goto v0009;
    v0061 = v0023;
    v0061 = Lconsp(nil, v0061);
    env = stack[0];
    if (v0061 == nil) goto v0042;
    v0060 = qcdr(v0060);
    v0023 = qcdr(v0023);
        popv(1);
        return Llessp(nil, v0060, v0023);

v0042:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0023); }

v0009:
    v0061 = v0023;
    v0061 = Lconsp(nil, v0061);
    env = stack[0];
    if (v0061 == nil) goto v0021;
    v0023 = qvalue(elt(env, 2)); // t
    { popv(1); return onevalue(v0023); }

v0021:
        popv(1);
        return Llessp(nil, v0060, v0023);
}



// Code for zero2nil

static LispObject CC_zero2nil(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for zero2nil");
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
    v0006 = stack[0];
    fn = elt(env, 2); // !:zerop
    v0006 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0043;
    env = stack[-1];
    if (v0006 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0006 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0006); }
// error exit handlers
v0043:
    popv(2);
    return nil;
}



// Code for ordad

static LispObject CC_ordad(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0066, v0067;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ordad");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0001;

v0001:
    v0066 = stack[0];
    if (v0066 == nil) goto v0068;
    v0067 = stack[-1];
    v0066 = stack[0];
    v0066 = qcar(v0066);
    fn = elt(env, 2); // ordp
    v0066 = (*qfn2(fn))(qenv(fn), v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    if (!(v0066 == nil)) goto v0068;
    v0066 = stack[0];
    v0067 = qcar(v0066);
    v0066 = stack[-2];
    v0066 = cons(v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    stack[-2] = v0066;
    v0066 = stack[0];
    v0066 = qcdr(v0066);
    stack[0] = v0066;
    goto v0001;

v0068:
    v0067 = stack[-1];
    v0066 = stack[0];
    v0066 = cons(v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    stack[0] = v0066;
    goto v0065;

v0065:
    v0066 = stack[-2];
    if (v0066 == nil) { LispObject res = stack[0]; popv(4); return onevalue(res); }
    v0066 = stack[-2];
    v0066 = qcdr(v0066);
    stack[-1] = v0066;
    v0067 = stack[-2];
    v0066 = stack[0];
    v0066 = Lrplacd(nil, v0067, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    v0066 = stack[-2];
    stack[0] = v0066;
    v0066 = stack[-1];
    stack[-2] = v0066;
    goto v0065;
// error exit handlers
v0069:
    popv(4);
    return nil;
}



// Code for mval

static LispObject CC_mval(LispObject env,
                         LispObject v0000)
{
    LispObject v0027;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0027 = v0000;
// end of prologue
    return onevalue(v0027);
}



// Code for evcomp

static LispObject CC_evcomp(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0013, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0013 = v0017;
    v0033 = v0000;
// end of prologue
    stack[0] = qvalue(elt(env, 1)); // dipsortevcomp!*
    v0013 = list2(v0033, v0013);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    {
        LispObject v0014 = stack[0];
        popv(2);
        fn = elt(env, 2); // apply
        return (*qfn2(fn))(qenv(fn), v0014, v0013);
    }
// error exit handlers
v0055:
    popv(2);
    return nil;
}



// Code for evmatrixcomp2

static LispObject CC_evmatrixcomp2(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0080, v0081, v0082, v0083;
    LispObject fn;
    LispObject v0053, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "evmatrixcomp2");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    v0053 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evmatrixcomp2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0053;
    stack[-1] = v0017;
    stack[-2] = v0000;
// end of prologue

v0011:
    v0080 = stack[-2];
    if (v0080 == nil) goto v0003;
    v0080 = stack[-1];
    v0080 = (v0080 == nil ? lisp_true : nil);
    goto v0002;

v0002:
    if (!(v0080 == nil)) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0080 = stack[-1];
    v0080 = qcar(v0080);
    stack[-3] = v0080;
    v0081 = stack[-3];
    v0080 = (LispObject)1; // 0
    fn = elt(env, 2); // iequal
    v0080 = (*qfn2(fn))(qenv(fn), v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    if (v0080 == nil) goto v0048;
    v0080 = stack[-2];
    v0082 = qcdr(v0080);
    v0080 = stack[-1];
    v0081 = qcdr(v0080);
    v0080 = stack[0];
    stack[-2] = v0082;
    stack[-1] = v0081;
    stack[0] = v0080;
    goto v0011;

v0048:
    v0081 = stack[-3];
    v0080 = (LispObject)17; // 1
    fn = elt(env, 2); // iequal
    v0080 = (*qfn2(fn))(qenv(fn), v0081, v0080);
    nil = C_nil;
    if (exception_pending()) goto v0084;
    env = stack[-4];
    if (v0080 == nil) goto v0085;
    v0080 = stack[-2];
    v0083 = qcdr(v0080);
    v0080 = stack[-1];
    v0082 = qcdr(v0080);
    v0081 = stack[0];
    v0080 = stack[-2];
    v0080 = qcar(v0080);
    v0080 = (LispObject)(int32_t)((int32_t)v0081 + (int32_t)v0080 - TAG_FIXNUM);
    stack[-2] = v0083;
    stack[-1] = v0082;
    stack[0] = v0080;
    goto v0011;

v0085:
    v0083 = stack[-2];
    v0082 = stack[-3];
    v0081 = stack[-1];
    v0080 = stack[0];
    {
        popv(5);
        fn = elt(env, 3); // evmatrixcomp3
        return (*qfnn(fn))(qenv(fn), 4, v0083, v0082, v0081, v0080);
    }

v0003:
    v0080 = qvalue(elt(env, 1)); // t
    goto v0002;
// error exit handlers
v0084:
    popv(5);
    return nil;
}



// Code for xval

static LispObject CC_xval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0009;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for xval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0009 = v0000;
// end of prologue
    v0009 = qcar(v0009);
    v0009 = qcar(v0009);
    {
        fn = elt(env, 1); // wedgefax
        return (*qfn1(fn))(qenv(fn), v0009);
    }
}



// Code for times!:

static LispObject CC_timesT(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0058, v0039;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for times:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0017;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = elt(env, 1); // !:rd!:
    v0058 = stack[-2];
    v0058 = qcdr(v0058);
    v0039 = qcar(v0058);
    v0058 = stack[-1];
    v0058 = qcdr(v0058);
    v0058 = qcar(v0058);
    stack[0] = times2(v0039, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-4];
    v0058 = stack[-2];
    v0058 = qcdr(v0058);
    v0039 = qcdr(v0058);
    v0058 = stack[-1];
    v0058 = qcdr(v0058);
    v0058 = qcdr(v0058);
    v0058 = plus2(v0039, v0058);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    {
        LispObject v0023 = stack[-3];
        LispObject v0060 = stack[0];
        popv(5);
        return list2star(v0023, v0060, v0058);
    }
// error exit handlers
v0022:
    popv(5);
    return nil;
}



// Code for convprec

static LispObject CC_convprec(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for convprec");
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
    v0005 = v0000;
// end of prologue
    fn = elt(env, 1); // round!*
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // convchk
        return (*qfn1(fn))(qenv(fn), v0005);
    }
// error exit handlers
v0009:
    popv(1);
    return nil;
}



// Code for physopp

static LispObject CC_physopp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0061, v0010;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for physopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0010 = v0000;
// end of prologue
    v0061 = v0010;
    if (!consp(v0061)) goto v0008;
    v0061 = v0010;
    v0061 = qcar(v0061);
    if (symbolp(v0061)) goto v0059;
    v0061 = qvalue(elt(env, 1)); // nil
    return onevalue(v0061);

v0059:
    v0061 = v0010;
    v0061 = qcar(v0061);
    if (!symbolp(v0061)) v0061 = nil;
    else { v0061 = qfastgets(v0061);
           if (v0061 != nil) { v0061 = elt(v0061, 2); // rtype
#ifdef RECORD_GET
             if (v0061 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0061 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0061 == SPID_NOPROP) v0061 = nil; }}
#endif
    v0010 = elt(env, 2); // physop
    v0061 = (v0061 == v0010 ? lisp_true : nil);
    return onevalue(v0061);

v0008:
    v0061 = v0010;
    if (symbolp(v0061)) goto v0024;
    v0061 = qvalue(elt(env, 1)); // nil
    return onevalue(v0061);

v0024:
    v0061 = v0010;
    if (!symbolp(v0061)) v0061 = nil;
    else { v0061 = qfastgets(v0061);
           if (v0061 != nil) { v0061 = elt(v0061, 2); // rtype
#ifdef RECORD_GET
             if (v0061 != SPID_NOPROP)
                record_get(elt(fastget_names, 2), 1);
             else record_get(elt(fastget_names, 2), 0),
                v0061 = nil; }
           else record_get(elt(fastget_names, 2), 0); }
#else
             if (v0061 == SPID_NOPROP) v0061 = nil; }}
#endif
    v0010 = elt(env, 2); // physop
    v0061 = (v0061 == v0010 ? lisp_true : nil);
    return onevalue(v0061);
}



// Code for memq_edgelist

static LispObject CC_memq_edgelist(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for memq_edgelist");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0017;
    v0007 = v0000;
// end of prologue
    v0007 = qcar(v0007);
    v0006 = Lassoc(nil, v0007, v0006);
    return onevalue(v0006);
}



// Code for mo_comp

static LispObject CC_mo_comp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0043, v0024;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_comp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0043 = v0000;
// end of prologue
    v0024 = v0043;
    v0024 = qcar(v0024);
    if (v0024 == nil) goto v0008;
    v0043 = qcar(v0043);
    v0043 = qcar(v0043);
    return onevalue(v0043);

v0008:
    v0043 = (LispObject)1; // 0
    return onevalue(v0043);
}



// Code for c_zero

static LispObject CC_c_zero(LispObject env, int nargs, ...)
{
    LispObject v0053;
    argcheck(nargs, 0, "c_zero");
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for c_zero");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// end of prologue
    v0053 = qvalue(elt(env, 1)); // nil
    return onevalue(v0053);
}



// Code for sieve_pv0

static LispObject CC_sieve_pv0(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0040, v0066, v0067;
    LispObject fn;
    LispObject v0053, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sieve_pv0");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    v0053 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sieve_pv0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0053;
    stack[-1] = v0017;
    stack[-2] = v0000;
// end of prologue
    v0040 = stack[-2];
    if (!(v0040 == nil)) goto v0043;
    v0040 = qvalue(elt(env, 1)); // nil
    { popv(4); return onevalue(v0040); }

v0043:
    v0040 = stack[-1];
    if (v0040 == nil) goto v0086;
    v0040 = stack[-1];
    v0040 = qcar(v0040);
    v0040 = qcar(v0040);
    v0066 = qcdr(v0040);
    v0040 = stack[-2];
    v0040 = qcar(v0040);
    v0040 = qcdr(v0040);
    v0040 = (LispObject)greaterp2(v0066, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    v0040 = v0040 ? lisp_true : nil;
    env = stack[-3];
    if (v0040 == nil) goto v0086;
    v0040 = stack[-1];
    v0040 = qcdr(v0040);
    stack[-1] = v0040;
    goto v0043;

v0086:
    v0040 = stack[-2];
    if (v0040 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0040 = stack[-1];
    if (v0040 == nil) { LispObject res = stack[-2]; popv(4); return onevalue(res); }
    v0067 = stack[-2];
    v0040 = stack[-1];
    v0066 = qcar(v0040);
    v0040 = stack[0];
    fn = elt(env, 2); // reduce_pv0
    v0040 = (*qfnn(fn))(qenv(fn), 3, v0067, v0066, v0040);
    nil = C_nil;
    if (exception_pending()) goto v0069;
    env = stack[-3];
    stack[-2] = v0040;
    v0040 = stack[-1];
    v0040 = qcdr(v0040);
    stack[-1] = v0040;
    goto v0086;
// error exit handlers
v0069:
    popv(4);
    return nil;
}



// Code for listp

static LispObject CC_listp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055, v0014;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for listp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0055 = v0000;
// end of prologue

v0011:
    v0014 = v0055;
    if (v0014 == nil) goto v0008;
    v0014 = v0055;
    if (!consp(v0014)) goto v0013;
    v0055 = qcdr(v0055);
    goto v0011;

v0013:
    v0055 = qvalue(elt(env, 2)); // nil
    return onevalue(v0055);

v0008:
    v0055 = qvalue(elt(env, 1)); // t
    return onevalue(v0055);
}



// Code for modzerop!:

static LispObject CC_modzeropT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0006;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modzerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0004 = v0000;
// end of prologue
    v0006 = qcdr(v0004);
    v0004 = (LispObject)1; // 0
    v0004 = (v0006 == v0004 ? lisp_true : nil);
    return onevalue(v0004);
}



// Code for aeval

static LispObject CC_aeval(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aeval");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0004 = v0003;
    v0003 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // reval1
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



// Code for lalr_closure

static LispObject CC_lalr_closure(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0099, v0100, v0101;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_closure");
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
    v0099 = stack[-8];
    stack[-9] = v0099;
    goto v0007;

v0007:
    v0099 = stack[-9];
    if (v0099 == nil) { LispObject res = stack[-8]; popv(11); return onevalue(res); }
    v0099 = stack[-9];
    v0099 = qcar(v0099);
    stack[-6] = v0099;
    v0099 = stack[-9];
    v0099 = qcdr(v0099);
    stack[-9] = v0099;
    v0099 = stack[-6];
    v0099 = qcar(v0099);
    v0100 = stack[-6];
    v0100 = qcdr(v0100);
    v0100 = qcar(v0100);
    v0101 = v0100;
    v0100 = elt(env, 2); // !.
    v0099 = Lmember(nil, v0100, v0099);
    v0099 = qcdr(v0099);
    stack[-7] = v0099;
    v0099 = stack[-7];
    if (v0099 == nil) goto v0007;
    v0099 = stack[-7];
    v0099 = qcar(v0099);
    if (is_number(v0099)) goto v0007;
    v0099 = stack[-7];
    stack[0] = qcdr(v0099);
    v0099 = v0101;
    v0099 = ncons(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    v0099 = Lappend(nil, stack[0], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    fn = elt(env, 4); // lalr_first
    v0099 = (*qfn1(fn))(qenv(fn), v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    stack[-6] = v0099;
    v0099 = stack[-7];
    v0100 = qcar(v0099);
    v0099 = elt(env, 3); // produces
    v0099 = get(v0100, v0099);
    env = stack[-10];
    stack[-5] = v0099;
    goto v0028;

v0028:
    v0099 = stack[-5];
    if (v0099 == nil) goto v0007;
    v0099 = stack[-5];
    v0099 = qcar(v0099);
    stack[-4] = v0099;
    v0099 = stack[-6];
    stack[-3] = v0099;
    goto v0085;

v0085:
    v0099 = stack[-3];
    if (v0099 == nil) goto v0103;
    v0099 = stack[-3];
    v0099 = qcar(v0099);
    stack[-2] = v0099;
    v0099 = stack[-7];
    stack[-1] = qcar(v0099);
    v0100 = elt(env, 2); // !.
    v0099 = stack[-4];
    v0099 = qcar(v0099);
    stack[0] = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    v0099 = stack[-2];
    v0099 = ncons(v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    v0099 = acons(stack[-1], stack[0], v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    stack[0] = v0099;
    v0100 = stack[0];
    v0099 = stack[-8];
    v0099 = Lmember(nil, v0100, v0099);
    if (!(v0099 == nil)) goto v0104;
    v0100 = stack[0];
    v0099 = stack[-8];
    v0099 = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    stack[-8] = v0099;
    v0100 = stack[0];
    v0099 = stack[-9];
    v0099 = cons(v0100, v0099);
    nil = C_nil;
    if (exception_pending()) goto v0102;
    env = stack[-10];
    stack[-9] = v0099;
    goto v0104;

v0104:
    v0099 = stack[-3];
    v0099 = qcdr(v0099);
    stack[-3] = v0099;
    goto v0085;

v0103:
    v0099 = stack[-5];
    v0099 = qcdr(v0099);
    stack[-5] = v0099;
    goto v0028;
// error exit handlers
v0102:
    popv(11);
    return nil;
}



// Code for monomcompare

static LispObject CC_monomcompare(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0063, v0098, v0052, v0074;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for monomcompare");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0052 = v0017;
    v0074 = v0000;
// end of prologue
    v0098 = qvalue(elt(env, 1)); // fluidbibasismonomialorder
    v0063 = elt(env, 2); // lex
    if (v0098 == v0063) goto v0054;
    v0098 = qvalue(elt(env, 1)); // fluidbibasismonomialorder
    v0063 = elt(env, 4); // deglex
    if (v0098 == v0063) goto v0059;
    v0063 = v0074;
    v0098 = v0052;
    {
        fn = elt(env, 5); // monomcomparedegrevlex
        return (*qfn2(fn))(qenv(fn), v0063, v0098);
    }

v0059:
    v0063 = v0074;
    v0098 = v0052;
    {
        fn = elt(env, 6); // monomcomparedeglex
        return (*qfn2(fn))(qenv(fn), v0063, v0098);
    }

v0054:
    v0063 = v0074;
    v0098 = v0052;
    {
        fn = elt(env, 7); // monomcomparelex
        return (*qfn2(fn))(qenv(fn), v0063, v0098);
    }
}



// Code for quotf

static LispObject CC_quotf(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0007, v0043, v0024;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for quotf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0043 = v0017;
    v0024 = v0000;
// end of prologue
    v0007 = qvalue(elt(env, 1)); // t
    stack[0] = qvalue(elt(env, 2)); // !*exp
    qvalue(elt(env, 2)) = v0007; // !*exp
    v0007 = v0024;
    fn = elt(env, 3); // quotf1
    v0007 = (*qfn2(fn))(qenv(fn), v0007, v0043);
    nil = C_nil;
    if (exception_pending()) goto v0054;
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*exp
    { popv(2); return onevalue(v0007); }
// error exit handlers
v0054:
    env = stack[-1];
    qvalue(elt(env, 2)) = stack[0]; // !*exp
    popv(2);
    return nil;
}



// Code for mchk!*

static LispObject CC_mchkH(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0023, v0060;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mchk*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue
    v0060 = stack[-1];
    v0023 = stack[0];
    fn = elt(env, 3); // mchk
    v0023 = (*qfn2(fn))(qenv(fn), v0060, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0060 = v0023;
    if (!(v0023 == nil)) { popv(3); return onevalue(v0060); }
    v0023 = qvalue(elt(env, 1)); // !*mcd
    if (!(v0023 == nil)) goto v0033;
    v0023 = stack[-1];
    fn = elt(env, 4); // sfp
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    if (v0023 == nil) goto v0033;
    v0023 = stack[0];
    fn = elt(env, 4); // sfp
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    if (v0023 == nil) goto v0033;
    v0023 = stack[-1];
    fn = elt(env, 5); // prepf
    stack[-1] = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    v0023 = stack[0];
    fn = elt(env, 5); // prepf
    v0023 = (*qfn1(fn))(qenv(fn), v0023);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    {
        LispObject v0015 = stack[-1];
        popv(3);
        fn = elt(env, 3); // mchk
        return (*qfn2(fn))(qenv(fn), v0015, v0023);
    }

v0033:
    v0023 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0023); }
// error exit handlers
v0065:
    popv(3);
    return nil;
}



// Code for get!+mat!+entry

static LispObject CC_getLmatLentry(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0055, v0014;
    LispObject fn;
    LispObject v0053, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "get+mat+entry");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    v0053 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get+mat+entry");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0053;
    v0055 = v0017;
    v0014 = v0000;
// end of prologue
    fn = elt(env, 1); // nth
    v0014 = (*qfn2(fn))(qenv(fn), v0014, v0055);
    nil = C_nil;
    if (exception_pending()) goto v0041;
    env = stack[-1];
    v0055 = stack[0];
    {
        popv(2);
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0014, v0055);
    }
// error exit handlers
v0041:
    popv(2);
    return nil;
}



// Code for powers

static LispObject CC_powers(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for powers");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0004 = v0003;
    v0003 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // powers0
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



// Code for lto_hashequalq

static LispObject CC_lto_hashequalq(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0107, v0108;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_hashequalq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0017;
    stack[-3] = v0000;
// end of prologue
    v0107 = (LispObject)1; // 0
    stack[-1] = v0107;
    v0107 = (LispObject)1; // 0
    stack[0] = v0107;
    goto v0007;

v0007:
    v0107 = stack[-3];
    if (v0107 == nil) goto v0006;
    v0107 = stack[-2];
    if (v0107 == nil) goto v0006;
    v0107 = stack[-3];
    v0107 = qcar(v0107);
    v0108 = v0107;
    v0107 = stack[-2];
    v0107 = qcar(v0107);
    stack[-4] = v0107;
    v0107 = stack[-3];
    v0107 = qcdr(v0107);
    stack[-3] = v0107;
    v0107 = stack[-2];
    v0107 = qcdr(v0107);
    stack[-2] = v0107;
    v0107 = v0108;
    fn = elt(env, 2); // lto_hashid
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-5];
    v0107 = (LispObject)(int32_t)((int32_t)stack[-1] + (int32_t)v0107 - TAG_FIXNUM);
    stack[-1] = v0107;
    v0107 = stack[-4];
    fn = elt(env, 2); // lto_hashid
    v0107 = (*qfn1(fn))(qenv(fn), v0107);
    nil = C_nil;
    if (exception_pending()) goto v0025;
    env = stack[-5];
    v0107 = (LispObject)(int32_t)((int32_t)stack[0] + (int32_t)v0107 - TAG_FIXNUM);
    stack[0] = v0107;
    goto v0007;

v0006:
    v0107 = stack[-3];
    if (v0107 == nil) goto v0105;
    v0107 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0107); }

v0105:
    v0107 = stack[-2];
    if (v0107 == nil) goto v0030;
    v0107 = qvalue(elt(env, 1)); // nil
    { popv(6); return onevalue(v0107); }

v0030:
    v0108 = stack[-1];
    v0107 = stack[0];
    {
        popv(6);
        fn = elt(env, 3); // iequal
        return (*qfn2(fn))(qenv(fn), v0108, v0107);
    }
// error exit handlers
v0025:
    popv(6);
    return nil;
}



// Code for find2

static LispObject CC_find2(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0061, v0010, v0065, v0015;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for find2");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0010 = v0017;
    v0065 = v0000;
// end of prologue

v0002:
    v0015 = v0010;
    v0061 = nil;
    if (v0015 == v0061) goto v0012;
    v0061 = v0010;
    v0061 = qcar(v0061);
    v0065 = Lmember(nil, v0061, v0065);
    v0061 = v0010;
    v0061 = qcdr(v0061);
    v0010 = v0061;
    goto v0002;

v0012:
    v0061 = v0065;
    if (v0061 == nil) goto v0056;
    v0061 = v0065;
    v0061 = qcdr(v0061);
    return onevalue(v0061);

v0056:
    v0061 = elt(env, 1); // (stop)
    return onevalue(v0061);
}



// Code for exchk

static LispObject CC_exchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0050, v0054, v0013, v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for exchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0050 = v0000;
// end of prologue
    v0033 = v0050;
    v0013 = qvalue(elt(env, 1)); // nil
    v0054 = qvalue(elt(env, 1)); // nil
    v0050 = qvalue(elt(env, 1)); // nil
    {
        fn = elt(env, 2); // exchk1
        return (*qfnn(fn))(qenv(fn), 4, v0033, v0013, v0054, v0050);
    }
}



// Code for pm!:free

static LispObject CC_pmTfree(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pm:free");
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
    v0004 = v0000;
// end of prologue
    fn = elt(env, 2); // binding
    v0004 = (*qfn1(fn))(qenv(fn), v0004);
    nil = C_nil;
    if (exception_pending()) goto v0007;
    env = stack[0];
    v0006 = elt(env, 1); // unbound
    v0004 = (v0004 == v0006 ? lisp_true : nil);
    { popv(1); return onevalue(v0004); }
// error exit handlers
v0007:
    popv(1);
    return nil;
}



// Code for vbcsize

static LispObject CC_vbcsize(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0015, v0031, v0062;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for vbcsize");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0031 = v0017;
    stack[0] = v0000;
// end of prologue

v0012:
    v0062 = v0031;
    v0015 = (LispObject)-15; // -1
    if (((int32_t)(v0062)) > ((int32_t)(v0015))) goto v0005;
    v0015 = stack[0];
    if (!consp(v0015)) { popv(2); return onevalue(v0031); }
    v0015 = stack[0];
    v0015 = qcar(v0015);
    v0031 = (LispObject)((int32_t)(v0031) + 0x10);
    v0015 = CC_vbcsize(env, v0015, v0031);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-1];
    v0031 = v0015;
    v0015 = v0031;
    if (v0015 == nil) goto v0059;
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    stack[0] = v0015;
    goto v0012;

v0059:
    v0015 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0015); }

v0005:
    v0015 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0015); }
// error exit handlers
v0048:
    popv(2);
    return nil;
}



// Code for pnth

static LispObject CC_pnth(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0068, v0021, v0086;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pnth");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0021 = v0017;
    stack[0] = v0000;
// end of prologue

v0005:
    v0068 = stack[0];
    if (v0068 == nil) goto v0006;
    v0086 = v0021;
    v0068 = (LispObject)17; // 1
    if (v0086 == v0068) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    stack[0] = v0068;
    v0068 = v0021;
    v0068 = sub1(v0068);
    nil = C_nil;
    if (exception_pending()) goto v0022;
    env = stack[-1];
    v0021 = v0068;
    goto v0005;

v0006:
    v0086 = elt(env, 1); // alg
    v0021 = (LispObject)97; // 6
    v0068 = elt(env, 2); // "Index out of range"
    {
        popv(2);
        fn = elt(env, 3); // rerror
        return (*qfnn(fn))(qenv(fn), 3, v0086, v0021, v0068);
    }
// error exit handlers
v0022:
    popv(2);
    return nil;
}



// Code for wedgefax

static LispObject CC_wedgefax(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0034, v0055, v0014;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wedgefax");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0055 = v0000;
// end of prologue
    v0034 = v0055;
    v0014 = elt(env, 1); // wedge
    if (!consp(v0034)) goto v0050;
    v0034 = qcar(v0034);
    if (!(v0034 == v0014)) goto v0050;
    v0034 = v0055;
    v0034 = qcdr(v0034);
    return onevalue(v0034);

v0050:
    v0034 = v0055;
    return ncons(v0034);
}



// Code for !*physopp

static LispObject CC_Hphysopp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0057, v0019;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *physopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0019 = v0000;
// end of prologue
    v0057 = v0019;
    if (!consp(v0057)) goto v0008;
    v0057 = v0019;
    v0057 = qcar(v0057);
    if (symbolp(v0057)) goto v0044;
    v0057 = qvalue(elt(env, 1)); // nil
    return onevalue(v0057);

v0044:
    v0057 = v0019;
    v0057 = qcar(v0057);
    if (!symbolp(v0057)) v0057 = nil;
    else { v0057 = qfastgets(v0057);
           if (v0057 != nil) { v0057 = elt(v0057, 18); // phystype
#ifdef RECORD_GET
             if (v0057 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0057 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0057 == SPID_NOPROP) v0057 = nil; }}
#endif
    return onevalue(v0057);

v0008:
    v0057 = v0019;
    if (symbolp(v0057)) goto v0007;
    v0057 = qvalue(elt(env, 1)); // nil
    return onevalue(v0057);

v0007:
    v0057 = v0019;
    if (!symbolp(v0057)) v0057 = nil;
    else { v0057 = qfastgets(v0057);
           if (v0057 != nil) { v0057 = elt(v0057, 18); // phystype
#ifdef RECORD_GET
             if (v0057 != SPID_NOPROP)
                record_get(elt(fastget_names, 18), 1);
             else record_get(elt(fastget_names, 18), 0),
                v0057 = nil; }
           else record_get(elt(fastget_names, 18), 0); }
#else
             if (v0057 == SPID_NOPROP) v0057 = nil; }}
#endif
    return onevalue(v0057);
}



// Code for wideid2list

static LispObject CC_wideid2list(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for wideid2list");
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
    v0005 = v0000;
// end of prologue
    fn = elt(env, 1); // id2string
    v0005 = (*qfn1(fn))(qenv(fn), v0005);
    nil = C_nil;
    if (exception_pending()) goto v0009;
    env = stack[0];
    {
        popv(1);
        fn = elt(env, 2); // widestring2list
        return (*qfn1(fn))(qenv(fn), v0005);
    }
// error exit handlers
v0009:
    popv(1);
    return nil;
}



// Code for termsf

static LispObject CC_termsf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015, v0031;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for termsf");
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
    v0015 = (LispObject)1; // 0
    v0031 = v0015;
    goto v0001;

v0001:
    v0015 = stack[0];
    if (!consp(v0015)) goto v0024;
    v0015 = stack[0];
    v0015 = qcar(v0015);
    v0015 = (consp(v0015) ? nil : lisp_true);
    goto v0043;

v0043:
    if (v0015 == nil) goto v0044;
    v0015 = stack[0];
    if (v0015 == nil) { popv(3); return onevalue(v0031); }
    v0015 = v0031;
    popv(3);
    return add1(v0015);

v0044:
    stack[-1] = v0031;
    v0015 = stack[0];
    v0015 = qcar(v0015);
    v0015 = qcdr(v0015);
    v0015 = CC_termsf(env, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    v0015 = plus2(stack[-1], v0015);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    env = stack[-2];
    v0031 = v0015;
    v0015 = stack[0];
    v0015 = qcdr(v0015);
    stack[0] = v0015;
    goto v0001;

v0024:
    v0015 = qvalue(elt(env, 1)); // t
    goto v0043;
// error exit handlers
v0048:
    popv(3);
    return nil;
}



// Code for mkspm

static LispObject CC_mkspm(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0074, v0075;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkspm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue
    v0075 = stack[0];
    v0074 = (LispObject)1; // 0
    if (v0075 == v0074) goto v0005;
    v0074 = qvalue(elt(env, 1)); // subfg!*
    if (v0074 == nil) goto v0055;
    v0075 = stack[-1];
    v0074 = qvalue(elt(env, 2)); // asymplis!*
    v0074 = Latsoc(nil, v0075, v0074);
    v0075 = v0074;
    if (v0074 == nil) goto v0055;
    v0074 = v0075;
    v0075 = qcdr(v0074);
    v0074 = stack[0];
    v0074 = (LispObject)lesseq2(v0075, v0074);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    v0074 = v0074 ? lisp_true : nil;
    env = stack[-2];
    if (v0074 == nil) goto v0055;
    v0074 = qvalue(elt(env, 3)); // nil
    { popv(3); return onevalue(v0074); }

v0055:
    v0074 = stack[-1];
    fn = elt(env, 4); // sub2chk
    v0074 = (*qfn1(fn))(qenv(fn), v0074);
    nil = C_nil;
    if (exception_pending()) goto v0028;
    env = stack[-2];
    v0075 = stack[-1];
    v0074 = stack[0];
    {
        popv(3);
        fn = elt(env, 5); // to
        return (*qfn2(fn))(qenv(fn), v0075, v0074);
    }

v0005:
    v0074 = (LispObject)17; // 1
    { popv(3); return onevalue(v0074); }
// error exit handlers
v0028:
    popv(3);
    return nil;
}



// Code for dssoc

static LispObject CC_dssoc(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0032, v0018, v0057, v0019;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dssoc");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0057 = v0017;
    v0019 = v0000;
// end of prologue

v0005:
    v0032 = v0057;
    if (v0032 == nil) goto v0001;
    v0018 = v0019;
    v0032 = v0057;
    v0032 = qcar(v0032);
    v0032 = qcdr(v0032);
    if (equal(v0018, v0032)) goto v0006;
    v0032 = v0057;
    v0032 = qcdr(v0032);
    v0057 = v0032;
    goto v0005;

v0006:
    v0032 = v0057;
    v0032 = qcar(v0032);
    return onevalue(v0032);

v0001:
    v0032 = qvalue(elt(env, 1)); // nil
    return onevalue(v0032);
}



// Code for noncomlistp

static LispObject CC_noncomlistp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0034;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomlistp");
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

v0011:
    v0034 = stack[0];
    v0034 = Lconsp(nil, v0034);
    env = stack[-1];
    if (v0034 == nil) goto v0008;
    v0034 = stack[0];
    v0034 = qcar(v0034);
    fn = elt(env, 2); // noncomp1
    v0034 = (*qfn1(fn))(qenv(fn), v0034);
    nil = C_nil;
    if (exception_pending()) goto v0014;
    env = stack[-1];
    if (!(v0034 == nil)) { popv(2); return onevalue(v0034); }
    v0034 = stack[0];
    v0034 = qcdr(v0034);
    stack[0] = v0034;
    goto v0011;

v0008:
    v0034 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0034); }
// error exit handlers
v0014:
    popv(2);
    return nil;
}



// Code for rnzerop!:

static LispObject CC_rnzeropT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnzerop:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0000;
// end of prologue
    v0006 = qcdr(v0006);
    v0007 = qcar(v0006);
    v0006 = (LispObject)1; // 0
    v0006 = (v0007 == v0006 ? lisp_true : nil);
    return onevalue(v0006);
}



// Code for mksp

static LispObject CC_mksp(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mksp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    stack[0] = v0017;
    v0006 = v0000;
// end of prologue
    fn = elt(env, 1); // fkern
    v0007 = (*qfn1(fn))(qenv(fn), v0006);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-1];
    v0006 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // getpower
        return (*qfn2(fn))(qenv(fn), v0007, v0006);
    }
// error exit handlers
v0024:
    popv(2);
    return nil;
}



// Code for getrtypeor

static LispObject CC_getrtypeor(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrtypeor");
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

v0011:
    v0033 = stack[0];
    if (v0033 == nil) goto v0008;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    fn = elt(env, 2); // getrtype
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    if (!(v0033 == nil)) { popv(2); return onevalue(v0033); }
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0011;

v0008:
    v0033 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0033); }
// error exit handlers
v0055:
    popv(2);
    return nil;
}



// Code for lalr_goto

static LispObject CC_lalr_goto(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0052, v0074;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_goto");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0017;
    v0052 = v0000;
// end of prologue
    stack[-3] = nil;
    stack[-1] = v0052;
    goto v0003;

v0003:
    v0052 = stack[-1];
    if (v0052 == nil) goto v0002;
    v0052 = stack[-1];
    v0052 = qcar(v0052);
    stack[0] = v0052;
    v0052 = stack[0];
    v0074 = qcar(v0052);
    v0052 = stack[-2];
    fn = elt(env, 2); // lalr_move_dot
    v0052 = (*qfn2(fn))(qenv(fn), v0074, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0074 = v0052;
    v0052 = v0074;
    if (v0052 == nil) goto v0057;
    v0052 = stack[0];
    v0052 = qcdr(v0052);
    v0052 = qcar(v0052);
    v0074 = list2(v0074, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    v0052 = stack[-3];
    v0052 = cons(v0074, v0052);
    nil = C_nil;
    if (exception_pending()) goto v0064;
    env = stack[-4];
    stack[-3] = v0052;
    goto v0057;

v0057:
    v0052 = stack[-1];
    v0052 = qcdr(v0052);
    stack[-1] = v0052;
    goto v0003;

v0002:
    v0052 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); // lalr_closure
        return (*qfn1(fn))(qenv(fn), v0052);
    }
// error exit handlers
v0064:
    popv(5);
    return nil;
}



// Code for addcomment

static LispObject CC_addcomment(LispObject env,
                         LispObject v0000)
{
    LispObject v0027;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addcomment");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0027 = v0000;
// end of prologue
    qvalue(elt(env, 1)) = v0027; // cursym!*
    return onevalue(v0027);
}



// Code for setkorder

static LispObject CC_setkorder(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0056, v0041;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for setkorder");
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
    v0041 = v0000;
// end of prologue
    v0014 = qvalue(elt(env, 1)); // kord!*
    stack[0] = v0014;
    v0056 = v0041;
    v0014 = stack[0];
    if (equal(v0056, v0014)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0014 = v0041;
    qvalue(elt(env, 1)) = v0014; // kord!*
    v0014 = qvalue(elt(env, 2)); // nil
    v0014 = ncons(v0014);
    nil = C_nil;
    if (exception_pending()) goto v0044;
    env = stack[-1];
    qvalue(elt(env, 3)) = v0014; // alglist!*
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0044:
    popv(2);
    return nil;
}



// Code for cl_cflip

static LispObject CC_cl_cflip(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0007, v0043;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for cl_cflip");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0017;
    v0043 = v0000;
// end of prologue
    if (!(v0007 == nil)) return onevalue(v0043);
    v0007 = v0043;
    {
        fn = elt(env, 1); // cl_flip
        return (*qfn1(fn))(qenv(fn), v0007);
    }
}



// Code for subs3f

static LispObject CC_subs3f(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007, v0043, v0024;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for subs3f");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0000;
// end of prologue
    v0024 = v0007;
    v0043 = qvalue(elt(env, 1)); // !*match
    v0007 = qvalue(elt(env, 2)); // t
    {
        fn = elt(env, 3); // subs3f1
        return (*qfnn(fn))(qenv(fn), 3, v0024, v0043, v0007);
    }
}



// Code for kernlp

static LispObject CC_kernlp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0057, v0019;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernlp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0057 = v0000;
// end of prologue

v0008:
    v0019 = v0057;
    if (!consp(v0019)) goto v0004;
    v0019 = v0057;
    v0019 = qcar(v0019);
    v0019 = (consp(v0019) ? nil : lisp_true);
    goto v0003;

v0003:
    if (!(v0019 == nil)) return onevalue(v0057);
    v0019 = v0057;
    v0019 = qcdr(v0019);
    if (v0019 == nil) goto v0055;
    v0057 = qvalue(elt(env, 2)); // nil
    return onevalue(v0057);

v0055:
    v0057 = qcar(v0057);
    v0057 = qcdr(v0057);
    goto v0008;

v0004:
    v0019 = qvalue(elt(env, 1)); // t
    goto v0003;
}



// Code for qqe_rbopp

static LispObject CC_qqe_rbopp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for qqe_rbopp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0004 = elt(env, 1); // (equal neq lessp leq geq greaterp)
    v0003 = Lmemq(nil, v0003, v0004);
    return onevalue(v0003);
}



// Code for ibalp_emptyclausep

static LispObject CC_ibalp_emptyclausep(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0061, v0010;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ibalp_emptyclausep");
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
    v0061 = stack[0];
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    v0061 = qcar(v0061);
    if (v0061 == nil) goto v0054;
    v0061 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0061); }

v0054:
    v0061 = stack[0];
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    v0010 = qcar(v0061);
    v0061 = (LispObject)1; // 0
    v0061 = Leqn(nil, v0010, v0061);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    if (v0061 == nil) goto v0043;
    v0061 = stack[0];
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    v0061 = qcdr(v0061);
    v0010 = qcar(v0061);
    v0061 = (LispObject)1; // 0
        popv(2);
        return Leqn(nil, v0010, v0061);

v0043:
    v0061 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0061); }
// error exit handlers
v0015:
    popv(2);
    return nil;
}



// Code for sub2chk

static LispObject CC_sub2chk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0039, v0068, v0021;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sub2chk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0021 = v0000;
// end of prologue
    v0039 = qvalue(elt(env, 1)); // subfg!*
    if (v0039 == nil) goto v0005;
    v0068 = v0021;
    v0039 = qvalue(elt(env, 2)); // powlis!*
    v0039 = Latsoc(nil, v0068, v0039);
    if (!(v0039 == nil)) goto v0008;
    v0039 = v0021;
    if (!consp(v0039)) goto v0049;
    v0039 = v0021;
    v0068 = qcar(v0039);
    v0039 = elt(env, 3); // (expt sqrt)
    v0039 = Lmemq(nil, v0068, v0039);
    goto v0034;

v0034:
    if (!(v0039 == nil)) goto v0008;

v0005:
    v0039 = nil;
    return onevalue(v0039);

v0008:
    v0039 = qvalue(elt(env, 5)); // t
    qvalue(elt(env, 6)) = v0039; // !*sub2
    return onevalue(v0039);

v0049:
    v0039 = qvalue(elt(env, 4)); // nil
    goto v0034;
}



// Code for butes

static LispObject CC_butes(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0015, v0031, v0062;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for butes");
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
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0062 = v0000;
// end of prologue
    v0015 = v0062;
    v0015 = qcar(v0015);
    qvalue(elt(env, 1)) = v0015; // cha
    v0031 = qvalue(elt(env, 1)); // cha
    v0015 = elt(env, 2); // ! 
    if (v0031 == v0015) goto v0007;
    v0031 = qvalue(elt(env, 1)); // cha
    v0015 = elt(env, 4); // !$
    v0015 = (v0031 == v0015 ? lisp_true : nil);
    goto v0006;

v0006:
    if (v0015 == nil) goto v0068;
    v0015 = qvalue(elt(env, 5)); // nil
    { popv(1); return onevalue(v0015); }

v0068:
    v0015 = v0062;
    stack[0] = qcar(v0015);
    v0015 = v0062;
    v0015 = qcdr(v0015);
    v0015 = CC_butes(env, v0015);
    nil = C_nil;
    if (exception_pending()) goto v0048;
    {
        LispObject v0047 = stack[0];
        popv(1);
        return cons(v0047, v0015);
    }

v0007:
    v0015 = qvalue(elt(env, 3)); // t
    goto v0006;
// error exit handlers
v0048:
    popv(1);
    return nil;
}



// Code for prepf1a

static LispObject CC_prepf1a(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0024, v0050, v0054;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for prepf1a");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// copy arguments values to proper place
    v0024 = v0017;
    v0050 = v0000;
// end of prologue
    v0054 = v0050;
    v0050 = v0024;
    v0024 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // prepf1a_reversed
    v0024 = (*qfnn(fn))(qenv(fn), 3, v0054, v0050, v0024);
    errexit();
        return Lnreverse(nil, v0024);
}



// Code for expchk

static LispObject CC_expchk(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for expchk");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0000;
// end of prologue
    v0006 = qvalue(elt(env, 1)); // !*exp
    if (!(v0006 == nil)) return onevalue(v0007);
    v0006 = v0007;
    {
        fn = elt(env, 2); // offexpchk
        return (*qfn1(fn))(qenv(fn), v0006);
    }
}



// Code for dm!-abs

static LispObject CC_dmKabs(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dm-abs");
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
    v0007 = stack[0];
    fn = elt(env, 1); // !:minusp
    v0007 = (*qfn1(fn))(qenv(fn), v0007);
    nil = C_nil;
    if (exception_pending()) goto v0024;
    env = stack[-1];
    if (v0007 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0007 = stack[0];
    {
        popv(2);
        fn = elt(env, 2); // dm!-minus
        return (*qfn1(fn))(qenv(fn), v0007);
    }
// error exit handlers
v0024:
    popv(2);
    return nil;
}



// Code for binding

static LispObject CC_binding(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0006, v0007;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for binding");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0000;
// end of prologue
    if (!symbolp(v0006)) v0006 = nil;
    else { v0006 = qfastgets(v0006);
           if (v0006 != nil) { v0006 = elt(v0006, 13); // binding
#ifdef RECORD_GET
             if (v0006 != SPID_NOPROP)
                record_get(elt(fastget_names, 13), 1);
             else record_get(elt(fastget_names, 13), 0),
                v0006 = nil; }
           else record_get(elt(fastget_names, 13), 0); }
#else
             if (v0006 == SPID_NOPROP) v0006 = nil; }}
#endif
    v0007 = v0006;
    v0006 = v0007;
    if (v0006 == nil) goto v0001;
    v0006 = v0007;
    v0006 = qcar(v0006);
    return onevalue(v0006);

v0001:
    v0006 = nil;
    return onevalue(v0006);
}



// Code for evlexcomp

static LispObject CC_evlexcomp(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0065, v0015;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evlexcomp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue

v0005:
    v0065 = stack[-1];
    if (v0065 == nil) goto v0001;
    v0065 = stack[0];
    if (v0065 == nil) goto v0006;
    v0065 = stack[-1];
    v0015 = qcar(v0065);
    v0065 = stack[0];
    v0065 = qcar(v0065);
    fn = elt(env, 2); // iequal
    v0065 = (*qfn2(fn))(qenv(fn), v0015, v0065);
    nil = C_nil;
    if (exception_pending()) goto v0105;
    env = stack[-2];
    if (v0065 == nil) goto v0016;
    v0065 = stack[-1];
    v0065 = qcdr(v0065);
    stack[-1] = v0065;
    v0065 = stack[0];
    v0065 = qcdr(v0065);
    stack[0] = v0065;
    goto v0005;

v0016:
    v0065 = stack[-1];
    v0015 = qcar(v0065);
    v0065 = stack[0];
    v0065 = qcar(v0065);
    if (((int32_t)(v0015)) > ((int32_t)(v0065))) goto v0019;
    v0065 = (LispObject)-15; // -1
    { popv(3); return onevalue(v0065); }

v0019:
    v0065 = (LispObject)17; // 1
    { popv(3); return onevalue(v0065); }

v0006:
    v0065 = elt(env, 1); // (0)
    stack[0] = v0065;
    goto v0005;

v0001:
    v0065 = (LispObject)1; // 0
    { popv(3); return onevalue(v0065); }
// error exit handlers
v0105:
    popv(3);
    return nil;
}



// Code for sc_getmat

static LispObject CC_sc_getmat(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0055, v0014;
    LispObject v0053, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "sc_getmat");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    v0053 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for sc_getmat");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0053;
    v0055 = v0017;
    v0014 = v0000;
// end of prologue
    stack[-1] = v0014;
    v0055 = sub1(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    env = stack[-2];
    stack[-1] = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0055/(16/CELL)));
    v0055 = stack[0];
    v0055 = sub1(v0055);
    nil = C_nil;
    if (exception_pending()) goto v0042;
    v0055 = *(LispObject *)((char *)stack[-1] + (CELL-TAG_VECTOR) + ((int32_t)v0055/(16/CELL)));
    { popv(3); return onevalue(v0055); }
// error exit handlers
v0042:
    popv(3);
    return nil;
}



// Code for getrtypecar

static LispObject CC_getrtypecar(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0005;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getrtypecar");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0005 = v0000;
// end of prologue
    v0005 = qcar(v0005);
    {
        fn = elt(env, 1); // getrtype
        return (*qfn1(fn))(qenv(fn), v0005);
    }
}



// Code for round!*

static LispObject CC_roundH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0007, v0043;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for round*");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0000;
// end of prologue
    v0043 = v0007;
    v0043 = qcdr(v0043);
    if (!(!consp(v0043))) return onevalue(v0007);
    v0007 = qcdr(v0007);
    return onevalue(v0007);
}



// Code for isanindex

static LispObject CC_isanindex(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0064, v0029, v0051;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for isanindex");
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
    v0051 = v0000;
// end of prologue
    v0064 = v0051;
    if (symbolp(v0064)) goto v0007;
    v0064 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0064); }

v0007:
    v0029 = v0051;
    v0064 = qvalue(elt(env, 2)); // physopindices!*
    v0064 = Lmemq(nil, v0029, v0064);
    if (!(v0064 == nil)) { popv(1); return onevalue(v0064); }
    v0029 = v0051;
    v0064 = qvalue(elt(env, 3)); // physopvarind!*
    v0064 = Lmember(nil, v0029, v0064);
    if (!(v0064 == nil)) { popv(1); return onevalue(v0064); }
    v0029 = v0051;
    v0064 = qvalue(elt(env, 4)); // frlis!*
    v0064 = Lmemq(nil, v0029, v0064);
    if (v0064 == nil) goto v0016;
    v0029 = v0051;
    v0064 = qvalue(elt(env, 5)); // frasc!*
    fn = elt(env, 6); // revassoc
    v0064 = (*qfn2(fn))(qenv(fn), v0029, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0106;
    env = stack[0];
    v0029 = qvalue(elt(env, 2)); // physopindices!*
    v0064 = Lmember(nil, v0064, v0029);
    { popv(1); return onevalue(v0064); }

v0016:
    v0064 = qvalue(elt(env, 1)); // nil
    { popv(1); return onevalue(v0064); }
// error exit handlers
v0106:
    popv(1);
    return nil;
}



// Code for mo_divides!?

static LispObject CC_mo_dividesW(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0007, v0043;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mo_divides?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0007 = v0017;
    v0043 = v0000;
// end of prologue
    v0043 = qcar(v0043);
    v0007 = qcar(v0007);
    {
        fn = elt(env, 1); // mo!=modiv1
        return (*qfn2(fn))(qenv(fn), v0043, v0007);
    }
}



// Code for dlesslex

static LispObject CC_dlesslex(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0022, v0023, v0060, v0061;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for dlesslex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0023 = v0017;
    v0060 = v0000;
// end of prologue

v0005:
    v0022 = v0060;
    if (v0022 == nil) goto v0001;
    v0022 = v0060;
    v0061 = qcar(v0022);
    v0022 = v0023;
    v0022 = qcar(v0022);
    if (((int32_t)(v0061)) > ((int32_t)(v0022))) goto v0006;
    v0022 = v0060;
    v0061 = qcar(v0022);
    v0022 = v0023;
    v0022 = qcar(v0022);
    if (((int32_t)(v0061)) < ((int32_t)(v0022))) goto v0041;
    v0022 = v0060;
    v0022 = qcdr(v0022);
    v0060 = v0022;
    v0022 = v0023;
    v0022 = qcdr(v0022);
    v0023 = v0022;
    goto v0005;

v0041:
    v0022 = qvalue(elt(env, 2)); // t
    return onevalue(v0022);

v0006:
    v0022 = qvalue(elt(env, 1)); // nil
    return onevalue(v0022);

v0001:
    v0022 = qvalue(elt(env, 1)); // nil
    return onevalue(v0022);
}



// Code for hasonevector

static LispObject CC_hasonevector(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0033;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for hasonevector");
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

v0011:
    v0033 = stack[0];
    if (v0033 == nil) goto v0008;
    v0033 = stack[0];
    v0033 = qcar(v0033);
    fn = elt(env, 2); // vecp
    v0033 = (*qfn1(fn))(qenv(fn), v0033);
    nil = C_nil;
    if (exception_pending()) goto v0055;
    env = stack[-1];
    if (!(v0033 == nil)) { popv(2); return onevalue(v0033); }
    v0033 = stack[0];
    v0033 = qcdr(v0033);
    stack[0] = v0033;
    goto v0011;

v0008:
    v0033 = qvalue(elt(env, 1)); // nil
    { popv(2); return onevalue(v0033); }
// error exit handlers
v0055:
    popv(2);
    return nil;
}



// Code for reduce_pv0

static LispObject CC_reduce_pv0(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0101, v0118;
    LispObject fn;
    LispObject v0053, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 3, "reduce_pv0");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    v0053 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for reduce_pv0");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push3(v0053,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop3(v0000,v0017,v0053);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
    push(nil);
// copy arguments values to proper place
    stack[-3] = v0053;
    stack[-4] = v0017;
    stack[0] = v0000;
// end of prologue
    v0101 = stack[-4];
    if (v0101 == nil) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0101 = stack[0];
    if (v0101 == nil) goto v0003;
    v0101 = stack[0];
    stack[-5] = v0101;
    goto v0056;

v0056:
    v0101 = stack[-5];
    if (v0101 == nil) goto v0014;
    v0101 = stack[-4];
    if (v0101 == nil) goto v0014;
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0118 = qcdr(v0101);
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    v0101 = (LispObject)greaterp2(v0118, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    v0101 = v0101 ? lisp_true : nil;
    env = stack[-6];
    if (v0101 == nil) goto v0014;
    v0101 = stack[-5];
    v0101 = qcdr(v0101);
    stack[-5] = v0101;
    goto v0056;

v0014:
    v0101 = stack[-5];
    if (v0101 == nil) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0101 = stack[-4];
    if (v0101 == nil) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0118 = qcdr(v0101);
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcdr(v0101);
    if (!(equal(v0118, v0101))) { LispObject res = stack[0]; popv(7); return onevalue(res); }
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0118 = qcar(v0101);
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    fn = elt(env, 3); // lcm
    v0101 = (*qfn2(fn))(qenv(fn), v0118, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    stack[-2] = v0101;
    v0118 = stack[-2];
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0101 = quot2(v0118, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    fn = elt(env, 4); // pv_multc
    stack[-1] = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    stack[0] = stack[-4];
    v0118 = stack[-2];
    v0101 = stack[-4];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0101 = quot2(v0118, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    v0101 = negate(v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    fn = elt(env, 4); // pv_multc
    v0101 = (*qfn2(fn))(qenv(fn), stack[0], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    fn = elt(env, 5); // pv_add
    v0101 = (*qfn2(fn))(qenv(fn), stack[-1], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    stack[0] = v0101;
    v0101 = stack[-3];
    if (v0101 == nil) goto v0120;
    v0101 = (LispObject)17; // 1
    qvalue(elt(env, 2)) = v0101; // pv_den
    { LispObject res = stack[0]; popv(7); return onevalue(res); }

v0120:
    stack[-1] = qvalue(elt(env, 2)); // pv_den
    v0118 = stack[-2];
    v0101 = stack[-5];
    v0101 = qcar(v0101);
    v0101 = qcar(v0101);
    v0101 = quot2(v0118, v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    v0101 = times2(stack[-1], v0101);
    nil = C_nil;
    if (exception_pending()) goto v0119;
    env = stack[-6];
    qvalue(elt(env, 2)) = v0101; // pv_den
    { LispObject res = stack[0]; popv(7); return onevalue(res); }

v0003:
    v0101 = qvalue(elt(env, 1)); // nil
    { popv(7); return onevalue(v0101); }
// error exit handlers
v0119:
    popv(7);
    return nil;
}



// Code for modonep!:

static LispObject CC_modonepT(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0006;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for modonep:");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0004 = v0000;
// end of prologue
    v0006 = qcdr(v0004);
    v0004 = (LispObject)17; // 1
    v0004 = (v0006 == v0004 ? lisp_true : nil);
    return onevalue(v0004);
}



// Code for getpower

static LispObject CC_getpower(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0020, v0022;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for getpower");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue
    v0020 = stack[-1];
    v0022 = qcar(v0020);
    v0020 = elt(env, 1); // expt
    if (!consp(v0022)) goto v0046;
    v0022 = qcar(v0022);
    if (!(v0022 == v0020)) goto v0046;
    v0022 = stack[0];
    v0020 = (LispObject)17; // 1
    v0020 = (LispObject)greaterp2(v0022, v0020);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    v0020 = v0020 ? lisp_true : nil;
    env = stack[-2];
    goto v0001;

v0001:
    if (v0020 == nil) goto v0049;
    v0020 = qvalue(elt(env, 3)); // t
    qvalue(elt(env, 4)) = v0020; // !*sub2
    goto v0049;

v0049:
    v0020 = stack[-1];
    v0022 = qcar(v0020);
    v0020 = stack[0];
    popv(3);
    return cons(v0022, v0020);

v0046:
    v0020 = qvalue(elt(env, 2)); // nil
    goto v0001;
// error exit handlers
v0061:
    popv(3);
    return nil;
}



// Code for smemql

static LispObject CC_smemql(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0086, v0020;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for smemql");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue
    stack[-2] = nil;
    goto v0009;

v0009:
    v0086 = stack[-1];
    if (v0086 == nil) goto v0002;
    v0086 = stack[-1];
    v0020 = qcar(v0086);
    v0086 = stack[0];
    v0086 = Lsmemq(nil, v0020, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    if (v0086 == nil) goto v0058;
    v0086 = stack[-1];
    v0020 = qcar(v0086);
    v0086 = stack[-2];
    v0086 = cons(v0020, v0086);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-3];
    stack[-2] = v0086;
    v0086 = stack[-1];
    v0086 = qcdr(v0086);
    stack[-1] = v0086;
    goto v0009;

v0058:
    v0086 = stack[-1];
    v0086 = qcdr(v0086);
    stack[-1] = v0086;
    goto v0009;

v0002:
    v0086 = stack[-2];
    {
        popv(4);
        fn = elt(env, 1); // nreverse
        return (*qfn1(fn))(qenv(fn), v0086);
    }
// error exit handlers
v0061:
    popv(4);
    return nil;
}



// Code for multdm

static LispObject CC_multdm(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0040, v0066, v0067;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multdm");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// copy arguments values to proper place
    v0066 = v0017;
    v0067 = v0000;
// end of prologue
    v0040 = v0067;
    if (!consp(v0040)) goto v0002;
    v0040 = qvalue(elt(env, 1)); // nil
    goto v0001;

v0001:
    if (v0040 == nil) goto v0030;
    v0040 = v0067;
    v0040 = times2(v0040, v0066);
    nil = C_nil;
    if (exception_pending()) goto v0097;
    env = stack[0];
    v0066 = v0040;
    v0040 = qvalue(elt(env, 2)); // dmode!*
    if (v0040 == nil) goto v0019;
    v0040 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0040)) v0040 = nil;
    else { v0040 = qfastgets(v0040);
           if (v0040 != nil) { v0040 = elt(v0040, 5); // convert
#ifdef RECORD_GET
             if (v0040 == SPID_NOPROP)
                record_get(elt(fastget_names, 5), 0),
                v0040 = nil;
             else record_get(elt(fastget_names, 5), 1),
                v0040 = lisp_true; }
           else record_get(elt(fastget_names, 5), 0); }
#else
             if (v0040 == SPID_NOPROP) v0040 = nil; else v0040 = lisp_true; }}
#endif
    v0040 = (v0040 == nil ? lisp_true : nil);
    goto v0057;

v0057:
    if (!(v0040 == nil)) { popv(1); return onevalue(v0066); }
    v0040 = qvalue(elt(env, 2)); // dmode!*
    if (!symbolp(v0040)) v0040 = nil;
    else { v0040 = qfastgets(v0040);
           if (v0040 != nil) { v0040 = elt(v0040, 34); // i2d
#ifdef RECORD_GET
             if (v0040 != SPID_NOPROP)
                record_get(elt(fastget_names, 34), 1);
             else record_get(elt(fastget_names, 34), 0),
                v0040 = nil; }
           else record_get(elt(fastget_names, 34), 0); }
#else
             if (v0040 == SPID_NOPROP) v0040 = nil; }}
#endif
        popv(1);
        return Lapply1(nil, v0040, v0066);

v0019:
    v0040 = qvalue(elt(env, 3)); // t
    goto v0057;

v0030:
    v0040 = elt(env, 4); // times
    {
        popv(1);
        fn = elt(env, 5); // dcombine
        return (*qfnn(fn))(qenv(fn), 3, v0067, v0066, v0040);
    }

v0002:
    v0040 = v0066;
    v0040 = (consp(v0040) ? nil : lisp_true);
    goto v0001;
// error exit handlers
v0097:
    popv(1);
    return nil;
}



// Code for lalr_remove_duplicates

static LispObject CC_lalr_remove_duplicates(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0023, v0060, v0061, v0010;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lalr_remove_duplicates");
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
    v0023 = v0000;
// end of prologue
    v0010 = nil;
    stack[0] = v0023;
    goto v0001;

v0001:
    v0023 = stack[0];
    if (v0023 == nil) goto v0012;
    v0023 = stack[0];
    v0023 = qcar(v0023);
    v0061 = v0023;
    v0060 = v0061;
    v0023 = v0010;
    v0023 = Lmember(nil, v0060, v0023);
    if (!(v0023 == nil)) goto v0034;
    v0023 = v0061;
    v0060 = v0010;
    v0023 = cons(v0023, v0060);
    nil = C_nil;
    if (exception_pending()) goto v0015;
    env = stack[-1];
    v0010 = v0023;
    goto v0034;

v0034:
    v0023 = stack[0];
    v0023 = qcdr(v0023);
    stack[0] = v0023;
    goto v0001;

v0012:
    v0023 = v0010;
        popv(2);
        return Lnreverse(nil, v0023);
// error exit handlers
v0015:
    popv(2);
    return nil;
}



// Code for minusf

static LispObject CC_minusf(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0063, v0098;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for minusf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0063 = v0000;
// end of prologue

v0008:
    v0098 = v0063;
    if (v0098 == nil) goto v0012;
    v0098 = v0063;
    if (!consp(v0098)) goto v0024;
    v0098 = v0063;
    v0098 = qcar(v0098);
    v0098 = (consp(v0098) ? nil : lisp_true);
    goto v0043;

v0043:
    if (v0098 == nil) goto v0031;
    v0098 = v0063;
    if (!consp(v0098)) goto v0018;
    v0098 = v0063;
    v0098 = qcar(v0098);
    if (!symbolp(v0098)) v0098 = nil;
    else { v0098 = qfastgets(v0098);
           if (v0098 != nil) { v0098 = elt(v0098, 30); // minusp
#ifdef RECORD_GET
             if (v0098 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0098 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0098 == SPID_NOPROP) v0098 = nil; }}
#endif
        return Lapply1(nil, v0098, v0063);

v0018:
    v0098 = v0063;
    v0063 = (LispObject)1; // 0
        return Llessp(nil, v0098, v0063);

v0031:
    v0063 = qcar(v0063);
    v0063 = qcdr(v0063);
    goto v0008;

v0024:
    v0098 = qvalue(elt(env, 2)); // t
    goto v0043;

v0012:
    v0063 = qvalue(elt(env, 1)); // nil
    return onevalue(v0063);
}



// Code for mtchp1

static LispObject CC_mtchp1(LispObject env, int nargs, ...)
{
    LispObject nil = C_nil;
    LispObject v0130, v0131, v0132;
    LispObject fn;
    LispObject v0027, v0053, v0017, v0000;
    va_list aa;
    va_start(aa, nargs);
    argcheck(nargs, 4, "mtchp1");
    va_start(aa, nargs);
    v0000 = va_arg(aa, LispObject);
    v0017 = va_arg(aa, LispObject);
    v0053 = va_arg(aa, LispObject);
    v0027 = va_arg(aa, LispObject);
    va_end(aa);
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mtchp1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push4(v0027,v0053,v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop4(v0000,v0017,v0053,v0027);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    v0130 = v0027;
    stack[0] = v0053;
    stack[-1] = v0017;
    stack[-2] = v0000;
// end of prologue
    v0131 = stack[-2];
    v0130 = stack[-1];
    if (equal(v0131, v0130)) goto v0003;
    v0130 = stack[-2];
    v0131 = qcar(v0130);
    v0130 = stack[-1];
    v0130 = qcar(v0130);
    fn = elt(env, 5); // mchk!*
    v0130 = (*qfn2(fn))(qenv(fn), v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    stack[-3] = v0130;
    if (v0130 == nil) goto v0055;
    v0130 = stack[-1];
    v0131 = qcdr(v0130);
    v0130 = qvalue(elt(env, 2)); // frlis!*
    v0130 = Lmemq(nil, v0131, v0130);
    if (v0130 == nil) goto v0059;
    v0130 = stack[-2];
    v0131 = qcdr(v0130);
    v0130 = (LispObject)17; // 1
    if (v0131 == v0130) goto v0105;
    v0130 = stack[-1];
    v0132 = qcdr(v0130);
    v0131 = stack[-3];
    v0130 = stack[-2];
    v0130 = qcdr(v0130);
    fn = elt(env, 6); // powmtch
    v0130 = (*qfnn(fn))(qenv(fn), 3, v0132, v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    stack[-3] = v0130;
    v0130 = (v0130 == nil ? lisp_true : nil);
    goto v0062;

v0062:
    if (v0130 == nil) goto v0103;
    v0130 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0130); }

v0103:
    stack[0] = stack[-3];
    v0130 = stack[-1];
    v0131 = qcdr(v0130);
    v0130 = stack[-2];
    v0130 = qcdr(v0130);
    v0130 = cons(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    {
        LispObject v0134 = stack[0];
        popv(5);
        fn = elt(env, 7); // mapcons
        return (*qfn2(fn))(qenv(fn), v0134, v0130);
    }

v0105:
    v0130 = qvalue(elt(env, 3)); // t
    goto v0062;

v0059:
    v0130 = stack[0];
    if (v0130 == nil) goto v0135;
    v0130 = stack[-2];
    v0131 = qcdr(v0130);
    v0130 = stack[-1];
    v0130 = qcdr(v0130);
    if (!(equal(v0131, v0130))) goto v0082;

v0135:
    v0130 = stack[-1];
    v0130 = qcdr(v0130);
    if (is_number(v0130)) goto v0136;
    v0130 = qvalue(elt(env, 3)); // t
    goto v0137;

v0137:
    if (v0130 == nil) { LispObject res = stack[-3]; popv(5); return onevalue(res); }
    else goto v0082;

v0082:
    v0130 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0130); }

v0136:
    v0130 = stack[-2];
    v0130 = qcdr(v0130);
    if (is_number(v0130)) goto v0138;
    v0130 = qvalue(elt(env, 3)); // t
    goto v0137;

v0138:
    v0130 = qvalue(elt(env, 4)); // !*mcd
    if (v0130 == nil) goto v0139;
    v0130 = stack[-2];
    v0131 = qcdr(v0130);
    v0130 = stack[-1];
    v0130 = qcdr(v0130);
    v0130 = (LispObject)lessp2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    v0130 = v0130 ? lisp_true : nil;
    env = stack[-4];
    goto v0137;

v0139:
    v0130 = stack[-2];
    v0131 = qcdr(v0130);
    v0130 = stack[-1];
    v0130 = qcdr(v0130);
    v0131 = times2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0130 = (LispObject)1; // 0
    v0130 = (LispObject)lessp2(v0131, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    v0130 = v0130 ? lisp_true : nil;
    env = stack[-4];
    if (!(v0130 == nil)) goto v0137;
    v0130 = stack[-2];
    v0130 = qcdr(v0130);
    stack[0] = Labsval(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0130 = stack[-1];
    v0130 = qcdr(v0130);
    v0130 = Labsval(nil, v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    env = stack[-4];
    v0130 = (LispObject)lessp2(stack[0], v0130);
    nil = C_nil;
    if (exception_pending()) goto v0133;
    v0130 = v0130 ? lisp_true : nil;
    env = stack[-4];
    goto v0137;

v0055:
    v0130 = qvalue(elt(env, 1)); // nil
    { popv(5); return onevalue(v0130); }

v0003:
    v0130 = qvalue(elt(env, 1)); // nil
    popv(5);
    return ncons(v0130);
// error exit handlers
v0133:
    popv(5);
    return nil;
}



// Code for tayexp!-greaterp

static LispObject CC_tayexpKgreaterp(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0004, v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for tayexp-greaterp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0006 = v0017;
    v0004 = v0000;
// end of prologue
    {
        fn = elt(env, 1); // tayexp!-lessp
        return (*qfn2(fn))(qenv(fn), v0006, v0004);
    }
}



// Code for get!+row!+nr

static LispObject CC_getLrowLnr(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0009;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for get+row+nr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0009 = v0000;
// end of prologue
        return Llength(nil, v0009);
}



// Code for kernels1

static LispObject CC_kernels1(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0066, v0067, v0097, v0076;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for kernels1");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    v0097 = v0017;
    v0066 = v0000;
// end of prologue

v0011:
    v0067 = v0066;
    if (!consp(v0067)) goto v0002;
    v0067 = v0066;
    v0067 = qcar(v0067);
    v0067 = (consp(v0067) ? nil : lisp_true);
    goto v0001;

v0001:
    if (!(v0067 == nil)) { popv(4); return onevalue(v0097); }
    v0067 = v0066;
    v0067 = qcar(v0067);
    v0067 = qcar(v0067);
    v0067 = qcar(v0067);
    v0076 = v0067;
    v0067 = v0066;
    v0067 = qcar(v0067);
    stack[-2] = qcdr(v0067);
    stack[-1] = qcdr(v0066);
    v0067 = v0076;
    v0066 = v0097;
    v0066 = Lmemq(nil, v0067, v0066);
    if (v0066 == nil) goto v0109;
    v0066 = v0097;
    goto v0021;

v0021:
    v0067 = CC_kernels1(env, stack[-1], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0066 = stack[-2];
    v0097 = v0067;
    goto v0011;

v0109:
    stack[0] = v0097;
    v0066 = v0076;
    v0066 = ncons(v0066);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    v0066 = Lappend(nil, stack[0], v0066);
    nil = C_nil;
    if (exception_pending()) goto v0108;
    env = stack[-3];
    goto v0021;

v0002:
    v0067 = qvalue(elt(env, 1)); // t
    goto v0001;
// error exit handlers
v0108:
    popv(4);
    return nil;
}



// Code for lto_setequalq

static LispObject CC_lto_setequalq(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0140, v0079, v0077;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for lto_setequalq");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue
    v0140 = qvalue(elt(env, 1)); // !*rlsetequalqhash
    if (v0140 == nil) goto v0057;
    v0079 = stack[-1];
    v0140 = stack[0];
    fn = elt(env, 4); // lto_hashequalq
    v0140 = (*qfn2(fn))(qenv(fn), v0079, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    goto v0050;

v0050:
    if (v0140 == nil) goto v0086;
    v0140 = qvalue(elt(env, 3)); // t
    v0077 = v0140;
    goto v0065;

v0065:
    v0140 = v0077;
    if (v0140 == nil) { popv(3); return onevalue(v0077); }
    v0140 = stack[-1];
    if (v0140 == nil) { popv(3); return onevalue(v0077); }
    v0140 = stack[-1];
    v0140 = qcar(v0140);
    v0079 = v0140;
    v0140 = stack[0];
    v0140 = Lmemq(nil, v0079, v0140);
    if (v0140 == nil) goto v0107;
    v0140 = stack[-1];
    v0140 = qcdr(v0140);
    stack[-1] = v0140;
    goto v0065;

v0107:
    v0140 = qvalue(elt(env, 2)); // nil
    v0077 = v0140;
    goto v0065;

v0086:
    v0140 = qvalue(elt(env, 2)); // nil
    { popv(3); return onevalue(v0140); }

v0057:
    v0079 = stack[-1];
    v0140 = stack[0];
    fn = elt(env, 5); // lto_equallengthp
    v0140 = (*qfn2(fn))(qenv(fn), v0079, v0140);
    nil = C_nil;
    if (exception_pending()) goto v0103;
    env = stack[-2];
    goto v0050;
// error exit handlers
v0103:
    popv(3);
    return nil;
}



// Code for aex_ex

static LispObject CC_aex_ex(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for aex_ex");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0004 = v0003;
    v0003 = (LispObject)33; // 2
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



// Code for addd

static LispObject CC_addd(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0028, v0064;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for addd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push3(nil, nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue
    v0064 = nil;
    goto v0009;

v0009:
    v0028 = stack[0];
    if (v0028 == nil) goto v0024;
    v0028 = stack[0];
    if (!consp(v0028)) goto v0041;
    v0028 = stack[0];
    v0028 = qcar(v0028);
    v0028 = (consp(v0028) ? nil : lisp_true);
    goto v0056;

v0056:
    if (v0028 == nil) goto v0105;
    stack[-2] = v0064;
    v0064 = stack[-1];
    v0028 = stack[0];
    fn = elt(env, 2); // adddm
    v0028 = (*qfn2(fn))(qenv(fn), v0064, v0028);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    {
        LispObject v0066 = stack[-2];
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0066, v0028);
    }

v0105:
    v0028 = stack[0];
    v0028 = qcar(v0028);
    v0028 = cons(v0028, v0064);
    nil = C_nil;
    if (exception_pending()) goto v0040;
    env = stack[-3];
    v0064 = v0028;
    v0028 = stack[0];
    v0028 = qcdr(v0028);
    stack[0] = v0028;
    goto v0009;

v0041:
    v0028 = qvalue(elt(env, 1)); // t
    goto v0056;

v0024:
    v0028 = stack[-1];
    {
        popv(4);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0064, v0028);
    }
// error exit handlers
v0040:
    popv(4);
    return nil;
}



// Code for compress!*

static LispObject CC_compressH(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0143, v0095, v0114, v0096;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for compress*");
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
    v0143 = v0000;
// end of prologue
    v0096 = nil;
    v0095 = v0143;
    v0095 = qcar(v0095);
    v0095 = Ldigitp(nil, v0095);
    env = stack[-1];
    if (v0095 == nil) goto v0009;
        popv(2);
        return Lcompress(nil, v0143);

v0009:
    stack[0] = v0143;
    goto v0054;

v0054:
    v0143 = stack[0];
    if (v0143 == nil) goto v0050;
    v0143 = stack[0];
    v0143 = qcar(v0143);
    v0114 = v0143;
    v0095 = v0114;
    v0143 = elt(env, 2); // !/
    if (v0095 == v0143) goto v0016;
    v0095 = v0114;
    v0143 = elt(env, 4); // !-
    if (v0095 == v0143) goto v0015;
    v0095 = v0114;
    v0143 = elt(env, 5); // !;
    if (v0095 == v0143) goto v0064;
    v0095 = v0114;
    v0143 = elt(env, 6); // !.
    v0143 = (v0095 == v0143 ? lisp_true : nil);
    goto v0049;

v0049:
    if (v0143 == nil) goto v0080;
    v0095 = v0114;
    v0143 = elt(env, 7); // !!
    v0114 = v0096;
    v0143 = list2star(v0095, v0143, v0114);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-1];
    v0096 = v0143;
    goto v0032;

v0032:
    v0143 = stack[0];
    v0143 = qcdr(v0143);
    stack[0] = v0143;
    goto v0054;

v0080:
    v0143 = v0114;
    v0095 = v0096;
    v0143 = cons(v0143, v0095);
    nil = C_nil;
    if (exception_pending()) goto v0121;
    env = stack[-1];
    v0096 = v0143;
    goto v0032;

v0064:
    v0143 = qvalue(elt(env, 3)); // t
    goto v0049;

v0015:
    v0143 = qvalue(elt(env, 3)); // t
    goto v0049;

v0016:
    v0143 = qvalue(elt(env, 3)); // t
    goto v0049;

v0050:
    v0143 = v0096;
    v0143 = Lnreverse(nil, v0143);
    env = stack[-1];
    v0143 = Lcompress(nil, v0143);
    nil = C_nil;
    if (exception_pending()) goto v0121;
        popv(2);
        return Lintern(nil, v0143);
// error exit handlers
v0121:
    popv(2);
    return nil;
}



// Code for noncomfp1

static LispObject CC_noncomfp1(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0068;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for noncomfp1");
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

v0011:
    v0068 = stack[0];
    if (!consp(v0068)) goto v0001;
    v0068 = stack[0];
    v0068 = qcar(v0068);
    v0068 = (consp(v0068) ? nil : lisp_true);
    goto v0012;

v0012:
    if (v0068 == nil) goto v0008;
    v0068 = qvalue(elt(env, 2)); // nil
    { popv(2); return onevalue(v0068); }

v0008:
    v0068 = stack[0];
    v0068 = qcar(v0068);
    v0068 = qcar(v0068);
    v0068 = qcar(v0068);
    fn = elt(env, 3); // noncomp
    v0068 = (*qfn1(fn))(qenv(fn), v0068);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    if (!(v0068 == nil)) { popv(2); return onevalue(v0068); }
    v0068 = stack[0];
    v0068 = qcar(v0068);
    v0068 = qcdr(v0068);
    v0068 = CC_noncomfp1(env, v0068);
    nil = C_nil;
    if (exception_pending()) goto v0086;
    env = stack[-1];
    if (!(v0068 == nil)) { popv(2); return onevalue(v0068); }
    v0068 = stack[0];
    v0068 = qcdr(v0068);
    stack[0] = v0068;
    goto v0011;

v0001:
    v0068 = qvalue(elt(env, 1)); // t
    goto v0012;
// error exit handlers
v0086:
    popv(2);
    return nil;
}



// Code for ldepends

static LispObject CC_ldepends(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0023, v0060;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ldepends");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue

v0011:
    v0023 = stack[-1];
    if (v0023 == nil) goto v0005;
    v0023 = stack[-1];
    if (!consp(v0023)) goto v0007;
    v0023 = stack[-1];
    v0060 = qcar(v0023);
    v0023 = stack[0];
    fn = elt(env, 2); // depends
    v0023 = (*qfn2(fn))(qenv(fn), v0060, v0023);
    nil = C_nil;
    if (exception_pending()) goto v0065;
    env = stack[-2];
    if (!(v0023 == nil)) { popv(3); return onevalue(v0023); }
    v0023 = stack[-1];
    v0060 = qcdr(v0023);
    v0023 = stack[0];
    stack[-1] = v0060;
    stack[0] = v0023;
    goto v0011;

v0007:
    v0060 = stack[-1];
    v0023 = stack[0];
    {
        popv(3);
        fn = elt(env, 2); // depends
        return (*qfn2(fn))(qenv(fn), v0060, v0023);
    }

v0005:
    v0023 = qvalue(elt(env, 1)); // nil
    { popv(3); return onevalue(v0023); }
// error exit handlers
v0065:
    popv(3);
    return nil;
}



// Code for numlis

static LispObject CC_numlis(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0014, v0056;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for numlis");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0014 = v0000;
// end of prologue

v0011:
    v0056 = v0014;
    if (v0056 == nil) goto v0008;
    v0056 = v0014;
    v0056 = qcar(v0056);
    if (is_number(v0056)) goto v0054;
    v0014 = qvalue(elt(env, 2)); // nil
    return onevalue(v0014);

v0054:
    v0014 = qcdr(v0014);
    goto v0011;

v0008:
    v0014 = qvalue(elt(env, 1)); // t
    return onevalue(v0014);
}



// Code for !:minusp

static LispObject CC_Tminusp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0055, v0014;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for :minusp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0055 = v0000;
// end of prologue
    v0014 = v0055;
    if (!consp(v0014)) goto v0008;
    v0014 = v0055;
    v0014 = qcar(v0014);
    if (!symbolp(v0014)) v0014 = nil;
    else { v0014 = qfastgets(v0014);
           if (v0014 != nil) { v0014 = elt(v0014, 30); // minusp
#ifdef RECORD_GET
             if (v0014 != SPID_NOPROP)
                record_get(elt(fastget_names, 30), 1);
             else record_get(elt(fastget_names, 30), 0),
                v0014 = nil; }
           else record_get(elt(fastget_names, 30), 0); }
#else
             if (v0014 == SPID_NOPROP) v0014 = nil; }}
#endif
        return Lapply1(nil, v0014, v0055);

v0008:
        return Lminusp(nil, v0055);
}



// Code for evzero!?

static LispObject CC_evzeroW(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0046, v0032, v0018;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for evzero?");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0032 = v0000;
// end of prologue

v0011:
    v0046 = v0032;
    if (v0046 == nil) goto v0008;
    v0046 = v0032;
    v0018 = qcar(v0046);
    v0046 = (LispObject)1; // 0
    if (v0018 == v0046) goto v0006;
    v0046 = qvalue(elt(env, 2)); // nil
    return onevalue(v0046);

v0006:
    v0046 = v0032;
    v0046 = qcdr(v0046);
    v0032 = v0046;
    goto v0011;

v0008:
    v0046 = qvalue(elt(env, 1)); // t
    return onevalue(v0046);
}



// Code for factorordp

static LispObject CC_factorordp(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0042, v0044, v0045, v0046;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for factorordp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0045 = v0017;
    v0046 = v0000;
// end of prologue
    v0044 = v0046;
    v0042 = v0045;
    if (v0044 == v0042) goto v0005;
    v0042 = v0046;
    v0044 = v0045;
    {
        fn = elt(env, 2); // worderp
        return (*qfn2(fn))(qenv(fn), v0042, v0044);
    }

v0005:
    v0042 = qvalue(elt(env, 1)); // nil
    return onevalue(v0042);
}



// Code for degr

static LispObject CC_degr(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0060, v0061, v0010;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for degr");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0061 = v0017;
    v0010 = v0000;
// end of prologue
    v0060 = v0010;
    if (!consp(v0060)) goto v0007;
    v0060 = v0010;
    v0060 = qcar(v0060);
    v0060 = (consp(v0060) ? nil : lisp_true);
    goto v0006;

v0006:
    if (v0060 == nil) goto v0042;
    v0060 = qvalue(elt(env, 1)); // t
    goto v0001;

v0001:
    if (v0060 == nil) goto v0068;
    v0060 = (LispObject)1; // 0
    return onevalue(v0060);

v0068:
    v0060 = v0010;
    v0060 = qcar(v0060);
    v0060 = qcar(v0060);
    v0060 = qcdr(v0060);
    return onevalue(v0060);

v0042:
    v0060 = v0010;
    v0060 = qcar(v0060);
    v0060 = qcar(v0060);
    v0060 = qcar(v0060);
    v0060 = (v0060 == v0061 ? lisp_true : nil);
    v0060 = (v0060 == nil ? lisp_true : nil);
    goto v0001;

v0007:
    v0060 = qvalue(elt(env, 1)); // t
    goto v0006;
}



// Code for mkround

static LispObject CC_mkround(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0013, v0033;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mkround");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0033 = v0000;
// end of prologue
    v0013 = v0033;
    if (!(!consp(v0013))) return onevalue(v0033);
    v0013 = elt(env, 1); // !:rd!:
    return cons(v0013, v0033);
}



// Code for collectindices

static LispObject CC_collectindices(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0006;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for collectindices");
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
    v0004 = v0000;
// end of prologue
    v0006 = v0004;
    v0004 = qvalue(elt(env, 1)); // nil
    fn = elt(env, 2); // collectindices_reversed
    v0004 = (*qfn2(fn))(qenv(fn), v0006, v0004);
    errexit();
        return Lnreverse(nil, v0004);
}



// Code for union_edge

static LispObject CC_union_edge(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0044, v0045;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for union_edge");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
// space for vars preserved across procedure calls
    push2(nil, nil);
// copy arguments values to proper place
    stack[0] = v0017;
    stack[-1] = v0000;
// end of prologue
    v0045 = stack[-1];
    v0044 = stack[0];
    fn = elt(env, 1); // memq_edgelist
    v0044 = (*qfn2(fn))(qenv(fn), v0045, v0044);
    nil = C_nil;
    if (exception_pending()) goto v0018;
    if (!(v0044 == nil)) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0045 = stack[-1];
    v0044 = stack[0];
    popv(2);
    return cons(v0045, v0044);
// error exit handlers
v0018:
    popv(2);
    return nil;
}



// Code for poly!-multf

static LispObject CC_polyKmultf(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0189, v0190, v0191;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for poly-multf");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0017;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0012;

v0012:
    v0189 = stack[-2];
    if (v0189 == nil) goto v0043;
    v0189 = stack[-1];
    v0189 = (v0189 == nil ? lisp_true : nil);
    goto v0007;

v0007:
    if (v0189 == nil) goto v0042;
    v0189 = qvalue(elt(env, 2)); // nil
    { popv(5); return onevalue(v0189); }

v0042:
    v0190 = stack[-2];
    v0189 = (LispObject)17; // 1
    if (v0190 == v0189) { LispObject res = stack[-1]; popv(5); return onevalue(res); }
    v0190 = stack[-1];
    v0189 = (LispObject)17; // 1
    if (v0190 == v0189) { LispObject res = stack[-2]; popv(5); return onevalue(res); }
    v0189 = stack[-2];
    if (!consp(v0189)) goto v0065;
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    v0189 = (consp(v0189) ? nil : lisp_true);
    goto v0010;

v0010:
    if (v0189 == nil) goto v0060;
    v0190 = stack[-2];
    v0189 = stack[-1];
    {
        popv(5);
        fn = elt(env, 10); // multd
        return (*qfn2(fn))(qenv(fn), v0190, v0189);
    }

v0060:
    v0189 = stack[-1];
    if (!consp(v0189)) goto v0067;
    v0189 = stack[-1];
    v0189 = qcar(v0189);
    v0189 = (consp(v0189) ? nil : lisp_true);
    goto v0066;

v0066:
    if (v0189 == nil) goto v0106;
    v0190 = stack[-1];
    v0189 = stack[-2];
    {
        popv(5);
        fn = elt(env, 10); // multd
        return (*qfn2(fn))(qenv(fn), v0190, v0189);
    }

v0106:
    v0189 = qvalue(elt(env, 3)); // !*exp
    if (!(v0189 == nil)) goto v0002;
    v0189 = qvalue(elt(env, 4)); // ncmp!*
    if (!(v0189 == nil)) goto v0002;
    v0189 = qvalue(elt(env, 5)); // wtl!*
    if (!(v0189 == nil)) goto v0002;
    v0189 = stack[-3];
    if (!(v0189 == nil)) goto v0002;
    v0189 = stack[-2];
    fn = elt(env, 11); // mkprod
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-2] = v0189;
    v0189 = stack[-1];
    fn = elt(env, 11); // mkprod
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-1] = v0189;
    v0189 = qvalue(elt(env, 1)); // t
    stack[-3] = v0189;
    goto v0012;

v0002:
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    stack[-3] = v0189;
    v0189 = stack[-1];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    stack[0] = v0189;
    v0189 = stack[-1];
    fn = elt(env, 12); // noncomfp
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    if (v0189 == nil) goto v0089;
    v0189 = stack[-3];
    fn = elt(env, 13); // noncomp
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    if (!(v0189 == nil)) goto v0091;
    v0189 = qvalue(elt(env, 6)); // !*!*processed
    if (!(v0189 == nil)) goto v0089;

v0091:
    v0190 = stack[-2];
    v0189 = stack[-1];
    {
        popv(5);
        fn = elt(env, 14); // poly!-multfnc
        return (*qfn2(fn))(qenv(fn), v0190, v0189);
    }

v0089:
    v0190 = stack[-3];
    v0189 = stack[0];
    if (v0190 == v0189) goto v0193;
    v0190 = stack[-3];
    v0189 = stack[0];
    fn = elt(env, 15); // ordop
    v0189 = (*qfn2(fn))(qenv(fn), v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    if (v0189 == nil) goto v0194;
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    v0190 = qcdr(v0189);
    v0189 = stack[-1];
    v0189 = CC_polyKmultf(env, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-3] = v0189;
    v0189 = stack[-2];
    v0190 = qcdr(v0189);
    v0189 = stack[-1];
    v0189 = CC_polyKmultf(env, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    stack[0] = v0189;
    v0189 = stack[-3];
    if (v0189 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    v0191 = qcar(v0189);
    v0190 = stack[-3];
    v0189 = stack[0];
    popv(5);
    return acons(v0191, v0190, v0189);

v0194:
    v0190 = stack[-2];
    v0189 = stack[-1];
    v0189 = qcar(v0189);
    v0189 = qcdr(v0189);
    v0189 = CC_polyKmultf(env, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-3] = v0189;
    v0190 = stack[-2];
    v0189 = stack[-1];
    v0189 = qcdr(v0189);
    v0189 = CC_polyKmultf(env, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    stack[0] = v0189;
    v0189 = stack[-3];
    if (v0189 == nil) { LispObject res = stack[0]; popv(5); return onevalue(res); }
    v0189 = stack[-1];
    v0189 = qcar(v0189);
    v0191 = qcar(v0189);
    v0190 = stack[-3];
    v0189 = stack[0];
    popv(5);
    return acons(v0191, v0190, v0189);

v0193:
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    v0189 = qcdr(v0189);
    v0189 = integerp(v0189);
    if (v0189 == nil) goto v0129;
    v0189 = stack[-1];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    v0189 = qcdr(v0189);
    v0189 = integerp(v0189);
    v0189 = (v0189 == nil ? lisp_true : nil);
    goto v0195;

v0195:
    if (v0189 == nil) goto v0196;
    stack[0] = stack[-3];
    v0191 = elt(env, 7); // plus
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    v0190 = qcdr(v0189);
    v0189 = stack[-1];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    v0189 = qcdr(v0189);
    v0189 = list3(v0191, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    fn = elt(env, 16); // reval
    v0189 = (*qfn1(fn))(qenv(fn), v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    fn = elt(env, 17); // to
    v0189 = (*qfn2(fn))(qenv(fn), stack[0], v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-3] = v0189;
    goto v0197;

v0197:
    v0189 = stack[-2];
    v0190 = qcdr(v0189);
    v0189 = stack[-1];
    stack[0] = CC_polyKmultf(env, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    v0190 = ncons(v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0189 = stack[-1];
    v0189 = qcdr(v0189);
    v0189 = CC_polyKmultf(env, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    fn = elt(env, 18); // addf
    v0189 = (*qfn2(fn))(qenv(fn), stack[0], v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[0] = v0189;
    v0189 = stack[-3];
    if (v0189 == nil) goto v0198;
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    v0190 = qcdr(v0189);
    v0189 = stack[-1];
    v0189 = qcar(v0189);
    v0189 = qcdr(v0189);
    v0189 = CC_polyKmultf(env, v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-2] = v0189;
    v0189 = (v0189 == nil ? lisp_true : nil);
    goto v0199;

v0199:
    if (v0189 == nil) goto v0200;
    v0189 = qvalue(elt(env, 1)); // t
    qvalue(elt(env, 8)) = v0189; // !*asymp!*
    { LispObject res = stack[0]; popv(5); return onevalue(res); }

v0200:
    v0190 = stack[-3];
    v0189 = (LispObject)17; // 1
    if (v0190 == v0189) goto v0201;
    v0189 = qvalue(elt(env, 9)); // !*mcd
    if (v0189 == nil) goto v0202;
    v0191 = stack[-3];
    v0190 = stack[-2];
    v0189 = stack[0];
    popv(5);
    return acons(v0191, v0190, v0189);

v0202:
    v0190 = stack[-3];
    v0189 = stack[-2];
    v0189 = cons(v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0190 = ncons(v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    v0189 = stack[0];
    {
        popv(5);
        fn = elt(env, 18); // addf
        return (*qfn2(fn))(qenv(fn), v0190, v0189);
    }

v0201:
    v0190 = stack[-2];
    v0189 = stack[0];
    {
        popv(5);
        fn = elt(env, 18); // addf
        return (*qfn2(fn))(qenv(fn), v0190, v0189);
    }

v0198:
    v0189 = qvalue(elt(env, 1)); // t
    goto v0199;

v0196:
    stack[0] = stack[-3];
    v0189 = stack[-2];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    v0190 = qcdr(v0189);
    v0189 = stack[-1];
    v0189 = qcar(v0189);
    v0189 = qcar(v0189);
    v0189 = qcdr(v0189);
    v0189 = plus2(v0190, v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    fn = elt(env, 19); // mkspm
    v0189 = (*qfn2(fn))(qenv(fn), stack[0], v0189);
    nil = C_nil;
    if (exception_pending()) goto v0192;
    env = stack[-4];
    stack[-3] = v0189;
    goto v0197;

v0129:
    v0189 = qvalue(elt(env, 1)); // t
    goto v0195;

v0067:
    v0189 = qvalue(elt(env, 1)); // t
    goto v0066;

v0065:
    v0189 = qvalue(elt(env, 1)); // t
    goto v0010;

v0043:
    v0189 = qvalue(elt(env, 1)); // t
    goto v0007;
// error exit handlers
v0192:
    popv(5);
    return nil;
}



// Code for ring_ecart

static LispObject CC_ring_ecart(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0003, v0004;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for ring_ecart");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0003 = v0000;
// end of prologue
    v0004 = v0003;
    v0003 = (LispObject)81; // 5
    {
        fn = elt(env, 1); // nth
        return (*qfn2(fn))(qenv(fn), v0004, v0003);
    }
}



// Code for mtp

static LispObject CC_mtp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0010, v0065, v0015;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for mtp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0065 = v0000;
// end of prologue

v0011:
    v0010 = v0065;
    if (v0010 == nil) goto v0008;
    v0010 = v0065;
    v0015 = qcar(v0010);
    v0010 = qvalue(elt(env, 2)); // frlis!*
    v0010 = Lmemq(nil, v0015, v0010);
    if (v0010 == nil) goto v0006;
    v0010 = v0065;
    v0015 = qcar(v0010);
    v0010 = v0065;
    v0010 = qcdr(v0010);
    v0010 = Lmember(nil, v0015, v0010);
    if (v0010 == nil) goto v0046;
    v0010 = qvalue(elt(env, 3)); // nil
    return onevalue(v0010);

v0046:
    v0010 = v0065;
    v0010 = qcdr(v0010);
    v0065 = v0010;
    goto v0011;

v0006:
    v0010 = qvalue(elt(env, 3)); // nil
    return onevalue(v0010);

v0008:
    v0010 = qvalue(elt(env, 1)); // t
    return onevalue(v0010);
}



// Code for pappl

static LispObject CC_pappl(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0030, v0028;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for pappl");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push5(nil, nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-2] = v0017;
    stack[-3] = v0000;
// end of prologue
    stack[-4] = nil;
    v0030 = stack[-3];
    fn = elt(env, 2); // unpkp
    v0030 = (*qfn1(fn))(qenv(fn), v0030);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-5];
    stack[-3] = v0030;
    goto v0007;

v0007:
    v0030 = stack[-3];
    if (v0030 == nil) goto v0006;
    v0030 = stack[-2];
    stack[-1] = v0030;
    v0030 = (LispObject)17; // 1
    stack[0] = v0030;
    goto v0019;

v0019:
    v0030 = stack[-3];
    v0030 = qcar(v0030);
    v0028 = sub1(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-5];
    v0030 = stack[0];
    v0030 = difference2(v0028, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-5];
    v0030 = Lminusp(nil, v0030);
    env = stack[-5];
    if (v0030 == nil) goto v0045;
    v0030 = stack[-1];
    v0028 = qcar(v0030);
    v0030 = stack[-4];
    v0030 = cons(v0028, v0030);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-5];
    stack[-4] = v0030;
    v0030 = stack[-3];
    v0030 = qcdr(v0030);
    stack[-3] = v0030;
    goto v0007;

v0045:
    v0030 = stack[-1];
    v0030 = qcdr(v0030);
    stack[-1] = v0030;
    v0030 = stack[0];
    v0030 = add1(v0030);
    nil = C_nil;
    if (exception_pending()) goto v0066;
    env = stack[-5];
    stack[0] = v0030;
    goto v0019;

v0006:
    v0030 = stack[-4];
        popv(6);
        return Lnreverse(nil, v0030);
// error exit handlers
v0066:
    popv(6);
    return nil;
}



// Code for rnequiv

static LispObject CC_rnequiv(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0034, v0055, v0014;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for rnequiv");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0055 = v0000;
// end of prologue
    v0034 = v0055;
    v0034 = qcdr(v0034);
    v0055 = v0034;
    v0014 = qcdr(v0034);
    v0034 = (LispObject)17; // 1
    if (v0014 == v0034) goto v0008;
    v0034 = qvalue(elt(env, 1)); // nil
    return onevalue(v0034);

v0008:
    v0034 = v0055;
    v0034 = qcar(v0034);
    return onevalue(v0034);
}



// Code for general!-modular!-times

static LispObject CC_generalKmodularKtimes(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0022, v0023;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for general-modular-times");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push(nil);
// copy arguments values to proper place
    v0022 = v0017;
    v0023 = v0000;
// end of prologue
    v0023 = times2(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    v0022 = qvalue(elt(env, 1)); // current!-modulus
    v0022 = Cremainder(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    env = stack[-1];
    stack[0] = v0022;
    v0023 = stack[0];
    v0022 = (LispObject)1; // 0
    v0022 = (LispObject)lessp2(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    v0022 = v0022 ? lisp_true : nil;
    env = stack[-1];
    if (v0022 == nil) { LispObject res = stack[0]; popv(2); return onevalue(res); }
    v0023 = stack[0];
    v0022 = qvalue(elt(env, 1)); // current!-modulus
    v0022 = plus2(v0023, v0022);
    nil = C_nil;
    if (exception_pending()) goto v0061;
    stack[0] = v0022;
    { LispObject res = stack[0]; popv(2); return onevalue(res); }
// error exit handlers
v0061:
    popv(2);
    return nil;
}



// Code for !*d2n

static LispObject CC_Hd2n(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0004, v0006;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for *d2n");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0004 = v0000;
// end of prologue
    v0006 = v0004;
    if (!(v0006 == nil)) return onevalue(v0004);
    v0004 = (LispObject)1; // 0
    return onevalue(v0004);
}



// Code for delcp

static LispObject CC_delcp(LispObject env,
                         LispObject v0000)
{
    LispObject nil = C_nil;
    LispObject v0008;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for delcp");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
// copy arguments values to proper place
    v0008 = v0000;
// end of prologue
    if (!symbolp(v0008)) v0008 = nil;
    else { v0008 = qfastgets(v0008);
           if (v0008 != nil) { v0008 = elt(v0008, 40); // delchar
#ifdef RECORD_GET
             if (v0008 == SPID_NOPROP)
                record_get(elt(fastget_names, 40), 0),
                v0008 = nil;
             else record_get(elt(fastget_names, 40), 1),
                v0008 = lisp_true; }
           else record_get(elt(fastget_names, 40), 0); }
#else
             if (v0008 == SPID_NOPROP) v0008 = nil; else v0008 = lisp_true; }}
#endif
    return onevalue(v0008);
}



// Code for multd

static LispObject CC_multd(LispObject env,
                         LispObject v0000, LispObject v0017)
{
    LispObject nil = C_nil;
    LispObject v0035, v0036;
    LispObject fn;
#ifdef DEBUG_VALIDATE
    if (check_env(env)) return aerror("env for multd");
#endif
#ifdef CHECK_STACK
    if_check_stack;
#endif
    if (stack >= stacklimit)
    {
        push2(v0017,v0000);
        env = reclaim(env, "stack", GC_STACK, 0);
        pop2(v0000,v0017);
        nil = C_nil;
        if (exception_pending()) return nil;
    }
    push(env);
// space for vars preserved across procedure calls
    push4(nil, nil, nil, nil);
// copy arguments values to proper place
    stack[-1] = v0017;
    stack[-2] = v0000;
// end of prologue
    stack[-3] = nil;
    goto v0009;

v0009:
    v0035 = stack[-1];
    if (v0035 == nil) goto v0002;
    v0036 = stack[-1];
    v0035 = (LispObject)17; // 1
    if (v0036 == v0035) goto v0041;
    v0035 = stack[-1];
    if (!consp(v0035)) goto v0059;
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0035 = (consp(v0035) ? nil : lisp_true);
    goto v0016;

v0016:
    if (v0035 == nil) goto v0064;
    stack[0] = stack[-3];
    v0036 = stack[-2];
    v0035 = stack[-1];
    fn = elt(env, 2); // multdm
    v0035 = (*qfn2(fn))(qenv(fn), v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    {
        LispObject v0070 = stack[0];
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0070, v0035);
    }

v0064:
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    stack[0] = qcar(v0035);
    v0036 = stack[-2];
    v0035 = stack[-1];
    v0035 = qcar(v0035);
    v0035 = qcdr(v0035);
    v0036 = CC_multd(env, v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    v0035 = stack[-3];
    v0035 = acons(stack[0], v0036, v0035);
    nil = C_nil;
    if (exception_pending()) goto v0038;
    env = stack[-4];
    stack[-3] = v0035;
    v0035 = stack[-1];
    v0035 = qcdr(v0035);
    stack[-1] = v0035;
    goto v0009;

v0059:
    v0035 = qvalue(elt(env, 1)); // t
    goto v0016;

v0041:
    v0036 = stack[-3];
    v0035 = stack[-2];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn2(fn))(qenv(fn), v0036, v0035);
    }

v0002:
    v0035 = stack[-3];
    {
        popv(5);
        fn = elt(env, 3); // nreverse
        return (*qfn1(fn))(qenv(fn), v0035);
    }
// error exit handlers
v0038:
    popv(5);
    return nil;
}



setup_type const u01_setup[] =
{
    {"reval",                   CC_reval,       too_many_1,    wrong_no_1},
    {"simpcar",                 CC_simpcar,     too_many_1,    wrong_no_1},
    {"noncomp",                 CC_noncomp,     too_many_1,    wrong_no_1},
    {"num-exponents",           CC_numKexponents,too_many_1,   wrong_no_1},
    {"argsofopr",               CC_argsofopr,   too_many_1,    wrong_no_1},
    {"smember",                 too_few_2,      CC_smember,    wrong_no_2},
    {"*n2f",                    CC_Hn2f,        too_many_1,    wrong_no_1},
    {"lalr_move_dot",           too_few_2,      CC_lalr_move_dot,wrong_no_2},
    {"mkvar",                   too_few_2,      CC_mkvar,      wrong_no_2},
    {"multf",                   too_few_2,      CC_multf,      wrong_no_2},
    {"monomgetvariabledegree",  too_few_2,      CC_monomgetvariabledegree,wrong_no_2},
    {"quotelist",               CC_quotelist,   too_many_1,    wrong_no_1},
    {"wuconstantp",             CC_wuconstantp, too_many_1,    wrong_no_1},
    {"mkcopy",                  CC_mkcopy,      too_many_1,    wrong_no_1},
    {"mchkopt",                 too_few_2,      CC_mchkopt,    wrong_no_2},
    {"revpr",                   CC_revpr,       too_many_1,    wrong_no_1},
    {"nth",                     too_few_2,      CC_nth,        wrong_no_2},
    {"kernels",                 CC_kernels,     too_many_1,    wrong_no_1},
    {"qqe_rqopp",               CC_qqe_rqopp,   too_many_1,    wrong_no_1},
    {"ibalp_clmember",          too_few_2,      CC_ibalp_clmember,wrong_no_2},
    {"noncomfp",                CC_noncomfp,    too_many_1,    wrong_no_1},
    {"delall",                  too_few_2,      CC_delall,     wrong_no_2},
    {"terminalp",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_terminalp},
    {"ordop",                   too_few_2,      CC_ordop,      wrong_no_2},
    {"prepf",                   CC_prepf,       too_many_1,    wrong_no_1},
    {"c:ordxp",                 too_few_2,      CC_cTordxp,    wrong_no_2},
    {"zero2nil",                CC_zero2nil,    too_many_1,    wrong_no_1},
    {"ordad",                   too_few_2,      CC_ordad,      wrong_no_2},
    {"mval",                    CC_mval,        too_many_1,    wrong_no_1},
    {"evcomp",                  too_few_2,      CC_evcomp,     wrong_no_2},
    {"evmatrixcomp2",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_evmatrixcomp2},
    {"xval",                    CC_xval,        too_many_1,    wrong_no_1},
    {"times:",                  too_few_2,      CC_timesT,     wrong_no_2},
    {"convprec",                CC_convprec,    too_many_1,    wrong_no_1},
    {"physopp",                 CC_physopp,     too_many_1,    wrong_no_1},
    {"memq_edgelist",           too_few_2,      CC_memq_edgelist,wrong_no_2},
    {"mo_comp",                 CC_mo_comp,     too_many_1,    wrong_no_1},
    {"c_zero",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_c_zero},
    {"sieve_pv0",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_sieve_pv0},
    {"listp",                   CC_listp,       too_many_1,    wrong_no_1},
    {"modzerop:",               CC_modzeropT,   too_many_1,    wrong_no_1},
    {"aeval",                   CC_aeval,       too_many_1,    wrong_no_1},
    {"lalr_closure",            CC_lalr_closure,too_many_1,    wrong_no_1},
    {"monomcompare",            too_few_2,      CC_monomcompare,wrong_no_2},
    {"quotf",                   too_few_2,      CC_quotf,      wrong_no_2},
    {"mchk*",                   too_few_2,      CC_mchkH,      wrong_no_2},
    {"get+mat+entry",           wrong_no_na,    wrong_no_nb,   (n_args *)CC_getLmatLentry},
    {"powers",                  CC_powers,      too_many_1,    wrong_no_1},
    {"lto_hashequalq",          too_few_2,      CC_lto_hashequalq,wrong_no_2},
    {"find2",                   too_few_2,      CC_find2,      wrong_no_2},
    {"exchk",                   CC_exchk,       too_many_1,    wrong_no_1},
    {"pm:free",                 CC_pmTfree,     too_many_1,    wrong_no_1},
    {"vbcsize",                 too_few_2,      CC_vbcsize,    wrong_no_2},
    {"pnth",                    too_few_2,      CC_pnth,       wrong_no_2},
    {"wedgefax",                CC_wedgefax,    too_many_1,    wrong_no_1},
    {"*physopp",                CC_Hphysopp,    too_many_1,    wrong_no_1},
    {"wideid2list",             CC_wideid2list, too_many_1,    wrong_no_1},
    {"termsf",                  CC_termsf,      too_many_1,    wrong_no_1},
    {"mkspm",                   too_few_2,      CC_mkspm,      wrong_no_2},
    {"dssoc",                   too_few_2,      CC_dssoc,      wrong_no_2},
    {"noncomlistp",             CC_noncomlistp, too_many_1,    wrong_no_1},
    {"rnzerop:",                CC_rnzeropT,    too_many_1,    wrong_no_1},
    {"mksp",                    too_few_2,      CC_mksp,       wrong_no_2},
    {"getrtypeor",              CC_getrtypeor,  too_many_1,    wrong_no_1},
    {"lalr_goto",               too_few_2,      CC_lalr_goto,  wrong_no_2},
    {"addcomment",              CC_addcomment,  too_many_1,    wrong_no_1},
    {"setkorder",               CC_setkorder,   too_many_1,    wrong_no_1},
    {"cl_cflip",                too_few_2,      CC_cl_cflip,   wrong_no_2},
    {"subs3f",                  CC_subs3f,      too_many_1,    wrong_no_1},
    {"kernlp",                  CC_kernlp,      too_many_1,    wrong_no_1},
    {"qqe_rbopp",               CC_qqe_rbopp,   too_many_1,    wrong_no_1},
    {"ibalp_emptyclausep",      CC_ibalp_emptyclausep,too_many_1,wrong_no_1},
    {"sub2chk",                 CC_sub2chk,     too_many_1,    wrong_no_1},
    {"butes",                   CC_butes,       too_many_1,    wrong_no_1},
    {"prepf1a",                 too_few_2,      CC_prepf1a,    wrong_no_2},
    {"expchk",                  CC_expchk,      too_many_1,    wrong_no_1},
    {"dm-abs",                  CC_dmKabs,      too_many_1,    wrong_no_1},
    {"binding",                 CC_binding,     too_many_1,    wrong_no_1},
    {"evlexcomp",               too_few_2,      CC_evlexcomp,  wrong_no_2},
    {"sc_getmat",               wrong_no_na,    wrong_no_nb,   (n_args *)CC_sc_getmat},
    {"getrtypecar",             CC_getrtypecar, too_many_1,    wrong_no_1},
    {"round*",                  CC_roundH,      too_many_1,    wrong_no_1},
    {"isanindex",               CC_isanindex,   too_many_1,    wrong_no_1},
    {"mo_divides?",             too_few_2,      CC_mo_dividesW,wrong_no_2},
    {"dlesslex",                too_few_2,      CC_dlesslex,   wrong_no_2},
    {"hasonevector",            CC_hasonevector,too_many_1,    wrong_no_1},
    {"reduce_pv0",              wrong_no_na,    wrong_no_nb,   (n_args *)CC_reduce_pv0},
    {"modonep:",                CC_modonepT,    too_many_1,    wrong_no_1},
    {"getpower",                too_few_2,      CC_getpower,   wrong_no_2},
    {"smemql",                  too_few_2,      CC_smemql,     wrong_no_2},
    {"multdm",                  too_few_2,      CC_multdm,     wrong_no_2},
    {"lalr_remove_duplicates",  CC_lalr_remove_duplicates,too_many_1,wrong_no_1},
    {"minusf",                  CC_minusf,      too_many_1,    wrong_no_1},
    {"mtchp1",                  wrong_no_na,    wrong_no_nb,   (n_args *)CC_mtchp1},
    {"tayexp-greaterp",         too_few_2,      CC_tayexpKgreaterp,wrong_no_2},
    {"get+row+nr",              CC_getLrowLnr,  too_many_1,    wrong_no_1},
    {"kernels1",                too_few_2,      CC_kernels1,   wrong_no_2},
    {"lto_setequalq",           too_few_2,      CC_lto_setequalq,wrong_no_2},
    {"aex_ex",                  CC_aex_ex,      too_many_1,    wrong_no_1},
    {"addd",                    too_few_2,      CC_addd,       wrong_no_2},
    {"compress*",               CC_compressH,   too_many_1,    wrong_no_1},
    {"noncomfp1",               CC_noncomfp1,   too_many_1,    wrong_no_1},
    {"ldepends",                too_few_2,      CC_ldepends,   wrong_no_2},
    {"numlis",                  CC_numlis,      too_many_1,    wrong_no_1},
    {":minusp",                 CC_Tminusp,     too_many_1,    wrong_no_1},
    {"evzero?",                 CC_evzeroW,     too_many_1,    wrong_no_1},
    {"factorordp",              too_few_2,      CC_factorordp, wrong_no_2},
    {"degr",                    too_few_2,      CC_degr,       wrong_no_2},
    {"mkround",                 CC_mkround,     too_many_1,    wrong_no_1},
    {"collectindices",          CC_collectindices,too_many_1,  wrong_no_1},
    {"union_edge",              too_few_2,      CC_union_edge, wrong_no_2},
    {"poly-multf",              too_few_2,      CC_polyKmultf, wrong_no_2},
    {"ring_ecart",              CC_ring_ecart,  too_many_1,    wrong_no_1},
    {"mtp",                     CC_mtp,         too_many_1,    wrong_no_1},
    {"pappl",                   too_few_2,      CC_pappl,      wrong_no_2},
    {"rnequiv",                 CC_rnequiv,     too_many_1,    wrong_no_1},
    {"general-modular-times",   too_few_2,      CC_generalKmodularKtimes,wrong_no_2},
    {"*d2n",                    CC_Hd2n,        too_many_1,    wrong_no_1},
    {"delcp",                   CC_delcp,       too_many_1,    wrong_no_1},
    {"multd",                   too_few_2,      CC_multd,      wrong_no_2},
    {NULL, (one_args *)"u01", (two_args *)"10558 8598035 5687824", 0}
};

// end of generated code