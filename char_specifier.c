#include "main.h"
#include <stdlib.h>
/**
 * get_char - acquires pointer 2 an arraystoring char & null byte
 * @args: va_list to get discussion 4rm of type char
 * @mods: length modifiers, voided, nt used with this specifier
 *
 * Return: pointer to array containing char and null byte
 */
char *get_char(va_list args, char *mods)
{
	char *strs;
	char c;

	(void)mods;
	c = va_arg(args, int);
	strs = malloc(2);

	if (!strs)
		return (NULL);
	if (c)

		strs[0] = c;
	else
		strs[0] = '\0';
	strs[1] = '\0';
	return (strs);
}
/**
 * get_string - acquire a pointer 2 a string, null stop
 * @args: va_list to get discussion of char
 * @mods: length viewers, voided, nt in used with specifier*
 *
 * Return: pointer 2 starting of string
 */
char *get_string(va_list args, char *mods)
{
	char *str;
	char *reth;

	(void)mods;
	str = va_arg(args, char *);

	if (str)
	{
		reth = malloc(_strlen(str) + 1);
		if (!reth)
			return (NULL);
		ret = _strcpy(reth, str);
	}
	else
	{
		reth = malloc(6 + 1);
		if (!reth)
			return (NULL);
		reth = _strcpy(reth, "(null)");
	}
	return (reth);
}
/**
 * get_percent - uses pointer 2 a string mainly storing "%\0"
 * @args: va_list needed 4 working pointer, voided, nt used
 * @mods: lent magnifiers, voided, nt working wit dis specifier
 *
 * Return: pointer 2 string having %
 */
char *get_percent(va_list args, char *mods)
{
	char *strs;

	(void)mods;
	if (args)
	{
	}

	strs = malloc(2);
	if (!strs)
		return (NULL);
	strs[0] = '%';
	strs[1] = '\0';

	return (strs);
}
/**
 * insert_null_char - Puts a nullbyte in2 d buffer  implementing width
 * or left change.
 * @help_s: pointer 2 d framework holding width & accuracy code.
 *
 * Return: null.
 */
void insert_null_char(printh_t *help_s)
{
	int i, shift_flag, width;

	shift_flag = help_s->flags[3];
	width = help_s->width;

	if (shift_flag)
	{
		help_s->buffs[help_s->buffs_i++] = '\0';
		help_s->buffs_len++;
		for (i = 0; i < width - 1; i++)
		{
			help_s->buffs[help_s->buffs_i++] = ' ';
			help_s->buffs_len++;
		}
	}
	else
	{
		for (i = 0; i < width - 1; i++)
		{
			help_s->buffs[help_s->buffs_i++] = ' ';
			help_s->buffs_len++;
		}
		help_s->buffs[help_s->buffs_i++] = '\0';
		help_s->buffs_len++;
	}
}
