#include <stdio.h>

int bis(int x, int y)
{
    return x | y;
}

int bic(int x, int y)
{
    return (x & (~y));
}

int bool_or(int x, int y)
{
    int result = bis(x, y);
    return result;
}

int bool_xor(int x, int y) // NAND
// a^b = (~a)b | a(~b)
{
    int result = bis(bic(x, y), bic(y, x));
    return result;
}

int main()
{
    int x = 0b10010;
    int y = 0b10101;

    int result;
    result = bool_or(x, y);
    printf("bool_or(10010, 10101) = %b\n", result);

    result = bool_xor(x, y);
    printf("bool_xor(10010, 10101) = %b\n", result);
}