#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* risuto = (List *)malloc(sizeof(List));
  if (risuto == NULL) exit(1);

  risuto->head = NULL;
  risuto->tail = NULL;
  risuto->current = NULL;
  
  return risuto;
}

void * firstList(List * list) {

  list->current = list->head;
  if (list->current != NULL) return list->current->data;

  return NULL;
}

void * nextList(List * list) {

  return NULL;

  
}

void * lastList(List * list) {
  if (list->tail == NULL) return NULL;

  if (list->tail == list->current) return list->current;

  list->current = list->tail;
  return list->current;
}

void * prevList(List * list) {
    return NULL;
}

void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}