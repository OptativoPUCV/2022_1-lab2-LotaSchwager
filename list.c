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

  if (list->current == NULL) return NULL;

  if (list->current->next != NULL){
    list->current = list->current->next;

    if (list->current != NULL) return list->current->data;
  }

  return NULL;
}

void * lastList(List * list) {

  list->current = list->tail;
  if (list->current != NULL) return list->current->data;

  return NULL;
}

void * prevList(List * list) {

  if (list->current == NULL) return NULL;

  if (list->current->prev != NULL){
    list->current = list->current->prev;

    if (list->current != NULL) return list->current->data;
  }

  return NULL;
}

void pushFront(List * list, void * data) {

  Node *nuevo = createNode (data);

  if (nuevo != NULL){

    nuevo->next = list->head;
    nuevo->prev = NULL;
    if (list->head != NULL){

      list->head->prev = nuevo;
    }

    list->head = nuevo;
  }

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
  Node* aux = list->current;
  Node* siguiente = nextList(list);
  Node* anterior = nextList(list);

  if (anterior != NULL){

    anterior->next = aux->next;
  }
  else{

    list->head = siguiente;
  }
  if (siguiente != NULL){

    siguiente->next = aux->prev;
  }
  else{

    list->tail = anterior;
  }

  free(list->current);

  return aux->data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}