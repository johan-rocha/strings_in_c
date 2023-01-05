#include <stdio.h>
#include <string.h>

int main()
{
    char string[1001];
    scanf("%[^\n]s", string);
    printf("%lu\n", strlen(string));
    return 0;
}