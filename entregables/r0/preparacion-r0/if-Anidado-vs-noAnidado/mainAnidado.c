#include <stdio.h>
#include <stdlib.h>

int main(){
    int promedio=0;
    printf("Cual es el promedio actual? ");
    scanf("%d", &promedio);

    printf("El promedio capturado es %d\n\n", promedio);
    
    if((promedio>=60)&&(promedio<80)){

        if((promedio>=95)&&(promedio<=100)){
            printf("Excelente, si continuas asi te puedes titular por excelencia academica");
        } 
        else if((promedio>=90)&&(promedio<=95)){
            printf("Muy bien, si continuas asi te titularas por promedio");
        }
        else if((promedio>=85)&&(promedio<=90)){
            printf("Bien, pero te conviene estar mas cerca del 90 por aquello de un semestre dificil");
        }
        else if((promedio>=80)&&(promedio<=85)){
            printf("Cuidado!, si bajas no podras aspirar a una maestria de excelencia nacional o extrangera");
        }
        else {
            printf("Si no subes tu promedio arriba de 80, estaras condenado a ser un licenciado(si acaso) el resto de tu vida\n");
            printf("Te conviene llevar el minimo de creditos para subir promedio\n");
        }    
    }
    else{
        printf("Hay que contemplar todas las opciones, pos eso este \"else\"\n");
    }
    printf("\n\n Recuerda que por promedio se eligen: \n");
    printf("Los mejores profesores, los mejores horarios, las mejores plazas para sevicio social\n");
    printf("Los mejores posgrados, ect\n");
    printf("Te sera mejor titularte si haces una tesis\n");
    return 0;
}