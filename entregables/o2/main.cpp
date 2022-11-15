/**
 * POO
 * NickName = DosTres
 * Ejercicio o2
 * Tiempo = 00:30
 * 
*/

#include <iostream>

#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__uninx)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado pra limpiar la pantalla"
#endif

#define MAXIMO_LIBROS 3

using namespace std;

class Libro{
    string nombre;
    float precio;
    char genero;
public:
    void fijaNombre(string n){
        nombre = n;
    }
    void fijaPrecio(float p){
        precio = p;
    }
    void fijaGenero(char g){
        genero = g;
    }
    string dameNombre(){
        return nombre;
    }
    float damePrecio(){
        return precio;
    }
    char dameGenero(){
        return genero;
    }
};

class Arbol{
    string nombre;
    int codigo;
    Libro libros[MAXIMO_LIBROS];
public:
    void fijaNombre(string n){
        nombre=n;
    }
    void fijaCodigo( int c ){
        codigo = c;
    }
    void fijaLibros( Libro lib[MAXIMO_LIBROS]){
        for( int i=0; i<MAXIMO_LIBROS ; i++){
            libros[i] = lib[i];
        }
    }
    string dameNombre(){
        return nombre;
    }
    int dameCodigo(){
        return codigo;
    }
    Libro dameLibros(){
        return libros[MAXIMO_LIBROS];
    }
};

void pausar();
void imprimeLibros(Libro libros[MAXIMO_LIBROS]);



int main(){
    Libro libros[MAXIMO_LIBROS];
    Arbol arbol;
    string nombre;
    int codigo;
    float precio;
    char genero;
    

    cout << "***TREE BOOKS***" << endl << endl
         << "GENEROS DE LIBROS" << endl
         << " C=Economia" << endl 
         << " S=Suspenso" << endl
         << " L=Literatura" << endl
         << " F=Ficcion" << endl
         << " A=Autocrecimiento" << endl
         << " H=Historia"
         << " E=Educacion" << endl << endl;

    cout << "Creando datos del Tree book" << endl
         << "Nombre: ";
    getline(cin, nombre);
    cout << "Codigo: ";
    cin >> codigo;
    cin.ignore();

    arbol.fijaNombre(nombre);
    arbol.fijaCodigo(codigo);
    
    cout << endl << "**Agregando libros**" << endl;

    for(int i=0 ; i<MAXIMO_LIBROS; i++){
        cout << "Creando datos del libro #" << i+1 << endl;
        cout << " Nombre: " ;
        getline(cin, nombre);
        libros[i].fijaNombre(nombre);
        
        cout << " Precio: ";
        cin >> precio;
        cin.ignore();
        libros[i].fijaPrecio(precio);

        cout << " Genero: ";
        cin >> genero;
        cin.ignore();
        libros[i].fijaGenero(genero);

        cout << endl;
    }
    arbol.fijaLibros(libros);
    pausar();


    cout << endl << "DATOS ALMACENADOS" << endl << endl
         << "Nombre del arbol: " << arbol.dameNombre() << endl
         << "Codigo del arbol: " << arbol.dameCodigo() << endl;
    cout << endl << "Libros en el arbol" << endl << endl;
    imprimeLibros(libros);
    pausar();

    return 0;
}

void imprimeLibros(Libro libros[MAXIMO_LIBROS]){
    for(int i=0; i<MAXIMO_LIBROS ; i++){
        cout << "Nombre " <<"libro " <<  i+1 << ": " << libros[i].dameNombre() << endl
             << "Precio " <<"libro " <<  i+1 << ": " << libros[i].damePrecio() << endl 
             << "Genero " <<"libro " <<  i+1 << ": " << libros[i].dameGenero() << endl << endl;
    }
};

void pausar(){
    cout << "Presione enter para continuar . . .";
    cin.ignore();
}