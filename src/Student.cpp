#include "Student.h"
#include <numeric>    
#include <sstream>    
#include <iomanip>   

Student::Student()
    : Person("", 0), rollNo(0), branch(""), semester(0), marks(), cgpa(0.0f) {}

Student::Student(int rollNo, const std::string& name, int age,
                  const std::string& branch, int semester,
                  const std::vector<float>& marks)
    : Person(name, age), rollNo(rollNo), branch(branch),
      semester(semester), marks(marks) {
    cgpa = calculateCGPA();
}

float Student::calculateCGPA() const {
    if (marks.empty()) return 0.0f;
   
    float sum = std::accumulate(marks.begin(), marks.end(), 0.0f);
    float avg = sum / marks.size();
    return avg / 10.0f;
}


int Student::getRollNo() const { return rollNo; }
std::string Student::getName() const { return name; }
std::string Student::getBranch() const { return branch; }
int Student::getSemester() const { return semester; }
float Student::getCGPA() const { return cgpa; }
std::vector<float> Student::getMarks() const { return marks; }


void Student::setBranch(const std::string& b) { branch = b; }
void Student::setSemester(int s) { semester = s; }
void Student::setMarks(const std::vector<float>& m) {
    marks = m;
    cgpa = calculateCGPA(); 
}

void Student::display() const {
    std::cout << std::left
              << std::setw(8)  << rollNo
              << std::setw(15) << name
              << std::setw(15) << branch
              << std::setw(5)  << semester
              << std::fixed << std::setprecision(2) << cgpa << "\n";
}

bool Student::operator<(const Student& other) const {
    return cgpa < other.cgpa;
}

bool Student::operator==(const Student& other) const {
    return rollNo == other.rollNo;
}

std::ostream& operator<<(std::ostream& os, const Student& s) {

    os << s.rollNo << "," << s.name << "," << s.age << ","
       << s.branch << "," << s.semester << ",";
    for (size_t i = 0; i < s.marks.size(); ++i) {
        os << s.marks[i];
        if (i != s.marks.size() - 1) os << ";";
    }
    return os;
}

std::string Student::toFileString() const {
    std::ostringstream oss;
    oss << *this;           
    return oss.str();
}

Student Student::fromFileString(const std::string& line) {
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> fields;

    while (std::getline(ss, token, ',')) {
        fields.push_back(token);
    }

    int rollNo        = std::stoi(fields[0]);
    std::string name  = fields[1];
    int age            = std::stoi(fields[2]);
    std::string branch = fields[3];
    int semester        = std::stoi(fields[4]);

    std::vector<float> marks;
    if (fields.size() > 5 && !fields[5].empty()) {
        std::stringstream marksStream(fields[5]);
        std::string markToken;
        while (std::getline(marksStream, markToken, ';')) {
            marks.push_back(std::stof(markToken));
        }
    }

    return Student(rollNo, name, age, branch, semester, marks);
}