# Derived
# Functions
## basic function
- basic functions as same as C
- Except that we can add defualt parameters
```cpp
#include <iostream>
void printMessage(std::string message = "Hello, World!") {
std::cout << message << std::endl;
}

int main() {
printMessage(); // Prints default message
printMessage("Hi there!"); // Prints custom message
return 0;
}

``` 
- tricky:
```cpp
#include <iostream>
void fun(int x = 2, int y);
void fun(int x, int y) {
    std::cout << x << " " << y << std::endl;
}

int main() {
    fun(2);
    return 0;
}
```
- this code results an error as when you add default paramter the following parameters must have default values also
- correct code 

```cpp
#include <iostream>
void fun(int y, int x=2);
void fun(int y, int x) {
    std::cout << x << " " << y << std::endl;
}

int main() {
    fun(3);
    return 0;
}
```
- output: 2 3

## Function overloading 
- Function overloading allows multiple functions to have the same name with different parameters. The correct function to be called is determined by the arguments provided.
```cpp
#include <iostream>

void print(int i) {
    std::cout << "Integer: " << i << std::endl;
}

void print(double f) {
    std::cout << "Double: " << f << std::endl;
}

void print(const std::string &s) {
    std::cout << "String: " << s << std::endl;
}

int main() {
    print(10);
    print(3.14);
    print("Hello, World!");
    return 0;
}
```
## Ambiguous function call
```cpp
void fun(int x, int y = 3){
std::cout << x <<" " << y << std::endl;
}
void fun(int x, float y = 3){
std::cout << x <<" " << y << std::endl;
}
int main()
{
    fun(2);
    return 0;
}
```
- the function call is ambiguous


## Mangling 
- Name mangling is the process where the compiler generates unique names for each function based on their parameters. This allows function overloading to work. Mangled names are often compiler-specific.
##Demangling
- to see how your functions are mangled 
- seeing mangling: grep on your function name in the objdump file 
```
objdump -t --demangle | grep fun_name
```
-demangling: using c++filt tool
```
c++filt mangled_name_of_function
```

#Arrays
## Declaration
To declare an array, specify the type of elements and the number of elements in brackets.

```cpp
int numbers[6]; // Declare an integer array with 6 elements
```
## Initialization
- Arrays can be initialized when declared.
```cpp
int numbers[6] = {2, 4, 8, 12, 16, 18}; // Initialize array elements
```
- or 
```cpp
int numbers[] = {2, 4, 8, 12, 16, 18}; // Compiler determines the size
```
## Accessing Elements
```cpp
for (int i = 0; i < 6; ++i) {
    cout << numbers[i] << " ";
}
```
- or use ranged loop
```cpp
int numbers[] = {0, 1, 2, 3, 4, 5};
for (int value : numbers) {
    std::cout << value << " ";
}
```
## Memory Layout
- Memory layout of arrays in C++ involves contiguous memory allocation for array elements.

# Pointers
- it have tha same rules as c pointers
## pointer to function syntax
```cpp
#include <iostream>
void greet() {
    std::cout << "Hello, World!" << std::endl;
}
int main() {
    void (*funcPtr)() = greet;
    funcPtr();
    return 0;
}
```
## Arrays and Pointers

- Arrays are closely related to pointers:

```cpp
int arr[5] = {1, 2, 3, 4, 5};
int *ptr = arr; // Pointer points to the first element of the array

## Pointer Arithmetic
```cpp
int *nextPtr = ptr + 1; // Points to the next element in the array
```

# References
- References are aliases(another names) for other variables.
```cpp
#include <iostream>
int main() {
    int a = 10;
    int &b =a;
    b=8;
    std::cout << a << " ";
    std::cout << b << "\n";
    return 0;
}
```
- output: 8 8

## Calling By References
```cpp
#include <iostream>

void byValue(int x) {
    x = 100;
}

void byPointer(int *x) {
    *x = 100;
}

void byReference(int &x) {
    x = 100;
}

int main() {
    int a = 10;
    byValue(a);
    std::cout << "By value: " << a << std::endl;

    byPointer(&a);
    std::cout << "By pointer: " << a << std::endl;

    byReference(a);
    std::cout << "By reference: " << a << std::endl;

    return 0;
}
```
- output: By value: 10
- By pointer: 100
- By reference: 100

## Null Pointer
- The diffrence between nullptr and NULL
- using NULL
```cpp
#include <iostream>

void foo(int) {
    std::cout << "Called foo(int)" << std::endl;
}

void foo(char*) {
    std::cout << "Called foo(char*)" << std::endl;
}

int main() {
    foo(NULL); // Ambiguous: could call either foo(int) or foo(char*)
    return 0;
}
```
- using nullptr
```cpp
#include <iostream>

void foo(int) {
    std::cout << "Called foo(int)" << std::endl;
}

void foo(char*) {
    std::cout << "Called foo(char*)" << std::endl;
}

int main() {
    foo(nullptr); // Unambiguous: calls foo(char*)
    return 0;
}
```
## Dynamic Memory Allocation
- Allocation:
```cpp
int *ptr = new int;
*ptr = 43;
```
- Deallocation
```cpp
delete ptr;
ptr = nullptr;
```

## auto keyword
```cpp
auto var = 10;
auto var2 = 10.5;

auto var3 = 'a';
auto var4 = const char*;
auto var5 = std::string("hello String ");

// with const
const int x = 10;
auto var6 = x; // var is int
//** to make it const
const auto var7 = x;
// with referance const works as expectd 
auto &var8 = x;
// with pointer const works as expectd  
auto ptr = &;

// std::initliaizer_list
auto Ist = {1, 2, 3, 4, 5};
// error
// auto lst{l, 2, 3, 4};
return 0;
```


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
## Capture List
- [captured_variables]: This is the capture list, which allows the lambda to access variables from its enclosing scope.

- [&] captures all variables by reference.
- [=] captures all variables by value.
- Specific variables can be captured by listing them, like [x, &y].
## Mutable Variables
- The mutable keyword allows modifying captured variables within the lambda
```cpp
[temp] mutable {
    return x + y;
};
```

## Return Type
- -> return_type: This specifies the return type of the lambda function. If omitted, the return type is deduced automatically.
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