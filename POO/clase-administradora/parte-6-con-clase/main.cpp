#include <iostream>
#include "Administrador.h"
#include "Circulo.h"

using namespace std;

int main(){
    Administrador* admin = new Administrador();

    if(admin->agregar(10,14,9)){
        cout << "Se agrego el circulo 1" << endl;
    } else{
        cout << "No se pudo agregar 1" << endl;
    }
    if(admin->agregar(20,14,9)){
        cout << "Se agrego el circulo 2" << endl;
    } else {
        cout << "No se pudo agregar 2" << endl;
    }
    if(admin->agregar(30,14,9)){
        cout << "Se agrego el circulo 3" << endl;
    } else {
        cout << "No se pudo agregar el circulo 3" << endl << endl;
    }
    cout << admin->dameInfoCirculo(1) << endl;
    cout << admin->dameInfoCirculo(2) << endl;
    cout << admin->dameInfoCirculo(3) << endl;    
    
    delete admin;
    
    return 0;
} 