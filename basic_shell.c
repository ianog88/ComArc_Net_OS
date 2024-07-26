#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 128

void parse_command(char* line, char** argv) {
    while (*line != '\0') {       
        while (*line == ' ' || *line == '\t' || *line == '\n') {
            *line++ = '\0';       
        }
        *argv++ = line;           
        while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n') {
            line++;               
        }
    }
    *argv = '\0';                 
}

void execute_command(char** argv) {
    pid_t pid;
    int status;
    
    if ((pid = fork()) < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        if (execvp(*argv, argv) < 0) {  
            perror("Exec failed");
            exit(1);
        }
    } else {
        while (wait(&status) != pid);   
    }
}

void handle_redirection(char** argv) {
    int i = 0;
    int fd;

    while (argv[i] != NULL) {
        if (strcmp(argv[i], ">") == 0) {
            argv[i] = NULL;
            if ((fd = open(argv[i+1], O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0) {
                perror("File open failed");
                exit(1);
            }
            dup2(fd, STDOUT_FILENO);  
            close(fd);
        } else if (strcmp(argv[i], "<") == 0) {
            argv[i] = NULL;
            if ((fd = open(argv[i+1], O_RDONLY)) < 0) {
                perror("File open failed");
                exit(1);
            }
            dup2(fd, STDIN_FILENO);  
            close(fd);
        }
        i++;
    }
}

void execute_piped_commands(char** argv1, char** argv2) {
    int fd[2];
    pid_t pid1, pid2;

    if (pipe(fd) < 0) {
        perror("Pipe failed");
        exit(1);
    }

    if ((pid1 = fork()) < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid1 == 0) {
        dup2(fd[1], STDOUT_FILENO); 
        close(fd[0]);
        close(fd[1]);
        execvp(argv1[0], argv1);
        perror("Exec failed");
        exit(1);
    }

    if ((pid2 = fork()) < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid2 == 0) {
        dup2(fd[0], STDIN_FILENO); 
        close(fd[0]);
        close(fd[1]);
        execvp(argv2[0], argv2);
        perror("Exec failed");
        exit(1);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

int main() {
    char line[MAX_LINE];
    char* argv[MAX_ARGS];
    char* argv1[MAX_ARGS];
    char* argv2[MAX_ARGS];
    
    while (1) {
        printf("myshell> ");
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            perror("fgets failed");
            exit(1);
        }
        
        line[strcspn(line, "\n")] = '\0'; 

        if (strstr(line, "|")) {
            char* cmd1 = strtok(line, "|");
            char* cmd2 = strtok(NULL, "|");
            parse_command(cmd1, argv1);
            parse_command(cmd2, argv2);
            execute_piped_commands(argv1, argv2);
        } else {
            parse_command(line, argv);
            handle_redirection(argv);
            execute_command(argv);
        }
    }

    return 0;
}
