#include <ios>
#include <iostream>
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}



int main() {
    char c;
    std::cin >> c;
    std::cout <<std::boolalpha<< isDigit(c) << std::endl;
    return 0;
}