/**
 * POO
 * NickName = DosTres
 * Ejercicio o3
 * Tiempo = 00:20
 * 
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Carrera{
    int idCarrera;
    string nombre;
public:
//Setters
    void fijarIdCarrera(int id){
        idCarrera = id;
    }
    void fijarNombre(string n){
        nombre = n;
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
    void fijaNombre(string n){
         nombre = n;
    }
    void fijarEdad(short e){
        if( e >= 0){
          edad = e; 
        }
    }
    void fijarEstatura(float e){
        if(estatura>=0){
            estatura = e;
        }
    }
    void fijarIdCarrera(int id){
        idCarrera = id;
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

void pausar();

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
    
    cout << "-Nombre del alunmo: ";
    getline(cin, nombre);

    cout << "-Edad del alumno: ";
    cin >> edad;

    cout << "-Estatura del alumno: ";
    cin >> estatura;
    cin.ignore();

    carreraAlumno.fijarIdCarrera(id);
    alumno.fijarIdCarrera(id);
    alumno.fijarEstatura(estatura);
    alumno.fijaNombre(nombre);
    alumno.fijarEdad(edad);

    cout << endl << "**Datos Ragistrados**" << endl << endl
         << "Carrera" << endl 
         << " Nombre:     " << carreraAlumno.dameNombre() << endl
         << " Id Carrera: " << carreraAlumno.dameIdNombre() << endl << endl
         << "Alumno" << endl 
         << " Nombre:     " << alumno.dameNombre() << endl
         << " Edad:       " << alumno.dameEdad() << endl
         << fixed << setprecision(2) << " Estatura:   " << alumno.dameEstatura() << endl 
         << " Id carrera: " << alumno.dameIdCarrera() << endl << endl;
    pausar();

}

void pausar(){
    cout << "Presione enter para continuar . . ." << endl;
    cin.ignore();
}