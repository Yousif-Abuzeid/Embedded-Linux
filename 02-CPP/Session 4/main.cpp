#include "intClass.hpp"
#include <iostream>



int main(){
    
    int hamada= 10;
    myInt x(hamada);
    myInt y(10);
    ++x;
    x=x+y+20;
    std::cout<<x++<<std::endl;
    std::cout<<x<<std::endl;
}