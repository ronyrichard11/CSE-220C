//
//  Main.cpp
//  Third Week Learning C++ Assignment
//
//  Created by Rony Richard on 6th May, 2023
//
//  Goal: To Replicate a simple ATM Program using more advanced systems

// Libraries and directives for Windows/Linux-based machines necessary to compile this program

#ifdef _WIN32
  #define _CRT_SECURE_NO_WARNINGS
#endif /* _WIN32 */

#include <iostream> // for cout, cin
#include <string>   // for string
#include <list>     // for list
#include <algorithm>
#include "Account.hpp"
using namespace std;



int main(){

    int id_num = rand() % 9999 + 10000;
    string name = "";
    float balance = 0.0f;
    int choice;
    float total = 0.0f;
    list<BankAccount> accounts;

    cout << "Enter Account Name: ";
    cin >> name;
    cout << "What is the present Balance? $";
    cin >> balance;

    BankAccount myAccount(id_num, name, balance);
    accounts.push_back(myAccount);

    float value;

    auto it = accounts.end(); // Declare and initialize it here

    do {
        // Print the menu options
        cout << "-------------------------------------\n"
             << "Menu\n\n"
             << "1. Display Account Information\n"
             << "2. Deposit\n"
             << "3. Withdraw\n"
             << "4. Find Account by ID\n"
             << "5. Delete Account\n"
             << "6. Total Balance\n"
             << "7. Add Dividend\n"
             << "8. Add Account\n"             
             << "9. Quit\n";

        
        // Read user choice from input
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << "\n";
        // Perform action based on user choice
        switch (choice) {
            case 1:
                // Display Account information
                cout << "You chose Option 1\n\n";
                for (auto account : accounts){
                    account.printAccountInfo();
                    cout << "\n";
                }           
                break;
    
            case 2:
                // Deposit
                cout << "You chose Option 2\n\n";
                int deposit_id;
                cout << "Enter Account ID: ";
                cin >> deposit_id;
                it = find_if(accounts.begin(), accounts.end(), [&](BankAccount& account) {
                    return account.matchesAccountID(deposit_id);
                });
                if (it == accounts.end()) {
                    cout << "Account not found." << endl;
                } else {
                    float deposit_amount;
                    cout << "Enter deposit amount: $";
                    cin >> deposit_amount;
                    it->deposit(deposit_amount);
                    cout << "Deposit successful." << endl;
                }
                break;

            case 3:
                // Withdraw
                cout << "You chose Option 3\n\n";
                int withdraw_id;
                cout << "Enter Account ID: ";
                cin >> withdraw_id;
                it = find_if(accounts.begin(), accounts.end(), [&](BankAccount& account) {
                    return account.matchesAccountID(withdraw_id);
                });
                if (it == accounts.end()) {
                    cout << "Account not found." << endl;
                } else {
                    float withdraw_amount;
                    cout << "Enter withdrawal amount: $";
                    cin >> withdraw_amount;
                    it->withdraw(withdraw_amount);
                    cout << "Withdrawal successful." << endl;
                }
                break;
            
            case 4:
                // Display Account information
                cout << "You chose Option 4\n\n";
                int display_id;
                cout << "Enter Account ID: ";
                cin >> display_id;
                it = find_if(accounts.begin(), accounts.end(), [&](BankAccount& account) {
                    return account.matchesAccountID(display_id);
                });
                if (it == accounts.end()) {
                    cout << "Account not found." << endl;
                }
                else {
                    it->printAccountInfo();
                } 
                break;

            case 5: 
                // Delete A Bank Account
                int AccountToDelete;
                cout << "Enter the Account ID for the Account you would like to Delete: ";
                cin >> AccountToDelete;
                it = find_if(accounts.begin(), accounts.end(), [&](BankAccount& account){
                    return account.matchesAccountID(AccountToDelete);
                });
                if (it == accounts.end()){
                    cout << "Account not found.\n";
                }
                else {
                    it = accounts.erase(it);
                }

                break;

            case 6:
                // Total Balance
                for (auto account : accounts){
                    total += account.getAccountBalance();
                }  
                cout << total << "\n";

            break;   
            
            case 7:
                // Add Dividend to all accounts
                float dividendPercentage;
                cout << "Enter the percentage of the dividend: ";
                cin >> dividendPercentage;

                transform(accounts.begin(), accounts.end(), accounts.begin(), [&](BankAccount& account) {
                    account *= (dividendPercentage);
                    return account;
                });

                cout << "Dividend added to all accounts successfully." << endl;
                break;

            case 8:
                // Create Another Bank Account
                int id_num = rand() % 9999 + 10000;

                cout << "Enter Account Name: ";
                cin >> name;
                cout << "What is the present Balance? $";
                cin >> balance;

                BankAccount myAccount(id_num, name, balance);
                accounts.push_back(myAccount);
                break;
            }
        
    } while (choice != 9);
    
    return 0;   
}
