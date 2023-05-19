#include "main.h"

/**
 * infinite_loop - function to make the shell always open
 * inside the loop we get string, split it and execute it
 */
void infinite_loop(void)
{
	char *string;
	char **arguments;
	char **paths = get_all_paths();
	char *breaks = " \t\r\n\a";

	/*Read input from pipe*/
	/* non interactive */
	if (!isatty(STDIN_FILENO))
	{
		/* read stander input && split arguments && execution the commands*/
		shell_process(string, arguments, paths, breaks);
		free_array_of_pointers(paths);
		exit(EXIT_SUCCESS);
	}
	/*Read input from user*/
	/* interactive */
	while (1)
	{
		write(STDOUT_FILENO, "m$ ", 3);
		fflush(stdout);
		/* read stander input && split arguments && execution the commands*/
		shell_process(string, arguments, paths, breaks);
	}
}
