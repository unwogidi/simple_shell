#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer to the string
 * Return: length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}


/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: an integer
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}


/**
 * _strcspn - gets the length of a prefix substring
 * @s: the string to be scanned
 * @reject: the string containing the characters to match
 * Return: the number of bytes in the initial segment of s
 */
unsigned int _strcspn(char *s, char *reject)
{
	unsigned int count = 0;
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; reject[j] != '\0'; j++)
		{
			if (s[i] == reject[j])
			{
				return (count);
			}
		}
		count++;
	}

	return (count);
}
