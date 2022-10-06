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

};

int main(){
    Circulo circulo;
    circulo.setRadio(10);
    circulo.setColorBorde(11);
    circulo.setColorFondo(14);

    cout << "Radio: " << circulo.getRadio() << endl
         << "Color borde: " << circulo.getColorBorde() << endl
         << "Color fondo: " << circulo.getColorFondo() << endl
         << "Area: " << circulo.getArea() << endl;


}
