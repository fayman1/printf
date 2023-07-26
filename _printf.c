#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _printf - Entry point
 *
 * Description: 'a program to emulate the functions of printf'
 * @format: char pointer to a format string that holds the text
 * Return: strlen
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int j;
	int di, id;
	int strlen = 0;
	char *s;
	va_list args;
	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			while (format[i] == '%')
			{
				i++;
				if (format[i] == '%')
				{
					break;
				}
				else if (format[i] == '\0')
				{
					strlen++;
					return (-1);
				}
				else if (format[i] == ' ')
				{
					return (-1);
					strlen++;
					i++;
				}
				else
				{
					switch (format[i])
					{
						case 's':
							i++;
							s = va_arg(args, char *);
							if (s == NULL)
							{
								_putchar('(');
								_putchar('n');
								_putchar('u');
								_putchar('l');
								_putchar('l');
								_putchar(')');
								strlen += 6;
								break;
							}
							strlen += _strlen(s);

							for (j = 0; s[j] != '\0'; j++)
							{
								_putchar(s[j]);
							}
							break;
						case 'c':
							i++;
							_putchar(va_arg(args, int));
							break;
						case 'd':
							i++;
							di = va_arg(args, int);
							strlen += print_integer(di);
							break;
						case 'i':
							i++;
							id = va_arg(args, int);
							strlen += print_integer(id);
							break;
						default:
							_putchar('%');
							strlen++;
					}
				}
			}
			_putchar(format[i]);
			strlen++;
		}
	}
	va_end(args);
	return (strlen);
}

