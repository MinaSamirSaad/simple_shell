#include "main.h"
/**
 * execve_error - function to print execve error message
 * @command: the false command that entered
 * @proccess_number: the number of proccess
 * @program_path: the path of program
 */

void execve_error(char *command, int proccess_number, char *program_path)
{
char *error_message = "not found";
int string_length;
string_length = _strlen(program_path);
write(STDOUT_FILENO, program_path, string_length);
write(STDOUT_FILENO, ": ", 2);
print_num(proccess_number);
write(STDOUT_FILENO, ": ", 2);
string_length = _strlen(command);
write(STDOUT_FILENO, command, string_length);
write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, error_message, 9);
write(STDOUT_FILENO, "\n", 1);
}
