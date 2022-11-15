#include <iostream>
#include "Lista.h"

enum {ALTA_ELEMENTO=1,BAJA_ELEMENTO,LISTADO_ELEMENTOS,SALIR};


void elegirOpcionMenu(int& opcion);
void registrarElemento();
void eliminarElemento();
void listarElementos();


using namespace std;

int main(){
    int opcionMenu;
    do{
        elegirOpcionMenu(opcionMenu);
        switch (opcionMenu){
        case ALTA_ELEMENTO:
            registrarElemento();
            break;
        case BAJA_ELEMENTO:
            eliminarElemento();
            break;
        case LISTADO_ELEMENTOS:
            listarElementos();
            break;
        case SALIR:
            cout << "Bytes !!!!" << endl;
            break;
        default:
            cout << "opcion no valida" << endl;
            break;
        }
    } while(opcionMenu!=SALIR);
    return 0;
}
void elegirOpcionMenu(int&  opcion){
    cout << "TDA Lista" << endl << endl
         << "Elige una opcion" << endl
         << "1.Alta de elemento" << endl
         << "2.Baja de elemento" << endl
         << "3.Listar elementos" << endl
         << "4.Salir" << endl
         << "Opcion: ";
    cin >> opcion;
}

void registrarElemento(){
    int elemento;
    cout << "Alta de elemento" << endl << endl;
    if(!estaLlenaLista()){
        cout << "Dame el valor entero a guardar: ";
        cin >> elemento;
        insertarElemento(elemento);
    } else {
        cout << "No hay más espacio para capturar elementos" << endl;
    }
}

void eliminarElemento(){
    int posicion;
    cout << "Baja de elemento" << endl << endl;
    if(!estaVaciaLista()){
        cout << "Dame la posicion( 0 a "<<cuentaElementos+1<<") del entero a remover: ";
        cin >> posicion;
        suprimeDeLista(posicion);
    }
}

void listarElementos(){
    int i, j;
    cout << "Listado de elementos" << endl << endl;
    if(!estaVaciaLista()){
        for(i=0, j=dameCuentaElementos() ; i<j ; i++){
            cout << "elementos[" << i << "] = " << dameElemento(i) << endl;
        }
    } else {
        cout << "No hay elementos que mostrar" << endl;
    }
}