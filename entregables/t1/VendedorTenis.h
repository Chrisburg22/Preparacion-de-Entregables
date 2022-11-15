#ifndef VENDEDORTENIS_H_INCLUDE
#define VENDEDORTENIS_H_INCLUDE

#include "Vendedor.h"

using namespace std;

class VendedorTenis:public Vendedor{
private:
    string marcaTenis;
    float precioTenis;
    int tallaMax;
public:
    VendedorTenis(string marca, float precio, int talla):Vendedor(nombre,cantidad,ganancia);
    bool fijaMarca(string nombre);
    bool fijaPrecio(float precio);
    bool fijaTallaMax(int talla);
    string dameMarca(){return marcaTenis};
    float damnePrecio(){return precioTenis};
    int dameTallaMax(){return tallaMax};
};

VendedorTenis::VendedorTenis(string marca, float precio, int talla):
    Vendedor(nombre,cantidad,ganancia){
        if(!fijaMarca(marca)){
            this->marcaTenis = "No hay marca";
        }
        if(!fijaPrecio(precio)){
            this->precioTenis = 0;
        }
        if(!fijaTallaMax(talla)){
            this->tallaMax = 0;
        }
}

bool VendedorTenis::fijaMarca(string marca){
    this->marcaTenis = marca;
    return true;
}

bool VendedorTenis::fijaTallaMax(int talla){
    this->tallaMax = talla;
    return true;
}

bool VendedorTenis::fijaPrecio(float precio){
    this->precioTenis = precio;
    return true;
}










#endif //VENDEDORTENIS_H_INCLUDE