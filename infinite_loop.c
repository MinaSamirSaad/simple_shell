#include "main.h"
/**
 * infinite_loop - function to make the shell always open
 * inside the loop we get string, split it and execute it
 */
void infinite_loop(void)
{
char *string;
char **arguments;
/*Read input from pipe*/
if (!isatty(STDIN_FILENO))
{
string = get_string();
arguments = split(string);
execution(arguments);
free(string);
exit(EXIT_SUCCESS);
}
/*Read input from user*/
while (1)
{
write(STDOUT_FILENO, "m$ ", 3);
fflush(stdout);
string = get_string();
arguments = split(string);
execution(arguments);
free(string);
}
}
