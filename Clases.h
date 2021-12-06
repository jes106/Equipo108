#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

class Usuario{
public:
    void identificar_usuario();                                             //Funciones modificadas
    bool comprueba_login();
    void imprimeDatos();
    inline string getnick(){ return nick; }
    inline string getpassword(){ return password; }
    inline string getnombrecompleto(){ return nombrecompleto; }
    inline string getemail(){ return email; }
    inline int gettipo(){ return tipo; }
    //bool comprueba_login(string nick);                                    Funciones originales del diagrama de clases
    //void identificar_usuario(string *nick, string *password);
protected:
    string nick;
    string password;
    string nombrecompleto;
    string email;
    int tipo;

    //Usuario();

};

class Administrador{
protected:
    Administrador();
    bool ActualizarReserva(string nickReservado, string fechaNueva);
};

class AdministradorUsu{
private:
    bool creaUsuario(string nick, string nombrecompleto, string password, string edad, string tipo);
    bool actualizaUsuario(string ncik);
    //bool comprueba_login(string nick);                                        La introduzco en la clase Usuario
    string seleccionaUsuario();
};

class AdministradorMaq{
private:
    bool creaMaquina(string nombre, float recursos);
    bool actualizaMaquina(string nombre, float nuevoRecurso);
    bool comprueba_maquina(string nombre);
};

class Maquinas{
private:
    string nombre;
    float recursos;
};

class Reservas{
private:
    string fechanueva;

    bool creaReserva(string nick, string fechaNueva);
    bool actualizaReserva(string login, string fechaNueva);
    string introducir_fecha();
};
