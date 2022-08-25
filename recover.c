#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


typedef uint8_t BYTE;

#define BLOCK_SIZE 512


int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("This ain't right\n");
        return 1;

    }
    FILE *memcard = fopen(argv[1], "r");
    if (memcard == NULL)
    {
        fclose(memcard);
        printf("ain't a working file\n");
        return 1;
    }
    int jpg_no = 0;
    BYTE blok[512];
    FILE *photo = NULL;
    while (true)
    {
        size_t bytes = fread(blok, sizeof(BYTE), 512, memcard);
        if (bytes == 0)
        {
            break;
        }
        if (blok[0] == 0xff && blok[1] == 0xd8 && blok[2] == 0xff && (blok[3] & 0xf0) == 0xe0)
        {
            if (jpg_no > 0)
            {
                fclose(photo);
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", jpg_no);
            photo = fopen(filename, "w");
            fwrite(blok, sizeof(BYTE), bytes, photo);
            jpg_no += 1;
        }
        else if (jpg_no > 0)
        {
            fwrite(blok, sizeof(BYTE), bytes, photo);
        }
    }

    fclose(photo);
    fclose(memcard);
    return (0);
}
