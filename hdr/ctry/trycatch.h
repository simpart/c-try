/**
 * @file trycatch.h
 * @brief defined try-catch function
 * @author simpart
 */
#ifndef __CK_TRYCATCH_H__
#define __CK_TRYCATCH_H__


/*** include ***/
#include "ckai/util.h"

/*** define ***/
#define try memset(&gck_tchctl, 0x00, sizeof(ck_trychctl_st));

#define catch       \
    return;         \
    goto CK_CATCH;  \
    CK_CATCH:       \
    gck_tchctl.sts = CK_CATSTS_INCAT;

#define catch_ret(r)  \
    return r;         \
    goto CK_CATCH;    \
    CK_CATCH:         \
    gck_tchctl.sts = CK_CATSTS_INCAT;

#define catch_        \
    goto CK_FINALLY;  \
    goto CK_CATCH;    \
    CK_CATCH:         \
    gck_tchctl.sts = CK_CATSTS_INCAT;

#define finally CK_FINALLY:

#define CK_TCHMSG_LEN 256

/*** enum ***/
typedef enum ck_catsts {
    CK_CATSTS_INIT = 0 ,
    CK_CATSTS_INCAT    ,
    CK_CATSTS_INCATERR
} ck_catsts_en;

/*** struct ***/
typedef struct ck_trychctl {
    char         errmsg[CK_TCHMSG_LEN];
    ck_catsts_en sts;
} ck_trychctl_st;


ck_trychctl_st        gck_tchctl;
extern ck_trychctl_st gck_tchctl;

/*** macro ***/
#define $ ;                                                    \
    if ( (0 != strnlen(gck_tchctl.errmsg, CK_TCHMSG_LEN)) &&   \
         (CK_CATSTS_INCATERR == gck_tchctl.sts) ) {            \
        gck_tchctl.sts = CK_CATSTS_INIT;                       \
        goto CK_CATCH;                                         \
    }

#define __ck_throwerr_com(msg, prs)                        \
    strncpy(&gck_tchctl.errmsg[0], msg, CK_TCHMSG_LEN-1);  \
    CK_ERRCB_FUNCNAME(__FILE__, __LINE__, msg);            \
    if (CK_CATSTS_INCAT == gck_tchctl.sts) {               \
        gck_tchctl.sts = CK_CATSTS_INCATERR;               \
        prs;                                               \
    }                                                      \
    goto CK_CATCH;

#define __ck_throwerr(msg)  __ck_throwerr_com(msg, return;)

#define __ck_throwerr_ret(msg, ret) __ck_throwerr_com(msg, return ret;)

/*** prototype ***/
/**
 * error calback function
 * 
 * @param file name of error point (__FILE__)
 * @param line number of error point (__LINE__)
 * @param error message
 */
void err_callback (const char *, int, char *);

#endif
/* end of file */
