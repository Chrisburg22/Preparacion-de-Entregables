/**
 * Nickname = DosTres
 * PRACTICA 3
 * Calculo de impusto anual
 * TiempoTranscripción: 00:00
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

//IVA=0.16%  Retencion=0.10% Ganancia=0.11%
#define CANTIDAD_MESES 12
#define IVA 16
#define RETENCION 10
#define PORCENTAJE 100
#define NOMBRE_ARCHIVO "impuestos.txt"
#define ARCHIVO_INGRESOS "INGRESOS.txt"
#define ARCHIVO_GASTOS "GASTOS.txt"
#define ARCHIVO_ISR "ISR.txt"
#define ARCHIVO_IVA "IVA.txt"

typedef enum{VERDADERO, FALSO} boolean;
typedef enum {ESTABLECER_MES=1,CAPTURAR_INGRESO,CAPTURAR_GASTOS, LISTAR_INGRESOS, 
      LISTAR_GASTO, CALCULAR_IMPUESTO_ANUAL, GUARDAR_ARCHIVO, SALIR} opcionesMenu;
typedef enum{ENERO=1,FEBRERO,MARZO,ABRIL,MAYO,JUNIO,JULIO,AGOSTO,SEPTIEMBRE,
      OCTUBRE,NOVIEMBRE,DICIEMBRE} meses;
//Variables modificables por el usuario
float ingresos[CANTIDAD_MESES];
float gastos[CANTIDAD_MESES];
float  ingresosIVA, retencionISR, retencionIVA, subtotal, total;
float  gananciaBruta, gananciaBrutaISR, gananciaNeta;
float isrPagar, ganancia;
float gastoIva, pagarIva;
float gastoTotal, ingresoTotal;


//Funciones 
int menuPrincipal(int mes);
void inicializarPrograma();
int establecerMes();
void capturarIngreso(int mes);
void capturarGasto(int mes);
void listarIngresos();
void listarGastos();
float calcularTotal(float arreglo[CANTIDAD_MESES]);
void calcularImpuestoAnual(int ingresoTotal, int gastoTotal);
void calcularTablaIngresos(int ingresoTotal);
void calcularTablaGastos(int ingresoTotal, int gastoTotal);
void calcularPorcentajeIsr();
void calcularTablaIsr();
void calcularTablaIva(int gastoTotal);
void guardarTablaIngresos();
void guardarTablaGastos();
void guardarTablaIsr();
void guardarTablaIva();
void guardarTablaImpuestoAnual();
void crearArchivos();
int calcularProcentajeIsr(float ingresoTotal);
void pausar();

int main(){
    int mes=1, opcionMenu;
    boolean salir;
    float gastoTotal,ingresoTotal;
    inicializarPrograma();
    do{
        gastoTotal = calcularTotal(gastos);
        ingresoTotal = calcularTotal(ingresos);
        opcionMenu = menuPrincipal(mes);
        switch (opcionMenu){
        case ESTABLECER_MES:
            mes = establecerMes();
            break;
        case CAPTURAR_INGRESO:
            capturarIngreso(mes);
            break;
        case CAPTURAR_GASTOS:
            capturarGasto(mes);
            break;
        case LISTAR_INGRESOS:
            listarIngresos();
            pausar();
            break;
        case LISTAR_GASTO:
            listarGastos();
            pausar();
            break;
        case CALCULAR_IMPUESTO_ANUAL:
            calcularImpuestoAnual(ingresoTotal,gastoTotal);
            break;
        case GUARDAR_ARCHIVO:
            crearArchivos();
            break;
        case SALIR:
            salir = FALSO;
            break;
        default:
            printf("Opción no valid\n");
            break;
        }

    }while(salir);
    return 0;
}

void inicializarPrograma(){
    int i;
    for(i=0; i<CANTIDAD_MESES ;  i++ ){
        ingresos[i] = 0;
        gastos[i] = 0;
    }
    ingresosIVA=0; 
    retencionISR=0;
    retencionIVA=0;
    subtotal=0;
    total=0;
    gananciaBruta=0;
    gananciaBrutaISR=0;
    gananciaNeta=0;
    isrPagar=0;
    gastoIva=0;
    pagarIva=0;
    gastoTotal=0;
    ingresoTotal=0;
}

int menuPrincipal(int mes){
    int opcion;
    system("CLEAR");
    printg("CÁLCULO DE IMPUESTOS ANUAL\n\n");
    printg("Menú principal:\n");
    printg("1. Establecer mes para captura (mes actual es %.2f)", mesesAnio[mes-1]);
    printg("2. Captura de ingresos");
    printg("3. Captura de gastos");
    printg("4. Mostrar lista de ingresos anual");
    printg("5. Mostrar lista de gastos anual");
    printg("6. Cálculo de impuestos anual");
    printg("7. Gurdar en archivo");
    printg("8. Salir");
    printg("Opción: ";
    cin >> opcion;
    return opcion;
}