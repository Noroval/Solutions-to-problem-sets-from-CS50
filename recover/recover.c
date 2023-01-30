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
}