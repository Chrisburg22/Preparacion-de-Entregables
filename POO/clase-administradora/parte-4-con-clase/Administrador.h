#ifndef ADMINISTRADOR_H_INCLUDE
#define ADMINISTRADOR_H_INCLUDE

#include <iostream>
#include <sstream>
#include "Circulo.h"

#define MAX_CIRCULOS 2

class Administrador {
private:
   Circulo* circulos[MAX_CIRCULOS];
   int cuentaCirculos;
public:
   Administrador(){
      cuentaCirculos = 0;
      for(int i=0;i<MAX_CIRCULOS;i++){
         circulos[i] = NULL;
      }
   }
   bool agregar(Circulo* c){
      bool agrego;
      if(cuentaCirculos<MAX_CIRCULOS){
         circulos[cuentaCirculos++] = c;
         agrego = true;
      } else {
         agrego = false;
      }
      return agrego;
   }

    string dameInfoCirculo(int numCirculo){
      stringstream s;
      if(numCirculo>=1 && numCirculo<=cuentaCirculos){
         s << "Propiedades del Ciculo c" << numCirculo << ":" << endl;
         s << circulos[numCirculo-1]->dameInfo();
      } else {
         s << "Posicion " << numCirculo << " fuera de rango" << endl;
      }
      return s.str();
    }
};

#endif
