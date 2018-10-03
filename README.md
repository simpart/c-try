# c-kai
c lang util macro.<br>
simple header files for enable try-catch at c lang.

# usage

## throw erorr

```c
 __ck_throwerr("set error message");
```

### try-catch (for no return value function)

```c
try {
    /* pros */
} catch {
    /* err pros */
}
```

### try-catch (for return any value function)

```c
try {
    /* pros */
} catch(FAILED_VAL) {
    /* err pros */
}
```

## erorr callback function
error callback function is called every time it thwew error.<br>
it is necessary you to implements.<br>
<br>
please chenge value of CK_ERRCB_FUNCNAME at hdr/ckai/check.h, if you want rename function name

```c
/* prototype */
/**
 * error calback function
 * 
 * @param file name of error point (__FILE__)
 * @param line number of error point (__LINE__)
 * @param error message
 */
void err_callback (const char *, int, char *);
```

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

# attention
this try-catch function refers global value.
so do not use try-catch at multi-process program.
