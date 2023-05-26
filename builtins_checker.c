#include "main.h"
/**
 * check_exit - check that argument[0] = exit
 * exit with argument[1] if exists
 * @str: input string to shell
 * @args: splitted string acc to breaks
 * @paths: splitted path from environment
 * @st: status of execution
 * @p: number of proccess
 * @pth: the program path
 * Return: zero if found exit but not true
 * one if not found
 */
int check_exit(char **args, char *str, char **paths, int *st, char *pth, int p)
{
char *msg = NULL;
int arg1_result;
if (_strcmp("exit", args[0]) == 0)
{
if (args[1])
{
if (check_positive(args[1]) == 0)
{
arg1_result = _atoi(args[1]);
free_all(args, str, paths);
free_array_of_pointers(environ);
exit(arg1_result);
}
else
{
msg = _strconcat2("Illegal number", args[1]);
execve_error(msg, args[0], p, pth);
free(msg);
*st = 2;
return (0);
}
}
free_all(args, str, paths);
free_array_of_pointers(environ);
exit(*st);
}
return (1);
}

/**
 * check_builtin - check the builtin environments
 * @arguments: splitted string acc to breaks
 * Return: -1 if not builtin else return builtin function
 */

int check_builtin(char **arguments)
{
/*list of builtin environments to compare with argument[0]*/
char *builtin_str[] = {"env", "setenv", "unsetenv", "cd"};
/*pointers to builtin functions*/
int (*builtin_func[])(char **) = {&print_env,
&set_env_variable, &unset_env_variable, &_cd};
int i;
/*length of builtin functions*/
int num_builtins = (sizeof(builtin_str) / sizeof(char *));

for (i = 0; i < num_builtins; i++)
{
if (_strcmp(arguments[0], builtin_str[i]) == 0)
{
return ((*builtin_func[i])(arguments));
}
}
return (-1);
}
