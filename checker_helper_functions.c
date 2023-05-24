#include "main.h"

/**
 * check_full_path - check if argument is full_path
 * @argument: string to test
 * Return: result of access (0)success
 */
int check_full_path(char *argument)
{
	return (access(argument, F_OK));
}

/**
 * check_small_path - check if arfument is small_path
 * @argument: string to test
 * @path: array of separted paths to contactenate to argument
 * Return: allocated full path (success) NULL (fail)
 */
char *check_small_path(char *argument, char **path)
{
	char *fullpath;

	while (*path != NULL)
	{
		fullpath =  _strconcat(*path, argument);
		if (check_full_path(fullpath) == 0)
		{
			return (fullpath);
		}
		free(fullpath);
		path++;
	}
	return (NULL);
}
