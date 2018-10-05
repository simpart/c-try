/**
 * @file   equal.h
 * @brief  defined non equal check function
 * @author simpart
 */
#ifndef __CK_CHECK_NEQUAL_H__
#define __CK_CHECK_NEQUAL_H__

/*** include ***/
#include <stdlib.h>

/*** macro ***/
/**
 * common value checker
 * set error message and execute (p4), if (p1) is not equal value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 * @param error process
 * @note this is private macro
 */
#define ERRCHK_NEQPRS(tgt, err, msg, prs)           \
    if (err != tgt) {                               \
        CK_ERRCB_FUNCNAME(__FILE__, __LINE__, msg); \
        prs;                                        \
    }

/**
 * check target value whether it is error value
 * set error message and return -1, if (p1) is not equal value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_NEQ_RETNG(tgt, err, msg) ERRCHK_NEQPRS(tgt, err, msg, return -1)

/**
 * check target value whether it is error value
 * set error message and return NULL, if (p1) is not equal value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_NEQ_RETNUL(tgt, err, msg) ERRCHK_NEQPRS(tgt, err, msg, return NULL)

/**
 * check target value whether it is error value
 * set error message and goto label, if (p1) is not equal value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_NEQ_GOTO(tgt, err, msg, lbl) ERRCHK_NEQPRS(tgt, err, msg, goto lbl)

/**
 * check target value whether it is error value
 * set error message and no value return, if (p1) is not equal value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_NEQ_SKIP(tgt, err, msg) ERRCHK_NEQPRS(tgt, err, msg, return)

/*** ng value check ***/
/**
 * check target value.
 * set error message and return -1, if (p1) is not 0.
 *
 * @param return value
 */
#define NOKCHK_RETNG(ret) ERRCHK_NEQ_RETNG(ret, 0, "error return value")

/**
 * check target value.
 * set error message and return NULL, if (p1) is not 0.
 *
 * @param return value
 */
#define NOKCHK_RETNUL(ret) ERRCHK_NEQ_RETNUL(ret, 0, "error return value")

/**
 * check target value.
 * set error message and goto label, if (p1) is not 0.
 *
 * @param return value
 */
#define NOKCHK_GOTO(ret, lbl) ERRCHK_NEQ_GOTO(ret, 0, "error return value", lbl)

/**
 * check target value.
 * set error message and no value return (skip process), if target value is -1.
 *
 * @param return value
 */
#define NOKCHK_SKIP(ret, lbl) ERRCHK_NEQ_SKIP(ret, 0, "error return value")

#endif
/* end of file */
