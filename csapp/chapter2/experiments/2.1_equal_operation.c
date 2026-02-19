#include <stdio.h>

int main()
{
    // x == y

    int x = 2, y = 3;

    int b = !(x ^ y);

    printf("%d\n", b);

}