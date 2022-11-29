#include <iostream>
#include "Lista.h"

enum {ALTA_ELEMENTO=1,BAJA_ELEMENTO,LISTADO_ELEMENTOS,SALIR};

Lista ingresos;
void elegirOpcionMenu(int& opcion);
void registrarIngresos();
void eliminarIngresos();
void listarIngresos();
void mostrarIngresos();

 
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
            mostrarIngresos();
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
    float ingreso;
    cout << "Alta de elemento" << endl << endl;
    if(!estaLlenaLista(ingresos)){
        cout << "Dame el valor entero a guardar: ";
        cin >> ingreso;
        insertarEnLista(ingreso, fin(ingresos), ingresos);
    } else {
        cout << "No hay más espacio para capturar elementos" << endl;
    }
 
}

void eliminarIngresos(){
    int numeroElementoRemover, i;
    posicion p,f;
    cout << "Baja de elemento" << endl << endl;
    if(!estaVaciaLista(ingresos)){
        listarIngresos();
        cout << "Dime cual ingreso deseas remover (1 a " << dameUltimo(ingresos) << "): ";
        cin >> numeroElementoRemover;
        for(i=1, p=primero(ingresos), f=fin(ingresos);i<numeroElementoRemover && p!=f; i++,p=siguiente(p,ingresos));
        if(p!=f && numeroElementoRemover>0){
            suprimeDeLista(p,ingresos);
        } else {
          cout << numeroElementoRemover << " esta fuera del rango solicitado" << endl;
        }
    } else {
        cout << "No hay elementos para eliminar" << endl;
    }
}

void listarIngresos(){
    int i, j;
    int k;
    for(k=1,i=primero(ingresos),j=fin(ingresos) ; i!=j ; i=siguiente(i,ingresos), k++){
            cout << k << ". " << dameElemento(i, ingresos) << endl;
    }
}

void mostrarIngresos(){
    if(!estaVaciaLista(ingresos)){
        listarIngresos();
    }else{
        cout << "No hay ingresos por mostrar" << endl;
    }
}