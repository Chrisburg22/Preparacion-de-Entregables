#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

#define MAX_NOMBRE 20
#define MAX_ALUMNOS 3
#define MAX_EXAMENES 3


enum {CAPTURAR_ALUMNO=1,MOSTRAR_ALUMNO,LISTAR_ALUMNOS,SALIR};
enum {VERDADERO,FALSO}booleano;

typedef struct {
    char nombre[MAX_NOMBRE];
    int codigo;
    float aportacion;
    int calificacionesExamenes[MAX_EXAMENES];
}Alumno;

Alumno alumnos[MAX_ALUMNOS];
int cuentaAlumnos;

int menu();
void capturarAlumno();
void mostrarAlumno();
void listarAlumnos();
void pausar();

int main(){
    int salir = FALSO;
    int opcion;
    do{
        opcion = menu();
        switch (opcion){
        case CAPTURAR_ALUMNO:
            capturarAlumno();
            pausar();
            break;
        case MOSTRAR_ALUMNO:
            mostrarAlumno();
            pausar();
        case LISTAR_ALUMNOS:
            listarAlumnos();
            pausar();
        case SALIR: 
            salir = VERDADERO;
            break;
        default:
            printf("Opcion no valida\n\n");
            break;
        }
    }while(salir);
    
}

int menu(){
    int opcion;
    system(CLEAR);
    printf("**CAPTURANDO ALUMNOS**\n\n");
    printf(" 1) Capturar alumno\n");
    printf(" 2) Mostrar alumno\n");
    printf(" 3) Listar alumnos\n\n");
    printf("Opc: ");
    scanf("%d",&opcion);
    return opcion;
}

void capturarAlumno(){
    if(cuentaAlumnos<MAX_ALUMNOS){
        int i;
        printf("Capturando alumno #%d\n\n",cuentaAlumnos+1);
        printf("Dame nombre: " );
        scanf("%s", alumnos[cuentaAlumnos].nombre);
        printf("Dame codigo: ");
        scanf("%d", &alumnos[cuentaAlumnos].codigo);
        printf("Dame la aportaci%cn: ", 162);
        scanf("%f", &alumnos[cuentaAlumnos].aportacion);
        for(i=0; i<MAX_EXAMENES; i++){
            printf("Calificacion %d%c examen: ", i+1, 248);
            scanf("%d", &alumnos[cuentaAlumnos].calificacionesExamenes[i]);
        }
        cuentaAlumnos++;
    } else {
        printf("Sin espacio para registros");
    }
}
void mostrarAlumno(){
    int codigo;
    int i, j;
    printf("Mostrar alumno\n\n");
    printf("Ingresa el codigo del alumno: ");
    scanf("%d",&codigo);
    for(i=0; i<MAX_ALUMNOS; i++){
        if(codigo==alumnos[i].codigo){
            printf("Nombre: %s\n", alumnos[i].nombre);
            printf("Codigo: %d\n", alumnos[i].codigo);
            printf("Aportacion: %.2f\n", alumnos[i].aportacion);
            for(j=0; j<MAX_EXAMENES ; i++){
                printf("Calificacion %d%c examen: %d\n", i+1, 248, alumnos[i].calificacionesExamenes[j]);
            }
        } else if(i==MAX_ALUMNOS,i++){
            printf("Alumno no registrado");
        } 
    }
}
void listarAlumnos(){
    int i,j;
    for(i=0; i<cuentaAlumnos; i++){
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Codigo: %d\n", alumnos[i].codigo);
        printf("Aportacion: %.2f\n", alumnos[i].aportacion);
        for(j=0; j<MAX_EXAMENES ; i++){
            printf("Calificacion %d%c examen: %d\n", i+1, 248, alumnos[i].calificacionesExamenes[j]);
        }
    }
}
void pausar(){
    printf("\nPresiona enter para continuar ...");
    getchar();
}