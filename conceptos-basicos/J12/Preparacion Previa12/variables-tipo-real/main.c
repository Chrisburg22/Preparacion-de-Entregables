#include <stdio.h>
#include <stdlib.h>

int main() {
    
    float a, b, c;
    
    printf("Dale el valor para la variable A: ");
    scanf( "%f", &a );
    printf("Dale el valor para la variable B: ");
    scanf( "%f", &b );

    c = a+b;

    printf("A= %f\n", a);
    printf("B= %f\n", b);
    printf("C= %f\n", c);

    return 0;
}