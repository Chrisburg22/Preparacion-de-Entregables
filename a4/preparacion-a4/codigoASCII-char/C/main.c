#include <stdio.h>
#include <stdlib.h>

int main (){

    char letra;
    
    letra = 'A';
    printf( "Tu letra es: %c\n", letra );
    printf( "Codigo ASCII de la letra: %d\n\n", (int)letra ); // Converción de tipo de dato char a int. En este caso para imprimir el valor del código ASCII

    letra = 66; //Podriamos almacenar una variable numerica
    printf( "Tu letra es: %c\n", letra );// Podemos imprimir el caracter 66 que en este caso va a imprimir la letra 'B'
    printf( "Codigo ASCII de la letra: %d\n\n", (int)letra );

    for( int i=0 ; i < 24 ; i++ ){
        letra ++;
        printf( "Tu letra es: %c\n", letra );
        printf( "Codigo ASCII de la letra: %d\n\n", (int)letra );
    }

    return 0;
}