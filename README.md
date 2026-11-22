# DSA0111 OOPS - Assignment 4

## Designing Reusable Class Hierarchies

### Student Details

| Field | Details |
|---|---|
| Student Name | Sharmila S |
| Register Number | 192525011 |
| Programme | B.Tech Artificial Intelligence and Machine Learning |
| Course | DSA0111 - OOPS |
| Course Outcome | CO4 |
| Assignment | 4 |
| Total Marks | 50 |
| Programming Language | C++ |
| Compiler | g++ 16.1.0 |
| Language Standard | C++17 |

## Assignment Overview

This assignment demonstrates advanced object-oriented programming concepts through six independent C++ implementations. It focuses on reusable class design, inheritance, composition, constructors, pointers, polymorphism, and extensible class hierarchies.

## Compilation and Execution

Navigate to the respective task directory and compile the source file:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o main.exe
```

Run the executable in PowerShell:

```powershell
.\main.exe
```

## Assignment Tasks

| Task | Description | Main Concepts |
|---|---|---|
| 1 | Class Design Review | Abstraction, encapsulation, inheritance, polymorphism |
| 2 | From Requirement to Hierarchy | Multiple, hybrid and virtual inheritance |
| 3 | Constructors and Member Classes | Constructors, destructors, composition, initializer lists |
| 4 | Pointers to Derived Classes | Base and derived pointers, polymorphism, object slicing |
| 5 | Pointers to Objects and This Pointer | Object pointers, references, dynamic allocation, method chaining |
| 6 | Vehicle Rental Fleet | Abstract classes, inheritance, overriding, extensibility |

## Repository Structure

```text
DSA01-192525011-Assignment4/
|
|-- Task01-Class-Design-Review/
|-- Task02-Inheritance-Hierarchy/
|-- Task03-Constructors-Member-Classes/
|-- Task04-Pointers-Derived-Classes/
|-- Task05-Objects-This-Pointer/
|-- Task06-Vehicle-Rental-Fleet/
|-- Report/
|   |-- Assignment4-Report.md
|-- UML-Diagrams/
|   |-- Class-Diagrams.md
|-- .gitignore
|-- README.md
```

Each task directory contains its implementation, analysis, and available output evidence. Supplementary comparison programs are included where applicable.

## Concepts Covered

- Class design and encapsulation
- Inheritance and virtual inheritance
- Constructor and destructor execution order
- Composition and member classes
- Runtime polymorphism and static binding
- Base-class and derived-class pointers
- Virtual destructors and object lifetime
- Dynamic memory management and smart pointers
- Object slicing
- The `this` pointer and method chaining
- Abstract classes and pure virtual functions
- Reusable and extensible class hierarchies

## Testing and Verification

All six main programs were successfully compiled using:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o main.exe
```

The repository includes execution screenshots, analysis documents, supplementary experiments, UML diagrams, and the final assignment report.

The AddressSanitizer experiment could not be executed because the installed compiler environment did not provide the required sanitizer library.

## Repository Purpose

This repository maintains the source code, implementation experiments, testing evidence, and supporting documentation for DSA0111 OOPS Assignment 4.