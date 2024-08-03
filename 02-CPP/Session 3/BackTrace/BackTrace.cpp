#include "BackTrace.hpp"
#include <iostream>
#include <stack>
#include <vector>

std::stack<std::string> backTrace::Trace;

void backTrace::Enter(const std::string& funName){
            Trace.push(funName);
            std::cout<<"Enter :"<<funName<<std::endl;
        }
void backTrace::Exit(){
            std::cout<<"Exit :"<<Trace.top()<<std::endl;
            Trace.pop();
        }
void backTrace::PrintBackTrace(){
            std::stack<std::string> temp=Trace;
            std::vector<std::string> vector_Trace;
            int count =0;
            std::cout<<"BackTrace As Follows:"<<std::endl;
            while (!temp.empty()) {
                vector_Trace.push_back(temp.top());
                temp.pop();
            }
            for(auto it = vector_Trace.rbegin(); it!=vector_Trace.rend(); it++){
                std::cout<<count<<"-"<<*it<<std::endl;
            }
}