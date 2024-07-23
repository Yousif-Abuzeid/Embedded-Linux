#include <iostream>
#include <functional>

std::function<int(int)> square = [](int x){
    return x*x;
};

int main(){
    int x=5;
    std::cout<<square(x);
}