#include <iostream>


template <typename T,size_t N1,size_t N2>
T* merge_two_arr(T (&arr1)[N1],T (&arr2)[N2]){
    
    T *merged_arr = new T[N1+N2];
    for(int index=0; index<N1; index++){
        merged_arr[index]=arr1[index];
    }
    for(int index=0; index<N2; index++){
        merged_arr[index+N1]=arr2[index];
    }
    return merged_arr;
    


}

template <typename T>
void print_arr(const T* arr, size_t size) {
    for (size_t index = 0; index < size; ++index) {
        std::cout << arr[index] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int arr1[]={1,2,3,4,5,6,7};
    int arr2[]={9,10,11,12};
    auto new_arr=merge_two_arr(arr1,arr2);

    print_arr(new_arr,11);
    delete[] new_arr;
}