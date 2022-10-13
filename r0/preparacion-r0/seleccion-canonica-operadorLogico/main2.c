#include <stdio.h>

int main(){
    int p,q;

    printf("Operador logico Y\n\n");
    printf("Simbologia: \n");
    printf("P = Lavar los trastes\n");
    printf("Q = Arreglas tu cuarto\n");
    printf("El 10 es totamente echo\n");
    printf("Dame el valor para P (Del 0 al 10): ");
    scanf("%d", &p);
    printf("Dame el valor para Q (Del 0 al 10): ");
    scanf("%d", &q);

    if(p==10 || q==10){// si p=10 "O" q=10
        printf("Puedes ir a jugar\n");
    } else {
        printf("No puedes ir a jugar\n");
    }

    return 0;
}