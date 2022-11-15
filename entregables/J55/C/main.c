/**
 * DosTres
 * Tiempo=08:00
*/
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

#define MAX_MATERIAS 15
#define MAX_REQUISITOS 3
#define TAMANIO_NOMBRE 50
#define TAMANIO_REQUISITO 50
#define TAMANIO_CLAVE 5
#define CARACTERES_POR_FILA 80

typedef enum {FALSO, VERDADERO} booleano;
typedef enum {ALTA=1, BAJA, CONSULTA, ACTUALIZACION, LISTADO, BUSQUEDA, SALIR} opcionMenu;

typedef struct {
    char requisito[TAMANIO_REQUISITO+2];
    booleano existe;
}Requisitos;

typedef struct{
    char clave[TAMANIO_CLAVE+2];
    char nombre[TAMANIO_NOMBRE+2];
    Requisitos prerrequisitos[MAX_REQUISITOS];
    booleano libre;
}Materia;

Materia materias[MAX_MATERIAS];

void pausar();
void limpiarRegistroMaterias(int indice);
void inicializaPrograma();
void modifidicarRegistroMaterias(int indice);
booleano elRegistrosMateriasTieneDatos(int indice);
void mostrarMateria();
void darAltaMateria();
void darBajaMateria();
void consultarMaterias();
void actualizarDatosMateria();
void buscarMateria();
void listarMaterias();
int elegirOpcionMenuMaterias();
void crearBaseDatos();

int main (){
    booleano continuarPrograma=VERDADERO;
    inicializaPrograma(); // Se limpia la memoria RAM
    crearBaseDatos();
    do{
        switch(elegirOpcionMenuMaterias()){
            case ALTA: darAltaMateria(); break;
            case BAJA: darBajaMateria();break;
            case CONSULTA: consultarMaterias();  break;
            case ACTUALIZACION: actualizarDatosMateria(); break;
            case LISTADO: listarMaterias(); break;
            case BUSQUEDA: buscarMateria(); break;
            case SALIR: continuarPrograma = FALSO; break;
            default: printf("Opcion no valida\n");
        }
        continuarPrograma ? pausar() : 0;

    } while(continuarPrograma);
    return 0;
}

//Esta funcion limpiara la memoria RAM
void limpiarRegistroMaterias(int indice){
    int i=indice, j;
    strcpy(materias[i].clave, "");
    strcpy(materias[i].nombre, ""); // A excepcion de estas dos lineas de codigo
    for(j=0; j<3 ; j++){
        strcpy(materias[i].prerrequisitos[j].requisito, "");
        materias[i].prerrequisitos[j].existe = FALSO;
    }
    materias[i].libre = VERDADERO;
}

void inicializaPrograma(){
    int i;
    for(i=0; i<MAX_MATERIAS; i++){
        limpiarRegistroMaterias(i);
    }
}

void modifidicarRegistroMaterias(int indice){
    int i = indice;
    int prerrequisitos, j;
    
    printf("Provee datos para el registro %d.\n", i+1);
    printf("Clave: ");
    fgets(materias[i].clave, TAMANIO_CLAVE+2, stdin);
    materias[i].clave[strlen(materias[i].clave) -1 ] = '\0';
    
    printf("Nombre: ");
    fgets(materias[i].nombre, TAMANIO_NOMBRE+2, stdin);
    materias[i].nombre[strlen(materias[i].nombre) -1 ] = '\0'; //Elimina el salto de linea que existe una casilla despues de la recibida    
    
    printf("Cuantos prerequisitos tiene la materia (1 a %d)? ", MAX_REQUISITOS);
    scanf("%d", &prerrequisitos);

    for (j=0; j<prerrequisitos; j++){
        
        getchar();
        printf("Prerrequisito #%d: ", j+1);
        fgets(materias[i].prerrequisitos[j].requisito, TAMANIO_REQUISITO+2, stdin);
        materias[i].prerrequisitos[j].requisito[strlen(materias[i].prerrequisitos[j].requisito) -1 ] = '\0'; 
        materias[i].prerrequisitos[j].existe = VERDADERO;
        fflush(stdin);
        
    }
    materias[i].libre = FALSO;
}

booleano elRegistrosMateriasTieneDatos(int indice){
    booleano tieneDatos = FALSO;
    
    if( (0<=indice)&&(indice<MAX_MATERIAS)){
        
        if(materias[indice].libre){
            printf("Registro sin datos\n\n");
        } else {
            tieneDatos = VERDADERO;
        }
    
    } else {
        printf("No esxiste ese indice de registo\n\n");
    }
    getchar();
    return tieneDatos;
}

