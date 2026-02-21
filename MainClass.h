#ifndef MAINCLASS_H
#define MAINCLASS_H

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

// ✅ Classes & Objects: Defining a Class
class Info {
protected:
    char username[20]; // Stores the username
    char password[20]; // Stores the password
    float balance; // Stores the account balance

public:
    // ✅ Constructors & Destructors: Parameterized Constructor
    Info(const char *un = "", const char *pw = "", float bal = 0.0) {
        strcpy(username, un);
        strcpy(password, pw);
        balance = bal;
    }

    // ✅ Encapsulation: Getters for private members
    const char* getuser() { return username; }
    const char* getpass() { return password; }
    float getbalance() { return balance; }

    // ✅ File Handling: Writing to File
    void AddUser() {
        ofstream file("userinfo.dat", ios::binary | ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        file.write(reinterpret_cast<char*>(this), sizeof(*this));
        file.close();
    }

    // ✅ File Handling: Reading from File
    void ShowUsers() {
        ifstream file("userinfo.dat", ios::binary);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        while (file.read(reinterpret_cast<char*>(this), sizeof(*this))) {
            cout << "Username: " << username << " | Balance: " << balance << endl;
        }
        file.close();
    }

    // ✅ Function Overloading: Overloading the + operator
    void operator+(float amount) {
        balance += amount;
        cout << "New Balance: " << balance << endl;
    }

    // ✅ Function Overloading: Overloading the - operator
    void operator-(float amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Transaction Successful! Remaining Balance: " << balance << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }
};

#endif
