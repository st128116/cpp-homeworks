#include <iostream>
#include <string>
#include <vector>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    BankAccount(const std::string& number,
                const std::string& holder,
                double initialBalance)
        : accountNumber(number),
          accountHolder(holder),
          balance(initialBalance) {}

    void Deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void Withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Error: insufficient funds on account "
                      << accountNumber << std::endl;
        } else {
            balance -= amount;
        }
    }

    double GetBalance() const {
        return balance;
    }

    std::string GetAccountHolder() const {
        return accountHolder;
    }

    std::string GetAccountNumber() const {
        return accountNumber;
    }

    void PrintAccountInfo() const {
        std::cout << "Account number: " << accountNumber << std::endl;
        std::cout << "Account holder: " << accountHolder << std::endl;
        std::cout << "Balance: " << balance << std::endl;
        std::cout << "------------------------" << std::endl;
    }
};

class Bank {
private:
    std::vector<BankAccount> accounts;

public:
    void AddAccount(const BankAccount& account) {
        accounts.push_back(account);
    }

    double GetTotalBalance() const {
        double total = 0.0;
        for (const auto& account : accounts) {
            total += account.GetBalance();
        }
        return total;
    }

    void PrintAllAccounts() const {
        for (const auto& account : accounts) {
            account.PrintAccountInfo();
        }
    }
};

int main() {
    Bank bank;

    BankAccount acc1("001", "Ivan Ivanov", 1000.0);
    BankAccount acc2("002", "Petr Petrov", 500.0);
    BankAccount acc3("003", "Anna Smirnova", 2000.0);

    acc1.Deposit(500);
    acc2.Withdraw(100);
    acc3.Withdraw(3000); // ошибка — недостаточно средств

    bank.AddAccount(acc1);
    bank.AddAccount(acc2);
    bank.AddAccount(acc3);

    bank.PrintAllAccounts();

    std::cout << "Total balance in bank: "
              << bank.GetTotalBalance() << std::endl;

    return 0;
}
