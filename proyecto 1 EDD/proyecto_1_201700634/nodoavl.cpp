#include "nodoavl.h"

NodoAvl::NodoAvl(int valor)
{
//     this ->ubicacionLista = listaUbicacion;
     this->dato = valor;
     this->izquierdo =this->derecho= NULL;
     this->FactorEquilibrio = 0;
}
//-------------------------------------

int NodoAvl::valorNodo(){
    return dato;
}

NodoAvl* NodoAvl::subarbolIzdo(){
    return this->izquierdo;
}


NodoAvl* NodoAvl::subarbolDcho(){
    return this->derecho;
}


void NodoAvl::ramaIzdo(NodoAvl *n){
    this->izquierdo = n;
}

void NodoAvl::ramaDcho(NodoAvl *n){
    this->derecho =n;
}



void NodoAvl::Pfe(int vfe){
    this->FactorEquilibrio = vfe;
}

int NodoAvl::Ofe(){
    return this->FactorEquilibrio;
}
