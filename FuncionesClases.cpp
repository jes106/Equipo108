#include "Clases.h"

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



bool AdministradorMaq::actualizaMaquina(){
    bool encontrado;                                //Funcion que servira para saber si el usuario se encuentra en la base de datos y posteriormente
                                                    //para saber si se ha actualizado correctamente
    int opcion;

    Machine maqlec;
    Maquinas maqaux;

    //En primer lugar mostraremos una lista de todas las maquinas que ahy disponibles.
    //Abrimos el fichero 'Maquinas.txt'
    fstream filemaq("Máquinas.txt", ios::in);
    if(!filemaq){
        cout << "Error al abrir el fichero 'Máquinas.txt'" << endl;
        exit(-1);
    }

    cout << endl;
    cout << "Lista de maquinas en el fichero: " << endl;
    cout << "|ID|Nombre Maq|Nucleos|RAM|Nucleos Lib|RAM lib|" << endl;
    while(filemaq >> maqlec.id){
        filemaq >> maqlec.nombre >> maqlec.nucleos >> maqlec.ram >> maqlec.nucleoslibres >> maqlec.ramlibre;
        cout << maqlec.id << "\t" << maqlec.nombre << "\t" << maqlec.nucleos << "\t" << maqlec.ram << "\t" << maqlec.nucleoslibres << "\t" << maqlec.ramlibre << endl;
    }
    filemaq.close();
    
    cout << "Introduce el ID de la maquina a actualizar:" << endl;
    cout << "ID -> ";
    string id;
    getline(cin, id);
    maqaux.setid(id);


    fstream file("Máquinas.txt", ios::in);
    if(!file){
        cout << "Error al abrir el fichero 'Máquinas.txt'" << endl;
        exit(-1);
    }

    //Procedemos a encontrar la maquina seleccionada en el fichero y guardar los datos
    //filemaq.seekg(ios::beg);             //Establecemos el cursor al principio del fichero
    while(file >> maqlec.id){
        file >> maqlec.nombre >> maqlec.nucleos >> maqlec.ram >> maqlec.nucleoslibres >> maqlec.ramlibre;

        if(maqlec.id == maqaux.getid()){
            maqaux.setid(maqlec.id);
            maqaux.setnombre(maqlec.nombre);
            maqaux.setnucleos(maqlec.nucleos);
            maqaux.setram(maqlec.ram);
            maqaux.setnucleoslib(maqlec.nucleoslibres);
            maqaux.setramlib(maqlec.ramlibre);
cout << "ID -> " << maqaux.getid() << endl;
cout << "Nombre -> " << maqaux.getnombre() << endl;
cout << "Nucleos -> " << maqaux.getnucleos() << endl;
cout << "RAM -> " << maqaux.getram() << endl;
cout << "Nucleos Libres -> " << maqaux.getnucleoslib() << endl;
cout << "RAM Libre -> " << maqaux.getramlib() << endl;
        }  
    }

    if(encontrado == true){
        menuActualizaMaq();
        cout << "Elige una opcion -> ";
        cin >> opcion;
        cin.ignore();
    }

    if(opcion == 1){
        maqaux.modificaMaquina();
    }
    if(opcion == 2){
        maqaux.eliminaMaquina();
    }
    file.close();
    return encontrado;
}
bool AdministradorMaq::creaMaquina(){
    
    bool encontrado = true;
    Machine aux;
    

    while(encontrado == true){
        //Pedimos al administrador que introduzca el login para comprobar si esta en la lista.
        cout << endl << "Introduce los datos de la maquina:" << endl;
        cout << "ID -> ";
        getline(cin, aux.id);

        encontrado = busca_maquina(aux.id);
    }

    if(encontrado == false){
        cout << "Introduce el nombre -> ";
        getline(cin, aux.nombre);
        cout << "Introduce los nucleos -> ";
        cin >> aux.nucleos;
        cin.ignore();
        cout << "Introduce la RAM -> ";
        cin >> aux.ram;
        cin.ignore();
        aux.nucleoslibres = aux.nucleos;
        aux.ramlibre = aux.ram;

        fstream fichero("Máquinas.txt", ios::app);
        if(!fichero){                                                        //Comprobamos que el fichero se ha abierto correctamente
            cout << "ERROR. Error al abrir el fichero." << endl;
            exit(-1);
        }

        fichero << aux.id << " " << aux.nombre << " " << aux.nucleos << " " << aux.ram << " " << aux.nucleoslibres << " " << aux.ramlibre << endl;
        cout << "Maquina añadida con exito." << endl;
        encontrado == true;
    }

    return encontrado;
}


