#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *copy_elements(void *ele_src[], int ele_cnt, size_t ele_size)
{
    void *result = malloc((unsigned)ele_cnt * ele_size);
    // malloc은 32-bit system에서 컴파일 시 size_t는 32-bit unsigned인데
    // unsigned 곱셈 연산을 할 경우 32-bit보다 더 커지는 경우에는 값이 작아지는
    // 문제점이 있다. 즉, 결과가 unsigned 32-bit의 max 값보다 커지는 경우 
    // 최종 결과는 작은 값을 가지게 된다. 
    if (result = NULL)
    {
        return NULL;
    }

    void *next = result;

    for(int i = 0; i < ele_cnt; i++)
    {
        memcpy(next, ele_src[i], ele_size);
        next += ele_size;
    }

    return result;
}

int main()
{
    void *buffer[4];

    for(int i = 0; i < 4; i++)
    {
        buffer[i] = malloc(sizeof(int) * 5UL);
        int *i_ptr = (int *)(buffer[i]);
        for(int j = 0; j < 5; j++)
        {
            i_ptr[j] = i * j;
        }
    }

    void *add = copy_elements(buffer, 2, sizeof(int) * 5UL);    

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", ((int*)add)[i]);
    }
    printf("\n");

    free(add);
    for(int i = 0; i < 4; i++)
        free(buffer[i]);
}