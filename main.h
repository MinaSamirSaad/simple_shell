#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/* global variable to access environment */
extern char **environ;

void infinite_loop(void);

/* function to read stander input */
/* and split arguments && execution the commands*/
void shell_process(char *string, char **arguments, char **paths, char *breaks);

/* checker helper functions*/
int check_full_path(char *argument);
char *check_small_path(char *argument, char **path);

/* string helper functions*/
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strconcat(char *str1, char *str2);
char *_strcopy(char *str);
char *get_string(void);

/* string helper functions 2*/
char **split(char *string, char *breaks);
int _atoi(char *s);

/* environment helper functions*/
char **get_all_paths(void);
char *get_env(char *string);

/*execution functions*/
void before_execution(char **arguments, char **paths);
void execution(char **arguments);

/* array helper functions*/
char **copy_array_of_strings(char **str);
void free_array_of_pointers(char **array);

/* built in checker */
void check_exit(char **arguments, char *string, char **paths);

/*free helper functions */
void free_all(char **arguments, char *string, char **paths);

#endif
