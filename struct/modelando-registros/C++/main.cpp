#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Persona{
    string nombre;
    int edad;
    float estatura;
    char genero;
};

int main(){
    Persona persona1,persona2;
    cout << "Datos de personajes\n\n";

    persona1.nombre="Christian Ramos'";
    persona1.edad= 23;
    persona1.estatura= 1.78;
    persona1.genero= 'M';
    
    persona2.nombre="Claudia Gomez";
    persona2.edad= 28;
    persona2.estatura= 1.70;
    persona2.genero= 'F';

    cout << "Nombre: " << persona1.nombre << endl;
    cout << "Edad: " << persona1.edad << endl;
    cout << "Estatura: " << persona1.estatura << endl;
    cout << "Genero: " << persona1.genero << endl;

    cout << "Nombre: " << persona2.nombre << endl;
    cout << "Edad: " << persona2.edad << endl;
    cout << "Estatura: " << persona2.estatura << endl;
    cout << "Genero: " << persona2.genero << endl;


    return 0;
}