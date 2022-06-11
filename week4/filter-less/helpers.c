#include "helpers.h"
#include <math.h>

int limit(int rgb) {
    if (rgb > 255) {
        return 255;
    }

    return rgb;
}


int calc(int i, int j, int height,int width, RGBTRIPLE image[height][width], int pcor ){//calcular o blur
    float count = 0;
    int cores = 0;
    for (int k = i - 1; k <  (i + 2); k++){//uma linha antes e uma depois sendo k coluna e l linha
        for (int l = j - 1; l < (j + 2); l ++){
            if(k < 0 || l < 0 || k >= height || l >= width){//se for os pixels em volta do pixel que irá ser modificado
                continue;//prossiga
            }
            if (pcor == 0){
                cores += image[k][l].rgbtRed;//para vermelho 0, 1 green, 2 blue
            }
            else if (pcor == 1){
                cores += image[k][l].rgbtGreen;//calculo da porcentagem da cor escolhida dentre os pixeis em volta do pixel aser modificado
            }
            else if(pcor==2){
                cores += image[k][l].rgbtBlue;
            }
            count++;
        }
    }
    return round(cores /count);
}


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i<height;i++){
        for(int j=0;j<width;j++){
             float avg = round((image[i][j].rgbtRed+image[i][j].rgbtGreen+image[i][j].rgbtBlue)/3.000);

             image[i][j].rgbtRed=avg;
             image[i][j].rgbtBlue=avg;
             image[i][j].rgbtGreen=avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            float sepiaRed= (0.393*image[i][j].rgbtRed)+(0.769*image[i][j].rgbtGreen)+(0.189*image[i][j].rgbtBlue);
            float sepiaGreen= (0.349*image[i][j].rgbtRed)+(0.686*image[i][j].rgbtGreen)+(0.168*image[i][j].rgbtBlue);
            float sepiaBlue= (0.272*image[i][j].rgbtRed)+(0.534*image[i][j].rgbtGreen)+(0.131*image[i][j].rgbtBlue);

            int parsedSepiaRed   =  limit(round(sepiaRed));
            int parsedSepiaBlue  =  limit(round(sepiaBlue));
            int parsedSepiaGreen =  limit(round(sepiaGreen));

            image[i][j].rgbtRed=parsedSepiaRed;
            image[i][j].rgbtGreen=parsedSepiaGreen;
            image[i][j].rgbtBlue=parsedSepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for (int i=0;i<height;i++){//altura, coluna
        for(int j=0;j<width/2;j++){//largura, linha
            // RGBTRIPLE aux = image[i][width-j-1];
            // image[i][j]=aux;


            int aux[3];

            int jInvert = width-j-1;

            aux[0]=image[i][j].rgbtRed;
            aux[1]=image[i][j].rgbtBlue;
            aux[2]=image[i][j].rgbtGreen;

            image[i][j].rgbtRed=image[i][jInvert].rgbtRed;
            image[i][j].rgbtBlue=image[i][jInvert].rgbtBlue;
            image[i][j].rgbtGreen=image[i][jInvert].rgbtGreen;

            image[i][jInvert].rgbtRed=aux[0];
            image[i][jInvert].rgbtBlue=aux[1];
            image[i][jInvert].rgbtGreen=aux[2];
        }
     }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            image[i][j].rgbtRed = calc(i, j, height, width, copy, 0);
            image[i][j].rgbtGreen = calc(i, j, height, width, copy, 1);
            image[i][j].rgbtBlue = calc(i, j, height, width, copy, 2);
        }
    }
    return;
}
