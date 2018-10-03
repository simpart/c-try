# c-kai
c lang util macro.
simple header files for enable try-catch at c lang.

# sample
```c
#include <stdio.h>
#include "ckai.h"

void err_callback (const char *fn, int ln, char *msg) {
    __ck_nullskip2(fn, msg);

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
```

result:
```
main.c,13:test error
main.c,16:test in catch error
test in catch error
```
