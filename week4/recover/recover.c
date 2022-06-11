#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    char *filename = argv[1];
    FILE *f = fopen(filename, "r");

    if (f == NULL)
    {
        printf("Error: cannot open %s\n", filename);
        return 2;
    }

    BYTE buffer[512];//utilizado o BYTE, mas acredito que poderia ser escrito como char buffer[521] e na hora do fread: fread(&buffer, sizeof(char), 512,f);
    int count = 0;
    FILE *imagem = NULL;
    char file[8];//card.raw
    while (fread(&buffer, 512, 1, f) == 1)//buffer é onde será armazenado o que foi lido, 512 é o numero de bytes, 1 é o count, f e o arquivo do argv card.raw eu acho
        {
//se começar um novo arquivo jpg com os 4 digitos :
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                // se o primeiro não for jpeg feche o anterior
                if (!(count == 0))
                {
                    fclose(imagem);
                }
                //inicialize o arquivo
                sprintf(file, "%03i.jpg", count);// usado apenas para dar um nome decente para as imamgens
                imagem = fopen(file, "w");
                count++;
            }
//se o jpg for encontrado escreva o arquivo
            if (!(count == 0))
            {
                fwrite(&buffer, 512, 1, imagem);
            }
        }
        fclose(f);
        fclose(imagem);
        return 0;
    }
// }
// }