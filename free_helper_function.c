#include "main.h"
/**
 * free_all - free all memory from arguments & string & paths
 * @string: input string to shell
 * @arguments: splitted string acc to breaks
 * @paths: splitted path from environment
 */
void free_all(char **arguments, char *string, char **paths)
{
free(string);
free(arguments);
free_array_of_pointers(paths);
}
