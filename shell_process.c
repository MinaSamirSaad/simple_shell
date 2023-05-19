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
	arguments = split(string, breaks);

	/* check \n enter character */
	/* builtin check from here */
	if (_strcmp(arguments[0], "exit") == 0)
	{
		free(string);
		free(arguments);
		free_array_of_pointers(paths);
		exit(EXIT_SUCCESS);
	}
	before_execution(arguments, paths);
	free(string);
	free(arguments);
}
