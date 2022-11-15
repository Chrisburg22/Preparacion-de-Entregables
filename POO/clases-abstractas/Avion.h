#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include <iostream>
#include "Vehiculo.h"

using namespace std;

class Avion : public Vehiculo{
private:
    int numeroLlantas;
    int numeroVelocidades;
public:
    void calcularEficienciaGasolina(){
        cout << "Calculando eficiencia de un Avion" << endl;
    }
};

#endif //AVION_H_INCLUDED