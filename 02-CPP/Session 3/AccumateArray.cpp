#include <iostream>
#include <vector>
#include <numeric>



std::ostream& operator<<(std::ostream& os, const std::vector<int>& arr){
    for(auto i : arr){
        os << i << " ";
    }
    return os;
}

int main(){
    std::vector<int> arr = {1, 2, 3, 4, 5};
    int sum =std::accumulate(arr.begin(), arr.end(), 0);
    std::cout << arr << std::endl;
    std::cout << "Sum of the array is: " << sum << std::endl;
}
