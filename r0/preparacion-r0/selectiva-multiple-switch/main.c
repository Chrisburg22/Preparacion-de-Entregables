#include <stdio.h>
#include <stdlib.h>

typedef enum{SUMA=1,RESTA,MULTIPLICACION,DIVICION,SALIR};

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


    switch (opc)
    {
    case 1:
        printf("\nSuma de dos enteros\n\n");
        
        printf("Ingresa el primer valor: ");
        scanf("%d", &a);
        
        printf("Ingresa el segundo valor: ");
        scanf("%d", &b);
        
        resultado = a+b;
        printf("Resultado de la suma... %d + %d = %d\n\n", a,b,resultado);
        break;
    case 2:
        printf("\nResta de dos enteros\n\n");
        
        printf("Ingresa el primer valor: ");
        scanf("%d", &a);
        
        printf("Ingresa el segundo valor: ");
        scanf("%d", &b);
        
        resultado = a-b;
        printf("Resultado de la resta... %d - %d = %d\n\n", a,b,resultado);
        break;
    case 3:
        printf("\nMultiplicacion de dos enteros\n\n");
        
        printf("Ingresa el primer valor: ");
        scanf("%d", &a);
        
        printf("Ingresa el segundo valor: ");
        scanf("%d", &b);
        
        resultado = a*b;
        printf("Resultado de la multiplicacion... %d * %d = %d\n\n", a,b,resultado);
        break;
    case 4:
        printf("\nDivicion de dos enteros\n\n");
        
        printf("Ingresa el primer valor: ");
        scanf("%d", &a);
        
        printf("Ingresa el segundo valor: ");
        scanf("%d", &b);
        
        resultado = a%b;
        printf("Resultado de la divicion... %d / %d = %d\n\n", a,b,resultado);
        break;    
    case 5:
        printf("\nPrograma terminado\n");
        return 0;
        break;    
    default:
        printf("Opcion no valida\n");
        break;
    }

    return 0;
}