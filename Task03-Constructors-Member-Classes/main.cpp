#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    string city;
    string pincode;

public:
    Address(string city, string pincode)
        : city(city), pincode(pincode) {
        cout << "Address constructor called" << endl;
    }

    void display() const {
        cout << city << "-" << pincode;
    }

    ~Address() {
        cout << "Address destructor called" << endl;
    }
};

class Person {
protected:
    int id;
    string name;
    int age;
    Address home;

public:
    Person(int id, string name, int age, Address home)
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
    Course(string courseName) : courseName(courseName) {
        cout << "Course constructor called" << endl;
    }

    void display() const {
        cout << courseName;
    }

    ~Course() {
        cout << "Course destructor called" << endl;
    }
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;
    Course course;

public:
    Student(int id, string name, int age, Address home,
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

class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(int id, string name, int age, Address home,
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
    TeachingAssistant(int id, string name, int age, Address home,
                      string programme, double cgpa, string courseName,
                      string department, double salary)
        : Person(id, name, age, home),
          Student(id, name, age, home, programme, cgpa, courseName),
          Staff(id, name, age, home, department, salary) {
        cout << "TeachingAssistant constructor called" << endl;
    }

    ~TeachingAssistant() override {
        cout << "TeachingAssistant destructor called" << endl;
    }
};

class Engine {
public:
    Engine() {
        cout << "Engine constructor called" << endl;
    }

    ~Engine() {
        cout << "Engine destructor called" << endl;
    }
};

class Vehicle {
protected:
    Engine engine;

public:
    Vehicle() {
        cout << "Vehicle constructor called" << endl;
    }

    virtual ~Vehicle() {
        cout << "Vehicle destructor called" << endl;
    }
};

class Car : public Vehicle {
public:
    Car() {
        cout << "Car constructor called" << endl;
    }

    ~Car() override {
        cout << "Car destructor called" << endl;
    }
};

int main() {
    cout << "STUDENT OBJECT" << endl;

    {
        Address home("Salem", "636001");

        Student student(
            192311001,
            "Kavya",
            19,
            home,
            "AIML",
            8.9,
            "Object Oriented Programming"
        );

        cout << "\nSTUDENT DETAILS" << endl;
        student.display();
    }

    cout << "\nTEACHING ASSISTANT OBJECT" << endl;

    {
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
        assistant.displayStaff();
    }

    cout << "\nENGINE VEHICLE CAR CONSTRUCTION" << endl;

    {
        Car car;
    }
cout << "\nOBJECT SIZE COMPARISON" << endl;
cout << "Person: " << sizeof(Person) << " bytes" << endl;
cout << "Student: " << sizeof(Student) << " bytes" << endl;
cout << "Staff: " << sizeof(Staff) << " bytes" << endl;
cout << "TeachingAssistant: " << sizeof(TeachingAssistant) << " bytes" << endl;
    return 0;
}