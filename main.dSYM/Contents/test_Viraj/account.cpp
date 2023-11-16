#include <iostream>
#include <string>

using namespace std;

// Structure to represent a bank account
struct BankAccount {
    string accountNumber;
    double balance;
    BankAccount* next;

    BankAccount(const string& accNumber, double initBalance) : accountNumber(accNumber), balance(initBalance), next(nullptr) {}
};

// Linked list class to manage bank accounts
class BankAccountList {
private:
    BankAccount* head;

public:
    BankAccountList() : head(nullptr) {}

    // Function to add a new account to the linked list
    void addAccount(const string& accNumber, double initBalance) {
        BankAccount* newAccount = new BankAccount(accNumber, initBalance);
        newAccount->next = head;
        head = newAccount;
    }

    // Function to get the balance of an account given its account number
    double getBalance(const string& accNumber) {
        BankAccount* current = head;
        while (current != nullptr) {
            if (current->accountNumber == accNumber) {
                return current->balance;
            }
            current = current->next;
        }
        return -1;  // Return -1 if the account is not found
    }

    // Function to deposit money into an account
    void deposit(const string& accNumber, double amount) {
        BankAccount* current = head;
        while (current != nullptr) {
            if (current->accountNumber == accNumber) {
                current->balance += amount;
                cout << "Deposit successful. New balance: " << current->balance << endl;
                return;
            }
            current = current->next;
        }
        cout << "Account not found. Deposit failed." << endl;
    }

    // Function to withdraw money from an account
    void withdraw(const string& accNumber, double amount) {
        BankAccount* current = head;
        while (current != nullptr) {
            if (current->accountNumber == accNumber) {
                if (current->balance >= amount) {
                    current->balance -= amount;
                    cout << "Withdrawal successful. New balance: " << current->balance << endl;
                } else {
                    cout << "Insufficient funds. Withdrawal failed." << endl;
                }
                return;
            }
            current = current->next;
        }
        cout << "Account not found. Withdrawal failed." << endl;
    }
};

int main() {
    // Example usage of the BankAccountList class
    BankAccountList accounts;

    // Add some accounts
    accounts.addAccount("123456", 1000.0);
    accounts.addAccount("789012", 500.0);

    // Deposit and withdraw money
    accounts.deposit("123456", 200.0);
    accounts.withdraw("789012", 100.0);

    // Get balances
    cout << "Balance for account 123456: " << accounts.getBalance("123456") << endl;
    cout << "Balance for account 789012: " << accounts.getBalance("789012") << endl;

    return 0;
}
