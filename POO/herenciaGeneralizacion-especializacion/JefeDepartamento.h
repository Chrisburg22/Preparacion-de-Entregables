#ifndef JEFEDEPARTAMENTO_H_INCLUDE
#define JEFEDEPARTAMENTO_H_INCLUDE

#include "Empleado.h"

using namespace std;

class JefeDepartamento:public Empleado{
        string departamento;
    public:
        JefeDepartamento(string nombre, string departamento):
            Empleado(nombre){
                if(!setDepartamento(departamento)){
                    this->departamento = "Sin departamento";
                }
            }
            bool setDepartamento(string d){
                departamento = d;
                return true;
            }
            string getDepartamento(){
                return departamento;
            }
};

#endif// JEFEDEPARTAMENTO_H_INCLUDE
