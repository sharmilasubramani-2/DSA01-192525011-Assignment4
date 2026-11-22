#include <iostream>
#include <memory>
using namespace std;

class Account {
protected:
    double interestRate;

public:
    Account() : interestRate(3.5) {
        cout << "Account constructor called" << endl;
    }

    virtual double getInterestRate() const {
        return interestRate;
    }

    virtual void display() const {
        cout << "Account Interest Rate: "
             << getInterestRate() << "%" << endl;
    }

    virtual ~Account() {
        cout << "Account destructor called" << endl;
    }
};

class SeniorAccount : public Account {
private:
    double* transactionHistory;
    int historySize;

public:
    SeniorAccount(int size) : transactionHistory(nullptr), historySize(size) {
        interestRate = 4.0;
        transactionHistory = new double[historySize];

        for (int i = 0; i < historySize; i++) {
            transactionHistory[i] = (i + 1) * 1000;
        }

        cout << "SeniorAccount constructor called" << endl;
    }

    double getInterestRate() const override {
        return interestRate;
    }

    void display() const override {
        cout << "Senior Account Interest Rate: "
             << getInterestRate() << "%" << endl;

        cout << "Transaction History: ";

        for (int i = 0; i < historySize; i++) {
            cout << transactionHistory[i] << " ";
        }

        cout << endl;
    }

    ~SeniorAccount() override {
        delete[] transactionHistory;
        cout << "SeniorAccount destructor called" << endl;
    }
};

int main() {
    cout << "BASE CLASS POINTER" << endl;

    Account account;
    Account* accountPtr = &account;

    cout << accountPtr->getInterestRate() << endl;

    cout << "\nDERIVED CLASS POINTER" << endl;

    SeniorAccount senior(3);
    Account* seniorPtr = &senior;

    cout << seniorPtr->getInterestRate() << endl;
    seniorPtr->display();

    cout << "\nSMART POINTER POLYMORPHISM" << endl;

    unique_ptr<Account> smartAccount =
        make_unique<SeniorAccount>(2);

    cout << smartAccount->getInterestRate() << endl;
    smartAccount->display();

    cout << "\nPOLYMORPHIC POINTER ARRAY" << endl;

    Account* accounts[2];

    accounts[0] = &account;
    accounts[1] = &senior;

    for (int i = 0; i < 2; i++) {
        cout << accounts[i]->getInterestRate() << endl;
    }

    return 0;
}