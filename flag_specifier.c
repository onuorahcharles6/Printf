#include "main.h"
#include <stdlib.h>

/**
 * do_plus_flag - Sums a '+' before all positive integers.
 * @str: D string storing d integer. Assume nt NULL.
 *
 * Return: Void.
 */

char *do_plus_flag(char *str)
{
	int i, lent;
	char *rat;

	if (str[0] == '-')
		return (str);

	lent = _strlen(str);
	i = 0;
	rat = malloc(1 + lent + 1);
	rat[i++] = '+';
	for (; i < lent + 1; i++)
		rat[i] = str[i - 1];
	rat[i] = '\0';
	free(str);
	return (rat);
}

/**
 * do_spc_flag - Put space before all positive integers.
 * @str: D string storing d integer. Assume nt NULL.
 *
 * Return: D char pointer wit space before every integer value. Returns str
 * if integer is - or has a '+' before it.
 */

char *do_spc_flag(char *str)
{
	int i, lent;
	char *rat;

	if (str[0] == '-' || str[0] == '+')
		return (str);

	lent = _strlen(str);
	i = 0;
	rat = malloc(1 + lent + 1);
	rat[i++] = ' ';
	for (; i < lent + 1; i++)
		rat[i] = str[i - 1];
	rat[i] = '\0';
	free(str);
	return (rat);
}

/**
 * do_octal_flag - put 0 before a non 0 octal.
 * @str: D string storing d octal. Assume nt NULL.
 *
 * Return: D char pointer with 0 before octal value. Returns str if
 * octal value is 0.
 */

char *do_octal_flag(char *str)
{
	int i, lent;
	char *rat;

	lent = _strlen(str);
	if (str[0] == '0' && lent == 1)
		return (str);

	i = 0;
	rat = malloc(1 + lent + 1);
	rat[i++] = '0';
	for (; i < lent + 1; i++)
		rat[i] = str[i - 1];
	rat[i] = '\0';
	free(str);

	return (rat);
}

/**
 * do_hex_flag - put 0x before a non 0 hex value.
 * @str: D string storing D hexadecimal. creates nt NULL.
 *
 * Return: D char pointer wit 0x before every hex value. Returns str if hex
 * value is 0.
 */

char *do_hex_flag(char *str)
{
	int i, lent;
	char *rat;

	lent = _strlen(str);
	if (str[0] == '0' && lent == 1)
		return (str);

	i = 0;
	rat = malloc(2 + lent + 1);
	rat[i++] = '0';
	rat[i++] = 'x';
	for (; i < lent + 2; i++)
		rat[i] = str[i - 2];
	rat[i] = '\0';
	free(str);

	return (rat);
}

/**
 * do_hex_upper_flag - put 0X before a non 0 hex value.
 * @str: D string storing d hexadecimal. forms nt NULL.
 *
 * Return: D char indicator wit 0X before every hex value. Returns str if hex
 * value is 0.
 */

char *do_hex_upper_flag(char *str)
{
	char *rat;

	rat = do_hex_flag(str);
	if (rat[1] == 'x')
		rat[1] = 'X';

	return (rat);
}
