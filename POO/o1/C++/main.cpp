#include <iostream>

using namespace std;

class Alumno{

private:
//Propiedades
    string nombre;
    short edad;
    float estatura;
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
    void fijarEstatura(float estatura){
        this->estatura = estatura;
    }
// METODOS GETTERS    
    string dameNombre(){
        return nombre;
    }
    short dameEdad(){
        return edad;
    }
    float dameEstatura(){
        return estatura;
    }
};

int main(){
    Alumno alumno;
    
    string nombre;
    short edad;
    float estatura;

    cout << "Llenando datos de un alumno" << endl << endl;

    cout << "Dame su nombre: ";
    getline(cin, nombre);
    alumno.fijaNombre(nombre);

    cout << "Dame su edad: ";
    cin >> edad;
    alumno.fijarEdad(edad);

    cout << "Dame su estatura: ";
    cin >> estatura;
    cin.ignore();
    alumno.fijarEstatura(estatura);
  
    cout << endl << "Datos del alumno" << endl;
    cout << endl << "Nombre: " << alumno.dameNombre() << endl;
    cout << "Edad: " << alumno.dameEdad() << endl;
    cout << "Estatura: " << alumno.dameEstatura() << endl << endl;

}