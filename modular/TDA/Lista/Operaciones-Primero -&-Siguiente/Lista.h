#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Tipos-y-Constantes.h"

typedef int posicion;
#define MAX_ELEMENTOS 3
#define ELEMENTO_NO_EXISTE -1

struct Lista
{
    tipo_elemento elementos[MAX_ELEMENTOS];
    int ultimo;
};

void inicializar(Lista& lista);
int dameUltimo(Lista& lista);
bool estaVaciaLista(Lista& lista);
tipo_elemento dameElemento(int posicion, Lista& lista);
bool estaLlenaLista(Lista& lista);
void suprimeDeLista(int posicion,Lista& lista);
void insertarEnLista(tipo_elemento elemento, int posicion, Lista& lista);
posicion fin(Lista& lista);
posicion primero(Lista& lista);
posicion siguiente(posicion p, Lista& lista);


posicion primero(Lista& lista){
    if(estaVaciaLista(lista)){
        return lista.ultimo+1;
    } else {
        return 0;
    }
}

posicion siguiente(posicion p,Lista& lista){
    if(p>=0 && p<=lista.ultimo){
        return p+1;
    } else {
        return ELEMENTO_NO_EXISTE;
    }
}

void inicializar(Lista& lista){
    lista.ultimo = -1;
}

posicion fin(Lista& lista){
    return lista.ultimo+1; 
}

void insertarEnLista(tipo_elemento elemento, int posicion, Lista& lista){
    int i;
    if(posicion>=0 && posicion<=lista.ultimo+1 ){
        for(i=lista.ultimo+1;i>posicion;i--){
            lista.elementos[i]=lista.elementos[i-1];
        }
        lista.elementos[posicion]=elemento;
        lista.ultimo++;
    }
}

void suprimeDeLista(int posicion,Lista& lista){
    int i;
    if(posicion>=0 && posicion<=lista.ultimo+1){
        for(i=posicion,lista.ultimo-- ; i<lista.ultimo+1; i++){
            lista.elementos[i] = lista.elementos[i+1];
        }
    }
}
bool estaLlenaLista(Lista& lista){
    return lista.ultimo+1==MAX_ELEMENTOS;
}
bool estaVaciaLista(Lista& lista){
    return lista.ultimo+1==0;
}
int dameUltimo(Lista& lista){
    return lista.ultimo+1;
}
tipo_elemento dameElemento(int posicion, Lista& lista){
    if(posicion<lista.ultimo+1){
        return lista.elementos[posicion];
    }else{
        return ELEMENTO_NO_EXISTE;
    }
}

#endif //LISTA_H_INCLUDED
