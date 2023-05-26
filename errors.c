#include "main.h"
/**
 * execve_error - function to print execve error message
 * @msg: the error message
 * @command: the false command that entered
 * @count: the number of proccess
 * @p_path: the path of program
 */

void execve_error(char *msg, char *command, int count, char *p_path)
{
int string_length;
string_length = _strlen(p_path);
write(STDERR_FILENO, p_path, string_length);
write(STDERR_FILENO, ": ", 2);
print_num(count);
write(STDERR_FILENO, ": ", 2);
string_length = _strlen(command);
write(STDERR_FILENO, command, string_length);
write(STDERR_FILENO, ": ", 2);
string_length = _strlen(msg);
write(STDERR_FILENO, msg, string_length);
write(STDERR_FILENO, "\n", 1);
}
