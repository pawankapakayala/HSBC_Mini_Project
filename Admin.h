#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include "MainClass.h" // Ensuring dependency on MainClass
using namespace std;

// ✅ Classes & Objects: Defining an Admin Class
class Admin {
public:
    // ✅ Function to View All Users (Uses File Handling)
    static void ViewAllUsers() {
        ifstream file("userinfo.dat", ios::binary);
        if (!file) {
            cout << "-- No user data found! --" << endl;
            return;
        }

        Info user; // ✅ Object Creation: Using Info class
        cout << "\n++ All Registered Users ++\n";
        cout << "-----------------------------------\n";
        while (file.read(reinterpret_cast<char*>(&user), sizeof(user))) {
            cout << ">> Username: " << user.getuser() << " | Balance: ₹" << user.getbalance() << endl;
        }
        cout << "-----------------------------------\n";
        file.close();
    }

    // ✅ Function to Delete a User (File Handling)
    static void DeleteUser(const char* username) {
        ifstream file("userinfo.dat", ios::binary);
        ofstream tempFile("temp.dat", ios::binary);

        if (!file || !tempFile) {
            cout << "-- Error: Unable to open file! --" << endl;
            return;
        }

        Info user;
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&user), sizeof(user))) {
            if (strcmp(user.getuser(), username) != 0) {
                tempFile.write(reinterpret_cast<char*>(&user), sizeof(user));
            } else {
                found = true;
            }
        }

        file.close();
        tempFile.close();
        remove("userinfo.dat");
        rename("temp.dat", "userinfo.dat");

        if (found) {
            cout << "-- User " << username << " deleted successfully! --" << endl;
        } else {
            cout << "-- User not found! --" << endl;
        }
    }
};

#endif
