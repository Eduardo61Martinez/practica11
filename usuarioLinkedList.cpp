#include <iostream>
using namespace std;
#include "LinkedList.h"

int sumatoria(LinkedList xs){
    //Devuelve la suma de todos los elementos. 
    int total= 0;
    ListIterator recorridoActual = getIterator(xs) ;
    while (!atEnd(recorridoActual)){
        total +=current(recorridoActual) ;
        Next(recorridoActual);
    }
    DisposeIterator(recorridoActual);
    return total;
}

void Sucesores(LinkedList xs){
    //Incrementa en uno todos los elementos.
    ListIterator iterador = getIterator(xs) ;
    while (! atEnd(iterador)){
        SetCurrent( current(iterador)+1 ,iterador  );
        Next(iterador);
    }

}

bool pertenece(int x, LinkedList xs){
    //Indica si el elemento pertenece a la lista.
    return true;
}

int apariciones(int x, LinkedList xs){
    //Indica la cantidad de elementos iguales a x.
    return 1;
}

int minimo(LinkedList xs){
    //Devuelve el elemento más chico de la lista.
    return 1;
}

LinkedList copy(LinkedList xs){
    //Dada una lista genera otra con los mismos elementos, en el mismo orden.
    //Nota: notar que el costo mejoraría si Snoc fuese O(1), ¿cómo podría serlo?
    return NULL;
}