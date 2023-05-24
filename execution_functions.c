#include "main.h"
/**
 * execution - function that Execute external command
 * @arguments: the arguments of command
 * the arguments[0] is the path of program to Execute
 * Return: status of execution
 */
int execution(char **arguments)
{
pid_t pid;
int status = 1;

/*using fork to create child proccess*/
pid = fork();
if (pid == 0)
{
/*child proccess*/
execve(arguments[0], arguments, NULL);
}
else if (pid == -1)
{
/*failed to fork proccess*/
perror("Error: Cannot fork");
return (EXIT_FAILURE);
}
else
{
/*parent proccess*/
if (waitpid(pid, &status, 0) == -1)
{
perror("Error: waitpid failed");
return (EXIT_FAILURE);
}
}
if (WIFEXITED(status))
{
int exit_status = WEXITSTATUS(status);
return (exit_status);
}
return (status);
}

/**
 * before_execution - check certain condition betfore execution
 * @arguments: arguments splitted
 * @paths: paths splitted
 * @p_cnt: number of proccess
 * @p_path: the program path
 * Return: status of execution
 */
int before_execution(char **arguments, char **paths, int p_cnt, char *p_path)
{
int status = 1;
char *fullpath = NULL;

if (access(arguments[0], F_OK) == 0)
status = execution(arguments);
else if (check_full_path(arguments[0]) == 0)
status = execution(arguments);
else
{
fullpath = check_small_path(arguments[0], paths);
if (fullpath != NULL)
{
arguments[0] = fullpath;
status = execution(arguments);
free(fullpath);
}
else
{
execve_error(arguments[0], p_cnt, p_path);
return (127);
}
}

return (status);
}
