/**
 * @file   range.h
 * @brief  defined range check function
 * @author simpart
 */
#ifndef __CK_CHECK_RANGE_H__
#define __CK_CHECK_RANGE_H__

/*** macro ***/

/**
 * check target value whether it within renge value
 * set error message and return -1, if target value is not within renge value
 *
 * @param.check target value
 * @param start renge value
 * @param end renge value
 */
#define RANGE_CHECK_RETNG(tgt, st, end)             \
    ERRCHK_LS_RETNG(tgt, st, "out of range value")  \
    ERRCHK_OV_RETNG(tgt, end, "out of range value")


/**
 * check target value whether it within renge value
 * set error message and return NULL, if target value is not within renge value
 *
 * @param.check target value
 * @param start renge value
 * @param end renge value
 */
#define RANGE_CHECK_RETNUL(tgt, st, end)             \
    ERRCHK_LS_RETNUL(tgt, st, "out of range value")  \
    ERRCHK_OV_RETNUL(tgt, end, "out of range value")

/**
 * check target value whether it within renge value
 * set error message and return -1, if target value is not within renge value
 *
 * @param.check target value
 * @param start renge value
 * @param end renge value
 */
#define RANGE_CHECK_GOTO(tgt, st, end, lbl)             \
    ERRCHK_LS_GOTO(tgt, st, "out of range value", lbl)  \
    ERRCHK_LS_GOTO(tgt, end, "out of range value", lbl)

/**
 * check target value whether it within renge value
 * set error message and no value return, if target value is not within renge value
 *
 * @param.check target value
 * @param start renge value
 * @param end renge value
 */
#define RANGE_CHECK_SKIP(tgt, st, end)             \
    ERRCHK_LS_SKIP(tgt, st, "out of range value")  \
    ERRCHK_OV_SKIP(tgt, end, "out of range value")

#endif
/* end of file */
