/**
 * @file   check.h
 * @brief  defined check function
 * @author simpart
 */
#ifndef __CK_CHECK_H__
#define __CK_CHECK_H__

/*** include ***/
#include <stdlib.h>

/*** define ***/

/*** struct ***/

/*** prototype ***/
void ck_err       (const char *, int, char *);
void ck_set_errcb (void (*)(const char *, int, char *));

/*** macro ***/
/**
 * common value checker
 * set error message and execute process(prs), if target value is error value.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 * @param error process
 * @note this is private macro
 */
#define __ck_errchk_value_com(tgt, err, msg, prs) \
    if (err == tgt) {                             \
        ck_err(__FILE__, __LINE__, msg);          \
        prs;                                      \
    }

/**
 * common value checker
 * set error message and execute process(prs), if target value is not error value.
 * 
 * @param check target value
 * @param no error value
 * @param (const char *) error message
 * @param error process
 * @note this is private macro
 */
#define __ck_errchk_notval_com(tgt1, tgt2, msg, prs) \
    if (tgt1 != tgt2) {                              \
        ck_err(__FILE__, __LINE__, msg);             \
        prs;                                         \
    }

/**
 * common value checker
 * set error message and execute process(prs), if target value is over than error value.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 * @param error process
 * @note this is private macro
 */
#define __ck_errchk_over_com(tgt, err, msg, prs) \
    if (err < tgt) {                             \
        ck_err(__FILE__, __LINE__, msg);         \
        prs;                                     \
    }

/**
 * common value checker
 * set error message and execute process(prs), if target value is less than error value.
 * 
 * @param check target value
 * @param error base value
 * @param (const char *) error message
 * @param error process
 * @note this is private macro
 */
#define __ck_errchk_less_com(tgt, err, msg, prs) \
    if (err > tgt) {                             \
        ck_err(__FILE__, __LINE__, msg);         \
        prs;                                     \
    }


/**
 * check target value whether  it is error value
 * set error message and return TTR_NG, if target value(p1) is error value(p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define __ck_errchk_value(tgt, err, msg) __ck_errchk_value_com(tgt, err, msg, return TTR_NG)

/**
 * check target value whether  it is error value
 * set error message and goto label, if target value(p1) is error value(p2).
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define __ck_errchk_valgoto(tgt, err, msg, lbl)  __ck_erchk_value_com(tgt, err, msg, goto lbl)

/**
 * check null a target value.
 * set error message and return TTR_NG, if target value is null.
 *
 * @param[in] (pointer)      null check target
 * @param[in] (const char *) error message
 */
#define __ck_nullchk(tgt, msg) __ck_errchk_value(tgt, NULL, msg)

/**
 * check null 2 target value.
 * set error message and return TTR_NG, if target value is null.
 *
 * @param[in] (pointer)      null check target
 * @param[in] (pointer)      null check target
 * @param[in] (const char *) error message
 */
#define __ck_nullchk2(tgt1, tgt2, msg) \
    __ck_nullchk(tgt1, msg);           \
    __ck_nullchk(tgt2, msg)

/**
 * check null 3 target value.
 * set error message and return TTR_NG, if target value is null.
 *
 * @param[in] (pointer)      null check target
 * @param[in] (pointer)      null check target
 * @param[in] (pointer)      null check target
 * @param[in] (const char *) error message
 */
#define __ck_nullchk3(tgt1, tgt2, tgt3, msg) \
    __ck_nullchk2(tgt1, tgt2, msg);          \
    __ck_nullchk(tgt3, msg)

/**
 * check null a target value.
 * set error message and goto label, if target value is null.
 * 
 * @param (pointer)      null check target
 * @param (const char *) error message
 * @param (label)        target goto label
 */
#define __ck_nullchk_goto(tgt, msg, lbl)  __ck_errchk_valgoto(tgt, NULL, msg, lbl)

/**
 * check null a target parameter.
 * set "invalid parameter" error message and return TTR_NG, if target value is null.
 * 
 * @param (pointer) null check target
 */
#define __ck_nullchk_prm(p)  __ck_nullchk(p, "invalid parameter")

/**
 * check null 2 target parameter.
 * set "invalid parameter" error message and return TTR_NG, if target value is null.
 *
 * @param (pointer) null check target
 * @param (pointer) null check target
 */
#define __ck_nullchk_prm2(p1, p2)  \
    __ck_nullchk_prm(p1);          \
    __ck_nullchk_prm(p2)

/**
 * check null 3 target parameter.
 * set "invalid parameter" error message and return TTR_NG, if target value is null.
 *
 * @param (pointer) null check target
 * @param (pointer) null check target
 * @param (pointer) null check target
 */
