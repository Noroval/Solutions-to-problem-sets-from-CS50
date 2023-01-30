#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
 if (argc != 2)
 {
    //making sure arguments are 2
    printf("Usage: ./recover IMAGE\n");
    return 1;
 }

//opens file for reading
 FILE *file = fopen(argv[1], "r");
 if (file == NULL)
 {
    printf("Could not open file.\n");
    return 1;
 }

 BYTE buffer[512];
 int count = 0;
 FILE *image = NULL;
 char filename[8];

 //repeat untill end of the card, read 512 bytes into a buffer
 while (fread(&buffer, 512, 1, file) == 1)
 {
  //if start of new JPEG
  if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
  {
    //if not first JPEG, close
    if (!(count == 0))
    {
      fclose(image);
    }
    sprintf(filename, "%03i.jpg", count);
    image = fopen(filename, "w");
    count++;
  }
  if (!(count == 0))
  {
    //write new file
    fwrite(&buffer, 512, 1, image);
  }
 }
 //close any remaining files
 fclose(file);
 fclose(image);
}