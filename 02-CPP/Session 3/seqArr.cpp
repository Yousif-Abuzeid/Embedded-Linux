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

int main(){
    auto arr = seqArr(1, 10, 1);
    for(auto i : arr){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}