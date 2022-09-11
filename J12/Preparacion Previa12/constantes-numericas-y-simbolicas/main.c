#include <stdio.h>
#include <stdlib.h>

#define PI 3.1416

int main() {
    
    int radio[2];
    float area[2];
    printf("Calculo del area de circulos\n\n");

    printf("Dame los datos de un primer circulo\n");
    printf("Dame el radio: " );
    scanf("%d", &radio[0]);

    area[0]= PI * radio[0] * radio[0];

    printf("Dame los datos de un segundo circulo\n");
    printf("Dame el radio: " );
    scanf("%d", &radio[1]);

    area[1]= PI * radio[1] * radio[1];

    printf("Los resultados del primer circulo son:  \n");
    printf("Radio: %d\n", radio[0]);
    printf("Area %f\n", area[0]);

    printf("Los resultados del segundo circulo son:  \n");
    printf("Radio: %d\n", radio[1]);
    printf("Area %f\n", area[1]);
    return 0;



}