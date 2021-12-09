
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include "Funciones.h"
using namespace std;

/*
bool comprueba_login(Users *users){
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
        fichero >> aux.tipo;
    }

    if(users->nick != aux.nick && users->password != aux.password){
            cout << "No se encuentra registrado en la Base de Datos. Debe comunicarse con un administrador para que lo registre." << endl;
            encontrado = false;
    }
    else{ encontrado = true; }

    *users = aux;
    return encontrado;   
}


void crearUsuario(){
    Users aux;

    //Pedimos al administrador que introduzca los datos del cliente.
    cout << "Introduce nick -> ";
    getline(cin, aux.nick);
    cout << "Introduce password -> ";
    getline(cin, aux.password);
    cout << "Tipos de Usuario:\n\tAdminitrador 1 = 1\n\tAdministrador 2 = 2\n\tUsuario = 3" << endl;
    cout <<  "Introduce el tipo de usuario -> ";
    cin >> aux.tipo;

    fstream fichero("BASE_DE_DATOS.txt", ios::app);
    if(!fichero){                                                        //Comprobamos que el fichero se ha abierto correctamente
        cout << "ERROR. Error al abrir el fichero." << endl;
        exit(-1);
    }

    fichero << aux.nick << "\t" << aux.password << "\t" << aux.tipo << endl;
    cout << "Usuario añadido con exito." << endl;
}
*/
int menuAdmin1(){
    cout << endl;
    cout << "0. Cerrar Sesion." << endl;
    cout << "1. Crear Usuario." << endl;
    cout << "2. Actualizar Usuarios." << endl;
    cout << "3. Actualizar Reservas." << endl;
    cout << "Seleccione una opcion:";
    int x;
    cin >> x;
    
    cin.ignore();                                  //Tenemos que limpiar el buffer despues de un cin para que no se quede almacenado un "\n"
    return x;
}
int menuAdmin2(){
    cout << endl;
    cout << "0. Cerrar Sesion." << endl;
    cout << "1. Añadir Maquina." << endl;
    cout << "2. Actualizar Maquinas." << endl;
    cout << "3. Actualizar Reservas." << endl;
    cout << "Seleccione una opcion:";
    int x;
    cin >> x;
    cin.ignore();

    if(x==1){ x=4; }
    else if(x==2){ x=5; }
    else if(x==3){ x=6; }
    else{ return 0; }

    return x;
}
int menuUsuario(){
    cout << endl;
    cout << "0. Cerrar Sesion." << endl;
    cout << "1. Crear Reserva." << endl;
    cout << "2. Actualizar Reserva." << endl;
    cout << "Seleccione una opcion:";
    int x;
    cin >> x;
    
    fflush(stdin);                                  //Tenemos que limpiar el buffer despues de un cin para que no se quede almacenado un "\n"
    if(x==1){ x=7; }
    else if(x==2){ x=8; }
    else{ return 0; }

    return x;    
}

void menuActualizaUsu(){
    cout << endl;
    cout << "1. Modificar Datos Usuario." << endl;
    cout << "2. Eliminar Usuario." << endl;
}
void menuModifica(){
    cout << "\t ¿Que datos desea modificar? " << endl;
    cout << "\t 1. Nick." << endl;
    cout << "\t 2. Password." << endl;
    cout << "\t 3. Nombre Compelto." << endl;
    cout << "\t 4. Email." << endl;
    cout << "\t 5. Tipo de Usuario." << endl;
}

bool cumpruebaFecha(string FFI, string FFN, string UFI, string UFN){
    /* SIGNIFICADO DE PARAMETROS */
    // - FFI -> Fecha inicio leida del fichero
    // - FFN -> Fecha fin leida del fichero
    // - UFI -> Fecha inicio del usuario
    // - UFN -> Fecha fin del usuario
}










