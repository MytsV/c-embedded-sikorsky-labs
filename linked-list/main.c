#include "include/solution.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *name;
  int price;
  int page_count;
  char *language;
  float weight;
  int publish_year;
} book_t;

book_t *read_book(char *buff) {
  book_t *book = malloc(sizeof(book_t));
  book->name = malloc(sizeof(char) * 128);
  book->language = malloc(sizeof(char) * 64);
  sscanf(buff, "%d %d %s %f %d;%[^\n]s", &(book->price), &(book->page_count),
         book->language, &(book->weight), &(book->publish_year), book->name);
  return book;
}

void print_book(void *data) {
  printf("***\n");
  book_t *book = (book_t *)data;
  printf("Назва: %s\n", book->name);
  printf("Ціна: %dгрн\n", book->price);
  printf("Кількість сторінок: %d\n", book->page_count);
  printf("Мова: %s\n", book->language);
  printf("Вага: %.2fг\n", book->weight);
  printf("Рік видання: %d\n", book->publish_year);
}

void free_book(void *data) {
  book_t *book = (book_t *)data;
  free(book->name);
  free(book->language);
  free(book);
}

// Load books from an input file and delete the last entry
int main(int argc, char **argv) {
  if (argc < 2)
    return 1;

  FILE *fh;
  int buff_len = 1024;
  char buff[buff_len];

  node_t *head = NULL;
  fh = fopen(argv[1], "r");

  while (fgets(buff, buff_len, fh)) {
    book_t *book = read_book(buff);
    if (head == NULL) {
      head = list_create(book);
    } else {
      list_push(head, book);
    }
  }

  fclose(fh);

  // Remove an element and free memory of it
  node_t *removed = list_pop(&head);
  list_destroy(&removed, free_book);

  list_visitor(head, print_book);

  list_destroy(&head, free_book);

  return 0;
}