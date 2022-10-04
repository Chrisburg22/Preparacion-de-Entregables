#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Persona{
    string nombre, apellidos;
    int edad;
    float estatura;
    char genero;
};
//Escaneo sin limite
int main(){
    Persona personaje;
    
    cout << "Agregando datos del personaje\n\n";
    cout << "Nombre(s):";
    getline(cin,personaje.nombre);
    
    cout << "Apellidos: ";
    getline(cin, personaje.apellidos);
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