# c-kai
simple header files for enable try-catch in c lang.<br>
and it also has utility macros.<br>

# start
1. including a header file(ckai.h).

2. implements err_callback function.(please see 'erorr callback function' section)

# usage

## throw erorr

```c
 __ck_throwerr("set error message");
```

### try-catch (for no return value function)

```c++
try {
    /* pros */
} catch {
    /* err pros */
}
```

### try-catch (for return any value function)
please change FAILED_VAL to any error value  depending on function return value.

```c++
try {
    /* pros */
} catch(FAILED_VAL) {
    /* err pros */
}
```

### finally
please use 'catch_' macro with or without return value.

```c++
try {
    /* pros */
} catch_ {
    /* err pros */
} finally {
    /* pros */
}
```

### catch the error in called function
please use '$' instead of ';' when you called function.<br>
'$' is macro for check whether function call threw error.

```c++
try {
    call_func()$
} catch {
    /* err pros */
}
```

### get error message
you can get error message setted by __ck_throwerr by using CK_ERROR_MSG define.

```c++
try {
    __ck_throwerr("error message");
} catch {
    printf("%s¥n", CK_ERROR_MSG);  // error message
}
```

## erorr callback function
error callback function is called every time it thwew error.<br>
**it is necessary you to implements.<br>**
please chenge value of CK_ERRCB_FUNCNAME in hdr/ckai/check.h, if you want rename function name

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
```c++
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
this try-catch refers the global value and use the single label.<br>
please do not use the following

- not supported multi-process, multi-thread. 
- not supported nest try-catch
- default error message buffer size is 256.
