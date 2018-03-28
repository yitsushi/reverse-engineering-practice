#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
  // volatile
  int i_am_bad;
  char me_too[SIZE];

  i_am_bad = ORIGINAL;
  gets(me_too);

  if(i_am_bad == EXPECTED) {
      printf("You did it!\n");
  } else {
      printf("Try again?\n");
  }
}
