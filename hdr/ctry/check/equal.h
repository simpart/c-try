/**
 * @file   equal.h
 * @brief  defined equal check function
 * @author simpart
 */
#ifndef __CK_CHECK_EQUAL_H__
#define __CK_CHECK_EQUAL_H__

/*** include ***/
#include <stdlib.h>

/*** macro ***/
/**
 * common value checker
 * set error message and execute (p4), if (p1) is equal value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 * @param error process
 * @note this is private macro
 */
#define ERRCHK_EQPRS(tgt, err, msg, prs)            \
    if (err == tgt) {                               \
        CK_ERRCB_FUNCNAME(__FILE__, __LINE__, msg); \
        prs;                                        \
    }

/**
 * check target value whether it is error value
 * set error message and return -1, if (p1) is equal value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_EQ_RETNG(tgt, err, msg) ERRCHK_EQPRS(tgt, err, msg, return -1)

/**
 * check target value whether it is error value
 * set error message and return NULL, if (p1) is equal value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_EQ_RETNUL(tgt, err, msg) ERRCHK_EQPRS(tgt, err, msg, return NULL)

/**
 * check target value whether  it is error value
 * set error message and goto label, if (p1) is equal value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_EQ_GOTO(tgt, err, msg, lbl) ERRCHK_EQPRS(tgt, err, msg, goto lbl)

/**
 * check target value whether  it is error value
 * set error message and no value return, if (p1) is equal value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_EQ_SKIP(tgt, err, msg) ERRCHK_EQPRS(tgt, err, msg, return)

/*** null check ***/

/**
 * check null a target value.
 * set error message and return -1, if target value is null.
 *
 * @param[in] (pointer)      null check target
 * @param[in] (const char *) error message
 */
#define NULCHK_RETNG(tgt, msg) ERRCHK_EQ_RETNG(tgt, NULL, msg)

/**
 * check null a target value.
 * set error message and return NULL, if target value is null.
 * 
 * @param[in] (pointer)      null check target
 * @param[in] (const char *) error message
 */
#define NULCHK_RETNUL(tgt, msg) ERRCHK_EQ_RETNUL(tgt, NULL, msg)

/**
 * check null a target value.
 * set error message and goto label, if target value is null.
 * 
 * @param[in] (pointer)      null check target
 * @param[in] (const char *) error message
 */
#define NULCHK_GOTO(tgt, msg, lbl) ERRCHK_EQ_GOTO(tgt, NULL, msg, lbl)

/**
 * check null a target parameter.
 * set error message and no value return (skip process), if target value is null.
 *
 * @param (pointer) null check target
 */
#define NULCHK_SKIP(tgt) ERRCHK_EQ_SKIP(tgt, NULL, "null value, no thing to do")


/*** ng value check ***/
/**
 * check target value.
 * set error message and return -1, if (p1) is -1.
 *
 * @param return value
 */
#define NGCHK_RETNG(ret) ERRCHK_EQ_RETNG(ret, -1, "error return value")

/**
 * check target value.
 * set error message and return NULL, if (p1) is -1.
 *
 * @param return value
 */
#define NGCHK_RETNUL(ret) ERRCHK_EQ_RETNUL(ret, -1, "error return value")

/**
 * check target value.
 * set error message and goto label, if (p1) is -1.
 *
 * @param return value
 */
#define NGCHK_GOTO(ret, lbl) ERRCHK_EQ_GOTO(ret, -1, "error return value", lbl)

/**
 * check target value.
 * set error message and no value return (skip process), if target value is -1.
 *
 * @param return value
 */
#define NGCHK_SKIP(ret, lbl) ERRCHK_EQ_SKIP(ret, -1, "error return value")

#endif
/* end of file */
