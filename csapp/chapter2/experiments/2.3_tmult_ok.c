#include <stdio.h>
#include <stdint.h>
#include <limits.h>


int tmul_ok(int x, int y)
{
    int64_t result = (int64_t)x * (int64_t)y;

    if (result > INT32_MAX || result < INT32_MIN)
        return 0;
    else   
        return 1;
}

int main()
{
    int a, b;
    a = 400;
    b = 500;
    printf("a = %d, b = %d, tmul_ok = %d\n", a, b, tmul_ok(a, b));

    a = 60000;
    b = 900000;
    printf("a = %d, b = %d, tmul_ok = %d\n", a, b, tmul_ok(a, b));

    a = -600000;
    b = 8000000;
    printf("a = %d, b = %d, tmul_ok = %d\n", a, b, tmul_ok(a, b));
}