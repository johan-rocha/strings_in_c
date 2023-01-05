#include <stdio.h>
#include <string.h>

int main()
{
    int count = 0, i;
    char string[60], vogais[5] = {'a', 'e', 'i', 'o', 'u'}, stringVogal[60];
    scanf("%[^\n]s", string);
    getchar();

    for(i=0; i < strlen(string); i++)
    {
        for(int j=0; j < 5; j++)
        {
            if(string[i] == vogais[j])
            {
                stringVogal[count] = vogais[j];
                count++;
            }
        }
    }

    if(count != 0)
    {
        stringVogal[count] = '\0';

        for(i = 0; i < strlen(stringVogal); i++)
        {
            if(stringVogal[i] != stringVogal[(strlen(stringVogal)-1) - i])
                break;
        }
        if(i == strlen(stringVogal))
            puts("S");
        else
            puts("N");
    }
    else
        puts("Valor invalido!");

    /*
    passo 1 - verificar a existencia de vogais (caso não exista, imprimir "Valor invalido!")
    passo 2 - verificar a simetria nos dois sentidos
    passo 3 - imprimir S caso for simetrica ou N caso contrário
    */


    return 0;
}