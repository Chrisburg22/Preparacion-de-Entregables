
#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

#define CARACTERES_POR_FILA 80

using namespace std;
void centrarTexto( string texto, char relleno  );

int main () {
    centrarTexto("Hola Putines", '@');
    return 0;
}

void centrarTexto( string texto, char relleno ){
    int tamanioRelleno;

    tamanioRelleno = CARACTERES_POR_FILA - texto.length();

    for(int i=0 ; i < (tamanioRelleno/2) ; i++ ){
        cout << relleno;
    }

    cout << texto;

    for(int i=0 ; i < (tamanioRelleno/2) ; i++ ){
        cout << relleno;
    }

    cout << endl;

}