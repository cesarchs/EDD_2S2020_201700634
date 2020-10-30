#include "matrizdispersa.h"
#include<arbolabb.h>

MatrizDispersa::MatrizDispersa()
{
this->origen = new nodoMatriz(NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, "xd", "", NULL);

}
// metodo verificar las cabeceras horinzontales

bool MatrizDispersa::verificarCabecerasHorizontales(string depa){
    nodoMatriz* aux = this->origen;

        if(aux->derecha == NULL){
            return false;
        }else{
            while(aux != NULL){
                if(aux->nombre == depa){
                    return true;
                }
                aux = aux->derecha;
            }
            return false;
        }
}
 // insertar cabecera horizontal
void MatrizDispersa::crearCabeceraHorizontal(string depa){
    if(verificarCabecerasHorizontales(depa) == false){
            nodoMatriz* aux = this->origen;
            int x = 1;
            while(aux->derecha != NULL){
                aux = aux->derecha;
                x++;
            }
            aux->derecha = new nodoMatriz(NULL, NULL, NULL, aux, NULL, NULL, x, 0, depa,"", NULL);
        }
}

// verificar cabecera vertical
bool MatrizDispersa::verificarCabecerasVerticales(string empresa){
    nodoMatriz* aux = this->origen;

    if(aux->abajo == NULL){
        return false;
    }else{
        while(aux != NULL){
            if(aux->nombre == empresa){
                return true;
            }
            aux = aux->abajo;
        }
        return false;
    }
}

// insertar cabecera vertical

void MatrizDispersa::crearCabeceraVertical(string empresa){
    if(verificarCabecerasVerticales(empresa) == false){

        nodoMatriz* aux = this->origen;
        int y = 1;
        while(aux->abajo != NULL){
            aux = aux->abajo;
            y++;
        }
        aux->abajo = new nodoMatriz(aux, NULL, NULL, NULL, NULL, NULL, 0, y, empresa,"", NULL);
    }
}

// recorrer columnas
string MatrizDispersa::recorrerDepartamentos(){
   string retorno = "Departamentos disponibles:\n";
   nodoMatriz* aux = this->origen;
   while(aux != NULL){
       if(aux->nombre != "Origen"){
           retorno += aux->nombre + "\n";
       }
       aux = aux->derecha;
   }
   return retorno;
}

// recorrer filas

string MatrizDispersa::recorrerEmpresas(){
    string retorno = "Empresas disponibles:\n";
    nodoMatriz* aux = this->origen;
    while(aux != NULL){
        if(aux->nombre != "Origen"){
            retorno += aux->nombre + "\n";
        }
        aux = aux->abajo;
    }
    return retorno;
}
// buscar departamento (columnas)
nodoMatriz* MatrizDispersa::buscarDepartamento(string depa){
    nodoMatriz* aux = this->origen;
    while(aux != NULL){

        if(aux->nombre == depa){
            break;
        }
        aux = aux->derecha;
    }
    return aux;
}
// buscar empresa (filas)
nodoMatriz* MatrizDispersa::buscarEmpresa(string empresa){
    nodoMatriz* aux = this->origen;
    while(aux != NULL){
        if(aux->nombre == empresa){
            break;
        }
        aux = aux->abajo;
    }
    return aux;
}


// verificar existencia en la matriz



bool MatrizDispersa::verificarExistencia(string usu, string depa, string empresa){

    nodoMatriz* columna = buscarDepartamento(depa);

    nodoMatriz* fila = buscarEmpresa(empresa);

    int x = columna->posX, y = fila->posY;
    if(columna->abajo == NULL || fila->derecha == NULL ){
        return true;
    }else{
        bool band = false;
        while(columna != NULL){
            if(columna->posX == x && columna->posY == y){
                band = true;
                break;
            }
            columna = columna->abajo;
        }
        if(band){
            while(columna != NULL){
                if(columna->nombre== usu){ // PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
                    return false;
                }
                columna = columna->adentro;
            }
        }
        return true;
    }
}

