#include <iostream>
#include <fstream>// Fuglo de datos hacia archivos
#include <sstream>


#define MAX_ALUMNOS 3
#define NOMBRE_ARCHIVO "Alumno.txt"
#define DELIMITADOR_CAMPOS "|"

using namespace std;

struct  Alumno
{
    string nombre;
    int codigo;
};

Alumno alumnos[MAX_ALUMNOS];
int cuentaAlumnos;

void pausar();
bool registrarAlumnos();
void guardarAlumnos();
bool cargarAlumnos();
void listarAlumnos();
int convierteStringAInt(string s);


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
    if( cuentaAlumnos<MAX_ALUMNOS ){
        cout << "Registro #" << cuentaAlumnos << "." << endl;
        cout << "Dame el nombre: ";
        getline(cin,alumnos[cuentaAlumnos].nombre);
        cout << "Dame el codigo: ";
        cin >> alumnos[cuentaAlumnos++].codigo;
        return true;
    } else {
        cout << endl << "No hay mas espacio para capturar" << endl << endl;
    }
    return false;
}

void guardarAlumnos(){
    ofstream archivo;

    cout << "Guardando archivo " << NOMBRE_ARCHIVO << endl;
    archivo.open(NOMBRE_ARCHIVO);

    if( archivo.is_open() ){
        
        archivo << cuentaAlumnos << DELIMITADOR_CAMPOS << "Total" << endl; //ENCABEZADO DEL ARCHIVO
        for(int i=0 ; i<cuentaAlumnos ; i++){
            archivo << alumnos[i].nombre << DELIMITADOR_CAMPOS << alumnos[i].codigo << endl;
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
        << alumnos[i].codigo << "    " << alumnos[i].nombre << endl << endl;
    }

}


bool cargarAlumnos(){
    ifstream archivo;// Salida o entrada de datos hacia archivos
    char separador;
    string cadena, subCadena;
    int pos;

    cout << "Cargando archivo " << NOMBRE_ARCHIVO << endl;
    archivo.open( NOMBRE_ARCHIVO, ios::in );

    if( archivo.is_open() ){
        
        archivo >> cuentaAlumnos;
        getline( archivo, cadena );

        for(int i=0; i<cuentaAlumnos ; i++){
            stringstream ss;
            getline( archivo, cadena );
            cout << "Registro leido: " << cadena << endl;
            pos = cadena.find_first_of(DELIMITADOR_CAMPOS, 0);
            alumnos[i].nombre = subCadena = cadena.substr(0,pos);
            cout << "Nombre: " << subCadena << endl;
            subCadena = cadena.substr(pos+1);
            cout << "Codigo: " << subCadena << endl;
            ss << subCadena;
            ss >> alumnos[i].codigo;
            }
         cout << "Hecho" << endl;
         archivo.close();
         return true;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }
}


