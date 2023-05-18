#include "main.h"
/**
 * execution - function that Execute external command
 * @arguments: the arguments of command
 * the arguments[0] is the path of program to Execute
 */
void execution(char **arguments)
{
pid_t pid;
int status;
/*using fork to create child proccess*/
pid = fork();
if (pid == 0)
{
/*child proccess*/
if (execve(arguments[0], arguments, NULL) == -1)
{
perror("execve");
}
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
}
