# DSA0111 – Object-Oriented Programming
## Assignment 4 – Advanced Object-Oriented Programming Concepts

**Student Name:** Sharmila  
**Register Number:** 192525011  
**Programme:** B.Tech Artificial Intelligence and Machine Learning  
**Compiler:** GNU G++ 16.1.0  
**Language Standard:** C++17

## 1. Abstract

This assignment explores advanced Object-Oriented Programming concepts using C++. It includes class design, inheritance hierarchies, constructors, member classes, pointers to derived objects, runtime polymorphism, object pointers, the this pointer, and a vehicle rental fleet system. Each task demonstrates the application of OOP principles through independent programs, output observations, and design analysis.

## 2. Objectives

- Design classes using encapsulation and abstraction.
- Implement inheritance and virtual base classes.
- Understand constructors, destructors, and member initialization.
- Demonstrate pointers to base and derived classes.
- Analyse static binding, dynamic binding, and object slicing.
- Use object pointers and the this pointer.
- Develop an extensible vehicle rental fleet using polymorphism.

## 3. Task-wise Implementation

### Task 1 – Class Design Review

Implemented an abstract Staff base class with Professor, LabAssistant, and GuestFaculty derived classes. Virtual functions provide class-specific salary calculations and display operations. Smart pointers manage dynamically allocated objects.

**Concepts:** Abstraction, inheritance, encapsulation, runtime polymorphism, virtual destructors, smart pointers.

### Task 2 – From Requirement to Hierarchy

Implemented a Person-based hierarchy involving Student, Staff, TeachingAssistant, and ResearchScholar. Virtual inheritance prevents duplicate Person subobjects in the diamond hierarchy. A separate implementation demonstrates the non-virtual inheritance comparison.

**Concepts:** Hierarchical inheritance, multiple inheritance, hybrid inheritance, virtual inheritance, constructor order, object size comparison.

### Task 3 – Constructors and Member Classes

Implemented Address as a member object of Person, Course as a member of Student, and Engine as a member of Vehicle. TeachingAssistant combines Student and Staff using virtual inheritance. A separate experiment demonstrates member initialization order.

**Concepts:** Composition, constructor initializer lists, constructor and destructor order, member objects, virtual base initialization.

### Task 4 – Pointers to Derived Classes

Implemented Account and SeniorAccount to demonstrate base-class pointers, derived-class pointers, smart pointers, and polymorphic pointer arrays. A separate unsafe demonstration illustrates static binding, object slicing, and the risks of deleting derived objects through base pointers without virtual destructors.

**Concepts:** Base and derived pointers, runtime polymorphism, static binding, object slicing, virtual destructors, dynamic memory management.

### Task 5 – Pointers to Objects and This Pointer

Implemented a Cart class supporting direct object access, pointer access, reference access, dynamic object creation, and arrays of object pointers. The this pointer enables method chaining by returning the current object reference.

**Concepts:** Object pointers, references, dynamic allocation, this pointer, method chaining.

### Task 6 – Vehicle Rental Fleet

Implemented an extensible vehicle hierarchy with Bicycle, TwoWheeler, Car, ElectricCar, and ElectricBus. A common Vehicle interface supports displaying vehicle details and rental operations. Late charges are calculated based on the daily rate and delay duration.

**Concepts:** Abstract classes, inheritance, polymorphism, function overriding, extensibility, rental operations.

## 4. Testing and Verification

All six main programs were compiled successfully using:

`g++ -std=c++17 -Wall -Wextra main.cpp -o main.exe`

The individual programs were tested, and output screenshots were maintained in their respective task folders.

The unsafe pointer experiment demonstrates potentially undefined behaviour. AddressSanitizer execution was not completed because the installed compiler environment could not locate the required sanitizer library.

## 5. Conclusion

The assignment provided practical experience in designing and implementing object-oriented C++ applications. The tasks demonstrate how inheritance, composition, abstraction, polymorphism, constructors, destructors, and pointers support modular and reusable software design. The implementations also highlight the importance of safe memory management and correct object lifetime handling.

## 6. References

1. Bjarne Stroustrup, *The C++ Programming Language*, Addison-Wesley.
2. ISO C++ documentation – https://isocpp.org/
3. cppreference – https://en.cppreference.com/
4. GNU Compiler Collection documentation – https://gcc.gnu.org/onlinedocs/

## 7. Appendix

The repository contains the source programs, supplementary comparison programs, analysis documents, output screenshots, UML diagrams, and this report.