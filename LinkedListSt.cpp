#include <iostream>
using namespace std;
#include "LinkedList.h"

struct NodoL {
    int elem; // valor del nodo
    NodoL* siguiente; // puntero al siguiente nodo
};

struct LinkedListSt {
// INV.REP.: cantidad indica la cantidad de nodos que se pueden recorrer
// desde primero por siguiente hasta alcanzar a NULL

    int cantidad; // cantidad de elementos
    NodoL* primero; // puntero al primer nodo
}; 


struct IteratorSt {
    NodoL* current;
};


LinkedList nil(){
    LinkedListSt *p = new LinkedListSt;
    p->cantidad = 0;
    p-> primero = NULL;

    return p;

}

bool isEmpty(LinkedList xs){
    if (xs->cantidad == 0){
        return true; 
    }
    else{
        return false;
    }
}

int head(LinkedList xs){
    return xs->primero->elem;
} 

void Cons(int x, LinkedList xs){
    NodoL *node = new NodoL;
    node->elem = x;
    node -> siguiente = xs->primero;

    xs->cantidad++;
}

void Tail(LinkedList xs){
    // PRECOND: lista no vacía
    NodoL *temp  = xs ->primero;
    xs->primero = xs->primero->siguiente;
    xs->cantidad--;
    delete temp;
}

int length(LinkedList xs){
    return xs->cantidad;
}

/* 
void Snoc(int x, LinkedList xs){
    NodoL *n = new NodoL;
    n->elem = x;
    n->siguiente =NULL;

    NodoL *temp = new NodoL; 

    for (int i= 0; i<xs->cantidad; i++){
        temp = xs->primero ;
    }
    temp->siguiente = n;

    //delete temp;
}*/

void Snoc(int x, LinkedList xs) {
    NodoL* nuevo = new NodoL {x, NULL};
    if (xs->primero == NULL) {
        xs->primero = nuevo;
    } else {
        NodoL* actual = xs->primero;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    xs->cantidad++;
}

ListIterator getIterator(LinkedList xs){
    IteratorSt *i = new IteratorSt;
    i->current = xs->primero;
    return i; 
}

int current(ListIterator ixs) {
    // PRECOND: no está al fin del recorrido
    return ixs->current->elem;
}

void SetCurrent(int x, ListIterator ixs){
    ixs->current->elem =x;
}

void Next(ListIterator ixs){
    // PRECOND: no está al fin del recorrido
    ixs->current = ixs->current->siguiente;
}


bool atEnd(ListIterator ixs){
    return ixs->current==NULL;
}

void DisposeIterator(ListIterator ixs){
    delete ixs;
}

void DestroyL(LinkedList xs){
    NodoL* current = xs->primero;
    while (current != NULL) {
        NodoL* next = current->siguiente;
        delete current;
        current = next;
    }
    delete xs;
}
