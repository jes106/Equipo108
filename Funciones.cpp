
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "Funciones.h"
using namespace std;


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
    cout << "Seleccione una opcion: ";
    int x;
    cin >> x;
    cin.ignore();                                 //Tenemos que limpiar el buffer despues de un cin para que no se quede almacenado un "\n"
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

void muestraListaMaquinas(vector <Machine> vmaq){
    //Creamos el iterador para recorrer el vector

    cout << "Lista de maquinas disponibles con los recursos." << endl;
    cout << "|ID Maquina|Nombo Maquina|Nucleos libres|RAM libre|" << endl;
    
    //Recorremos el vector e imprimimos.
    for(const auto &i: vmaq){
        cout << i.id << "\t" << i.nombre << "\t" << i.nucleoslibres << "\t" << i.ramlibre << endl;
    }
}

void actualizaMaquinas(string id, string nombre, int nucleos, int ram){
    Machine maqaux;
    //Abrimos el fichero 'maquinas.txt'
    fstream filemaq("Máquinas.txt", ios::in);
    fstream filetemp("Temporal.txt", ios::out);
    if(!filemaq || !filetemp){
        cout << "ERROR al abrir el fichero temporal o el fichero 'Maquinas.txt'." << endl;
        exit(-1);
    }

    //Iremos leyendo del fichero
    while(filemaq >> maqaux.id){
        filemaq >> maqaux.nombre >> maqaux.nucleos >> maqaux.ram >> maqaux.nucleoslibres >> maqaux.ramlibre;

        //Comprobamos que el id de la maquina sea la que se a elegido para realizar la reserva y actulizamos sus nucleos y ram libre
        if( id == maqaux.id){
            maqaux.nucleoslibres = (maqaux.nucleoslibres - nucleos);
            maqaux.ramlibre = (maqaux.ramlibre - ram);
        }

        //Introducimos la los datos ya actualizado en el fichero
        filetemp << maqaux.id << " " << maqaux.nombre << " " << maqaux.nucleos << " " << maqaux.ram << " " << maqaux.nucleoslibres << " " << maqaux.ramlibre << endl;
    }

    //Cerramos el fichero
    filemaq.close();
    filetemp.close();

    remove("Máquinas.txt");
    rename("Temporal.txt", "Máquinas.txt");
}

void menuActualizaMaq(){
    cout << endl;
    cout << "1. Modificar Datos Maquina." << endl;
    cout << "2. Eliminar Maquina." << endl;
}
void menuModificaMaq(){
    cout << "\t ¿Que datos desea modificar? " << endl;
    cout << "\t 1. Nombre." << endl;
    cout << "\t 2. Nucleos." << endl;
    cout << "\t 3. RAM." << endl;
}









