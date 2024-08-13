# inheritence

- Inheritence is a mechanism in which one class acquires the properties and behavior of another class.
- The class that inherits the properties of another class is called the derived class or child class.
- The class whose properties are inherited is called the base class or parent class.

## In inheritance we should follow the rule of "is a" relationship

### `if we have a class vehicle.`

- we cas say that a car is a vehicle.
- we can say that a truck is a vehicle.
- we can say that a BMW is a car which is a vehicle.

```cpp

#include <iostream>


class Base
{
public:
    Base()
    {
        std::cout << "Base Constructor" << std::endl;
    }
    void display()
    {
        std::cout << "Display of Base" << std::endl;
    }
    ~Base()
    {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived Constructor" << std::endl;
    }
    ~Derived()
    {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main (){
    Derived d;
    d.display();
    return 0;

    /****
    Output:
    1-Base Constructor
    2-Derived Constructor
    3-Display of Base
    4-Derived Destructor
    5-Base Destructor
    *****/
}

```

- In the above example, we have a base class `Base` and a derived class `Derived`.

- The derived class `Derived` is inheriting the properties of the base class `Base` using the `public` keyword, so the public members of the base class `Base` will become the public members of the derived class `Derived`.

- The constructor of the base class `Base` is called first, then the constructor of the derived class `Derived` is called.

- The destructor of the derived class `Derived` is called first, then the destructor of the base class `Base` is called.

## Types of Inheritance

![Inheritance](TypesOfInheritence.png)

- Single Inheritance
- Multiple Inheritance
- Multilevel Inheritance
- Hierarchical Inheritance
- Hybrid Inheritance

### `Single Inheritance`

- In single inheritance, a class is allowed to inherit from only one class. `JUST LIKE THE EXAMPLE ABOVE.`

### `Multilevel Inheritance`

- In multilevel inheritance, a class is derived from another derived class.
    
    ```cpp
    class A
    {
    public:
        A()
        {
            std::cout << "A Constructor" << std::endl;
        }
        void display()
        {
            std::cout << "Display of A" << std::endl;
        }
        ~A()
        {
            std::cout << "A Destructor" << std::endl;
        }
    };

    class B : public A
    {
    public:
        B()
        {
            std::cout << "B Constructor" << std::endl;
        }
        void show()
        {
            std::cout << "Show of B" << std::endl;
        }
        ~B()
        {
            std::cout << "B Destructor" << std::endl;
        }
    };

    class C : public B
    {
    public:
        C()
        {
            std::cout << "C Constructor" << std::endl;
        }
        void view()
        {
            std::cout << "View of C" << std::endl;
        }
        ~C()
        {
            std::cout << "C Destructor" << std::endl;
        }
    };

    int main()
    {
        C c;
        c.display();
        c.show();
        c.view();
        return 0;
    }
    /***
    Output:
    1-A Constructor
    2-B Constructor
    3-C Constructor
    4-Display of A
    5-Show of B
    6-View of C
    7-C Destructor
    8-B Destructor
    9-A Destructor
    ```

### `Hierarchical Inheritance`

- In hierarchical inheritance, more than one class is derived from a single base class.

    ```cpp
    class employee
    {
    public:
        employee()
        {
            std::cout << "Employee Constructor" << std::endl;
        }
        void display()
        {
            std::cout << "Display of Employee" << std::endl;
        }
        ~employee()
        {
            std::cout << "Employee Destructor" << std::endl;
        }
    };

    class manager : public employee
    {
    public:
        manager()
        {
            std::cout << "Manager Constructor" << std::endl;
        }
        void show()
        {
            std::cout << "Show of Manager" << std::endl;
        }
        ~manager()
        {
            std::cout << "Manager Destructor" << std::endl;
        }
    };

    class HR : public employee
    {
    public:
        HR()
        {
            std::cout << "HR Constructor" << std::endl;
        }
        void view()
        {
            std::cout << "View of HR" << std::endl;
        }
        ~HR()
        {
            std::cout << "HR Destructor" << std::endl;
        }
    };

    int main()
    {
        manager m;
       
        HR h;
       
        return 0;
    }
    /***
    Output:
    1-Employee Constructor
    2-Manager Constructor
    3-Employee Constructor
    4-HR Constructor
    5-HR Destructor
    6-Employee Destructor
    7-Manager Destructor
    8-Employee Destructor
 
    ```

### `Multiple Inheritance`

`Prohibited by Misra`

- In multiple inheritance, a class is derived from more than one class.

```cpp
class A
    {
        public:
        void fun(){
            std::cout<<"Fun A"<<std::endl;
        }
    };
    class B
    {
        public:
        void fun(){
            std::cout<<"Fun B"<<std::endl;
        }
    };
    class AB :public A, public B{

    };

    int main (){
        AB obj;
        
        obj.fun(); //ambigous call
        /* Can be Fixed Like This*/
        obj.A::fun();
        obj.B::fun();


    }

```

### `Hybrid Inheritance`

- Hybrid inheritance is a combination of multiple inheritance and multilevel inheritance.

```cpp
#include <iostream>
class A
{
    public: 
    int a;
public:
    void display()
    {
        std::cout << "Display of A" << std::endl;
    }
};

class B : virtual public A
{
public:
    
};

class C : virtual public A
{
public:
    
};

class D :  public B,  public C
{
public:
    
};

int main()
{
    D d;
    d.display();
    
    return 0;
}

```

- `Using the Virtual Keyword Resolved The Problem of Ambigous Call`
