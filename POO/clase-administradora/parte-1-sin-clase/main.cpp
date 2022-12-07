#include <iostream>
#include "Circulo.h"

using namespace std;

Circulo* c1;
Circulo* c2;
int cuentaCirculos;

void inicializarPrograma(){
    cuentaCirculos = 0;
    c1 = NULL;
    c2 = NULL;
}

bool agregar(Circulo* c){
    bool agrego;
    switch(cuentaCirculos){
        case 0:
           c1 = c;
           agrego = true;
           cuentaCirculos++;
           break;
        case 1:
           c2 = c;
           agrego = true;
           cuentaCirculos++;
           break;
        default:
           agrego = false;
    }
    return agrego;
}

void imprimeCirculo(int cual){
    switch(cual){
        case 1:
          cout << "Propiedades del circulo 1" << endl;
          c1->imprimeInfo();
          break;
        case 2:
          cout << "Propiedades del circulo 2" << endl;
          c2->imprimeInfo();
          break;
        default:
          cout << "\nNumero " << cual << " fuera de rango" << endl;
    }
}

 int main() {
    Circulo c11(10,14,9);
    Circulo c22(20,14,9);
    Circulo c33(30,14,9);

    inicializarPrograma();

    cout << "Propiedades del circulo c11" << endl;
    c11.imprimeInfo();
    cout << "Propiedades del circulo c22" << endl;
    c22.imprimeInfo();
    cout << "Propiedades del circulo c33" << endl;
    c33.imprimeInfo();

    if(agregar(&c11)){
        cout << "Se agrego c11" << endl;
    } else {
        cout << "No se pudo agregar c11" << endl;
    }

    if(agregar(&c22)){
        cout << "Se agrego c22" << endl;
    } else {
        cout << "No se pudo agregar c22" << endl;
    }

    if(agregar(&c33)){
        cout << "Se agrego c33" << endl;
    } else {
        cout << "No se pudo agregar c33" << endl;
    }

    imprimeCirculo(1);
    imprimeCirculo(2);
    imprimeCirculo(3);

    return 0;
 }