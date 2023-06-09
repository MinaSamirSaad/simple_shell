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

/* and split arguments && execution the commands*/
void sh(char *str, char **args, char **paths, int p_cnt, char *p_path,
int *st);

/* checker helper functions*/
int check_full_path(char *argument);
char *check_small_path(char *argument, char **path);

/* string helper functions*/
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strconcat(char *str1, char *str2);
char *_strcopy(char *str);
void remove_comment(char *str);

/* string helper functions 2*/
char **split(char *string, char *breaks);
int _atoi(char *s);
char *cleanStr(char *str);
ssize_t _getline(char **string, size_t *string_size);

/*string helper functions 3*/
char *_strconcat2(char *str1, char *str2);

/* environment helper functions*/
char **get_all_paths(void);
char *get_env(char *string);

/*execution functions*/
void before_exec(char **args, char **paths, int p_cnt, char *p_path, int *st);
void execution(char **arguments, int *st);

/* array helper functions*/
char **copy_array_of_strings(char **str);
void free_array_of_pointers(char **array);
void remove_idx_from_array(int idx, char **array);

/* built in checker */
int check_exit(char **args, char *str, char **paths, int *st,
char *pth, int p);
int check_builtin(char **arguments);

/* built in functions*/
int set_env_variable(char **arguments);
int unset_env_variable(char **arguments);
int _cd(char **arguments);
int print_env(char **arguments);

/*free helper functions */
void free_all(char **arguments, char *string, char **paths);

/*error functions*/
void execve_error(char *msg, char *command, int count, char *p_path);
/*number helper functions*/
void print_num(unsigned int n);
int check_positive(char *str);

#endif
