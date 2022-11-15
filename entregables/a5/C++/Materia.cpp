#include "./Materia.h"
Materia::Materia(char nombre, char acronimo, char profesor,
                char diasClase, int horaInicio, int horaFin, int tareasEntregadas,
                int calificacionesActividades[], int calificacionesExamenes[]){
    fijaNombre(nombre);
    fijaAcronimo(acronimo);
    fijaProfesor(profesor);
    fijaDiasClase(diasClase);
    fijaHorario(horaInicio,horaFin);
    fijaTareasEntregadas(tareasEntregadas);
    fijaActividades(calificacionesActividades);
    fijaExamenes(calificacionesExamenes);
}

void Materia::fijaNombre(char nombre){
    this->nombre = nombre;
}
void Materia::fijaAcronimo(char acronimo){
    this->acronimo = acronimo;
}
void Materia::fijaProfesor(char nombre){
    this->profesor = nombre;
}
void Materia::fijaDiasClase(char diasClase){
    this->diasClase = diasClase;
}
void Materia::fijaHorario(int horaInicio, int horaFin){
    this->horaInicio = horaInicio;
    this->horaFin = horaFin;
}
void Materia::fijaTareasEntregadas(int cantidad){
    this->tareasEntregadas = cantidad;
}
void Materia::fijaActividades(int calificaciones[]){
    int i;
    for(i=0;i<9;i++){
       this->calificacionesActividades[i] = calificaciones[i];
    }
}
void Materia::fijaExamenes(int calificaciones[]){
    int i;
    for(i=0;i<3;i++){
       this->calificacionesExamenes[i] = calificaciones[i];
    }
}
char Materia::dameNombre(){
    return nombre;
}
char Materia::dameAcronimo(){
    return acronimo;
}
char Materia::dameProfesor(){
    return profesor;
}
char Materia::dameDiasClase(){
    return diasClase;
}
int Materia::dameHoraInicio(){
    return horaInicio;
}
int Materia::dameHoraFin(){
    return horaFin;
}
int Materia::dameTareasEntregadas(){
    return tareasEntregadas;
}
int Materia::dameCalificacionesActividades(){
    return calificacionesActividades[9];
}
int Materia::dameCalificacionesExamenes(){
    return calificacionesExamenes[3];
}
