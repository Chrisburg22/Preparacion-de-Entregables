#include <iostream>

using namespace std;

#define C_2 2

class Circulo{
        static constexpr float PI = 3.1416;
        double radio;
        int colorBorde;
        int colorFondo;
    public:
        Circulo(double radiox, int colorBordex, int coloFondox ){
            radio=radiox;
            colorBorde=colorBordex;
            colorFondo=coloFondox;
        }
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
        //Metodo con varios parametros para fijar los datos
        void fijaDatos(double radiox, int colorBordex, int coloFondox ){
            radio=radiox;
            colorBorde=colorBordex;
            colorFondo=coloFondox;
        }

};

int main(){
    Circulo circulo(20,11,14);

    //circulo.fijaDatos(20,11,14);
    cout << "Radio: " << circulo.getRadio() << endl
         << "Color borde: " << circulo.getColorBorde() << endl
         << "Color fondo: " << circulo.getColorFondo() << endl
         << "Area: " << circulo.getArea() << endl;

}
