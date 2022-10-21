/**
 * DosTres
 * TrasTiempo: 
*/
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <string>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

using namespace std;

#define MAX_MATERIAS 15
#define MAX_REQUISITOS 3
#define TAMANIO_CLAVE 5
#define CARACTERES_POR_FILA 80
#define NOMBRE_ARCHIVO "registros.txt"
#define DELIMITADOR_REGISTRO '\n'
#define DELIMITADOR_CAMPOS '|'

enum {ALTA=1, BAJA, CONSULTA, ACTUALIZACION, LISTADO, BUSQUEDA, GUARDADO, SALIR} opcionMenu;

struct Requisitos{
    string requisitos;
    bool existe;
};

struct Materia{
    string clave;
    string nombre;
    Requisitos prerrequisitos[MAX_REQUISITOS];
    bool libre;
    bool registrada;
};

Materia materias[MAX_MATERIAS];

void pausar();
void limpiarRegistroMaterias(int indice);
void inicializaPrograma();
void modifidicarRegistroMaterias(int indice);
bool elRegistrosMateriasTieneDatos(int indice);
void mostrarMateria();
void darAltaMateria();
void darBajaMateria();
void consultarMaterias();
void actualizarDatosMateria();
void buscarMateria();
void listarMaterias();
int elegirOpcionMenuMaterias();
void guardarRegistros(int indice);
bool leerArchivoAlumnos();
void guardarArchivo();

int main (){
    bool continuarPrograma=true;
    inicializaPrograma(); // Se limpia la memoria RAM
    leerArchivoAlumnos();
    do{
        switch(elegirOpcionMenuMaterias()){
            case ALTA: darAltaMateria(); break;
            case BAJA: darBajaMateria();break;
            case CONSULTA: consultarMaterias();  break;
            case ACTUALIZACION: actualizarDatosMateria(); break;
            case LISTADO: listarMaterias(); break;
            case BUSQUEDA: buscarMateria(); break;
            case GUARDADO: guardarArchivo(); break;
            case SALIR: continuarPrograma = false; break;
            default: printf("Opcion no valida\n");
        }
        if(continuarPrograma){
            pausar();
         } else {
            return 0;
         }

    } while(continuarPrograma);
    return 0;
}
//Esta funcion limpiara la memoria RAM
void limpiarRegistroMaterias(int indice){
    int i=indice, j;
    materias[i].clave = "";
    materias[i].nombre = ""; 
    for(j=0; j<3 ; j++){
        materias[i].prerrequisitos[j].requisitos = "";
        materias[i].prerrequisitos[j].existe = false;
    }
    materias[i].libre = true;
    materias[i].registrada = false;
}

void inicializaPrograma(){
    int i;
    for(i=0; i<MAX_MATERIAS; i++){
        limpiarRegistroMaterias(i);
    }
}

void modifidicarRegistroMaterias(int indice){
    int i = indice;
    int prerrequisitos, j;
    
    cout << "Provee datos para el registro #" << i+1 << endl;
    cout << "Clave: ";
    getline(cin, materias[i].clave);
    
    cout << "Nombre: ";
    getline(cin, materias[i].nombre);
    
    cout << "Cuantos prerequisitos tiene la materia (1 a " << MAX_REQUISITOS << ")? ";
    cin >> prerrequisitos;
    cin.ignore();

    for (j=0; j<prerrequisitos; j++){
        
        cout << "Prerrequisito #" << j+1 << ": ";
        getline(cin, materias[i].prerrequisitos[j].requisitos);
        materias[i].prerrequisitos[j].existe = true;
        
    }
    materias[i].libre = false;
}

bool elRegistrosMateriasTieneDatos(int indice){

    bool tieneDatos = false;
    
    if( (0<=indice)&&(indice<MAX_MATERIAS)){
        
        if(materias[indice].libre){
            cout << "Registro sin datos" << endl << endl;
        } else {
            tieneDatos = true;
        }
    
    } else {
        cout << "No esxiste ese indice de registo" << endl << endl;
    }
    cin.ignore();
    return tieneDatos;
}

void mostrarMateria(int indice){
    char rellenaVacio= ' ';
    int i= indice;
    int j=0;

    if(!materias[i].libre){
        if( materias[i].prerrequisitos[j].requisitos.length() <= 5 ){
                cout << left
                     << setw(5) << materias[i].clave << " | " 
                     << setw(37)<< materias[i].nombre << " | "
                     << materias[i].prerrequisitos[j++].requisitos << endl;
            } else {
                cout << left
                     << setw(5) << materias[i].clave << " | " 
                     << setw(37)<< materias[i].nombre << " | "
                     << "(" << materias[i].prerrequisitos[j++].requisitos << ")" << endl;
            }  
        do{
    
            if(materias[i].prerrequisitos[j].existe){
                if( materias[i].prerrequisitos[j].requisitos.length() <= 5 ){
                    cout << left
                         << setw(5) << rellenaVacio << " | " 
                         << setw(37)<< rellenaVacio << " | "
                         << materias[i].prerrequisitos[j++].requisitos << endl;
                } else {
                    cout << left
                         << setw(5) << rellenaVacio << " | " 
                         << setw(37)<< rellenaVacio << " | "
                         << "(" << materias[i].prerrequisitos[j++].requisitos << ")" << endl;
                }
            }
            j++;
        }while(j<MAX_REQUISITOS);
        printf("---------------------------------------------------------------------\n");
    }
    
}

