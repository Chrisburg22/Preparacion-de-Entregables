<<<<<<< HEAD
#include <iostream>
#include <fstream>// FlUJo de datos hacia archivos

//#define NOMBRE_ARCHIVO "C:users/'Melisa Ramos'/'OneDrive - Universidad de Guadalajara'/'Estructura de Datos 2'/ejercicios-youtube/'Preparacion de Entregables'/Practica2/preparacion-practica2/ecribir-archivo/test/Reporte.txt"
#define NOMBRE_ARCHIVO "../test/Reporte.txt"

using namespace std;

int main()
{
    ofstream archivo;// Salida o entrada de datos hacia archivos
    string texto;
    //string path = "../test/Reporte.txt";
    cout << "Escritura del archivo " << NOMBRE_ARCHIVO << endl;
    archivo.open(NOMBRE_ARCHIVO);//Al terminar este linea el archivo a diso creado
    cout << "Presiona enter para continuar . . ." << endl;
    cin.get();
    /*Siempre hay que verificar que el archivo se haya podido abrir
     pues el nombre del archivo podria ser incorrecto o usar una ruta USB y no estar disponible
    */
    if( archivo.is_open() ){
        cout << "Que deseas escribir?" << endl;
        cin >> texto; // De esta manera escribimos pero sin especios en el string
        archivo << texto;
        cin.get();
        /*
        cout << "Presiona enter para continuar . . ." << end;
        cin.get();
        */
        archivo.close();
        cout << "ECHO" << endl;

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    cout << "Presiona enter para terminar. . ." << endl;
    cin.get();

    return EXIT_SUCCESS;
}
=======
#include <iostream>
#include <fstream>// FlUJo de datos hacia archivos

//#define NOMBRE_ARCHIVO "C:users/'Melisa Ramos'/'OneDrive - Universidad de Guadalajara'/'Estructura de Datos 2'/ejercicios-youtube/'Preparacion de Entregables'/Practica2/preparacion-practica2/ecribir-archivo/test/Reporte.txt"
#define NOMBRE_ARCHIVO "../test/Reporte.txt"

using namespace std;

int main()
{
    ofstream archivo;// Salida o entrada de datos hacia archivos
    string texto;
    //string path = "../test/Reporte.txt";
    cout << "Escritura del archivo " << NOMBRE_ARCHIVO << endl;
    archivo.open(NOMBRE_ARCHIVO);//Al terminar este linea el archivo a diso creado
    cout << "Presiona enter para continuar . . ." << endl;
    cin.get();
    /*Siempre hay que verificar que el archivo se haya podido abrir
     pues el nombre del archivo podria ser incorrecto o usar una ruta USB y no estar disponible
    */
    if( archivo.is_open() ){
        cout << "Que deseas escribir?" << endl;
        cin >> texto; // De esta manera escribimos pero sin especios en el string
        archivo << texto;
        cin.get();
        /*
        cout << "Presiona enter para continuar . . ." << end;
        cin.get();
        */
        archivo.close();
        cout << "ECHO" << endl;

    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    cout << "Presiona enter para terminar. . ." << endl;
    cin.get();

    return EXIT_SUCCESS;
}
>>>>>>> 6b4ddcdec1fd95e40d8ad5eda93e4856333ec062
