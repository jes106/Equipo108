#ifndef FUNCIONESMAIN_H
#define FUNCIONESMAIN_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
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

struct Reservation{
    string nick;
    string id;
    string nombre;
    string fechaini;
    string fechafin;
    int nucleos;
    int ram;
};

struct Machine{
    string id;
    string nombre;
    int nucleos;
    int nucleoslibres;
    int ram;
    int ramlibre;
};


//bool comprueba_login(Users *users);

int menuAdmin1();
int menuAdmin2();
int menuUsuario();

void menuActualizaUsu();
void menuModifica();

void muestraListaMaquinas(vector <Machine> vmaq);
void actualizaMaquinas(string id, string nombre, int nucleos, int ram);

void menuActualizaMaq();
void menuModificaMaq();


//void crearUsuario();
//void actualizaUsuario();

#endif
