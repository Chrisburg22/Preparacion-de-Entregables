#include <iostream>

using namespace std;

class Persona{
public:
    string nombre;
    int edad;
    float estatura;
    char genero;
};


int main(){
    Persona persona;

    cout << "Los datos de un personaje" << endl << endl;
    persona.nombre = "Petter Parker";
    persona.edad = 22;
    persona.estatura = 1.78;
    persona.genero = 'M';

    cout << "Nombre: " << persona.nombre << endl;
    cout << "Edad: " << persona.edad << endl;
    cout << "Estatura: " << persona.estatura << endl;
    cout << "Genero: " << persona.genero << endl;
    
}
