#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
  // volatile
  int i_am_bad;
  char me_too[258];

  i_am_bad = 0xfa56;
  gets(me_too);

  if(i_am_bad == 0xfb11) {
      printf("You did it!\n");
  } else {
      printf("Try again?\n");
  }
}
