#include <stdio.h>
#include "./hdr/ctry.h"

void err_callback (const char *fn, int ln, char *msg) {
    NULCHK_SKIP(fn);
    NULCHK_SKIP(msg);
    printf("%s,%d:%s\n", fn, ln, msg);
}

void test_func (int val) {
    try {
        if (100 > val) {
            __ck_throwerr("test error");
        }
    } catch {
        __ck_throwerr("test in catch error");
    }
}

int main (void) {
    try {
        test_func(200)$
        test_func(10)$
        return 0;
    } catch_ret (-1) {
        printf("%s\n", CK_ERROR_MSG);
        return -1;
    }
}
