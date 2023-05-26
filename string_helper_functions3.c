#include "main.h"

/**
 * _strconcat2 - add str2 command to str1 path
 * @str1: first string
 * @str2: second string
 * Return: str1 after addition
 */
char *_strconcat2(char *str1, char *str2)
{
int str1_length, str2_length, i;
char *full_str = NULL;

i = 0;
str1_length = _strlen(str1);
str2_length = _strlen(str2);
/* 2 for / , \0 chars */
full_str = malloc(str1_length + str2_length + 3);
for (i = 0; i < str1_length; i++)
full_str[i] = str1[i];

full_str[i++] = ':';
full_str[i] = ' ';

for (i = 0; i < str2_length; i++)
full_str[(i + str1_length)+2] = str2[i];

full_str[str1_length + str2_length + 2] = '\0';
return (full_str);
}
