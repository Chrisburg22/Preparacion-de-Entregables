#include <iostream>

using namespace std;

class Circulo{
    private:
       static constexpr double PI=3.1416;
       double radio;
       int colorBorde;
       int colorFondo;
    public:
        Circulo(double radio, int colorBorde, int colorFondo){
            this->radio = 10;
            this->colorBorde = 14;
            this->colorFondo = 11;

            setRadio(radio);
            setColorBorde(colorBorde);
            setColorFondo(colorFondo);
        }
        bool setRadio(double r){
            if(r>0){
                radio = r;
                return true;
            } else {
                return false;
            }
        }
        bool setColorBorde(int b){
            if(b>0){
                colorBorde = b;
                return true;
            } else {
                return false;
            }
        }
        bool setColorFondo(int f){
            if(f>0){
                colorBorde = f;
                return true;
            } else {
                return false;
            }
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

void imprimirCirculo(Circulo& c);
void capturarDatos(double& radio, int& colorBorde, int& colorFondo);

int main(){

    double radio;
    int colorBorde, colorFondo;
    capturarDatos(radio,colorBorde,colorFondo);
    Circulo c(radio,colorBorde,colorFondo);
    cout << "Datos del nuevo circulo" << endl;
    imprimirCirculo(c);
    return 0;
}

void imprimirCirculo(Circulo& c){//& es paso de parametro por referencia, de esta manera no clonamos el dato, sino que le pasamos la ubicacion de el dato
    cout << "Radio: " << c.getRadio() << endl;
    cout << "Color Borde: " << c.getColorBorde() << endl;
    cout << "Color Fondo: " << c.getColorFondo() << endl << endl;
}

void capturarDatos(double& radio, int& colorBorde, int& colorFondo){
    cout << "Capturando datos" << endl;
    cout << "Radio: ";
    cin >> radio;
    cout << "Color borde: ";
    cin >> colorBorde;
    cout << "Color fondo: ";
    cin >> colorFondo;
}
