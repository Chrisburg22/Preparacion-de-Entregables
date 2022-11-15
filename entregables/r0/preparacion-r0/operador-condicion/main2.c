#include <stdio.h>
#include <stdlib.h>

//Esta seria la manera de poder trabajar este operador en el lenguaje JAVA

int main(){
    int cantidadMaestros, cantidadAlumnos;
    char* resultado;
    cantidadMaestros=1;
    cantidadAlumnos=22;

    resultado = ((cantidadMaestros==1)&&(cantidadAlumnos>0)) ? "Si hay clase\n" : "No hay clase\n";
    printf("%s", resultado);

    return 0;
}