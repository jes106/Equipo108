#ifndef FUNCIONESMAIN_H
#define FUNCIONESMAIN_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

struct Users
{
    string nick;
    string password;
    string nombrecompleto;
    string email;
    int tipo;                //Indicara el tipo de usuario que es [Administrador1] = 1  [Administrador2] = 2   [Usuario] = 3
};


//bool comprueba_login(Users *users);

int menuAdmin1();
int menuAdmin2();
int menuUsuario();

void menuActualizaUsu();
void menuModifica();


//void crearUsuario();
//void actualizaUsuario();

#endif
