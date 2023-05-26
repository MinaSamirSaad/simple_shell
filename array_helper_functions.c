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
/**
 * remove_idx_from_array - remove element from array
 * @idx: index of element
 * @array: array to remove element from
 */
void remove_idx_from_array(int idx, char **array)
{
int i = idx;
int length = 0;
while (array && array[length])
{
length++;
}
length++;
free(array[i]);
for (; i < (length - 1); i++)
{
array[i] = array[i + 1];
}
}
