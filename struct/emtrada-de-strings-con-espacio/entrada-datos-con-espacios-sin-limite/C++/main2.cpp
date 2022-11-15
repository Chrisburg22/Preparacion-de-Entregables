//Mejorando en main 
//Agregando de registros y programacion modular
#include <iostream>

#define MAX_PERSONAS 10;

enum {ALTA_PERSONA=1,BAJA_PERSONA,MOSTRAR_PERSONA,LISTAR_PERSONAS,MODIFICAR_PERSONA,ELIMINAR_PERSONA,SALIR};


struct  Persona{
    string nombre;
    int edad;
    float estatura;
    char genero;
};

Persona personas[MAX_PERSONAS];

using namespace std;
