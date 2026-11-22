#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>

using namespace std;

constexpr double DA_RATE = 0.42;

class Staff {
protected:
    string name;
    int id;

public:
    Staff(const string& name, int id)
        : name(name), id(id) {}

    virtual double pay() const = 0;

    virtual void display() const {
        cout << "Staff ID: " << id
             << "\nName: " << name
             << "\nPay: " << pay() << '\n';
    }

    virtual ~Staff() = default;
};

class Professor : public Staff {
private:
    double basic;
    double research;

public:
    Professor(const string& name, int id,
              double basic, double research)
        : Staff(name, id), basic(basic), research(research) {}

    double pay() const override {
        return basic + basic * DA_RATE + research;
    }
};

class LabAssistant : public Staff {
private:
    double basic;

public:
    LabAssistant(const string& name, int id, double basic)
        : Staff(name, id), basic(basic) {}

    double pay() const override {
        return basic + basic * DA_RATE;
    }
};

class GuestFaculty : public Staff {
private:
    double hours;
    double rate;

public:
    GuestFaculty(const string& name, int id,
                 double hours, double rate)
        : Staff(name, id), hours(hours), rate(rate) {}

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    vector<unique_ptr<Staff>> employees;

    employees.push_back(
        make_unique<Professor>("Arun", 101, 50000, 10000));

    employees.push_back(
        make_unique<LabAssistant>("Priya", 102, 30000));

    employees.push_back(
        make_unique<GuestFaculty>("Kavin", 103, 40, 800));

    cout << fixed << setprecision(2);
    cout << "UNIVERSITY PAYROLL SYSTEM\n\n";

    for (const auto& employee : employees) {
        employee->display();
        cout << "----------------------\n";
    }

    return 0;
}