#include <iostream>
#include <vector>


bool ArrEven(const std::vector<int> & arr){
    for(auto i : arr){
        if(i % 2 != 0){
            return false;
        }
    }
    return true;
}

int main(){
    std::vector<int> arr = {2, 4, 6, 8, 10};
    std::vector<int> arr2= {2, 4, 6, 8, 11};
    std::cout << std::boolalpha << ArrEven(arr) << std::endl;
    std::cout << std::boolalpha << ArrEven(arr2) << std::endl;
    return 0;
}