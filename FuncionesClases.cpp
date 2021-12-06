#include "Clases.h"

#include <cstring>
#include <iostream>
#include <fstream>
#include "Funciones.h"
using namespace std;


void Usuario::identificar_usuario(){
    cout << "/-----------------------------------------------/" << endl;
    cout << "/           IDENTIFICACION DE USUARIO           /" << endl;
    cout << "/-----------------------------------------------/" << endl;

    cout << "Nickname -> ";
    getline(cin, nick);
    cout << "Password -> ";
    getline(cin, password);

}

bool Usuario::comprueba_login(){
    Users aux;
    bool encontrado = false;                                                        //Variable que indica si el usuario esta o no en la base de datos.

    string filename = "BASE_DE_DATOS.txt";
    fstream fichero(filename, ios::in);                                         //Abrimos el fichero en modo entrada(lectura)
    if(!fichero){
        cout << "Error al abrir el fichero" << endl;
        exit(-1);
    }

    while(fichero >> aux.nick && encontrado == false){
        fichero >> aux.password;
        fichero >> aux.nombrecompleto;
        fichero >> aux.email;
        fichero >> aux.tipo;
    }

    if(nick != aux.nick && password != aux.password){
            cout << "No se encuentra registrado en la Base de Datos. Debe comunicarse con un administrador para que lo registre." << endl;
            encontrado = false;
    }
    else{ encontrado = true; }

    nombrecompleto = aux.nombrecompleto;
    email = aux.email;
    tipo = aux.tipo;
    return encontrado;
}

void Usuario::imprimeDatos(){
    cout << "Nick -> " << nick << endl;
    cout << "Password -> " << password << endl;
    //cout << "Nombre Completo -> " << nombrecompleto << endl;
    //cout << "Email -> " << email << endl;
   // cout << "Tipo -> " << tipo << endl;
}














/*
void Usuario::identificar_usuario(string *nick, string *password){
    cout << "/-----------------------------------------------/" << endl;
    cout << "/           IDENTIFICACION DE USUARIO           /" << endl;
    cout << "/-----------------------------------------------/" << endl;

    cout << "Nickname -> ";
    getline(cin, *nick);
    cout << "Password -> ";
    getline(cin, *password);

}
*/