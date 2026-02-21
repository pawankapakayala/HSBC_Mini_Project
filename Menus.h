#ifndef MENUS_H
#define MENUS_H

#include "MainClass.h"
#include "Works.h"
#include "Admin.h"

//Function Overloading: Overloaded Menu Function for Different Roles
void ShowMenu(Info &user) {
    cout << "\n====================================";
    cout << "\n||         USER MENU              ||";
    cout << "\n====================================";
    cout << "\n1. Check Balance";
    cout << "\n2. Deposit Money";
    cout << "\n3. Withdraw Money";
    cout << "\n4. View Transaction History";
    cout << "\n5. Exit";
    cout << "\nEnter choice: ";
}

void ShowMenu(Admin &admin) {
    cout << "\n====================================";
    cout << "\n||         ADMIN MENU              ||";
    cout << "\n====================================";
    cout << "\n1. View All Users";
    cout << "\n2. Delete User";
    cout << "\n3. View Transactions";
    cout << "\n4. Exit";
    cout << "\nEnter choice: ";
}

#endif // MENUS_H
