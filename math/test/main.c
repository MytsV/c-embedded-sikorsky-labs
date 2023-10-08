#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "../include/solution.h"

double tolerance = 0.001;

int main(int argc, char **argv) {
  if (argc < 2) return 1;

  FILE *fh;
  int buff_len = 255;
  char buff[buff_len];

  fh = fopen(argv[1], "r");

  while (fgets(buff, buff_len, fh)) {
    double a;
    double b;
    double res;
    sscanf(buff, "%lf %lf %lf", &a, &b, &res);
    double actual = calc_first(a, b);
    assert(fabs(actual - res) < tolerance);
    assert(fabs(actual - calc_second(b)) < tolerance);
  }

  fclose(fh);
  return 0;
}