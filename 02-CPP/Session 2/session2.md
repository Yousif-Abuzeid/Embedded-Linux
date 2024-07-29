# C++ Casting Summary

Casting in C++ is a mechanism to convert a variable from one type to another. There are several types of casting, each designed for specific scenarios.

## 1. C-Style Cast

The traditional method inherited from C. It can be used to cast any type to any other type, but it is not type-safe and can lead to errors.

```cpp
int a = 10;
double b = (double)a;  // C-style cast
```

## 2. Static Cast (static_cast)

The most common cast in C++. It performs a compile-time check and is type-safe, meaning it will only perform casts that are sensible and allowed by the type system.

```cpp
int a = 10;
double b = static_cast<double>(a);  // Static cast
```

## 3. Dynamic Cast (dynamic_cast)

Used for casting pointers or references to base class objects into pointers or references to derived class objects. It is primarily used with polymorphic classes (those with virtual functions). It performs a runtime check and can return nullptr if the cast is not valid.

```cpp
class Base { virtual void foo() {} };
class Derived : public Base { void foo() override {} };

Base* base = new Derived();
Derived* derived = dynamic_cast<Derived*>(base); // Dynamic cast
```

## 4. Const Cast (const_cast)

Used to add or remove const or volatile qualifiers from a variable. It is the only cast that can change the constness of a variable.

```cpp
const int a = 10;
int* b = const_cast<int*>(&a);  // Const cast
```

## 5. Reinterpret Cast (reinterpret_cast)

Used for low-level reinterpreting of bit patterns. It is the most dangerous cast, as it can cast one type to any other type of the same size. It is mainly used for system-level programming or interfacing with hardware.

```cpp
int a = 10;
char* b = reinterpret_cast<char*>(&a);  // Reinterpret cast
```

## Summary of Usage

- C-Style Cast: Avoid in modern C++ due to lack of type safety and clarity.
- Static Cast: Use for most non-polymorphic type conversions.
- Dynamic Cast: Use for safe downcasting in polymorphic hierarchies.
- Const Cast: Use to add/remove const or volatile qualifiers.
- Reinterpret Cast: Use for low-level casts where bitwise reinterpretation is needed.

## Lambda Expressions
### Syntax
- Lambda expressions provide a concise way to create anonymous function objects. The basic syntax is:

```cpp
auto func = []() {
    // function body
};
```
- You can also capture variables, pass parameters, and specify the return type:

```cpp
auto func = [captured_variables](parameters) -> return_type {
    // function body
};
```
## Implementation (Functors)
Lambda expressions are essentially syntactic sugar for creating functors (objects that can be called as if they are functions). Here's an example of a lambda expression and its equivalent functor:

```cpp
// Lambda expression
auto lambda = [](int a, int b) -> int {
    return a + b;
};
// Equivalent functor
struct Add {
    int operator()(int a, int b) const {
        return a + b;
    }
};
```
- Both lambda and Add can be used to add two integers.

## Const vs Constexpr
### const
The const keyword is used to declare variables whose value cannot be changed after initialization. It can be used with variables, pointers, and member functions:

```cpp
const int x = 10;          // constant variable
const int* ptr = &x;       // pointer to a constant integer
int* const ptr2 = &x;      // constant pointer to an integer
```
### constexpr
The constexpr keyword is used to declare variables, functions, and objects that can be evaluated at compile time. This allows for optimizations and ensures that the value is constant:

```cpp
constexpr int y = 20;      // constant expression

constexpr int add(int a, int b) {
    return a + b;
}

constexpr int result = add(3, 4); // evaluated at compile time
```

### Differences
- const ensures that the value cannot be changed, but the value might be determined at runtime.
- constexpr ensures that the value is constant and can be evaluated at compile time.
```cpp
const int a = 5;
constexpr int b = 10;

int array1[a];           // This may not compile, depending on the compiler
int array2[b];           // This will always compile

constexpr int add(int x, int y) {
    return x + y;
}

int result = add(a, b);  // This will be evaluated at compile time
```