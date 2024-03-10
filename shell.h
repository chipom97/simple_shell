#ifndef SHELL_H
#define SHELL_H

/* Standard C library headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Function prototypes */
extern char **environ;
void run_shell(void);
void tokenize_input(char *line, char **args);
void handle_builtin(char **args);
void create_child_process(char **args);
void initialize_shell(void);
void handle_ls_command(char **args);
void execute_command(char **args);

#endif /* SHELL_H */
