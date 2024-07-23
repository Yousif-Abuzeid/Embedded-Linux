#include <iostream>


template <typename T, size_t N>
T return_max(T (&arr)[N]){
    T max = arr[0];
    for(T current :arr){
        if (current>max){
            max=current;
        }
    }
    return max;
}

int main() {
    int arr[]={5,10,20,40,70};
    std::cout<<return_max(arr);
    return 0;
}