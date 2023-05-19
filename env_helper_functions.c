#include "main.h"

/**
 * get_env - get environment from environ
 * @string: environment to search in environ
 * Return: address of its value if  found - NULL if not
 */
char *get_env(char *string)
{
	int length = _strlen(string);
	int i = 0;

	while (environ[i] != NULL)
	{
		if (_strcmp(string, environ[i]) == 0)
		{
			return (&environ[i][length + 1]);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_all_paths - split the found path into paths
 * Return: splitted paths (allocated in memory)
 */
char **get_all_paths(void)
{
	char *path = get_env("PATH");
	char *pathcopy = _strcopy(path);
	char **splitted_paths = split(pathcopy, ":");
	char **copy_splitted_paths = copy_array_of_strings(splitted_paths);

	free(pathcopy);
	free(splitted_paths);
	return (copy_splitted_paths);
}
