# include <stdio.h>
# include <cs50.h>
//esse aqui é o mario more, porém se tirarmos os espaços e hash secundarios virará mario-less
int main (){
    int altura = 0;
    do
    {
        altura = get_int("Height: ");
    }
    while (altura < 1 || altura > 8);

    for (int i=1; i<=altura; i++){
        int whitespaces = altura - i;

        for (int j=0; j < whitespaces; j++) {
            printf(" ");
        }

        for (int j=0; j < i; j++) {
            printf("#");
        }

        printf("  ");

        for (int j=0; j < i; j++) {
            printf("#");
        }

        printf ("\n");
    }

    return 0;


}
