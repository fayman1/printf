#include "main.h"

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formatted string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	conver_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	va_list arg_list;
	
	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			int i = 0;

			while (f_list[i].specifier)
			{
				if (*format == *(f_list[i].specifier))
				{
					printed_chars += f_list[i].f(arg_list);
					break;
				}
				i++;
			}

			if (!f_list[i].specifier)
			{
				printed_chars += _putchar('%');
				if (*format)
					printed_chars += _putchar(*format);
			}
		}
		else
		{
			printed_chars += _putchar(*format);
		}

		format++;
	}

	va_end(arg_list);
	return (printed_chars);
}

