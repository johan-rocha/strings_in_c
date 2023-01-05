#include <stdio.h>
#include <string.h>

int main()
{
    int count = 0;
    char frase[1001] = {"A vaca malhada foi molhada por outra vaca molhada e malhada"}, p1[41] = {"malhada"};
    printf("FRASE = %s\nPALAVRA = %s\n", frase, p1);

    for(int i=0; i<strlen(frase); i++)
    {
        if(frase[i] == p1[count])
        {
            count++;
            if(count == strlen(p1))
            {
                printf("A POSICAO EH %d\n", i+1); //aqui vai entrar o return
                break;
            }
        }
        else
            count = 0;
    }
    return 0;
}