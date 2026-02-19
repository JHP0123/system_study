#include <stdio.h>

void print_bytes(void *pointer, size_t size)
{
    unsigned char *one_byte_pointer = (unsigned char *)pointer; 
    int i;

    for(i = 0; i < size; i++)
    {
        printf("%.2x ", *(one_byte_pointer+i));
    }

    printf("\n");
}

int main()
{
    short a = -12345;   // -12345
    unsigned b = a;     // 0xCFC7 -> size up -> 0xFFFFCFC7 -> 
                        // T2U_32(-12345) = -12345 + 2^32 = 4,294,954,951

    printf("b = %u\t", b);
    print_bytes((void*)&b, sizeof(unsigned));
}