#ifndef VENDEDOR_H_INCLUDE  
#define VENDEDOR_H_INCLUDE

using namespace std;

class Vendedor{
private:
    string nombre;
    int cantidadVentasSemanal;
    float gananciaSemanal;
public:
    Vendedor(string nombre, int cantidad, float ganancia){
         if(!fijaNombre(nombre)){
             this->nombre = "Sin nombre de Vendedor";
         }
         if(!fijaCantidadVentas(cantidad)){
             this->cantidadVentasSemanal = 0;
         }
         if(!fijaGanaciaSemanal(ganancia)){
             this->gananciaSemanal = 0;
         }
    }     
    bool fijaNombre(string nombre){
        this->nombre = nombre;
        return true;
    }
    bool fijaCantidadVentas(int cantidad){
        this->cantidadVentasSemanal = cantidad;
        return true;
    }
    bool fijaGanaciaSemanal(float ganancia){
        this->gananciaSemanal = ganancia;
        return true;
    }
    string dameNombre(){return nombre;};
    int dameCantidadVentas(){return cantidadVentasSemanal;};
    float dameGananciaSemanal(){return gananciaSemanal;};
};

#endif //VENDEDOR_H_INCLUDE