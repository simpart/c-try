/**
 * @file com.h
 * @author simpart
 */

#ifndef __CK_COM_H__
#define __CK_COM_H__

/*** include ***/
#include <string.h>

/*** macro ***/
#define __ck_loop(i, c) int i=0; for (;i < c;i++)
#define __ck_loop_i(c) __ck_loop(i, c)
#define __ck_loop_j(c) __ck_loop(j, c)
#define __ck_loop_k(c) __ck_loop(k, c)

#define __ck_initval(i) memset(&i, 0x00, sizeof(i))
#define __ck_initval2(i1, i2) __ck_initval(i1); __ck_initval(i2)
#define __ck_initval3(i1, i2, i3) __ck_initval(i1); __ck_initval(i2); __ck_initval(i3)

#define __ck_strinit(s) memset(&s[0], 0x00, sizeof(s))
#define __ck_strinit2(s1, s2) __ck_strinit(s1); __ck_strinit(s2)
#define __ck_strinit3(s1, s2, s3) __ck_strinit(s1); __ck_strinit(s2); __ck_strinit(s3)

#define __ck_limitval(v, m) if (v > m) v = m

#endif
/* end of file */
