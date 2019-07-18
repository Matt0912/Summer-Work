/* Calculates interest on savings */
#include <stdio.h>

double add(double money, double interest_percentage) {
  double interest = money * interest_percentage/100;
  return money + interest;
}

int main() {
  double money;
  double interest;
  printf("Insert amount of money: ");;
  scanf("%lf", &money);
  printf("Insert interest rate (%%): ");
  scanf("%lf", &interest);
  printf("Total after adding interest = %lf\n", add(money, interest));
}
