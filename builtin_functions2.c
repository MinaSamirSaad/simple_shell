#include "main.h"
/**
 * set_environ - set environ at idx i
 * @i: index
 * @arg1: variable name
 * @arg2: value
 */
void set_environ(int i, char *arg1, char *arg2)
{
	int k;
	int len1 = _strlen(arg1);
	int len2 = _strlen(arg2);

	environ[i] = malloc(len1 + len2 + 2);
	for (k = 0; k < len1; k++)
		environ[i][k] = arg1[k];
	environ[i][k++] = '=';
	for (; k < len1 + len2 + 2; k++)
		environ[i][k] = arg2[k - len1 - 1];
	environ[i][k] = '\0';
}
/**
 * copy_array_of_strings2 - hard copy
 * @str: array of strings
 * Return: allocated new copy array
 */
char **copy_array_of_strings2(char **str)
{
	char **new_array = NULL;
	int i = 0;

	while (str[i])
	{
		i++;
	}
	new_array = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (str[i])
	{
		new_array[i] = _strcopy(str[i]);
		i++;
	}
	new_array[i + 1] = NULL;
	return (new_array);
}
/**
 * set_env_variable - set the environment
 * @arguments: splitted string acc to breaks
 * Return: EXIT_SUCCESS = 0
 */
int set_env_variable(char **arguments)
{
int i = 0, j;
int len1 = 0;

if (arguments[1] != NULL && arguments[2] != NULL)
{
	len1 = _strlen(arguments[1]);
	while (environ[i])
	{
		for (j = 0; j < len1; j++)
		{
			if (arguments[1][j] != environ[i][j])
				break;
		}
		if (j == len1)
		{
			free(environ[i]);
			set_environ(i, arguments[1], arguments[2]);
		}
		i++;
	}
	environ = copy_array_of_strings2(environ);
	set_environ(i, arguments[1], arguments[2]);
}
else
{
perror("enter environment variable and value");
return (EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}
/**
 * unset_env_variable - unset the environment
 * @arguments: splitted string acc to breaks
 * Return: EXIT_SUCCESS = 0
 */
int unset_env_variable(char **arguments)
{
if (arguments[1] != NULL)
{
if (unsetenv(arguments[1]) != 0)
{
perror("Failed to unset environment variable");
return (EXIT_FAILURE);
}
}
else
{
perror("enter environment variable");
return (EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}

