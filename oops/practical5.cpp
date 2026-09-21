#include <iostream>
#include <string>

using namespace std;

class PersonalRecord
{
protected:
    string name;
    int age;
    string address;
    string phoneno;
    string gender;

public:
    void acceptPersonalRecord()
    {
        cout << "Enter the personal data:\n";

        cout << "Name: ";
        getline(cin, name);

        cout << "Enter the age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter the address: ";
        getline(cin, address);

        cout << "Enter the phone no: ";
        getline(cin, phoneno);

        cout << "Enter the gender: ";
        getline(cin, gender);
    }

    void displayPersonalRecord()
    {
        cout << "\n--- Personal Data ---\n";
        cout << "Name       : " << name << endl;
        cout << "Age        : " << age << endl;
        cout << "Address    : " << address << endl;
        cout << "Phone No   : " << phoneno << endl;
        cout << "Gender     : " << gender << endl;
    }
};


class ProffesionalRecord
{
protected:
    string employeeID;
    string designation;
    string department;
    float salary;

public:
    void acceptProfessionalData()
    {
        cout << "\nEnter the professional details:\n";

        cout << "Enter the employee ID: ";
        getline(cin, employeeID);

        cout << "Enter the designation: ";
        getline(cin, designation);

        cout << "Enter the department: ";
        getline(cin, department);

        cout << "Enter the salary: ";
        cin >> salary;
        cin.ignore();
    }

    void displayProfessionalRecord()
    {
        cout << "\n--- Professional Data ---\n";
        cout << "Employee ID : " << employeeID << endl;
        cout << "Designation : " << designation << endl;
        cout << "Department  : " << department << endl;
        cout << "Salary      : " << salary << endl;
    }
};


class AcademicRecord
{
protected:
    string qualification;
    string university;
    float cgpa;

public:
    void acceptAcademicRecord()
    {
        cout << "\nEnter the academic details:\n";

        cout << "Enter the qualification: ";
        getline(cin, qualification);

        cout << "Enter the university: ";
        getline(cin, university);

        cout << "Enter the CGPA: ";
        cin >> cgpa;
        cin.ignore();
    }

    void displayAcademicRecord()
    {
        cout << "\n--- Academic Data ---\n";
        cout << "Qualification : " << qualification << endl;
        cout << "University    : " << university << endl;
        cout << "CGPA          : " << cgpa << endl;
    }
};


// Multiple Inheritance
class Employee : public PersonalRecord,
                 public ProffesionalRecord,
                 public AcademicRecord
{
public:
    void acceptAllRecords()
    {
        acceptPersonalRecord();
        acceptProfessionalData();
        acceptAcademicRecord();
    }

    void displayAllRecords()
    {
        displayPersonalRecord();
        displayProfessionalRecord();
        displayAcademicRecord();
    }
};


int main()
{
    Employee e;

    cout << "========== ENTER EMPLOYEE DETAILS ==========\n";

    e.acceptAllRecords();

    cout << "\n\n========== EMPLOYEE RECORD ==========\n";

    e.displayAllRecords();

    return 0;
}

