#include <stdio.h>
#include <string.h>

#define SIZE 1024
char uni_buf[SIZE];

size_t copy_char_buf(void *src, size_t maxlen)
{
    size_t len = SIZE < maxlen ? SIZE : maxlen;
    memcpy(uni_buf, src, len);
    return len;
}

int main()
{
    char user_buf[20];

    printf("Input String: ");
    scanf("%s", user_buf);

    unsigned int n;
    printf("How many characters have you inputted?: ");
    scanf("%u", &n);

    copy_char_buf(user_buf, n);
    char *add = user_buf + n;
    for(char *i = user_buf; i < add; i++)
    {
        printf("%c", *i);
    }
    printf("\n");
}