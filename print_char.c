#include "main.h"

/**
 * print_char - returns the character
 * @buff_dest: buffer
 * @arg: list of arguments
 * @buff_count: index of buffer pointer
 * Return: buffer index
 */
int print_char(char *buff_dest, va_list arg, int buff_count)
{
	char c;
	
	while ((c = va_arg(arg, int)) != '\0')
	{
		buff_dest[buff_count] = c;
		buff_count++;
	}
	return (buff_count);
}

