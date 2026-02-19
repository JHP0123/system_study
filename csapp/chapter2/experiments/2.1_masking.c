#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t x = 0x87654321;
    uint32_t y;
    
    // least significant byte
    y = x & 0xFF;
    printf("%.8x\n", y);

    // all but the least sigificant byte complemented
    uint32_t z = x & 0xFFFFFF00;
    z = ~z;
    z = z + y + 1;
    printf("%.8x\n", z);

    // least significant byte to all 1s
    z = (x & 0xFFFFFF00) | 0x000000FF;
    printf("%.8x\n", z);

}