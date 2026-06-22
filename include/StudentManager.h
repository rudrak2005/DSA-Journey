#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "Student.h"
#include <vector>
#include <map>
#include <string>

class StudentManager{
        private:
        std::vector<Student> students;
        std::map<int , int >  rollIndexmap;
        std::string filename;

void rebuildIndexMap();
public:
explicit StudentManager(const std::string &filename ="data/students.txt");
void addStudent(const Student &s);
bool removeStudent(int rollNo);
Student* searchStudent(int rollNo);
bool updateStudent(int rollNo, const Student& updated);


void displayAll()const;
void sortByCGPA(bool descending = true);
void sortByName();
double averageCGPA() const;
std::vector<Student> topNStudents(int n) const;


void saveToFile()const;
void loadFromFile();
size_t totalStudents() const;


};
#endif