#include "main.h"

/**
 * _strlen - string length
 * @str: array of charahcters null terminated
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str && str[i] != '\0')
		i++;

	return (i);
}
/**
 * _strcmp - compared two strings
 * @str1: first one
 * @str2: seocnd one
 * Return: (0) match (1) not match
 */
int _strcmp(char *str1, char *str2)
{
	int pos = 0;

	while (str1[pos])
	{
		if (str1[pos] != str2[pos])
			return (1);
		pos++;
	}
	return (0);
}

/**
 * _strcopy - copy str to new allocated one and return it
 * @str: source
 * Return: newly allocated string copy of source
 */
char *_strcopy(char *str)
{
	int length, i = 0;
	char *strcopy = NULL;

	length = _strlen(str);
	/* 1 to null character */
	strcopy = malloc(length + 1);
	while (i < length && str[i])
	{
		strcopy[i] = str[i];
		i++;
	}
	strcopy[i] = '\0';
	return (strcopy);
}

/**
 * _strconcat - add str2 command to str1 path
 * @str1: first string
 * @str2: second string
 * Return: str1 after addition
 */
char *_strconcat(char *str1, char *str2)
{
	int str1_length, str2_length, i;
	char *full_str = NULL;

	i = 0;
	str1_length = _strlen(str1);
	str2_length = _strlen(str2);
	/* 2 for / , \0 chars */
	full_str = malloc(str1_length + str2_length + 2);
	for (i = 0 ; i < str1_length; i++)
		full_str[i] = str1[i];

	full_str[i] = '/';

	for (i = 0 ; i < str2_length; i++)
		full_str[(i + str1_length) + 1] = str2[i];

	full_str[str1_length + str2_length + 1] = '\0';
	return (full_str);
}

/**
 * get_string - function to get the string from stander input
 * Return: the string from stander input
 */
char *get_string()
{
	char *string = NULL;
	size_t string_size = 0;

	if (getline(&string, &string_size, stdin) == -1)
	{
		perror("Error : failed to get line\n");
		exit(EXIT_FAILURE);
	}
	return (string);
}

