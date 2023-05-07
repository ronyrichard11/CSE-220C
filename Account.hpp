#ifdef _WIN32
  #define _CRT_SECURE_NO_WARNINGS
#endif /* _WIN32 */

#include <iostream> // for cout, cin
#include <string>   // for string
#include <list>     // for list

using namespace std;

class BankAccount{
    private:

    int accountID;
    string accountName;
    float accountBalance;
    list<BankAccount> accounts;


    public:
    // Constructor
    BankAccount(int id, string name, float balance){
    accountID = id;
    accountName = name;
    accountBalance = balance;
    }

    // Accessor Methods
    int getAccountID() {
        return accountID;
    }

    string getAccountName() {
        return accountName;
    }

    float getAccountBalance() {
        return accountBalance;
    }

    // Mutator methods
    void setAccountID(int id) {
        accountID = id;
    }

    void setAccountName(string name) {
        accountName = name;
    }

    void setAccountBalance(float balance) {
        accountBalance = balance;
    }

    // Deposit method
    void deposit(float amount) {
        accountBalance += amount;
    }

    // Withdrawal method
    void withdraw(float amount) {
        if (amount <= accountBalance) {
            accountBalance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    // Print account information
    void printAccountInfo() {
        cout << "Account ID: " << accountID << endl;
        cout << "Account Name: " << accountName << endl;
        cout << "Account Balance: $" << accountBalance << endl;

    };

    bool matchesAccountID(int id) {
    return accountID == id;
    }

};