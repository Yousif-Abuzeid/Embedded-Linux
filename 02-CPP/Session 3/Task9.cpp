#include <iostream>


template <typename T,size_t N>
void delete_num(T (&arr)[N],T target){
    bool found = false;
    int index;
    for ( index = 0; index<N; index++){
        if(arr[index]==target){
            found = true;
            break;
        }
        
    }
    if(!found){
        std::cout<<"the number does'nt exist"<<std::endl;
        return ;
    }
    for(int counter=index; counter<N; counter++){
        arr[counter]=arr[counter+1];
    }
    arr[N - 1] = T(); 
}
template <typename T,size_t N>
void print_arr(T (&arr)[N]){
    for(T current:arr){
        std::cout<<current<<" ";
    }
    std::cout<<std::endl;
}




int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    print_arr(arr);
    delete_num(arr,5);
    print_arr(arr);
}