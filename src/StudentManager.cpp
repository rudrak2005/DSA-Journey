#include "StudentManager.h"
#include <algorithm>  
#include <numeric>   
#include <fstream>   
#include <iostream>
#include <iomanip>

StudentManager::StudentManager(const std::string& filename) : filename(filename) {
    loadFromFile(); 
}

void StudentManager::rebuildIndexMap() {
    rollIndexmap.clear();
    for (size_t i = 0; i < students.size(); ++i) {
        rollIndexmap[students[i].getRollNo()] = static_cast<int>(i);
    }
}

void StudentManager::addStudent(const Student& s) {
    students.push_back(s);                                 
    rollIndexmap[s.getRollNo()] = static_cast<int>(students.size() - 1);
    saveToFile();                                          
}

bool StudentManager::removeStudent(int rollNo) {
   
    auto it = std::find_if(students.begin(), students.end(),
                            [rollNo](const Student& s) { return s.getRollNo() == rollNo; });

    if (it == students.end()) return false;

    students.erase(it);  
    rebuildIndexMap();
    saveToFile();
    return true;
}

Student* StudentManager::searchStudent(int rollNo) {
    auto it = rollIndexmap.find(rollNo);   
    if (it == rollIndexmap.end()) return nullptr;
    return &students[it->second];
}

bool StudentManager::updateStudent(int rollNo, const Student& updated) {
    Student* existing = searchStudent(rollNo);
    if (!existing) return false;
    *existing = updated;
    saveToFile();
    return true;
}

void StudentManager::displayAll() const {
    if (students.empty()) {
        std::cout << "No records found.\n";
        return;
    }
    std::cout << std::left
              << std::setw(8)  << "Roll"
              << std::setw(15) << "Name"
              << std::setw(15) << "Branch"
              << std::setw(5)  << "Sem"
              << "CGPA" << "\n";
    std::cout << std::string(50, '-') << "\n";

    for (const auto& s : students) s.display();
}

void StudentManager::sortByCGPA(bool descending) {
    // STL algorithm: sort with a custom lambda comparator
    std::sort(students.begin(), students.end(), [descending](const Student& a, const Student& b) {
        return descending ? b < a : a < b;
    });
    rebuildIndexMap();
}

void StudentManager::sortByName() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getName() < b.getName();
    });
    rebuildIndexMap();
}

double StudentManager::averageCGPA() const {
    if (students.empty()) return 0.0;
   
    double sum = std::accumulate(students.begin(), students.end(), 0.0,
                                  [](double acc, const Student& s) { return acc + s.getCGPA(); });
    return sum / students.size();
}

std::vector<Student> StudentManager::topNStudents(int n) const {
    std::vector<Student> copy = students;  
    std::sort(copy.begin(), copy.end(), [](const Student& a, const Student& b) { return b < a; });
    if (n > static_cast<int>(copy.size())) n = static_cast<int>(copy.size());
    if (n < 0) n = 0;
    return std::vector<Student>(copy.begin(), copy.begin() + n);
}

void StudentManager::saveToFile() const {
    std::ofstream out(filename);  
    for (const auto& s : students) {
        out << s.toFileString() << "\n";
    }
   
}

void StudentManager::loadFromFile() {
    std::ifstream in(filename);   
    if (!in.is_open()) return;     
    students.clear();
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        students.push_back(Student::fromFileString(line));
    }
    rebuildIndexMap();
}

size_t StudentManager::totalStudents() const { return students.size(); }