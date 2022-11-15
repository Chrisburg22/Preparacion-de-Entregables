#ifndef VEHICULO_H_INCLUDE
#define VEHICULO_H_INCLUDE

using namespace std;

class Vehiculo{
private:
    string marca;
    string nombre;
    string tipoMotor;
    int numeroPuertas;
    int numeroVentanas;
public:
    virtual void calcularEficienciaGasolina() = 0;
    virtual ~Vehiculo(){};
    bool fijarTipoMotor(string motor){
        tipoMotor = motor;
        return true;
    }
    string dameTipoMotor(){
        return tipoMotor;
    }
};

#endif // VEHICULO_H_INCLUDED




        