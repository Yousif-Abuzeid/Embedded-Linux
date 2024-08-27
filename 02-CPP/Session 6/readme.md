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

```

### std::weak_ptr

