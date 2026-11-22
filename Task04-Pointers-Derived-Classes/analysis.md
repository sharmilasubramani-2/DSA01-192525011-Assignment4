# Task 4 – Pointers to Derived Classes

## 1. Problem Analysis

The original Account hierarchy contains three major design issues:

- Non-virtual functions cause static binding through base-class pointers.
- A non-virtual destructor can cause undefined behaviour when deleting a derived object through a base pointer.
- Object slicing occurs when a derived object is copied into a base object by value.

## 2. Improved Design

The Account class provides a virtual getInterestRate() function and a virtual destructor.

SeniorAccount overrides getInterestRate() and display(). It also manages a dynamically allocated transaction history.

## 3. Polymorphism

The base Account pointer can refer to both Account and SeniorAccount objects.

The virtual function ensures runtime binding.

Observed interest rates:

| Object | Interest Rate |
|---|---:|
| Account | 3.5% |
| SeniorAccount | 4.0% |

## 4. Virtual Destructor

The virtual destructor ensures that the derived class destructor executes before the base class destructor when an object is deleted through a base-class pointer.

Observed destruction order:

SeniorAccount destructor → Account destructor

## 5. Dynamic Memory Management

SeniorAccount allocates transaction history dynamically using new[] and releases it using delete[].

The implementation also demonstrates std::unique_ptr, which automatically manages object lifetime and prevents memory leaks.

## 6. Conclusion

The experiment demonstrates runtime polymorphism, base-class pointers, function overriding, virtual destructors and dynamic memory management. Smart pointers provide safer resource management in an inheritance hierarchy.