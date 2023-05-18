#include "main.h"
/**
 * get_string - function to get the string from stander input
 * Return: the string from stander input
 */
char *get_string()
{
char *string = NULL;
size_t string_size = 0;

if (getline(&string, &string_size, stdin) == -1)
{
perror("Error : failed to get line\n");
exit(EXIT_FAILURE);
}

return (string);
}
