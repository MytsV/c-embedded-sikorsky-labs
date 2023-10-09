#include <stdlib.h>
#include <unistd.h>

typedef struct node {
  void *data;
  struct node *next;
} node_t;

// Allocate memory
node_t *list_create(void *data) {
  node_t *ptr = malloc(sizeof(node_t));
  ptr->data = data;
  ptr->next = NULL;
  return ptr;
}

// Free memory
void list_destroy(node_t **head, void (*fp)(void *data)) {
  if (*head == NULL) {
    return;
  }
  list_destroy(&(*head)->next, fp);
  (*fp)((*head)->data);
  free(*head);
  *head = NULL;
}

// Add an element to the end of the list
void list_push(node_t *head, void *data) {
  if (head == NULL) {
    return;
  }

  while (head->next != NULL) {
    head = head->next;
  }
  head->next = list_create(data);
}

// Add an element to the start of the list
void list_unshift(node_t **head, void *data) {
  if (*head == NULL) {
    return;
  }

  node_t *first = *head;
  *head = list_create(data);
  (*head)->next = first;
}

// Remove last element from the list
void *list_pop(node_t **head) {
  node_t *ptr = (*head);
  while (ptr->next->next != NULL) {
    ptr = ptr->next;
  }
  node_t *del_node = ptr->next;
  ptr->next = NULL;
  return del_node;
}

// Remove first element of the list
void *list_shift(node_t **head) {
  node_t *del_node = *head;
  *head = (*head)->next;
  return del_node;
}

// Apply a function to each element of the list
void list_visitor(node_t *head, void (*fp)(void *data)) {
  while (head != NULL) {
    (*fp)(head->data);
    head = head->next;
  }
}