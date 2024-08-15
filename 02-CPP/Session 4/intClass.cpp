#include "intClass.hpp"
#include <iostream>
#include <ostream>

/*
Default Constructor
*/
myInt::myInt() :number(0) {

}
/*
Copy Constructor
*/
myInt::myInt(const myInt& obj):number(obj.number) {
 std::cout<<"Copy Constructor Called"<<std::endl;   
}
/*
Can Work as a parametrized constructor or a copy constructor
*/
myInt::myInt(const int& obj):number(obj){
    std::cout<<"Initalized with Int"<<std::endl;
}
/*
Move constructor is useless here
*/
// myInt::myInt(myInt&& obj){}
// myInt::myInt(int&& obj){}
/*
Plus Operator
*/
myInt myInt:: operator+(const myInt& obj){
    return this->number+obj.number;
}
/*
Greater Than Operator
*/
bool myInt::operator>(const myInt& obj){
    return this->number>obj.number;
}
/*
Less Than Operator
*/
bool myInt::operator<(const myInt&obj){
    return this->number<obj.number;
}
/*
is equal operator
*/
bool myInt::operator==(const myInt&obj){
    return this->number==obj.number;
}
/*
PreFix
*/
myInt& myInt:: operator++(){
    this->number++;
    return *this;
}
  /*
    Assignment Operator
    */
    myInt& myInt:: operator=(const myInt& obj){
        if(this!=&obj){
            this->number=obj.number;
        }
        return *this;
    }
/*
Postfix
*/

myInt myInt:: operator++(int){
    myInt temp = *this;
    this->number++;
    return temp;
}

std::ostream& operator<<(std::ostream& os , const myInt& obj){
    os<<obj.number;
    return os;
}
