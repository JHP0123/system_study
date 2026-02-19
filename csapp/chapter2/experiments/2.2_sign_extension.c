#include <stdio.h>

void show_bytes(unsigned char *start, size_t len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

int main()
{
    short sx = -12345;          // -12345
    unsigned short usx = sx;    // U2T(-12345) = -12345 + 65536 = 53191
    int x = sx;                 // -12345
    unsigned ux = usx;          // 53191

    printf("sx = %d:\t", sx);
    show_bytes((unsigned char *)&sx, sizeof(short));
    printf("sx = %u:\t", usx);
    show_bytes((unsigned char *)&usx, sizeof(unsigned short));
    printf("sx = %d:\t", x);
    show_bytes((unsigned char *)&x, sizeof(int));
    printf("sx = %u:\t", ux);
    show_bytes((unsigned char *)&ux, sizeof(unsigned));
}