#include <iostream>
#include "Bank_Management.h"

// This function helps with withdrawing money out of the account
void  Bank_Management::withdraw(double amount) {
    if (amount > 0 && amount <= balance && amount <= 20000) { //im also putting a limit to how much money you can withdraw from the account per withdraw.
        balance -= amount;
        transactHist.push_back("Withdrew: $" + to_string(amount));
        cout << "Withdrawal successful!\n";
    }
    else {
        cout << "Invalid withdrawal amount. Maximum withdrawal limit is $20,000 or insufficient balance. \n";
    }
}
 
