#include <QCoreApplication>
#include<iostream>

#include "arbolavl.h"
#include <listanivel.h>
#include <matrizdispersa.h>
#include<arbolabb.h>
#include<listanivel.h>

//ESTAS SON LAS LIBRERIAS QUE TENEMOS QUE IMPORTAR PARA EL FUNCIONAMIENTO DE JSONS CON QT
#include<QJsonArray>
#include<QJsonObject>
#include <QJsonDocument>
#include<QJsonValue>
#include<QDebug>
#include<QFileDialog>
using namespace std;

//PROTOTIPOS PARA MENUS
void IntroduccionIndice();
void VerProyectos();
void EditarProyectos();
void CargarProyectos();
void GraficarProyectos();
void GuardarProyectos();
void CargarLibrerias();

//VARIABLES PARA EL USO DE DESPLIEGUES DE MENUS
int indice_menuMain;
int main()
{

    cout << "*****************************************************"<<endl;
    cout << "* USAC                                              *"<<endl;
    cout << "*ESTRUCTURA DE DATOS                                *"<<endl;
    cout << "*SECCION B                                          *"<<endl;
    cout << "*CESAR LEONEL CHAMALE SICAN                         *"<<endl;
    cout << "*201700634                                          *"<<endl;
    cout << "*****************************************************"<<endl;
    cout << "*          INDICE DE LO QUE DESEA HACER             *"<<endl;
    cout << "* 1. VER PROYECTOS                                  *"<<endl;
    cout << "* 2. EDITAR PROYECTOS                               *"<<endl;
    cout << "* 3. CARGAR PROYECTO                                *"<<endl;
    cout << "* 4. GRAFICAR PROYECTOS                             *"<<endl;
    cout << "* 5. GUARDAR PROYECTOS                              *"<<endl;
    cout << "* 6. CARGAR LIBRERIAS                               *"<<endl;
    cout << "*****************************************************"<<endl;

//    cout << "este es el arbol ABB "<< endl;
    ArbolAvl * nuevoArbol = new ArbolAvl();
    nuevoArbol->insertar(123);
    nuevoArbol->insertar(124);
    nuevoArbol->insertar(125);
    nuevoArbol->insertar(126);
    nuevoArbol->insertar(127);
    nuevoArbol->ObtenerGrafo(nuevoArbol->Oraiz());

    ArbolABB * nuevoarbol = new ArbolABB();
    nuevoarbol->insertar(122,"objeto1","A","#color1","0,3");
    nuevoarbol->insertar(123,"objeto2","B","#color2","1,2");
    nuevoarbol->insertar(120,"objeto3","C","#color3","2,5");
    nuevoarbol->insertar(121,"objeto4","C","#color3","2,5");
    nuevoarbol->insertar(125,"objeto5","C","#color3","2,5");
    nuevoarbol->insertar(127,"objeto6","C","#color3","2,5");
    nuevoarbol->insertar(129,"objeto7","C","#color3","2,5");
    nuevoarbol->ObtenerGrafo(nuevoarbol->Oraiz());
//    cout<< "engrese el id del nodo que desea eliminar"<<endl;
//    int adelete;
//    cin>>adelete;
//    cout<<adelete <<endl;
//    nuevoarbol->aEliminar(adelete);
//    cout<<" se elimino con exito " +adelete<<endl;
//    nuevoarbol->ObtenerGrafo(nuevoarbol->Oraiz());


    //----------------MATRIZ PARA LA PRUEBA DE LOS NIVELES ------------

//    cout << "matriz disperza "<< endl;
    MatrizDispersa * nuevaMatriz = new MatrizDispersa();
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","0","0");
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","1","1");
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","2","2");
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","3","3");
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","4","4");
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","5","5");
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","6","6");
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","7","7");
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","8","8");
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","9","9");
//    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","10","10");
//    nuevaMatriz->agregarObjeto(2,"E","E","#FDB546","2,6","3","2");
//    cout<<"ingreso exitoso"<<endl;
//    nuevaMatriz->reporteMatriz();
//    nuevaMatriz->arbolAbbMatriz->ObtenerGrafo(nuevaMatriz->arbolAbbMatriz->Oraiz());

//   ------------------------------- ELIMINAR MATRIZ------------------
//    string entradaxd;
//    cin>>entradaxd;
//    nuevaMatriz->eliminarNodoMatriz(entradaxd);
    ListaNivel * nuevaLista = new ListaNivel();
    nuevaLista->insertar(85,nuevaMatriz);
    nuevaLista->insertar(78,nuevaMatriz);
    nuevaLista->insertar(55,nuevaMatriz);


    nuevaLista->insertar(56,nuevaMatriz);
    nuevaLista->insertar(58,nuevaMatriz);
    nuevaLista->insertar(59,nuevaMatriz);
    nuevaLista->recorrer();
    nuevaLista->reporte();

    cout << "ingrese el numero que desea elimiar "<<endl;
        int numero;
        cin>>numero;
    nuevaLista->eliminar(numero);
    cout<<"elinimado "<<endl;
    nuevaLista->recorrer();
    nuevaLista->reporte();

    //--------------NIVEL - PAREDES----------------------------------------------------
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","0","0");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","1","0");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","2","0");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","3","0");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","4","0");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","5","0");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","6","0");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","7","0");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","8","0");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","9","0");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","10","0");

    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","0","1");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","0","2");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","0","3");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","0","4");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","0","5");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","0","6");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","0","7");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","0","8");

    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","1","8");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","2","8");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","3","8");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","4","8");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","5","8");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","6","8");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","7","8");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","8","8");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","9","8");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","10","8");

    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","10","1");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","10","2");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","10","3");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","10","4");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","10","5");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","10","6");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","10","7");

    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","1","5");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","2","5");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","3","5");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","4","5");

    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","5","2");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","5","3");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","5","4");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","5","5");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","5","6");
    nuevaMatriz->agregarObjeto(9,"pared","P","#F6FB34","2,1","5","7");

    nuevaMatriz->agregarObjeto(1,"sofa","s","#FDB546","1,1","1","2");
    nuevaMatriz->agregarObjeto(1,"sofa","s","#FDB546","1,1","2","2");
    nuevaMatriz->agregarObjeto(1,"sofa","s","#FDB546","1,1","3","2");
    nuevaMatriz->agregarObjeto(2,"televicion","T","#E6E6E6","1,1","2","1");
    nuevaMatriz->agregarObjeto(3,"planta","F","#50CB0A","1,2","1","4");
    nuevaMatriz->agregarObjeto(4,"mesa","M","#0A18CB","1,3","3","4");
    nuevaMatriz->agregarObjeto(4,"mesa","M","#0A18CB","1,3","4","4");
    nuevaMatriz->agregarObjeto(4,"mesa","M","#0A18CB","1,3","4","3");
    nuevaMatriz->agregarObjeto(5,"puerta","P","#CB790A","2,1","5","1");
    nuevaMatriz->agregarObjeto(6,"escalera","ES","#02703A","2,1","7","7");
    nuevaMatriz->agregarObjeto(6,"escalera","ES","#02703A","2,1","8","7");
    nuevaMatriz->agregarObjeto(6,"escalera","ES","#02703A","2,1","9","7");
    nuevaMatriz->agregarObjeto(6,"escalera","ES","#02703A","2,1","9","7");
    nuevaMatriz->reporteMatriz();
    cout<<"ingreso exitoso"<<endl;
