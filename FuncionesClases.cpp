#include "Clases.h"
#include "Funciones.h"

#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
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

        if(nick_ == aux.nick && password_ == aux.password){ 
            encontrado = true;
            nick_ = aux.nick;
            password_ = aux.password;
            nombrecompleto_ = aux.nombrecompleto;
            email_ = aux.email;
            tipo_ = aux.tipo;
        }
    }

    if(encontrado == false){
        cout << "El usuario no se encuentra en la base de datos. Contacte con el administrador 1 para que registre." << endl;
    }

    fichero.close();
    return encontrado;
}

bool Usuario::busca_login(){
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

        if(nick_ == aux.nick){ 
            encontrado = true;
            nick_ = aux.nick;
            password_ = aux.password;
            nombrecompleto_ = aux.nombrecompleto;
            email_ = aux.email;
            tipo_ = aux.tipo;
        }
    }

    if(encontrado == false){
        cout << "El usuario no se encuentra en la base de datos." << endl;
    }

    fichero.close();
    return encontrado;
}

void Usuario::imprimeDatos(){
    cout << "Nick -> " << nick_ << endl;
    cout << "Password -> " << password_ << endl;
    cout << "Nombre Completo -> " << nombrecompleto_ << endl;
    cout << "Email -> " << email_ << endl;
    cout << "Tipo -> " << tipo_ << endl;
}

void Usuario::eliminaUsuario(){
    //El procedimiento sera buscar en el fichero el nick de la persona a eliminar.
    string filename = "BASE_DE_DATOS.txt";
    fstream fichero(filename, ios::in);
    fstream temporal("template.txt", ios::out);
    if(!fichero){
        cout << "El fichero no se ha podido abrir." << endl;
        exit(-1);
    }

    Users aux;

    while(fichero >> aux.nick){
        fichero >> aux.password >> aux.nombrecompleto >> aux.email >> aux.tipo;
        if(aux.nick != nick_){
            temporal << aux.nick << " " << aux.password << " " << aux.nombrecompleto << " " << aux.email << " " << aux.tipo << endl;
        }
    }

    fichero.close();
    temporal.close();
    remove("BASE_DE_DATOS.txt");
    rename("template.txt", "BASE_DE_DATOS.txt");
}

void Usuario::modificaUsuario(){
    int opcion;
    bool encontrado = true;
    string nick_aux;
    menuModifica();
    cout << "\t Elige -> ";
    cin >> opcion;
    cin.ignore();
    switch (opcion){            //Falta realizar el cambio en el fichero.
        case 1:{                            //La razon de utiluzar llaves en el switch es debido a que creo variables en los casos.
            string nick;
            while(encontrado == true){
                cout << "Introduce el nuevo nick -> ";
                getline(cin, nick);
                //Como en la funcion busca_login(), el nick que comprobara es el que esta dentro de la clase, debemos guardar el 
                //original en otra variable y meter el nuevo en la clase. En caso de que el nuevo login este en la base de datos, el 
                //usuario se quedara con el mismo que tenia inicialmente y por tanto revertimos el cambio realziado.
                nick_aux = nick_;
                nick_ = nick;
                encontrado = busca_login();
                if(encontrado == true){
                    cout << "El nick introducido ya pertenece a un usuario. Inserte uno nuevo." << endl << endl;
                    nick_ = nick_aux;       //Deshacemos el cambio
                }else{
                    setnick(nick);
                }
            }
            break;
        }

        case 2:{
            string password;
            cout << "Introduce la nueva contraseña -> ";
            getline(cin, password);
            setpassword(password);
            break;
        }
        case 3:{
            string nombrecompleto;
            cout << "Introduce el nuevo nombre completo (sin espacios) -> ";
            getline(cin, nombrecompleto);
            setnombrecompleto(nombrecompleto);
            break;
        }
        case 4:{
            string email;
            cout << "Introduce el nuevo email -> ";
            getline(cin, email);
            setemail(email);
            break;
        }
        case 5:{
            int tipousu;
            cout << "Introduce el nuevo tipo de usuario -> ";
            cin >> tipousu;
            cin.ignore();
            settipo(tipousu);
            break;
        }
    }

    modificaUsuarioFichero();
    cout << "Usuario modificado con exito" << endl;
    
}

