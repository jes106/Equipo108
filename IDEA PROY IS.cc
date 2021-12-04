#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;



int main(){

    //Se imprime lo siguiente por pantalla para poder acceder con los privilegios de cada administrador
    cout<<"Para ser administrador 1:\n";
    cout<<"el nick debe ser -- admin1 -- y la contraseña -- usuarios --\n";
    cout<<"Para ser administrador 1:\n";
    cout<<"el nick debe ser -- admin2 -- y la contraseña -- maquinas --\n";

    string nick,password;
    cout<<"Introduce tu nickname:\n";
    cin>>nick;
    cout<<"Introduce tu contraseña:\n";
    cin>>password;

    //aqui habría que llamar a una funcion que recogiera el nick del usuario y comprobara si es nuevo o no
    //si es nunevo habria que registrarlo y añadirlo mediante la funcion al fichero de texto
    //si no lo es, este ya estaría registrado y podria acceder a la actualizacion de una reserva suya o la creacion de otra
    //por ej: nuevoUsuario(string nick);

    if(nick=="admin1"){
        //aqui imprimimos el menu del adminitrador 1 (admin de los usuarios)
        menuAdmin1();

    }
    else if(nick=="admin2"){
        //aqui imprimimos el menu del adminitrador 2 (admin de las maquinas)
        menuAdmin2();
        //para poder usar el mismo switch para todos y que a todos les aparezca desde 1 podemos podemos antes de salir del if hacer una suma con las opciones ya acumuladas
    }
    else{
        //aqui imprimimos el menu de los usuarios normales
        menuUsuario();
        //para poder usar el mismo switch para todos y que a todos les aparezca desde 1 podemos podemos antes de salir del if hacer una suma con las opciones ya acumuladas
    }

    int opcion; //creamos este entero para las opciones del switch
    cin>>opcion;
    cout<<endl;

    switch(opcion){
        //hay que tener cuidado pq tal y como está planteado las opciones a las que puede acceder cada uno tienen numeros diferente o se puden solapar (segun el planteamiento)
        //opcion1: poner los numeros correlativos entre las funciones de los menus (mas facil pero mas fea, y habria que comprobar que no se accede a funcionalidades que no se puedan)
        //opcion2: en cada llamada a los menus devolver el numero de la opcion con un return, e igualarlo a opcion para ya entrar en el switch directamente
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:

    }
}

//Posibles funciones a implementar
void nuevoUsuario(string nick); //implica guardarlos en un txt
//las reservas tambien habria que guardarlas en un fichero a traves de una struct: guarda la fecha de inicio(int),la de final(int) y los recursos(int)
void menuAdmin1();
void menuAdmin2();
void menuUsuario();
