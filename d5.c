#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char string[100], i = 0;

    scanf("%[^\n]s", string);
    while(string[i] != ' ')
    {
        printf("%c", tolower(string[i]));
        i++;
    }
    printf(".");

    for(i = strlen(string); string[i] != ' '; i--);
    for(i = (i+1); i < strlen(string); i++)
    {
        printf("%c", tolower(string[i]));
    }
    printf("@unb.br\n");

    return 0;
}