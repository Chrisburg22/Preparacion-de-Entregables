#ifndef EMPLEADO_H_INCLUDE
#define EMPLEADO_H_INCLUDE

using namespace std;

class Empleado{
    string nombre;
    public:
        Empleado(string nombre){
            if(!setNombre(nombre)){
               this->nombre="Staff";
            }
        }
        bool setNombre(string n){
            nombre = n;
            return true;
        }
        string getNombre(){
        return nombre;
        }
};

#endif // EMPLEADO_H

