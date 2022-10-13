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
#define DELIMITADOR_CAMPOS ','
#define DELIMITADOR_REGISTROS '|'//Delimitador de registros

using namespace std;

struct  Alumno
{
    int codigo;
    string nombre;
    string genero;
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
    cout << "Archivo de Texto con Registros" << endl << endl;
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
    bool registroAlumno;
    cout << endl << "Registro de Alumnos" << endl;
    if( cuentaAlumnos<MAX_ALUMNOS ){
        cout << "Registro #" << cuentaAlumnos << "." << endl;
        cout << "Dame el codigo: ";
        cin >> alumnos[cuentaAlumnos].codigo;
        cin.ignore();
        cout << "Dame el nombre: ";
        getline(cin, alumnos[cuentaAlumnos].nombre);
        cout << "Dame el genero: ";
        cin >> alumnos[cuentaAlumnos++].genero;
        cin.get();
        registroAlumno = true;
    } else {
        cout << endl << "No hay mas espacio para capturar" << endl << endl;
        registroAlumno = false;
    }
    return registroAlumno;
}

void guardarAlumnos(){
    ofstream archivo;

    cout << "Guardando archivo " << NOMBRE_ARCHIVO << "...";
    archivo.open(NOMBRE_ARCHIVO, ios::out);

    if( archivo.is_open() ){
        
        archivo << cuentaAlumnos << DELIMITADOR_REGISTROS; //ENCABEZADO DEL ARCHIVO
        for(int i=0 ; i<cuentaAlumnos ; i++){
            archivo 
                << alumnos[i].codigo << DELIMITADOR_CAMPOS 
                << alumnos[i].nombre << DELIMITADOR_CAMPOS 
                << alumnos[i].genero  << DELIMITADOR_REGISTROS;
        }
        archivo.close();
        cout << endl <<"Hecho" << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    pausar();
}

void listarAlumnos(){
    cout << endl << "Lista de Alumnos" << endl << endl;
    for(int i=0 ; i<cuentaAlumnos ; i++){
        cout << "Codigo \t Nombre   Genero" << endl;
        cout << alumnos[i].codigo << "  \t" << alumnos[i].nombre << "  \t" << alumnos[i].genero << endl;
    }

}

bool cargarAlumnos(){
    ifstream archivo;// Salida o entrada de datos hacia archivos
    string cadena, subcadena;
    int posIni, posFin;
    char caracter;

    cout << "Cargando archivo " << NOMBRE_ARCHIVO << "..." << endl;
    archivo.open( NOMBRE_ARCHIVO, ios::in );

    if( archivo.is_open() ){
        
        archivo >> cuentaAlumnos;
        archivo >> caracter;

        for(int i=0; i<cuentaAlumnos ; i++){

            getline(archivo, cadena, DELIMITADOR_REGISTROS);
            cout << "Registro leido: " << cadena << endl;
            
            posIni = 0;
            posFin = cadena.find_first_of(DELIMITADOR_CAMPOS, posIni);
            subcadena = cadena.substr(posIni,posFin);
            cout << "Codigo: " << subcadena << endl;
            alumnos[i].codigo = convierteStringAint(subcadena);

            posIni = posFin+1;
            posFin = cadena.find_first_of(DELIMITADOR_CAMPOS, posIni);
            subcadena = cadena.substr(posIni, posFin-posIni);
            cout << "Nombre: " << subcadena << endl;
            alumnos[i].nombre = subcadena;

            
            caracter = cadena.at(posFin+1);//.at extrae un caracter de una cadena de texto, y recibe como parametro la posicion del caracter
            cout << "Genero: " << subcadena << endl;
            alumnos[i].genero = caracter;
         }
         cout << "Hecho!!" << endl;
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