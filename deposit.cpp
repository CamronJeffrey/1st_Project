#include <iostream>
#include "Bank_Management.h"

// This function helps with depositing money into the account
void  Bank_Management::deposit(double amount) {
    if (amount > 0 && amount <= 10000) {  //making a limit to how much money you can put in per deposit. 
        balance += amount;
        transactHist.push_back("Deposited: $" + to_string(amount));
        cout << "Deposit successful!\n";
    }
    else {
        cout << "Invalid deposit amount, please input a valid amount\n";
        cout << "The maximun limit per deposit is $10,000. \n";
    }
} 
