#include <iostream>
#include "Bank_Management.h"

// This function Displays the Account Details
void  Bank_Management::displayAccDetails() const {
    cout << "\n===== Account Details =====" << endl;
    cout << "\nAccount Holder: " << account << endl;
    cout << "Account ID: " << IdPassword << endl;
    cout << "Balance: $" << balance << endl;
    cout << "==========================\n" << endl;
}