void darAltaMateria(){
    bool hayEspacioLibre;
    int i;
    
    cout << "ALTA DE NUEVA MATERIA" << endl << endl;
    hayEspacioLibre = false;

    for(i=0 ; i<MAX_MATERIAS; i++){
        if(materias[i].libre){
            hayEspacioLibre = true;
            break;
        } //else seguir Buscando un espaciolibre

    }

    if(hayEspacioLibre){
        modifidicarRegistroMaterias(i);
    } else {
        cout << "No hay mas espacios para capturar" << endl;
    }
}

void darBajaMateria(){
    int i, j;
    char opcion;
    cout << "BAJA DE UNA MATERIA" << endl << endl;
    cout << "Indica el numero de registo a consultar (1 a " << MAX_MATERIAS << "): ";
    cin >> i;
    i--;

    cout << endl;

    if(elRegistrosMateriasTieneDatos(i)){
        mostrarMateria(i);
        cout << endl <<"Estas seguro de que deseas eliminar el registro (s/n)? ";
        cin >> opcion;

        if(opcion=='s' || opcion == 'S'){
            
            do{    
                if(elRegistrosMateriasTieneDatos(i+1)){
                    materias[i].clave = materias[i+1].clave;
                    materias[i].nombre = materias[i+1].nombre;
                    for(j=0; j<MAX_REQUISITOS ; j++){
                        if(materias[i].prerrequisitos[j].existe){
                            materias[i].prerrequisitos[j].requisitos = materias[i+1].prerrequisitos[j].requisitos;
                        }
                    }    
                }
                limpiarRegistroMaterias(i+1);
            }while(!materias[i++].libre);
            cout << "Registro eliminado" << endl;
        } else {
            cout << "Registro consevado!" << endl;
            cin.ignore();
        }
    } 
}

void consultarMaterias(){
    int i;
    cout << "CONSULTA DE UNA MATERIA" << endl << endl;
    cout << "Indica el numero del registo a consultar (1 a " << MAX_MATERIAS << "): ";
    cin >>i;
    i--;

    cout << endl;

    if(elRegistrosMateriasTieneDatos(i)){
        cout << "---------------------------------------------------------------------" << endl
             << "Clave | Nombre                                | Prerrequisito(s)" << endl
             << "---------------------------------------------------------------------" <<endl;
        mostrarMateria(i);
    }
}

void actualizarDatosMateria(){
    int i;
    
    cout << "ACTUALIZACION DE DATOS DE UNA MATERIA" << endl << endl;
    cout << "Indica el numero de registro a modificar: ";
    cin >> i;
    cin.ignore();

    i--;
    
    if(elRegistrosMateriasTieneDatos(i)){
        mostrarMateria(i);
        modifidicarRegistroMaterias(i);
    }
}

void buscarMateria(){
    string buscado;
    bool patron;
    int i, cantNombresEncontrados;
    
    cout << "BUSQUEDA DE PROFESOR" << endl << endl;
    cout << "Indica el nombre del profesor: ";
    cin.ignore();
    getline(cin, buscado);

    cantNombresEncontrados = 0;
    cout << endl;
    for ( i=0; i<MAX_MATERIAS ; i++){
        patron = materias[i].nombre.find(buscado);
        if(patron){
            if(!materias[i].libre){
                mostrarMateria(i);
                cout << endl;
                cantNombresEncontrados ++;
            }
        }
    }
    if(cantNombresEncontrados){
        cout << "Se encontraron " << cantNombresEncontrados << " registro(s) con la palabra buscada" << endl;
    } else {
        cout << "No se encontro algun registro" << endl;
    }
}

void listarMaterias(){
    bool hayMaterias = false;
    int i;

    cout << "---------------------------------------------------------------------" << endl
         << "Clave | Nombre                                | Prerrequisito(s)" << endl
         << "---------------------------------------------------------------------" << endl;
    
    for(i=0; i<MAX_MATERIAS; i++){
        if(!materias[i].libre){
            hayMaterias = true;
            mostrarMateria(i);
        }
    }

    if (!hayMaterias){
        cout << "No hay profesores que mostrar." << endl;
    }
}

int elegirOpcionMenuMaterias(){
    int opcion;
    system(CLEAR);
    //imprimirCentrado("");
    cout << endl;
    cout << "1. Alta de un nueva materia" << endl;
    cout << "2. Baja de una materia" << endl;
    cout << "3. Consulta de una materia" << endl;
    cout << "4. Cambio de datos de una materia" << endl;
    cout << "5. Listado de materias" << endl;
    cout << "6. Busqueda de una materia" << endl;
    cout << "7. Guardar Registros" << endl;
    cout << "8. Salir" <<endl;
    cout << "Opción: ";
    cin >> opcion;
    if(opcion>=ALTA && opcion<=BUSQUEDA){
        system(CLEAR);
    }
    cin.ignore();
    return opcion;
}

