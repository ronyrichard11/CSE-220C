#include <iostream>
#include <string>
#include <vector>
#include <random>

struct Account {
    std::string accountID;
    std::string name;
    double balance;
};

struct Contact {
    std::string address;
    std::string city;
    std::string state;
    std::string zipCode;
    std::string phoneNumber;
};

std::vector<Account> accountList;
std::vector<Contact> contactList;

// Function to generate a random account ID
std::string generateAccountID() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1000, 9999);
    return std::to_string(dis(gen));
}

// Function to print account information
void printAccountInfo(const Account& account) {
    std::cout << "Account ID: " << account.accountID << std::endl;
    std::cout << "Name: " << account.name << std::endl;
    std::cout << "Balance: $" << account.balance << std::endl;
    std::cout << std::endl;
}

// Function to print contact information
void printContactInfo(const Contact& contact) {
    std::cout << "Address: " << contact.address << std::endl;
    std::cout << "City: " << contact.city << std::endl;
    std::cout << "State: " << contact.state << std::endl;
    std::cout << "Zip Code: " << contact.zipCode << std::endl;
    std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
    std::cout << std::endl;
}

// Function to find an account by ID
int findAccountByID(const std::string& accountID) {
    for (size_t i = 0; i < accountList.size(); i++) {
        if (accountList[i].accountID == accountID) {
            return static_cast<int>(i);
        }
    }
    return -1; // Account not found
}

void Menu() {
    std::cout << "\nATM Menu:\n" << std::endl;
    std::cout << "1. Print all accounts information" << std::endl;
    std::cout << "2. Add contact information" << std::endl;
    std::cout << "3. Deposit" << std::endl;
    std::cout << "4. Withdraw" << std::endl;
    std::cout << "5. Delete account" << std::endl;
    std::cout << "6. Total balance" << std::endl;
    std::cout << "7. Add dividend" << std::endl;
    std::cout << "8. Add account" << std::endl;
    std::cout << "9. Find account by ID" << std::endl;
    std::cout << "10. Quit" << std::endl;
}

void addContactInformation(std::vector<Contact>& contactList) {
    Contact contact;
    std::cout << "Enter Address: ";
    std::cin.ignore();
    std::getline(std::cin, contact.address);
    std::cout << "Enter City: ";
    std::getline(std::cin, contact.city);
    std::cout << "Enter State: ";
    std::getline(std::cin, contact.state);
    std::cout << "Enter Zip Code: ";
    std::getline(std::cin, contact.zipCode);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, contact.phoneNumber);
    contactList.push_back(contact);
}

void deposit(std::vector<Account>& accountList) {
    std::string accountID;
    double amount;
    std::cout << "Enter Account ID: ";
    std::cin >> accountID;
    int index = findAccountByID(accountID);
    if (index != -1) {
        std::cout << "Enter Deposit Amount: $";
        std::cin >> amount;
        accountList[index].balance += amount;
        std::cout << "Deposit successful." << std::endl;
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

void withdraw(std::vector<Account>& accountList) {
    std::string accountID;
    double amount;
    std::cout << "Enter Account ID: ";
    std::cin >> accountID;
    int index = findAccountByID(accountID);
    if (index != -1) {
        std::cout << "Enter Withdrawal Amount: $";
        std::cin >> amount;
        if (amount <= accountList[index].balance) {
            accountList[index].balance -= amount;
            std::cout << "Withdrawal successful." << std::endl;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

void deleteAccount(std::vector<Account>& accountList, std::vector<Contact>& contactList) {
    std::string accountID;
    std::cout << "Enter Account ID: ";
    std::cin >> accountID;
    int index = findAccountByID(accountID);
    if (index != -1) {
        accountList.erase(accountList.begin() + index);
        contactList.erase(contactList.begin() + index);
        std::cout << "Account deleted." << std::endl;
    } else {
        std::cout << "Account not found." << std::endl;
    }
}

void calculateTotalBalance(const std::vector<Account>& accountList) {
    double totalBalance = 0.0;
    for (const auto& account : accountList) {
        totalBalance += account.balance;
    }
    std::cout << "Total Balance: $" << totalBalance << std::endl;
}

void addDividend(std::vector<Account>& accountList) {
    double dividendPercent;
    std::cout << "Enter Dividend Percentage: ";
    std::cin >> dividendPercent;
    
    for (auto& account : accountList) {
        double dividendAmount = account.balance * (dividendPercent / 100);
        account.balance += dividendAmount;
    }
    
    std::cout << "Dividend added to all accounts." << std::endl;
}

void addAccount(std::vector<Account>& accountList) {
    Account account;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    std::getline(std::cin, account.name);
    std::cout << "Enter Balance: $";
    std::cin >> account.balance;
    account.accountID = generateAccountID();
    accountList.push_back(account);
    std::cout << "Account created successfully. Account ID: " << account.accountID << std::endl;
}

void findAccountByID(const std::vector<Account>& accountList, const std::vector<Contact>& contactList) {
    std::string accountID;
    std::cout << "Enter Account ID: ";
    std::cin >> accountID;
    int index = findAccountByID(accountID);
    if (index != -1) {
        printAccountInfo(accountList[index]);
        printContactInfo(contactList[index]);
    } else {
        std::cout << "Account not found." << std::endl;
    }
}
