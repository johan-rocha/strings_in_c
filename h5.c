#include <stdio.h>
#include <string.h>

/* Passos:
    1 - conta quantos caracteres tem em cada palavra
    2 - acha N posições do final de cada palavra contida no texto
    3 - a partir da palavra, desloca todos os caracteres em (qteCaracterPalavraAInserir - qteCaracterPalavraContido)
    4 - insere a palavra a partir da posição do caractere que havia no texto
*/

int countCaracter(char palavra[41]);
int positionWord(char frase[], char p1[]); //acha a palavra e dá a posição dela
void replaceWord(char frase[], char p1[], char p2[]);

int main()
{
    char frase[1001], p1[41], p2[41]; //p1 - palavra contida ; p2 - palavra a substituir

    scanf("%[^\n]s", frase);
    getchar();
    scanf("%[^\n]s", p1);
    getchar();
    scanf("%[^\n]s", p2);
    getchar();
    replaceWord(frase, p1, p2);
    printf("FRASE NOVA = %s\n", frase);

    return 0;
}

void replaceWord(char frase[], char p1[], char p2[])
{
    int sizep1, sizep2, next_word_end_position, deslocamento;
    sizep1 = countCaracter(p1);
    sizep2 = countCaracter(p2);
    next_word_end_position = positionWord(frase, p1); //posicao do caractere apos a palavra


    if(sizep1 < sizep2)
    {
        for(int i=strlen(frase); i >= next_word_end_position; i--) //desloca conjunto de palavras incluindo o caractere \0
        { 
            frase[i+(sizep2 - sizep1)] = frase[i];
            frase[i] = ' ';
        }
        deslocamento = (sizep2 - sizep1);
    }
    else if(sizep1 > sizep2)
    {
        for(int i=(next_word_end_position - (sizep1 - sizep2)); i <= strlen(frase) - (sizep1 - sizep2); i++)
        {
            frase[i] = frase[i + (sizep1 - sizep2)];
        }
        deslocamento = (sizep2 - sizep1);
    }

    int count = (sizep2-1);
    for(int i=((next_word_end_position+deslocamento)-1);i > ((next_word_end_position+deslocamento)-1) - sizep2; i--) //substitui com ele deslocado
    {
        frase[i] = p2[count];
        count --;
    }  
}

//sizep1 < sizep2
//P1 = rato
//P2 = esquilo
//sizep1 > sizep2
//P1 = esquilo 
//P2 = rato

int countCaracter(char palavra[41]) // editar depois
{
    return strlen(palavra);
}

int positionWord(char frase[], char p1[])
{
    int count = 0;

    for(int i=0; i<strlen(frase); i++)
    {
        if(frase[i] == p1[count])
        {
            count++;
            if(count == strlen(p1))
            {
                return (i+1);
            }
        }
        else
            count = 0;
    }
}

