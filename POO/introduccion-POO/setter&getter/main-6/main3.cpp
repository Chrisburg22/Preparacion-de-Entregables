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

class Triangulo{
        double base;
        double altura;
        int colorBorde;
        int colorFondo;
    public:
        void setbase(double base){
            this->base = base;
        }
        void setAltura(int altura ){
            this->altura = altura;
        }
        void setColorBorde(int borde ){
            this->colorBorde = borde;
        }
        void setColorFondo(int fondo ){
            this->colorBorde = fondo;
        }
        double getBase(){
            return base;
        }
        double getAltura(){
            return altura;
        }
        int getColorBorde(){
            return colorBorde;
        }
        int getColorFondo(){
            return colorFondo;
        }
        double getArea(){
            return base*altura/C_2;
        }

};

int main(){
    Circulo circulo1,circulo2;
    Triangulo triangulo;
    
    circulo1.setRadio(10);
    circulo1.setColorBorde(11);
    circulo1.setColorFondo(14);

    circulo2.setRadio(20);
    circulo2.setColorBorde(11);
    circulo2.setColorFondo(14);

    triangulo.setbase(15);
    triangulo.setAltura(20);
    triangulo.setColorBorde(11);
    triangulo.setColorFondo(14);

    cout << "Datos Circulo #1" << endl
         << "Radio: " << circulo1.getRadio() << endl
         << "Color borde: " << circulo1.getColorBorde() << endl
         << "Color fondo: " << circulo1.getColorFondo() << endl
         << "Area: " << circulo1.getArea() << endl;

    cout << "Datos Circulo #1" << endl
         << "Radio: " << circulo2.getRadio() << endl
         << "Color borde: " << circulo2.getColorBorde() << endl
         << "Color fondo: " << circulo2.getColorFondo() << endl
         << "Area: " << circulo2.getArea() << endl;
    
    cout << "Datos Triangulo" << endl
         << "Base: " << triangulo.getBase() << endl
         << "Altura: " << triangulo.getAltura() << endl
         << "Color borde: " << triangulo.getColorBorde() << endl
         << "Color fondo: " << triangulo.getColorFondo() << endl
         << "Area: " << triangulo.getArea() << endl;

}