//    cout<<nuevaMatriz->recorrerMatriz()<<endl;
//    nuevaMatriz->reporteMatriz();
//    nuevoarbol->ObtenerGrafo(nuevoarbol->Oraiz());

    IntroduccionIndice();
    return 0;
}

void IntroduccionIndice(){
    cout<<"introdusca el indice XD"<<endl;
    cin >>indice_menuMain;
//    cout << "este es el incide intruducido: " <<indice_menuMain<<endl;
    if (indice_menuMain==1){
        VerProyectos();
    }
    else if (indice_menuMain==2) {
        EditarProyectos();
    }
    else if (indice_menuMain==3) {
        CargarProyectos();
    }
    else if (indice_menuMain==4) {
        GraficarProyectos();
    }
    else if (indice_menuMain==5) {
        GuardarProyectos();
    }
    else if (indice_menuMain==6) {
        CargarLibrerias();
    }
    else {
        cout<< "indice " <<indice_menuMain << " no existente" <<endl;
        IntroduccionIndice();
    }
}
//metodos para el despliegue de los menus

void VerProyectos(){
    int numeroProySeleccionado;
    cout << "seleccionaste "<<indice_menuMain <<endl;
    cout << "LOS PROYECTOS DISPONIBLES SON: "<<endl;
    //desplegar proyectos
    cout <<"introdusca el indece del proyecto: "<<endl;
    cin >> numeroProySeleccionado;
    //desplegar proyecto
}
void EditarProyectos(){
    int indiceEditProy;
    cout << "seleccionaste "<<indice_menuMain <<endl;
    cout << "**  EDITAR PROYECTO   **" <<endl;
    cout << "************************" <<endl;
    cout << "* 1. AGREGAR NIVEL     *" <<endl;
    cout << "* 2. EDITAR NIVEL      *" <<endl;
    cout << "* 3. ELIMINAR NIVEL    *" <<endl;
    cout << "* 4. ELIMINAR PROYECTO *" <<endl;
    cout << "* 5. SALIR             *" <<endl;
    cout << "************************" <<endl;
    cout << "*  INGRESE EL INDICE:  *" <<endl;
    cin >> indiceEditProy;
    //seguir con las modificaciones

    if (indiceEditProy == 1){
    }
    else if (indiceEditProy == 2){
    }
    else if (indiceEditProy == 3){
    }
    else if (indiceEditProy == 4){
    }
    else if (indiceEditProy == 5){
    }
    else {
        cout<< "indice " <<indiceEditProy << " no existente" <<endl;
        EditarProyectos();
    }
}
void CargarProyectos(){
    cout << "seleccionaste "<<indice_menuMain <<endl;
}
void GraficarProyectos(){
    cout << "seleccionaste "<<indice_menuMain <<endl;
}
void GuardarProyectos(){
    cout << "seleccionaste "<<indice_menuMain <<endl;
}
void CargarLibrerias(){
    cout << "seleccionaste "<<indice_menuMain <<endl;
}












//void abrir_Entrada(){
//    QString json_filter = "JSON (*.json)";
//    QString nombre_archivo = QFileDialog::getOpenFileName(this, tr("abrir archivo"),"/",json_filter,&json_filter,QFileDialog::DontUseNativeDialog);

//}
