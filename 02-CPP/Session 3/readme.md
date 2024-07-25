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

### narrowing conversions

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
