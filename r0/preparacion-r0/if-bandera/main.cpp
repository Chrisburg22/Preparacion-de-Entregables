#include <iostream>

using namespace std;

#define EDAD_MINIMA 18

int main(){
    int edad;
    bool mayorEdad;

    cout << "Dime tu edad: ";
    cin >> edad;

    mayorEdad = edad>=EDAD_MINIMA;

    (mayorEdad) ? cout << "Puedes entrar al bar"  : cout << "No puedes pasar eres solo un chico";

    return 0;
}