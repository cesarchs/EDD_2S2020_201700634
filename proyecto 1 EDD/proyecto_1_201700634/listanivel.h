#ifndef LISTANIVEL_H
#define LISTANIVEL_H
#include <nodonivel.h>
#include <iostream>
#include <fstream>
using namespace  std;

class ListaNivel
{
public:
    ListaNivel();
    void insertar(nodoMatriz *inf);
    void recorrer();
    string graficar();
    void reporte();
    void buscar(int id);
    void eliminar(int id);
    void ordenarASC();
    void ordenarDESC();
private:
    nodoNivel * first;
    nodoNivel * last;
    int size;
    void ordenarASC(nodoNivel*head,int num);
    void ordenaDESC(nodoNivel*head,int num);
};

#endif // LISTANIVEL_H
