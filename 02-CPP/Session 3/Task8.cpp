#include <iostream>


template <typename T,size_t N>
T linear_search(T (&arr)[N],T target){
    
    for(T counter = 0; counter<N; counter++){
        std::cout<<counter<<std::endl;
        if(arr[counter]==target){
            return counter;
        }
    }
    return -1;

}
int main(){
    int arr[]= {10,20,30 ,50,9,1};
    std::cout<<linear_search(arr,20);
}