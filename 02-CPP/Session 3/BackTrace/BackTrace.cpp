#include "BackTrace.hpp"
#include <iostream>
#include <stack>
#include <vector>

// Define the static member variable
std::stack<std::string> backTrace::Trace;

/**
 * @brief Adds the function name to the stack trace and logs the entry.
 * 
 * @param funName The name of the function to add to the stack trace.
 */
void backTrace::Enter(const std::string& funName) {
    Trace.push(funName);
    std::cout << "Enter: " << funName << std::endl;
}

/**
 * @brief Removes the top function name from the stack trace and logs the exit.
 */
void backTrace::Exit() {
    if (!Trace.empty()) {
        std::cout << "Exit: " << Trace.top() << std::endl;
        Trace.pop();
    }
}

/**
 * @brief Prints the current stack trace from the first function entered to the last.
 */
void backTrace::PrintBackTrace() {
    std::stack<std::string> temp = Trace;
    std::vector<std::string> vector_Trace;
    int count = 0;

    std::cout << "BackTrace As Follows:" << std::endl;

    // Move elements from stack to vector to maintain order
    while (!temp.empty()) {
        vector_Trace.push_back(temp.top());
        temp.pop();
    }

    // Print elements from the vector in the original order
    for (auto it = vector_Trace.rbegin(); it != vector_Trace.rend(); ++it) {
        std::cout << count << "-" << *it << std::endl;
        ++count;
    }
}
