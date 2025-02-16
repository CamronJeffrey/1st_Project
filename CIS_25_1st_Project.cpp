// CIS_25_1st_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Bank_Management.h"

using namespace std;


int main() {
    string name;
    int id;
    
    cout << "Enter account holder name: ";
    getline(cin, name);
    cout << "Enter account ID/Password: ";
    cin >> id;
    
    Bank_Management account(name, id);
    
    int choice;
    double amount;
    
    do {
        cout << "\nBank Account Management System";
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. Display Account Details";
        cout << "\n4. Display Transaction History";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter deposit amount: ";
                cin >> amount;
                system("cls");
                account.deposit(amount);

                break;
            case 2:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                system("cls");
                account.withdraw(amount);
                break;
            case 3:
                system("cls");
                account.displayAccDetails();
                break;
            case 4:
                system("cls");
                account.displayTransactHist();
                break;
            case 5:
                system("cls");
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}

