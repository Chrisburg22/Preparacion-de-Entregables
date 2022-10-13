#include <iostream>
#include <sstream>
#include <fstream>// Fuglo de datos hacia archivos

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif 

#define MAX_ALUMNOS 3
#define NOMBRE_ARCHIVO "Alumno.txt"
#define DELIMITADOR_CAMPOS ","
#define SALTO_DE_LINEA "\r\n"

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
int convierteStringAint(string s);


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
        cin >> alumnos[cuentaAlumnos].nombre;
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

    cout << "Guardando archivo " << NOMBRE_ARCHIVO << "...";
    archivo.open(NOMBRE_ARCHIVO, ios::out);

    if( archivo.is_open() ){
        
        archivo << cuentaAlumnos << DELIMITADOR_CAMPOS << "Total" << SALTO_DE_LINEA; //ENCABEZADO DEL ARCHIVO
        for(int i=0 ; i<cuentaAlumnos ; i++){
            archivo << alumnos[i].nombre << DELIMITADOR_CAMPOS << alumnos[i].codigo << SALTO_DE_LINEA;
        }
        archivo.close();
        cout << endl <<"Hecho" << SALTO_DE_LINEA;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    pausar();
}

void listarAlumnos(){
    cout << endl << "Lista de Alumnos" << endl << endl;
    for(int i=0 ; i<cuentaAlumnos ; i++){
        cout << alumnos[i].nombre << "\t" << alumnos[i].codigo << endl;
    }

}


bool cargarAlumnos(){
    ifstream archivo;// Salida o entrada de datos hacia archivos
    string cadena, subcadena;
    int pos;

    cout << "Cargando archivo " << NOMBRE_ARCHIVO << "..." << endl;
    archivo.open( NOMBRE_ARCHIVO, ios::in );

    if( archivo.is_open() ){
        
        archivo >> cuentaAlumnos;
        archivo >> cadena;

        for(int i=0; i<cuentaAlumnos ; i++){
            archivo >> cadena;
            cout << "Registro leido: " << cadena << endl;
            pos = cadena.find_first_of(DELIMITADOR_CAMPOS, 0);//retorna un entero, que son las posiciones recorridas de la posiscion 0 del array hasta encontrar el delimitador
            alumnos[i].nombre = subcadena = cadena.substr(0, pos);//extrae de la cadena de la pocion 0 a la posicion "pos"
            cout << "Nombre: " << subcadena << endl;//subcadena extraida de cadena
            subcadena = cadena.substr(pos+1);
            cout << "Codigo: " << subcadena << endl;
            alumnos[i].codigo = convierteStringAint(subcadena);
         }
         cout << "Hecho" << endl;
         archivo.close();
         return true;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }
}

int convierteStringAint(string s){
    stringstream ss;
    int i;
    ss << s;
    ss >> i;
    return i;
}