#ifndef FECHA_H // include guard
#define FECHA_H

#define MULTIPLO_4 4
#define MULTIPLO_100 100
#define MULTIPLO_400 400

typedef enum {Enero=1, Febrero, Marzo , Abril, Mayo, Junio, Julio, Agosto, Septiembre, Octubre, Noviembre, Diciembre}meses;
typedef enum{FALSO,VERDADERO}booleno;

int codigoErrorFecha;

int anioBisiesto(int anio);
int validarFecha(int anio, int mes, int dia);
int dameCodigoErrorFecha();
void pausar();

int anioBisiesto(int anio){
    int multCuatro, multCien, multCuatrocientos;
    booleno esBiciesto;
    multCuatro = anio%MULTIPLO_4;
    multCien = anio&MULTIPLO_100;
    multCuatrocientos = anio%MULTIPLO_400;

    if((multCuatro==0&&multCien!=0)||(multCuatrocientos==0)){
        esBiciesto = VERDADERO; 
    } 
    else{
        esBiciesto = FALSO;
    }

    return esBiciesto;
}

int validarFecha(int anio, int mes, int dia){
    booleno fechaValida;

    switch(mes)
    {
    case 1:
        if((dia>0)&&(dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;
            fechaValida = FALSO;
        }
        break;
    case 2:
        if((dia>0)&&(dia<=28)||(dia==29&&anioBisiesto(anio))){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;
            fechaValida = FALSO;
        }
        break;
    case 3:
        if((dia>0)&&(dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;
            fechaValida = FALSO;
        }
        break;
    case 4:
        if((dia>0)&&(dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;
            fechaValida = FALSO;
        }
        break;
    case 5:
        if((dia>0)&&(dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;
            fechaValida = FALSO;
        }
        break;
    case 6:
        if((dia>0)&&(dia<=30)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;;
            fechaValida = FALSO;
        }
        break;
    case 7:
        if((dia>0)&&(dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;
            fechaValida = FALSO;
        }
        break;
    case 8:
        if((dia>)0&&(dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;
            fechaValida = FALSO;
        }
        break;
    case 9:
        if((dia>0)&&(dia<=30)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;;
            fechaValida = FALSO;
        }
        break;    
    case 10:
        if((dia>0)&&(dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;
            fechaValida = FALSO;
        }
        break;
    case 11:
        if((dia>0)&&(dia<=30)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;
            fechaValida = FALSO;
        }
        break;
    case 12:
        if((dia>0)&&(dia<=31)){
            codigoErrorFecha=0; // Fecha valida
            fechaValida = VERDADERO; //Bandera activada en true
        } else {
            codigoErrorFecha=-2;
            fechaValida = FALSO;
        }
        break;                
    default:
        codigoErrorFecha = -1;
        fechaValida = FALSO;
        break;
    }
    
    return fechaValida;
}

int dameCodigoErrorFecha(){
    return codigoErrorFecha;
}

#endif /*FECHA_H*/
