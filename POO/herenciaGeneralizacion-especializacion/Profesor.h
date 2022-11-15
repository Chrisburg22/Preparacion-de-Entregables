#ifndef PROFESOR_H_INCLUDE
#define PROFESOR_H_INCLUDE

#include "Empleado.h"

using namespace std;
 
class Profesor:public Empleado{
    int codigo;
public:
    Profesor(string nombre, int codigo):
        Empleado(nombre){
            if(!setCodigo(codigo)){
                this->codigo = codigo;
            }
    }
    bool setCodigo(int c){
        codigo = c;
        return true;
    }
    int getCodigo(){
        return codigo;
    }
};

#endif