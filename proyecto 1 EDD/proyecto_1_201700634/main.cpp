#include <QCoreApplication>
#include<iostream>

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
