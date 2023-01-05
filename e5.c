#include <stdio.h>
#include <string.h>

int main()
{
    char string[101];
    int count = 0;

    while((scanf("%[^\n]s", string)) != EOF)
    {
        getchar();
        for(int i=0; i < strlen(string); i++)
        {
            if(string[i] == 'o') count++;
        }
    }
    printf("%d\n", count);
    return 0;
}