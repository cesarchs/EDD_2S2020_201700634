#ifndef ARBOLABB_H
#define ARBOLABB_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include<nodoabb.h>

class ArbolABB
{
public:
    nodoABB* raiz;
    ArbolABB();
    nodoABB* Oraiz(); // get raiz
    void Praiz( nodoABB *r);// set raiz

    nodoABB* insertarABB(nodoABB* raiz,int identificador, string nombre,string letra,string color, string puntos );
//    nodoABB * aEliminar (int identificador);
    nodoABB* aEliminar (int identificador);
    void dibujarArbol(nodoABB *r, int h); // impresion en consola
    void insertar(int identificador, string nombre,string letra,string color, string puntos);
    void ObtenerGrafo(nodoABB * raiz);
    string obtenerDot(nodoABB*root); // reporte en graphviz


    void preorden(nodoABB* raiz);
    void postorden(nodoABB * raiz);
    void inorden(nodoABB* raiz);

};

#endif // ARBOLABB_H
