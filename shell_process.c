#include "main.h"
/**
 * sh_p - core of shell programe process
 * @str: input string to shell
 * @paths: splitted path from environment
 * @p_cnt: number of proccess
 * @p_path: the program path
 */
void sh_p(char *str, char **paths, int p_cnt, char *p_path)
{
char **args;
args = split(str, " ");
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
free_all(args, NULL, NULL);
}

/**
 * sh - core of shell programe process
 * @str: input string to shell
 * @paths: splitted path from environment
 * @p_cnt: number of proccess
 * @p_path: the program path
 */
void sh(char *str, char **paths, int p_cnt, char *p_path)
{
char *clean_string;
char *token = NULL;

str = get_string();
/*check EOF*/
if (str == NULL)
{
write(STDOUT_FILENO, "\n", 1);
free_all(NULL, str, paths);
exit(EXIT_SUCCESS);
}
clean_string = cleanStr(str);
/*check \n && comment(#)*/
if (clean_string == NULL)
{
free(str);
return;
}
token = strtok(str, "\n");

while (token != NULL)
{
sh_p(token, paths, p_cnt, p_path);
token = strtok(NULL, "\n");
}
free(token);
}
