#include "listanivel.h"

ListaNivel::ListaNivel()
{
    this->first = NULL;
    this->last = NULL;
    this->size = 0;
}

void ListaNivel::insertar(int numero,MatrizDispersa*MN){
    if(first ==  NULL){
//      nodoMatriz* nuevoNM = new nodoMatriz()
      nodoNivel * nuevo = new nodoNivel(NULL,NULL,numero,MN);
      this->first = nuevo;
      this->last = nuevo;
      nuevo->setsiguiente(this->first);
      nuevo->setanterior(this->last);
      this->size++;
    }else{
        nodoNivel * nuevo = new nodoNivel(this->first,this->last,numero,MN);
        this->last->setsiguiente(nuevo);
        this->last->setanterior(nuevo);
        this->last = nuevo;
        this->size++;
    }
}

void ListaNivel::recorrer(){
    nodoNivel * temp = this->first;
    if(temp !=NULL){
        do{
            cout<<temp->numero <<"----";
            temp = temp->getsiguiente();

        }while(temp!=this->first);
    }
}

void ListaNivel::eliminar(int id){
    nodoNivel * temp = this->first;
    nodoNivel * ant;
    if(temp !=NULL){
        do{
            if(temp->numero==id){
                if(temp ==first && temp == last){
                 first = NULL;
                 last  = NULL;
                 break;
                }else if(temp ==first){
                    this->first = this->first->getsiguiente();
                    this->first->setanterior(this->last);
                    this->last->setsiguiente(this->first);
                    delete(temp);
                    break;
                }else if(temp == last){
                    this->last = last->getanterior();
                    this->first->setanterior(this->last);
                    this->last->setsiguiente(this->first);
                    delete(temp);
                    break;
                }else{
                    ant->setsiguiente(temp->getsiguiente());
                    temp->getsiguiente()->setanterior(ant);
                    delete(temp);
                    break;
                }

            }
            ant = temp;
            temp = temp->getsiguiente();

        }while(temp!=this->first);
    }
}

void ListaNivel::ordenarASC(){
    ordenarASC(this->first,1);
}

void ListaNivel::ordenarASC(nodoNivel*aux,int num){
    if(num <=this->size){
        nodoNivel * temp =  this->first;
        do{
            if(temp->numero < aux->numero){

                nodoNivel * numero = temp;//ppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp
                temp->numero = aux->numero;
                aux->numero = numero->numero;
            }
            temp = temp->getsiguiente();
        }while(temp!=this->first);
        num++;
        ordenarASC(aux->getsiguiente(),num);
    }
}

void ListaNivel::ordenarDESC(){
    ordenaDESC(this->first,1);
}

void ListaNivel::ordenaDESC(nodoNivel*aux,int num){
    if(num <=this->size){
        nodoNivel * temp =  this->first;
        do{
            if(temp->numero > aux->numero){
                nodoNivel * info = temp;
                temp->numero = aux->numero;
                aux->numero = info->numero;
            }
            temp = temp->getsiguiente();
        }while(temp!=this->first);
        num++;
        ordenarASC(aux->getsiguiente(),num);
    }
}

string ListaNivel::graficar(){
    string dot = "digraph {\n"
                 "  rankdir=LR;\n"
                 "  node[shape=record];";
    nodoNivel * temp = this->first;
    if(temp !=NULL){
        do{
            dot+="t"+to_string(temp->numero)+" ";
            dot+="[ label = \""+ to_string(temp->numero) +"\"] \n";
            if (temp->getsiguiente()!=first){
                dot+="t"+to_string(temp->numero)+"->";
                dot+="t"+to_string(temp->getsiguiente()->numero)+"\n";
            }else{
                dot+="t"+to_string(temp->numero)+"->";
                dot+="t"+to_string(first->numero)+"[constraint = false]\n";
            }

            temp = temp->getsiguiente();

        }while(temp!=this->first);
    }
    return dot+="}";
}

void ListaNivel::reporte(){
    string dot = graficar();
    ofstream archivo;
    archivo.open("lista.dot",ios::out);
    archivo <<dot;
    archivo.close();
    system("dot lista.dot -Tpng -o listadoble.png");

}
