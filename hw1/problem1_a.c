#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack
{
    char data[100];
    size_t top;
} Stack;

int main(void)
{
    char s[100];
    scanf("%s", s);
    const int n = strlen(s);
    Stack stack = {.top = 0};
    char ans[100];
    for (size_t i = 0, j = 0; i < n; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            stack.data[stack.top++] = s[i];
        }
        else
        {
            ans[j++] = s[i];
            ans[j++] = stack.data[--stack.top];
        }
    }
    printf("%s\n", ans);
    return 0;
}