void mostrarMateria(int indice){
    int i= indice;
    char rellenaVacio= ' ';
    int j=0;

    if(!materias[i].libre){
        if( strlen(materias[i].prerrequisitos[j].requisito) <= 5 ){
                printf("%5s | %-37s | %s\n", materias[i].clave, materias[i].nombre, materias[i].prerrequisitos[j++].requisito);
            } else {
                printf("%5s | %-37s | (%s)\n", materias[i].clave, materias[i].nombre, materias[i].prerrequisitos[j++].requisito);
            }  
        do{
    
            if(materias[i].prerrequisitos[j].existe){
                if( strlen(materias[i].prerrequisitos[j].requisito) <= 5 ){
                    printf("%5c | %-37c | %s\n", rellenaVacio,rellenaVacio , materias[i].prerrequisitos[j].requisito);
                } else {
                    printf("%5c | %-37c | (%s)\n", rellenaVacio,rellenaVacio , materias[i].prerrequisitos[j].requisito);
                }
            }
            j++;
        }while(j<MAX_REQUISITOS);
        printf("---------------------------------------------------------------------\n");
    }
    
}

void darAltaMateria(){
    booleano hayEspacioLibre;
    int i;
    
    printf("ALTA DE NUEVA MATERIA\n\n");
    hayEspacioLibre = FALSO;

    for(i=0 ; i<MAX_MATERIAS; i++){
        if(materias[i].libre){
            hayEspacioLibre = VERDADERO;
            break;
        } //else seguir Buscando un espaciolibre

    }

    if(hayEspacioLibre){
        modifidicarRegistroMaterias(i);
    } else {
        printf("No hay mas espacios para capturar");
    }
}

void darBajaMateria(){
    int i, j;
    char opcion;
    printf("BAJA DE UNA MATERIA\n\n");
    printf("Indica el numero de registo a consultar (1 a %d): ", MAX_MATERIAS);
    scanf("%d", &i);
    i--;

    printf("\n");

    if(elRegistrosMateriasTieneDatos(i)){
        mostrarMateria(i);
        printf("\nEstas seguro de que deseas eliminar el registro (s/n)?");
        scanf("%c",&opcion);

        if(opcion=='s' || opcion == 'S'){
            
            do{    
                if(elRegistrosMateriasTieneDatos(i+1)){
                    strcpy(materias[i].clave, materias[i+1].clave);
                    strcpy(materias[i].nombre, materias[i+1].nombre);
                    for(j=0; j<MAX_REQUISITOS ; j++){
                        if(materias[i].prerrequisitos[j].existe){
                            strcpy(materias[i].prerrequisitos[j].requisito, materias[i+1].prerrequisitos[j].requisito);
                        }
                    }    
                }
                limpiarRegistroMaterias(i+1);
            }while(!materias[i++].libre);
            printf("Registro eliminado\n");
        } else {
            printf("Registro consevado!\n");
            getchar();
        }
    } 
}

void consultarMaterias(){
    int i;
    printf("CONSULTA DE UNA MATERIA\n\n");
    printf("Indica el numero del registo a consultar (1 a %d): ", MAX_MATERIAS);
    scanf("%d", &i);
    i--;

    printf("\n");

    if(elRegistrosMateriasTieneDatos(i)){
        printf("---------------------------------------------------------------------\n");
        printf("Clave | Nombre                                | Prerrequisito(s)\n");
        printf("---------------------------------------------------------------------\n");
        mostrarMateria(i);
    }
}

void actualizarDatosMateria(){
    int i;
    
    printf("ACTUALIZACION DE DATOS DE UNA MATERIA\n\n");
    printf("Indica el numero de registro a modificar: ");
    scanf("%d", &i);
    getchar();

    i--;
    
    if(elRegistrosMateriasTieneDatos(i)){
        mostrarMateria(i);
        modifidicarRegistroMaterias(i);
    }

}

void buscarMateria(){
    char buscado[TAMANIO_NOMBRE+2];
    char* patron;
    int i, cantNombresEncontrados;
    
    printf("BUSQUEDA DE PROFESOR\n\n");
    printf("Indica el nombre del profesor: ");
    getchar();
    fgets(buscado, TAMANIO_NOMBRE+1 , stdin);
    buscado[strlen(buscado)-1] = '\0';

    cantNombresEncontrados = 0;
    printf("\n");
    for ( i=0; i<MAX_MATERIAS ; i++){
        patron = strstr( materias[i].nombre, buscado );
        if(patron!=NULL){
            mostrarMateria(i);
            printf("\n");
            cantNombresEncontrados ++;
        }
    }
    if(cantNombresEncontrados){
        printf("Se encontraron %d registro(s) con la palabra buscada\n", cantNombresEncontrados);
    } else {
        printf("No se encontro algun registro");
    }
}

void listarMaterias(){
    booleano hayMaterias = FALSO;
    int i;

    printf("---------------------------------------------------------------------\n");
    printf("Clave | Nombre                                | Prerrequisito(s)\n");
    printf("---------------------------------------------------------------------\n");
    
    for(i=0; i<MAX_MATERIAS; i++){
        if(!materias[i].libre){
            hayMaterias = VERDADERO;
            mostrarMateria(i);
        }
    }

    if (!hayMaterias){
        printf("No hay profesores que mostrar.\n");
    }

}

