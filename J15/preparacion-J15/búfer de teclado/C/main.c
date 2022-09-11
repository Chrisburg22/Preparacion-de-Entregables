#include <stdio.h>
#include <stdlib.h>

int main() {
    char estasEntendiendoTodo, deVerdadEntiendeTodo;
    printf("Estas entendiendo todo (S/N) ? ");
    scanf("%c", &estasEntendiendoTodo);
    getchar();
    printf("Tu respuesta es -%c-\n", estasEntendiendoTodo);
    printf("De verdad entiendes todo (S/N) ? ");
    scanf("%c", &deVerdadEntiendeTodo);
    printf("Dices que -%c- \n", deVerdadEntiendeTodo);

    return 0;
}
