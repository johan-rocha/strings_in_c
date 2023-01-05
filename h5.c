#include <stdio.h>

/* Passos:
    1 - conta quantos caracteres tem em cada palavra
    2 - acha posições do final de cada palavra contida no texto
    3 - a partir da palavra, desloca todos os caracteres em (qteCaracterPalavraAInserir - qteCaracterPalavraContido)
    4 - insere a palavra a partir da posição do caractere que havia no texto
*/

int countCaracter(char str[41]); //podera ser usada caso a funcao countCaracter nao funcione
int positionWord(char frase[], char p1[], int cur_position); //acha a palavra e dá a posição dela com base na posicao especificada da string
void replaceWord(char frase[], char p1[], char p2[]); //substitui a palavra

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
    printf("%s\n", frase);

    return 0;
}

void replaceWord(char frase[], char p1[], char p2[])
{
    int sizep1, sizep2, next_word_end_position, deslocamento;
    sizep1 = countCaracter(p1);
    sizep2 = countCaracter(p2);
    next_word_end_position = positionWord(frase, p1, 0); //posicao do caractere apos a palavra

    while(next_word_end_position != -1)
    {
        if(sizep1 < sizep2)
        {
            for(int i=countCaracter(frase); i >= next_word_end_position; i--) //desloca conjunto de palavras incluindo o caractere \0
            { 
                frase[i+(sizep2 - sizep1)] = frase[i];
                frase[i] = ' ';
            }
            deslocamento = (sizep2 - sizep1);
        }
        else if(sizep1 > sizep2)
        {
            for(int i=(next_word_end_position - (sizep1 - sizep2)); i <= countCaracter(frase) - (sizep1 - sizep2); i++)
            {
                frase[i] = frase[i + (sizep1 - sizep2)];
            }
            deslocamento = (sizep2 - sizep1);
        }
        else
            deslocamento = 0;

        int count = (sizep2-1);
        for(int i=((next_word_end_position+deslocamento)-1);i > ((next_word_end_position+deslocamento)-1) - sizep2; i--) //substitui com ele deslocado
        {
            frase[i] = p2[count];
            count --;
        }
        next_word_end_position = positionWord(frase, p1, next_word_end_position+deslocamento);
    }
}

int countCaracter(char str[41]) // editar depois
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

int positionWord(char frase[], char p1[], int cur_position) //cur position e a partir de onde sera analisado
{
    int count = 0;

    for(int i=cur_position; i < countCaracter(frase); i++)
    {
        if(frase[i] == p1[count])
        {
            count++;
            if(count == countCaracter(p1))
            {
                return (i+1);
            }
        }
        else
            count = 0;
    }

    return -1; //quando nao for mais possivel entrar no laco for, a funcao retorna -1 para indicar o fim da string
}

