// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)//se o arquivo não tiver nada não da pra ler ne kk
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    //Seu programa deve primeiro ler o cabeçalho do arquivo de entrada e gravar o cabeçalho no arquivo de saída.
    uint8_t header[HEADER_SIZE];//Usando o uint8_ttipo para representar um byte, a cada 1 dentro de [] é 1 byte
    fread(header, sizeof(header), 1, input);
    fwrite(header, sizeof(header), 1, output);



    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer;//Seu programa deve ler o restante dos dados do arquivo WAV, uma amostra de 16 bits (2 bytes) por vez.
    int bytes=2;//16bits

    while (fread(&buffer, bytes, 1, input)){
    buffer = buffer * factor;//Seu programa deve multiplicar cada amostra por factor
    fwrite(&buffer, 2, 1, output);//escrever no arquivo (gravar a leitura em buffer que contém 16 bits, 16bits=2bytes, 1 vez de 16bits,gravar a nova amostra no arquivo de saída)
    }

    // Close files
    fclose(input);
    fclose(output);
}
