#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

#define MAX_PROFESORES 2
#define TAMANIO_NOMBRE 50
#define TAMANIO_RFC 13
#define CARACTERES_POR_FILA 80

typedef enum {FALSO, VERDADERO} booleano;
typedef enum {ALTA=1, BAJA, CONSULTA, CAMBIO, LISTAR, BUSQUEDA, SALIR} opcionMenu;

typedef struct {
    int anio;
    int mes;
    int dia;
}Fecha;

typedef struct{
    int codigo;
    char nombre[TAMANIO_NOMBRE];
    char rfc[TAMANIO_RFC+1];
    float salario;
    Fecha fechaNacimiento;
    booleano libre;
}Persona;

Persona profesores[MAX_PROFESORES];

void pausar();
void limpiarRegistroProfesores(int indice);
void inicializaPrograma();
//void modifidicarRegistroProfesores(int indice);
//booleano elRegistrosPofesoresTieneDatos();
//void mostrarProfesores();
//void darAltaProfesor();
//void darBajaProfesor();
//void consultarProfesores();
//void cambiarDatosProfesor();
//void buscarProfesor();
//void listarProfesor();
int elegirOpcionMenuProfesor();

int main (){
    booleano continuarPrograma=VERDADERO;
    inicializaPrograma(); // Se limpia la memoria RAM
    do{
        switch(elegirOpcionMenuProfesor()){
            //case ALTA: darAltaProfesor();break;
            //case BAJA: darBajaProfesor();break;
            //case CONSULTA: consultarProfesores();break;
            //case CAMBIO: cambiarDatosProfesor(); break;
            //case LISTAR: listarProfesor();break;
            //case BUSQUEDA: buscarProfesor(); break;
            case SALIR: continuarPrograma = FALSO; break;
            default: printf("Opcion no valida\n");
        }
        continuarPrograma ? pausar() : 0;

    } while(continuarPrograma);
    return 0;
}

//Esta funcion limpiara la memoria RAM
void limpiarRegistroProfesores(int indice){
    int i = indice;
    profesores[i].codigo = 0;
    strcpy(profesores[i].nombre, ""); // A excepcion de estas dos lineas de codigo
    strcpy(profesores[i].rfc, "");
    profesores[i].salario = 0;
    profesores[i].fechaNacimiento.anio = 0;
    profesores[i].fechaNacimiento.mes = 0;
    profesores[i].fechaNacimiento.dia = 0;
    profesores[i].libre = VERDADERO;
}

void inicializaPrograma(){
    int i;
    for(i=0; i<MAX_PROFESORES; i++){
        limpiarRegistroProfesores(i);
    }
}

void modifidicarRegistroProfesores(int indice);
booleano elRegistrosPofesoresTieneDatos();
void mostrarProfesores();
void darAltaProfesor();
void darBajaProfesor();
void consultarProfesores();
void cambiarDatosProfesor();
void buscarProfesor();
void listarProfesor();

int elegirOpcionMenuProfesor(){
    int opcion;
    system(CLEAR);
    //imprimirCentrado("");
    printf("\n");
    printf("1. Alta de un nuevo profesor\n");
    printf("2. Baja de un profesor\n");
    printf("3. Consulta de un profesor\n");
    printf("4. Cambio de dsatos de un profesor\n");
    printf("5. Listado de prefesores\n");
    printf("6. Busqueda de un profesor\n");
    printf("7. Salir\n");
    printf("Opción: ");
    scanf("%d", &opcion);
    if(opcion>=ALTA && opcion<=BUSQUEDA){
        system(CLEAR);
    }
    return opcion;
}

void pausar(){
    printf("Presione enter para continuar . . .");
    getchar();
}









