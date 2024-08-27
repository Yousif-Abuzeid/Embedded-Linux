# Algorithm and RAII

## For Algorithm Check [Here](https://hackingcpp.com/)

## Try/Catch

- Try/Catch is a way to handle exceptions in C++.
- noexcept is a way to tell the compiler that a function will not throw an exception.

```cpp
void foo()  {
    throw std::runtime_error("Error");
}

int main() {
    try {
        foo();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

output: Runtime Error

```

- Rethrowing an exception

```cpp

void functionB(){
    try {
        throw std::runtime_error("Error");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        throw; // Rethrow the exception
    }
}

void functionA(){
    try {
        functionB();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

```

- We Must Handle Exceptions in nested functions.

## Namespace

- Namespace is a way to avoid name conflicts in C++.
- Namespace is a way to group related functions, classes, and variables.


```cpp

namespace my_namespace {
    void foo() {
        std::cout << "Hello from my_namespace" << std::endl;
    }
}

int main() {
    my_namespace::foo();
}

```

### Nested Namespace

```cpp

namespace my_namespace {
    namespace nested_namespace {
        void foo() {
            std::cout << "Hello from nested_namespace" << std::endl;
        }
    }
}

int main() {
    my_namespace::nested_namespace::foo();
}

```
### Using Namespace

```cpp


namespace my_namespace {
    void foo() {
        std::cout << "Hello from my_namespace" << std::endl;
    }
}

int main() {
    using namespace my_namespace;
    foo();
}

```

### Using Alias

```cpp

namespace my_namespace {
    void foo() {
        std::cout << "Hello from my_namespace" << std::endl;
    }
}

int main() {
    namespace my = my_namespace;
    my::foo();
}

```
## New/Delete

- New and Delete are used to manually allocate and deallocate memory in C++. 

```cpp

int* p = new int;
*p = 5;
std::cout << *p << std::endl;
delete p;

```
- p is said to be an owning pointer because it is responsible for deleting the memory it points to.
- p is stored on the stack, and the memory it points to is stored on the heap.
- if we delete p twice, it will cause a double free error.

```cpp

int* p = new int;
*p = 5;
std::cout << *p << std::endl;
delete p;
delete p; // Double Free Error

```
- we can use nullptr to avoid double free error.

```cpp
- If we forget to delete the memory, it will cause a memory leak.

```cpp

int* p = new int;
*p = 5;
std::cout << *p << std::endl;
// delete p; // Memory Leak

```

## Nightmare of New/Delete

- If we forget to delete the memory, it will cause a memory leak.
- If we delete the memory twice, it will cause a double free error.
- If we delete the memory and then access it, it will cause a dangling pointer error.
- If we forget to initialize the pointer, it will cause an uninitialized pointer error.
- If we forget to check if the memory was allocated successfully, it will cause a null pointer error.
- We have to manually manage the memory, which is error-prone and time-consuming.
- Very error-prone and time-consuming, Can lead to hard to catch bugs.

## RAII (Resource Acquisition Is Initialization)

- RAII is a way to manage resources in C++.
- RAII is a way to avoid memory leaks, double free errors, dangling pointer errors, uninitialized pointer errors, and null pointer errors.
- RAII is a way to manage resources automatically.
- RAII is a way to manage resources in a safe and efficient way.
- RAII is a way to manage resources in a way that is easy to understand and maintain.

- `Constructor: Resource Acquisition`
- `Destructor: Resource Release`

```cpp  

class MyResource {
    private :
        int* p;
public:
    MyResource(): p(new int) {
        std::cout << "Resource Acquired" << std::endl;
    }

