/**
 * @file   over.h
 * @brief  defined over check function
 * @author simpart
 */
#ifndef __CK_CHECK_OVER_H__
#define __CK_CHECK_OVER_H__

/*** macro ***/

/**
 * common value checker
 * set error message and execute (p4), if (p1) is over value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 * @param error process
 * @note this is private macro
 */
#define ERRCHK_OVPRS(tgt, err, msg, prs)            \
    if (err < tgt) {                                \
        CK_ERRCB_FUNCNAME(__FILE__, __LINE__, msg); \
        prs;                                        \
    }

/**
 * check target value whether it is error value
 * set error message and return -1, if (p1) is over value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_OV_RETNG(tgt, err, msg) ERRCHK_OVPRS(tgt, err, msg, return -1)

/**
 * check target value whether it is error value
 * set error message and return NULL, if (p1) is over value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_OV_RETNUL(tgt, err, msg) ERRCHK_OVPRS(tgt, err, msg, return NULL)

/**
 * check target value whether it is error value
 * set error message and goto label, if (p1) is over value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_OV_GOTO(tgt, err, msg, lbl) ERRCHK_OVPRS(tgt, err, msg, goto lbl)

/**
 * check target value whether it is error value
 * set error message and no value return, if (p1) is over value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_OV_SKIP(tgt, err, msg) ERRCHK_OVPRS(tgt, err, msg, return)

#endif
/* end of file */
