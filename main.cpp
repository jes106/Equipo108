#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Funciones.h"
#include "Clases.h"

using namespace std;

int main(){

    bool encontrado = false;
    int opcion = 0;
    Users users;
    string nick, password;
    Usuario cliente;



    while(encontrado == false){
        while(encontrado == false){
            //En primer lugar vamos a pedir al usario que se identifique, para posteriormente comprobar si un usuario es 
            //administrador1, administrador2 o cliente, con el fin de mostrar un menu personalizado a los privilegios que 
            // tiene casa usuario
            /* Para esto debemos implementar la funcion "identificar_usuario" ya que es como lo expresamos en los diagamas de secuencia*/
            cout << endl << endl;

            cliente.identificar_usuario();

            users.nick = nick;
            users.password = password;

            //Una vez introducido el nikname y la contraseña tendremos que sabe si el usuario esta registrado en el sistema o no. En caso 
            //de que no exita se tendra que proceder a realizar el registro.
            encontrado = cliente.comprueba_login();
        }
        cout << endl << endl;
        //Una vez que el usuario ha accedido al sistema se le mostrara un menu personalizado en funcion del tipo de usuario
        if(cliente.gettipo() == 1 && encontrado == 1){ opcion = menuAdmin1(); }
        else if(cliente.gettipo() == 2){ opcion = menuAdmin2(); }
        else if(cliente.gettipo() == 3){ opcion = menuUsuario(); }
        if(opcion>=0 && opcion<=8){
            switch (opcion){
            case 0:
                encontrado = false;
                break;
            case 1:
                crearUsuario();
                break;
            case 2:
                actualizaUsuario();
                break;
            /*case 3:
                actualizaReserva();
                break;
            case 4:
                addMaquina();
                break;
            case 5:
                actualizaMaquina();
                break;
            case 6:
                actualizaReserva();
                break;
            case 7:
                crearReserva();
                break;
            case 8:
                actualizaReserva();
                break;*/
            }
        }
    }

    cout << "Saliendo del programa..." << endl;
    cout << "Hasta luego, tenga un buen día" << endl;
    return 0;
    
}
