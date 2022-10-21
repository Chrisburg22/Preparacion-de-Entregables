#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(){
    int num, resultadoFactorial;
    num=10;
    resultadoFactorial = factorial(num);
    printf("%d\n",resultadoFactorial);
    return 0;
}

int factorial(int n){
    int resultadoFactorial;
    if(n==0){
        resultadoFactorial=1;
    } else if(n>0){
        do{
            resultadoFactorial = n * factorial(n-1);
        }while(n<=0);
    }
    return resultadoFactorial;
}