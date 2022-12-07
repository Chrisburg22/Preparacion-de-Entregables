#ifndef ADMINISTRADOR_H_INCLUDE
#define ADMINISTRADOR_H_INCLUDE

#include <iostream>
#include "Circulo.h"

class Administrador {
private:
   Circulo* c1;
   Circulo* c2;
   int cuentaCirculos;
public:
   Administrador(){
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
};

#endif

/*

void inicializarPrograma(){
    cuentaCirculos = 0;
    c1 = NULL;
    c2 = NULL;
}




*/