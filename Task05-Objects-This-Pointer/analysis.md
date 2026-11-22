# Task 5 – Pointers to Objects and This Pointer

## 1. Objective

To demonstrate different methods of accessing objects using direct objects, pointers, references and dynamically allocated memory.

## 2. Object Access Methods

- Direct access: Members are accessed using the dot operator.
- Pointer access: Members are accessed using the arrow operator.
- Reference access: An existing object is accessed through a reference.
- Dynamic object creation: Objects are created using `new` and released using `delete`.

## 3. This Pointer

The `this` pointer refers to the current object.

The `add()` and `setDiscount()` methods return `*this` by reference, enabling method chaining.

Example:

`cart1.add(1).setDiscount(10);`

## 4. Array of Object Pointers

An array of Cart pointers stores addresses of multiple Cart objects. The program compares their total values and identifies the highest cart total.

Highest Cart Total: 324.00

## 5. Output Analysis

The same Arun object appears through different access methods. This confirms that pointers and references access the existing object rather than creating copies.

## 6. Conclusion

The experiment demonstrates object pointers, references, dynamic object creation, the `this` pointer and method chaining. Returning the current object by reference supports efficient method chaining without creating unnecessary object copies.