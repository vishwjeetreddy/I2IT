#include <iostream>
#include <string>
using namespace std;

struct node {
    int rollno;
    string name;
    int marks;
    node* next;

    node() {
        next = NULL;
    }

    void insert() {
        cout << "Enter Student Name: ";
        cin >> name;

        cout << "Enter Student Roll No.: ";
        cin >> rollno;

        cout << "Enter Student Marks: ";
        cin >> marks;
    }
};

node* start = NULL;

void insertStudent() {
    node* temp = new node;

    temp->insert();

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

    cout << "\nStudent inserted successfully!\n";
}

void display() {
    node* ptr = start;

    if (ptr == NULL) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\nRoll No.\tName\tMarks\n";
    cout << "--------------------------------\n";

    while (ptr != NULL) {
        cout << ptr->rollno << "\t\t"
             << ptr->name << "\t"
             << ptr->marks << endl;

        ptr = ptr->next;
    }
}

int main() {
    int choice;

    do {
        cout << "\n\n===== STUDENT RECORD SYSTEM =====";
        cout << "\n1. Insert Student";
        cout << "\n2. Display Students";
        cout << "\n3. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertStudent();
                break;

            case 2:
                display();
                break;

            case 3:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 3);

    return 0;
}
