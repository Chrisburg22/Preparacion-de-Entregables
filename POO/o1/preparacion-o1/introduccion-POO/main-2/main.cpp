#include <iostream>

using namespace std;

class Persona{
public:
    string nombre;
    int edad;
    float estatura;
    char genero;
};

Persona persona;

void fijaNombre(string nombre){
     persona.nombre = nombre;
}
void fijarEdad(int edad){
    if( edad >= 0){
        persona.edad = edad;
    }
}

string dameNombre(){
    return persona.nombre;
}

int dameEdad(){
    return persona.edad;
}

int main(){
    
    cout << "Los datos de un personaje" << endl << endl;
   
   fijaNombre("Petter Parker");
   fijarEdad(22);
  
    cout << "Nombre: " << dameNombre() << endl;
    cout << "Edad: " << dameEdad() << endl;

}
