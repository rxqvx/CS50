#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    double words = 1;
    double letters = 0;
    double chars = 0;
    double sentences=0;
    //---------passar a quantidade de letras da string num vetor em char------
    string texto = get_string("Text: ");

    char vetor[strlen(texto)];

    int i;
    for (i = 0; i < strlen(texto); i++) {
        vetor[i] = texto[i];
    }

    for (i=0;i<strlen(texto);i++){
        if (vetor[i] == ' '){//eu havia colocado apenas vetor, porém ocorreu erro de segmentation fault, implemetado [i] para resolver.
            words++;
        }

        if (vetor[i] == '.' || vetor[i] == '!' || vetor[i] == '?'){
            sentences++;
        }

        if(vetor[i] >= 'a' && vetor[i] <= 'z'){
            letters++;
        }

        if(vetor[i] >= 'A' && vetor[i] <= 'Z'){
            letters++;
        }
    }


    printf("A qtd de palavras é : %f\n", words);
    printf("A qtd de letras é : %f\n", letters);
    printf("A qtd de sentenças é: %f\n", sentences);

    double letters_avg = letters / words * 100;
    double sentences_avg = sentences / words * 100;
    double temp_grade = 0.0588 * letters_avg - 0.296 * sentences_avg - 15.8;

    printf("L: %f\n", letters_avg);
    printf("S: %f\n", sentences_avg);
    printf("G: %f\n", temp_grade);

    int grade = (int)(temp_grade < 0 ? (temp_grade - 0.5) : (temp_grade + 0.5));

    if (grade < 1) {
        printf("Before Grade 1\n");
    } else if (grade > 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", grade);
    }
    return 0;
}
