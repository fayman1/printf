#include "main.h"

/**
 * _printf - mimics library function printf
 * @format: input string storing all desired characters
 * Return: no of characters printed
 */
int _printf(const char *format, ...)
{
	int output;
	conver_t f_list[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"u", un_int},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	const char *ptr = format;
	do {
		if (*ptr != '%' || *(ptr + 1) == '\0') {
			putchar(*ptr);
			output++;
		} else {
			ptr++;
		}
		ptr++;
	} while (*ptr != '\0');

	va_end(arg_list);
	return (output);
}

