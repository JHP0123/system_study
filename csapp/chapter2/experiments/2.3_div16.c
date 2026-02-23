#include <stdio.h>

int div16(int x)
{
    int result = (x + (1 << 4) - 1) >> 4;
    return result;
}

int main()
{
    int a = -12340;
    int b = 12340;

    a = div16(a);
    b = div16(b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);
}