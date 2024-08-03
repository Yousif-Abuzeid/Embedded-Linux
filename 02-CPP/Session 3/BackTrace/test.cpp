#include "BackTrace.hpp"


void fun3(){
    ENTER_FUNCTION;
    PRINT_BT;
    EXIT_FUNCTION;
}
void fun2(){
    ENTER_FUNCTION;
    fun3();
    EXIT_FUNCTION;
}
void fun1(){
    ENTER_FUNCTION;
    fun2();
    EXIT_FUNCTION;
}


int main(){
    fun1();
}
