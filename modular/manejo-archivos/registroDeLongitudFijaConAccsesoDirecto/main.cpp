#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#define FILE_NAME "students.dat"
#define STUDENT_NAME_LENGTH 25
#define MAX_STUDENTS 2

using namespace std;

class Student{
    int id;
    char name[STUDENT_NAME_LENGTH+1];
public:
    Student(int id, char* name){
        setId(id);
        setName(name);
    }
    int getID(){
        return id;
    }
    char* getName(){
        return name;
    }
    void setId(int id){
        this->id = id;
    }
    void setName(char* name){
        strcpy(this->name, name);
    }
};

Student* students[MAX_STUDENTS];
bool updateStudents[MAX_STUDENTS];

void pause();
void writeStudent(ofstream& file, Student* s);
void writeStudents();
void readStudents();
Student* readStudent(ifstream& file);
int countWrittenRecords(ifstream& file);
void printStudent(Student* s);
void printStudents();
void createStudents();
void deleteStudents();
void updateStudent(int position,char* newName);
void updateFile();

int main(){
    cout << "Direct access to update records into a file..." << endl;
    createStudents();
    printStudents();
    writeStudents();
    deleteStudents();
    readStudents();
    printStudents();
    updateStudent(0,(char*)"Christian Ramos");
    updateStudent(1,(char*)"Alejandro Perez");
    printStudents();
    updateFile();
    deleteStudents();
    readStudents();
    printStudents();
    deleteStudents();

    return EXIT_SUCCESS;
}

void pause(){
    cout << "Press enter to contiue .." << endl;
    getchar();
}

void createStudents(){
    students[0] = new Student(221802,(char*)"Christian");
    students[1] = new Student(221802,(char*)"Alejandro");
}

void deleteStudents(){
    cout << "deleting studens ..." << endl;
    for(int i=0; i<MAX_STUDENTS&&students[i];i++){
        delete students[i];
    }
    pause();
}

void printStudent(Student* s){
    cout << "student's id is " << s->getID() << endl;
    cout << "student's name is " << s->getName() << endl;
}

void printStudents(){
    for(int i=0;i<MAX_STUDENTS&&students[i];i++){
        printStudent(students[i]);
    }
    pause();
}
void writeStudent(ofstream& file, Student* s){
    int nBytes;
    cout << "Writing a student" << endl;
    file.write((char*)s, nBytes=sizeof(Student));
    cout << "Writen" << nBytes << "bytes" << endl;
}
void writeStudents(){
    ofstream file;
    file.open(FILE_NAME, ios::trunc | ios::binary);
    if(file.is_open()){
        for(int i=0;i<MAX_STUDENTS&&students[i]; i++){
            writeStudent(file, students[i]);
        }
        file.close();
    } else {
        cout << "An error occured while writing student list" << endl;
    }
    pause();
}

Student* readStudent(ifstream& file){
    Student* s = new Student(0, (char*)"");
    cout << "Reading a student" << endl;
    file.read((char*)s,sizeof(Student));
    return s;
}

void readStudents(){
    ifstream file;
    cout << "Reading students list" << endl;
    file.open(FILE_NAME, ios::binary);
    if(file.is_open()){
        for(int i=0, writtenRecords=countWrittenRecords(file);i<MAX_STUDENTS&&i<writtenRecords; i++){
            students[i] = readStudent(file);
        }
        file.close();
    } else {
        cout << "An error ocurred while reading student list" << endl;
    }
    pause();
}

//Nuevas funciones
int countWrittenRecords(ifstream& file){
    int writtenRecords;
    file.seekg(0,ios_base::end);// Investigar la definicion y su uso
    writtenRecords = file.tellg()/sizeof(Student); // Esta funcion te entrega el numero de byte en donde estaas posicionado
    file.seekg(0,ios_base::beg);
    cout << "Counter written records: " << writtenRecords << endl;
    return writtenRecords;
}

void updateStudent(int position, char* newName){
    cout << "Updating student at position " << position << endl;
    students[position]->setName(newName);
    updateStudents[position] = true;
    pause();
}

void updateFile(){
   ofstream file;
   file.open(FILE_NAME, ofstream::in | ofstream::out | ios::binary);
   if(file.is_open()){
    for(int i=0;i<MAX_STUDENTS&&students[i];i++){
        if(updateStudents[i]){
            file.seekp(i*sizeof(Student));
            writeStudent(file,students[i]);
        }
    }
    file.close();
   }
   else {
    cout << "An error occured while writting list" << endl;
   }
   pause();
}