#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int d;
    char s1[1000];
    scanf("%[^\n]", s1);
    char *token = strtok(s1, " ");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    return 0;
}