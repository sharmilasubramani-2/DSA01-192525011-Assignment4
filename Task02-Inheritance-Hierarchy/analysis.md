# Task 2 – From Requirement to Hierarchy

## 1. Inheritance Relationships

The university management system contains the following inheritance relationships:

| Class | Parent Class | Relationship |
|---|---|---|
| Student | Person | Is-a |
| Staff | Person | Is-a |
| TeachingAssistant | Student and Staff | Multiple inheritance |
| ResearchScholar | Student | Multilevel inheritance |

### Inheritance Types

1. Hierarchical inheritance: Student and Staff inherit from Person.
2. Multiple inheritance: TeachingAssistant inherits from Student and Staff.
3. Multilevel inheritance: ResearchScholar inherits from Student, which inherits from Person.
4. Hybrid inheritance: The overall design combines hierarchical, multiple and multilevel inheritance.

## 2. Class Access Specifiers

| Class | Member | Access Specifier |
|---|---|---|
| Person | name | Protected |
| Person | id | Protected |
| Person | phone | Protected |
| Person | display() | Public |
| Student | programme | Protected |
| Student | cgpa | Protected |
| Student | displayStudent() | Public |
| Staff | department | Protected |
| Staff | salary | Protected |
| Staff | displayStaff() | Public |
| ResearchScholar | fellowship | Private |

### Access Rules

- Public members are accessible from outside the class through an object.
- Protected members are accessible within the class and its derived classes.
- Private members are accessible only within their declaring class.

## 3. Diamond Problem

The diamond problem occurs when a class inherits from two classes that share the same base class.

In this system:

Person → Student → TeachingAssistant

Person → Staff → TeachingAssistant

Without virtual inheritance, TeachingAssistant contains two separate Person subobjects. This creates duplicate data and ambiguity when accessing Person members.

### Solution: Virtual Inheritance

Student and Staff inherit using:

`class Student : virtual public Person`

`class Staff : virtual public Person`

Virtual inheritance ensures that TeachingAssistant contains only one shared Person subobject.

## 4. Constructor Execution Analysis

### With Virtual Inheritance

TeachingAssistant:

1. Person constructor
2. Student constructor
3. Staff constructor
4. TeachingAssistant constructor

ResearchScholar:

1. Person constructor
2. Student constructor
3. ResearchScholar constructor

### Without Virtual Inheritance

TeachingAssistant:

1. Person constructor through Student
2. Student constructor
3. Person constructor through Staff
4. Staff constructor
5. TeachingAssistant constructor

ResearchScholar:

1. Person constructor
2. Student constructor
3. ResearchScholar constructor

### Observation

The experiment confirms that Person is constructed once with virtual inheritance and twice for TeachingAssistant without virtual inheritance.

## 5. Composition Alternative

Instead of multiple inheritance, TeachingAssistant could contain separate Student and Staff objects.

For example:

- TeachingAssistant contains a Student object.
- TeachingAssistant contains a Staff object.
- Each object maintains its own data and responsibilities.

This composition-based design avoids the diamond inheritance problem and duplicate base-class ambiguity.

However, it models a has-a relationship rather than the original is-a relationship. The choice depends on the actual university requirements.

## 6. Complexity and Memory Analysis

| Parameter | Virtual Inheritance | Non-Virtual Inheritance | Composition |
|---|---|---|---|
| Person subobjects in TeachingAssistant | 1 | 2 | Depends on design |
| Duplicate Person data | No | Yes | Avoidable |
| Constructor calls for Person | 1 | 2 | Depends on contained objects |
| Member access ambiguity | Avoided | Possible | Avoided |
| Design structure | Shared base class | Separate base subobjects | Independent contained objects |

The time complexity of accessing an ordinary data member is O(1). The inheritance mechanism does not change this basic complexity.

Object sizes depend on compiler implementation, alignment, padding and virtual inheritance overhead. Therefore, exact sizes should be measured using `sizeof()` on the target compiler.

## 7. Conclusion

The university management system demonstrates hierarchical, multiple, multilevel and hybrid inheritance. The diamond problem was reproduced by removing virtual inheritance and resolved by using virtual base classes. Virtual inheritance avoids duplicate Person subobjects and provides a consistent shared base-class representation.
## 8. Experimental Object Size Comparison

The sizeof() operator was used to measure the object sizes of the
classes in both implementations.

### Measured Results

| Class | With Virtual Inheritance | Without Virtual Inheritance |
|---|---:|---:|
| Person | 80 bytes | 80 bytes |
| Student | 128 bytes | 120 bytes |
| Staff | 128 bytes | 120 bytes |
| TeachingAssistant | 176 bytes | 240 bytes |
| ResearchScholar | 136 bytes | 128 bytes |

### Analysis

The TeachingAssistant object occupies 176 bytes with virtual
inheritance and 240 bytes without virtual inheritance.

The 64-byte difference demonstrates the memory impact of duplicate
Person subobjects in the non-virtual implementation.

Student and Staff objects are slightly larger with virtual inheritance
because of compiler-specific virtual base implementation overhead.

The exact object sizes depend on the compiler, architecture,
alignment and implementation details.

### Conclusion

The experiment confirms that virtual inheritance avoids duplicate
Person subobjects in TeachingAssistant. Although virtual inheritance
may introduce additional implementation overhead in individual base
classes, it reduces the overall TeachingAssistant object size in
this experiment.