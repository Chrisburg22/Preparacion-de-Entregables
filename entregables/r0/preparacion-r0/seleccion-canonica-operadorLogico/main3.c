#include <stdio.h>

int main(){
    int p,q;

    printf("Operador logico Y\n\n");
    printf("Simbologia: \n");
    printf("P = Arreglaste tu cuerto antes de las 12pm\n");
    printf("El 10 es totamente echo\n");
    printf("Dame el valor para P (Del 0 al 10): ");
    scanf("%d", &p);

    if(!p==10){ //Negacion 
        printf("Hay castigo\n");
    } else {
        printf("No hay castigo\n");
    }

    return 0;
}