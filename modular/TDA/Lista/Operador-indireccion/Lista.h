#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Tipos-y-Constantes.h"

#define MAX_ELEMENTOS 3
#define ELEMENTO_NO_EXISTE -1

struct Lista
{
    tipo_elemento elementos[MAX_ELEMENTOS];
    int cuentaElementos;
};

void inicializar(Lista* lista){
    lista->cuentaElementos = 0;
}

void insertarEnLista(tipo_elemento elemento, Lista* lista){
    lista->elementos[lista->cuentaElementos++] = elemento;
}
void suprimeDeLista(int posicion,Lista* lista){
    int i;
    if(posicion>0 && posicion< lista->cuentaElementos){
        for(i=0,lista->cuentaElementos-- ; i<lista->cuentaElementos; i++){
            lista->elementos[i] = lista->elementos[i+1];
        }
    }
}
bool estaLlenaLista(Lista* lista){
    return lista->cuentaElementos==MAX_ELEMENTOS;
}
bool estaVaciaLista(Lista* lista){
    return lista->cuentaElementos==0;
}
int dameCuentaElementos(Lista* lista){
    return lista->cuentaElementos;
}
tipo_elemento dameElemento(int posicion, Lista* lista){
    if(posicion<lista->cuentaElementos){
        return lista->elementos[posicion];
    }else{
        return ELEMENTO_NO_EXISTE;
    }
}

#endif //LISTA_H_INCLUDED

