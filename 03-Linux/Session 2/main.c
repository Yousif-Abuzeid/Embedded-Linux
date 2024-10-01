#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid = fork();
    const char *cmd = "/usr/bin/sleep";
    char *args[] = {cmd, "10", NULL};
    char *env[] = {NULL};   
    // [a.out1,a.out2]
    if(pid<0){
        printf("Fork failed\n");
        exit(-1);
    }else if (pid == 0){
       // printf("Child process\n");
       // printf("Child PID: %d\n", getpid());
       // printf("Parent PID: %d\n", getppid());
        execve(cmd, args, env);
       // When this line will be called 
       // -- line 
       // (if execve fails)
        perror("Execve failed"); //[a.out2 is giving control to cmd]
        exit(-1); // exit the child process
        //sleep(5);
    }else{
        printf("Parent process\n");
        printf("Process PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        int status;
        waitpid(pid, &status, 0);
        printf("Child process exited with status: %d\n", status);
    }
}

/*
    BASH ID -> Parent of parent process
    Parent ID -> Parent process
    Child ID -> Child process

 */