#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int id;
    string phone;

public:
    Person(string name, int id, string phone)
        : name(name), id(id), phone(phone) {
        cout << "Person constructor called\n";
    }

    virtual void display() const {
        cout << "Name: " << name << '\n';
        cout << "ID: " << id << '\n';
        cout << "Phone: " << phone << '\n';
    }

    virtual ~Person() = default;
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;

public:
    Student(string name, int id, string phone,
            string programme, double cgpa)
        : Person(name, id, phone),
          programme(programme), cgpa(cgpa) {
        cout << "Student constructor called\n";
    }

    void displayStudent() const {
        cout << "Programme: " << programme << '\n';
        cout << "CGPA: " << cgpa << '\n';
    }
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string name, int id, string phone,
          string department, double salary)
        : Person(name, id, phone),
          department(department), salary(salary) {
        cout << "Staff constructor called\n";
    }

    void displayStaff() const {
        cout << "Department: " << department << '\n';
        cout << "Salary: " << salary << '\n';
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string name, int id, string phone,
                      string programme, double cgpa,
                      string department, double salary)
        : Person(name, id, phone),
          Student(name, id, phone, programme, cgpa),
          Staff(name, id, phone, department, salary) {
        cout << "TeachingAssistant constructor called\n";
    }

    void display() const override {
        cout << "\nTEACHING ASSISTANT DETAILS\n";
        Person::display();
        displayStudent();
        displayStaff();
    }
};

class ResearchScholar : public Student {
private:
    double fellowship;

public:
    ResearchScholar(string name, int id, string phone,
                    string programme, double cgpa,
                    double fellowship)
        : Person(name, id, phone),
          Student(name, id, phone, programme, cgpa),
          fellowship(fellowship) {
        cout << "ResearchScholar constructor called\n";
    }

    void display() const override {
        cout << "\nRESEARCH SCHOLAR DETAILS\n";
        Person::display();
        displayStudent();
        cout << "Fellowship: " << fellowship << '\n';
    }
};

int main() {
    cout << "CREATING TEACHING ASSISTANT\n";

    TeachingAssistant ta(
        "Arun", 101, "9876543210",
        "AIML", 8.9, "Computer Science", 30000
    );

    ta.display();

    cout << "\nCREATING RESEARCH SCHOLAR\n";

    ResearchScholar rs(
        "Priya", 102, "9876543211",
        "AI Research", 9.2, 25000
    );

    rs.display();
    cout << "\nOBJECT SIZE ANALYSIS\n";
cout << "Person: " << sizeof(Person) << " bytes\n";
cout << "Student: " << sizeof(Student) << " bytes\n";
cout << "Staff: " << sizeof(Staff) << " bytes\n";
cout << "TeachingAssistant: " << sizeof(TeachingAssistant) << " bytes\n";
cout << "ResearchScholar: " << sizeof(ResearchScholar) << " bytes\n";

    return 0;
}