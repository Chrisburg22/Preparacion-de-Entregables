/*
 * NickName = DosTres
 * Actividad a4
 * Tiempo = 02:00
*/
#include <iostream>
#include <iomanip>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

#define TOTAL_ASISTENCIAS 34
#define TOTAL_TAREAS 10
#define TOTAL_ACTIVIDADES 9
#define TOTAL_EXAMENES 3
#define CALIFICACION_MAX 100
#define CALFICACION_MIN 60
#define PORCENTAJE_TAREAS 0.07
#define PORCENTAJE_ACTIVIDADES 0.63
#define PORCENTAJE_EXAMENES 0.30
#define PORCENTAJE_ASISTENCIA 80
#define FALTA_RETARDOS 3

void pausar();

using namespace std;

int main(){
    int cantidadFaltas, cantidadRetardos, cantidadTareas;
    int califActividades[TOTAL_ACTIVIDADES], califExamenes[TOTAL_EXAMENES];
    float puntosTareas, puntosActividades, puntosExamenes, calificacionFinal;
    float totalAsistencias, porcentajeAsistencia;
    bool tieneDerecho, calificacionAprobatoria;
    int i, sumaActividades, sumaExamenes;

    cout << "Evaluador de Curso v1.0 – Estructuras de Datos II(EDA2) MJ 11a13" << endl << endl;
    
    cout << "Cuántas faltas acumulaste? ";
    cin >> cantidadFaltas; 
    cout << "Cuántos retardos acumulaste? ";
    cin >> cantidadRetardos; 
    cout << "Cuántas tareas realizaste? ";
    cin >> cantidadTareas;
    
    for(i=0; i<TOTAL_ACTIVIDADES ; i++){
        cout << "Cuánto obtuviste en la actividad #" << i+1 << "? ";
        cin >> califActividades[i];
    }
    
    for(i=0; i<TOTAL_EXAMENES ; i++){
        if((i+1)==1){
            cout << "Cuánto obtuviste en el primer examen parcial? ";
            cin >> califExamenes[i];
        } 
        else if(i+1==2){
            cout << "Cuánto obtuviste en el segundo examen parcial? ";
            cin >> califExamenes[i];
        }
        else{
            cout << "Cuánto obtuviste en el tercer examen parcial? ";
            cin >> califExamenes[i];
        }
    }
    
    for(i=0; i<TOTAL_ACTIVIDADES ; i++){
        sumaActividades = sumaActividades+ califActividades[i];
    }
    
    for(i=0; i<TOTAL_EXAMENES ; i++){
        sumaExamenes = sumaExamenes + califExamenes[i];
    }

    puntosTareas = ((float)cantidadTareas*PORCENTAJE_TAREAS)*(float)TOTAL_TAREAS;
    puntosActividades = ((float)sumaActividades/(float)TOTAL_ACTIVIDADES)*PORCENTAJE_ACTIVIDADES;
    puntosExamenes = ((float)sumaExamenes/(float)TOTAL_EXAMENES)*PORCENTAJE_EXAMENES;

    totalAsistencias = (float)TOTAL_ASISTENCIAS-((float)(cantidadRetardos/(float)FALTA_RETARDOS)+(float)cantidadFaltas);
    porcentajeAsistencia = (totalAsistencias*100)/TOTAL_ASISTENCIAS;
    calificacionFinal = ((puntosActividades+puntosTareas+puntosExamenes)*100)/100;
    if(porcentajeAsistencia<PORCENTAJE_ASISTENCIA){
        tieneDerecho = false;
    } else {
        tieneDerecho = true;
    }
    if(calificacionFinal<CALFICACION_MIN){
        calificacionAprobatoria = false;
    }else{
        calificacionAprobatoria = true;
    }

    cout << "Tareas  Actividades  Exámenes" << endl
         << fixed << setprecision(2) << "  " << puntosTareas 
         << fixed << setprecision(2) << "      " << puntosActividades
         << fixed << setprecision(2) << "       " << puntosExamenes << endl
         << "Total de asistencias=         " << totalAsistencias << endl;
    
    if(tieneDerecho){
        cout << "Porcentaje de asistencias=    " << porcentajeAsistencia 
             << "  Tiene derecho"  << endl;
    } else {
        cout << "Porcentaje de asistencias=    " << porcentajeAsistencia 
             << "  No tiene derecho"  << endl;
    }

    if(calificacionAprobatoria){
        cout << "Calificación Final=           " << calificacionFinal 
             << "  Calificación aprobatoria"  << endl;
    } else {
        cout << "Calificación Final=           " << calificacionFinal 
             << "  Calificación no aprobatoria"  << endl;
    }

    if(calificacionAprobatoria){
        if(tieneDerecho){
            cout << "Alumn@ aprobad@" << endl;
        } else {
            cout << "Alumn@ no aprobad@" << endl;
        }
    } else {
        cout << "Alumn@ no aprobad@" << endl;
    }

    cout << endl;
    pausar();
    return 0;
}

void pausar(){
    cout << "Presione entrar para continuar . . ." << endl;
    cin.ignore();
}
