#include "main.h"

/**
 * sh - core of shell programe process
 * @str: input string to shell
 * @args: splitted string acc to breaks
 * @paths: splitted path from environment
 * @p_cnt: number of proccess
 * @p_path: the program path
 * Return: status of execution
 */
int sh(char *str, char **args, char **paths, int p_cnt, char *p_path)
{
int status = 1;
char *breaks = " ";
char *clean_string;
clean_string = cleanStr(str);
/*check \n && comment(#)*/
if (clean_string == NULL)
{
free(str);
return (EXIT_SUCCESS);
}
args = split(str, breaks);
if (args[0] == NULL)
{
free_all(args, str, NULL);
return (EXIT_SUCCESS);
}
check_exit(args, str, paths);
/* builtin checker */
status = check_builtin(args);
if (status == -1)
{
status = before_execution(args, paths, p_cnt, p_path);
}
free_all(args, str, NULL);
return (status);
}
