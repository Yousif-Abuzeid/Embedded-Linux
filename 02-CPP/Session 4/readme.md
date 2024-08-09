# OOP Part 2

## Operator Overloading

- Operator overloading is a feature in C++ that allows us to redefine the way operators work with user-defined types.

- Operator overloading is achieved by defining a function that is called when the operator is used with the user-defined type.

- Operator overloading is useful for creating more intuitive and readable code.

### Syntax

```cpp

return_type operator op (parameters) {
    // code
}

```

### Example

```cpp

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    os << "[";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
```

### Postfix and Prefix Increment Operator

- The postfix increment operator (++) increments the value of the variable and returns the original value.

- The prefix increment operator (++var) increments the value of the variable and returns the new value.
```cpp

#include <iostream>

class Counter {
private:
    int count;
public:
    Counter() : count(0) {}
    int operator++() {
        return ++count;
    }
    int operator++(int) {
        return count++;
    }
    void display() {
        std::cout << "Count: " << count << std::endl;
    }
};

int main() {
    Counter c;
    c.display(); // Count: 0
    c++;
    c.display(); // Count: 1
    ++c;
    c.display(); // Count: 3
    return 0;
}
```


## Functor 

- A functor is an object that can be called as if it were a function.

- Functors are useful for creating objects that can be used in algorithms that require a function object.

- Functors are often used in conjunction with the standard library algorithms.

- Functors are also known as function objects.

### Example

```cpp
#include <iostream>

class Add {
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

int main() {
    Add add;
    std::cout << add(3, 4) << std::endl; // 7
    return 0;
}
```
### Another Example

```cpp

#include <iostream>

class GreaterThan {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    GreaterThan greater_than;
    std::cout << greater_than(3, 4) << std::endl; // 0
    std::cout << greater_than(4, 3) << std::endl; // 1
    return 0;
}
```

