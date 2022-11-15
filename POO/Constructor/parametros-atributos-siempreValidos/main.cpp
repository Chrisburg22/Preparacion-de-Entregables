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

void imprimirCiruclo(Circulo& c){//& es paso de parametro por referencia, de esta manera no clonamos el dato, sino que le pasamos la ubicacion de el dato
    cout << "Radio: " << c.getRadio() << endl;
    cout << "Color Borde: " << c.getColorBorde() << endl;
    cout << "Color Fondo: " << c.getColorFondo() << endl << endl;
}

int main(){
    Circulo c(100,15,13);
    double radio;

    cout << "Datos del circulo pasados por parametro" << endl;
    imprimirCiruclo(c);
    cout << "Dame nuevo valor para el radio: ";
    cin >> radio;

    if(c.setRadio(radio)){
        cout << "Si fue posible modificar el radio" << endl << endl;
    } else {
        cout << "El dato no pudo ser modificdo" << endl << endl;
    }
    imprimirCiruclo(c);
    return 0;
}