void Maquinas::modificaMaquina(){
    int opcion;
    bool encontrado = true;
    //string nick_aux;
    menuModificaMaq();
    cout << "\t Elige -> ";
    cin >> opcion;
    cin.ignore();
    switch (opcion){            //Falta realizar el cambio en el fichero.
        case 1:{                            //La razon de utiluzar llaves en el switch es debido a que creo variables en los casos.
            string nombre;
            cout << "Introduce el nuevo nombre -> ";
            getline(cin, nombre);
            setnombre(nombre);
            break;
        }

        case 2:{
            int nucleos, xnucleos;
            cout << "Introduce los nuevos nucleos -> ";
            cin >> nucleos;
            cin.ignore();
            //Tenemos que comprobar que se puede realizar la modificacion de los nucleos
            xnucleos = getnucleos() - nucleos;
            if(xnucleos > 0){       //NucleosNuevos < NucleosAntiguios
                if(xnucleos > getnucleoslib()){ cout << "No se puede realizar la modificacion puesto que se van a eliminar nucleos que estan siendo usados." << endl; }
                else{ 
                    setnucleos(nucleos);
                    setnucleoslib(nucleoslib_ - nucleos);
                }
            }
            if(xnucleos < 0){       //NucleosNuevos > NucleosAntiguios
                xnucleos = abs(xnucleos);
                setnucleos(nucleos);
                setnucleoslib(nucleoslib_ + xnucleos);
            }
            break;
        }
        case 3:{
            int ram, xram;
            cout << "Introduce la nueva ram -> ";
            cin >> ram;
            cin.ignore();
            //Tenemos que comprobar que se puede realizar la modificacion de los nucleos
            xram = getram() - ram;
            if(xram > 0){       //NucleosNuevos < NucleosAntiguios
                if(xram > getnucleoslib()){ cout << "No se puede realizar la modificacion puesto que se van a eliminar nucleos que estan siendo usados." << endl; }
                else{ 
                    setram(ram);
                    setramlib(ramlib_ - ram);
                }
            }
            if(xram < 0){       //NucleosNuevos > NucleosAntiguios
                xram = abs(xram);
                setram(ram);
                setramlib(ramlib_ + xram);
            }
            break;
        }
    }

    modificaMaquinaFichero();
    cout << "Maquina modificada con exito" << endl;
    
}

void Maquinas::eliminaMaquina(){
    //El procedimiento sera buscar en el fichero el id de la maquina a eliminar.
    string filename = "Máquinas.txt";
    fstream fichero(filename, ios::in);
    fstream temporal("template.txt", ios::out);
    if(!fichero || !temporal){
        cout << "El fichero no se ha podido abrir." << endl;
        exit(-1);
    }

    Machine aux;

    while(fichero >> aux.id){
        fichero >> aux.nombre >> aux.nucleos >> aux.ram >> aux.nucleoslibres >> aux.ramlibre;
        if(aux.id != id_){
            temporal << aux.id << " " << aux.nombre << " " << aux.nucleos << " " << aux.ram << " " << aux.nucleoslibres << aux.ramlibre << endl;
        }
    }

    fichero.close();
    temporal.close();
    remove("Máquinas.txt");
    rename("template.txt", "Máquinas.txt");
}

void Maquinas::modificaMaquinaFichero(){
    //Esta funcion leera el fichero y lo ira almacenando en otro temporal, pero cuando se encuentre con el id que se desea modificar,
    //se guardara la nueva informacion en el fichero tempora. Finalmente eliminaremos el fichero original y al temporal le daremos el 
    //nombre del fichero original

    //Creamos las variables oportunas.
    Machine aux;        //Donde se almacenara los datos leidos del fichero que posteriormente se compararan con los de la clase.
    bool encontrado;    //Variable que nos indicara si un usuario esta o no en la base de datos

    //Abrimos el fichero
    fstream fichero("Máquinas.txt", ios::in);   //Abrimos el fichero original en modo lectura
    fstream temporal("template.txt", ios::out);      //Abrimos el fichero temporal en modo escritura
    if(!fichero || !temporal){       //Comprobamos que los dos ficheros han sido abiertos correctamente
        cout << "Los ficheros no se han abierto correctamente." << endl;
        exit(-1);
    }

    while(fichero >> aux.id){
        fichero >> aux.nombre >> aux.nucleos >> aux.ram >> aux.nucleoslibres >> aux.ramlibre;
        if(aux.id == id_){

            temporal << id_ << " " << nombre_ << " " << nucleos_ << " " << ram_ << " " << nucleoslib_ << " " << ramlib_ << endl;
        }else{
            temporal << aux.id << " " << aux.nombre << " " << aux.nucleos << " " << aux.ram << " " << aux.nucleoslibres << " " << aux.ramlibre << endl;
        }
    }

    fichero.close();
    temporal.close();
    remove("Máquinas.txt");
    rename("template.txt", "Máquinas.txt");
}




