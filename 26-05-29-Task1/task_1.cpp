#include <iostream>
#include <string>

using namespace std;

// Define the Student struct
struct Student {
    int ID;
    string name;
    int age;
    string course;
};

// Function to display a single student record
void displayStudent(const Student& s) {
    cout << "\n*** Student Record ***" << endl;
    cout << "ID: " << s.ID << endl;
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Course: " << s.course << endl;
}

// Function to display all students
void displayAllStudents(Student students[], int size) {
    cout << "\n========== ALL STUDENT RECORDS ==========" << endl;
    for (int i = 0; i < size; i++) {
        displayStudent(students[i]);
    }
    cout << "==========================================" << endl;
}

// Function to search for a student by ID
int searchByID(Student students[], int size, int searchID) {
    for (int i = 0; i < size; i++) {
        if (students[i].ID == searchID) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}

// Function to update a student record
void updateStudent(Student& s) {
    int choice;
    cout << "\nWhat do you want to change?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Age" << endl;
    cout << "3. Course" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();  // Clear the newline from buffer

    switch (choice) {
    case 1:
        cout << "Enter new name: ";
        getline(cin, s.name);
        break;
    case 2:
        cout << "Enter new age: ";
        cin >> s.age;
        break;
    case 3:
        cout << "Enter new course: ";
        cin.ignore();
        getline(cin, s.course);
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
}

int main() {
    const int SIZE = 5;

    // Initialize 5 student records
    Student students[SIZE] = {
        {24007271, "Reeyan", 26, "IT"},
        {24007272, "Sarah", 22, "Computer Science"},
        {24007273, "Ahmed", 24, "Engineering"},
        {24007274, "Maria", 21, "Business"},
        {24007275, "John", 23, "Mathematics"}
    };

    int choice, searchID, index;

    do {
        cout << "\n======= STUDENT MANAGEMENT SYSTEM =======" << endl;
        cout << "1. Display all records" << endl;
        cout << "2. Search for a student by ID" << endl;
        cout << "3. Update a student record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayAllStudents(students, SIZE);
            break;

        case 2:
            cout << "Enter student ID to search: ";
            cin >> searchID;
            index = searchByID(students, SIZE, searchID);
            if (index != -1) {
                cout << "\nStudent found!";
                displayStudent(students[index]);
            }
            else {
                cout << "\nStudent with ID " << searchID << " not found." << endl;
            }
            break;

        case 3:
            cout << "Enter student ID to update: ";
            cin >> searchID;
            index = searchByID(students, SIZE, searchID);
            if (index != -1) {
                cout << "\nCurrent record:";
                displayStudent(students[index]);
                updateStudent(students[index]);
                cout << "\nUpdated record:";
                displayStudent(students[index]);
            }
            else {
                cout << "\nStudent with ID " << searchID << " not found." << endl;
            }
            break;

        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}