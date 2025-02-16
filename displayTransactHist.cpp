#include <iostream>
#include "Bank_Management.h"


// This function Displays the Transaction History
void  Bank_Management::displayTransactHist() const {
    cout << "\nTransaction History:" << endl;
    for (const auto& transaction : transactHist) {
        cout << transaction << endl;
    }
    cout << "Total Balance: $" << balance << endl;
}

