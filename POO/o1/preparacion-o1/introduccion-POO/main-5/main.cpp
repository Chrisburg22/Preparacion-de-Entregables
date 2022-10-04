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
    void fijarEdad(short e){
        if( e >= 0){
          edad = e; 
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
    Persona personaje;
    
    string nombre;
    short edad;

    cout << "Los datos de un personaje" << endl << endl;

    cout << "Dame su nombre: ";
    getline(cin, nombre);
    personaje.fijaNombre(nombre);

    cout << "Dame su edad: ";
    cin >> edad;
    personaje.fijarEdad(edad);
  
    cout << endl << "Nombre: " << personaje.dameNombre() << endl;
    cout << "Edad: " << personaje.dameEdad() << endl;

}
