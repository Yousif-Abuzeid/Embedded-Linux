#include <iostream>
#include <functional>


int main(){
    int *ptrWithNullPtr=nullptr;
    int *ptrWithNull=NULL;
    int x=100;

    std::cout<<"Null Pointer :"<<ptrWithNullPtr<<"\n";
    std::cout<<"Null :"<<ptrWithNull<<"\n";
    std::function<int(int)>pf = [x](int y){
        return x+y;
    };
    std::cout << pf(5) << std::endl;
    return 0;
}