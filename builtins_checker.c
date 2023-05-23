#include "main.h"
/**
 * check_exit - check that argument[0] = exit
 * exit with argument[1] if exists
 * @string: input string to shell
 * @arguments: splitted string acc to breaks
 * @paths: splitted path from environment
 */
void check_exit(char **arguments, char *string, char **paths)
{
int arg1_result;

if (_strcmp(arguments[0], "exit") == 0)
{
if (arguments[1])
{
arg1_result = _atoi(arguments[1]);
free_all(arguments, string, paths);
exit(arg1_result);
}
free_all(arguments, string, paths);
exit(EXIT_SUCCESS);
}
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
