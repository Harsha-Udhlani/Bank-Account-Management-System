#include <bits/stdc++.h>
using namespace std;

// BankAccount Class - Represents an individual bank account
class BankAccount
{
private:
    int balance;
    static int accCounter;

public:
    int accountNumber;
    string accountHolder;
    vector<string> transactionHistory;
    BankAccount()
    {
        accountNumber = 0;
        accountHolder = "";
        balance = 0;
    }
    BankAccount(string accH, int bal)
    {
        this->accountNumber = accCounter++;
        this->accountHolder = accH;
        this->balance = bal;
    }

    void displayAccount()
    {
        cout << "\n===== Account Details =====\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Account Holder: " << accountHolder << "\n";
        cout << "Balance: Rs." << balance << "\n";
    }

    void deposit(int amt)
    {
        if (amt <= 0)
        {
            cout << "Invalid Deposit Amount!\n";
            return;
        }
        balance += amt;
        transactionHistory.push_back("Deposited Rs: " + to_string(amt));
        cout << "Deposit Successful! New Balance: Rs." << balance << "\n";
    }

    void withdraw(int amt)
    {
        if (amt <= 0)
        {
            cout << "Invalid Withdrawal Amount!\n";
            return;
        }
        if (amt > balance)
        {
            cout << "Insufficient Balance!\n";
            return;
        }
        balance -= amt;
        transactionHistory.push_back("Withdrawn Rs: " + to_string(amt));
        cout << amt << " Withdrawn. Available balance: Rs." << balance << "\n";
    }

    void showTransactionHistory()
    {
        if (transactionHistory.empty())
        {
            cout << "No Transactions Yet!\n";
            return;
        }
        cout << "Transaction History for Account " << accountNumber << ":\n";
        for (const string &t : transactionHistory)
        {
            cout << "- " << t << "\n";
        }
    }

    int getBalance() { return balance; }
};
int BankAccount::accCounter = 1; // Initialize static variable

// BankSystem Class - Manages multiple accounts
class BankSystem
{
private:
    map<int, BankAccount> accounts; // Stores all accounts (Account Number -> BankAccount)

public:
    void createAccount(string accHolder, int initialBalance)
    {
        BankAccount newAcc(accHolder, initialBalance);
        accounts[newAcc.accountNumber] = newAcc;
        cout << "Account created successfully! Your Account Number is " << newAcc.accountNumber << "\n";
    }

    void deposit(int accNumber, int amount)
    {
        if (accounts.find(accNumber) != accounts.end())
        {
            accounts[accNumber].deposit(amount);
        }
        else
        {
            cout << "Account not found!\n";
        }
    }

    void withdraw(int accNumber, int amount)
    {
        if (accounts.find(accNumber) != accounts.end())
        {
            accounts[accNumber].withdraw(amount);
        }
        else
        {
            cout << "Account not found!\n";
        }
    }

    void showTransactionHistory(int accNumber)
    {
        if (accounts.find(accNumber) != accounts.end())
        {
            accounts[accNumber].showTransactionHistory();
        }
        else
        {
            cout << "Account not found!\n";
        }
    }

    void displayAccount(int accNumber)
    {
        if (accounts.find(accNumber) != accounts.end())
        {
            accounts[accNumber].displayAccount();
        }
        else
        {
            cout << "Account not found!\n";
        }
    }

    void deleteAccount(int accNumber)
    {
        if (accounts.erase(accNumber))
        {
            cout << "Account deleted successfully!\n";
        }
        else
        {
            cout << "Account not found!\n";
        }
    }
};

// Main Function - Menu-driven system
int main()
{
    BankSystem bank;
    while (true)
    {
        cout << "\n======= BANK ACCOUNT MANAGEMENT =======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Show Transaction History\n";
        cout << "5. Display Account Details\n";
        cout << "6. Delete Account\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            int balance;
            cout << "Enter Account Holder Name: ";
            cin >> name;
            cout << "Enter Initial Balance: ";
            cin >> balance;
            bank.createAccount(name, balance);
            break;
        }
        case 2:
        {
            int accNumber, amount;
            cout << "Enter Account Number: ";
            cin >> accNumber;
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            bank.deposit(accNumber, amount);
            break;
        }
        case 3:
        {
            int accNumber, amount;
            cout << "Enter Account Number: ";
            cin >> accNumber;
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            bank.withdraw(accNumber, amount);
            break;
        }
        case 4:
        {
            int accNumber;
            cout << "Enter Account Number: ";
            cin >> accNumber;
            bank.showTransactionHistory(accNumber);
            break;
        }
        case 5:
        {
            int accNumber;
            cout << "Enter Account Number: ";
            cin >> accNumber;
            bank.displayAccount(accNumber);
            break;
        }
        case 6:
        {
            int accNumber;
            cout << "Enter Account Number to Delete: ";
            cin >> accNumber;
            bank.deleteAccount(accNumber);
            break;
        }
        case 7:
            cout << "Exiting system...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
