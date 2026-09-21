#include <iostream>
#include <string>
#include <limits>
using namespace std;

class info
{
private:
    string nm, drv_lic, cl, dob;
    int roll;
    string div, bdgp;

public:
    info()
    {
        nm = "";
        dob = "";
        cl = "";
        div = "";
        bdgp = "";
        drv_lic = "";
        roll = 0;
    }

    friend class addinfo;

    void inputinfo()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n\n_______________*STUDENT DATABASE*______________\n\n";

        cout << "Student Name: ";
        getline(cin, nm);

        cout << "\nClass: ";
        getline(cin, cl);

        cout << "\nDivision: ";
        cin >> div;

        cout << "\nRoll number: ";
        cin >> roll;

        cout << "\nDate of Birth (Format- dd/mm/yyyy): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, dob);

        cout << "\nBlood Group (A+, A-, B+, B-, AB+, AB-, O+, O-): ";
        cin >> bdgp;

        cout << "\nEnter driving licence number: ";
        cin >> drv_lic;
    }
};

class addinfo
{
public:
    string ctnum;

    void getinfo()
    {
        cout << "\nContact Number: ";
        cin >> ctnum;

        if (ctnum.length() != 10)
        {
            cout << "\nException caught!";
            cout << "\nContact number must contain exactly 10 digits.";
            cout << "\nTry again!";
            
            cout << "\nContact Number: ";
            cin >> ctnum;
        }
    }

    int getroll(info &obj)
    {
        return obj.roll;
    }

    void show(info &obj);
};

void addinfo::show(info &obj)
{
    cout << "\nStudent Name: " << obj.nm;
    cout << "\nClass: " << obj.cl;
    cout << "\nDivision: " << obj.div;
    cout << "\nRoll number: " << obj.roll;
    cout << "\nDate of Birth: " << obj.dob;
    cout << "\nBlood Group: " << obj.bdgp;
    cout << "\nDriving licence number: " << obj.drv_lic;
    cout << "\nContact Number: " << ctnum;
    cout << "\n-------------------------------------\n";
}

int main()
{
    info x[30];
    addinfo s[30];

    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    if (n < 1 || n > 30)
    {
        cout << "\nInvalid number of students!";
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n---------------------------------------\n";
        cout << "\nEnter Details of student " << i + 1;

        x[i].inputinfo();
        s[i].getinfo();
    }

    cout << "\n_____________________________________________________________\n";

    for (int i = 0; i < n; i++)
    {
        s[i].show(x[i]);
    }

    while (true)
    {
        int r, ch;
        int flag = 0;

        cout << "\nEnter student roll number to get info: ";
        cin >> r;

        for (int i = 0; i < n; i++)
        {
            if (r == s[i].getroll(x[i]))
            {
                s[i].show(x[i]);
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            cout << "\nRecord not found!";

        cout << "\nDo you want to continue? (Enter 1 for Yes, 0 for No): ";
        cin >> ch;

        if (ch != 1)
            break;
    }

    cout << "\nEnding the Program!";

    return 0;
}