    ~MyResource() {
        delete p;
        std::cout << "Resource Released" << std::endl;
    }
};
```

## Smart Pointers

- Smart pointers are a way to manage resources in C++.
- It’s a pointer-wrapping stack-allocated object. Smart pointers, in plain terms, are classes that wrap a pointer, or scoped pointers.
- It destroys itself when it goes out of its scope.
- Smart pointers are more efficient as they have an additional feature of memory management. 
- They are automatic/pre-programmed in nature.

### Types of Smart Pointers

- `std::unique_ptr`
- `std::shared_ptr`
- `std::weak_ptr`

### std::unique_ptr

- holds one object (allocated on the heap) and takes ownership of that object.
- When the unique_ptr goes out of scope, the object is deleted.
- **unique ownership** : only one unique_ptr can own the object.
- Not copyable, but movable.

```cpp
#include <memory>

std::unique_ptr<int> p= std::make_unique<int>(5);
*p = 5;
std::cout << *p << std::endl;

std::unique_ptr<int> q = p; // Error: Not Copyable
std::unique_ptr<int> q = std::move(p); // OK: Movable
```
### std::unique_ptr with Custom Deleter

- We can use a custom deleter to delete the object in a different way.

```cpp

#include <memory>

class MyDeleter {
public:
    void operator()(int* p) {
        std::cout << "Custom Deleter" << std::endl;
        delete p;
    }
};

int main() {
    std::unique_ptr<int, MyDeleter> p(new int);
}

```
### std::unique_ptr with Array

- We can use std::unique_ptr with arrays.

```cpp

#include <memory>

std::unique_ptr<int[]> p(new int[5]);
p[0] = 1;
std::cout << p[0] << std::endl;

```

### std::unique_ptr methods
**Member Functions**
- `Constructor`: Creates a unique_ptr.
- `Destructor`: Deletes the object.
- `operator=`: Assigns the unique_ptr (cant be copied only moved).
**Modifiers**
- `reset()`: Deletes the object and sets the pointer to nullptr.
- `release()`: Releases the ownership of the object.
- `swap()`: Swaps the ownership of the object.
**Observers**
- `get()`: Returns the raw pointer.
- `get_deleter()`: Returns the deleter.
- `operator bool()`: Returns true if the unique_ptr is not nullptr.
**How to Access**
- Single Object
        - `operator*`: Returns the object.
        - `operator->`: Returns the object.
- Array
        - `operator[]`: Returns the object.

```cpp

#include <memory>

std::unique_ptr<int> p = std::make_unique<int>(5);
std::cout << p.get() << std::endl;
p.reset();
std::cout << p.get() << std::endl;
std::unique_ptr<int> q = p.release();
std::cout << p.get() << std::endl;
std::cout << q.get() << std::endl;
 // p is nullptr
// q is not nullptr

```

### std::shared_ptr

- holds a shared object (allocated on the heap) and takes shared ownership of that object.
- Conatins a reference count.
- When a new shared_ptr is created, the reference count is incremented.
- When a shared_ptr is deleted, the reference count is decremented.
- When the last shared_ptr goes out of scope, the object is deleted.
- **shared ownership** : multiple shared_ptr can own the object.
- Copyable and movable.

```cpp

#include <memory>

std::shared_ptr<int> p = std::make_shared<int>(5);
*p = 5;
std::cout << *p << std::endl;

std::shared_ptr<int> q = p; // OK: Copyable
std::shared_ptr<int> q = std::move(p); // OK: Movable

std::shared_ptr<int> ptr2 = q;
std::cout << q.use_count() << std::endl; // 2
std::cout << ptr2.use_count() << std::endl; // 2

```

### std::shared_ptr methods

**Member Functions**
- `Constructor`: Creates a shared_ptr.
- `Destructor`: Deletes the object.
- `operator=`: Assigns the shared_ptr.
**Modifiers**
- `reset()`: Deletes the object and sets the pointer to nullptr.
- `swap()`: Swaps the ownership of the object.
**Observers**
- `get()`: Returns the raw pointer.
- `use_count()`: Returns the reference count.
- `unique()`: Returns true if the reference count is one.(until c++ 20)
- `operator bool()`: Returns true if the shared_ptr is not nullptr.
**How to Access**
- Single Object
        - `operator*`: Returns the object.
        - `operator->`: Returns the object.
- Array
        - `operator[]`: Returns the object.


### Circular Reference in shared_ptr

- Circular reference is a situation in which two or more objects refer to each other.
- Objects are not deleted because they have a reference count greater than zero.

```cpp

