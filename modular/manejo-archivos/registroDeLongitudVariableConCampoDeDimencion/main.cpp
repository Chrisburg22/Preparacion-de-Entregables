#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#define FILE_NAME "students.dat"
#define STUDENT_NAME_LENGTH 10
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

void createStudents();
void deleteStudents();
void printStudent(Student* s);
void printStudents();
void writeStudent(ofstream& file, Student* s);
void writeStudents();
Student* readStudent(ifstream& file);
void readStudents();

int main(){
    cout << "Variable length records (size fields)..." << endl;
    createStudents();
    printStudents();
    writeStudents();
    deleteStudents();
    readStudents();
    printStudents();
    deleteStudents();
    return EXIT_SUCCESS;
}
void createStudents(){
    students[0] = new Student(76,(char*)"Christian");
    students[1] = new Student(76,(char*)"Alejandro");
}

void deleteStudents(){
    for(int i=0; i<MAX_STUDENTS&&students[i];i++){
        delete students[i];
    }
}

void printStudent(Student* s){
    cout << "student's id is " << s->getID() << endl;
    cout << "student's name is " << s->getName() << endl;
}
void printStudents(){
    for(int i=0;i<MAX_STUDENTS&&students[i];i++){
        printStudent(students[i]);
    }
}
void writeStudent(ofstream& file, Student* s){
    int id,nBytes, sizeOf;
    char* name;
    char nameLength;
    id = s->getID();
    name = s->getName();
    nameLength = (char)strlen(name)+1;
    cout << "Writing a student" << endl;
    file.write((char*)&id, nBytes=sizeof(int));
    file.write(&nameLength, sizeof(char));
    nBytes += sizeOf;
    file.write(name, nameLength);
    nBytes += nameLength;
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
}

Student* readStudent(ifstream& file){
    int id = -1;
    char nameLength;
    char name[STUDENT_NAME_LENGTH+1];
    file.read((char*)&id, sizeof(int)) ;
    if(id!=-1){
        cout << "Reading a student" << endl;
        file.read(&nameLength,sizeof(char));
        file.read(name, nameLength);
        return new Student(id, name);
    } else{
        return nullptr;
    }
}

void readStudents(){
    ifstream file;
    Student* s;
    cout << "Reading students list" << endl;
    file.open(FILE_NAME, ios::binary);
    if(file.is_open()){
        for(int i=0; !file.eof(); i++){
            s = readStudent(file);
            if(s!=nullptr){
                students[i] = s;
            }
        }
    file.close();
    } else {
        cout << "An error ocurred whiule reading student list" << endl;
    }
}

