#include "nodoabb.h"

nodoABB::nodoABB(int dato)// string nombre,string letra,string color, string puntos)
{
    this->dato=dato;
//    this->identificador = id;
//    this->nombre= nombre;
//    this->letra= letra;
//    this->color=color;
//    this->puntos = puntos;
    this->izdo =this->dcho= NULL;
}

nodoABB::nodoABB(int identificador, string nombre,string letra,string color, string puntos)
{
    this->identificador = identificador;
    this->nombre= nombre;
    this->letra= letra;
    this->color=color;
    this->puntos = puntos;
    this->izdo =this->dcho= NULL;
}


int nodoABB::valorNodo(){
    return identificador;
}
string nodoABB::nombreNodo(){
    return nombre;
}
nodoABB* nodoABB::subarbolIzdo(){
    return this->izdo;
}


nodoABB* nodoABB::subarbolDcho(){
    return this->dcho;
}


void nodoABB::ramaIzdo(nodoABB *n){
    this->izdo = n;
}

void nodoABB::ramaDcho(nodoABB *n){
    this->dcho =n;
}
