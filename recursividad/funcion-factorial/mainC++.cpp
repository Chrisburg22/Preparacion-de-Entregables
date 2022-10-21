#include <iostream>

using namespace std;

int factorial(int n);

int main(){
    int num,resultadoFactorial;
    num = 10;
    resultadoFactorial = factorial(num);
    cout << resultadoFactorial << endl;

    return 0;
}

int factorial(int n){
    int resultadoFactorial;
    
    do{
       if(n==0){
           resultadoFactorial=1;
       }else{
           resultadoFactorial= n * factorial(n-1);
       }
       n--;
    } while (n==0);
    return resultadoFactorial;
}