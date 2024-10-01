#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

// Maximum command length
#define MAX_CMD_LEN 100 

// Maximum number of arguments
#define MAX_ARGS 10

// Maximum number of pipes
#define MAX_PIPES 10

// Maximum number of commands
#define MAX_CMDS 10


// Color codes
#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_BLUE "\033[34m"
#define COLOR_YELLOW "\033[33m"

// Function prototype

void simpleShell();


int main() {
    simpleShell();
    return 0;
}

void simpleShell() {
    // Command buffer
    char cmd[MAX_CMD_LEN];

    // Array of arguments for each command
    char *args[MAX_ARGS];

    // Array of pipes
    int pipes[MAX_PIPES][2];

    // Array of commands
    char *cmds[MAX_CMDS];

    // Number of commands
    int num_cmds;

    while (1) {
       // Get the current working directory
        char cwd[MAX_CMD_LEN];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // Print prompt with color and current directory
            printf( COLOR_BLUE"%s"COLOR_GREEN"<simpleShell>$ " COLOR_RESET, cwd);
        } else {
            perror("getcwd() error");
            continue;  // Skip to the next iteration if getcwd fails
        }

        // Read command from user
        if (fgets(cmd, MAX_CMD_LEN, stdin) == NULL) {
            printf("Error reading command\n");
            continue;
        }

        // Remove newline character from the command if present
        cmd[strcspn(cmd, "\n")] = 0;

        // Ignore empty commands
        if (cmd[0] == '\0') {
            continue;
        }

        // Parse commands (split by pipes '|')
        num_cmds = 0;
        cmds[num_cmds] = strtok(cmd, "|");
        while (cmds[num_cmds] != NULL) {
            num_cmds++;
            cmds[num_cmds] = strtok(NULL, "|");
        }

        // Loop over each command and create pipes if needed
        for (int i = 0; i < num_cmds; i++) {
            // Parse the individual command and its arguments (split by spaces)
            int num_args = 0;
            args[num_args] = strtok(cmds[i], " ");
            while (args[num_args] != NULL) {
                num_args++;
                args[num_args] = strtok(NULL, " ");
            }
            args[num_args] = NULL; // Null-terminate the argument list

            // If there's a pipe, set up the next pipe
            if (i < num_cmds - 1) {
                if (pipe(pipes[i]) == -1) {
                    perror("pipe");
                    exit(EXIT_FAILURE);
                }
            }

            // If the command is "cd"
        if (strcmp(args[0], "cd") == 0) {
            // If "cd" has no arguments, go to the home directory
            if (args[1] == NULL) {
                chdir(getenv("HOME"));
            } else {
                // Change the directory to the specified path
                
                if (chdir(args[1]) != 0) {
                    perror("cd"); // Print error if chdir fails
                }
            }
            continue;  // Skip the rest of the loop for "cd"
        }

            // Fork and execute the command
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                // Child process
                // If it's not the first command, get input from the previous pipe
                if (i > 0) {
                    dup2(pipes[i-1][0], STDIN_FILENO);
                    close(pipes[i-1][0]);
                    close(pipes[i-1][1]);
                }

                // If it's not the last command, send output to the next pipe
                if (i < num_cmds - 1) {
                    dup2(pipes[i][1], STDOUT_FILENO);
                    close(pipes[i][0]);
                    close(pipes[i][1]);
                }

                // Execute the command
                if (execvp(args[0], args) == -1) {
                    perror("execvp");
                    exit(EXIT_FAILURE);
                }
            } else {
                // Parent process

                // Close the previous pipe's read end in the parent
                if (i > 0) {
                    close(pipes[i-1][0]);
                    close(pipes[i-1][1]);
                }

                // Wait for the child process to finish
                wait(NULL);
            }
        }
    }
}
