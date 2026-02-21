#ifndef WORKS_H
#define WORKS_H

#include<iostream>
#include<fstream>
using namespace std;

// ✅ Classes & Objects: Defining a Class
class Works {
public:
    // ✅ Static Members: Keeping track of total transactions
    static int TotalTransactions;
    
    // ✅ File Handling: Writing Transaction Details
    static void LogTransaction(const char* username, float amount, const char* type) {
        ofstream file("transactions.txt", ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        file << username << " " << type << " " << amount << endl;
        file.close();
        TotalTransactions++;
    }

    // ✅ File Handling: Reading Transactions
    static void ShowTransactions() {
        ifstream file("transactions.txt");
        if (!file) {
            cout << "No transactions found!" << endl;
            return;
        }
        string username, type;
        float amount;
        cout << "\n++ Transaction History ++\n";
        while (file >> username >> type >> amount) {
            cout << "User: " << username << " | Type: " << type << " | Amount: ₹" << amount << endl;
        }
        file.close();
    }
};

// ✅ Static Members: Initializing the Static Variable
int Works::TotalTransactions = 0;

#endif
