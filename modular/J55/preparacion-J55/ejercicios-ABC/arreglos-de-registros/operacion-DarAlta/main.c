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
    char nombre[TAMANIO_NOMBRE+1];
    char rfc[TAMANIO_RFC+1];
    float salario;
    Fecha fechaNacimiento;
    booleano libre;
}Persona;

Persona profesores[MAX_MATERIAS];

void pausar();
void limpiarRegistroProfesores(int indice);
void inicializaPrograma();
//void modifidicarRegistroProfesores(int indice);
//booleano elRegistrosPofesoresTieneDatos();
//void mostrarProfesores();
void darAltaProfesor();
//void darBajaProfesor();
//void consultarProfesores();
//void cambiarDatosProfesor();
//void buscarProfesor();
void listarProfesor();
int elegirOpcionMenuProfesor();

int main (){
    booleano continuarPrograma=VERDADERO;
    inicializaPrograma(); // Se limpia la memoria RAM
    do{
        switch(elegirOpcionMenuProfesor()){
            case ALTA: darAltaProfesor();break;
            //case BAJA: darBajaProfesor();break;
            //case CONSULTA: consultarProfesores();break;
            //case CAMBIO: cambiarDatosProfesor(); break;
            case LISTAR: listarProfesor();break;
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
    for(i=0; i<MAX_MATERIAS; i++){
        limpiarRegistroProfesores(i);
    }
}

void modifidicarRegistroProfesores(int indice){
    int i = indice;
    printf("Provee datos para el registro %d.\n", i+1);
    printf("Codigo: ");
    scanf("%d", &profesores[i].codigo);
    printf("Nombre: ");
    getchar();
    //fgets agregar un salto de linea al final del arreglo recibido esto es de ayuda para que este arreglo al momento de imprimirlo tenga un salto de linea por defecto
    //Ademas incrementa en uno el tamaño del array decibido
    fgets(profesores[i].nombre, TAMANIO_NOMBRE+1, stdin);
    profesores[i].nombre[strlen(profesores[i].nombre) -1 ] = '\0'; //Elimina el salto de linea que existe una casilla despues de la recibida    
    printf("RFC: ");
    scanf("%s", profesores[i].rfc);
    printf("Salario: ");
    scanf("%f", &profesores[i].salario);
    printf("Fecaha de nacimiento aaaa/mm/dd: ");
    scanf("%d/%d/%d", &profesores[i].fechaNacimiento.anio, &profesores[i].fechaNacimiento.mes, &profesores[i].fechaNacimiento.dia);
    profesores[i].libre = FALSO;
}

booleano elRegistrosPofesoresTieneDatos();
void mostrarProfesores();

void darAltaProfesor(){
    booleano hayEspacioLibre;
    int i;
    
    printf("ALTA DE NUEVO PROFESOR\n\n");
    hayEspacioLibre = FALSO;

    for(i=0 ; i<MAX_MATERIAS; i++){
        if(profesores[i].libre){
            hayEspacioLibre = VERDADERO;
            break;
        } //else seguir Buscando un espaciolibre
    }

    if(hayEspacioLibre){
        modifidicarRegistroProfesores(i);
    } else {
        printf("No hay mas espacios para capturar");
    }

}

void darBajaProfesor();

void consultarProfesores(){

}

void cambiarDatosProfesor();
void buscarProfesor();

void listarProfesor(){
    booleano hayProfesores = FALSO;
    printf("LISTADO DE PROFESORES");
    printf("#\tCodigo\tNombre\n");
    int i;
    for( i=0 ; i<MAX_MATERIAS ; i++){
        if(!profesores[i].libre){
            hayProfesores = VERDADERO;
            printf("%d\t", i+1);
            printf("%d\t", profesores[i].codigo);
            printf("%s\n", profesores[i].nombre);
        }
    }

    if (!hayProfesores){
        printf("No hay profesores que mostrar.\n");
        getchar();
    }
}

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









