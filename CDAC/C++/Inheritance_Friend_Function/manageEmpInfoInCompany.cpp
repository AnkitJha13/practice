// Create a system to manage employees in a company with the following structure:
// A base class Person with data members: name, age.
// A class Employee derived from Person, with additional attributes: empID, department.
// A class Salary that has salary-related attributes: basicPay, HRA, DA, grossPay.
// A class HR that is a friend class of Salary and calculates the gross pay.
// Create a class Manager that is derived from both Employee and Salary
// Requirements:
// demonstrate multiple inheritance.
// Use a friend function in HR to access and modify private data in Salary.
// Accept and display all details.
// Calculate and display the Gross Salary in the friend function.

#include <iostream>
using namespace std;

// Base Class
class Person {
protected:
    string name;
    int age;
public:
    void getPersonData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
    }
    void showPersonData() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// Derived Class from Person
class Employee : public Person {
protected:
    int empID;
    string department;
public:
    void getEmployeeData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cout << "Enter Department: ";
        cin >> department;
    }
    void showEmployeeData() {
        cout << "Employee ID: " << empID << "\nDepartment: " << department << endl;
    }
};

// Forward Declaration
class HR;

// Salary Class
class Salary {
private:
    float basicPay, HRA, DA, grossPay;

public:
    void getSalaryData() {
        cout << "Enter Basic Pay: ";
        cin >> basicPay;
        cout << "Enter HRA: ";
        cin >> HRA;
        cout << "Enter DA: ";
        cin >> DA;
    }

    void showSalaryData() {
        cout << "Basic Pay: " << basicPay << "\nHRA: " << HRA << "\nDA: " << DA << endl;
        cout << "Gross Pay: " << grossPay << endl;
    }

    // Friend Class
    friend class HR;
};

// HR Class that calculates grossPay
class HR {
public:
    void calculateGross(Salary &s) {
        s.grossPay = s.basicPay + s.HRA + s.DA;
    }
};

// Manager class using Multiple Inheritance
class Manager : public Employee, public Salary {
public:
    void inputAll() {
        getPersonData();
        getEmployeeData();
        getSalaryData();
    }

    void displayAll() {
        showPersonData();
        showEmployeeData();
        showSalaryData();
    }
};

int main() {
    Manager m;
    HR hr;

    cout << "Enter Manager Details:\n";
    m.inputAll();

    hr.calculateGross(m); // Friend class calculating gross salary

    cout << "\n--- Manager Details ---\n";
    m.displayAll();

    return 0;
}
