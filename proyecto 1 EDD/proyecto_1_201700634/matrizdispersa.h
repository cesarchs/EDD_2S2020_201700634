#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "nodomatriz.h"
#include <iostream>
#include <fstream>
#include<arbolabb.h>
using namespace std;

class MatrizDispersa
{

public:
    MatrizDispersa();
    bool agregarObjeto(int, string, string,string, string,string,string); // insertar
    bool verificarExistencia(string, string, string);
    ArbolABB * arbolAbbMatriz = new ArbolABB();
//    estudiante* validarSesion(string, string, string, string);
    string recorrerMatriz();
    string catalogoDeActivos();
    void eliminarNodoMatriz(string nombre);
//    estudiante* cambiarEstadoActivo(string, string, string);
//    estudiante* devolverUsuario(string, string, string);
//    estudiante activosDeEmpresa(string);
    string activosDeDepartamento(string);
    //Activo* buscarActivo(string);
    string recorrerDepartamentos();
    string recorrerEmpresas();
    string usuariosMatriz();
    void reporteMatriz();


private:

    nodoMatriz* origen;
    bool verificarCabecerasHorizontales(string);
    bool verificarCabecerasVerticales(string);
    void crearCabeceraHorizontal(string);
    void crearCabeceraVertical(string);
    nodoMatriz* buscarDepartamento(string); //  obtener columna
    nodoMatriz* buscarEmpresa(string); // obtener fila

};

#endif // MATRIZDISPERSA_H