void Usuario::modificaUsuarioFichero(){
    //Esta funcion leera el fichero y lo ira almacenando en otro temporal, pero cuando se encuentre con el nick que se desea modificar,
    //se guardara la nueva informacion en el fichero tempora. Finalmente eliminaremos el fichero original y al temporal le daremos el 
    //nombre del fichero original

    //Creamos las variables oportunas.
    Users aux;          //Donde se almacenara los datos leidos del fichero que posteriormente se compararan con los de la clase.
    bool encontrado;    //Variable que nos indicara si un usuario esta o no en la base de datos

    //Abrimos el fichero
    fstream fichero("BASE_DE_DATOS.txt", ios::in);   //Abrimos el fichero original en modo lectura
    fstream temporal("template.txt", ios::out);      //Abrimos el fichero temporal en modo escritura
    if(!fichero || !temporal){       //Comprobamos que los dos ficheros han sido abiertos correctamente
        cout << "Los ficheros no se han abierto correctamente." << endl;
        exit(-1);
    }

    while(fichero >> aux.nick){
        fichero >> aux.password >> aux.nombrecompleto >> aux.email >> aux.tipo;
        if(aux.nick == nick_){
            temporal << nick_ << " " << password_ << " " << nombrecompleto_ << " " << email_ << " " << tipo_ << endl;
        }else{
            temporal << aux.nick << " " << aux.password << " " << aux.nombrecompleto << " " << aux.email << " " << aux.tipo << endl;
        }
    }

    fichero.close();
    temporal.close();
    remove("BASE_DE_DATOS.txt");
    rename("template.txt", "BASE_DE_DATOS.txt");
}

void AdministradorUsu::creaUsuario(){
    string nombre, email;
    int tipo;
    bool encontrado = true;
    Usuario aux;
    string login, contrasena;

    while(encontrado == true){
        //Pedimos al administrador que introduzca el login para comprobar si esta en la lista.
        cout << endl << "Introduce el nick del usuairio a crear: ";
        getline(cin, login);
        aux.setnick(login);

        encontrado = aux.busca_login();
    }

    if(encontrado == false){
        cout << "Introduce una contraseña ->";
        getline(cin, contrasena);
        cout << "Introduce el Nombre Completo (sin espacios) -> ";
        getline(cin, nombre, '\n');
        cout << "Introduce el email -> ";
        getline(cin, email);
        cout << "Tipos de Usuario:\n\tAdminitrador de Usuarios = 1\n\tAdministrador de Maquinas = 2\n\tUsuario = 3" << endl;
        cout << "Introduce el tipo de usuario -> ";
        cin >> tipo;
        cin.ignore();
        aux.setpassword(contrasena);
        aux.setnombrecompleto(nombre);
        aux.setemail(email);
        aux.settipo(tipo);

        fstream fichero("BASE_DE_DATOS.txt", ios::app);
        if(!fichero){                                                        //Comprobamos que el fichero se ha abierto correctamente
            cout << "ERROR. Error al abrir el fichero." << endl;
            exit(-1);
        }

        fichero << aux.getnick() << " " << aux.getpassword() << " " << aux.getnombrecompleto() << " " << aux.getemail() << " " << aux.gettipo() << endl;
        cout << "Usuario añadido con exito." << endl;
    }else{
        cout << "El usuario ya se encuentra en la base de datos." << endl;
    }

    
}

bool AdministradorUsu::actualizaUsuario(){
    bool encontrado;                                //Funcion que servira para saber si el usuario se encuentra en la base de datos y posteriormente
                                                    //para saber si se ha actualizado correctamente
    int opcion;
    string login;
    Usuario aux;

    cout << endl;
    cout << "Introduce los datos del usuario que desea modificar:" << endl;
    cout << "Nickname -> ";
    getline(cin, login);
    aux.setnick(login);
    encontrado = aux.busca_login();                              //Comprobamos que el usuario este en la base de datos

    if(encontrado == true){
        menuActualizaUsu();
        cout << "Elige una opcion -> ";
        cin >> opcion;
        cin.ignore();
    }

    if(opcion == 1){
        aux.modificaUsuario();
    }
    if(opcion == 2){
        aux.eliminaUsuario();
    }

    return encontrado;
}

