#include "shell.h"

/**
 * _strlen - returns the str's length
 * @s: the str's length checked
 *
 * Return: int length of str
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compares lexicogarphic of two stras.
 * @s1: the first stra
 * @s2: the second stra
 *
 * Return: if s1 < s2 ->(-), if s1 > s2 ->(+), if s1 == s2->0
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - determins if needle starts with haystack
 * @haystack: str to find
 * @needle: the substring to detect
 *
 * Return: address of next char of haystack | otherwise NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strs
 * @dest: buffer's destination
 * @src: buffer's source
 *
 * Return: pointer to buffer's destination
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
