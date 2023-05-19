#include"main.h"
/**
 * split - function that split string  into arguments
 * @string: the string to split
 * @breaks: array of breaks characters
 * Return: array of arguments
 */
char **split(char *string, char *breaks)
{
	char *argument;
	char **arguments;
	int position = 0;

	/* no need to intialize breaks as it sent to it*/
	/* breaks = " \t\r\n\a"; */
	/* may cause error so need to check if it full */
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