bool Reservas::creaReserva(string nick){
    //Definimos las variables
    Reservation reserv;
    Reservation reserv_file;
    Machine maqaux;
    vector <Machine> vmaq; //Creamos un vector que ira almacenando las maquinas leidad
    bool disponible = false;    //Nos indicara si la maquina leida esta disponible o no

    //En primer lugar pedimos al usuario que introduzca los datos de la reserva.
    cout << "Introduce los siguientes datos para realizar la reserva: " << endl;
    cout << "Fecha Inicio (dd/mm/aaaa) -> ";
    getline(cin, reserv.fechaini);
    cout << "Fecha Fin (dd/mm/aaaa) -> ";
    getline(cin, reserv.fechafin);
    cout << "Nucleos a reservar -> ";
    cin >> reserv.nucleos;
    cout << "RAM a reservar -> ";
    cin >> reserv.ram;
    cin.ignore();

    //Ahora abriremos el fichero de maquina y mostraremos una lista de que maquinas estan disponibles con esos recursos. Tambien abriremos
    //el fichero reserva y comprobaremos que en dicha fecha no este la maquina reservada
    //Abrimos los dos ficheros
    fstream filemaq("Maquinas.txt", ios::in);
    fstream fileres("Reservas.txt", ios::in);
    if(!filemaq || !fileres){
        cout << "Error al abrir algunos de los ficheros." << endl;
        exit(-1);
    }
    //Primero obtenemos las máquinas disponibles para los recursos introducidos.
    while(filemaq >> maqaux.id){
        filemaq >> maqaux.nombre >> maqaux.nucleos >> maqaux.ram;
        //Comprobamos que la maquina leida tenga los recursos disponibles pedido por el usuario
        if(reserv.nucleos <= maqaux.nucleos && reserv.ram <= maqaux.ram){
            disponible = true;
        }

        //Procedemos a ir leyendo el fichero reservas y vamos comprobando las fechas de las reservas
        while(fileres >> reserv_file.id && disponible == true){     //Tenemos que saber si la maquina leida anteriormente cumple los requisitos
                                                                    //de nucleos y ram, para no hacer una lectura para nada. 
            fileres >> reserv_file.fechaini >> reserv_file.fechafin >> reserv_file.nucleos >> reserv_file.ram;
            //Una vez leida la reserva del fichero tenemos que comprobar la fecha.
            if(cumpruebaFecha(reserv_file.fechaini, reserv_file.fechafin, reserv.fechaini, reserv.fechafin) == true){
                
            }
    }
    }



    //Cerramos los ficheros
    filemaq.close();
    fileres.close();
}


bool AdministradorMaq::actualizaMaquina(string nombre, char nuevosnucleos[1000]='0', char nuevaram[1000]='0'){

	int opcion;
	cout<<"Introduzca la opción que va a querer realizar: 1 (actualizar) o 2 (eliminar)"<<endl;
	cin<<opcion;

	if(opcion==1){

		char aux[1000], aux2[1000],aux3[1000],aux4[1000];
		ifstream f("Máquinas.txt");
		//Creamos un fichero auxiliar al que ir moviendo los datos del original
		ofstream f2("AuxMaq.txt");
		while(f.getline(aux,1000,' ')){
			f.getline(aux2,1000,' ');
			f.getline(aux3,1000,' ');
			f.getline(aux4, 1000, '\n');
			//Si el nombre de máquina es igual al buscado cambiamos sus núcleos y su ram
			if(aux2==nombre){
				aux3=nuevosnucleos;
				aux4=nuevaram;
			}
			f2<<aux<<' '<<aux2<<' '<<aux3<<' '<<aux4<<'\n';



		}
		//Eliminamos el antiguo fichero Máquinas y renombramos el nuevo
		remove("Máquinas.txt");
		raname("AuxMaq.txt","Máquinas.txt");



	}

	if(opcion==2){

		char aux[1000], aux2[1000],aux3[1000],aux4[1000];
		ifstream f("Máquinas.txt");
		//Creamos un fichero auxiliar al que ir moviendo los datos del original
		ofstream f2("AuxMaq.txt");
		while(f.getline(aux,1000,' ')){
			f.getline(aux2,1000,' ');
			f.getline(aux3,1000,' ');
			f.getline(aux4, 1000, '\n');
			//Si el nombre de máquina es igual al buscado no lo metemos en el nuevo fichero si no si y eliminamos los recursos asociados a esta
			if(aux2==nombre){
				bool eliminaReservasMaquinaEliminada(nombre);
				//IMPLEMENTAR ESTA FUNCIÓN

			}

			else{
			f2<<aux<<' '<<aux2<<' '<<aux3<<' '<<aux4<<'\n';
			}



		}
		//Eliminamos el antiguo fichero Máquinas y renombramos el nuevo
		remove("Máquinas.txt");
		raname("AuxMaq.txt","Máquinas.txt");


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
