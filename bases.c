#include <stdlib.h>
#include "main.h"

/**
 * get_numbase_len - uses lent of buffer used 4 an unsigned int
 * @num: digit 2 acquire lent needed 4
 * @base: base of digit show needed by buffer
 *
 * Return: integer loaded lent of buffer in use (does not have null value)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int lens = 1; /* all digits has at least 1 digit */

	while (num > base - 1)
	{
		lens++;
		num /= base;
	}
	return (lens);
}
/**
 * get_longnumbase_len - gets length of buff needed for long unsigned int
 * @num: number to get length needed for
 * @base: base of number representation that will be used by buffer
 *
 * Return: integer containing length of buffer needed ( no null byte )
 */
int get_longnumbase_len(unsigned long int num, unsigned int base)
{
	int lens = 1; /* all digits has at least 1 digit */

	while (num > (unsigned long int)base - 1)
	{
		lens++;
		num /= (unsigned long int)base;
	}
	return (lens);
}
/**
 * fill_numbase_buff - loads buffer wit accurate digit up 2 base 36
 * @num: digit 2 change 2 string given base
 * @base: bases of digit utilizes in changing, shows up to base 36
 * @buff: buffer 2 loads wit answer of changing
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int ram, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		ram = num % base;
		if (ram > 9) /* return lowercase ascii value representation */
			buff[i] = ram + 87; /* 10 will b a, 11 = b, ... */
		else
			buff[i] = ram + '0';
		num /= base;
		i--;
	}
}
/**
 * fill_longnumbase_buff - loads buffer wit accurate digit up 2 base 36
 * @num: lent int 2 change 2 string of given base
 * @base: bases of digit utilizes in changing, shows up to base 36
 * @buff: buffer 2 loads wit answer of change, nt main printf buffer
 * @buff_size: size of buffer in bytes
 *
 * Return: still void.
 */
void fill_longnumbase_buff(unsigned long int num, unsigned int base,
				char *buff, int buff_size)
{
	int ram, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		ram = num % (unsigned long int)base;
		if (ram > 9)
			buff[i] = ram + 87;
		else
			buff[i] = ram + '0';
		num /= (unsigned long int)base;
		i--;
	}
}
