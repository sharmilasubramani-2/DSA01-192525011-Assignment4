#include <iostream>
#include <iomanip>
using namespace std;

class Cart {
private:
    string customer;
    double price;
    int quantity;
    double discount;

public:
    Cart(string name, double itemPrice, int itemQuantity)
        : customer(name), price(itemPrice), quantity(itemQuantity), discount(0) {}

    Cart& add(int amount) {
        quantity += amount;
        return *this;
    }

    Cart& setDiscount(double percentage) {
        discount = percentage;
        return *this;
    }

    double getTotal() const {
        return price * quantity * (1 - discount / 100);
    }

    void display() const {
        cout << customer << " - Quantity: " << quantity
             << ", Total: " << fixed << setprecision(2) << getTotal() << endl;
    }
};

int main() {
    cout << "DIRECT OBJECT ACCESS" << endl;
    Cart cart1("Arun", 180, 1);
    cart1.add(1).setDiscount(10);
    cart1.display();

    cout << "\nPOINTER ACCESS" << endl;
    Cart* cartPtr = &cart1;
    cartPtr->display();

    cout << "\nREFERENCE ACCESS" << endl;
    Cart& cartRef = cart1;
    cartRef.display();

    cout << "\nDYNAMIC OBJECT CREATION" << endl;
    Cart* dynamicCart = new Cart("Priya", 200, 2);
    dynamicCart->setDiscount(5);
    dynamicCart->display();
    delete dynamicCart;

    cout << "\nARRAY OF OBJECT POINTERS" << endl;
    Cart cart2("Kavin", 150, 2);
    Cart cart3("Meena", 250, 1);

    Cart* carts[3] = {&cart1, &cart2, &cart3};

    int highestIndex = 0;

    for (int i = 0; i < 3; i++) {
        carts[i]->display();

        if (carts[i]->getTotal() > carts[highestIndex]->getTotal()) {
            highestIndex = i;
        }
    }

    cout << "Highest Cart Total: "
         << fixed << setprecision(2)
         << carts[highestIndex]->getTotal() << endl;

    return 0;
}