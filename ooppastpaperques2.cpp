#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;

// Base class for Account
class Account {
protected:
    string accountHolder;
    int accountNumber;
    double balance;
    vector<string> transactionHistory;
    bool frozen;

public:
    Account(string holder, int number, double initialBalance)
        : accountHolder(holder), accountNumber(number), balance(initialBalance), frozen(false) {}

    virtual ~Account() {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    bool isFrozen() const {
        return frozen;
    }

    void freezeAccount() {
        frozen = true;
    }

    void addTransaction(const string& transaction) {
        transactionHistory.push_back(transaction);
    }

    const vector<string>& getTransactionHistory() const {
        return transactionHistory;
    }

    virtual bool deposit(double amount) {
        if (frozen || amount <= 0) return false;
        balance += amount;
        addTransaction("Deposit: BDT " + to_string(amount));
        return true;
    }

    virtual bool withdraw(double amount) {
        if (frozen || amount <= 0 || balance - amount < 0) return false;
        balance -= amount;
        addTransaction("Withdrawal: BDT " + to_string(amount));
        if (balance < 0) freezeAccount();
        return true;
    }

    virtual bool transfer(Account& toAccount, double amount) {
        if (frozen || amount <= 0 || balance - amount < 0) return false;
        if (withdraw(amount)) {
            toAccount.deposit(amount);
            addTransaction("Transfer to Account " + to_string(toAccount.getAccountNumber()) + ": BDT " + to_string(amount));
            return true;
        }
        return false;
    }

    virtual void resetDailyLimits() {}
};

// Derived class for CurrentAccount
class CurrentAccount : public Account {
    const double yearlyFee = 1000.0;

public:
    CurrentAccount(string holder, int number, double initialBalance)
        : Account(holder, number, initialBalance) {}

    void applyYearlyFee() {
        if (!frozen) {
            balance -= yearlyFee;
            addTransaction("Yearly Fee: BDT " + to_string(yearlyFee));
            if (balance < 0) freezeAccount();
        }
    }
};

// Derived class for SavingsAccount
class SavingsAccount : public Account {
    int freeWithdrawals;
    int freeDeposits;
    double dailyWithdrawalLimit;
    int withdrawalsToday;
    int depositsToday;

public:
    SavingsAccount(string holder, int number, double initialBalance, int freeWithdrawals = 5, int freeDeposits = 5, double withdrawalLimit = 10000.0)
        : Account(holder, number, initialBalance), freeWithdrawals(freeWithdrawals), freeDeposits(freeDeposits), dailyWithdrawalLimit(withdrawalLimit), withdrawalsToday(0), depositsToday(0) {}

    bool deposit(double amount) override {
        if (frozen || amount <= 0) return false;
        depositsToday++;
        if (depositsToday > freeDeposits) {
            double fee = max(100.0, amount * 0.02);
            balance -= fee;
            addTransaction("Deposit Fee: BDT " + to_string(fee));
        }
        balance += amount;
        addTransaction("Deposit: BDT " + to_string(amount));
        if (balance < 0) freezeAccount();
        return true;
    }

    bool withdraw(double amount) override {
        if (frozen || amount <= 0 || balance - amount < 0) return false;
        withdrawalsToday++;
        if (withdrawalsToday > freeWithdrawals || amount > dailyWithdrawalLimit) {
            double fee = max(100.0, amount * 0.02);
            balance -= fee;
            addTransaction("Withdrawal Fee: BDT " + to_string(fee));
        }
        balance -= amount;
        addTransaction("Withdrawal: BDT " + to_string(amount));
        if (balance < 0) freezeAccount();
        return true;
    }

    void resetDailyLimits() override {
        withdrawalsToday = 0;
        depositsToday = 0;
    }
};

// Bank class
class Bank {
    string name;
    vector<shared_ptr<Account>> accounts;
    vector<string> bankTransactionHistory;

public:
    Bank(string bankName) : name(bankName) {}

    void addAccount(shared_ptr<Account> account) {
        accounts.push_back(account);
    }

    void clearDailyLimits() {
        for (auto& account : accounts) {
            account->resetDailyLimits();
        }
    }

    void printTransactionHistories() const {
        for (const auto& account : accounts) {
            cout << "Account " << account->getAccountNumber() << " Transaction History:\n";
            for (const auto& transaction : account->getTransactionHistory()) {
                cout << transaction << "\n";
            }
        }
    }

    void printBalances() const {
        for (const auto& account : accounts) {
            cout << "Account " << account->getAccountNumber() << " Balance: BDT " << account->getBalance() << "\n";
        }
    }
};

// Main function
int main() {
    Bank bank("National Bank");

    auto currentAccount = make_shared<CurrentAccount>("John Doe", 1001, 50000);
    auto savingsAccount = make_shared<SavingsAccount>("Jane Smith", 1002, 30000);

    bank.addAccount(currentAccount);
    bank.addAccount(savingsAccount);

    currentAccount->deposit(5000);
    currentAccount->withdraw(10000);
    currentAccount->transfer(*savingsAccount, 2000);

    savingsAccount->withdraw(15000);
    savingsAccount->deposit(7000);

    bank.printBalances();
    bank.printTransactionHistories();

    bank.clearDailyLimits();

    return 0;
}
