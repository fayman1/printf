#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 * Return: 1 on success, -1 on error.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _puts - prints a string to stdout
 * @str: The string to print
 * Return: The number of characters printed (excluding the null byte)
 */
int _puts(char *str)
{
	int i = 0;

	while (str && str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * _printf - produces output according to a format
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char *str;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					str = va_arg(args, char *);
					count += _puts(str);
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
					break;
			}
		}
		i++;
	}

	va_end(args);

	return (count);
}

