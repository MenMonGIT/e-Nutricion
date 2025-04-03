/*
    Proyecto: Nutricion
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto permite trabajar con:
    Uso de clases 
    Uso de bibliotecas
    Uso de APIs
    Reutilización de código
    Software modular y compatibles con otro software

    

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/

#include <iostream>
#include <curl/curl.h>
#include <string>
#include "PeticionCurl.h"
#include "RecepcionJson.h"

using namespace std;

int main(){
    cout<<"hello world"<<endl;
    string receta;
    PeticionCurl peticion1;
    cout<<"Digite la receta: "<<endl;
    getline(std::cin, receta);
    RecepcionJson json1;
    cout<<json1.Json(peticion1.peticionC(receta))<<endl;

    return 0;
}