#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
//Escaneo con Limite
#define TAMANIO_NOMBRE 30
#define TAMANIO_APELLIDO 40

struct Persona{
    char nombre[TAMANIO_NOMBRE], apellidos[TAMANIO_APELLIDO];
    int edad;
    float estatura;
    char genero;
};

int main(){
    Persona personaje;
    
    cout << "Agregando datos del personaje\n\n";
    cout << "Nombre(s):";
    cin.getline(personaje.nombre, TAMANIO_NOMBRE);
    
    cout << "Apellidos: ";
    cin.getline(personaje.apellidos, TAMANIO_APELLIDO);
    cout << "Edad: ";
    cin >> personaje.edad;

    cout << "Estatura: ";
    cin >> personaje.estatura;

    cout << "Genero: ";
    cin >> personaje.genero;

    cout << "\nNombre: " << personaje.nombre << " " << personaje.apellidos <<endl;
    cout << "Edad: " << personaje.edad << endl;
    cout << "Estatura: " << personaje.estatura << endl;

    cout << "Genero: " << personaje.genero << endl;
    return 0;
}