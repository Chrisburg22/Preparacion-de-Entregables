#include <stdio.h>
#include <stdlib.h>

#define TORRE_INICIAL 1
#define TORRE_AUXILIAR 2
#define TORRE_FINAL 3


void llenarTorres(int* torre1[], int* torre2[], int* torre3[], int numeroDiscos);
int pop(int* torre[]);
void push(int valor, int* torre[]);
int hanoi(int numDiscos, int* torreInicial[], int* torreAuxiliar[], int* torreFinal[],
                    int  posTorreInicial, int posTorreAuxiliar, int posTorreFinal);


int main()
{
	
    int cantDiscos, totalMovimientos;
	printf("Cantidad de discos a mover: ");
	scanf("%d", &cantDiscos);
	int* torre1[cantDiscos];
	int* torre2[cantDiscos];
	int* torre3[cantDiscos];

	llenarTorres(torre1, torre2, torre3,cantDiscos);
	printf("\nLa serie de movimientos a realizar es: \n\n");
	printf("Discos al inicio, se muestra el diametro de los discos:\n");
	totalMovimientos = hanoi(cantDiscos, torre1, torre2, torre3,
	                         TORRE_INICIAL,TORRE_AUXILIAR,TORRE_FINAL);
	printf("\nSe realizaron en total %d movimientos\n", totalMovimientos);
	return 0;
}

void llenarTorres(int* torre1[], int* torre2[], int* torre3[], int numeroDiscos){
	int posicion = 0, i;

	for(i=numeroDiscos; i>0 ; i--){
		torre1[posicion] = &i;
		torre2[posicion] = 0;
		torre3[posicion] = 0;
		posicion++;
	}
}

int pop(int* torre[]){
	int salir, i, auxiliar;
	i=0;
	do{
		if(!torre[i]){
			salir = 0;
		} else if( (torre[i]>torre[i+1]) && (!torre[i+1]) ){
			auxiliar = *torre[i];
			*torre[i] = 0;
			salir = 0;
			salir = 0;
		} else{
			i++;
		}
	}while(salir);
	return auxiliar;	
}

void push(int valor, int* torre[]){
	int i, salir;
	i=0;
	do{
		if(*torre[i]<=0){
			torre[i] = &valor;
			salir = 0;
		} else {
			
			if( *torre[i]>valor ){
				torre[i+1] = &valor;
				salir = 0;
			} else{
				i++;
			}
		}
	}while(salir);
}

int hanoi(int numDiscos, int* torreInicial[], int* torreAuxiliar[], int* torreFinal[],
                         int  posTorreInicial, int posTorreAuxiliar, int posTorreFinal)
{
    static int totalMovimientos = 0;
	int auxiliar;
	if(numDiscos == 1) // solo hay un disco
	{
		printf("Mover el disco superior de la torre %d a la torre %d\n", posTorreInicial, posTorreFinal);
		auxiliar = pop(torreInicial);
		push(auxiliar, torreFinal);
		totalMovimientos++;
	}
	else // mas de un disco
	{
		hanoi(numDiscos - 1, torreInicial,torreFinal,torreAuxiliar,
		       posTorreInicial, posTorreFinal, posTorreAuxiliar);
		printf("Mover el disco superior de la torre %d a la torre %d\n", posTorreInicial, posTorreFinal);
		auxiliar = pop(torreInicial);
		push(auxiliar, torreFinal);
		hanoi(numDiscos - 1, torreAuxiliar, torreInicial, torreFinal,
		        posTorreAuxiliar, posTorreInicial, posTorreFinal);
	}
	//if(numDiscos>0){
	//	hanoi(numDiscos-1,torreInicial, torreFinal, torreAuxiliar);
	//	printf("\nMueve el anillo desde la torre %d hasta la torre %d", torreInicial, torreAuxiliar);
	//	totalMovimientos++;
	//	hanoi(numDiscos-1, torreFinal, torreAuxiliar, torreInicial);
	//}
	return totalMovimientos;
}