#include <memory>

class B;

class A {
    std::shared_ptr<B> b;
public:
    void setB(std::shared_ptr<B> b) {
        this->b = b;
    }
    ~A() {
        std::cout << "A Deleted" << std::endl;
    }
};

class B {
    std::shared_ptr<A> a;
public:

    void setA(std::shared_ptr<A> a) {
        this->a = a;
    }
    ~B() {
        std::cout << "B Deleted" << std::endl;
    }

};


int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->setB(b);
    b->setA(a);
    // a and b are not deleted
}

```

### std::weak_ptr

- holds a weak object (allocated on the heap) and takes weak ownership of that object.
- Does not increase the reference count.
- When the last shared_ptr goes out of scope, the object is deleted.
- **weak ownership** : does not own the object.
- Solve the circular reference problem.

### std::weak_ptr methods

**Member Functions**
- `Constructor`: Creates a weak_ptr.
- `Destructor`: Deletes the object.
- `operator=`: Assigns the weak_ptr.
**Modifiers**
- `reset()`: Deletes the object and sets the pointer to nullptr.
- `swap()`: Swaps the ownership of the object.
**Observers**
- `get()`: Returns the raw pointer.
- `use_count()`: Returns the reference count.
- `expired()`: Returns true if the object is deleted.
- `lock()`: Returns a shared_ptr that manages the referenced object.
***How to Access**
- Single Object
        - `operator*`: Returns the object.
        - `operator->`: Returns the object.
- Array
        - `operator[]`: Returns the object.

```cpp

#include <memory>

class B;

class A {
    std::shared_ptr<B> b;
public:
    void setB(std::shared_ptr<B> b) {
        this->b = b;
    }
    ~A() {
        std::cout << "A Deleted" << std::endl;
    }
};

class B {
    std::weak_ptr<A> a;
public:
    
        void setA(std::shared_ptr<A> a) {
            this->a = a;
        }
        ~B() {
            std::cout << "B Deleted" << std::endl;
        }
    
    };


int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->setB(b);
    b->setA(a);
    // a and b are deleted
}

```

## Templates

- Templates are a way to write generic code in C++.
- Parameter types are determined from arguments.
- Templates are a way to write functions and classes that work with any data type.
- std::algorithm is a good example of templates.

### Function Templates

- Write a template once and use it with any data type.
- Instantiate the template with the desired data type.

```cpp

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.1, 2.2) << std::endl;
}

```

- We can also use multiple data types.

```cpp

template <typename T, typename U>
auto add(T a, U b) {
    return a + b;
}
// auto is used to deduce the return type.

int main() {
    std::cout << add(1, 2.2) << std::endl;
}

```

- **`The compiler will generate the appropriate function for the data type`**.

### Class Templates

- Write a template once and use it with any data type.
- Instantiate the template with the desired data type.
- std:: Container classes are a good example of templates.

```cpp

template <typename T>

class MyVector {
    T* data;
    size_t size;
public:
    MyVector(size_t size): size(size), data(new T[size]) {}
    T& operator[](size_t index) {
        return data[index];
    }
    ~MyVector() {
        delete[] data;
    }
};

int main() {
    //<=c++ 14 types must be specified explicitly 
    //C++ 17 onwards type deduction is possible
    
    MyVector<int> v(5);

    MyVector<double> v(5);

    v[0] = 1;
    std::cout << v[0] << std::endl;
}

```

### How to use templates

1. Basic Template Single Argument

```cpp

template <typename T>
T add(T a, T b) {
    return a + b;
}
```

2. Basic Template Multiple Arguments

```cpp

template <typename T, typename U>
auto add(T a, U b) {
    return a + b;
}
```

3. Class Template

```cpp

template <typename T>
class MyVector {
    T* data;
    size_t size;
public:

