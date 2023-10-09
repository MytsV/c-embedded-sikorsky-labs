#include "include/solution.h"
#include <stdio.h>

int main() {
  char buff[255];
  char minus;
  char plus;

  printf("Input a string: ");
  scanf("%[^\n]s", buff);
  printf("Input a character to replace: ");
  scanf(" %c", &minus);
  printf("Input a replacement character: ");
  scanf(" %c", &plus);

  replace(buff, minus, plus);

  printf("%s\n", buff);
  return 0;
}