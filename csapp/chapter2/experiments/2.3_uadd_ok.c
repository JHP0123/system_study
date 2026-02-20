#include <stdio.h>

// Determine whether arguments can be added without overflow
int uadd_ok(unsigned x, unsigned y)
{
    unsigned result = x + y;
    if (x > result)
        return 0;   // Overflow
    else
        return 1;   // Normal
}

int main()
{
    unsigned a, b;
    a = 2147483648;
    b = 2147483648 + 1;

    printf("%d\n", uadd_ok(a, b));
}