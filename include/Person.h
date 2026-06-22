#ifndef PERSON_H
#define PERSON_H

 #include <string>
//  person base class
// concepts demostrated OOps -> Inheritance student 
// extend this class and polymorphism display () is virtual so
// derived classes can override it.

class Person{
    protected:
     std:: string name;
     int age;
     public: 
        Person(const std:: string & name = "", int age = 0);
        virtual void display () const;
        virtual ~Person();
};
#endif
