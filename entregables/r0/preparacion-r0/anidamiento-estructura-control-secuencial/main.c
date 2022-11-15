#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b, resultado, opc;;
    printf("Minicalculadora\n\n");
    printf("Elige una opcion de las siguientes\n");
    printf("1. La sumna de dos numero\n");
    printf("2. La resta de dos numeros\n");
    printf("3. La multiplicacion de dos numeros\n");
    printf("4. La divicion de dos numeros\n");
    printf("5. Salir\n");
    printf("Tu opcion: ");
    scanf("%d", &opc);

    if(opc==1){
        printf("Suma de dos enteros\n\n");
        
        printf("Ingresa el primer valor: ");
        scanf("%d", &a);
        
        printf("Ingresa el segundo valor: ");
        scanf("%d", &b);
        
        resultado = a+b;
        printf("Resultado de la suma... %d + %d = %d\n\n", a,b,resultado);

    } 
    else if(opc==2) {
        printf("Resta de dos enteros\n\n");
        
        printf("Ingresa el primer valor: ");
        scanf("%d", &a);
        
        printf("Ingresa el segundo valor: ");
        scanf("%d", &b);
        
        resultado = a-b;
        printf("Resultado de la resta... %d - %d = %d\n\n", a,b,resultado);
    }
    else if(opc==3){
        printf("Multiplicacion de dos enteros\n\n");
        
        printf("Ingresa el primer valor: ");
        scanf("%d", &a);
        
        printf("Ingresa el segundo valor: ");
        scanf("%d", &b);
        
        resultado = a*b;
        printf("Resultado de la multiplicacion... %d * %d = %d\n\n", a,b,resultado);
    }
    else if(opc==4){
        printf("Divicion de dos enteros\n\n");
        
        printf("Ingresa el primer valor: ");
        scanf("%d", &a);
        
        printf("Ingresa el segundo valor: ");
        scanf("%d", &b);
        
        resultado = a/b;
        printf("Resultado de la divicion... %d / %d = %d\n\n", a,b,resultado);
    } 
    else if(opc==5){
        printf("\nPrograma terminado\n");
        return 0;
    } 
    else {
        printf("Opcion no valida\n");
    }

    return 0;
}