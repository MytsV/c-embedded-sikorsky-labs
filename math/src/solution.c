#include <stdio.h>
#include <math.h>

double calc_first(double a, double b) {
    return (sin(a) + cos(2 * b - a))/(cos(a) - sin(2 * b - a));
}

double calc_second(double b) {
    return (1 + sin(2 * b))/cos(2 * b);
}