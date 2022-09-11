#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main () {
    int factor, vector[10];
    cout << "Numeros de vectores\n\n";

    vector[0]=1;
    vector[1]=2;
    vector[2]=3;
    vector[3]=4;
    vector[4]=5;
    vector[5]=6;
    vector[6]=7;
    vector[7]=8;
    vector[8]=9;
    vector[9]=10;

    cout << "Valor celda 1: " << vector[0] << endl;
    cout << "Valor celda 2: " << vector[1] << endl;
    cout << "Valor celda 3: " << vector[2] << endl;
    cout << "Valor celda 4: " << vector[3] << endl;
    cout << "Valor celda 5: " << vector[4] << endl;
    cout << "Valor celda 6: " << vector[5] << endl;
    cout << "Valor celda 7: " << vector[6] << endl;
    cout << "Valor celda 8: " << vector[7] << endl;
    cout << "Valor celda 9: " << vector[8] << endl;
    cout << "Valor celda 10: " << vector[9] << endl << endl;

    cout << "Multiplicaremos los vectores" << endl;
    cout << "Ingresa el valor para multiplicar: ";
    cin >> factor;

    vector[0]*=factor;
    vector[1]*=factor;
    vector[2]*=factor;
    vector[3]*=factor;
    vector[4]*=factor;
    vector[5]*=factor;
    vector[6]*=factor;
    vector[7]*=factor;
    vector[8]*=factor;
    vector[9]*=factor; 

    cout << "Valores modificados\n\n" ;

    cout << "Valor celda 1: " << vector[0] << endl;
    cout << "Valor celda 2: " << vector[1] << endl;
    cout << "Valor celda 3: " << vector[2] << endl;
    cout << "Valor celda 4: " << vector[3] << endl;
    cout << "Valor celda 5: " << vector[4] << endl;
    cout << "Valor celda 6: " << vector[5] << endl;
    cout << "Valor celda 7: " << vector[6] << endl;
    cout << "Valor celda 8: " << vector[7] << endl;
    cout << "Valor celda 9: " << vector[8] << endl;
    cout << "Valor celda 10: " << vector[9] << endl << endl;
    
    
    return 0;
}