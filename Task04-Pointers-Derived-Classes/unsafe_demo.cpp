#include <iostream>
using namespace std;

class Account {
protected:
    double interestRate;

public:
    Account() : interestRate(3.5) {
        cout << "Account constructor called" << endl;
    }

    double getInterestRate() const {
        return interestRate;
    }

    void display() const {
        cout << "Account Interest Rate: "
             << interestRate << "%" << endl;
    }

    ~Account() {
        cout << "Account destructor called" << endl;
    }
};

class SeniorAccount : public Account {
private:
    double* transactionHistory;
    int historySize;

public:
    SeniorAccount(int size) : historySize(size) {
        transactionHistory = new double[historySize];

        for (int i = 0; i < historySize; i++) {
            transactionHistory[i] = (i + 1) * 1000;
        }

        cout << "SeniorAccount constructor called" << endl;
    }

    double getInterestRate() const {
        return 4.0;
    }

    void display() const {
        cout << "Senior Account Interest Rate: "
             << getInterestRate() << "%" << endl;
    }

    ~SeniorAccount() {
        delete[] transactionHistory;
        cout << "SeniorAccount destructor called" << endl;
    }
};

int main() {
    cout << "STATIC BINDING" << endl;

    SeniorAccount senior(3);
    Account* ptr = &senior;

    cout << "Base pointer rate: " << ptr->getInterestRate() << endl;
    cout << "Derived object rate: " << senior.getInterestRate() << endl;

    ptr->display();

    cout << "\nOBJECT SLICING" << endl;

    Account sliced = senior;
    sliced.display();

    cout << "\nUNSAFE BASE POINTER DELETION" << endl;

    Account* dynamicAccount = new SeniorAccount(3);
    delete dynamicAccount;

    return 0;
}