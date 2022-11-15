#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED

#include <iostream>
#include "Vehiculo.h"

using namespace std;

class Automovil : public Vehiculo{
private:
    int numeroLlantas;
public:
    void calcularEficienciaGasolina(){ 
        cout << "Calculando la eficiencia del motor de un Automovil" << endl;
    }
    void fijarNumeroLlantas(int cantidad){
        numeroLlantas = cantidad;
    }
};

#endif //AUTOMOVIL_H_INCLUDED