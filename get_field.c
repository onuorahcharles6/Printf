#include "main.h"
#include <stdlib.h>
/**
 * get_width_precision - brings d width & precision for a format string
 * @help_s: pointer to our helper struct to contain variables for passing
 * @args: va_list of args to advance and use
 *
 * Return: always void
 */

void get_width_precision(printh_t *help_s, va_list args)
{
	char c;
	char dot;

	c = help_s->format[help_s->f_i];
	dot = help_s->dot;

	if (c == '.')
		help_s->dot = 1;
	else if (_isdigit(c))
	{
		c -= '0';
		if (!dot)
			help_s->width = (c + (help_s->width * 10));
		else
			help_s->precision = (c + (help_s->precision * 10));
	}
	else if (c == '*')
	{
		if (!dot)
			help_s->width = va_arg(args, int);
		else
			help_s->precision = va_arg(args, int);
	}
}

/**
 * do_width - Applies spaces or '0's in front of strings if their length is
 * less than the specified minimum width.
 * @str: The string to modify.
 * @width: The minimum width the string should have.
 * @zero: if 1, pad with 0's, otherwise pad with space.
 *
 * Return: char pointer to the new string.
 */

char *do_width(char *str, int width, int zero)
{
	int len, i, j, stop;
	char *rat;
	char pad, sign;

	stop = 0;
	len = _strlen(str);
	if (len > width)
		return (str);
	ret = malloc(width + 1);
	i (!rat)
		return (NULL);
	if (zero)
	{
		pad = '0';
		sign = str[0];
		if (str[0] == '+' || str[0] == '-' || str[0] == ' ')
		{
			rat[0] = sign;
			stop = 1;
		}
		if (str[0] == '0' && str[1] == 'x')
		{
			rat[0] = '0';
			rat[1] = 'x';
			stop = 2;
		}
	}
	else
	{
		pad = ' ';
	}
	i = width;
	j = len;
	while (j >= stop)
		rat[i--] = str[j--];

	while (i >= stop)
		rat[i--] = pad;
	free(str);
	return (rat);
}

/**
 * do_shift - Collects a string & if its' length is smaller than width, add n
 * spaces after d string where n is the difference between length and width.
 * @str: Pointer 2 d passed string.
 * @width: Minimum digits of characters 2 b printed. if length < width, pad
 * d end of d string wit spaces using d discrepancy.
 *
 * Return: D left clerified string.
 */
char *do_shift(char *str, int width)
{
	int len, i;
	char *rat;

	len = _strlen(str);
	if (len > width)
		return (str);
	rat = malloc(width + 1);
	if (!rat)
		return (NULL);
	for (i = 0; str[i]; i++)
		rat[i] = str[i];
	for (; i < width; i++)
		rat[i] = ' ';
	rat[i] = '\0';
	free(str);
	return (rat);
}
