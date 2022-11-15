/**
 * NickName = DosTres
 * Calculo de impuesto anual
 * Tiempo = 05:30
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar la pantalla"
#endif
//Constantes 
#define CANTIDAD_MESES 12
#define IVA 16
#define RETENCION 10
#define PORCENTAJE 100
#define NOMBRE_ARCHIVO "impuestos.txt"
#define ARCHIVO_INGRESOS "INGRESOS.txt"
#define ARCHIVO_GASTOS "GASTOS.txt"
#define ARCHIVO_ISR "ISR.txt"
#define ARCHIVO_IVA "IVA.txt"

enum {ESTABLECER_MES=1,CAPTURAR_INGRESO,CAPTURAR_GASTOS, LISTAR_INGRESOS, 
      LISTAR_GASTO, CALCULAR_IMPUESTO_ANUAL, GUARDAR_ARCHIVO, SALIR} opcionesMenu;
      
enum {ENERO=1,FEBRERO,MARZO,ABRIL,MAYO,JUNIO,JULIO,AGOSTO,SEPTIEMBRE,
      OCTUBRE,NOVIEMBRE,DICIEMBRE} meses;

//Variables modificables por el usuario
float ingresos[CANTIDAD_MESES];
float gastos[CANTIDAD_MESES];
float  ingresosIVA, retencionISR, retencionIVA, subtotal, total;
float  gananciaBruta, gananciaBrutaISR, gananciaNeta;
float isrPagar, ganancia;
float gastoIva, pagarIva;
float gastoTotal, ingresoTotal;
std::string mesesAnio[12] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio",
                        "Agosto","Septiembre","Octubre","Noviembre","Diciembre"};

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

using namespace std;

int main(){
    int mes=1, opcionMenu;
    bool salir=true;
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
            salir = false;
            break;
        default:
            cout << "Opción no valida" << endl;
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
    cout  << "CÁLCULO DE IMPUESTOS ANUAL" << endl << endl
          << "Menú principal:" << endl
          << "1. Establecer mes para captura (mes actual es " << mesesAnio[mes-1] << ")" << endl
          << "2. Captura de ingresos" << endl
          << "3. Captura de gastos" << endl
          << "4. Mostrar lista de ingresos anual" << endl
          << "5. Mostrar lista de gastos anual" << endl
          << "6. Cálculo de impuestos anual" << endl
          << "7. Gurdar en archivo" << endl
          << "8. Salir" << endl
          << "Opción: ";
    cin >> opcion;
    return opcion;
}
int establecerMes(){
    int mes, i;
    system("CLEAR");
    cout << "Establecer mes para captura" << endl;
    //Imprimir meses 
    for(i=0;i<CANTIDAD_MESES ; i++){
        cout << i+1 << ") " << mesesAnio[i] << endl;
    }
    cout << "Elige el mes (1-12): ";
    cin >> mes;

    cout << "Se ha establecido el mes de captura en " << mesesAnio[mes-1] << endl;
    pausar();
    return mes;
}
void capturarIngreso(int mes){
    int ingreso;
    bool salir = true;
    cout << "Captura de ingresos" << endl; 
    do{
    cout << "Dame el ingreso de " << mesesAnio[mes-1] << ": ";
    cin >> ingreso;
    
        if(ingreso>0){
            ingresos[mes-1] = ingreso;
            salir=false;
        } else {
            cout << endl << "La cantidad debe ser mayor a 0" << endl;
        }
    }while(salir);
    pausar();
}
void capturarGasto(int mes){
    int gasto;
    bool salir=true;
    cout << "Captura de gasto" << endl; 
    do{
        cout << "Dame el gasto de " << mesesAnio[mes-1] << ": ";
        cin >> gasto;
        if( gasto>0 ){
            gastos[mes-1] = gasto;
            salir=false;
        } else {
            cout << endl << "La cantidad debe ser mayor a 0" << endl;
        }
    }while(salir);
    pausar();
}
void listarIngresos(){
    int i;
    system("CLEAR");
    cout << "Mostrar lista de ingresos anual" << endl;
    for ( i=0; i < CANTIDAD_MESES ; i++)
    {
        cout << mesesAnio[i] << "= " << fixed << setprecision(2) << ingresos[i] << endl;       
    }
}
void listarGastos(){
    int i;
    system("CLEAR");
    cout << "Mostrar lista de gastos anual" << endl;
    for ( i=0; i < CANTIDAD_MESES ; i++)
    {
        cout << mesesAnio[i] << "= " << fixed << setprecision(2) << gastos[i] << endl;        
    }
}
float calcularTotal(float arreglo[CANTIDAD_MESES]){
    int i;
    float total=0;
    for(i=0; i<CANTIDAD_MESES;i++){
        total += arreglo[i];
    }
    cout << total;
    return total;
}
void calcularTablaIngresos(int ingresoTotal){
    ingresosIVA = (ingresoTotal*(float)IVA)/PORCENTAJE;
    subtotal = ingresoTotal + ingresosIVA;
    retencionISR = (ingresoTotal*(float)RETENCION)/PORCENTAJE;
    retencionIVA = (ingresoTotal*(float)RETENCION)/PORCENTAJE;
    total = subtotal - (retencionISR+retencionIVA);
    cout << fixed << setprecision(2) 
         << "***Tabla Recibo de Hororarios***" << endl
         << left << "Ingresos               "<< right << setw(8) << ingresoTotal << endl
         << left << "(+) IVA                "<< right << setw(8) << ingresosIVA << endl
         << left << "(=) Subtotal           "<< right << setw(8) << subtotal << endl
         << left << "(-) Retencion ISR      "<< right << setw(8) << retencionISR << endl
         << left << "(-) Retencion IVA      "<< right << setw(8) << retencionIVA << endl
         << left << "(=) Total              "<< right << setw(8) << total << endl;
};
void calcularTablaGastos(int ingresoTotal, int gastoTotal){
    ganancia = calcularProcentajeIsr(ingresoTotal);
    gananciaBruta = ingresoTotal - gastoTotal;
    gananciaBrutaISR = (gananciaBruta*(float)ganancia)/PORCENTAJE;
    gananciaNeta = gananciaBruta - gananciaBrutaISR;
    cout << fixed << setprecision(2) 
         << left << "***Tabla Ganancias***  "<< endl
         << left << "Ingresos               "<< right << setw(8) << ingresoTotal << endl
         << left << "(-) Gastos             "<< right << setw(8) << gastoTotal << endl
         << left << "(=) Ganancia Brut      "<< right << setw(8) << gananciaBruta << endl
         << left << "(-) ISR                "<< right << setw(8) << gananciaBrutaISR << endl
         << left << "(=) Ganancia Neta      "<< right << setw(8) << gananciaNeta << endl;
}
void calcularTablaIsr(){
    isrPagar = gananciaBrutaISR - retencionISR;
    cout << fixed << setprecision(2) 
         << left << "***Tabla ISR***        "<< endl
         << left << "ISR                    "<< right << setw(8) << gananciaBrutaISR << endl
         << left << "(%) Porcentaje         "<< right << setw(8) << ganancia << endl
         << left << "(-) ISR Retenido       "<< right << setw(8) << retencionISR << endl
         << left << "(=) ISR a Pagar        "<< right << setw(8) << isrPagar << endl;
}
void calcularTablaIva(int gastoTotal){
    gastoIva = (gastoTotal*(float)IVA)/PORCENTAJE;
    pagarIva = ingresosIVA-gastoIva-retencionIVA;
    cout << fixed << setprecision(2) 
         << left << "***Tabla IVA***        "<< endl
         << left << "IVA                    "<< right << setw(8) << ingresosIVA << endl
         << left << "(-) Gastos IVA         "<< right << setw(8) << gastoIva << endl
         << left << "(-) Retencion IVA      "<< right << setw(8) << retencionIVA << endl
         << left << "(=) IVA a Pagar        "<< right << setw(8) << pagarIva << endl << endl;
}
void calcularImpuestoAnual(int ingresoTotal, int gastoTotal){
    cout << "CALCULO DE IMPUESTOS" << endl << endl;
    calcularTablaIngresos(ingresoTotal);
    calcularTablaGastos(ingresoTotal, gastoTotal);
    calcularTablaIsr();
    calcularTablaIva(gastoTotal);
    pausar();
}
void guardarTablaIngresos(){
    ofstream archivo;

    archivo.open(ARCHIVO_INGRESOS);
    if(archivo.is_open()){
        archivo << fixed << setprecision(2) << left 
                << "***Tabla Recibo de Hororarios***" << endl
                << setw(26) << "Ingresos"           << ingresoTotal << endl
                << setw(27) << "(+) IVA"             << ingresosIVA << endl
                << setw(26) << "(=) Subtotal"        << subtotal << endl
                << setw(27) << "(-) Retencion ISR"   << retencionISR << endl
                << setw(27) << "(-) Retencion IVA"   << retencionIVA << endl
                << setw(27) << "(=) Total"           << total << endl;
    } else {
        cout << "No se pudo crear el archivo" << endl;
    }
    archivo.close();
}
void guardarTablaGastos(){
    ofstream archivo;

    archivo.open(ARCHIVO_GASTOS);
    if(archivo.is_open()){
        archivo << fixed << setprecision(2) << left
                << "***Tabla Ganancias***"          << endl
                << setw(26) << "Ingresos"           << ingresoTotal << endl
                << setw(28) << "(-) Gastos"          << gastoTotal << endl
                << setw(27) << "(=) Ganancia Bruta"  << gananciaBruta << endl
                << setw(27) << "(-) ISR"             << gananciaBrutaISR << endl
                << setw(27) << "(=) Ganancia Neta"      << gananciaNeta << endl;
    } else {
        cout << "No se pudo crear el archivo" << endl;
    }
    archivo.close();
}
void guardarTablaIsr(){
    ofstream archivo;

    archivo.open(ARCHIVO_ISR);
    if(archivo.is_open()){
        archivo << fixed << setprecision(2) << left
                << "***Tabla ISR***"                << endl
                << setw(27) << "ISR"                << gananciaBrutaISR << endl
                << setw(27) << "(-) ISR Retenido"    << retencionISR << endl
                << setw(29) << "(=) ISR a Pagar"     << isrPagar << endl;
    } else {
        cout << "No se pudo crear el archivo" << endl;
    }
    archivo.close();
}
void guardarTablaIva(){
    ofstream archivo;

    archivo.open(ARCHIVO_IVA);
    if(archivo.is_open()){
        archivo << fixed << setprecision(2) << left 
                << "***Tabla IVA***"                 << endl
                << setw(27) << "IVA"                 << ingresosIVA << endl
                << setw(29) << "(-) Gastos IVA"      << gastoIva << endl
                << setw(27) << "(-) Retencion IVA"   << retencionIVA << endl
                << setw(28) << "(=) IVA a Pagar"     << pagarIva << endl << endl;
    } else {
        cout << "No se pudo crear el archivo" << endl;
    }
    archivo.close();
}
void crearArchivos(){
    guardarTablaIngresos();
    guardarTablaGastos();
    guardarTablaIsr();
    guardarTablaIva();
}
void guardarTablaImpuestoAnual(){
    ofstream archivo;

    archivo.open(NOMBRE_ARCHIVO);
    
    if(archivo.is_open()){
        archivo << fixed << setprecision(2) 
         << "CALCULO DE IMPUESTOS" << endl << endl
         << left << endl
         << "***Tabla Recibo de Hororarios***" << endl
         << setw(26) << "Ingresos"           << ingresoTotal << endl
         << setw(27) << "(+) IVA"             << ingresosIVA << endl
         << setw(26) << "(=) Subtotal"        << subtotal << endl
         << setw(27) << "(-) Retencion ISR"   << retencionISR << endl
         << setw(27) << "(-) Retencion IVA"   << retencionIVA << endl
         << setw(27) << "(=) Total"           << total << endl
         << "***Tabla Ganancias***"          << endl
         << setw(26) << "Ingresos"           << ingresoTotal << endl
         << setw(28) << "(-) Gastos"          << gastoTotal << endl
         << setw(27) << "(=) Ganancia Bruta"  << gananciaBruta << endl
         << setw(27) << "(-) ISR"             << gananciaBrutaISR << endl
         << setw(27) << "(=) Ganancia Neta"      << gananciaNeta << endl
         << "***Tabla ISR***"                << endl
         << setw(27) << "ISR"                << gananciaBrutaISR << endl
         << setw(27) << "(-) ISR Retenido"    << retencionISR << endl
         << setw(29) << "(=) ISR a Pagar"     << isrPagar << endl
         << "***Tabla IVA***"                << endl
         << setw(27) << "IVA"                << ingresosIVA << endl
         << setw(29) << "(-) Gastos IVA"      << gastoIva << endl
         << setw(27) << "(-) Retencion IVA"   << retencionIVA << endl
         << setw(28) << "(=) IVA a Pagar"    << pagarIva << endl << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}
int calcularProcentajeIsr(float ingresoTotal){
    int porcentaje;
    
    if(ingresoTotal>20000.01){
        porcentaje = 20;
    } else if(ingresoTotal>10000.01){
        porcentaje = 15;
    } else{
        porcentaje = 11;
    }
    return porcentaje;
}
void pausar(){
    cin.ignore();
    cout << "Presione enter para continuar . . ." << endl;
    cin.ignore();
}

