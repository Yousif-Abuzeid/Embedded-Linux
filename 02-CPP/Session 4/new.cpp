#include <cstdlib>
#include <iostream>
#include <filesystem>



int main(){
    std::system("git add new.cpp");
    std::system("git commit -m \"Added new.cpp\"");
    std::system("git push");
}