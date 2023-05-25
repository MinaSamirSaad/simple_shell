#include "main.h"
/**
 * catch_signal - signal handler
 * @number: the number of signal
 */
void catch_signal(int number)
{
if (number == SIGINT)
{
write(STDOUT_FILENO, "\n ", 1);
exit(EXIT_SUCCESS);
}
}
/**
 * infinite_loop - function to make the shell always open
 * inside the loop we get string, split it and execute it
 * @program_path: the program path
 * Return: status of execution
 */
int infinite_loop(char *program_path)
{
int status = 1;
char **args = NULL;
int proccess_counter = 1;
char *string = NULL;
char **paths = get_all_paths();

/*test 2*/
setenv("LANG", "en_US.UTF-8", 1);
signal(SIGINT, catch_signal);
/*Read input from pipe*/
/* non interactive */
if (!isatty(STDIN_FILENO))
{
/* read stander input && split arguments && execution the commands*/
status = sh(string, args, paths, proccess_counter, program_path);
free_array_of_pointers(paths);
exit(status);
}
/*Read input from user*/
/* interactive */
while (1)
{
write(STDOUT_FILENO, "m$ ", 3);
fflush(stdout);
/* read stander input && split arguments && execution the commands*/
status = sh(string, args, paths, proccess_counter, program_path);
proccess_counter++;
}
return (status);
}
