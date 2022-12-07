#include <iostream>
#include "Administrador.h"
#include "Circulo.h"

using namespace std;

int main(){
    Administrador admin;
    Circulo* c1 = new Circulo(10,14,9);
    Circulo* c2 = new Circulo(20,14,9);
    Circulo* c3 = new Circulo(30,14,9);

    cout << "Propiedades del circulo c1" << endl;
    cout << c1->dameInfo() << endl;
    cout << "Propiedades del circulo c2" << endl;
    cout << c2->dameInfo() << endl;
    cout << "Propiedades del circulo c3" << endl;
    cout << c3->dameInfo() << endl;

    if(admin.agregar(c1)){
        cout << "Se agrego el circulo c1" << endl;
    } else{
        cout << "No se pudo agregar c1" << endl;
    }
    if(admin.agregar(c2)){
        cout << "Se agrego el circulo c2" << endl;
    } else {
        cout << "No se pudo agregar c2" << endl;
    }
    if(admin.agregar(c3)){
        cout << "Se agrego el circulo c3" << endl;
    } else {
        cout << "No se pudo agregar el circulo c3" << endl << endl;
    }
    cout << admin.dameInfoCirculo(1) << endl;
    cout << admin.dameInfoCirculo(2) << endl;
    cout << admin.dameInfoCirculo(3) << endl;    

    delete c1;
    delete c2;   
    delete c3;   
         
    return 0;
} 