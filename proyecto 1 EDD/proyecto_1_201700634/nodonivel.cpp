#include "nodonivel.h"

nodoNivel::nodoNivel(nodoNivel*s,nodoNivel*a, int n, MatrizDispersa*MN)
{
    this->siguiente=s;
    this->anterior=a;
    this->numero=n;
    this->nuevaM= MN;
}
void nodoNivel::setsiguiente(nodoNivel *sig){
    this->siguiente=sig;
}

void nodoNivel::setanterior(nodoNivel *ant){
    this->anterior=ant;
}

nodoNivel* nodoNivel::getsiguiente(){
    return siguiente;
}

nodoNivel* nodoNivel::getanterior(){
    return anterior;
}
