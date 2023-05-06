//
//  Week02.cpp
//  Second Week Learning C++ Assignment
//
//  Created by Rony Richard on 28st April, 2023
//
//  Goal: To Replicate a simple ATM Program using Classes

// Libraries and directives for Windows/Linux-based machines necessary to compile this program
#ifdef _WIN32
  #define _CRT_SECURE_NO_WARNINGS
#endif /* _WIN32 */

#include <iostream> // for cout, cin
#include <string>   // for string
using namespace std;

class BankAccount{
    private:

    int accountID;
    string accountName;
    float accountBalance;

    public:
    // Constructor
    BankAccount(int id, string name, float balance){
        accountID = id;
        accountName = name;
        accountBalance = balance;
    }


    // Accesspr Methods
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
    }
};

int main(){
    int id_num = rand() % 99999 + 13427;
    string name = "";
    float balance = 0.0f;
    int choice;

    cout << "Enter Account Name: ";
    cin >> name;
    cout << "What is the present Balance? $";
    cin >> balance;

    BankAccount myAccount(id_num, name, balance);

    float value;

    do {
        // Print the menu options
        cout << "-------------------------------------\n";
        cout << "Menu\n\n";
        cout << "1. Display Account Information\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Quit\n";
        
        // Read user choice from input
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << "\n";
        // Perform action based on user choice
        switch (choice) {
            case 1:
                // Display Account information
                cout << "You chose Option 1\n\n";
                myAccount.printAccountInfo();
                break;
            case 2:
                // Deposit Money
                cout << "You chose Option 2\n\n";
                cout << "How much would you like to DEPOSIT? $";
                cin >> value;
                myAccount.deposit(value);
                value = 0;
                break;
            case 3:
                // Withdraw Money
                cout << "You chose Option 3\n\n";
                cout << "How much would you like to WITHDRAW? $";
                cin >> value;
                myAccount.withdraw(value);
                value = 0;
                break;
            case 4:
                // Break
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        
    } while (choice != 4);
    
    return 0;
}