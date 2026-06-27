#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>
#include <string>
#include <iostream>

class Student : public Person{
    private:
        int rollNo;
        std::string branch;
        int semester;
        std::vector<float> marks;
        float cgpa;
        float calculateCGPA() const;
    public:
        Student();
        Student(int rollNo,const std::string & name, int age, const std::string & branch, int semester, const std::vector<float>&marks);
        int getRollNo() const;
        std::string getName() const;
        int getSemester() const;
        std::string getBranch() const;
        float getCGPA() const;
        std::vector<float> getMarks()const;

        void setBranch (const std::string & branch);
        void setSemester(int semester );
        void setMarks(const std::vector<float> & marks);
    
        void display () const override;
        

        bool operator <(const Student & other) const;
         bool operator ==(const Student & other) const;

         friend std::ostream& operator<<(std::ostream& os, const Student& s);
         std::string toFileString() const;
         static Student fromFileString(const std:: string& line);

    };

    #endif