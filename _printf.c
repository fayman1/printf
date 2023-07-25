#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int p = 0;
	va_list args;
	char c;
	char *str;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			p++;
		}
		else
		{
			format++;

			switch (*format)
			{
				case 'c':
					c = (char)va_arg(args, int);
					write(1, &c, 1);
					p++; break;
				case 's':
					str = va_arg(args, char *);
					  if (str != NULL)
					  {
						  int len = 0;

						  while (str[len])
							  len++;
						  write(1, str, len);
						  p += len;
					  }
					  else
					  {
						  write(1, "(null)", 6);
						  p += 6;
					  } break;
				case '%':
					  write(1, "%", 1);
					  p++; break;
				default:
					  write(1, format - 1, 2);
					 p += 2; break;
			}
		}
		format++;
	}
	va_end(args);
	return (p);
}

