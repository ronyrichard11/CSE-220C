#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Main.hpp"


int main() {
    int choice;

    while (true) {
        
        Menu();

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n";

        switch (choice) {
            case 1:
            std::cout << "Account Information:\n" << std::endl;
            for (size_t i = 0; i < accountList.size(); i++) {
                const Account& account = accountList[i];
                printAccountInfo(account);
                if (i < contactList.size()) {
                    const Contact& contact = contactList[i];
                    printContactInfo(contact);
                }
                std::cout << std::endl;
            }
            break;

            case 2:
                addContactInformation(contactList);
                break;


            case 3:
                deposit(accountList);
                break;


            case 4:
                withdraw(accountList);
                break;


            case 5:
                deleteAccount(accountList, contactList);
                break;


            case 6:
                calculateTotalBalance(accountList);
                break;


            case 7:
                addDividend(accountList);
                break;

            case 8:
                addAccount(accountList);
                break;


            case 9:
                findAccountByID(accountList, contactList);
                break;


            case 10:
                std::cout << "Quitting the program..." << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
