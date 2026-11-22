# Task 4 – Pointers to Derived Classes

## 1. Objective

To examine polymorphism, base-class pointers, derived-class access, object slicing, virtual destructors and safe dynamic memory management.

## 2. Problems in the Original Design

The original Account hierarchy demonstrates three important design problems.

### 2.1 Static Binding

When a base-class pointer accesses a non-virtual function, the function belonging to the pointer's declared type is called.

Observed output:

| Access | Interest Rate |
|---|---:|
| Base-class pointer | 3.5 |
| Derived object | 4.0 |

The base pointer calls the base-class function because the function is non-virtual.

### 2.2 Object Slicing

Object slicing occurs when a derived-class object is copied into a base-class object.

```cpp
Account sliced = senior;
```

Only the base-class portion is copied. Derived-class-specific members and behaviour are not retained.

The sliced object displays the base Account interest rate of 3.5%.

### 2.3 Non-Virtual Destructor

The original Account destructor is non-virtual.

When a dynamically allocated SeniorAccount object is deleted through an Account pointer, the derived destructor is not properly invoked.

Observed destruction output for the dynamically allocated object:

```text
Account constructor called
SeniorAccount constructor called
Account destructor called
```

The SeniorAccount destructor is skipped, so its dynamically allocated transaction history is not released.

Deleting a derived object through a base pointer with a non-virtual destructor results in undefined behaviour.

## 3. Improved Design

The corrected implementation in `main.cpp` uses:

- Virtual `getInterestRate()` function.
- Virtual `display()` function.
- Virtual base-class destructor.
- Function overriding in SeniorAccount.
- Dynamic memory release using `delete[]`.

These changes support runtime polymorphism and safe destruction through base-class pointers.

## 4. Polymorphism

The Account pointer can refer to both Account and SeniorAccount objects.

Virtual functions ensure that the correct derived implementation is selected at runtime.

| Object | Interest Rate |
|---|---:|
| Account | 3.5% |
| SeniorAccount | 4.0% |

## 5. Virtual Destructor

The corrected implementation declares the Account destructor as virtual.

When an object is deleted through an Account pointer, the derived destructor executes first, followed by the base destructor.

Expected destruction order:

```text
SeniorAccount destructor called
Account destructor called
```

## 6. Dynamic Memory Management

SeniorAccount allocates its transaction history using `new[]` and releases it using `delete[]`.

The corrected implementation also demonstrates `std::unique_ptr`, which automatically manages object lifetime.

## 7. AddressSanitizer Experiment

Compilation was attempted using:

```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -g unsafe_demo.cpp -o unsafe_demo.exe
```

The compilation failed because the installed MinGW environment could not locate the AddressSanitizer library `libasan`.

Therefore, no AddressSanitizer runtime report was obtained. The limitation is documented rather than treating the experiment as successfully completed.

## 8. Conclusion

The experiment demonstrates static binding, object slicing, unsafe base-pointer deletion, runtime polymorphism, virtual destructors and dynamic memory management.

The corrected inheritance design uses virtual functions and smart pointers to improve safety, extensibility and resource management.