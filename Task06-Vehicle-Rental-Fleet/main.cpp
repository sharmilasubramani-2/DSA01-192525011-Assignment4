#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Vehicle {
protected:
    string registrationNumber;
    double dailyRate;
    bool rented;

public:
    Vehicle(string registration, double rate)
        : registrationNumber(registration), dailyRate(rate), rented(false) {}

    virtual void display() const = 0;

    virtual double calculateLateCharge(int lateDays) const {
        return lateDays * dailyRate * 0.25;
    }

    void rent() {
        if (!rented) {
            rented = true;
            cout << registrationNumber << " rented successfully." << endl;
        } else {
            cout << registrationNumber << " is already rented." << endl;
        }
    }

    void returnVehicle(int lateDays) {
        if (rented) {
            double lateCharge = calculateLateCharge(lateDays);
            cout << registrationNumber << " returned successfully." << endl;
            cout << "Late Charge: Rs. " << lateCharge << endl;
            rented = false;
        } else {
            cout << registrationNumber << " was not rented." << endl;
        }
    }

    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle {
public:
    Bicycle(string registration, double rate)
        : Vehicle(registration, rate) {}

    void display() const override {
        cout << "Bicycle | Registration: " << registrationNumber
             << " | Daily Rate: Rs. " << dailyRate << endl;
    }
};

class TwoWheeler : public Vehicle {
private:
    double fuelLevel;
    string serviceDueDate;

public:
    TwoWheeler(string registration, double rate, double fuel, string serviceDate)
        : Vehicle(registration, rate),
          fuelLevel(fuel), serviceDueDate(serviceDate) {}

    void display() const override {
        cout << "Two Wheeler | Registration: " << registrationNumber
             << " | Daily Rate: Rs. " << dailyRate
             << " | Fuel: " << fuelLevel << "%"
             << " | Service Due: " << serviceDueDate << endl;
    }
};

class Car : public Vehicle {
private:
    int seatingCapacity;
    double fuelLevel;
    string serviceDueDate;

public:
    Car(string registration, double rate, int seats,
        double fuel, string serviceDate)
        : Vehicle(registration, rate),
          seatingCapacity(seats), fuelLevel(fuel),
          serviceDueDate(serviceDate) {}

    void display() const override {
        cout << "Car | Registration: " << registrationNumber
             << " | Daily Rate: Rs. " << dailyRate
             << " | Seats: " << seatingCapacity
             << " | Fuel: " << fuelLevel << "%"
             << " | Service Due: " << serviceDueDate << endl;
    }
};

class ElectricCar : public Vehicle {
private:
    double batteryCapacity;
    double chargeLevel;
    double chargePerKWh;

public:
    ElectricCar(string registration, double rate, double capacity,
                double charge, double cost)
        : Vehicle(registration, rate),
          batteryCapacity(capacity), chargeLevel(charge),
          chargePerKWh(cost) {}

    void display() const override {
        cout << "Electric Car | Registration: " << registrationNumber
             << " | Daily Rate: Rs. " << dailyRate
             << " | Battery: " << batteryCapacity << " kWh"
             << " | Charge: " << chargeLevel << "%"
             << " | Cost/kWh: Rs. " << chargePerKWh << endl;
    }
};

class ElectricBus : public Vehicle {
private:
    int seatingCapacity;
    double batteryCapacity;

public:
    ElectricBus(string registration, double rate,
                int seats, double capacity)
        : Vehicle(registration, rate),
          seatingCapacity(seats), batteryCapacity(capacity) {}

    void display() const override {
        cout << "Electric Bus | Registration: " << registrationNumber
             << " | Daily Rate: Rs. " << dailyRate
             << " | Seats: " << seatingCapacity
             << " | Battery: " << batteryCapacity << " kWh" << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    Bicycle bicycle("BIKE101", 100);
    TwoWheeler twoWheeler("TN01AB1234", 300, 80, "15-12-2026");
    Car car("TN02CD5678", 1500, 5, 75, "20-12-2026");
    ElectricCar electricCar("TN03EF9012", 2000, 60, 85, 8);
    ElectricBus electricBus("TN04GH3456", 5000, 40, 250);

    Vehicle* fleet[] = {
        &bicycle,
        &twoWheeler,
        &car,
        &electricCar,
        &electricBus
    };

    cout << "VEHICLE RENTAL FLEET" << endl;

    for (Vehicle* vehicle : fleet) {
        vehicle->display();
    }

    cout << "\nRENTAL OPERATIONS" << endl;

    for (Vehicle* vehicle : fleet) {
        vehicle->rent();
    }

    cout << "\nRETURN OPERATIONS" << endl;

    for (Vehicle* vehicle : fleet) {
        vehicle->returnVehicle(2);
    }

    return 0;
}