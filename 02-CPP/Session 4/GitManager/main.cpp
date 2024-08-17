#include "GitManager.hpp"
#include <iostream>
#include <string>


void mainLoop(){
    std::string command;
    while(command!="exit"){
        std::cout<<"Enter Command: ";
        std::getline(std::cin,command);
        if(command=="add"){
            GitManager git;
            git.add();
        }
        else if(command=="commit"){
            GitManager git;
            git.commit();
        }
        else if(command=="push"){
            GitManager git;
            git.push();
        }
        else if(command=="pull"){
            GitManager git;
            git.pull();
        }
        else if(command=="clone"){
            GitManager git;
            git.clone();
        }
        else if(command=="status"){
            GitManager git;
            git.status();
        }
        else if(command=="log"){
            GitManager git;
            git.log();
        }
        else if(command=="exit"){
            break;
        }
        else{
            std::cout<<"Invalid Command"<<std::endl;
        }
    }
}

int main(){
    GitManager git;
    mainLoop();
}