    MyVector(size_t size): size(size), data(new T[size]) {}
    T& operator[](size_t index) {
        return data[index];
    }
    ~MyVector() {
        delete[] data;
    }
};

```

4. Class Template With Standalone Function

```cpp

template <typename T> 
class Container {
    T data;
public:
    Container(T data): data(data) {}
    T getData() {
        return data;
    }
    template <typename U>
    void add(U value) {
        data += value;
    }
    void print() {
        std::cout << data << std::endl;
    }
};

```

5. Explicit Specialization

- `Explicit specialization is a way to provide a different implementation for a specific data type`.

```cpp

template <typename T>
class Container {
    T data;
public:
    Container(T data): data(data) {}
    T getData() {
        return data;
    }
    void print() {
        std::cout << data << std::endl;
    }
};

template <>

class Container<std::string> {
    std::string data;
public:
    Container(std::string data): data(data) {}
    std::string getData() {
        return data;
    }
    void print() {
        std::cout << data << std::endl;
    }
};

```

6. Partial Specialization

- `Partial specialization is a way to provide a different implementation for a specific data type`.

```cpp
template <typename T, typename U>
class Container {
    T data;
    U value;
public:
    Container(T data, U value): data(data), value(value) {}
    T getData() {
        return data;
    }
    U getValue() {
        return value;
    }
    void print() {
        std::cout << data << " " << value << std::endl;
    }
};

template <typename T>
class Container<T, std::string> {
    T data;
    std::string value;

public:
    Container(T data, std::string value): data(data), value(value) {}
    T getData() {
        return data;
    }
    std::string getValue() {
        return value;
    }
    void print() {
        std::cout << data << " " << value << std::endl;
    }
};

```

7. default template arguments

- `Default template arguments are a way to provide a default data type for a template`.

```cpp

template <typename T = int>
T add(T a, T b) {
    return a + b;
}

```
8. Const Template Arguments

- `Const template arguments are a way to provide a constant data type for a template`.
- Like std::array

```cpp

template <typename T, int Size>
class MyArray {
    T data[Size];
public:
    MyArray() {}
    T& operator[](int index) {
        return data[index];
    }
};

int main() {
    MyArray<int, 5> arr;
    arr[0] = 1;
    std::cout << arr[0] << std::endl;
}

```

### Variadic Templates

- `Variadic templates are a way to write functions and classes that take a variable number of arguments`.

```cpp

// Base Case
template <typename T>
T add(T a) {
    return a;
}

// Recursive Case
template <typename T, typename... Args>
T add(T first, Args... args) {
    return first + add(args...);
}
template <typename T>
void print(T t) {
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void print(T t, Args... args) {
    std::cout << t << " ";
    print(args...);
}

int main() {
    std::cout << add(1, 2, 3, 4, 5) << std::endl;
    // 15
    print(1, 2, 3, 4, 5);
    // 1 2 3 4 5
}

```


### SFINAE (Substitution Failure Is Not An Error)

- `SFINAE is a way to enable or disable a function or class template based on a condition`.

```cpp

template <typename T>
typename T::value_type add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(1, 2) << std::endl;
    // Error: int does not have value_type
}

```

- We can use SFINAE(Substitution Failure Is Not An Error) to enable or disable a function or class template based on a condition.

- `std::enable_if` is a way to enable or disable a function or class template based on a condition.

- **How `SFINAE` Works**

When the C++ compiler is instantiating templates, it tries to substitute the types provided by the user into the template's parameters. If a substitution causes an invalid type or expression, the compiler doesn't treat this as a fatal error. Instead, it simply discards that particular specialization and moves on to other possible specializations or overloads. This allows the programmer to create more flexible and robust templates.

```cpp

#include <type_traits>
#include <iostream>

// Function template for integral types
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
printType(T t) {
    std::cout << t << " is an integral type.\n";
}

// Function template for floating-point types
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
printType(T t) {
    std::cout << t << " is a floating-point type.\n";
}