#define __ck_nullchk_prm3(p1, p2, p3)  \
    __ck_nullchk_prm2(p1, p2);         \
    __ck_nullchk_prm(p3)

/**
 * check null a target parameter.
 * no value return (skip process), if target value is null.
 *
 * @param (pointer) null check target
 */
#define __ck_nullskip(tgt) __ck_errchk_value_com(tgt, NULL, "null value, no thing to do", return)

/**
 * check null 2 target parameter.
 * no value return (skip process), if target value is null.
 *
 * @param (pointer) null check target
 * @param (pointer) null check target
 */
#define __ck_nullskip2(tgt1, tgt2) \
    __ck_nullskip(tgt1)            \
    __ck_nullskip(tgt2)

/**
 * check null 3 target parameter.
 * no value return (skip process), if target value is null.
 *
 * @param (pointer) null check target
 * @param (pointer) null check target
 * @param (pointer) null check target
 */
#define __ck_nullskip3(tgt1, tgt2, tgt3) \
    __ck_nullskip2(tgt1, tgt2);          \
    __ck_nullskip(tgt3)

/**
 * check over value a target parameter.
 * no value return (skip process), if target value is over than error value.
 *
 * @param (pointer) null check target
 * @param error base value
 */
#define __ck_overskip(tgt, err) __ck_chkerr_over_com(tgt, err, "null value, no thing to do", return)

/**
 * check less value a target parameter.
 * no value return (skip process), if target value is less than error value.
 *
 * @param (pointer) null check target
 * @param error base value
 */
#define __ck_lessskip(tgt, err) __ck_errchk_less_com(tgt, err, "null value, no thing to do", return)

/**
 * check target value whether it is over than error value
 * set error message and return TTR_NG, if target value is over than error value.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define __ck_errchk_over(tgt, ovr, msg) __ck_errchk_over_com(tgt, ovr, msg, return TTR_NG)

/**
 * check target value whether it is over than error value
 * set error message and goto label, if target value is over than error value.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 * @param label
 */
#define __ck_errchk_over_goto(tgt, ovr, msg, lbl) __ck_errchk_over_com(tgt, ovr, msg, goto lbl)

/**
 * check target value whether it is less than error value
 * set error message and return TTR_NG, if target value is less than error value.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define __ck_errchk_less(tgt, les, msg) __ck_errchk_less_com(tgt, les, msg, return TTR_NG)

/**
 * check target value whether it is less than error value
 * set error message and goto label, if target value is less than error value.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 * @param label
 */
#define __ck_errchk_less_goto(tgt, les, msg, lbl) __ck_errchk_over_com(tgt, les, msg, goto lbl)

/**
 * check target value whether it is less than 0
 * set error message and return TTR_NG, if target value is less than 0.
 * 
 * @param check target value
 * @param error value
 * @param (const char *) error message
 */
#define __ck_errchk_0less(tgt, msg) \ __ck_errchk_less_com(tgt, 0, msg, return TTR_NG)

/**
 * check target value whether it is different with check value
 * set error message and return TTR_NG, if target value is different with check value.
 * @param target value
 * @param check value
 * @param (const char *) error message
 */
#define __ck_errchk_notval(tgt, chk, msg)  __ck_errchk_notval_com(tgt, chk, msg, return TTR_NG)

/**
 * check target value whether it is different with check value
 * set error message and goto label, if target value is different with check value.
 *
 * @param target value
 * @param check value
 * @param (const char *) error message
 */
#define __ck_errchk_notval_goto(tgt, chk, msg, lbl) __ck_errchk_notval_com(tgt, chk, msg, goto lbl)

/**
 * check target value whether it is null value
 * set error message and return TTR_NG, if target value is NULL.
 *
 * @param return value
 */
#define __ck_errchk_retnull(ret) __ck_errchk_value(ret, NULL, "error return value")

/**
 * check target value whether it is NG value.
 * set error message and return TTR_NG, if target value is TTR_NG.
 *
 * @param return value
 */
#define __ck_errchk_retng(ret) __ck_errchk_value(ret, TTR_NG, "error return value")

/**
 * check target value whether it is not OK value.
 * set error message and return TTR_NG, if target value is not TTR_OK.
 *
 * @param return value
 */
#define __ck_errchk_retnotok(ret) __ck_errchk_notval(ret, TTR_OK, "error return value")

/**
 * check target value whether it within renge value
 * set error message and return TTR_NG, if target value is not within renge value
 *
 * @param.check target value
 * @param start renge value
 * @param end renge value
 */
#define __ck_errchk_renge(tgt, st, end)  \
    __ck_errchk_less(tgt, st);           \
    __ck_errchk_over(tgt, end) 

#endif
/* end of file */
