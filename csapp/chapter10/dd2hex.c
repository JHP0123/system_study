#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char *dig = argv[argc - 1];
    int num;

    num = strtol(dig, NULL, 10);
    printf("0x%X\n", num);
    
}