void pausar(){
    cout << "Presione enter para continuar . . .";
    cin.ignore();
}

bool leerArchivoAlumnos(){
    ifstream archivo;// Salida o entrada de datos hacia archivos
    string cadena, subcadena;
    int posIni, posFin, cuentaMaterias, i, j;
    char caracter;

    cout << "Cargando archivo " << NOMBRE_ARCHIVO << "..." << endl;
    archivo.open( NOMBRE_ARCHIVO, ios::in );

    if( archivo.is_open() ){
        
        archivo >> cuentaMaterias;
        archivo >> cadena;
        cout << cuentaMaterias << " " << cadena << endl;
        getline(archivo,cadena);
        getline(archivo,cadena);

        i=0;
        while(!archivo.eof()){

            if(materias[i].libre){
                getline(archivo, cadena, DELIMITADOR_REGISTRO);
                posIni = 0;
                cout << cadena << endl;
                posFin = cadena.find_first_of(DELIMITADOR_CAMPOS, posIni);
                subcadena = cadena.substr(posIni,posFin);
                materias[i].clave = subcadena;

                posIni = posFin+1;
                posFin = cadena.find_first_of(DELIMITADOR_CAMPOS, posIni);
                subcadena = cadena.substr(posIni, posFin-posIni);
                materias[i].nombre = subcadena;
    
                posIni = posFin+1;
                posFin = cadena.find_first_of(DELIMITADOR_REGISTRO, posIni);//.at extrae un caracter de una cadena de texto, y recibe como parametro la posicion del caracter
                subcadena = cadena.substr(posIni, posFin-posIni);
                j=0;
                materias[i].prerrequisitos[j++].requisitos = subcadena;
                for( j ; j<3 ; j++){
                        subcadena = cadena.substr(posIni, posFin-posIni);
                        materias[i].prerrequisitos[j].requisitos = subcadena;
                }
            }
            materias[i++].libre=false;
            //i++;
        } 
        pausar();
        archivo.close();
        return true;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
        return false;
    }
}

void guardarRegistros(int indice){

    ofstream archivo;
    char rellenaVacio= ' ';
    int i= indice;
    int j=0;

    archivo.open(NOMBRE_ARCHIVO, ios::out);

    if( archivo.is_open() ){
        archivo << indice << "  Registros" << endl;
        if(!materias[i].libre){
            if( materias[i].prerrequisitos[j].requisitos.length() <= 5 ){
                archivo << left
                     << setw(5) << materias[i].clave << DELIMITADOR_CAMPOS 
                     << setw(37)<< materias[i].nombre << DELIMITADOR_CAMPOS
                     << materias[i].prerrequisitos[j++].requisitos << DELIMITADOR_REGISTRO;
            } else {
                archivo << left
                     << setw(5) << materias[i].clave << DELIMITADOR_CAMPOS
                     << setw(37)<< materias[i].nombre << DELIMITADOR_CAMPOS
                     << "(" << materias[i].prerrequisitos[j++].requisitos << ")" << DELIMITADOR_REGISTRO;
            }  
            do{
        
                if(materias[i].prerrequisitos[j].existe){
                    if( materias[i].prerrequisitos[j].requisitos.length() <= 5 ){
                        archivo << left
                             << setw(5) << rellenaVacio << DELIMITADOR_CAMPOS
                             << setw(37)<< rellenaVacio << DELIMITADOR_CAMPOS
                             << materias[i].prerrequisitos[j++].requisitos << DELIMITADOR_REGISTRO;
                    } else {
                        archivo << left
                             << setw(5) << rellenaVacio << DELIMITADOR_CAMPOS 
                             << setw(37)<< rellenaVacio << DELIMITADOR_CAMPOS
                             << "(" << materias[i].prerrequisitos[j++].requisitos << ")" << DELIMITADOR_REGISTRO;
                    }
                }
                j++;
            }while(j<MAX_REQUISITOS);
            cout << "---------------------------------------------------------------------" << endl;
            materias[i].registrada = true;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    pausar();
    

}

void guardarArchivo(){
    bool hayEspacioLibre;
    int i;
    
    cout << "CREANDO ARCHIVO DE REGISTROS" << endl << endl;
    hayEspacioLibre = false;

    for(i=0 ; i<MAX_MATERIAS; i++){
        if(!materias[i].registrada){
            hayEspacioLibre = true;
            break;
        } //else seguir Buscando un espaciolibre

    }

    if(hayEspacioLibre){
        cout << "Archivo Guardado" << endl;
        guardarRegistros(i);
    } else {
        cout << "No hay mas espacios para capturar" << endl;
    }
}