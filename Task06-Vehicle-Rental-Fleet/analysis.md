# Task 6 – Vehicle Rental Fleet

## 1. Objective

To design and implement a reusable vehicle rental system using inheritance, abstract classes and runtime polymorphism.

## 2. Class Hierarchy

The abstract base class `Vehicle` stores common attributes such as registration number, daily rental rate and rental status.

Derived classes:

- `Bicycle`
- `TwoWheeler`
- `Car`
- `ElectricCar`
- `ElectricBus`

Each derived class implements the virtual `display()` function.

## 3. Object-Oriented Concepts

- Abstraction: Vehicle is an abstract class with a pure virtual function.
- Inheritance: All vehicle types inherit common properties from Vehicle.
- Runtime Polymorphism: Base-class pointers invoke the appropriate derived-class display function.
- Encapsulation: Vehicle-specific attributes are maintained within their respective classes.
- Extensibility: ElectricBus is added without modifying the existing vehicle classes.

## 4. Rental Operations

The `rent()` function checks the rental status and marks an available vehicle as rented.

The `returnVehicle()` function processes the return and calculates late charges.

Late charge formula:

Late Charge = Daily Rate × Late Days × 25%

For two late days, the bicycle late charge is:

100 × 2 × 0.25 = Rs. 50

## 5. Polymorphic Pointer Array

An array of `Vehicle*` stores addresses of different vehicle objects.

The same array is used to display vehicle details and perform rental and return operations.

## 6. Class Diagram

```text
             Vehicle
                |
    ---------------------------
    |       |       |         |
 Bicycle TwoWheeler Car  ElectricCar
                            |
                        ElectricBus
```

ElectricBus is also derived directly from Vehicle.

## 7. Extensibility

The ElectricBus class demonstrates that new vehicle categories can be introduced by extending the existing abstract base class without changing the existing derived classes.

## 8. Alternative Switch-Based Design

A switch-based implementation would require checking vehicle types before displaying details and performing operations. As new vehicle categories are added, the switch statements must also be modified.

The polymorphic design reduces type-dependent conditional logic and supports easier extension.

## 9. Conclusion

The implementation demonstrates abstract classes, inheritance, runtime polymorphism, virtual functions, base-class pointer arrays, rental management and late-charge calculation. The design supports the addition of new vehicle categories while maintaining reusable class structures.