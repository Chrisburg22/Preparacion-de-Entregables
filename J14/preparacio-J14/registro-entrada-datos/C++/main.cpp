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
    Persona personaje;
    
    cout << "Datos del personaje\n\n";
    cout << "Dame el nombre:";
    cin >> personaje.nombre;

    cout << "Dame la edad: ";
    cin >> personaje.edad;

    cout << "Dame la estatura: ";
    cin >> personaje.estatura;

   cout << "Dame el genero: ";
    cin >> personaje.genero;

    cout << "Nombre: " << personaje.nombre << endl;
    cout << "Edad: " << personaje.edad << endl;
    cout << "Estatura: " << personaje.estatura << endl;

    cout << "Genero: " << personaje.genero << endl;
    return 0;
}