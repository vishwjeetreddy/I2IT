#include<iostream>
#include<string>
using namespace std;

class UserException{
    public:
    string message;

    UserException(string msg) {
        message = msg;
    }
};

int main(){
    int age;
    double income;
    string city;
    string vehicle;

    cout<<"enter the age: ";
    cin>>age;

    cout<<"enter the monthly income: ";
    cin>>income;

    cout<<"enter the city: ";
    cin>>city;

    cout<<"dose user have a 4 wheeler ? (yes/no): ";
    cin>>vehicle;

    try{
        if (age <18 || age >55){
            throw UserException("age musr be between 18 and 55.");

         }

        if (income < 50000 || income > 100000){
            throw UserException("income must be between rs. 50000 and rs. 100000 per month.");

        }

        if (city != "pune"&&
            city != "mumbai"&&
            city != "bangalore"&&
            city != "chennai"){

                throw UserException("user must in pune , mumbai , bangalore, chennai.");

            }
        if (vehicle != "yes"){
            throw UserException ("user must have a 4 wheeler.");
        }

        cout<<"\n user satisfies all the required conndition."<<endl;


    }
    catch (UserException&e){
        cout<<"\nException:"<<e.message<<endl;

    }
    return 0;

}

