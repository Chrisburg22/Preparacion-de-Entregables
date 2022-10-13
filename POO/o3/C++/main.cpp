#include <iostream>

using namespace std;

class Carrera{
    int idCarrera;
    string nombre;
public:
//Setters
    void fijarIdCarrera(int id){
        idCarrera = id;
    }
    void fijarNombre(string nombre){
        this->nombre = nombre;
    }
//Getters
    int dameIdNombre(){
        return idCarrera;
    }
    string dameNombre(){
        return nombre;
    }
};

class Alumno{

private:
//Propiedades
    string nombre;
    short edad;
    float estatura;
    int idCarrera;
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
    void fijarIdCarrera(int id){
        this->idCarrera = id;
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
    int dameIdCarrera(){
        return idCarrera;
    }
};

int main(){
    Alumno alumno;
    Carrera carreraAlumno;
    
    int id;
    string nombre;
    short edad;
    float estatura;

    cout << "**Registro de alumno UDG**" << endl << endl;

    cout << "-Nombre de la carrera: ";
    getline(cin,nombre);
    carreraAlumno.fijarNombre(nombre);

    cout << "-Id de la carrera: ";
    cin >> id;
    cin.ignore();
    carreraAlumno.fijarIdCarrera(id);
    alumno.fijarIdCarrera(id);

    cout << "-Nombre del alunmo: ";
    getline(cin, nombre);
    alumno.fijaNombre(nombre);

    cout << "-Edad del alumno: ";
    cin >> edad;
    alumno.fijarEdad(edad);

    cout << "-Estatura del alumno: ";
    cin >> estatura;
    cin.ignore();
    alumno.fijarEstatura(estatura);

    cout << endl << "**Datos Ragistrados**" << endl << endl
         << "Carrera" << endl 
         << " Nombre:     " << carreraAlumno.dameNombre() << endl
         << " Id Carrera: " << carreraAlumno.dameIdNombre() << endl << endl
         << "Alumno" << endl 
         << " Nombre:     " << alumno.dameNombre() << endl
         << " Edad:       " << alumno.dameEdad() << endl
         << " Estatura:   " << alumno.dameEstatura() << endl 
         << " Id carrera: " << alumno.dameIdCarrera() << endl << endl;

}