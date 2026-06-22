#include "../include/StudentManager.h"

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void printMenu(){
    cout<<"\n ****************** STUDENT MANAGEMENT SYSTEM **********\n";
    cout<<"1. Add Student\n";
    cout<<"2. Display All Student \n";
    cout<<"3. Search Student by Roll no \n";
    cout<<"4. Update Student\n";
    cout<<"5. Delete Student\n";
    cout<<"6. sort by CGPA (high -> low)\n";
    cout<<"7. Sort by Name (A to Z )\n";
    cout<<"8. Show class average CGPA\n";
    cout<<"9. Show Top N Students\n";
    cout<<"10. exit\n";
    cout<<"*************************************************************"<<endl;
    cout<<"enter your choice : ";
}
    //  collecting all student details for one student
    Student takeInput(){
        int rollNo, age , semester , numSubjects;
        string name, branch;
        cout <<"Roll No: ";
        cin>>rollNo;

        cout <<"Name: ";
        cin.ignore();
        getline(cin ,name);

        cout<<"Age: ";
        cin>>age;

        cout<<"Branch: ";
        cin.ignore();
        getline(cin, branch);
        
        cout<<"Semester: ";
        cin>>semester;

        cout<<"Number of subject: ";
        cin >> numSubjects;

        vector<float> marks(numSubjects);
        for(int i=0; i<numSubjects; ++i)
        {
            cout<<"Marks for subject  "<<(i+1)<<"(out of 100): ";
            cin>>marks[i];
    }
    return Student(rollNo, name, age, branch, semester,marks);
    }
    
    int main(){
        StudentManager manager("../data/students.txt");
        int choice = -1;

        do{
            printMenu();
            cin>>choice;

            switch(choice){
                case 1: {
                    Student s = takeInput();
                    manager.addStudent(s);
                    cout<<"Student added  Successfully\n";
                    break;

                }
                case  2 : {
                    manager.displayAll();
                    break;
                }
                case 3 :  {
                    int roll ;
                    cout<<"Enter Roll No: ";
                    cin>>roll;
                    Student* found = manager.searchStudent(roll);
                    if(found) found->display();
                    else cout<<"Student not  found. \n";
                    break;
                }
                case 4:{
                    int roll ;
                    cout<<"enter roll no to update: ";
                    cin>> roll;
                     if(manager.searchStudent(roll)){
                        cout<<"Enter new details: \n";
                        Student updated = takeInput();
                        manager.updateStudent(roll, updated);
                        cout<<"Updated Successfully\n";
                        }
                        else{
                                cout<<"Student not found.\n";
                            }
                    break;
                }
                case 5 :{
                    int roll;
                    cout<<"Enter roll no to delete: ";
                    cin >> roll;
                    if(manager.removeStudent(roll)){
                        cout<<"Deleted successfully\n";

                    }
                    else{
                        cout<<"Student not found.\n";
                        
                    }
                    break;
                }
                case 6:{
                    manager.sortByCGPA(true);
                    cout<<"Sorted by CGPA (Descending): \n";
                    manager.displayAll();
                    break;
                }
                case 7: {
                    manager.sortByName();
                    cout<<"Sorted by Name: \n";
                    manager.displayAll();
                    break;
                }
                case 8:{
                    cout<<"class Average CGPA: "<<manager.averageCGPA()<<"\n";
                    break;
                }
                case 9:{
                    int n;
                    cout<<"enter Number";
                    cin>>n;
                    auto top = manager.topNStudents(n);
                    for(auto & s : top) s.display();
                    break;
                }
                case 10 : 
                        cout<<"Data saved. Exiting...\n";
                        break;
                    default :
                        cout<<"Invalid choice! Try agian.\n";

            }
        
         } while (choice !=10);
        
        return 0;
    }

