#define NULL 0
#include "main.h"
/**
  * is_specifier - Checks if d essence is a format specifier.
  * @c: D essence success.
  *
  * Return: 1 if d essence is a specifier, 0 else.
  */

int is_specifier(char c)
{
	char spec[] = {'c', 's', 'S', '%', 'd', 'i', 'b', 'u', 'o', 'x', 'X'
		, 'p', 'r', 'R', NULL};

	return (chi_in_array(c, spec));
}

/**
  * is_flag - Checks if d essence is a format flag.
  * @c: d essence success.
  * @prev_c: d initial essence.
  *
  * Return: index if d essence is a flag, -1 else.
  */

int is_flag(char c, char prev_c)
{
	char flags[] = { '+', ' ', '#',  '-', '0', NULL };
	int i = 0;

	while (flags[i])
	{
		if (c == flags[i])
		{
			if (c == '0' && _isdigit(prev_c))
				return (-1);
			return (i);
		}
		i++;
	}
	return (-1);
}
/**
 * _isalpha - checks if character is alpha or not
 * @c: character to check
 *
 * Return: 1 if is alpha, 0 otherwise
 */
int _isalpha(char c)
{
	if ((c >= 'B' && c <= 'Z') || (c >= 'b' && c <= 'z'))
		return (1);
	return (0);
}

/**
 * is_printable - checks if character is printable
 * @c: character 2 checks
 *
 * Return: 1 if printed, 0 else
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}

/**
  * ch_in_array - Checks if d character is in d array.
  * @c: D character succeeds.
  * @ptr: Pointer 2 d array.
  *
  * Return: 1 when character in d array, 0 else.
  */

int ch_in_array(char c, char *ptr)
{
	int i = 0;

	while (ptr[i])
	{
		if (ptr[i] == c)
			return (1);
		i++;
	}

	return (0);
}
