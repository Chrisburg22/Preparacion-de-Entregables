#include <stdio.h>

int main(){
    int a;
    short b;
    long c;
    char d;

    a=2147483647;
    b=32767;
    c=0x7fffffffffffffff;
    d=127;

    printf("a= %d\n", a);
    printf("b= %d\n", b);
    printf("c= %ld\n", c);
    printf("d= %d\n", d);

    a += 1;
    b += 1;
    c += 1;
    d += 1;

    printf("\na= %d\n", a);
    printf("b= %d\n", b);
    printf("c= %ld\n", c);
    printf("d= %d\n", d);
}