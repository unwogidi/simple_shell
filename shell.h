#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void display_prompt(void);
void read_input(char *input);
void execute_command(char **argv);
void handle_error(char *message);
void parse_input(char *input, char **argv);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
unsigned int _strcspn(char *s, char *reject);

#endif /* SHELL_H */
