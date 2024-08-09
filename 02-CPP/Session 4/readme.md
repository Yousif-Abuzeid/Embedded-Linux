# OOP Part 2

## Copy COnstructor

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
- "has its ownership"