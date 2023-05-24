#include "main.h"

/**
 * sh - core of shell programe process
 * @str: input string to shell
 * @args: splitted string acc to breaks
 * @paths: splitted path from environment
 * @p_cnt: number of proccess
 * @p_path: the program path
 */
void sh(char *str, char **args, char **paths, int p_cnt, char *p_path)
{
char *breaks = " ";
char *clean_string;
str = get_string();
/*check EOF*/
if (str == NULL)
{
write(STDOUT_FILENO, "\n", 1);
free_all(args, str, paths);
exit(EXIT_SUCCESS);
}
clean_string = cleanStr(str);
/*check \n && comment(#)*/
if (clean_string == NULL)
{
free(str);
return;
}
args = split(str, breaks);
if (args[0] == NULL)
{
free_all(args, str, NULL);
return;
}
check_exit(args, str, paths);
/* builtin checker */
if (check_builtin(args) == -1)
{
before_execution(args, paths, p_cnt, p_path);
}
free_all(args, str, NULL);
}
	