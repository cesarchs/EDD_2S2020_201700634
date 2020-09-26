#include "nodoMatriz.h"

nodoMatriz::nodoMatriz(nodoMatriz* arr, nodoMatriz* ab, nodoMatriz* der, nodoMatriz* izq, nodoMatriz* af, nodoMatriz* ade, int px, int py, string name)//, estudiante* estu)
{
        this->arriba = arr;
        this->abajo = ab;
        this->izquierda = izq;
        this->derecha = der;
        this->afuera = af;
        this->adentro = ade;
        this->posX = px;
        this->posY = py;
        this->nombre = name;
//        this->infoestu = estu;
}
