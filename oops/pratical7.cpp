#include <iostream>
#include <string>
using namespace std;

// User-defined exception class
class UserException {
public:
    string message;

    UserException(string msg) {
        message = msg;
    }
};

int main() {
    int age;
    double income;
    string city;
    string vehicle;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter monthly income: ";
    cin >> income;

    cout << "Enter city: ";
    cin >> city;

    cout << "Does user have a 4-wheeler? (yes/no): ";
    cin >> vehicle;

    try {
        // Check age
        if (age < 18 || age > 55) {
            throw UserException("Age must be between 18 and 55.");
        }

        // Check income
        if (income < 50000 || income > 100000) {
            throw UserException(
                "Income must be between Rs. 50,000 and Rs. 1,00,000 per month."
            );
        }

        // Check city
        if (city != "Pune" &&
            city != "Mumbai" &&
            city != "Bangalore" &&
            city != "Chennai") {

            throw UserException(
                "User must stay in Pune, Mumbai, Bangalore, or Chennai."
            );
        }

        // Check vehicle
        if (vehicle != "yes") {
            throw UserException("User must have a 4-wheeler.");
        }

        cout << "\nUser satisfies all the required conditions." << endl;
    }
    catch (UserException &e) {
        cout << "\nException: " << e.message << endl;
    }

    return 0;
}
