#include <iostream>

using namespace std;

class Circulo{
    public:
        double radio;
        int colorBorde;
        int colorFondo;
};

int main(){
    Circulo c;
    c.radio = 10;
    c.colorBorde=11;
    c.colorFondo=14;

    cout << "Radios es: " << c.radio << endl
         << "Color borde: " << c.colorBorde << endl
         << "Color fondo: " << c.colorFondo << endl;
    
    return 0;

}
