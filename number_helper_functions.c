#include "main.h"
/**
 * print_num - recursive function to print a number
 *@n: number to print
*/
void print_num(unsigned int n)
{
char num;

if (n / 10)
print_num(n / 10);

num = n % 10 + '0';
write(STDERR_FILENO, &num, 1);
}
