#include <iostream>

using namespace std;

#define MAXIMO_LIBROS 3

class Libro{
    string nombre;
    float precio;
    char genero;
public:
    Libro(){
        nombre= "Nombre libro";
        precio = 0;
        genero = ' ';
    }
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
    Libro llenaDatos(string nombre, float precio, char genero){
        Libro libro;

        libro.setNombre(nombre);
        libro.setPrecio(precio);
        libro.setGenero(genero);

        cout << endl << "Datos recibidos" << endl 
             << "Nombre " << "libro: " << libro.getNombre() << endl
             << "Precio " << "libro: " << libro.getPrecio() << endl
             << "Genero " << "libro: " << libro.getGenero() << endl;

        return libro;
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
    Libro getLibros(){
        return libros[MAXIMO_LIBROS];
    }
    void imprimeLibros(){
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

    cout << "***TREE BOOKS***" << endl << endl;
    cout << "GENEROS DE LIBROS" << endl;
    cout << " C=Economia" << endl 
         << " S=Suspenso" << endl
         << " L=Literatura" << endl
         << " F=Ficcion" << endl
         << " A=Autocrecimiento" << endl
         << " E=Educacion" << endl << endl
         << "Creando Tree book" << endl
         << "Crea un codigo para el Tree book: ";
    cin >> codigo;
    cin.ignore();
    
    cout << endl << "**Agregando libros**" << endl;
    
    for(int i=0 ; i<MAXIMO_LIBROS; i++){
        cout << "Creando datos del libro #" << i+1 << endl;
        cout << " Nombre: " ;
        getline(cin, nombre);
        
        cout << " Precio: ";
        cin >> precio;
        cin.ignore();

        cout << " Genero: ";
        cin >> genero;
        cin.ignore();

        libros[i] = libros[i].llenaDatos(nombre, precio, genero);
        cout << endl;
    }

    arbol.setCodigo(codigo);
    arbol.setLibros(libros);

    cout << endl << "Codigo Tree book: " << arbol.getCodigo() << endl;
    arbol.imprimeLibros();

    return 0;
}