#include "main.h"

/**
 * sh - core of shell programe process
 * @str: input string to shell
 * @args: splitted string acc to breaks
 * @paths: splitted path from environment
 * @p_cnt: number of proccess
 * @p_path: the program path
 * @st: status of execution
 * Return: status of execution
 */
void sh(char *str, char **args, char **paths, int p_cnt, char *p_path, int *st)
{
char *breaks = " ";
char *clean_string;
clean_string = cleanStr(str);
/*check \n && comment(#)*/
if (clean_string == NULL)
{
free(str);
*st = 0;
return;
}
args = split(str, breaks);
if (args[0] == NULL)
{
free_all(args, str, NULL);
*st = 0;
return;
}
check_exit(args, str, paths, st);
/* builtin checker */
*st = check_builtin(args);
if (*st == -1)
{
before_exec(args, paths, p_cnt, p_path, st);
}
free_all(args, str, NULL);
}
