#include <stdio.h>
#include <string.h>

void solve(char *input, int n, char *ans, size_t i, size_t j, char *stack, size_t top);

int main()
{
    char input[100];
    scanf("%s", input);
    int n = strlen(input);
    size_t i = 0, j = 0;
    char ans[100];
    char stack[100];
    solve(input, n, ans, i, j, stack, 0);
    if (stack[0] != '\0')
    {
        ans[n - 1] = stack[0];
    }
    printf("%s\n", ans);
    return 0;
}

void solve(char *input, int n, char *ans, size_t i, size_t j, char *stack, size_t top)
{
    if (i >= n)
    {
        return;
    }
    if (input[i] == '+' || input[i] == '-')
    {
        if (top > 0 && (stack[top - 1] == '+' || stack[top - 1] == '-'))
        {
            ans[j++] = stack[--top];
        }
        stack[top++] = input[i];
    }
    else if (input[i] == '*' || input[i] == '/')
    {
        stack[top++] = input[i];
    }
    else
    {
        ans[j++] = input[i];
        if (top > 0 && (stack[top - 1] == '*' || stack[top - 1] == '/'))
        {
            ans[j++] = stack[--top];
        }
    }
    solve(input, n, ans, i + 1, j, stack, top);
}