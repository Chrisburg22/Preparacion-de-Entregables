#ifndef CIRCULO_H_INCLUDE
#define CIRCULO_H_INCLUDE

#include <iostream>

using namespace std;

class Circulo {
    private:
      double radio;
      int colorBorde;
      int colorFondo;
    public:
      static constexpr double PI=3.1416;
      Circulo(double radio, int colorBorde, int colorFondo){
        if(!fijaRadio(radio)){
            this->radio = 10;
        }
        if(!fijaColorBorde(colorBorde)){
            this->colorBorde=14;
        }
        if(!fijaColorFondo(colorFondo)){
            this->colorFondo=10;
        }
      }
      bool fijaRadio(double r){
        if(r>0){
            radio = r;
            return true;
        } else {
            return false;
        }
      }
      bool fijaColorBorde(int b){
        if(b>0){
            colorBorde = b;
            return true;
        } else {
            return false;
        }
      }
      bool fijaColorFondo(int f){
        if(f>0){
            colorFondo = f;
            return true;
        } else {
            return false;
        }
      }
      double dameRadio(){
        return radio;
      }
      int dameColorBorde(){
        return colorBorde;
      }
      int dameColorFondo(){
        return colorFondo;
      }
      int dameArea(){
        return PI*radio*radio;
      }
      void dibujar(){
        cout << "Dibujando el circulo" << endl;
      }
      void trasladar(){
        cout << "Transalando el circulo" << endl;
      }
      void redimensionar(int porcentaje){
        cout << "Redimencionando en " << porcentaje << "%" << endl;
      }
      void imprimeInfo(){
        cout << "Radio:" << radio 
             << "  Color Borde:" << colorBorde 
             << "  Color Fondo:" << colorFondo << endl;
      }
};


#endif //CIRCULO_H_INCLUDE