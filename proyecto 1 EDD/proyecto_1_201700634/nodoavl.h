#ifndef NODOAVL_H
#define NODOAVL_H
#include <iostream>
#include <string>
//llamanos a la lista por que en proyecto tiene una lista de niveles que a su vez cada nivel tiene una matriz dispersa
//#include <nodonivel.h>
using namespace std;
// LO NOBRAMOS NODOavl PERO DEBERIA O PODRIA LLAMARSE NODO PROYECTO ó SOLO PROYECTO
class NodoAvl
{   
protected:
//    nodoNivel *ubicacionLista;
    int dato;
    NodoAvl *izquierdo;
    NodoAvl *derecho;
//    int fe;
    int FactorEquilibrio;

public:
    NodoAvl(int dato);

    // operaciones de acceso
     int valorNodo();

     /* metodos propios */
     NodoAvl* subarbolIzdo(); // get izq
     NodoAvl* subarbolDcho(); // get derecho
     void ramaIzdo(NodoAvl* n); // set izq
     void ramaDcho(NodoAvl* n); // set derecho
     void Pfe(int vfe); // set
     int Ofe(); // get
};

#endif // NODOAVL_H
