#include <stdio.h>

void print_bytes(void *pointer, size_t size)
{
    unsigned char *one_byte_pointer = (unsigned char *)pointer; 
    // char *로 하면 char->int로 확장될 때 0xFF->0xFFFFFFFF로 확장된다
    // unsigned char *는 0xFF->0X000000FF로 확장
    int i;

    for(i = 0; i < size; i++)
    {
        printf("%.2x ", *(one_byte_pointer+i)); // integer promotion 발생(unsigned char -> int)
    }

    printf("\n");
}

int main()
{
    int ix = 123;
    float fx = 123.0f;
    int *px = &ix;

    printf("%d : ", ix);
    print_bytes((void*)&ix, sizeof(int));
    printf("%.2f : ", fx);
    print_bytes((void*)&fx, sizeof(float));
    printf("%p : ", (void*)px);
    print_bytes((void*)&px, sizeof(void *));   //&px : int **
}