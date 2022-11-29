#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Tipos-y-Constantes.h"

#define MAX_ELEMENTOS 3
#define ELEMENTO_NO_EXISTE -1

struct Lista
{
    tipo_elemento elementos[MAX_ELEMENTOS];
    int ultimo;
};

void inicializar(Lista& lista){
    lista.ultimo = -1;
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
        lista.ultimo--;
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

