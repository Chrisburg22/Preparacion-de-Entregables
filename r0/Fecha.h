#include <iostream>

using namespace std;

#ifndef FECHA_H // include guard
#define FECHA_H

#define MULTIPLO_4 4
#define MULTIPLO_100 100
#define MULTIPLO_400 400
enum {Enero=1, Febrero, Marzo , Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre}meses;

int codigoErrorFecha;

bool anioBisiesto(int anio);
bool validarFecha(int anio, int mes, int dia);
int dameCodigoErrorFecha();
void pausar();

bool anioBisiesto(int anio){
    int multCuatro, multCien, multCuatrocientos;
    bool esBiciesto;
    multCuatro = anio%MULTIPLO_4;
    multCien = anio&MULTIPLO_100;
    multCuatrocientos = anio%MULTIPLO_400;

    if((multCuatro==0&&multCien!=0)||(multCuatrocientos==0)){
        esBiciesto = true; 
    } 
    else{
        esBiciesto = false;
    }

    return esBiciesto;
}

bool validarFecha(int anio, int mes, int dia){
    bool fechaValida;

    if(mes==1){
        if((dia>0&&dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;
        }
    } else if(mes==2){
        if((dia>0)&&(dia<=28)||(dia==29&&anioBisiesto(anio))){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;
        }
    } else if(mes==3){
        if((dia>0)&&(dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;
        }
    } else if(mes==4){
       if((dia>0&&dia<=30)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;
        } 
    } else if(mes==5){
        if((dia>0&&dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;
        }
    }else if(mes==6){
        if((dia>0&&dia<=30)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;;
        }
    } else if(mes==7){
        if((dia>0&&dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;
        }
    } else if(mes==8){
        if((dia>0&&dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;
        }
    } else if(mes==9){
        if((dia>0&&dia<=30)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;;
        }
    } else if(mes==10){
       if((dia>0&&dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;
        } 
    } else if(mes==11){
        if((dia>0&&dia<=30)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;
        }
    } else if(mes==12){
        if((dia>0&&dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = true; //Bandera activada en true
        } else {
            fechaValida = false;
            codigoErrorFecha=-2;
        }
    } else{
        codigoErrorFecha = -1;
        fechaValida = false;
    }
    return fechaValida;
}

int dameCodigoErrorFecha(){
    return codigoErrorFecha;
}

void pausar(){
    cout << "Presione enter para continuar . . .";
    cin.ignore();
}

#endif /*FECHA_H*/
