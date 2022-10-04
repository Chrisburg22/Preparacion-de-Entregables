#include <iostream>
#include <fstream>// Fuglo de datos hacia archivos
#include <sstream>


#define MAX_ALUMNOS 3
#define NOMBRE_ARCHIVO "Alumno.txt"
#define DELIMITADOR_CAMPOS ","

using namespace std;

struct  Alumno
{
    int codigo;
    string nombre;
};

Alumno alumnos[MAX_ALUMNOS];
int cuentaAlumnos;

void pausar();
bool registrarAlumnos();
void guardarAlumnos();
bool cargarAlumnos();
void listarAlumnos();

int main()
{
    cout << "Archivo de Texto con Registros" << endl;
    if(cargarAlumnos()){
        listarAlumnos();
    }
    if(registrarAlumnos()){
        guardarAlumnos();
    }
    return EXIT_SUCCESS;
}

void pausar(){
    cout << "Presione enter para continuar . . .";
    cin.ignore();
}



bool registrarAlumnos(){
    cout << endl << "Registro de Alumnos" << endl;
    if( cuentaAlumnos< MAX_ALUMNOS ){
        cout << "Registro #" << cuentaAlumnos << "." << endl;
        cout << "Dame el codigo: ";
        cin >> alumnos[cuentaAlumnos].codigo;
        cout << "Dame el nombre: ";
        cin >> alumnos[cuentaAlumnos++].nombre;
        cin.ignore();
        return true;
    } else {
        cout << endl << "No hay mas espacio para capturar" << endl << endl;
        return false;
    }
}

void guardarAlumnos(){
    ofstream archivo;

    cout << "Guardando archivo " << NOMBRE_ARCHIVO << endl;
    archivo.open(NOMBRE_ARCHIVO);

    if( archivo.is_open() ){
        
        for(int i=0 ; i<cuentaAlumnos ; i++){
            archivo << alumnos[i].codigo << DELIMITADOR_CAMPOS << alumnos[i].nombre;
            if(i!=cuentaAlumnos-1){
                archivo << endl;
            }
        }
        archivo.close();
    
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    pausar();
}




void listarAlumnos(){
    cout << endl << "Lista de Alumnos" << endl << endl;
    for(int i=0 ; i<cuentaAlumnos ; i++){
        cout << "Codigo    Nombre " << endl
        << alumnos[i].codigo << "      " << alumnos[i].nombre << endl << endl;
    }

}


bool cargarAlumnos(){
    ifstream archivo;// Salida o entrada de datos hacia archivos
    char separador;
    string cadena;

    cout << "Cargando archivo " << NOMBRE_ARCHIVO << endl;
    archivo.open( NOMBRE_ARCHIVO);

    if( archivo.is_open() ){


        while(!archivo.eof()){
            
            archivo >> alumnos[cuentaAlumnos].codigo;
            archivo >> separador;
            archivo >> alumnos[cuentaAlumnos++].nombre;
            cout << "Se leyo el archivo" << endl;
         }
         cout << "Hecho" << endl;
         archivo.close();
         return true;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }
}

