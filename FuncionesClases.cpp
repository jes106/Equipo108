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
    getline(cin, nick_);
    cout << "Password -> ";
    getline(cin, password_);

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
         fichero >> aux.password >> aux.nombrecompleto >> aux.email >> aux.tipo;
        /*
        getline(fichero, aux.nick, ';');
        getline(fichero, aux.password, ';');
        getline(fichero, aux.nombrecompleto, ';');
        getline(fichero, aux.email, ';');
        fichero >> aux.tipo;*/

cout << endl;
cout << "Nick -> <" << nick_ << ">" << endl;
cout << "Password -> " << password_ << endl;
cout << endl;
cout << "aux.Nick -> <" << aux.nick << ">" << endl;
cout << "aux.Password -> " << aux.password << endl;
cout << "aux.Nombre Completo -> " << aux.nombrecompleto << endl;
cout << "aux.Email -> " << aux.email << endl;
cout << "aux.Tipo -> " << aux.tipo << endl;
cout << endl;


        if(nick_ == aux.nick && password_ == aux.password){ 
            encontrado = true; 
            nombrecompleto_ = aux.nombrecompleto;
            email_ = aux.email;
            tipo_ = aux.tipo;
        }
        else{ encontrado = 0;}

    }

    if(encontrado == false){
        cout << "El usuario no se encuentra en la base de datos. Contacte con el administrador 1 para que registre." << endl;
    }
cout << endl;
cout << "Encontrado -> " << encontrado << endl;
cout << endl;

    fichero.close();
    return encontrado;
}

void Usuario::imprimeDatos(){
    cout << "Nick -> " << nick_ << endl;
    cout << "Password -> " << password_ << endl;
    //cout << "Nombre Completo -> " << nombrecompleto_ << endl;
    //cout << "Email -> " << email_ << endl;
   // cout << "Tipo -> " << tipo_ << endl;
}

void AdministradorUsu::creaUsuario(){
    string nombre, email;
    int tipo;
    bool encontrado = false;
    Usuario aux;
    string login, contrasena;

    //Pedimos al administrador que introduzca los datos del cliente.
    aux.identificar_usuario();

    encontrado = aux.comprueba_login();

    if(encontrado == false){
        cout << "Introduce el Nombre Completo (sin espacios) -> ";
        getline(cin, nombre, '\n');
        cout << "Introduce el email -> ";
        getline(cin, email);
        cout << "Tipos de Usuario:\n\tAdminitrador de Usuarios = 1\n\tAdministrador de Maquinas = 2\n\tUsuario = 3" << endl;
        cout << "Introduce el tipo de usuario -> ";
        cin >> tipo;
        cin.ignore();
        aux.setnombrecompleto(nombre);
        aux.setemail(email);
        aux.settipo(tipo);

        fstream fichero("BASE_DE_DATOS.txt", ios::app);
        if(!fichero){                                                        //Comprobamos que el fichero se ha abierto correctamente
            cout << "ERROR. Error al abrir el fichero." << endl;
            exit(-1);
        }

        fichero << "\n" << aux.getnick() << " " << aux.getpassword() << " " << aux.getnombrecompleto() << " " << aux.getemail() << " " << aux.gettipo();
        cout << "Usuario añadido con exito." << endl;
    }else{
        cout << "El usuario ya se encuentra en la base de datos." << endl;
    }

    
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