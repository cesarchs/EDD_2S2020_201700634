#include "arbolabb.h"

ArbolABB::ArbolABB()
{
    this->raiz = NULL;
}

nodoABB* ArbolABB::Oraiz(){
    return this->raiz;
}

void ArbolABB::Praiz(nodoABB*r){
    this->raiz = r;
}

nodoABB* ArbolABB::insertarABB(nodoABB *raiz, int identificador, string nombre, string letra, string color, string puntos) {
    if (raiz == NULL)
    {
        raiz = new nodoABB(identificador,nombre,letra,color,puntos);
    }
    else if (identificador < raiz->valorNodo())
    {
        nodoABB *iz;
        iz = insertarABB(raiz->subarbolIzdo(), identificador,nombre,letra,color,puntos);
        raiz->ramaIzdo(iz);
        // regreso por los nodos del camino de búsqueda
    }
    else if (identificador > raiz->valorNodo())
        {
            nodoABB *dr;
            dr = insertarABB(raiz->subarbolDcho(), identificador,nombre,letra,color,puntos);
            raiz->ramaDcho(dr);
        }
        else
            throw "No puede haber claves repetidas " ;
        return raiz;
    }

void ArbolABB::dibujarArbol(nodoABB *r, int h)
 {
 // escribe las claves del árbol estableciendo separación entre nodos
 int i;
 if (r != NULL)
 {
 dibujarArbol(r->subarbolIzdo(), h + 1);
 for (i = 1; i <= h; i++)
 cout << " ";
 cout << r->valorNodo() << endl;
 dibujarArbol(r->subarbolDcho(), h + 1);
    }
 }
void ArbolABB::insertar(int identificador, string nombre, string letra, string color, string puntos){
    this->raiz = insertarABB(this->Oraiz(), identificador,nombre,letra,color,puntos);
}

void ArbolABB::ObtenerGrafo(nodoABB *raiz){
    string dotocompleto = "digraph grafica{\n"
            "rankdir=TB;\n"
            "node [shape = record, style=filled, fillcolor=seashell2];\n"+
             obtenerDot(raiz)+
             "}\n";

    ofstream archivo;
    archivo.open("arbol.dot",ios::out);
    archivo <<dotocompleto;
    archivo.close();
    system("dot arbol.dot -Tpng -o arbol.png");
}

string ArbolABB::obtenerDot(nodoABB *root){
    string dot;
    if(root->subarbolIzdo() == NULL && root->subarbolDcho() == NULL){
        dot="nodo"+to_string(root->valorNodo())+" [ label =\""+to_string( root->valorNodo()) + " "+root->nombreNodo()+"\"];\n";
    }else{
        dot="nodo"+to_string(root->valorNodo())+" [ label =\"<C0>|"+to_string( root->valorNodo())+" " +root->nombreNodo()+"|<C1>\"];\n";
    }

    if(root->subarbolIzdo()!=NULL){
        dot=dot +obtenerDot(root->subarbolIzdo()) +
                       "nodo"+to_string(root->valorNodo())+":C0->nodo"+to_string(root->subarbolIzdo()->valorNodo())+"\n";
    }

    if (root->subarbolDcho()!=NULL){
        dot=dot + obtenerDot(root->subarbolDcho()) +
                       "nodo"+to_string(root->valorNodo())+":C1->nodo"+to_string(root->subarbolDcho()->valorNodo())+"\n";
    }
    return dot;
}

void ArbolABB::postorden(nodoABB *raiz){
    if(raiz!=NULL){
        postorden(raiz->subarbolIzdo());
        postorden(raiz->subarbolDcho());
        cout<<"dato"<<raiz->valorNodo()<<endl;
    }
}

void ArbolABB::preorden(nodoABB *raiz){
    if(raiz!=NULL){

        cout<<"dato"<<raiz->valorNodo()<<endl;
        postorden(raiz->subarbolIzdo());
        postorden(raiz->subarbolDcho());
    }
}

void ArbolABB::inorden(nodoABB *raiz){
    if(raiz!=NULL){
        postorden(raiz->subarbolIzdo());
        cout<<"dato"<<raiz->valorNodo()<<endl;
        postorden(raiz->subarbolDcho());
    }
}

nodoABB* ArbolABB::aEliminar(int identificador){

    if (raiz != NULL){
        if(raiz->valorNodo()==identificador){
            raiz = raiz->subarbolDcho();
            cout << "se elimino"<<endl;
        }else{
         raiz =raiz->subarbolDcho();
         aEliminar(identificador);
        }
        raiz = raiz->subarbolIzdo();
        aEliminar(identificador);
        }
    return raiz;
    }
