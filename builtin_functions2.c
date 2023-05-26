#include "main.h"

/**
 * set_environ - set environ at idx i
 * @i: index
 * @arg1: variable name
 * @arg2: value
 */
void set_environ(int i, char *arg1, char *arg2)
{
int len1 = _strlen(arg1);
int len2 = _strlen(arg2);
int total_length = len1 + len2 + 2;
int j = 0;
int idx = 0;

environ[i] = malloc(total_length);
if (!environ[i])
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}

for (j = 0; j < len1; j++)
{
environ[i][idx] = arg1[j];
idx++;
}
environ[i][idx] = '=';
idx++;
for (j = 0; j < len2; j++)
{
environ[i][idx] = arg2[j];
idx++;
}
environ[i][idx] = '\0';
}

/**
 * copy_array_of_strings2 - hard copy
 * @str: array of strings
 * Return: allocated new copy array
 */
char **copy_array_of_strings2(char **str)
{
int count = 0;
char **new_array = str;
int i;

while (*new_array)
{
count++;
new_array++;
}

new_array = malloc(sizeof(char *) * (count + 2));
if (!new_array)
{
perror("Memory allocation failed");
exit(EXIT_FAILURE);
}

for (i = 0; i < count; i++)
{
new_array[i] = _strcopy(str[i]);
if (!new_array[i])
{
perror("Memory allocation failed");
free_array_of_pointers(new_array);
exit(EXIT_FAILURE);
}
}
new_array[count + 1] = NULL;

return (new_array);
}

/**
 * set_env_variable - set the environment
 * @arguments: splitted string according to breaks
 * Return: EXIT_SUCCESS = 0
 */
int set_env_variable(char **arguments)
{
int i = 0, j;
int len1 = 0;
char **new_environ = NULL;
if (arguments[1] != NULL && arguments[2] != NULL)
{
len1 = _strlen(arguments[1]);
while (environ[i])
{
for (j = 0; j <= len1; j++)
{
if (arguments[1][j] != environ[i][j])
break;
}
if (j == len1)
{
free(environ[i]);
set_environ(i, arguments[1], arguments[2]);
return (EXIT_SUCCESS);
}
i++;
}

new_environ = copy_array_of_strings2(environ);
if (!new_environ)
{
perror("Memory allocation failed");
return (EXIT_FAILURE);
}

free_array_of_pointers(environ);
environ = new_environ;

set_environ(i, arguments[1], arguments[2]);
}
else
{
return (EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}

/**
 * unset_env_variable - unset the environment
 * @arguments: splitted string according to breaks
 * Return: EXIT_SUCCESS = 0
 */
int unset_env_variable(char **arguments)
{
int i = 0, j;
int len1 = 0;
if (arguments[1] != NULL)
{
len1 = _strlen(arguments[1]);
while (environ[i])
{
for (j = 0; j <= len1; j++)
{
if (arguments[1][j] != environ[i][j])
break;
}
if (j == len1)
{
/* remove variable*/
remove_idx_from_array(i, environ);
return (EXIT_SUCCESS);
}
i++;
}
}
return (EXIT_FAILURE);
}
