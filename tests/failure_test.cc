#include "my.h"
#include <stdio.h>

int main(void) {
  if (Add_(100, 200) == 300) {
    return 0;
  } else {
    fprintf(stderr, "failed to sum up two integers\n");
    return 1;
  }
}

