#include <stdio.h>
#include <stdlib.h>

#define EDAD_ADULTA 18

int main()
{
    int edad;
    int mayorEdad;

    printf("Dame tu edad: ");
    scanf("%d", &edad);

    mayorEdad = edad >= EDAD_ADULTA; // Si es mayor o igual retorna un uno, si no es mayor o igual retorna 0

    // En c 1 es igual a verdad y 0 es fal
    if (mayorEdad)
    {
        printf("Entra a la disco paps\n");
    }
    else
    {
        printf("JA.. Directo a la chosa de los peques\n");
    }
    return 0;
}