# Task 3 – Constructors in Derived Classes and Member Classes

## 1. Constructor Initializer Lists

Constructor initializer lists initialize base classes and member objects before the constructor body executes.

Student and Staff initialize the Person base class and their respective data members. TeachingAssistant initializes the shared virtual Person base because it is the most-derived class.

## 2. Composition

Address is a member object of Person, and Course is a member object of Student.

This demonstrates composition, where one class contains objects of other classes.

## 3. Virtual Inheritance

Student and Staff virtually inherit Person.

TeachingAssistant inherits from both Student and Staff. Virtual inheritance ensures that TeachingAssistant contains only one shared Person base object.

## 4. Constructor and Destructor Order

### With Virtual Inheritance

Person → Student → Staff → TeachingAssistant

Destruction:

TeachingAssistant → Staff → Student → Person

### Without Virtual Inheritance

Person → Student → Person → Staff → TeachingAssistant

Destruction:

TeachingAssistant → Staff → Person → Student → Person

Virtual inheritance prevents duplicate Person base objects.

## 5. Object Size Comparison

| Class | With Virtual Inheritance | Without Virtual Inheritance |
|---|---:|---:|
| Person | 120 bytes | 120 bytes |
| Student | 200 bytes | 192 bytes |
| Staff | 168 bytes | 160 bytes |
| TeachingAssistant | 248 bytes | 352 bytes |

The TeachingAssistant object occupies 104 fewer bytes with virtual inheritance in this experiment.

The measured sizes depend on compiler implementation, architecture, alignment and object layout.

## 6. Engine, Vehicle and Car

Engine is a member object of Vehicle, and Car inherits Vehicle.

Construction order:

Engine → Vehicle → Car

Destruction order:

Car → Vehicle → Engine

Member objects are constructed before the containing class constructor body and destroyed after the containing class destructor body.

## 7. Dynamic Pointer Alternative

A dynamically allocated Address object can be managed using a smart pointer such as std::unique_ptr.

This allows controlled dynamic memory management and automatic cleanup when the owning object is destroyed.

However, composition using a direct Address member is simpler when Person always requires an Address object.

## 8. Conclusion

The experiment demonstrates constructor initializer lists, composition, virtual inheritance, multiple inheritance, object construction and destruction order.

Virtual inheritance eliminates duplicate Person base objects in TeachingAssistant. The sizeof experiment demonstrates the memory-layout difference between virtual and non-virtual inheritance on the tested compiler.