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
    inline string getnick(){ return nick_; }
    inline void setnick(string nick){ nick_ = nick; }
    inline string getpassword(){ return password_; }
    inline void setpassword(string password){ password_ = password; }
    inline string getnombrecompleto(){ return nombrecompleto_; }
    inline void setnombrecompleto(string nombrecompleto){ nombrecompleto_ = nombrecompleto;}
    inline string getemail(){ return email_; }
    inline void settipo(int tipo){ tipo_ = tipo;}
    inline int gettipo(){ return tipo_; }
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
    Administrador();
    bool ActualizarReserva(string nickReservado, string fechaNueva);
};

class AdministradorUsu: public Administrador{
private:
    bool creaUsuario(string nick, string nombrecompleto, string password, string edad, string tipo);
    bool actualizaUsuario(string ncik);
    //bool comprueba_login(string nick);                                        La introduzco en la clase Usuario
    string seleccionaUsuario();
};

class AdministradorMaq: public Administrador{
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
