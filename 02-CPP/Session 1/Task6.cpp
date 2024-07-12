#include <iostream>
#include <string>

int main(int argc, const char** argv) {


    int num=0;
    std::string num_str;
    int sum=0;

    std::cin>>num;
    num_str=std::to_string(num);
    for(auto i : num_str){
        sum+=i-'0';
    }
    std::cout<<sum;
    return 0;
}