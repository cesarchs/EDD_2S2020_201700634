#ifndef nodoMatriz_H
#define nodoMatriz_H

#include<iostream>
#include<string>
using namespace std;
//#include <arbolabb.h>
#include<nodoabb.h>

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
    string color;
//    estudiante * infoestu;
    nodoABB * nodoObjeto;
//    ArbolABB * arbolNivel;
    nodoMatriz(nodoMatriz*, nodoMatriz*, nodoMatriz*, nodoMatriz*, nodoMatriz*, nodoMatriz*, int, int, string, string, nodoABB*);//, estudiante*);
};

#endif // nodoMatriz_H
