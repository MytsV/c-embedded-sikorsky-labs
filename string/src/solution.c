char replace(char *str, char minus, char plus) {
  for (; *str != '\0'; str++) {
    if (*str == minus) {
      *str = plus;
    }
  }
}