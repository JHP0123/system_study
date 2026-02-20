#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)



// Determine whether arguments can be added without overflow
int tadd_ok(int x, int y)
{
    int result = x + y;

    if (x > 0 && y > 0 && result < 0)
        return 0;
    else if (x < 0 && y < 0 && result > 0)
        return 0;
    else
        return 1;
}

int main()
{
    int x, y;
    x = INT_MAX;
    y = 1;
    printf("x = %d, y = %d, tadd_ok = %d\n", x, y, tadd_ok(x, y));

    x = INT_MIN;
    y = -123;
    printf("x = %d, y = %d, tadd_ok = %d\n", x, y, tadd_ok(x, y));
    
    x = 1234567890;
    y = 123;
    printf("x = %d, y = %d, tadd_ok = %d\n", x, y, tadd_ok(x, y));


}