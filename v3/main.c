#include <stdio.h>
#include <string.h>

#define CHAR_PER_BLOCK 6
#define NUMBER_OF_BLOCKS 4

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    printf("Usage: %s token\n", argv[0]);
    return 1;
  }

  printf("Checking token: %s\n", argv[1]);

  if (strlen(argv[1]) != CHAR_PER_BLOCK * NUMBER_OF_BLOCKS + (NUMBER_OF_BLOCKS - 1)) {
    printf("Failed!\n");
    return 1;
  }

  int checksum = 0;
  for (int block = 0; block < NUMBER_OF_BLOCKS; block++) {
    for (int i = 0; i < CHAR_PER_BLOCK; i++) {
      checksum += (int)argv[1][(block*(CHAR_PER_BLOCK+1))+i];
    }
  }

  // VALID: LKJHGF-ASDFGH-UYTREW-JHGFDS
  if (checksum == 1801) {
    printf("Correct!\n");
  } else {
    printf("Fialed!\n");
  }

  return 0;
}
