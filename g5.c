#include <stdio.h>
#include <ctype.h>

int tamString(char str[])
{
    int tam = 0;
    for(tam; str[tam] != '\0'; tam++)
    {
        if(str[tam] == '\n')
        {
            str[tam] = '\0';
            tam = 0;
        }
    }
    return tam;
}

char verificaOrdenada(char string[])
{
    for(int i=1; i < tamString(string); i++)
    {
        if(tolower(string[i-1]) >= tolower(string[i]))
            return 'N';
    }
    return 'O';
}

int main()
{
    int qte;
    char palavra[43];
    scanf("%d", &qte);
    getchar();

    for(int i=0; i < qte; i++)
    {
        scanf("%[^\n]s", palavra);
        getchar();
        printf("%s: %c\n", palavra, verificaOrdenada(palavra));

    }
    return 0;
}