#ifndef  BACKTRACE_HPP

#define  BACKTRACE_HPP
#include <stack>
#include <string>


#define ENTER_FUNCTION backTrace::Enter (__FUNCTION__)
#define EXIT_FUNCTION  backTrace::Exit() 
#define PRINT_BT       backTrace::PrintBackTrace()

class backTrace{

    private:
      static  std::stack<std::string> Trace;
    public:
      static  void Enter(const std::string& funName);
            
        static void Exit();
        static void PrintBackTrace();

};

#endif  //BACKTRACE_HPP

