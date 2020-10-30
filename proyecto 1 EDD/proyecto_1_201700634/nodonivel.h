#ifndef NODONIVEL_H
#define NODONIVEL_H
#include<matrizdispersa.h>
#include <nodomatriz.h>
#include <iostream>
#include <fstream>
using namespace  std;

class nodoNivel
{
public:
//    nodoNivel(nodoNivel*s,nodoNivel*a, int n);
    nodoNivel(nodoNivel*s,nodoNivel*a, int n,MatrizDispersa* matrizz);
    nodoNivel* siguiente;
    nodoNivel* anterior;
    int numero;
//    nodoMatriz * nodoMatrizNivel;
    MatrizDispersa* nuevaM = new MatrizDispersa();
//    estudiante* Infoestudiante;
//    nodoNivel(nodoNivel*s,nodoNivel*a,estudiante*stu);
    void setsiguiente(nodoNivel* sig);
    void setanterior(nodoNivel*ant);
    nodoNivel* getsiguiente();
    nodoNivel * getanterior();
};

#endif // NODONIVEL_H
