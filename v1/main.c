#include <stdio.h>
#include <string.h>

// Test
int main(int argc, const char *argv[])
{
  if (argc < 2) {
    printf("Usage: %s token\n", argv[0]);
    return 1;
  }

  printf("Checking token: %s\n", argv[1]);

  // VALID: LICENSE-KEY-TEST-02
  if (strcmp(argv[1], "LICENSE-KEY-TEST-02") == 0) {
    printf("Correct!\n");
  } else {
    printf("Fialed!\n");
  }

  return 0;
}
