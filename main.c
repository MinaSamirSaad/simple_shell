#include "main.h"
/**
 * main - the main function that start the program
 * it contain one function that start infinity loop
 * @argc: number of arguments
 * @argv: the arguments
 * Return: EXIT_SUCCESS = 0 if successful
 */
int main(__attribute__((unused)) int argc, char **argv)
{
/*a function that helps me to keep the shell open*/
infinite_loop(argv[0]);
return (EXIT_SUCCESS);
}
