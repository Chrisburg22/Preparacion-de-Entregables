#ifndef VENDEDORAUTOS_H_INCLUDE
#define VENDEDORAUTOS_H_INCLUDE

#include "Vendedor.h"

using namespace std;

class VendedorAutos:public Vendedor{
private:
    string nombreEmpresa;
    string modeloAuto;
    float precioAuto;
public:
    VendedorAutos(string nombreEmpresa, string modelo, float precio):
    Vendedor(nombre,cantidad,ganancia){
        if(!fijaEmpresa(nombreEmpresa)){
            this->nombreEmpresa = "Sin empresa";
        }
        if(!fijaModelo(modelo)){
            this->modeloAuto = "Sin modelo";
        }
        if(!fijaPrecio(precio)){
            this->precioAuto = 0;
        }
    }
    bool fijaEmpresa(string nombre){
    this->nombreEmpresa = nombre;
    return true;
    }
    bool fijaModelo(string modelo) {
    this->modeloAuto = modelo;
    return true;
    }
    bool fijaPrecio(float precio){
    this->precioAuto = precio;
    return true;
    }
    string dameEmpresa(){ return nombreEmpresa; };
    string dameModelo(){ return modeloAuto; };
    float damnePrecio(){ return precioAuto; };
};

#endif //VENDEDORAUTOS_H_INCLUDE