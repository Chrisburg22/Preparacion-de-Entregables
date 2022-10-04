#include <stdio.h>

int main(){
    int a;
    short b;
    long c;
    char d;

    a=2147483647;
    b=32767;
    c=0x7fffffffffffffff;

    printf("a = %d\n", a);
    printf("b= %d\n", b);
    printf("c= %ld\n", c);
    printf("d= %d\n", d);
}