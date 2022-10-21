#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;

    printf("Determinar el caso de un numero\n\n");
    printf("Dame un numero: ");
    scanf("%d", &num);

    if(num>0){
        printf("El numero es positivo\n");
    } 
    else if(num==0){
        printf("El numero es neutro\n");
    } 
    else{
        printf("El numero es negativo\n");
    }

    return 0;
}