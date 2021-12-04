
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include "Funciones.h"
using namespace std;


void identificar_usuario(string *nick, string *password){
    cout << "/-----------------------------------------------/" << endl;
    cout << "/           IDENTIFICACION DE USUARIO           /" << endl;
    cout << "/-----------------------------------------------/" << endl;

    cout << "Nickname -> ";
    getline(cin, *nick);
    cout << "Password -> ";
    getline(cin, *password);

}

int comprueba_login(Usuario *usuario){
    Usuario aux;
    int encontrado = 0;                                                        //Variable que indica si el usuario esta o no en la base de datos.

    string filename = "BASE_DE_DATOS.txt";
    fstream fichero(filename, ios::in);                                         //Abrimos el fichero en modo entrada(lectura)
    if(!fichero){
        cout << "Error al abrir el fichero" << endl;
        exit(-1);
    }

    while(fichero >> aux.nick){
        fichero >> aux.password;
        fichero >> aux.tipo;

        if(usuario->nick == aux.nick && usuario->password == aux.password){
            encontrado=1;
            *usuario = aux;

        }
        else{
            cout << "No se encuentra registrado en la Base de Datos. Debe comunicarse con un administrador para que lo registre." << endl;
            encontrado = 0;
        }
    }

    return encontrado;   
}

void menuAdmin1(){
    int b;  //Creadas solo para que no diera error
}
void menuAdmin2(){
    int v;  //Creadas solo para que no diera error
}
void menuUsuario(){
    int d;  //Creadas solo para que no diera error
}