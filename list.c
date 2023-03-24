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
    List *Nuevalista= malloc(sizeof(List));
    Nuevalista -> head = NULL;
    Nuevalista -> tail = NULL;
    Nuevalista -> current = NULL;
     return Nuevalista;
}

void * firstList(List * list) {
    
    if(list-> head){
      list -> current = list -> head;
    }
    else return NULL;
    return (list -> head -> data);
}

void * nextList(List * list) {
  if(list -> current== NULL){
    return NULL;
  }
  if(list -> current -> next  == NULL) return  NULL;
  list -> current = list -> current -> next;
  
  return (list -> current-> data);
  
}

void * lastList(List * list) {
   
    if(list-> tail){
      list -> current = list -> tail;
    }
  return  list -> current -> data;
}

void * prevList(List * list) {
  if(list -> current== NULL){
    return NULL;
  }
  if(list -> current -> prev  == NULL) return  NULL;
  list -> current = list -> current -> prev;
  
  return (list -> current-> data);
}

void pushFront(List * list, void * data) {
  Node *nodonuevo = createNode(data);
  if ( list -> head == NULL )
  {
    list -> head = nodonuevo;
    list -> tail = nodonuevo;
    return;
  }
  nodonuevo -> next = list -> head;
  list -> head = nodonuevo;
  return;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node *nodonuevo= createNode(data);
  if (list -> current == NULL){
    list -> head = nodonuevo;
    list -> tail = nodonuevo;
    return;
  }
  if(list -> current == list -> tail) list -> tail = nodonuevo;
  list -> current -> next = nodonuevo;
  nodonuevo -> prev = list -> current;
  list -> current = nodonuevo;
  
  return;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {//curren al nodo siguiente
    //caso 1 "el nodo es el ultimo"
    void * databorrada;
    if (list -> current -> next == NULL){
      list -> current = list -> current -> prev;
      databorrada = list -> current -> next -> data;
      free(list -> current -> next);
      return databorrada;
    }
    //caso 2 " en medio de la lista"
    /*if((list -> current -> next != NULL)&&(list -> current -> prev != NULL)){
      databorrada = list -> current -> data;
      
      
      return  databorrada;
    }*/
  // caso 3 "al inicio de la lista"
    if (list -> current == list -> head){
      databorrada = list -> current -> data;
      list -> head = list -> current -> next;
      free(list -> current);
      list -> current = list -> head;
      return  databorrada;
    }
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}