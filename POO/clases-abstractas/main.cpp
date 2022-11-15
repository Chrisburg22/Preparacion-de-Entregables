#include <iostream>
#include "Avion.h"
#include "Barco.h"
#include "Automovil.h"

using namespace std;

int main(){
    Avion* f12 = new Avion();
    Automovil* ferrari = new Automovil();
    Barco* titanic = new Barco();

    f12->calcularEficienciaGasolina();
    ferrari->calcularEficienciaGasolina();
    titanic->calcularEficienciaGasolina();

    delete f12;
    delete ferrari;
    delete titanic;
}