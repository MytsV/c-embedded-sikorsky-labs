#ifndef SOLUTION_H_
#define SOLUTION_H_

typedef struct node {
  void *data;
  struct node *next;
} node_t;

node_t *list_create(void *data);
void list_destroy(node_t **head, void (*fp)(void *data));

void list_push(node_t *head, void *data);
void list_unshift(node_t **head, void *data);

void *list_pop(node_t **head);
void *list_shift(node_t **head);

void list_visitor(node_t *head, void (*fp)(void *data));

#endif /* SOLUTION_H_ */