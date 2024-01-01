#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Function prototypes */
int strncasecmp(const char *s1, const char *s2, size_t n);
void display_prompt(void);
char *read_command(void);

#endif /* SHELL_H */
