#include <iostream>
#include "Vendedor.h"
#include "VendedorAutos.h"
#include "VendedorTenis.h"

using namespace std;

void llenarDatosVendedor(Vendedor* vendedor);
//void llenarDatosVendedorAutos();
//void llenarDatosVendedorTenis();

Vendedor* vendedorGeneral;
VendedorAutos* vendedorTesla;
VendedorTenis* vendedotNike;

using namespace std;

int main(){
    llenarDatosVendedor(vendedorGeneral);
    return 0;
}

void llenarDatosVendedor(Vendedor* vendedor){
    string nombre;
    int cantidad;
    float ganancias;
    cout << "Nombre del vendedor: ";
    getline(cin, nombre);
    cin.ignore();
    cout << "Cantidad productos vendidos p/semana: ";
    cin >> cantidad;
    cout << "Ganacia semanal: ";
    cin >> ganancias;
    vendedor = new Vendedor(nombre,cantidad,ganancias);
}