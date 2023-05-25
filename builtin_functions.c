#include "main.h"
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
 * set_env - set the environments
 * @key: splitted string acc to breaks
 * @value: splitted string acc to breaks
 * Return: EXIT_SUCCESS = 0
 */
int set_env(char *key, char *value)
{
char **args = NULL;
int length = _strlen(key);
args = malloc(3 * sizeof(char *));
args[1] = malloc((length + 1));
args[1] = key;
length = _strlen(value);
args[2] = malloc((length + 1));
args[2] = value;
set_env_variable(args);
free(value);
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
printf("%s\n", arguments[1]);
if (!arguments[1])
{
write(STDERR_FILENO, &"cd: OLDPWD not set\n", 19);
return (EXIT_FAILURE);
}
}
old_pwd = getcwd(NULL, 0);
set_env("OLDPWD", old_pwd);
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
set_env("PWD", pwd);
return (EXIT_SUCCESS);
}
}
return (EXIT_SUCCESS);
}
