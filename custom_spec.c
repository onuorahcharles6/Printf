#include "main.h"
#include <stdlib.h>

/**
 * get_reverse - Get d change duplicate of d string.
 * @args: va_list storing d string.
 * @mods: length modifiers, voided, not used with this specifier
 *
 * Return: char pointer to the reversed string.
 */

char *get_reverse(va_list args, char *mods)
{
	int i;
	int length;
	char *strs, *rat;

	(void)mods;
	strs = va_arg(args, char *);
	length = _strlen(strs);
	rat = malloc(length + 1);
	if (!rat)
		return (NULL);

	for (i = 0; i < length; i++)
		rat[i] = strs[length - i - 1];
	rat[i] = '\0';

	return (rat);
}

/**
 * get_rot - Gets the Rot13'd copy of the string
 * @args: va_list storing d string
 * @mods: length modifiers, voided, not used wit dis specifier
 *
 * Return: char pointer 2 newly given and rot13'd string
 */

char *get_rot(va_list args, char *mods)
{
	int index, length;
	unsigned char temp_c;
	char is_upper;
	char *strs, *rat;

	(void)mods;
	strs = va_arg(args, char *);
	length = _strlen(strs);
	rat = malloc(length + 1);
	if (!rat)
		return (NULL);
	index = 0;
	while (strs[index])
	{
		temp_c = (unsigned char)strs[index];
		if (_isalpha(temp_c))
		{
			is_upper = (temp_c >= 'A' && temp_c <= 'Z');
			temp_c += 13;
			if (is_upper)
			{
				if (temp_c > 'Z')
					temp_c -= 26;
			}
			else
			{
				if (temp_c > 'z')
					temp_c -= 26;
			}
		}
		rat[index] = (char)temp_c;
		index++;
	}
	rat[length] = '\0';
	return (rat);
}

/**
 * get_nonprint_string - uses a pointer 2 string in storage np's
 * @args: va_list 2 get string storing non printables
 * @mods: length modifiers, voided, not used with this specifier
 *
 * Return: pointer 2 newly allocated string containing hex np's
 */

char *get_nonprint_string(va_list args, char *mods)
{
	char *strs, *rat;
	int length, i;

	(void)mods;
	strs = va_arg(args, char *);
	length = 0;
	i = 0;

	while (strs[i])
	{
		if (!is_printable(strs[i]))
		{
			length += 4;
		}
		else
			length++;
		i++;

	}
	i = 0;
	rat = malloc(length + 1);
	if (!rat)
		return (NULL);
	if (!fill_nonprint_buffer(length, rat, strs))
	{
		free(rat);
		return (NULL);
	}

	return (rat);
}

/**
 * get_binary - changes unsigned integer 2 binary replacement.
 * @args: va_list storing d unsigned integer.
 * @mods: length modifiers, nulled, not in used along dis specifier
 *
 * Return: char pointer 2 d binary string. NULL when malloc fails.
 */

char *get_binary(va_list args, char *mods)
{
	unsigned int num;
	int length;
	char *rat;

	(void)mods;
	num = va_arg(args, unsigned int);
	length = get_numerbase_len(num, 2);

	rat = malloc(length + 1);
	if (!rat)
		return (NULL);

	fill_numberbase_buff(num, 2, rat, length);

	return (rat);
}
