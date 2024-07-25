# Session 3 OOP Part One

## Initializations Types

## Trivial Data Types (char, int, float,double bool)

### Copy Initialization

- Initializes a variable using the value of another variable.

```cpp
int x = 10;
```

### Value Initialization || Uniform Initialization

- Uses curly braces {} for initializing variables.
- Prevents narrowing conversions.

```cpp
int x2{};
```

### Direct Initialization

- Calls the constructor directly.

```cpp
int x3(0);
```

### Narrowing conversions

Narrowing conversions in C++ refer to conversions that may result in loss of data or precision. These conversions typically occur when a value of one type is converted to a type that cannot represent all possible values of the original type. Common examples include converting from a floating-point type to an integer type or from a larger integer type to a smaller integer type.

```cpp
int x = 3.14;     // Narrowing conversion: allowed
int x2(3.14);     // Narrowing conversion: allowed
int y {3.14};     // Error: narrowing conversion is not allowed
```

## Enum in C and C++ (enum class)

### C-Style Enum

- In C, enums are a way to assign names to integral constants, which makes the code more readable. However, they are not type-safe and can lead to naming conflicts.

```cpp
enum Color { RED, GREEN, BLUE };
Color color = RED;
```

### C++-Style Enum (enum class)

- C++ introduces enum class, which provides type safety and prevents naming conflicts. enum class members must be accessed using the scope resolution operator.

```cpp
enum class Color { RED, GREEN, BLUE };
Color color = Color::RED;
```

### Struct in C++

- A struct in C++ is a user-defined data type that groups together variables under a single name. Structs in C++ are similar to classes but differ mainly in terms of default access specifiers. In a struct, members are public by default.

```cpp
struct Point {
    int x;
    int y;
};
```

## Object-Oriented Programming (OOP)

### Class

- A class is a blueprint for creating objects (instances of the class). A class encapsulates data (attributes) and functions (methods) that operate on the data.

### Encapsulatio

Encapsulation is the bundling of data and methods that operate on that data within a single unit or class, and restricting access to some of the object's components.

### Memory Layout

In C++, objects are typically allocated on the stack or the heap:

- Stack Segment: Local variables, including object instances, are stored here.
- Heap Segment: Dynamically allocated memory (using new and delete).
- Text Segment: Stores compiled code (the program's executable instructions).
- BSS Segment: Uninitialized global and static variables.

### Global Object and BSS Section

Global objects or static objects that are not explicitly initialized are placed in the BSS (Block Started by Symbol) segment of the memory, which is initialized to zero.

### Access Modifiers

- Public: Members are accessible from outside the class.
- Private: Members are only accessible from within the class itself.
- Protected: Members are accessible within the class and by derived class instances.

### Constructors

#### Default Constructor: A constructor that takes no arguments.

```cpp
class MyClass {
public:
    MyClass() {}  // Default constructor
};
```

#### Parameterized Constructor: A constructor that takes one or more arguments.

```cpp
class MyClass {
public:
    MyClass(int value) {}  // Parameterized constructor
};
```

### This Pointer

this is an implicit pointer in C++ that points to the object for which a member function is called. It is used within a class's member functions to refer to the invoking object.

```cpp
class MyClass {
    int value;
public:
    void setValue(int value) {
        this->value = value;
    }
};
```
