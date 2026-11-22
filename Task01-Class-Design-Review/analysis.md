# Task 1 – Class Design Review

## 1.1 Diagnose the Design

The original payroll implementation contains several object-oriented design deficiencies.

| No. | Design Deficiency | Explanation |
|---|---|---|
| 1 | Repeated data members | Professor and LabAssistant separately declare `name`, `id` and `basic`, resulting in duplicated code. |
| 2 | Public data members | All attributes are public, allowing external code to modify employee information without validation. |
| 3 | Inconsistent naming | Professor and LabAssistant use `name` and `id`, whereas GuestFaculty uses `nm` and `code` for equivalent information. |
| 4 | Unused data member | The `da` field is declared in Professor and LabAssistant but is not used in their pay calculations. |
| 5 | Magic number | The value `0.42` is directly embedded in the pay calculation instead of being defined as a named constant. |
| 6 | No common interface | The three classes do not share a common base class, making uniform processing difficult. |
| 7 | Poor extensibility | Adding another staff category requires separate implementation and may introduce duplicated logic. |

## 1.2 Repair the Design

The design is improved using a common abstract base class named `Staff`.

- `Staff` stores the common employee information: `name` and `id`.
- The `pay()` function is declared as a pure virtual function.
- `Professor`, `LabAssistant` and `GuestFaculty` publicly inherit from `Staff`.
- Each derived class overrides `pay()` according to its salary calculation.
- The common data is protected, while category-specific data is private.
- `DA_RATE` is declared as a named constant to avoid repeating the magic number.
- A virtual destructor ensures safe destruction through base-class pointers.

### UML Class Diagram

```text
                 +---------------------------+
                 |       Staff               |
                 +---------------------------+
                 | # name : string           |
                 | # id : int                |
                 +---------------------------+
                 | + Staff(name, id)         |
                 | + pay() : double {pure}   |
                 | + display() : void        |
                 | + ~Staff() : virtual      |
                 +-------------+-------------+
                               |
                 +-------------+-------------+
                 |             |             |
                 v             v             v
       +----------------+ +----------------+ +----------------+
       | Professor      | | LabAssistant   | | GuestFaculty   |
       +----------------+ +----------------+ +----------------+
       | - basic        | | - basic        | | - hours        |
       | - research     | |                | | - rate         |
       +----------------+ +----------------+ +----------------+
       | + pay()        | | + pay()        | | + pay()        |
       +----------------+ +----------------+ +----------------+
```

### Salary Calculation

| Staff Category | Pay Calculation |
|---|---|
| Professor | Basic + (Basic × 0.42) + Research Allowance |
| LabAssistant | Basic + (Basic × 0.42) |
| GuestFaculty | Working Hours × Hourly Rate |

### Implementation Approach

The implementation uses `vector<unique_ptr<Staff>>` to store different derived objects through base-class pointers.

When `display()` calls `pay()`, runtime polymorphism selects the appropriate overridden function based on the actual object type.

This avoids separate processing logic for each staff category.

## 1.3 Design Defence

The common Staff base class stores shared employee information and defines a common pay() interface. Each derived class implements its own salary calculation through overriding. Therefore, a new staff category can be introduced by deriving another class from Staff and implementing pay(), without modifying the existing derived classes or the payroll processing loop. This improves code reuse, maintainability and extensibility through runtime polymorphism.

## 1.4 Alternative Concept and Complexity Analysis

An alternative design would represent all employees using one `Staff` class containing a type field and a switch statement inside `pay()`.

### Alternative Design Approach

```cpp
enum class StaffType {
    Professor,
    LabAssistant,
    GuestFaculty
};

class Staff {
public:
    StaffType type;
    double basic;
    double research;
    double hours;
    double rate;

    double pay() const {
        switch (type) {
            case StaffType::Professor:
                return basic + basic * 0.42 + research;

            case StaffType::LabAssistant:
                return basic + basic * 0.42;

            case StaffType::GuestFaculty:
                return hours * rate;
        }

        return 0.0;
    }
};
```

### Complexity Comparison

| Parameter | Inheritance Approach | Single Class with Switch |
|---|---|---|
| Time per pay() call | O(1) | O(1) |
| Space per object | Stores common and category-specific fields | Stores all category-specific fields, including unused fields |
| Adding a staff type | Add a new derived class and override `pay()` | Modify the enum, add required fields if necessary, and update the switch |
| Maintainability | Better separation of responsibilities | Logic becomes concentrated in one class |
| Extensibility | Existing payroll loop remains unchanged | Existing switch-based logic must be modified |

### Places Requiring Modification

When adding a new staff category to the switch-based approach, at least the following locations may require changes:

1. The `StaffType` enumeration.
2. The `Staff` class data members, if new attributes are required.
3. The `pay()` switch statement.
4. Object creation and input-handling logic.

In the inheritance approach, a new derived class can implement the required salary calculation while the existing payroll loop remains unchanged.

### Conclusion

Both approaches provide O(1) time complexity for an individual pay calculation. However, the inheritance approach provides better separation of responsibilities and extensibility. The switch-based approach may waste memory because every object stores fields that may not be relevant to its staff category. Therefore, inheritance and runtime polymorphism are preferred for this payroll system.