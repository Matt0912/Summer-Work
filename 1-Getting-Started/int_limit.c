/* Checking the limit of int types */
#include <stdio.h>

int main() {
  int i = 2147482000;
  while (i > 0.0) {
    i = i+1;
    printf("%d\n", i);
  }
}
