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
   ~Administrador(){
      cout << "Eliminando Administrador" << endl;
      for(int i=0;i<MAX_CIRCULOS;i++){
         delete circulos[i];
      }
   }
   bool agregar(double radio, int borde, int fondo){
      bool agrego;
      if(cuentaCirculos<MAX_CIRCULOS){
         circulos[cuentaCirculos++] = new Circulo(radio,borde,fondo);
         agrego = true;
      } else {
         agrego = false;
      }
      return agrego;
   }

    string dameInfoCirculo(int posicion){
      stringstream s;
      if(posicion>=1 && posicion<=cuentaCirculos){
         s << "Propiedades del Ciculo c" << posicion << ":" << endl;
         s << circulos[posicion-1]->dameInfo();
      } else {
         s << "Posicion " << posicion << " fuera de rango" << endl;
      }
      return s.str();
    }
};

#endif
