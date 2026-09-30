#include <iostream>
#include <string>
using namespace std;

struct node {
    int rollno;
    string name;
    int marks;
    node* next = NULL;

    void insert_details() {
        cout << "Enter the Student Name: ";
        cin >> name;

        cout << "Enter the Student Roll no.: ";
        cin >> rollno;

        cout << "Enter the Student Marks: ";
        cin >> marks;
    }
} *start = NULL;

node* create() {
    node* temp = new node;
    temp->insert_details();
    temp->next = NULL;
    return temp;
}


void addStudent() {
    node* temp = create();

    if (start == NULL) {
        start = temp;
    }
    else {
        node* ptr = start;

        while (ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = temp;
    }

    cout << "\nStudent added successfully!\n";
}


void display() {
    if (start == NULL) {
        cout << "\nNo student records found.\n";
        return;
    }

    node* ptr = start;

    cout << "\n-------------------------------------------------\n";
    cout << "Roll No.\tName\t\tMarks\n";
    cout << "-------------------------------------------------\n";

    while (ptr != NULL) {
        cout << ptr->rollno << "\t\t"
             << ptr->name << "\t\t"
             << ptr->marks << endl;

        ptr = ptr->next;
    }

    cout << "-------------------------------------------------\n";
}

void searchStudent() {
    if (start == NULL) {
        cout << "\nNo student records found.\n";
        return;
    }

    int roll;
    cout << "\nEnter Roll No. to search: ";
    cin >> roll;

    node* ptr = start;

    while (ptr != NULL) {
        if (ptr->rollno == roll) {
            cout << "\nStudent Found!\n";
            cout << "Roll No. : " << ptr->rollno << endl;
            cout << "Name     : " << ptr->name << endl;
            cout << "Marks    : " << ptr->marks << endl;
            return;
        }

        ptr = ptr->next;
    }

    cout << "\nStudent with Roll No. " << roll << " not found.\n";
}

void deleteStudent() {
    if (start == NULL) {
        cout << "\nNo student records found.\n";
        return;
    }

    int roll;
    cout << "\nEnter Roll No. to delete: ";
    cin >> roll;

    node* ptr = start;
    node* prev = NULL;

    // If first node has the required roll number
    if (ptr->rollno == roll) {
        start = ptr->next;
        delete ptr;

        cout << "\nStudent deleted successfully!\n";
        return;
    }


int main() {
    int choice;

    do {
        cout << "\n\n===== STUDENT RECORD MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. search Student ";
        cout << "\n4. delete Student";
        cout << "\n5. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {

        
            case 1:
                addStudent();
                break;

            case 2:
                display();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    }  while (choice != 5;

    return 0;
}



