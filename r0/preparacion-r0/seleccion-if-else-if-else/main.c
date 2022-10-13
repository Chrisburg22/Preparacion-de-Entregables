#include <stdio.h>

int main(){
    int num;

    printf("Determinar si un numero es positivo, neutro o negativo\n");
    printf("Dame un numero entero: ");
    scanf("%d", &num);

    if(num>0){
        printf("El numero %d es positivo\n", num);
    } 
    else if(num==0){
        printf("El numero %d es neutro\n", num);
    }
    else {
        printf("El numero %d es negativo\n", num);
    }
    printf("Gracias por jugar XD\n");

    return 0;

}