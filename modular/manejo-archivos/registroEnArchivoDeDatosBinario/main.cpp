#include <iostream>
#include <fstream>
#include <cstring>

#define FILE_NAME "students.dat"
#define STUDENT_NAME_LENGTH 25


using namespace std;

class Student{
    int id;
    char name[STUDENT_NAME_LENGTH+1];
public:
    Student(int id, char* name){
        this->id = id;
        strcpy(this->name, name);
    }
    int getID(){
        return id;
    }
    char* getName(){
        return name;
    }
};

void writeStudent(Student& s);
Student* readStudent();
void printStudent(Student* s);

int main () {
    int id=395012345;

    Student chris(id,(char*)"Christian Ramos");
    Student* ramos;
    cout << "Writing one record to a file ..." << endl;
    printStudent(&chris);
    writeStudent(chris);
    ramos = readStudent();
    printStudent(ramos);
    delete ramos;
    return EXIT_SUCCESS;
}

