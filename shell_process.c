#include "main.h"

/**
 * shell_process - core of shell programe process
 * @string: input string to shell
 * @arguments: splitted string acc to breaks
 * @paths: splitted path from environment
 * @breaks: user to split the string
 */
void shell_process(char *string, char **arguments, char **paths, char *breaks)
{
string = get_string();

/* check \n enter character */
if (*string == '\n')
{
free(string);
return;
}
arguments = split(string, breaks);

/* handle EOF && ctrl+c*/
check_exit(arguments, string, paths);
/* builtin checker */
if (check_builtin(arguments) == -1)
{
before_execution(arguments, paths);
}
free_all(arguments, string, NULL);
}

