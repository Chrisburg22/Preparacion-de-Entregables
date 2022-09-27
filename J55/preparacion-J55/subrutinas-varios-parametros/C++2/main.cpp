#include <iostream>
#include <stdio.h>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

#define CARACTERES_POR_FILA 80;
typedef enum { Suma=1, Resta, Multiplicacion, Divicion, Potencia, Salir} opcionMenu;
using namespace std;

void pausar();
void limpiarPantalla();
void sumar(int a, int b);
void restar(int a, int b);
void mutiplicar(int a, int b);
void dividir(int a, int b);
void potencia( int base, int exponente);
void titulo( string titulo, char relleno);

int main (){
    int opc, a, b;
    bool terminarPrograma = true;
    do{
        limpiarPantalla();
        titulo(" CALCULADORA BASICA ", '*');
        cout << "1) Sumar " << endl;
        cout << "2) Restar " << endl;
        cout << "3) Multiplicar " << endl;
        cout << "4) Dividir " << endl;
        cout << "5) Potencia " << endl;
        cout << "6) Salir " << endl << endl;
        cout << "Elige una opcion: ";
        cin >> opc;
    
        switch( opc ){
            case Suma:
               limpiarPantalla();
               sumar(a,b);
               break;
            case Resta:
               limpiarPantalla();
               restar(a,b);
               break;
            case Multiplicacion:
               limpiarPantalla();
               mutiplicar(a,b);
               break;
            case Divicion:
               limpiarPantalla();
               dividir(a,b);
               break;   
            case Potencia:
               limpiarPantalla();
               potencia(a,b);
               break;
            case Salir:
               terminarPrograma = false;
               break;
            default:
               cin.ignore();
               cout << "Opcion no valida\n\n";
               pausar();
               break;         
        }
    } while(terminarPrograma);
}

void limpiarPantalla(){
    system(CLEAR);
}

void pausar(){
    cout << "Presione enter para continuar . . .";
    cin.ignore();
}

void sumar(int a, int b){
    int resultado;
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;
    resultado = a +b;
    cin.ignore();
    cout << endl << "El resultado es: " << resultado << endl;
    pausar();
}

void restar(int a, int b){
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;
    cin.ignore();
    cout << endl << "El resultado es: " << a-b << endl;
    pausar();
}

void mutiplicar(int a, int b){
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;
    cin.ignore();
    cout << endl << "El resultado es: " << a*b << endl;
    pausar();
}

void dividir(int a, int b){
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;
    cin.ignore();
    cout << endl << "El resultado es: " << a/b << endl;
    pausar();
}
void potencia( int base, int exponente){
    int resultado;
    cout << "Ingrese el numero base: ";
    cin >> base;
    cout << "Ingresa el exponente: ";
    cin >> exponente;
    resultado = base;
    for(int i=0; i<exponente ; i++){
         resultado *= base;
    }
    cin.ignore();
    cout << endl << "El resultado es: " << resultado << endl;
    pausar();
}

void titulo( string titulo, char relleno){
    int tamanioRelleno;

    tamanioRelleno = CARACTERES_POR_FILA - titulo.length();

    for(int i=0 ; i < (tamanioRelleno/2) ; i++ ){
        cout << relleno;
    }

    cout << titulo;

    for(int i=0 ; i < (tamanioRelleno/2) ; i++ ){
        cout << relleno;
    }

    cout << endl << endl;
}