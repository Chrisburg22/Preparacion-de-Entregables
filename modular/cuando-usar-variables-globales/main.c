#include <stdio.h>
#include <stdlib.h>

#define MAX_INGRESOS 3

int cuentaIngresos;
float ingresos[MAX_INGRESOS];

void capturarIngreso();
void listarIngresos();
void listarSoloIngresosCapturados();

int main(){
    for(int i=0; i<MAX_INGRESOS; i++){
        listarSoloIngresosCapturados();         
        capturarIngreso();
    }
    listarIngresos();
    return 0;
}

void capturarIngreso(){
    printf("Capturando Ingresos\n");
    printf("Dame el ingreso #%d: ",cuentaIngresos);
    scanf("%f", &ingresos[cuentaIngresos++]);
}

void listarIngresos(){
    printf("Lista de ingresos\n");
    for(int i=0; i<MAX_INGRESOS ; i++){
        printf("Ingresos #%d son %.2f\n", i, ingresos[i]);
    }
}

void listarSoloIngresosCapturados(){
    printf("\nLista de ingresos capturados\n\n");
    if(cuentaIngresos){
        for(int i=0; i<cuentaIngresos ; i++){
                printf("Ingresos #%d son %.2f\n", i, ingresos[i]);
        }
    }else{
        printf("No hay ingresos registrados\n\n");
    }
}