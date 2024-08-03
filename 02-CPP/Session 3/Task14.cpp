#include <iostream>
#include <vector>

bool anyEven(const std::vector<int> & arr){
    for(auto i : arr){
        if(i % 2 == 0){
            return true;
        }
    }
    return false;
}


int main(){
    std::vector<int> arr = {1, 3, 5, 7, 9};
    std::vector<int> arr2= {1, 3, 5, 7, 10};
    std::cout << std::boolalpha << anyEven(arr) << std::endl;
    std::cout << std::boolalpha << anyEven(arr2) << std::endl;
    return 0;
}