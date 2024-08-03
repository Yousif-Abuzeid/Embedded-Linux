#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

#include <stack>
#include <string>

/// Macro to be placed at the beginning of a function to add it to the backtrace
#define ENTER_FUNCTION backTrace::Enter(__FUNCTION__)
/// Macro to be placed at the end of a function to remove it from the backtrace
#define EXIT_FUNCTION  backTrace::Exit()
/// Macro to print the current backtrace
#define PRINT_BT       backTrace::PrintBackTrace()

/**
 * @class backTrace
 * @brief A class to manage a stack trace for debugging purposes.
 */
class backTrace {

private:
    static std::stack<std::string> Trace; ///< Stack to store function names

public:
    /**
     * @brief Enters a function by adding its name to the trace stack.
     * @param funName The name of the function to add to the trace stack.
     */
    static void Enter(const std::string& funName);

    /**
     * @brief Exits a function by removing its name from the trace stack.
     */
    static void Exit();

    /**
     * @brief Prints the current backtrace.
     */
    static void PrintBackTrace();
};

#endif // BACKTRACE_HPP
