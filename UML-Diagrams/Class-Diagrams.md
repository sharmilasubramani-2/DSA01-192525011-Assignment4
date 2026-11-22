# Assignment 4 – UML Class Diagrams

These diagrams represent the major class relationships used in the six assignment tasks.

## Task 1 – Staff Hierarchy

```mermaid
classDiagram
    class Staff {
        <<abstract>>
        -string name
        -int id
        +calculatePay() double*
        +display() void*
    }
    class Professor {
        +calculatePay() double
        +display() void
    }
    class LabAssistant {
        +calculatePay() double
        +display() void
    }
    class GuestFaculty {
        +calculatePay() double
        +display() void
    }
    Staff <|-- Professor
    Staff <|-- LabAssistant
    Staff <|-- GuestFaculty
```

## Task 2 – Inheritance Hierarchy

```mermaid
classDiagram
    class Person
    class Student
    class Staff
    class TeachingAssistant
    class ResearchScholar

    Person <|-- Student : virtual
    Person <|-- Staff : virtual
    Student <|-- TeachingAssistant
    Staff <|-- TeachingAssistant
    Student <|-- ResearchScholar
```

## Task 3 – Composition and Inheritance

```mermaid
classDiagram
    class Address
    class Person
    class Course
    class Student
    class Staff
    class TeachingAssistant
    class Engine
    class Vehicle
    class Car

    Person *-- Address
    Student *-- Course
    Person <|-- Student : virtual
    Person <|-- Staff : virtual
    Student <|-- TeachingAssistant
    Staff <|-- TeachingAssistant
    Vehicle *-- Engine
    Vehicle <|-- Car
```

## Task 4 – Account Hierarchy

```mermaid
classDiagram
    class Account {
        -double interestRate
        +getInterestRate() double
        +display() void
        +~Account()
    }
    class SeniorAccount {
        -double* transactionHistory
        -int historySize
        +getInterestRate() double
        +display() void
        +~SeniorAccount()
    }
    Account <|-- SeniorAccount
```

## Task 5 – Cart Class

```mermaid
classDiagram
    class Cart {
        -string customer
        -double price
        -int quantity
        -double discount
        +add(int) Cart&
        +setDiscount(double) Cart&
        +getTotal() double
        +display() void
    }
```

## Task 6 – Vehicle Rental Fleet

```mermaid
classDiagram
    class Vehicle {
        <<abstract>>
        -string registrationNumber
        -double dailyRate
        -bool rented
        +display() void*
        +calculateLateCharge(int) double
        +rent() void
        +returnVehicle() void
    }
    class Bicycle
    class TwoWheeler
    class Car
    class ElectricCar
    class ElectricBus

    Vehicle <|-- Bicycle
    Vehicle <|-- TwoWheeler
    Vehicle <|-- Car
    Vehicle <|-- ElectricCar
    Vehicle <|-- ElectricBus
```

**Note:** These diagrams represent the principal class relationships. Member details are abbreviated for readability.