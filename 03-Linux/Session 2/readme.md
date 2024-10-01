# Fork in linux

## Fork

- Fork is a system call that is used for creating a new process, which is called child process, which runs concurrently with the process that makes the fork() call (parent process).

- After a new child process is created, both processes will execute the next instruction following the fork() system call.

- A child process uses the same program counter as the parent process and shares all the data, such as the memory, file descriptors, and so on, with the parent process.

- A child process can be created using fork() system call as follows:


## execve

- The execve() system call is used after a fork() to replace the current running process with a new process.

- The execve() system call loads a new program into the current process space, replacing the current program with a new one.

- The execve() system call is used to execute a program which is referred to by a file descriptor.


