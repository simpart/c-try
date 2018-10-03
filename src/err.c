/**
 * @file  err.c
 * @brief error function
 * @author simpart
 */
#include "ckai/check.h"

void ck_err (const char *fn, int ln, char * msg) {
    __ck_nullskip2(fn, msg);
    ln = ln;
}

void ck_set_errcb (void (*cb)(const char *, int, char *)) {
    __ck_nullskip(cb);
}

/*** end of file ***/