bool Reservas::creaReserva(string nick){
    //Definimos las variables
    Reservation reserv;
    Machine maqaux;
    vector <Machine> vmaq; //Creamos un vector que ira almacenando las maquinas leidad
    bool disponible = false;    //Nos indicara si la maquina leida esta disponible o no


    //Asignamos el nick pasado como parametro a la clase
    reserv.nick = nick;

    //Abrimos el fichero 'Maquinas.txt para posteriormente leerlo y obtener una lista de que maquinas estan disponibles con esos recursos. 
    //Abrimos los dos ficheros
    fstream filemaq("Máquinas.txt", ios::in);       //Fichero que contiene la lista de máquinas
    if(!filemaq){
        cout << "Error al abrir el fichero 'maquinas.txt'." << endl;
        exit(-1);
    }

    while(disponible == false){
        //En primer lugar pedimos al usuario que introduzca los datos de la reserva.
        cout << endl << "Introduce los siguientes datos para realizar la reserva: " << endl;
        cout << "Fecha Inicio (dd/mm/aaaa) -> ";
        getline(cin, reserv.fechaini);
        cout << "Fecha Fin (dd/mm/aaaa) -> ";
        getline(cin, reserv.fechafin);
        cout << "Nucleos a reservar -> ";
        cin >> reserv.nucleos;
        cout << "RAM a reservar -> ";
        cin >> reserv.ram;
        cin.ignore();

        
        //Comenzamos a leer el fichero 'Maquinas.txt'
        //Primero obtenemos las máquinas disponibles para los recursos introducidos.
        while(filemaq >> maqaux.id){
            filemaq >> maqaux.nombre >> maqaux.nucleos >> maqaux.ram >> maqaux.nucleoslibres >> maqaux.ramlibre;
            //Comprobamos que la maquina leida tenga los recursos disponibles pedido por el usuario
            if(reserv.nucleos <= maqaux.nucleoslibres && reserv.ram <= maqaux.ramlibre){
                //ME QUEDO AQUI!!!! NO ES NECESARIO COMPROBAR LA FECHA YA QUE CUANDO HACEMOS UNA RESERVA DIRECCTAMENTE ACTUALIZAMOS LOS NUCLEOS Y RAM DISPONIBLE EN EL FICHERO MAQUINAS
                vmaq.push_back(maqaux);
                disponible = true;
            }
        }
        if(disponible == false){ cout << "No se ha encontrado nunguna maquina que tenga libre los recursos elegido. Por favor escoja otra." << endl; }
    }
    //Una vez leidas todas las maquinas que esta disponibles y almacenadas en el vector, se las mostramos al usuario para que elija.
    cout << endl;                                                   //Estetica
    muestraListaMaquinas(vmaq);

    //Pedimos al usuario que introduca el id de la maquina que desea utilizar
    cout << "Introuce el id de la máquina a reservar: ";
    getline(cin, reserv.id);

    //Obtenemos el nombre de la maquina a partir del id.
    for(const auto &i: vmaq){
        if(i.id == reserv.id){ reserv.nombre = i.nombre; }
    }

    //Escribimos en el fichero de reserva la reserva realizada.
    escribeReserva(reserv);
    cout << "Reserva realizada con exito." << endl;

    //Cerramos el fichero
    filemaq.close();

    //Ahora debemos abrir nuestro fichero "maquinas.txt" y actualziar los nucleos y la ram disponible. 
    //Para ello debemos crear un fichero temporal en el que iremos guardando linea a linea del fichero "maquinas.txt" y modificaremos
    //aquellas que lo necesiten
    actualizaMaquinas(reserv.id, reserv.nombre, reserv.nucleos, reserv.ram);

    return true;
}

void Reservas::escribeReserva(Reservation reserv){
    //En esta funcion procederemos a abrir el fichero de reservas en modo lectura con el cursor al final (ios::app) e insertaremos todos los
    //datos de la estructura pasada como parametro en el siguiente orden.
    //<nick>    <id>    <nombre>    <fecha_inicio>    <fecha_fin>    <nucleos>    <ram> 

    //Abrimos el fichero 
    fstream file("Reservas.txt", ios::app);
    if(!file){
        cout << "No se ha podido abrir el fichero 'reservas.txt' " << endl;
        exit(-1);
    }
    //Procedemos a escribir los datos en el fichero
    file << reserv.nick << " " << reserv.id << " " << reserv.nombre << " " << reserv.fechaini << " " << reserv.fechafin << " " << reserv.nucleos << " " << reserv.ram << endl;


    file.close();
}

/*
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

*/

