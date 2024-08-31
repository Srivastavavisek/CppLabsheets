// Create a base class Account with data members accountNumber and balance.
// Derive two classes SavingsAccount and CheckingAccount from Account.
// Implement polymorphic behavior where the base class pointer can point to objects of
// derived classes, and call their respective member functions to deposit and withdraw
// money, applying specific rules for each account type.

#include <iostream>

using namespace std;

class Account 
{
protected:
    int accountNum;
    double balance;

public:
    Account(int accNumber, double initBalance)
        : accountNum(accNumber), balance(initBalance) 
    {}

    virtual void deposit(double amount) 
    {
        balance += amount;
    }

    virtual bool withdraw(double amount) 
    {
        if (balance >= amount) 
        {
            balance -= amount;
            return true;
        }
        return false;
    }

    virtual void showBalance() const 
    {
        cout << "Account Number: " << accountNum << endl << "Balance: $" << balance << endl;
    }

    virtual ~Account()
    {}
};

class SavingsAccount : public Account 
{
private:
    double interest;

public:
    SavingsAccount(int accNumber, double initBalance, double rate)
        : Account(accNumber, initBalance), interest(rate) 
    {}

    void deposit(double amount) 
    {
        balance += amount;
        balance += balance * (interest / 100.0);
    }

    bool withdraw(double amount)
    {
        if (balance - amount >= 500) 
        {
            balance -= amount;
            return true;
        }
        cout << "Insufficient balance to maintain minimum balance after withdrawal." << endl;
        return false;
    }

    void showBalance() const
    {
        cout << "Savings ";
        Account::showBalance();
    }
};

class CheckingAccount : public Account 
{
private:
    double overLimit;

public:
    CheckingAccount(int accNumber, double initBalance, double overdraft)
        : Account(accNumber, initBalance), overLimit(overdraft) 
    {}

    bool withdraw(double amount)
    {
        if (balance + overLimit >= amount) 
        {
            balance -= amount;
            return true;
        }
        cout << "Withdrawal exceeds overdraft limit." << endl;
        return false;
    }

    void showBalance() const 
    {
        cout << "Checking ";
        Account::showBalance();
    }
};

int main() {
    Account* acc1 = new SavingsAccount(1001, 1000.0, 2.5);
    Account* acc2 = new CheckingAccount(1002, 500.0, 200.0);

    char ch;
    double amount;

    do
    {
        cout << endl << "Select account type:\n1: Savings\n2: Checking\n3: Quit)\n: ";
        cin >> ch;

        Account* selectedAccount = nullptr;

        switch (ch)
        {
            case '1':
                selectedAccount = acc1;
                break;
            
            case '2':
                selectedAccount = acc2;
                break;

            case '3':
                cout << "Exiting program" << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
                continue;
        }

        if (ch == '3')
            break;

        cout << "Enter 'd' for deposit or 'w' for withdrawal: ";
        cin >> ch;

        switch (ch)
        {
            case 'd':
                cout << "Enter amount to deposit: ";
                cin >> amount;
                selectedAccount->deposit(amount);
                break;
            
            case 'w':
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (!selectedAccount->withdraw(amount))
                    cout << "Withdrawal failed." << endl;
                break;
            
            default:
                cout << "Invalid option. Please try again." << endl;
        }
        
        selectedAccount->showBalance();
    } while(ch != 3);

    delete acc1;
    delete acc2;

    return 0;
}
