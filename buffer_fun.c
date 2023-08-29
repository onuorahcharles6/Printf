#include "main.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * create_buff - produces a buffer storage & sets 2 0
 * @bytes: digits of bytes 2 given 4 buffer
 *
 * Return: char pointer 2 starting of buffer
 */
char *create_buff(unsigned int bytes)
{
	char *D_buffs;

	D_buffs = malloc(bytes);
	if (!D_buffs)
		return (NULL);
	/*for (i = 0; i < bytes; i++)*/
	/*	D_buffs[i] = 0; */
	return (D_buffs);
}
/**
 * copy_buff - duplicate a string in2 d buffer
 * @str: string 2 duplicate in2 buffer
 * @help_s: pointer 2 printh_t framework storing buffer, buff_i, etc..
 *
 * Return: number of bytes written
 */
unsigned int copy_buff(char *str, printh_t *help_s)
{
	unsigned int i = 0;

	if (!str || !help_s->buff)
		return (0);
	while (str[i] && help_s->buff_i < BUFF_SIZE)
	{
		help_s->buff[help_s->buff_i] = str[i];
		help_s->buff_i++, i++;
		if (help_s->buff_i == BUFF_SIZE)
		{
			print_buff(help_s->buff, BUFF_SIZE);
			free(help_s->buff);
			help_s->buff = create_buff(BUFF_SIZE);
			if (!help_s->buff)
				return (i);
			help_s->buff_i = 0;
		}
	}
	if (help_s->c != str) /* addresses */
		free(str);
	return (i);
}
/**
 * print_buff - prints d substance of d buffer
 * @buff: buffer 2 print
 * @buff_size: size of buffer in bytes
 *
 * Return: digits of bytes rewritten
 */
unsigned int print_buff(char *buff, unsigned int buff_size)
{
	unsigned int bytes_rewritten;

	bytes_rewritten = write(1, buff, buff_size);
	return (bytes_rewritten);
}

/**
 * free_all - Releases all storage in framework & args.
 * @help_s: D pointing 2 a malloced framework.
 * @args: Pointing 2 va_list.
 *
 * Return: Void.
 */
void free_all(printh_t *help_s, va_list args)
{
	if (help_s)
	{
		if (help_s->flags)
			free(help_s->flags);
		if (help_s->buff)
			free(help_s->buff);
		if (help_s->c)
			free(help_s->c);
		if (help_s->mods)
			free(help_s->mods);
		free(help_s);
	}
	va_end(args);
}
