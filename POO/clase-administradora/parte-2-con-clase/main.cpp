#include <iostream>
#include "Administrador.h"
#include "Circulo.h"

using namespace std;

int main(){
    Administrador admin;
    Circulo c1(10,14,9);
    Circulo c2(20,14,9);
    Circulo c3(30,14,9);

    cout << "Propiedades del circulo c11" << endl;
    c1.imprimeInfo();
    cout << "Propiedades del circulo c22" << endl;
    c2.imprimeInfo();
    cout << "Propiedades del circulo c33" << endl;
    c3.imprimeInfo();

    if(admin.agregar(&c1)){
        cout << "Se agrego el circulo c1" << endl;
    } else{
        cout << "No se pudo agregar c1" << endl;
    }
    if(admin.agregar(&c2)){
        cout << "Se agrego el circulo c2" << endl;
    } else {
        cout << "No se pudo agregar c2" << endl;
    }
    if(admin.agregar(&c3)){
        cout << "Se agrego el circulo c3" << endl;
    } else {
        cout << "No se pudo agregar el circulo c3" << endl;
    }
    admin.imprimeCirculo(1);
    admin.imprimeCirculo(2);
    admin.imprimeCirculo(3);    

    return 0;
}