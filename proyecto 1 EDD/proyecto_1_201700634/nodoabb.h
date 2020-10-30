#ifndef NODOABB_H
#define NODOABB_H
#include <iostream>
#include <string>
using namespace std;

class nodoABB
{

public:
    nodoABB(int identificador, string nombre,string letra,string color, string puntos);
    nodoABB(int dato);
    // operaciones de acceso
     int valorNodo();
     string nombreNodo();



     /* metodos propios */
     nodoABB* subarbolIzdo(); // get izq
     nodoABB* subarbolDcho(); // get derecho
     void ramaIzdo(nodoABB* id); // set izq
     void ramaDcho(nodoABB* id); // set derecho

protected:
     int identificador;
     string nombre;
     string letra;
     string color;
     string puntos;
     int dato;
     nodoABB *izdo;
     nodoABB *dcho;

};

#endif // NODOABB_H
