#ifndef FUNCIONESMAIN_H
#define FUNCIONESMAIN_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

struct Usuario
{
    string nick;
    string password;
    int tipo;                //Indicara el tipo de usuario que es [Administrador1] = 1  [Administrador2] = 2   [Usuario] = 3
};


void identificar_usuario(string *nick, string *password);
int comprueba_login(Usuario *usuario);

void menuAdmin1();
void menuAdmin2();
void menuUsuario();

#endif