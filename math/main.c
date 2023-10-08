#include "include/solution.h"
#include <stdio.h>

void read(char *name, double *var) {
  printf(name);
  while (scanf("%lf", var) != 1) {
    printf("Wrong input! Try again. %s", name);
    scanf("%*s");
  }
}

int main() {
  double a;
  double b;
  read("a = ", &a);
  read("b = ", &b);
  printf("z1 = %lf\nz2 = %lf\n", calc_first(a, b), calc_second(b));
  return 0;
}