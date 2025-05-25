


# Peer Code Review by Hania G

##  Project: Bank Management System

This review evaluates the code specifically to the ``Bank_Management` implementation files.

---


### 2. code Structure 
- files are not organized, there are no src folders, no include folders, no include files, and the read me is incomplete and badly formatted
- ** it's Missing CMake or build system**: No `CMakeLists.txt` or build instructions provided.
-  Main function is logically separated from business logic in a class.
-  Multiple header files contain fragmented declarations instead of centralized, organized headers.

**Suggestion**:  
Create one complete `Bank_Management.h` header file & remove the redundant mini-header files for each function.

---

###  Modularity & Readability
- Clear function separation (deposit, withdraw, display).
Inconsistent naming and formatting conventions.
- Some function names are abbreviated (`displayTransactHist`) — consider using full, descriptive names for better readibility.

**Suggestion**:  
Use more descriptive function names & consistent camelCase or snake_case style across the project.

---

###  Tests
-  No unit tests are implemented.
-  No input validation for edge cases (negative deposit/withdrawal, non-numeric input).
-  Some logic constraints are enforced (transaction limits).

**Suggestion**:  
Implement Google Test cases for both valid and invalid inputs, especially edge cases.

---

###  Bugs Identified
- `cin` inputs are not error-checked  entering a letter instead of a number causes infinite loop or crash).
- `displayTransactHist()` function is incomplete and has a misplaced `}`.
-  No separation between account creation and authentication — no real security for ID/password.

---

### Clarity & formatting
-  Transaction messages are printed after each operation.
-  Output could be more readable with better formatting.
-  Transaction history lacks timestamps or structure.

**Suggestion**:  
Add timestamps or at least sequence numbers to transaction logs for clarity.

---

##  New Google Test Cases

```cpp
// Test 1: Deposit valid amount
TEST(BankManagementTest, Deposit_ValidAmount) {
    Bank_Management acc("Test User", 1234);
    acc.deposit(1000);
    EXPECT_EQ(acc.getBalance(), 1000);
}

// Test 2: Deposit exceeding limit
TEST(BankManagementTest, Deposit_ExceedsLimit) {
    Bank_Management acc("Test User", 1234);
    acc.deposit(15000);
    EXPECT_EQ(acc.getBalance(), 0); 
}

// Test 3: Withdraw more than available balance
TEST(BankManagementTest, Withdraw_InsufficientFunds) {
    Bank_Management acc("Test User", 1234);
    acc.deposit(500);
    acc.withdraw(600);
    EXPECT_EQ(acc.getBalance(), 500); 
}

// Test 4: Withdraw within limit
TEST(BankManagementTest, Withdraw_ValidAmount) {
    Bank_Management acc("Test User", 1234);
    acc.deposit(1000);
    acc.withdraw(300);
    EXPECT_EQ(acc.getBalance(), 700);
}

// Test 5: Transaction history logs correctly
TEST(BankManagementTest, TransactionHistoryLogs) {
    Bank_Management acc("Test User", 1234);
    acc.deposit(200);
    acc.withdraw(100);
    auto history = acc.getTransactionHistory(); 
    EXPECT_EQ(history.size(), 2);
}