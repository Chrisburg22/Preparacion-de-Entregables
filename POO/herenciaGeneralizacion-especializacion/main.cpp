//Herencia generalizacion y especializacion

#include <iostream>

#include "Empleado.h"
#include "Profesor.h"
#include "JefeDepartamento.h"

using namespace std;

int main()
{
    Empleado* luis = new Empleado("Luis");
    Profesor* alberto = new Profesor("Alberto", 221802441);
    JefeDepartamento* carlos = new JefeDepartamento("Carlos", "Informatica");

//Metodos Gerneralizados de la clase Empleado, estan siendo utilizadas gracias a la herencia
    cout << "Nombre empleado: " << luis->getNombre() << endl
         << "Nombre profesor: " << alberto->getNombre() << endl
         << "Nombre del Jefe de departamento: " << carlos->getNombre() << endl;

//Metodos de especialización de cada clase.
   cout << "Codigo del profesor: " << alberto->getCodigo() << endl
        << "Nombre del Departamento: " << carlos->getDepartamento();

    return 0;
}