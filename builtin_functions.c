#include "main.h"
/**
 * set_env_variable - set the environment
 * @arguments: splitted string acc to breaks
 * Return: EXIT_SUCCESS = 0
 */
int set_env_variable(char **arguments)
{
if (arguments[1] != NULL && arguments[2] != NULL)
{
if (setenv(arguments[1], arguments[2], 1) != 0)
{
perror("Failed to set environment variable");
return (EXIT_FAILURE);
}
}
else
{
perror("enter environment variable and value");
return (EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}
/**
 * unset_env_variable - unset the environment
 * @arguments: splitted string acc to breaks
 * Return: EXIT_SUCCESS = 0
 */
int unset_env_variable(char **arguments)
{
if (arguments[1] != NULL)
{
if (unsetenv(arguments[1]) != 0)
{
perror("Failed to unset environment variable");
return (EXIT_FAILURE);
}
}
else
{
perror("enter environment variable");
return (EXIT_FAILURE);
}
return (EXIT_SUCCESS);
}
/**
 * print_env - print the environments
 * @arguments: splitted string acc to breaks
 * Return: EXIT_SUCCESS = 0
 */
int print_env(__attribute__((unused)) char **arguments)
{
int length;
char **temp = environ;

while (temp && *temp)
{
length = _strlen(*temp);
write(STDOUT_FILENO, *temp, length);
write(STDOUT_FILENO, "\n", 1);
temp++;
}
return (EXIT_SUCCESS);
}
/**
 * _cd - change directory
 * @arguments: splitted string acc to breaks
 * Return: EXIT_SUCCESS = 0
 */
int _cd(char **arguments)
{
char *pwd;
char *old_pwd;
/* If no directory is provided, change to the home directory*/
if (arguments[1] == NULL)
{
arguments[1] = get_env("HOME");
}

/* If the directory is '-', change to the previous directory*/
if (arguments[1][0] == '-' && arguments[1][1] == '\0')
{
arguments[1] = get_env("OLDPWD");
}
old_pwd = getcwd(NULL, 0);
setenv("OLDPWD", old_pwd, 1);
free(old_pwd);
if (chdir(arguments[1]) != 0)
{
perror("cd");
return (EXIT_FAILURE);
}
else
{
/*Update the PWD environment variable*/
pwd = getcwd(NULL, 0);
if (pwd != NULL)
{
setenv("PWD", pwd, 1);
free(pwd);
return (EXIT_SUCCESS);
}
}
return (EXIT_SUCCESS);
}
