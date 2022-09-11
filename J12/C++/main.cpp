#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int const MAX_ASISTENCIAS=34;

    int alumnoFaltas, alumnoAsistencias;
    float porcentajeAsistencias;

    cout << "Ingresa el numero de faltas del alumno: ";
    cin >> alumnoFaltas;

    alumnoAsistencias = MAX_ASISTENCIAS - alumnoFaltas;

    porcentajeAsistencias= ( (float)alumnoAsistencias / (float)MAX_ASISTENCIAS ) * 100;

    cout << "El pocentaje en porcentaje es: "<< porcentajeAsistencias;


    return 0;
}
