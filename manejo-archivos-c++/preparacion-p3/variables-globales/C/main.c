#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

#define MAX_INGRESOS 3

float ingresos[MAX_INGRESOS];
int cuentaIngresos;

void capturarIngresos();
void listarIngresos();
void pausar();

int main(){
    capturarIngresos();
    listarIngresos();
    capturarIngresos();
    listarIngresos();
    capturarIngresos();
    listarIngresos();

}
void capturarIngresos(){
    float ingreso;
    printf("Captura de ingreso\n");
    printf("Dame un ingreso mas: ");
    scanf("%f",&ingreso);
    pausar();
    ingresos[cuentaIngresos] = ingreso;
    cuentaIngresos ++;
    getchar;
    printf("\n");
}

void listarIngresos(){
    printf("Lista de ingresos\n");
    for( int i=0 ; i<3 ; i++ ){
        printf("ingresos[%d]= %f\n", i, ingresos[i]);
    }
    pausar();
}

void pausar(){
    printf("Presione enter para continuar . . .");
    getchar();
}