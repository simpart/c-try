/**
 * @file   less.h
 * @brief  defined less check function
 * @author simpart
 */
#ifndef __CK_CHECK_LESS_H__
#define __CK_CHECK_LESS_H__

/*** macro ***/

/**
 * common value checker
 * set error message and execute (p4), if (p1) is less value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 * @param error process
 * @note this is private macro
 */
#define ERRCHK_LSPRS(tgt, err, msg, prs)            \
    if (err > tgt) {                                \
        CK_ERRCB_FUNCNAME(__FILE__, __LINE__, msg); \
        prs;                                        \
    }

/**
 * check target value whether it is error value
 * set error message and return -1, if (p1) is less value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_LS_RETNG(tgt, err, msg) ERRCHK_LSPRS(tgt, err, msg, return -1)

/**
 * check target value whether it is error value
 * set error message and return NULL, if (p1) is less value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_LS_RETNUL(tgt, err, msg) ERRCHK_LSPRS(tgt, err, msg, return NULL)

/**
 * check target value whether it is error value
 * set error message and goto label, if (p1) is less value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_LS_GOTO(tgt, err, msg, lbl) ERRCHK_LSPRS(tgt, err, msg, goto lbl)

/**
 * check target value whether it is error value
 * set error message and no value return, if (p1) is less value to (p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define ERRCHK_LS_SKIP(tgt, err, msg) ERRCHK_LSPRS(tgt, err, msg, return)

/**
 * check target value whether it is error value
 * set error message and return -1, if (p1) is less 0.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define LSSCHK_ZERO_RETNG(tgt) ERRCHK_LS_RETNG(tgt, 0, "zero less error")

/**
 * check target value whether it is error value
 * set error message and return NULL, if (p1) is less 0.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define LSSCHK_ZERO_RETNUL(tgt) ERRCHK_LS_RETNUL(tgt, 0, "zero less error")

/**
 * check target value whether it is error value
 * set error message and goto label, if (p1) is less 0.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define LSSCHK_ZERO_GOTO(tgt, lbl) ERRCHK_LS_RETNG(tgt, 0, "zero less error", lbl)

/**
 * check target value whether it is error value
 * set error message and no value return, if (p1) is less 0.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define LSSCHK_ZERO_SKIP(tgt) ERRCHK_LS_SKIP(tgt, 0, "zero less error")

#endif
/* end of file */
