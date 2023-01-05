#include <stdio.h>

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

int main()
{
    int n, maior = 0;
    scanf("%d", &n);
    getchar();
    char string[n][100];

    for(int i=0; i<n; i++)
    {
        scanf("%[^\n]s", string[i]);
        getchar();
        if(tamString(string[i]) > maior)
            maior = tamString(string[i]);
    }
    printf("%d\n", maior);

    return 0;
}

