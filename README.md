#  Student Management System (C++)

This is a simple Student Management System developed in C++ as a practice project to improve my understanding of Object-Oriented Programming (OOP), STL, and File Handling.

The project allows users to manage student records through a menu-driven console application. Student data is stored in a text file so that records remain available even after closing the program.

##  What This Project Can Do

* Add a new student record
* View all saved student records
* Search a student using Roll Number
* Update student information
* Delete a student record
* Sort students based on CGPA
* Sort students alphabetically by name
* Calculate the average CGPA of the class
* Display the top N students
* Save and load data using file handling

---

##  Technologies & Concepts Used

* C++17
* Object-Oriented Programming (OOP)
* STL (Vector, Map, Algorithms)
* File Handling
* Git & GitHub

---

##  Project Structure

```text
Student-Management-System-CPP/
│
├── data/
│   |── students.txt
|   |__ README.md
│
├── include/
│   ├── Person.h
│   ├── Student.h
│   |── StudentManager.h
|   |__ README.md 
│
├── src/
│   ├── main.cpp
│   ├── Person.cpp
│   ├── Student.cpp
│   |── StudentManager.cpp
|   |__ README.md
│
├── README.md
├── LICENSE
└── .gitignore
```

---

##  OOP Concepts Practiced

* Encapsulation
* Inheritance
* Polymorphism
* Abstraction
* Operator Overloading

---

## ▶ How to Run

Compile the project:

```bash
g++ src/*.cpp -Iinclude -o main
```

Run the executable:

```bash
./main
```

For Windows:

```bash
.\main.exe
```

---

##  Sample Menu

```text
1. Add Student
2. Display All Student
3. Search Student by Roll No
4. Update Student
5. Delete Student
6. Sort by CGPA
7. Sort by Name
8. Show Class Average CGPA
9. Show Top N Students
10. Exit
```

---

## 🎯 Why I Built This Project

I created this project to strengthen my C++ fundamentals and get hands-on experience with OOP, STL containers, and file handling. It helped me understand how real-world applications manage and store data.

---

## 🚀 Future Improvements

* Graphical User Interface (GUI)
* Database Integration
* User Authentication
* CSV Export Feature
* Advanced Search and Filters

---

## 👨‍💻 Created 

**Rudraksh Kumar**

B.Tech Computer Science Engineering Student
