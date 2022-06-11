#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 26

int main(int argc, string argv[])
{
    if(argc != 2) {
        printf("Usage: ./caesar CYPHERKEY\n");
        return 1;
    }

    for(int i=0; i < strlen(argv[1]); i++) {
        if(!isdigit(argv[1][i])) {
            printf("Usage: ./caesar CYPHERKEY\n");
            return 1;
        }
    }

    int k = atoi(argv[1]);// k que é o cypherkey (./caesar cypherkey)

    string plaintext = get_string("plaintext: ");
    char vetorplain[strlen(plaintext)];
    // char Alfabeto[26];
    // int a;
    // char ciphertext[MAX];
    // for(a='a';a<='z';a++){
    //     Alfabeto[a]=a;
    //     printf("%c ", Alfabeto[a]);
    //     ciphertext[a]=Alfabeto[a]+1%MAX;
    //     printf("%c ", ciphertext[a]);
    // }

    char Ci[MAX];
    printf("ciphertext: ");

    for(int i=0;i<strlen(plaintext);i++){
        if(plaintext[i]<97 && plaintext[i]>=65){//tabela ascii para maiusculas
            vetorplain[i] = plaintext[i] - 64;
            Ci[i]=((vetorplain[i] + k )% MAX) +64;
            printf("%c",Ci[i]);
        }
        else if(plaintext[i]>=97 && plaintext[i]<=122){//tabela ascii para minusculas
            vetorplain[i] = plaintext[i] - 96;
            Ci[i]=((vetorplain[i] + k )% MAX )+ 96;
            printf("%c",Ci[i]);
        }
        else{
            printf("%c",plaintext[i]);
        }


    }
        printf("\n");

}