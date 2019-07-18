/* Squaring program which squares an integer */
#include <stdio.h>
#include <math.h>

double square(input) {
  double inputSquared = pow(input, 2);
  return inputSquared;
}

int main() {
  int a;
  printf("The square of 42 is: %f\n", square(42));
  printf("Please input an integer value: ");
  scanf("%d", &a);
  printf("The input squared is: %f\n", square(a));
}
