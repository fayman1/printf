#include "main.h"

/**
 * print_char - returns the character
 * @buff_dest: buffer
 * @arg: list of arguments
 * @buff_count: index of buffer pointer
 * Return: index
 */
int print_char(char *buff_dest, va_list arg, int buff_count)
{
	char ch = va_arg(arg, int);

	buff_dest[buff_count] = ch;

	return (++buff_count);
}
