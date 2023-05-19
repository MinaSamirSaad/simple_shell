#include "main.h"

/**
 * free_array_of_pointers - free array of allocated pointers
 * @array: array of pointers
 */
void free_array_of_pointers(char **array)
{
	char **temp = array;

	while (array && *array)
	{
		free(*array);
		array++;
	}
	free(temp);
}

/**
 * copy_array_of_strings - hard copy
 * @str: array of strings
 * Return: allocated new copy array
 */
char **copy_array_of_strings(char **str)
{
	char **new_array = NULL;
	int i = 0;

	while (str[i])
	{
		i++;
	}
	new_array = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (str[i])
	{
		new_array[i] = _strcopy(str[i]);
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}