### Example with Standard Library

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class GreaterThan {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    GreaterThan greater_than;
    std::sort(vec.begin(), vec.end(), greater_than);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

### Advantages of Functors

- Functors can have state, which allows them to maintain information between calls.

- Functors can be used in algorithms that require a function object.

- Functors can be used to create objects that behave like functions.

### Disadvantages of Functors

- Functors can be more complex than regular functions.

- Functors can be harder to understand and maintain.

- Functors can be harder to use in some situations.

## Conversion

- Conversion operators are used to convert an object of one type to another type.

- Conversion operators are defined as member functions of a class.

### Syntax

```cpp
operator type() {
    // code
}
```

### Example

```cpp

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int n, int d) : numerator(n), denominator(d) {}
    operator double() {
        return static_cast<double>(numerator) / denominator;
    }
};

int main() {
    Fraction f(3, 4);
    double d = f;
    std::cout << d << std::endl; // 0.75
    return 0;
}
```

## Friend Operator

- The friend keyword is used to declare a function or a class as a friend of another class.

- A friend function can access the private and protected members of the class in which it is declared as a friend.

### Example

```cpp

#include <iostream>

class A {
private:
    int x;
public:
    A(int x) : x(x) {}
    friend void display(A a);
};

void display(A a) {
    std::cout << a.x << std::endl;
}

int main() {
    A a(10);
    display(a); // 10
    return 0;
}
```
## Explicit

- The explicit keyword is used to prevent implicit conversions of constructor functions.

### Example

```cpp
class complex{
    private:
        int real;
        int imag;
    public:
        explicit complex(int r = 0, int i = 0){
            real = r;
            imag = i;
        }
};

int main(){
    complex c1(10, 20); // OK
    complex c2 = complex(10); // OK
    complex c3 = 30; // Error
    return 0;
}

```
### Explicit With Operator


```cpp
class complex{
    private:
        int real;
        int imag;
    public:
        explicit complex(int r = 0, int i = 0){
            real = r;
            imag = i;
        }
        explicit operator int(){
            return real;
        }
};

int main(){
    complex c1(10, 20); // OK
    int x = c1; // Error
    int y = static_cast<int>(c1); // OK

    return 0;
}

```



## Copy Constructor

- A copy constructor is a member function which initializes an object using another object of the same class.
- A copy constructor has the following general function prototype:

```cpp
ClassName (const ClassName &old_obj);
```

### Rules for copy constructor

- Must be passed by reference to avoid infinite loop.
```cpp
ClassName (ClassName old_obj); // Wrong


int main() {
    ClassName obj1;
    ClassName obj2 = obj1; // Copy constructor called 
    // ClassName(old_obj = obj1) Calls Copy constructor
    // Thus an infinite loop
}
```

- Must be const to avoid modification of old object Also For Handling Temporary Objects.

```cpp
ClassName (const ClassName &old_obj); // Correct
```
### Tracing Example (NO ELide Optimization)

```cpp
#include <iostream>

class string{
    private:
        char *s;
        int size;
    public:
    string(){
        std::cout << "Default Constructor Called" << std::endl;
    }
    string(const string &old_obj){
        std::cout << "Copy Constructor Called" << std::endl;
        size = old_obj.size;
        s = new char[size+1];
        for(int i = 0; i < size; i++){
            s[i] = old_obj.s[i];
        }
        s[size] = '\0';
    }
    ~string(){
        std::cout << "Destructor Called" << std::endl;
        delete [] s;
    }


}

    string get_instance(){
        string temp; // Default Constructor Called 1
        return temp; // Copy Constructor Called 2
        // Destructor Called 3
    }

int main(){
    string t2(get_instance()); // copy constructor called 4
    // Destructor Called 5
    // Destructor Called 6
    return 0;
}
```
### Tracing Example (ELide Optimization)

```cpp
#include <iostream>

class string{
    private:
        char *s;
        int size;
    public:
    string(){
        std::cout << "Default Constructor Called" << std::endl;
    }
    string(const string &old_obj){
        std::cout << "Copy Constructor Called" << std::endl;
        size = old_obj.size;
        s = new char[size+1];
        for(int i = 0; i < size; i++){
            s[i] = old_obj.s[i];
        }
        s[size] = '\0';
    }
    ~string(){
        std::cout << "Destructor Called" << std::endl;
        delete [] s;
    }

    string get_instance(){
        string temp; // Default Constructor Called 1
        return temp; 
    }

int main(){
    string t2(get_instance()); 
    return 0;
    // Destructor Called 2

}
```
### Elide Optimization

- Elide optimization is a compiler optimization technique that eliminates unnecessary copying of objects.

- In the above example, the copy constructor is called twice. Once when the temporary object is created and once when the temporary object is returned.

- In the case of elide optimization, the compiler eliminates the copy constructor calls and directly constructs the object in the memory location of the object being returned.

- This optimization is done by the compiler and is not guaranteed to happen. It depends on the compiler and the optimization level used.

- The copy constructor is called only once in the case of elide optimization.

### When is the copy constructor called?

- When an object is passed by value as an argument to a function.

- When an object is returned by value from a function.

- When an object is constructed based on another object of the same class.

- When an object is initialized using another object of the same class.

### When is the copy constructor not called?

- When an object is passed by reference as an argument to a function.

- When an object is returned by reference from a function.

- When an object is constructed based on another object of a different class.

- When an object is initialized using a value of the same type as the object.

### Shallow Copy and Deep Copy

- Shallow Copy: In shallow copy, the data members of the new object are copied from the old object as it is. If the data members are pointers, then the address is copied, not the data itself.

- Deep Copy: In deep copy, the data members of the new object are copied from the old object, and if the data members are pointers, then the data itself is copied.

### Example of Shallow Copy

```cpp
#include <iostream>

class string{
    private:   
    public:
    string(const string &old_obj){
        std::cout << "Copy Constructor Called" << std::endl;
        size = old_obj.size;
        s = old_obj.s;
    }
};

```

### Example of Deep Copy

```cpp
#include <iostream>

class string{
    private:
    public:
    string(const string &old_obj){
        std::cout << "Copy Constructor Called" << std::endl;
        size = old_obj.size;
        s = new char[size+1]; // memory leakage 
        strcpy(s, old_obj.s);
    }
};
```

### Rule of Three

- If a class defines one of the following functions, it should probably explicitly define all three:

- Destructor
- Copy Constructor
- Copy Assignment Operator

### RAII (Resource Acquisition Is Initialization)

- RAII is a programming idiom used in C++ to manage resources safely. The idea is to tie the life cycle of a resource to the object's life cycle.

- The resource is acquired in the constructor and released in the destructor.

- This ensures that the resource is released when the object goes out of scope, even in the presence of exceptions.

### Rule of Five

- The rule of five is an extension of the rule of three. It states that if a class defines one of the following functions, it should probably explicitly define all five:

- Destructor

- Copy Constructor

- Copy Assignment Operator

- Move Constructor

- Move Assignment Operator

### Move Constructor

- A move constructor is a special member function that is used to move the resources owned by an rvalue to a new object.

- A move constructor has the following general function prototype:

```cpp
ClassName (ClassName &&old_obj);
```

- The move constructor is called when an rvalue is passed to a function or returned from a function.

- The move constructor is used to transfer the resources owned by the rvalue to the new object, rather than copying them.



### Rule of Zero

- The rule of zero states that if a class does not need to manage resources, it should not define any of the following functions:

- Destructor

- Copy Constructor

- Copy Assignment Operator

- Move Constructor

- Move Assignment Operator

- This is because the default implementations provided by the compiler are sufficient for such classes.



## Value Categories

### Lvalue

- Named by programmer
- Lvalue initialized by Rvalue / Lvalue
- `has its ownership`

`Ownership : Has a memory address and responsible for the memory management.`
- `Lvalue = name + address`
```cpp
int &fun(){
    static int x = 10;
    return x;
}
int fun2({
    static int m = 20;
})
fun() = 30; // x = 30
fun2()/* Rvalue*/ = 40; // Error lvalue required as left operand of assignment  
int a =fun(); // a = 30
int x = 10; // x is Lvalue
int y = x; // x is Lvalue
int z = x + y; // x and y are Lvalue

x/*Lvalue*/ = 5/*(Rvalue)*/ = 10;//(Rvalue);

(x+1 /*(Rvalue)*/) = 6; // Error lvalue required as left operand of assignment

&x=6; // Error lvalue required as left operand of assignment
```
### Rvalue

- Programmer Never Has The chance to name it
- Never Initialized, it is value by itself
- `Does not have its ownership`
- `Temporary Object`
- `3,4,5,'a','true "Hello World" are Rvalues`
- `Temporary + no Name`


### Xvalue

- eXpiring value
- `Identity + Moved`
```cpp


int main(){

    std::string name ="Youssef";
    std::string name2 = std::move(name);

    std::cout << name << std::endl; // Xvalue
    std::cout << name2 << std::endl; // Youssef
}
```