int elegirOpcionMenuMaterias(){
    int opcion;
    system(CLEAR);
    //imprimirCentrado("");
    printf("\n");
    printf("1. Alta de un nueva materia\n");
    printf("2. Baja de una materia\n");
    printf("3. Consulta de una materia\n");
    printf("4. Cambio de datos de una materia\n");
    printf("5. Listado de materias\n");
    printf("6. Busqueda de una materia\n");
    printf("7. Salir\n");
    printf("Opción: ");
    scanf("%d", &opcion);
    if(opcion>=ALTA && opcion<=BUSQUEDA){
        system(CLEAR);
    }
    getchar();
    return opcion;
}

void pausar(){
    printf("Presione enter para continuar . . .");
    getchar();
}

void crearBaseDatos(){
    //Creando datos Harcodeados de las materias creadar en el archivo del ejericio
   //Primer Registro
    int i, j;
    i=0;
    j=0;
    strcpy(materias[i].clave, "I5247");
    strcpy(materias[i].nombre, "Logica Matematica");
    strcpy(materias[i].prerrequisitos[j].requisito, "Espaniol");
    materias[i].prerrequisitos[j++].existe = VERDADERO;
    strcpy(materias[i].prerrequisitos[j].requisito, "Algebra");
    materias[i].prerrequisitos[j].existe = VERDADERO;
    materias[i++].libre = FALSO;
    //Segundo Registro
    j=0;
    strcpy(materias[i].clave, "IL352");
    strcpy(materias[i].nombre, "Programacion Estructurada");
    strcpy(materias[i].prerrequisitos[j].requisito, "I5247");
    materias[i].prerrequisitos[j].existe = VERDADERO;
    materias[i++].libre = FALSO;
    //Tercer Registro
    strcpy(materias[i].clave, "IL345");
    strcpy(materias[i].nombre, "Matematicas Discretas");
    strcpy(materias[i].prerrequisitos[j].requisito, "Aritmetica");
    materias[i].prerrequisitos[j++].existe = VERDADERO;
    strcpy(materias[i].prerrequisitos[j].requisito, "Trigonometria");
    materias[i].prerrequisitos[j++].existe = VERDADERO;
    strcpy(materias[i].prerrequisitos[j].requisito, "I5247");
    materias[i].prerrequisitos[j].existe = VERDADERO;
    materias[i++].libre = FALSO;
    //Cuarto Registro
    j=0;
    strcpy(materias[i].clave, "I5289");
    strcpy(materias[i].nombre, "Programacion Orientada a Objetos");
    strcpy(materias[i].prerrequisitos[j].requisito, "IL352");
    materias[i].prerrequisitos[j].existe = VERDADERO;
    materias[i++].libre = FALSO;
    //Quinto Registro
    strcpy(materias[i].clave, "I5886");
    strcpy(materias[i].nombre, "Estructuras de Datos");
    strcpy(materias[i].prerrequisitos[j].requisito, "I5289");
    materias[i].prerrequisitos[j++].existe = VERDADERO;
    strcpy(materias[i].prerrequisitos[j].requisito, "IL345");
    materias[i].prerrequisitos[j].existe = VERDADERO;
    materias[i++].libre = FALSO;
    //Sexto
    j=0;
    strcpy(materias[i].clave, "I5890");
    strcpy(materias[i].nombre, "Bases de Datos");
    strcpy(materias[i].prerrequisitos[j].requisito, "I5886");
    materias[i].prerrequisitos[j].existe = VERDADERO;
    materias[i++].libre = FALSO;
    //Septimo
    strcpy(materias[i].clave, "I5898");
    strcpy(materias[i].nombre, "Ingenieria de Software I");
    strcpy(materias[i].prerrequisitos[j].requisito, "I5890");
    materias[i].prerrequisitos[j].existe = VERDADERO;
    materias[i++].libre = FALSO;
    //Octavo
    strcpy(materias[i].clave, "I5909");
    strcpy(materias[i].nombre, "Programacion para Internet");
    strcpy(materias[i].prerrequisitos[j].requisito, "I5890");
    materias[i].prerrequisitos[j].existe = VERDADERO;
    materias[i++].libre = FALSO;
    //Noveno
    strcpy(materias[i].clave, "I7029");
    strcpy(materias[i].nombre, "Sistemas Operativos");
    strcpy(materias[i].prerrequisitos[j].requisito, "I5886");
    materias[i].prerrequisitos[j].existe = VERDADERO;
    materias[i++].libre = FALSO;
    //Decimo
    strcpy(materias[i].clave, "I5886");
    strcpy(materias[i].nombre, "Estructuras de Datos");
    strcpy(materias[i].prerrequisitos[j].requisito, "I5289");
    materias[i].prerrequisitos[j++].existe = VERDADERO;
    strcpy(materias[i].prerrequisitos[j].requisito, "IL345");
    materias[i].prerrequisitos[j].existe = VERDADERO;
    materias[i++].libre = FALSO;
}







