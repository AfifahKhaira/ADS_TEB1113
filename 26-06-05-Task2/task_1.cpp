#include <iostream>
using namespace std;

struct Student {
    string id;
    string name;
    string course;
    int age;
};

int main() {

    Student student[1000];
    
    student[0].id = "24007271";
    student[0].name = "Reeyan";
    student[0].course = "IT";
    student[0].age = 25;
    
    student[1].id = "24006565";
    student[1].name = "Aimar";
    student[1].course = "IT";
    student[1].age = 20;
    
    for (int i = 0; i < 1000; i++)
        {
        cout << student[i].id << endl;
        cout << student[i].name << endl;
        cout << student[i].course << endl;
        cout << student[i].age << endl;
        
        cout << endl;
        }

    return 0;
}