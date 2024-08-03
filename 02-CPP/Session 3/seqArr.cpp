#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>


template <typename T>
std::vector<T> seqArr(T start, T end, T step){
    std::vector<T> arr(((end - start) / (step))+1);
    std::generate(arr.begin(), arr.end(), [&n = start, step]()  { 
        int temp = n;
        n += step; 
        return temp;});
    return arr;
}
std:: ostream& operator<<(std::ostream& os, const std::vector<int>& arr){
    for(auto i : arr){
        os << i << " ";
    }
    return os;
}
int main(){
    std::vector<int> arr = seqArr(1, 10, 1);
    
    std::cout <<arr<< std::endl;
    return 0;
}