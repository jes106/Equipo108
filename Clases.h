#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Funciones.h"

using namespace std;

class Usuario{
public:
    void identificar_usuario();                                             //Funciones modificadas
    bool comprueba_login();
    void imprimeDatos();



    void eliminaUsuario();                                                 //Funciones añadidas por cuenta propia
    bool busca_login();
    void modificaUsuario();
    void modificaUsuarioFichero();      //Funcion para modificar el usuario en el fichero


    inline string getnick(){ return nick_; }
    inline void setnick(string nick){ nick_ = nick; }
    inline string getpassword(){ return password_; }
    inline void setpassword(string password){ password_ = password; }
    inline string getnombrecompleto(){ return nombrecompleto_; }
    inline void setnombrecompleto(string nombrecompleto){ nombrecompleto_ = nombrecompleto;}
    inline string getemail(){ return email_; }
    inline void setemail(string email){ email_ = email; }
    inline int gettipo(){ return tipo_; }
    inline void settipo(int tipo){ tipo_ = tipo;}
    //bool comprueba_login(string nick);                                    Funciones originales del diagrama de clases
    //void identificar_usuario(string *nick, string *password);
protected:
    string nick_;
    string password_;
    string nombrecompleto_;
    string email_;
    int tipo_;

    //Usuario();

};

class Administrador: public Usuario{
protected:
    bool ActualizarReserva(string nickReservado, string fechaNueva);
};

class AdministradorUsu: public Administrador{
public:
    bool creaUsuario();                                                         //Funciones Modificadas
    bool actualizaUsuario();

    //bool creaUsuario(string nick, string nombrecompleto, string password, string edad, string tipo);
    //bool comprueba_login(string nick);                                        La introduzco en la clase Usuario
    string seleccionaUsuario();
};

class AdministradorMaq: public Administrador{
public:
    bool actualizaMaquina();
    bool creaMaquina();
private:
    //bool creaMaquina(string nombre, float recursos);
    //bool actualizaMaquina(string nombre, float nuevoRecurso);
    bool comprueba_maquina(string nombre);
};

class Maquinas{
public:
    inline string getid(){return id_;}
    inline void setid(string id){ id_ = id; }
    inline string getnombre(){ return nombre_; }
    inline void setnombre(string nombre){ nombre_ = nombre; }
    inline string getnick(){ return nick_; }
    inline void setnick(string nick){ nick_ = nick; }
    inline int getnucleos(){ return nucleos_; }
    inline void setnucleos(int nucleos){ nucleos_ = nucleos; }
    inline int getram(){ return ram_; }
    inline void setram(int ram){ ram_ = ram; }
    inline int getnucleoslib(){ return nucleoslib_; }
    inline void setnucleoslib(int nucleos){ nucleoslib_ = nucleos; }
    inline int getramlib(){ return ramlib_; }
    inline void setramlib(int ram){ ramlib_ = ram; }

    void modificaMaquina();
    void eliminaMaquina();
    void modificaMaquinaFichero();
    
private:
    string id_;
    string nombre_;
    string nick_;
    string fechaini_;
    string fechafin_;
    int nucleos_;
    int ram_;
    int nucleoslib_;
    int ramlib_;
};

class Reservas{
public:
    bool creaReserva(string nick);
    void escribeReserva(Reservation maqaux);
private:
    string fechanueva;

        bool actualizaReserva(string login, string fechaNueva);
    string introducir_fecha();
};
