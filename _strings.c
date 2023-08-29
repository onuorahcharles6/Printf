#include <stdlib.h>
#include "main.h"

/**
 * _strlen - collects lent of string, not adding null byte
 * @str: string 2 add lent of
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int i = 0;

	while (*(str + i))
		i++;
	return (i);
}
/**
 * _strcpy - duplicates a string
 * @dest: location string
 * @src: source of d string
 *
 * Return: pointing 2 location
 */
char *_strcpy(char *desti, char *srcs)
{
	int i = 0;

	while (srcs[i])
	{
		desti[i] = srcs[i];
		i++;
	}
	desti[i] = '\0';
	return (desti);
}
/**
 * _string_upper - changes lowercases in a string 2 uppercase.
 * @str: char pointer 2 d string.
 *
 * Return: Void.
 */
void _string_upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}
/**
 * fill_nonprint_buffer - pours a buffer with given string, replacing nonprints
 * @length: length of buffer in bytes
 * @buff: char pointer 2 buffer in store
 * @str: char pointer 2 string 2 double in2 buffer in store
 *
 * Return: 1 on access, 0 on malloc failure on hexvalue 4 nonprints
 */
int fill_nonprint_buffer(int length, char *buff, char *str)
{
	int i, j;
	char *hex_value;

	i = 0, j = 0;
	while (i < length)
	{
		if (!is_printable(str[j]) && str[j] > 0)
		{
			hex_value = get_hex_n((unsigned int)str[j]);
			if (!hex_value)
				return (0);
			buff[i++] = '\\';
			buff[i++] = 'x';
			_string_upper(hex_value);
			if (hex_value[1])
			{
				buff[i++] = hex_value[0];
				buff[i++] = hex_value[1];
			}
			else
			{
				buff[i++] = '0';
				buff[i++] = hex_value[0];
			}
			free(hex_value);
		}
		else
		{
			buff[i] = str[j];
			i++;
		}
		j++;
	}
	buff[length] = '\0';
	return (1);
}
