#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define MAX_PROFESORES 2
#define TAMANO_NOMBRE 50
#define TAMANO_RFC 13

enum{ ALTA=1, BAJA, CONSULTA, CAMBIO, LISTAR, BUSQUEDA, SALIR} opcionesMenu;

struct Fecha
{
    int anio;
    int mes;
    int dia;
};

class Persona{
    int codigo;
public:
    char nombre[TAMANO_NOMBRE+1];
    char rfc[TAMANO_RFC+1];
    float salario;
    Fecha fechaNAcimiento;
    bool libre;

    bool setCodigo(int codigo){
        if(codigo>0){
            this->codigo = codigo;
            return true;
        } else{
            return false;
        }
    };
    int getCodigo(){
        return codigo;
    }
};

Persona* profesores[MAX_PROFESORES];

void limpiarRegistroProfesor(int indice);
void iniciarPrograma();
void modificarRegistroProfesor(int indice);
bool registroProfesorContieneDatos(int indice);
void mostrarProfesor(int indice);
void darDeAltaProfesor();
void darDeBajaProfesor();
void consultarProfesor();
