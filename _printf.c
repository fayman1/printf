#include "main.h"
#include <unistd.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            printed_chars++;
        }
        else
        {
            format++; // Move past the '%'

            // Check for the conversion specifiers
            switch (*format)
            {
                case 'c':
                    {
                        char c = (char)va_arg(args, int);
                        write(1, &c, 1);
                        printed_chars++;
                    }
                    break;
                case 's':
                    {
                        char *str = va_arg(args, char *);
                        if (str != NULL)
                        {
                            int len = 0;
                            while (str[len])
                                len++;
                            write(1, str, len);
                            printed_chars += len;
                        }
                        else
                        {
                            write(1, "(null)", 6);
                            printed_chars += 6;
                        }
                    }
                    break;
                case '%':
                    write(1, "%", 1);
                    printed_chars++;
                    break;
                default:
                    write(1, format - 1, 2);
                    printed_chars += 2;
                    break;
            }
        }

        format++;
    }

    va_end(args);

    return (printed_chars);
}

