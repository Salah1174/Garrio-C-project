#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"
int main()
{
    char s[100];
    printf("\nEnter Name : ");
    fgets(s, sizeof(s), stdin);
    fflush(stdin);
    IsAlpha(s);
}