int main() {
    printType(5);      // Calls the integral version
    printType(5.5);    // Calls the floating-point version
    // printType("test"); // Compilation error: no matching function
}
```

## `std::tuble`

- `std::tuple` is a way to store multiple data types in a single object.
- `std::tuple` is a way to return multiple values from a function.
- `std::tuple` like a list in python.

```cpp

#include <tuple>

int main() {
    std::tuple<int, double, std::string> t(1, 2.2, "Hello");
    std::cout << std::get<0>(t) << std::endl;
    std::cout << std::get<1>(t) << std::endl;
    std::cout << std::get<2>(t) << std::endl;

}

```

## `std::pair`

- `std::pair` is a way to store two data types in a single object.

```cpp

#include <utility>
int main() {
    std::pair<int, double> p(1, 2.2);
    std::cout << p.first << std::endl;
    std::cout << p.second << std::endl;
}

```

## `std::variant`

- `std::variant` is a way to store multiple data types in a single object.
- `std::variant` is a way to return multiple values from a function.
- `std::variant` is like a union in C.

```cpp
#include <variant>


int main() {
    std::variant<int, double, std::string> v;
    v = 1;
    std::cout << std::get<int>(v) << std::endl;
    v = 2.2;
    std::cout << std::get<double>(v) << std::endl;
    v = "Hello";
    std::cout << std::get<std::string>(v) << std::endl;
}

```

# Searching Tasks

## Final Classifier

- It is keyword that is used to specify that a method in base class cannot be overridden.
- Must be Virtual.

```cpp

class Base {
public:
    virtual void foo() final {
        std::cout << "Base::foo" << std::endl;
    }
};

class Derived : public Base {
public:
//wrong 
    void foo() {
        std::cout << "Derived::foo" << std::endl;
    }
};

```

- `Error: Cannot override final method.`

## std::bind

- `std::bind` is a way to bind arguments to a function.
- `std::bind` is a way to create a function object.
- `std::bind` is a way to create a function object with placeholders.

```cpp

#include <functional>

void foo(int a, int b) {
    std::cout << a << " " << b << std::endl;
}

int main() {
    auto f = std::bind(foo, 1, 2);
    f();
}

```

```cpp
#include <functional>

class A{
public:
    void foo(int a, int b) {
        std::cout << a << " " << b << std::endl;
    }
};

int main() {
    A a;
    auto f = std::bind(&A::foo, &a, std::placeholders::_1, std::placeholders::_2);
    f(1, 2);
}

```

```cpp
#include <functional>

int multiply(int a, int b) {
    return a * b;
}

// dont do this
int multiplyByTwo(int a) {
    return a * 2;
}

int main() {
    // do this
    auto f = std::bind(multiply, std::placeholders::_1, 2);
    std::cout << f(3) << std::endl;

}

```

## template hpp

- A `template.hpp` file is not a standard or specific term in C++, but it typically refers to a header file (.hpp) that contains template definitions. In C++, template classes and functions are usually defined in header files because of how template instantiation works.

### Why use template.hpp?

1. **Template Instantiation**: When you use a template class or function in your code, the compiler needs to know the template definition to instantiate it for the specific data types you're using. If the template definition is in a separate .cpp file, the compiler won't be able to instantiate it correctly.

2. **Separation of Concerns**: By defining templates in a separate header file, you can keep the template definition separate from the implementation details. This can make your code more modular and easier to maintain.

### How to use template.hpp?

#### MyClass.hpp

```cpp

#ifndef MYCLASS_HPP
#define MYCLASS_HPP

template <typename T>
class MyClass {
private:
    T data;

public:

    MyClass(T data);

    T getData();
};

#include "MyClass.template.hpp"

#endif
```

#### MyClass.template.hpp

```cpp

template<typename T>
MyClass<T>::MyClass(T value) : value(value) {}

template<typename T>
T MyClass<T>::getValue() const {
    return value;
}
```

#### main.cpp

```cpp


#include "MyClass.hpp"

int main() {
    MyClass<int> myClass(42);
    std::cout << myClass.getValue() << std::endl;
    return 0;
}
```

## StringStream



