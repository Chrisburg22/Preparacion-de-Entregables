#include <iostream>

using namespace std;

#define MAXIMO_LIBROS 3

class Libro{
    string nombre;
    float precio;
    char genero;
public:
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    void setPrecio(float precio){
        this->precio = precio;
    }
    void setGenero(char genero){
        this->genero = genero;
    }
    string getNombre(){
        return nombre;
    }
    float getPrecio(){
        return precio;
    }
    char getGenero(){
        return genero;
    }
};

class Arbol{
    int codigo;
    Libro libros[MAXIMO_LIBROS];
public:
    void setCodigo( int codigo ){
        this->codigo = codigo;
    }
    void setLibros( Libro libros[MAXIMO_LIBROS]){
        for( int i=0; i<MAXIMO_LIBROS ; i++){
            this->libros[i] = libros[i];
        }
    }
    int getCodigo(){
        return codigo;
    }
    void getLibros(){
        for(int i=0; i<MAXIMO_LIBROS ; i++){
            cout << endl << "Nombre " <<"libro " <<  i+1 << ": " << libros[i].getNombre() << endl
                 << "Precio " <<"libro " <<  i+1 << ": " << libros[i].getPrecio() << endl
                 << "Genero " <<"libro " <<  i+1 << ": " << libros[i].getGenero() << endl;
        }
    }
};

int main(){
    string nombre;
    int codigo;
    float precio;
    char genero;
    Libro libros[MAXIMO_LIBROS];
    Arbol arbol;

    cout << "                                TREE BOOK" << endl << endl;
    cout << "                            GENEROS DE LIBROS" << endl;
    cout << "Economia=C Suspenso=S Literatura=L Ficcion=F Autocrecimiento=A Educacion=E " << endl << endl;
    cout << "Creando un nuevo arbol" << endl;
    cout << "Nuevo codigo de arbol: ";
    cin >> codigo;
    cin.ignore();
    cout << endl;

    for(int i=0 ; i<MAXIMO_LIBROS; i++){
        cout << "Creando datos del libro #" << i+1 << endl;
        cout << "Ingresa el nombre: " ;
        getline(cin, nombre);
        libros[i].setNombre(nombre);
        
        cout << "Ingresa el precio: ";
        cin >> precio;
        cin.ignore();
        libros[i].setPrecio(precio);

        cout << "Ingresa el genero: ";
        cin >> genero;
        cin.ignore();
        libros[i].setGenero(genero);

        cout << endl;
    }

    arbol.setCodigo(codigo);
    arbol.setLibros(libros);

    cout << endl << "Libros del Arbol: " << arbol.getCodigo() << endl;
    arbol.getLibros();

}