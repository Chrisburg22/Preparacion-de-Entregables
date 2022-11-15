#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX_ELEMENTOS 3
#define ELEMENTO_NO_EXISTE -1


int elementos[MAX_ELEMENTOS];
int cuentaElementos;

void insertarElemento(int elemento){
    elementos[cuentaElementos++] = elemento;
}
void suprimeDeLista(int posicion){
    int i;
    if(posicion>0 && posicion< cuentaElementos){
        for(i=0,cuentaElementos-- ; i<cuentaElementos; i++){
            elementos[i] = elementos[i+1];
        }
    }
}
bool estaLlenaLista(){
    return cuentaElementos==MAX_ELEMENTOS;
}
bool estaVaciaLista(){
    return cuentaElementos==0;
}
int dameCuentaElementos(){
    return cuentaElementos;
}
int dameElemento(int posicion){
    if(posicion<cuentaElementos){
        return elementos[posicion];
    }else{
        return ELEMENTO_NO_EXISTE;
    }
}

#endif //LISTA_H_INCLUDED

