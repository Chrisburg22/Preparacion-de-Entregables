#include <iostream>
#include "Lista.h"

enum {ALTA_ELEMENTO=1,BAJA_ELEMENTO,LISTADO_ELEMENTOS,SALIR};

Lista ingresos;
void elegirOpcionMenu(int& opcion);
void registrarIngresos();
void eliminarIngresos();
void listarIngresos();


using namespace std;

int main(){
    int opcionMenu;
    inicializar(ingresos);
    do{
        elegirOpcionMenu(opcionMenu);
        switch (opcionMenu){
        case ALTA_ELEMENTO:
            registrarIngresos();
            break;
        case BAJA_ELEMENTO:
            eliminarIngresos();
            break;
        case LISTADO_ELEMENTOS:
            listarIngresos();
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
    cout << "Control de Ingresos" << endl << endl
         << "Elige una opcion" << endl
         << "1.Alta de ingresos" << endl
         << "2.Baja de ingresos" << endl
         << "3.Listar ingresos" << endl
         << "4.Salir" << endl
         << "Opcion: ";
    cin >> opcion;
}

void registrarIngresos(){
    int elemento;
    cout << "Alta de elemento" << endl << endl;
    if(!estaLlenaLista(ingresos)){
        cout << "Dame el valor entero a guardar: ";
        cin >> elemento;
        insertarEnLista(elemento, ingresos);
    } else {
        cout << "No hay más espacio para capturar elementos" << endl;
    }

}

void eliminarIngresos(){
    int posicion;
    cout << "Baja de elemento" << endl << endl;
    if(!estaVaciaLista(ingresos)){
        cout << "Dame la posicion( 0 a "<<ingresos.cuentaElementos<<") del entero a remover: ";
        cin >> posicion;
        suprimeDeLista(posicion, ingresos);
    }
}

void listarIngresos(){
    int i, j;
    cout << "Listado de elementos" << endl << endl;
    if(!estaVaciaLista(ingresos)){
        for(i=0, j=dameCuentaElementos(ingresos) ; i<j ; i++){
            cout << "elementos[" << i << "] = " << dameElemento(i, ingresos) << endl;
        }
    } else {
        cout << "No hay elementos que mostrar" << endl;
    }
}