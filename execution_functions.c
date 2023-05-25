#include "main.h"
/**
 * execution - function that Execute external command
 * @arguments: the arguments of command
 * the arguments[0] is the path of program to Execute
 * @st: status of execution
 * Return: status of execution
 */
void execution(char **arguments, int *st)
{
pid_t pid;
int status = 0;
/*using fork to create child proccess*/
pid = fork();
if (pid == 0)
{
/*child proccess*/
execve(arguments[0], arguments, environ);
}
else if (pid == -1)
{
/*failed to fork proccess*/
perror("Error: Cannot fork");
exit(EXIT_FAILURE);
}
else
{
/*parent proccess*/
if (waitpid(pid, &status, 0) == -1)
{
perror("Error: waitpid failed");
exit(EXIT_FAILURE);
}
}
if (WIFEXITED(status))
{
int exit_status = WEXITSTATUS(status);
*st = exit_status;
}
}

/**
 * before_exec - check certain condition betfore execution
 * @args: arguments splitted
 * @paths: paths splitted
 * @p_cnt: number of proccess
 * @p_path: the program path
 * @st: status of execution
 * Return: status of execution
 */
void before_exec(char **args, char **paths, int p_cnt, char *p_path, int *st)
{
char *fullpath = NULL;

if (access(args[0], F_OK) == 0)
execution(args, st);
else if (check_full_path(args[0]) == 0)
execution(args, st);
else
{
fullpath = check_small_path(args[0], paths);
if (fullpath != NULL)
{
args[0] = fullpath;
execution(args, st);
free(fullpath);
}
else
{
execve_error(args[0], p_cnt, p_path);
*st = 127;
return;
}
}
}