bool MatrizDispersa::agregarObjeto (int id, string nombre, string letra, string color, string puntos , string depa, string empresa){
    crearCabeceraHorizontal(depa);

    crearCabeceraVertical(empresa);

    if(verificarExistencia(nombre, depa, empresa)){

        nodoMatriz* columna = buscarDepartamento(depa);

        nodoMatriz* fila = buscarEmpresa(empresa);
        nodoMatriz* listado;

        int x = columna->posX, y = fila->posY;
        nodoABB * nuevoObjeto = new nodoABB(id,nombre,letra,color,puntos);
        ArbolABB *nuevoArbol = new ArbolABB();
        nuevoArbol->insertar(id,nombre,letra,color,puntos);
        nodoMatriz* nuevo = new nodoMatriz (NULL, NULL, NULL, NULL, NULL, NULL, x, y, letra,color, nuevoObjeto);
        if(columna->abajo == NULL && fila->derecha == NULL){
            nuevo->arriba = columna;
            nuevo->izquierda = fila;
            columna->abajo = nuevo;
            fila->derecha = nuevo;
            return true;
        }else{
            bool band = false;
            if(columna->abajo == NULL){
                while(fila->derecha != NULL){
                    fila = fila->derecha;
                }
                fila->derecha = nuevo;
                columna->abajo = nuevo;
                nuevo->izquierda = fila;
                nuevo->arriba = columna;
                return true;
            }else if(fila->derecha == NULL){
                while (columna->abajo != NULL) {
                    columna = columna->abajo;
                }
                columna->abajo = nuevo;
                fila->derecha = nuevo;
                nuevo->arriba = columna;
                nuevo->izquierda = fila;
                return true;
            }else{
                while(columna != NULL){
                    if(columna->posX == x && columna->posY == y){
                        listado = columna;
                        band = true;
                        break;
                    }
                    columna = columna->abajo;
                }
                if(band){
                    while(listado->adentro != NULL){
                        listado = listado->adentro;
                    }
                    listado->adentro = nuevo;
                    nuevo->afuera = listado;
                    return true;
                }else{
                    columna = buscarDepartamento(depa);
                    fila = buscarEmpresa(empresa);

                    while(columna->abajo !=NULL){
                        if(y > columna->posY && y < columna->abajo->posY){

                            break;
                        }

                        columna = columna->abajo;
                    }

                    while(fila->derecha!=NULL){
                        if(x > fila->posX && x <  fila->derecha->posX){
                            break;
                        }
                        fila = fila->derecha;
                    }

                    // cambios de punteros
                    if(columna->abajo ==NULL){
                        columna->abajo = nuevo;
                        nuevo->arriba = columna;
                    }else{
                     nuevo->abajo = columna->abajo;
                     nuevo->abajo->arriba = nuevo;
                     nuevo->arriba = columna;
                     columna->abajo = nuevo;
                    }

                    // filas
                    if(fila->derecha==NULL){
                     fila->derecha = nuevo;
                     nuevo->izquierda = fila;
                    }else{
                    nuevo->derecha = fila->derecha;
                    nuevo->derecha->izquierda = nuevo;
                    nuevo->izquierda = fila;
                    fila->derecha = nuevo;
                    }


                }
            }
        }
    }else{
        cout<<"false"<<endl;
        return false;
    }
    return false;
    cout<<"false2"<<endl;
}


// metodo para imprimir

string MatrizDispersa::recorrerMatriz(){
    string dot = "digraph G{\nnode[shape = circle]\n";

        nodoMatriz* fila = this->origen;

        nodoMatriz* columna = this->origen;

        while(fila != NULL){
            //string rank = "{rank = same; ";
            while(columna != NULL){
                string actual = to_string(columna->posX) + to_string(columna->posY);
                if(columna->nombre == "Listado"){
                    nodoMatriz* aux = columna;
                    string x = to_string(columna->posX);
                    string y = to_string(-columna->posY);
                    dot += actual + " [label = <<table border = \"0\">";
                    while(aux != NULL){
                        dot += "<tr><td> " + aux->nombre + "</td></tr> \n";
                        aux = aux->adentro;
                    }
                    dot += "</table>>,pos=\""+x+","+y+"!\""+",color=\""+columna->color+"\", style=filled]\n";

                }else{
                    string x = to_string(columna->posX);
                    string y = to_string(-columna->posY);
                    dot +=  actual+" [label = \"" + columna->nombre + "\""+"pos =\""+x+","+y+"!\""+",color=\""+columna->color+"\", style=filled]\n";
                }

                if(columna->arriba != NULL){
                    string arriba = to_string(columna->arriba->posX) + to_string(columna->arriba->posY);
                    dot += actual + " -> " + arriba + "\n" ;
                }
                if(columna->abajo != NULL){
                    string abajo = to_string(columna->abajo->posX) + to_string(columna->abajo->posY);
                    dot += actual + " -> " + abajo + "\n" ;
                }
                if(columna->derecha != NULL){
                    string derecha = to_string(columna->derecha->posX) + to_string(columna->derecha->posY);
                    dot += actual + " -> " + derecha + "\n" ;
                }
                if(columna->izquierda != NULL){
                    string izquierda = to_string(columna->izquierda->posX) + to_string(columna->izquierda->posY);
                    dot += actual + " -> " + izquierda + "\n";
                }

                columna = columna->derecha;
            }

            fila = fila->abajo;
            columna = fila;
        }
        dot += "}";
        return dot;
}

void MatrizDispersa::reporteMatriz(){
    string dot = recorrerMatriz();
    ofstream archivo;
    archivo.open("matriz.txt",ios::out);
    archivo <<dot;
    archivo.close();
    system("neato matriz.txt -Tpng -o matrizrepo.png");
}


void MatrizDispersa::eliminarNodoMatriz(string nombre){

    nodoMatriz* fila = this->origen;
    nodoMatriz* columna = this->origen;

    while (fila != NULL) {
        while (columna != NULL) {
            cout<<columna->nombre<< endl;
            if(columna->nombre==nombre){
                columna->abajo = columna->abajo->abajo;
                columna->adentro = columna->adentro->adentro;
                columna->afuera = columna->afuera->afuera;
                columna->arriba = columna->arriba->arriba;
                columna->derecha = columna->derecha->derecha;
                columna->izquierda = columna->izquierda->derecha;
                cout <<"Se elimino "+ columna->nombre<<endl;
                break;
            }
            columna = columna->derecha;
        }
        fila = fila->abajo;
        columna = fila;
    }

}
