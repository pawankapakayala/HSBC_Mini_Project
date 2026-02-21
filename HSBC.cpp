#include "Menus.h"

int main()
{
    // Clearing the screen for a fresh UI (System Dependent)
    system("cls");

    Info user; // Object Creation (Classes & Objects: Creating Objects)
    
    ifstream iFile;
    char un[7], pa[15];
    bool check = false;
    
    // Opening file in binary mode (File Handling: File Streams, Binary File Handling)
    iFile.open(file, ios::binary);
    if (!iFile)
    {
        cout << "File does not exist.....";
        system("PAUSE");
        return 0;
    }
    
    try
    {
        cout << "\n\n\t\tRedg_no:";
        cin >> un;
        
        // Reading from binary file (File Handling: Reading from files, Binary File Handling)
        while (iFile.read((char *)&user, sizeof(user)))
        {
            if (!strcmp(user.getuser(), un)) // Checking user credentials
            {
                check = true;
                break;
            }
        }
        if (!check)
            throw un; // Exception Handling (Exception Handling: Throwing Exceptions)
    }
    catch (char *user)
    {
        iFile.close();
        cout << "\n\n\t\t" << user << " is not a valid user name....";
        system("PAUSE");
        main(); // Recursively calling main (Not recommended, should use a loop instead)
    }
    
    iFile.close(); // Closing the file (File Handling: Closing Files)
    
    char ch;
    int i = 0;
    
    try
    {
        cout << "\t\tPassword:";
        
        while (1)
        {
            ch = getch(); // Taking input without displaying it (Masked Input for Security)
            if (ch == '\r') // If Enter key is pressed
            {
                pa[i] = '\0';
                cout << endl;
                break;
            }
            if (ch == '\b') // Handling Backspace
            {
                if (i <= 0)
                    continue;
                cout << '\b';
                i--;
                continue;
            }
            pa[i] = ch;
            i++;
            cout << '*'; // Printing * instead of actual password characters
        }
        
        if (strcmp(user.getpass(), pa))
            throw 0; // Exception Handling (Exception Handling: Handling Different Exception Types)
    }
    catch (int pass)
    {
        cout << "\n\n\t\tPlease check your password and try again....";
        system("PAUSE");
        main(); // Recursively calling main (Not recommended, should use a loop instead)
    }
    
    // Menu Selection Based on User Department (Polymorphism can be used here instead)
    switch (user.getdepartment())
    {
        case 0: DefaultMenu(user); return 0;
        case 1: SaireplicaMenu(user); return 0;
        case 2: SFCMenu(user); return 0;
        case 3: StoresMenu(user); return 0;
        case 4: HeMenu(user); return 0;
        case 5: AdminMenu(user); return 0;
    }
}
