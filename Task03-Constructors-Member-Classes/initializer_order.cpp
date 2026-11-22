#include <iostream>
using namespace std;

class InitializerOrder {
private:
    int first;
    int second;

public:
    InitializerOrder() : second(20), first(10) {
        cout << "Constructor executed" << endl;
    }

    void display() const {
        cout << "First: " << first << endl;
        cout << "Second: " << second << endl;
    }
};

int main() {
    InitializerOrder obj;
    obj.display();

    return 0;
}