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
int status = 0;
char **args = NULL;
int proccess_counter = 1;
char *string = NULL;
size_t string_size = 0;
char **paths = get_all_paths();

signal(SIGINT, catch_signal);

/*print prompt if user run the program*/
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "m$ ", 3);
/* if not or get the command from pipe*/
/*it will start execute the command*/
while ((_getline(&string, &string_size)))
{
/* split arguments && execution the commands*/
status = sh(string, args, paths, proccess_counter, program_path);
proccess_counter++;
fflush(stdout);
/*check non interactive mood*/
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "m$ ", 3);
}
/*check EOF*/
/*the only way you can arrive here with EOF = -1*/
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "\n", 1);
free_all(args, string, paths);
return (status);
}
