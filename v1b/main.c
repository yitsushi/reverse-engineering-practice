#include <stdio.h>
#include <string.h>

#define H(c) (char)((int)c + 0xf0)
#define U(str) do { char * ptr = str ; while (*ptr) *ptr++ -= 0xf0; } while(0)

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    printf("Usage: %s token\n", argv[0]);
    return 1;
  }

  printf("Checking token: %s\n", argv[1]);

  char valid_key[] = {
    H('\x4c'), H('\x49'), H('\x43'), H('\x45'),
    H('\x4e'), H('\x53'), H('\x45'), H('\x2d'),
    H('\x4b'), H('\x45'), H('\x59'), H('\x2d'),
    H('\x54'), H('\x45'), H('\x53'), H('\x54'),
    H('\x2d'), H('\x30'), H('\x31'), H('\x00')
  };

  // VALID: LICENSE-KEY-TEST-01
  U(valid_key);
  if (strcmp(argv[1], valid_key) == 0) {
    printf("Correct!\n");
  } else {
    printf("Fialed!\n");
  }

  return 0;
}
