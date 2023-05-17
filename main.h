#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void infinite_loop(void);
char *get_string(void);
char **split(char *string);
void execution(char **arguments);

#endif
