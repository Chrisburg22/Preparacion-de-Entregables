#include <iostream>

using namespace std;

class Persona{

private:
//Propiedades
    string nombre;
    short edad;
public:
// METODOS SETTERS
    void fijaNombre(string nombre){
         this->nombre = nombre;
    }
    void fijarEdad(short edadx){
        if( edadx >= 0){
          edad = edadx; 
        }
    }
// METODOS GETTERS    
    string dameNombre(){
        return nombre;
    }
    short dameEdad(){
        return edad;
    }
};

int main(){
    Persona persona;
    
    string nombre;
    short edad;

    cout << "Los datos de un personaje" << endl << endl;

    cout << "Dame su nombre: ";
    getline(cin, nombre);
    persona.fijaNombre(nombre);

    cout << "Dame su edad: ";
    cin >> edad;
    persona.fijarEdad(edad);
  
    cout << "Nombre: " << persona.dameNombre() << endl;
    cout << "Edad: " << persona.dameEdad() << endl;

}
