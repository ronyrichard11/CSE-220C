//
//  Week01.cpp
//  First Week Learning C++ Assignment
//
//  Created by Rony Richard on 21st April, 2023
//
//  Goal: To Replicate a simple ATM Program

// Libraries and directives for Windows/Linux-based machines necessary to compile this program
#ifdef _WIN32
  #define _CRT_SECURE_NO_WARNINGS
#endif /* _WIN32 */

#include <iostream> // for cout, cin
#include <string>   // for string
using namespace std;


int main() {
    int id_num = rand() % 99999 + 13427;
    string name = "";
    float balance = 0.0f;
    int choice;

    cout << "Enter Account Name: ";
    cin >> name;
    cout << "What is the present Balance? $";
    cin >> balance;
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
                cout << "Account ID: " << id_num << "\n";
                cout << "Account Name: " << name << "\n";
                cout << "Current Balance: $" << balance << "\n";
                break;
            case 2:
                // Deposit Money
                cout << "You chose Option 2\n\n";
                cout << "How much would you like to DEPOSIT? $";
                cin >> value;
                balance = value + balance;
                value = 0;
                break;
            case 3:
                // Withdraw Money
                cout << "You chose Option 3\n\n";
                cout << "How much would you like to WITHDRAW? $";
                cin >> value;
                balance = balance - value;
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