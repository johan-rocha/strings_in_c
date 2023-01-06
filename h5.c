#include <stdio.h>

/*-----------------------FUNCTIONS PROTOTYPES----------------------------*/
int countCaracter(char str[41]);
void replaceWord(char phrase[], char text_word[], char to_replace_word[]);
/*-----------------------------------------------------------------------*/

int main()
{
    char phrase[1001], text_word[41], to_replace_word[41];
    scanf(" %[^\n]s", phrase);
    scanf(" %[^\n]s", text_word);
    scanf(" %[^\n]s", to_replace_word);
    replaceWord(phrase, text_word, to_replace_word);
    printf("%s\n", phrase);
}

int countCaracter(char str[41])
{
    int tam;
    for(tam = 0; str[tam] != '\0'; tam++);
    return tam;
}

void replaceWord(char phrase[], char text_word[], char to_replace_word[])
{
    int size_text_word = countCaracter(text_word);
    int size_to_replace_word = countCaracter(to_replace_word);
    int size_phrase = countCaracter(phrase);
    int desloc = size_to_replace_word - size_text_word;
    
    int count = 0;
    for(int i=0; phrase[i] != '\0'; i++)
    {
        if(count >= size_text_word)
            count = 0;
        if (phrase[i] == text_word[count])
        {
            count++;
            if(count == size_text_word)
            {
                //faz o deslocamento. Em cada caso há um sentido de varredura do vetor
                if(size_text_word < size_to_replace_word)//nesse caso, tem que aumentar o tamanho de espacos
                {
                    //o tamanho da string(size_phrase) coincide com a posicao de phrase ate o \0
                    for(int j=size_phrase; j >= (i+1); j--) //i+1 é a posicao do caractere após a palavra
                    {
                        phrase[j+desloc] = phrase[j];
                        phrase[j] = ' ';
                    }
                }
                else if(size_text_word > size_to_replace_word)//nesse caso, tem que diminuir o tamanho de espacos
                {
                    for(int j=(i+1); j <= size_phrase; j++) //i+1 é a posicao do caractere após a palavra
                    {
                        phrase[j+desloc] = phrase[j];
                    }
                }
                
                //faz a substituicao do final do deslocamento ate o inicio da palavra
                int count2 = (size_to_replace_word-1);
                for(int j=i+desloc; j >=(i+desloc)-(size_to_replace_word-1); j--)
                {
                    phrase[j] = to_replace_word[count2];
                    count2--;
                }
                size_phrase = countCaracter(phrase); //o tamanho da frase vai alterando
                i += desloc; //compensa o deslocamento na frase
            }
        }
        else
        {
            count = 0;
        }
    }
}