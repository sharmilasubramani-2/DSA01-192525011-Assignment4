#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string city;
    string pincode;

public:
    Address(string city, string pincode)
        : city(city), pincode(pincode) {}

    void display() const {
        cout << city << "-" << pincode;
    }
};

class Person {
protected:
    int id;
    string name;
    int age;
    Address home;

public:
    Person(int id, string name, int age, const Address& home)
        : id(id), name(name), age(age), home(home) {
        cout << "Person constructor called" << endl;
    }

    virtual void display() const {
        cout << id << " " << name << " (" << age << ") ";
        home.display();
        cout << endl;
    }

    virtual ~Person() {
        cout << "Person destructor called" << endl;
    }
};

class Course {
private:
    string courseName;

public:
    Course(string courseName) : courseName(courseName) {}

    void display() const {
        cout << courseName;
    }
};

class Student : public Person {
protected:
    string programme;
    double cgpa;
    Course course;

public:
    Student(int id, string name, int age, const Address& home,
            string programme, double cgpa, string courseName)
        : Person(id, name, age, home),
          programme(programme), cgpa(cgpa), course(courseName) {
        cout << "Student constructor called" << endl;
    }

    void display() const override {
        Person::display();
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Course: ";
        course.display();
        cout << endl;
    }

    ~Student() override {
        cout << "Student destructor called" << endl;
    }
};

class Staff : public Person {
protected:
    string department;
    double salary;

public:
    Staff(int id, string name, int age, const Address& home,
          string department, double salary)
        : Person(id, name, age, home),
          department(department), salary(salary) {
        cout << "Staff constructor called" << endl;
    }

    void displayStaff() const {
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }

    ~Staff() override {
        cout << "Staff destructor called" << endl;
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(int id, string name, int age, const Address& home,
                      string programme, double cgpa, string courseName,
                      string department, double salary)
        : Student(id, name, age, home, programme, cgpa, courseName),
          Staff(id, name, age, home, department, salary) {
        cout << "TeachingAssistant constructor called" << endl;
    }

    void display() const override {
        Student::display();
        Staff::displayStaff();
    }

    ~TeachingAssistant() override {
        cout << "TeachingAssistant destructor called" << endl;
    }
};

int main() {
    cout << "NON-VIRTUAL INHERITANCE OBJECT SIZE COMPARISON" << endl;

    cout << "Person: " << sizeof(Person) << " bytes" << endl;
    cout << "Student: " << sizeof(Student) << " bytes" << endl;
    cout << "Staff: " << sizeof(Staff) << " bytes" << endl;
    cout << "TeachingAssistant: "
         << sizeof(TeachingAssistant) << " bytes" << endl;

    cout << "\nTEACHING ASSISTANT OBJECT" << endl;

    Address home("Chennai", "600001");

    TeachingAssistant assistant(
        101,
        "Arun",
        20,
        home,
        "AIML",
        8.9,
        "OOPS",
        "Computer Science",
        30000
    );

    cout << "\nTEACHING ASSISTANT DETAILS" << endl;
    assistant.display();

    return 0;
}