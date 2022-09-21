#include <iostream>
#include <fstream>// Fuglo de datos hacia archivos

//#define NOMBRE_ARCHIVO "Reporte.txt"
#define NOMBRE_ARCHIVO "../../ecribir-archivo/test/Reporte.txt"

using namespace std;

int main()
{
    ifstream archivo;// Salida o entrada de datos hacia archivos
    string texto;
    cout << "Lectura de archivo " << NOMBRE_ARCHIVO << endl;
    archivo.open( NOMBRE_ARCHIVO );

    if( archivo.is_open() ){
        archivo >> texto;
        cout << texto << endl;
        cout << "Presiona enter para terminar. . ." << endl;
        cin.get();
        archivo.close();
        cout << "ECHO" << endl;

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    cout << "Presiona enter para terminar. . ." << endl;
    cin.get();

    return EXIT_SUCCESS;
}
