#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

//IVA=0.16%  Retencion=0.10% Ganancia=0.11%
#define IVA 16
#define RETENCION 10
#define GANANCIA 11
#define NOMBRE_ARCHIVO "impuestos.txt"
#define PORCENTAJE 100

int main(){
    //Declaracion de las Variables
    FILE *archivo;
    //Datos Ingresos
    float ingresos, ingresosIVA, retencionISR, retencionIVA, subtotal, total;
    //Datos Gastos
    float gastos, gananciaBruta, gananciaBrutaISR, gananciaNeta;
    //Datos ISR
    float ISRPagar;
    //Datos IVA
    float gastoIVA, pagarIVA; 

    printf("CALCULO DE IMPUESTOS\n\n");
    printf("Dame el ingreso: ");
    scanf("%f",&ingresos); // Entrada de datos e inicializacion 
    getchar();
    printf("Dame el gasto: ");
    scanf("%f",&gastos);// Entrada de datos e inicializacion 
    getchar();

//CALCULO DE LOS IMPUESTOS
//TABLA DE INGRESOS
    ingresosIVA = (ingresos*(float)IVA)/PORCENTAJE;
    subtotal = ingresos + ingresosIVA;
    retencionISR = (ingresos*(float)RETENCION)/PORCENTAJE;
    retencionIVA = (ingresos*(float)RETENCION)/PORCENTAJE;
    total = subtotal - (retencionISR+retencionIVA);

//TABLA DE GANANCIAS
    gananciaBruta = ingresos - gastos;
    gananciaBrutaISR = (gananciaBruta*(float)GANANCIA)/PORCENTAJE;
    gananciaNeta = gananciaBruta - gananciaBrutaISR;

//Tabla ISR
    ISRPagar = gananciaBrutaISR - retencionISR;

//Tebla del IVA
    gastoIVA = (gastos*(float)IVA)/PORCENTAJE;
    pagarIVA = ingresosIVA-gastoIVA-retencionIVA;

//SALIDA DE DATOS
    printf("Calculo de impuestos\n\n");
    printf("***Tabla Recibo de Honorarios***\n");
    printf("Ingresos                 %8.2f\n", ingresos);
    printf("(+) IVA                  %8.2f\n", ingresosIVA);
    printf("(=) Subtotal             %8.2f\n", subtotal);
    printf("(-) Retencion ISR        %8.2f\n", retencionISR);
    printf("(-) Retencion IVa        %8.2f\n", retencionIVA);
    printf("(=) Total                %8.2f\n", total);
    printf("***Tabla de Ganancias***\n");
    printf("Ingresos                 %8.2f\n", ingresos);
    printf("(-) Gastos               %8.2f\n", gastos);
    printf("(=) Ganancia Bruta       %8.2f\n", gananciaBruta);
    printf("(-) ISR                  %8.2f\n", gananciaBrutaISR);
    printf("(=) Ganancia Neta        %8.2f\n", gananciaNeta);
    printf("***Tabla ISR***\n");
    printf("ISR                      %8.2f\n", gananciaBrutaISR);
    printf("(-) ISR Retenido         %8.2f\n", retencionISR);
    printf("(=) ISR a Pagar          %8.2f\n", ISRPagar);
    printf("***Tabla IVA***\n");
    printf("IVA                      %8.2f\n", ingresosIVA);
    printf("(-) Gastos IVA           %8.2f\n", gastoIVA);
    printf("(-) Retencion IVa        %8.2f\n", retencionIVA);
    printf("(=) IVA a Pagar          %8.2f\n", pagarIVA);
    printf("Presiona enter para terminar ...");
    getchar();

    archivo = fopen(NOMBRE_ARCHIVO, "w");
    
    if(archivo==NULL){
        printf("No existe en el archivo");
    } else{
        printf("Guardando el archivo %s\n", NOMBRE_ARCHIVO);
        fprintf(archivo, "Calculo de impuestos\n\n");
        fprintf(archivo, "***Tabla Recibo de Honorarios***\n");
        fprintf(archivo, "Ingresos                 %8.2f\n", ingresos);
        fprintf(archivo, "(+) IVA                  %8.2f\n", ingresosIVA);
        fprintf(archivo, "(=) Subtotal             %8.2f\n", subtotal);
        fprintf(archivo, "(-) Retencion ISR        %8.2f\n", retencionISR);
        fprintf(archivo, "(-) Retencion IVa        %8.2f\n", retencionIVA);
        fprintf(archivo, "(=) Total                %8.2f\n", total);
        fprintf(archivo, "***Tabla de Ganancias***\n");
        fprintf(archivo, "Ingresos                 %8.2f\n", ingresos);
        fprintf(archivo, "(-) Gastos               %8.2f\n", gastos);
        fprintf(archivo, "(=) Ganancia Bruta       %8.2f\n", gananciaBruta);
        fprintf(archivo, "(-) ISR                  %8.2f\n", gananciaBrutaISR);
        fprintf(archivo, "(=) Ganancia Neta        %8.2f\n", gananciaNeta);
        fprintf(archivo, "***Tabla ISR***\n");
        fprintf(archivo, "ISR                      %8.2f\n", gananciaBrutaISR);
        fprintf(archivo, "(-) ISR Retenido         %8.2f\n", retencionISR);
        fprintf(archivo, "(=) ISR a Pagar          %8.2f\n", ISRPagar);
        fprintf(archivo, "***Tabla IVA***\n");
        fprintf(archivo, "IVA                      %8.2f\n", ingresosIVA);
        fprintf(archivo, "(-) Gastos IVA           %8.2f\n", gastoIVA);
        fprintf(archivo, "(-) Retencion IVa        %8.2f\n", retencionIVA);
        fprintf(archivo, "(=) IVA a Pagar          %8.2f\n", pagarIVA);
        printf("Presiona enter para terminar ... ");
        getchar();
        fclose(archivo);
    }
    
    return 0;
}