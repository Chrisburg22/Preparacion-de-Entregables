#ifndef BARCO_H_INCLUDED
#define BARCO_H_INCLUDED

#include <iostream>
#include "Vehiculo.h"

using namespace std;

class Barco : public Vehiculo{
private:
    string tipoPropulsores;
public:
    void calcularEficienciaGasolina(){
        cout << "Calculando eficiencia en un Barco" << endl;
    }
    bool setTipoPropulsores(string propulsor){
        tipoPropulsores = propulsor;
        return true;
    }
};



#endif