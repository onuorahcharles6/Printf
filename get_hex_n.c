#include "main.h"
#include <stdlib.h>
/**
 * get_hex_n - acquires a string Dat is D hex depictation of d integer.
 * @num: D unsigned integer.
 *
 * Return: char arrowed 2 d string depictation. NULL if malloc fails.
 */
char *get_hex_n(unsigned int num)
{
	int length;
	char *rat;

	length = getting_numbase_len(num, 16);
	rat = malloc(length + 1);
	if (!rat)
		return (NULL);

	filling_numbase_buff(num, 16, ret, length);
	return (rat);
}
/**
 * get_hex_long_n - acquires a string dat is hex depictation of d lent int
 * @num: d lent unsigned integer 2 changed
 *
 * Return: char arrowed 2 d string depictation. NULL if malloc fails
 */
char *get_hex_long_n(unsigned long int num)
{
	int length;
	char *rat;

	length = getting_longnumbase_len(num, 16);
	rat = malloc(length + 1);
	if (!rat)
		return (NULL);
	filling_longnumbase_buff(num, 16, rat, length);
	return (rat);
}
