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
