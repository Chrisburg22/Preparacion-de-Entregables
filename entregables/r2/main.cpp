#include <iostream>

using namespace std;

#define MAX_CARACTERES 128

void imprimeCadena(byte arreglo[], string cadena);

int main(){
    byte* palabra;
    string cadena;
    cout << "Ingresa una cadena: ";
    getline(cin, cadena);
    palabra = new byte[MAX_CARACTERES];
    palabra[0] = (byte)cadena.length();
    imprimeCadena(palabra, cadena);
    return 0;
}

void imprimeCadena(byte arreglo[], string cadena){
    int longitud,i;
    longitud = cadena.length();
    for(i=1;i<longitud;i++){
        arreglo[i] = (byte)cadena[i];
    }
    std::string palabra(arreglo, sizeof(arreglo));
}
