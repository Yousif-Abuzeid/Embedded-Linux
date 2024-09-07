# Introduction
## C++ 
- is an extension of the C programming language
- Object-Oriented language
- statically-typed language
- we will work with C++14 and C++17 in this course 
- c++ is the same as c in basic data types 

## C basic data types 
- integer: signed/unsigned & int/short int/long int
- floating point: float/double/long double
- character: char/signed char/unsigned char
- the size of any data type is directly dependent on the compiler along with the target processor


```c
unsigned char x = -1;
printf("%d",x);
```
- this outputs 255 as -1 is full ones and in unsigned char that represents 255


```c
char x = 255;
printf("%d",x);
```
- this outputs -1 as char is signed by defualt so 255 "ful ones" represents -1

```c
char x = 128;
printf("%d",x);
```
- this outputs -128 as char is signed by defualt and 128 represents -128

```c
char x = 258;
printf("%d",x);
```
- this outputs -2 as char is stored in one byte and 258 binary representation is 100000010 so the MSB is ignored and 00000010 is left which is 2


## c++ input & output

```cpp
#include <iostream>
int main()
{
    int x;
    std::cin>>x;
    std::cout<<x<<"\n";
    return 0;
}
```

## c++ manipulators 
- check cpprefrence.com::input/output manipulators 
- focus on the manipulators of diffrent number bases
- rembeber to reset the manipulator as you finish using it
- example on manipulators:
```cpp
#include <iostream>
#include <iomanip>

int main() {
    int num = 255;
    std::cout << std::hex << num << std::endl; // Outputs in hexadecimal
    std::cout << std::dec << num << std::endl; // Outputs in decimal
    return 0;
}
```


## C++ memory sections same as C

## C++ operators same as C

## C++ conditional statements same as C

## C++ loops same as C except ranged based loop
```cpp
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 535};
    for (int num : numbers) 
    {
        std::cout<<num<<"\n";
    }
    return 0;
}
```

