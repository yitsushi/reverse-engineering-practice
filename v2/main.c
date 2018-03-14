#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    printf("Usage: %s token\n", argv[0]);
    return 1;
  }

  printf("Checking token: %s\n", argv[1]);

  int checksum = 0;
  for (int i = 0; i < strlen(argv[1]); i++) {
    checksum += (int)argv[1][i];
  }

  // VALID: LICENSE-KEY-NEXT-STEP
  if (checksum == 1518) {
    printf("Correct!\n");
  } else {
    printf("Fialed!\n");
  }

  return 0;
}
