#include <iostream>
#include "Administrador.h"
#include "Circulo.h"

enum{AGREGAR_CIRCULO=1, MOSTRAR_CIRCULOS,SALIR};

using namespace std;

Administrador* adminCirculos;

void inicializar(){
    adminCirculos = new Administrador();
}

void pausa(){
    cout << "Presiona enter para continuar ..." << endl;
    cin.ignore();
    cin.get();
}

void agregarCirculo(){
    double radio;
    int borde,fondo;
    if(adminCirculos->dameCuentaCirculos()<MAX_CIRCULOS){
        cout << "Agregando circulo" << endl << endl;
        cout << "Ingresa radio: ";
        cin >> radio;
        cout << "Ingresa color borde: ";
        cin >> borde;
        cout << "Ingresa color fondo: ";
        cin >> fondo;
        if(adminCirculos->agregar(radio,borde,fondo)){
            cout << "El circulo se agrego con exito" << endl << endl;
            pausa();
        } else {
            cout << "El circulo no pudo ser agregado" << endl << endl;
            pausa();
        }
    }
}

void mostrarCirculos(){
    int i,j;
    for(i=0, j=adminCirculos->dameCuentaCirculos();i<j;i++){
        cout << adminCirculos->dameInfoCirculo(i); 
        pausa();
    }
}

int main(){
    int opcion;
    bool salir = true;
     inicializar();
    do{
        cout << " Administrador de Circulo  " << endl << endl
             << "  1.Agregar" << endl
             << "  2.Listar" << endl
             << "  3.Salir" << endl << endl
             << "  Eligue una opción: ";
        cin >> opcion;
        switch (opcion){
            case AGREGAR_CIRCULO:
                 agregarCirculo();
                 break;
            case MOSTRAR_CIRCULOS:
                 mostrarCirculos();
                 break;
            case SALIR:
                 salir = false;
                 break;
            default:
                 cout << "Opcion invalida" << endl;
                 pausa();
        }
    } while (salir);
    
    
    delete adminCirculos;
    return 0;
} 