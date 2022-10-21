#include <iostream>

using namespace std;

int factorial(int n){
    int factor;
    if(n==0){
        factor=1;
    }
    else if(n>0){
/**
 * Con la recursividad esta funcion crea 
 * diferentes dimenciones de la misma función
 * hasta que ella ya no se llame asi misma,
 * en este caso sera cuando el parametro recivido sea 0 o menos
*/
        factor = n * factorial(n-1);
    }
    else{
        factor = -1;
    }
    return factor;
}

int main(){
    int resultado, n;
    cout << "Dame la \"N\" para factorial: ";
    cin >> n;
    resultado = factorial(n);
    cout << "Factorial de " << n << " es " << resultado << endl;

    return 0;
}