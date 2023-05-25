#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
/* global variable to access environment */

extern char **environ;


int infinite_loop(char *program_path);

/* function to read stander input */
/* and split arguments && execution the commands*/
int sh(char *str, char **args, char **paths, int p_cnt, char *p_path);

/* checker helper functions*/
int check_full_path(char *argument);
char *check_small_path(char *argument, char **path);

/* string helper functions*/
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strconcat(char *str1, char *str2);
char *_strcopy(char *str);

/* string helper functions 2*/
char **split(char *string, char *breaks);
int _atoi(char *s);
char *cleanStr(char *str);
ssize_t _getline(char **string, size_t *string_size);

/* environment helper functions*/
char **get_all_paths(void);
char *get_env(char *string);

/*execution functions*/
int before_execution(char **arguments, char **paths, int p_cnt, char *p_path);
int execution(char **arguments);

/* array helper functions*/
char **copy_array_of_strings(char **str);
void free_array_of_pointers(char **array);

/* built in checker */
void check_exit(char **arguments, char *string, char **paths);
int check_builtin(char **arguments);

/* built in functions*/
int set_env_variable(char **arguments);
int unset_env_variable(char **arguments);
int _cd(char **arguments);
int print_env(char **arguments);

/*free helper functions */
void free_all(char **arguments, char *string, char **paths);

/*error functions*/
void execve_error(char *command, int proccess_number, char *program_path);
/*number helper functions*/
void print_num(unsigned int n);

#endif
