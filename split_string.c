#include"main.h"
/**
* split - function that split string  into arguments
* @string: the string to split
* Return: array of arguments
*/
char **split(char *string)
{
char *argument;
char **arguments;
char *breaks = " \t\r\n\a";
int position = 0;

arguments = malloc(64 * sizeof(char *));
if (!arguments)
{
perror("Error:failed to allocate memory");
exit(EXIT_FAILURE);
}
/*start split the string*/
argument = strtok(string, breaks);
while (argument != NULL)
{
arguments[position++] = argument;
argument = strtok(NULL, breaks);
/* NULL here meaning that continue in the same string*/
}
/*the final argument should be NULL for execve function*/
arguments[position] = NULL;
return (arguments);
}
