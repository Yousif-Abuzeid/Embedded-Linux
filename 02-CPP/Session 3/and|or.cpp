#include <iostream>
#include <vector>


int main(){
    int x= 10;
    if(x>20 and x>5){
        std::cout << "x is greater than 20 and greater than 5" << std::endl;
    }
    else{
        std::cout << "x is not greater than 20 and less than 5" << std::endl;
    }
    if(x>20 or x>5){
        std::cout << "x is greater than 20 or greater than 5" << std::endl;
    }
    else{
        std::cout << "x is not greater than 20 or less than 5" << std::endl;
    }
}