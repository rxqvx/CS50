#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
//alfabeto======a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q,  r, s, t, u, v, w, x, y, z
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char alfabeto[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1>score2){
        printf("Player 1 wins!\n");
        // printf("Score 1: %d\n", score1);
        // printf("Score 2: %d\n", score2);
    }
    else if(score1<score2){
        printf("Player 2 wins!\n");
        // printf("Score 1: %d\n", score1);
        // printf("Score 2: %d\n", score2);
    }
    else{
        printf("Tie!\n");
    }



}

int compute_score(string word)
{

    int i,j;
    int pontuacao=0;
    int w = strlen(word);
    int a= strlen(alfabeto);
    for(i=0;i<w;i++){
        for(j=0;j<a;j++){
            if((word[i] == alfabeto[j])||(word[i] == toupper(alfabeto[j]))){//se a letra da frase que a pessoa inseriu estiver em alguma posicao do vetor do alfabeto normal ou maiusculo, essa mesma posicao que está em points vai retornar o valor da posicao que vai ser adicionado em pontuacao, e pontuacao vai acrescentando a soma das letras, pois está dentro de um for
            pontuacao = pontuacao + POINTS[j];
            }
        }
    }

    // for(int i=0; i<w; i++){
    //     if(isupper(word[i])){
    //         n = word[i]-65;
    //         n = POINTS[n];
    //     }
    //     if(islower(word[i])){
    //         n = word[i]-97;
    //         n = POINTS[n];
    //     }
    //     else{
    //         n = 0;
    //     }

    //     pontuacao+=n;
    // }
    return pontuacao;
}
