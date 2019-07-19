/* Example program: say Hi. */
#include <stdio.h>
#include <math.h>

// double root(double x) {
//     double r = x / 2.0;
//     double eps = 1e-15;
//     while (fabs(r - x/r) > eps) {
//         printf("r = %lf\n", r);
//         r = (r + x/r) / 2;
//     }
//     return r;
// }

int main() {
  // print s, n times with commas
  int n = 500000;
  int s = 5;
  for (int i = 0; i < n; i++) {
      if (i > 0) printf(", ");
      printf("%d", s);
  }
  printf("\n");
}
