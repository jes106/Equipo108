#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Funciones.h"

using namespace std;

int main(){

    int encontrado = 0;
    int opcion = 0;
    Usuario usuario;
    string nick, password;


    while(encontrado == 0){
        while(encontrado == 0){
            //En primer lugar vamos a pedir al usario que se identifique, para posteriormente comprobar si un usuario es 
            //administrador1, administrador2 o cliente, con el fin de mostrar un menu personalizado a los privilegios que 
            // tiene casa usuario
            /* Para esto debemos implementar la funcion "identificar_usuario" ya que es como lo expresamos en los diagamas de secuencia*/
            cout << endl << endl;

            identificar_usuario(&nick, &password);

            usuario.nick = nick;
            usuario.password = password;

            //Una vez introducido el nikname y la contraseña tendremos que sabe si el usuario esta registrado en el sistema o no. En caso 
            //de que no exita se tendra que proceder a realizar el registro.
            encontrado = comprueba_login(&usuario);
        }
        cout << endl << endl;
        //Una vez que el usuario ha accedido al sistema se le mostrara un menu personalizado en funcion del tipo de usuario
        if(usuario.tipo == 1 && encontrado == 1){ menuAdmin1(&opcion); }
        else if(usuario.tipo == 2){ menuAdmin2(&opcion); }
        else if(usuario.tipo == 3){ menuUsuario(&opcion); }

        switch (opcion>=1 && opcion<=7){
        case 1:
            crearUsuario();
            break;
       case 2:
            actualizaUsuario();
            break;
    /*    case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
        
            break;*/
        case 0:
            encontrado = 0;
            break;
        }
    }

    return 0;
    
}