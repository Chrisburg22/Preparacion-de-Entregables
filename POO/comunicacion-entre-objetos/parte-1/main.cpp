#include <iostream>

using namespace std;

#define C_2 2

class Circulo{
        static constexpr float PI = 3.1416;
        double radio;
        int colorBorde;
        int colorFondo;
    public:
        void setRadio(double radio){
            this->radio = radio;
        }
        void setColorBorde(int borde ){
            this->colorBorde = borde;
        }
        void setColorFondo(int fondo ){
            this->colorBorde = fondo;
        }
        double getRadio(){
            return radio;
        }
        int getColorBorde(){
            return colorBorde;
        }
        int getColorFondo(){
            return colorFondo;
        }
        double getArea(){
            return PI*radio*radio;
        }
        bool esIgual(Circulo* c){
            if(this->radio >= c->getRadio() && this->radio <= c->getRadio() 
               // this->radio==c->getRadio En esta situacion estamos comparando los valores de tipo flotante pero no es buena practica hacerlo así
               && this->colorBorde == c->getColorBorde()
               && this->colorFondo == c->getColorFondo() ){
                return true;
            } else {
                return false;
            }
            /**
             * Estas son diferentes versiones del mismo codigo de arriba, pero utilizando la programación funcional,
            */
            //return (this->radio >= c->getRadio() && this->radio <= c->getRadio() 
            //   && this->colorBorde == c->getColorBorde()
            //   && this->colorFondo == c->getColorFondo())? true: false;
          //
            //return this->radio >= c->getRadio() && this->radio <= c->getRadio() 
            //   && this->colorBorde == c->getColorBorde()
            //   && this->colorFondo == c->getColorFondo();

            
        }
};

int main(){
    Circulo circulo1,circulo2, circulo3;
    circulo1.setRadio(10);
    circulo1.setColorBorde(11);
    circulo1.setColorFondo(14);
    circulo2.setRadio(10);
    circulo2.setColorBorde(11);
    circulo2.setColorFondo(14);
    circulo3.setRadio(11);
    circulo3.setColorBorde(11);
    circulo3.setColorFondo(14);

    if(circulo1.esIgual(&circulo2)){
        cout << "El circulo 1 y 2 son iguales" << endl;
    }else{
        cout << "El circulo 1 y 2 no son iguales" << endl;
    }
    if(circulo1.esIgual(&circulo3)){
        cout << "El circulo 1 y 3 son iguales" << endl;
    }else{
        cout << "El circulo 1 y 3 no son iguales" << endl;
    }
    return 0;

}

// how create header in c++?