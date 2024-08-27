#include <iostream>
#include <csignal>
#include <cstdlib>
#include <thread>

// Signal handler function
void handleSignal(int signal) {
    std::cout << "Interrupt signal (" << signal << ") received. Exiting gracefully..." << std::endl;
    std::exit(signal); // Exit the program
}

int main() {
    // Register the signal handler for SIGINT
    std::signal(SIGINT, handleSignal);

    // Main loop
    std::cout << "Running. Press Ctrl+C to stop..." << std::endl;
    while (true) {
        // Busy wait to keep the program running
        // In a real application, this would be replaced with meaningful work
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
