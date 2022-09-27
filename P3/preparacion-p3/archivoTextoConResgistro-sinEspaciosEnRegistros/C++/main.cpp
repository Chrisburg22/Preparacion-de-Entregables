#include <iostream>
#include <fstream>// Fuglo de datos hacia archivos

#define NOMBRE_ARCHIVO "Reporte.txt"

void pausar();
void escribirArchivo();
void leerArchivo();

using namespace std;

int main()
{
    cout << "Escritura y lectura de archivos\n";
    escribirArchivo();
    leerArchivo();

    return EXIT_SUCCESS;
}

void pausar(){
    cout << "Presione enter para continuar . . .";
    cin.ignore();
}

void escribirArchivo(){
    ofstream archivo;
    string texto;
    cout << "Escritura del archivo " << NOMBRE_ARCHIVO << endl;
    archivo.open(NOMBRE_ARCHIVO);

    if( archivo.is_open() ){
        cout << "Que deseas escribir?" << endl;
        cin >> texto; // De esta manera escribimos pero sin especios en el string
        archivo << texto;
        cin.get();
       
        archivo.close();
        cout << "HECHO" << endl;

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    pausar();
}

void leerArchivo(){
    ifstream archivo;// Salida o entrada de datos hacia archivos
    string texto;
    cout << "Cargando archivo" << NOMBRE_ARCHIVO << endl;
    archivo.open( NOMBRE_ARCHIVO );

    if( archivo.is_open() ){
        archivo >> texto;
        cout << "Se leyo del archivo: " << NOMBRE_ARCHIVO << endl;
        cout << texto << endl;
        archivo.close();

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    pausar();
}