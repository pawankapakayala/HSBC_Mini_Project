#ifndef OTHERCLASSES_H
#define OTHERCLASSES_H

#include<iostream>
using namespace std;

// ✅ Classes & Objects: Defining a Class
class History {
public:
    // ✅ File Handling: Storing User Transactions
    static void AddHistory(const char* username, float amount, const char* action) {
        ofstream file("history.txt", ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        file << username << " " << action << " " << amount << endl;
        file.close();
    }

    // ✅ File Handling: Retrieving User History
    static void ShowHistory() {
        ifstream file("history.txt");
        if (!file) {
            cout << "No history available!" << endl;
            return;
        }
        string username, action;
        float amount;
        cout << "\n++ Transaction History ++\n";
        while (file >> username >> action >> amount) {
            cout << "User: " << username << " | Action: " << action << " | Amount: ₹" << amount << endl;
        }
        file.close();
    }
};

// ✅ Classes & Objects: Another Class for Account Dues
class Dues {
protected:
    float totalDues;
public:
    // ✅ Constructor & Initialization
    Dues(float dues = 0.0) { totalDues = dues; }

    // ✅ Encapsulation: Getter for Dues
    float getDues() { return totalDues; }

    // ✅ Operator Overloading: Overloading -= for Due Payments
    void operator-=(float amount) {
        if (totalDues >= amount) {
            totalDues -= amount;
            cout << "Dues Paid! Remaining Dues: ₹" << totalDues << endl;
        } else {
            cout << "No pending dues or invalid amount!" << endl;
        }
    }
};

#endif
