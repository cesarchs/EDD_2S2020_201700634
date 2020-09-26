#ifndef nodoMatriz_H
#define nodoMatriz_H
#include <nodoavl.h>
#include<iostream>
#include<string>
using namespace std;

class nodoMatriz
{
public:
    //PUNTEROS DE LA MATRIZ
    nodoMatriz* arriba;
    nodoMatriz* abajo;
    nodoMatriz* derecha;
    nodoMatriz* izquierda;
    nodoMatriz* afuera;
    nodoMatriz* adentro;
    int posX;
    int posY;
    string nombre;
//    estudiante * infoestu;
    nodoMatriz(nodoMatriz*, nodoMatriz*, nodoMatriz*, nodoMatriz*, nodoMatriz*, nodoMatriz*, int, int, string );//, estudiante*);
};

#endif // nodoMatriz_H
