#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

//Declaracion de Constantes simbolicas
#define IVA 16
#define RETENCION 10
#define GANANCIA 11
#define PORCENTAJE 100
#define NOMBRE_ARCHIVO "impuestos.txt"

using namespace std;

int main(){
    //Declaracion de Variables 
    //Datos Ingresos
    float ingresos, ingresosIVA, retencionISR, retencionIVA, subtotal, total;
    //Datos Gastos
    float gastos, gananciaBruta, gananciaBrutaISR, gananciaNeta;
    //Datos ISR
    float ISRPagar;
    //Datos IVA
    float gastoIVA, pagarIVA;
    ofstream archivo;

    cout << "CALCULO DE IMPUESTOS" << endl << endl;
    cout << "Dame el ingreso: ";
    cin >> ingresos;// ENTRADA DE DATOS
    cin.ignore();
    cout << "Dame el gasto: ";
    cin >> gastos;
    cin.ignore();
    system(CLEAR);

//CALCULO DE IMPUESTOS
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

//IMPRECION EN CONSOLA
    cout << fixed << setprecision(2) 
         << "CALCULO DE IMPUESTOS" << endl << endl
         << "***Tabla Recibo de Hororarios***" << endl
         << left << "Ingresos               "<< right << setw(8) << ingresos << endl
         << left << "(+) IVA                "<< right << setw(8) << ingresosIVA << endl
         << left << "(=) Subtotal           "<< right << setw(8) << subtotal << endl
         << left << "(-) Retencion ISR      "<< right << setw(8) << retencionISR << endl
         << left << "(-) Retencion IVA      "<< right << setw(8) << retencionIVA << endl
         << left << "(=) Total              "<< right << setw(8) << total << endl
         << left << "***Tabla Ganancias***  "<< endl
         << left << "Ingresos               "<< right << setw(8) << ingresos << endl
         << left << "(-) Gastos             "<< right << setw(8) << gastos << endl
         << left << "(=) Ganancia Brut      "<< right << setw(8) << gananciaBruta << endl
         << left << "(-) ISR                "<< right << setw(8) << gananciaBrutaISR << endl
         << left << "(=) Ganancia Neta      "<< right << setw(8) << gananciaNeta << endl
         << left << "***Tabla ISR***        "<< endl
         << left << "ISR                    "<< right << setw(8) << gananciaBrutaISR << endl
         << left << "(-) ISR Retenido       "<< right << setw(8) << retencionISR << endl
         << left << "(=) ISR a Pagar        "<< right << setw(8) << ISRPagar << endl
         << left << "***Tabla IVA***        "<< endl
         << left << "IVA                    "<< right << setw(8) << ingresosIVA << endl
         << left << "(-) Gastos IVA         "<< right << setw(8) << gastoIVA << endl
         << left << "(-) Retencion IVA      "<< right << setw(8) << retencionIVA << endl
         << left << "(=) IVA a Pagar        "<< right << setw(8) << pagarIVA << endl << endl;

    cout << "Presiona enter para contuniar . . ." ;
    getchar();

    cout << endl << "Guardando archivo " << NOMBRE_ARCHIVO << endl;
    archivo.open(NOMBRE_ARCHIVO);
    cout << "Presiona enter para contuniar . . ." ;
    getchar();

    if(archivo.is_open()){
        archivo << fixed << setprecision(2) 
         << "CALCULO DE IMPUESTOS" << endl << endl
         << left << endl
         << "***Tabla Recibo de Hororarios***" << endl
         << setw(26) << "Ingresos"           << ingresos << endl
         << setw(27) << "(+) IVA"             << ingresosIVA << endl
         << setw(26) << "(=) Subtotal"        << subtotal << endl
         << setw(27) << "(-) Retencion ISR"   << retencionISR << endl
         << setw(27) << "(-) Retencion IVA"   << retencionIVA << endl
         << setw(27) << "(=) Total"           << total << endl
         << "***Tabla Ganancias***"          << endl
         << setw(26) << "Ingresos"           << ingresos << endl
         << setw(28) << "(-) Gastos"          << gastos << endl
         << setw(27) << "(=) Ganancia Bruta"  << gananciaBruta << endl
         << setw(27) << "(-) ISR"             << gananciaBrutaISR << endl
         << setw(27) << "(=) Ganancia Neta"      << gananciaNeta << endl
         << "***Tabla ISR***"                << endl
         << setw(27) << "ISR"                << gananciaBrutaISR << endl
         << setw(27) << "(-) ISR Retenido"    << retencionISR << endl
         << setw(29) << "(=) ISR a Pagar"     << ISRPagar << endl
         << "***Tabla IVA***"                << endl
         << setw(27) << "IVA"                << ingresosIVA << endl
         << setw(29) << "(-) Gastos IVA"      << gastoIVA << endl
         << setw(27) << "(-) Retencion IVA"   << retencionIVA << endl
         << setw(28) << "(=) IVA a Pagar"    << pagarIVA << endl << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();

}

