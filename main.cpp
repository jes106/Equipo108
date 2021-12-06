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
    string nick, password;
    Usuario cliente;
    AdministradorUsu AdminU;
    AdministradorMaq AdminM;



    while(encontrado == false){
        while(encontrado == false){
            //En primer lugar vamos a pedir al usario que se identifique, para posteriormente comprobar si un usuario es 
            //administrador1, administrador2 o cliente, con el fin de mostrar un menu personalizado a los privilegios que 
            // tiene casa usuario
            /* Para esto debemos implementar la funcion "identificar_usuario" ya que es como lo expresamos en los diagamas de secuencia*/
            printf("\n\n");

            cliente.identificar_usuario();

            //Una vez introducido el nikname y la contraseña tendremos que sabe si el usuario esta registrado en el sistema o no. En caso 
            //de que no exita se tendra que proceder a realizar el registro.
            encontrado = cliente.comprueba_login();

            if(cliente.gettipo() == 1){ 
                AdminU.setnick(cliente.getnick());
                AdminU.setpassword(cliente.getpassword());
                AdminU.setnombrecompleto(cliente.getnombrecompleto());
                AdminU.settipo(cliente.gettipo());
            }
            else if(cliente.gettipo() == 2){ 
                AdminM.setnick(cliente.getnick());
                AdminM.setpassword(cliente.getpassword());
                AdminM.setnombrecompleto(cliente.getnombrecompleto());
                AdminM.settipo(cliente.gettipo());
            }
        }

        //Una vez que el usuario ha accedido al sistema se le mostrara un menu personalizado en funcion del tipo de usuario
        if(cliente.gettipo() == 1){ opcion = menuAdmin1(); }
        else if(cliente.gettipo() == 2){ opcion = menuAdmin2(); }
        else if(cliente.gettipo() == 3){ opcion = menuUsuario(); }


        if(opcion>=0 && opcion<=8){
            switch (opcion){
            case 0:
                encontrado = true;
                break;
            case 1:
                AdminU.creaUsuario();
                encontrado = false;
                break;
            case 2:
                actualizaUsuario();
                encontrado = false;
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

    printf("Saliendo del programa...\n");
    printf("Hasta luego, tenga un bien dia.\n");
    return 0;
    
}
