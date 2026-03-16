#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char *str = argv[argc - 1]; // ./hex2dd 0x400이면 "0x400"을 가리킨
    int num;

    num = strtol(str, NULL, 16);
    printf("%d\n", num);    
}