#include <iostream>
#include "Materia.h"

#define MAX_MATERIAS 5
#define CANTIDAD_ACTIVIDADES 9
#define CANTIDAD_EXAMENES 3
enum {EVALUAR_MATERIA, GESTIONAR_MATERIAS, SALIR};
enum {AGREGAR,LISTAR,MOSTRAR,MODIFICAR,ELIMINAR,GUARDAR,REGRESAR};

Materia* materias[MAX_MATERIAS];
int contadorMaterias=0;

int menuPrincipal();
int menuMaterias();
void manejarOpcionesMaterias(int opcion);
void agregarMateria();
void pausar();

using namespace std;

int main(){
    int opcionInicio, opcionMaterias;
    bool salir=true;
    
    do{
        opcionInicio = menuPrincipal();
        switch (opcionInicio)
        {
        case EVALUAR_MATERIA:
            cout << "En construcció" << endl;
            pausar();
            break;
        case GESTIONAR_MATERIAS: 
            opcionMaterias = menuMaterias();
            manejarOpcionesMaterias(opcionMaterias);
            break;
        case SALIR:
            salir = false;
            break;
        default:
            break;
        }
    }while(salir);
    
    return 0;
}

int menuPrincipal(){
    int opcion;
    cout << "Evaluador de curso v1.1.2 - Estructura de datos II (EDA2) MJ 11a13"
         << endl << endl
         << "1. Evaluavión del curso" << endl
         << "2. Gestión de materias" << endl
         << "3. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}
int menuMaterias(){
    int opcion;
    cout << " 1. Agregar materias" << endl
         << " 2. Listar Materias" << endl 
         << " 3. Mostrar detalles de una materia" << endl
         << " 4. Modificar materia" << endl
         << " 5. Eliminar materia" << endl
         << " 6. Guardar meteria" << endl
         << " 7. Regresar al menu anterior" << endl
         << " Opción: ";
    cin >> opcion;
    return opcion;
}
void manejarOpcionesMaterias(int opcion){
    switch (opcion)
    {
    case AGREGAR:
        agregarMateria();
        break;
    case LISTAR:
        /* code */
        break;
    case MOSTRAR:
        /* code */
        break;
    case MODIFICAR:
        /* code */
        break;
    case ELIMINAR:
        /* code */
        break;
    case GUARDAR:
        /* code */
        break;
    case REGRESAR:
        /* code */
        break;
    default:
        break;
    }
}
void agregarMateria(){
    string nombre, acronimo, nombreProfesor, diasClase;
    int horaInicio, horaFin, cantidadTareas,i;
    int calificacionesActividades[CANTIDAD_ACTIVIDADES];
    int calificacionesExamenes[CANTIDAD_EXAMENES];
    cout << "Agregar materia" << endl << endl;
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Acronimo: ";
    getline(cin, acronimo);
    cout << "Nombre profesor";
    getline(cin, nombreProfesor);
    cout << "Dias de clase: ";
    getline(cin, diasClase);
    cout << "Hora inicio: ";
    cin >> horaInicio;
    cout << "Hora fin: ";
    cin >> horaFin;
    cout << "Tareas entregadas:";
    for(i=0;i<CANTIDAD_ACTIVIDADES; i++){
        cout << "Calificación de actividad #" << i+1 << ": ";
        cin >> calificacionesActividades[i];
    }
    for(i=0;i<CANTIDAD_EXAMENES; i++){
        cout << "Calificación del examen #" << i+1 << ": ";
        cin >> calificacionesExamenes[i];
    }

    if(contadorMaterias<MAX_MATERIAS){
        materias[contadorMaterias] = new Materia(nombre,acronimo,nombreProfesor,
                                                 diasClase,horaInicio,horaFin,cantidadTareas,
                                                 calificacionesActividades,calificacionesExamenes);
        contadorMaterias++;
        cout << "Materia agreada"  << endl;
        pausar();
    } else {
        cout << "No hay más espacio para agregar" << endl;
    }
}

void pausar(){
    cout << "Presiona enter para continuar" << endl;
    getchar();
}