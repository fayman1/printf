#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - Print a single character to stdout
 * @c: The character to print
 * Return: Number of characters printed
 */
int print_char(char c)
{
    write(1, &c, 1);
    return (1);
}

/**
 * print_string - Print a string to stdout
 * @str: The string to print
 * Return: Number of characters printed
 */
int print_string(char *str)
{
    if (str != NULL)
    {
        int len = 0;

        while (str[len])
            len++;
        write(1, str, len);
        return (len);
    }
    else
    {
        write(1, "(null)", 6);
        return (6);
    }
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int p = 0;
    va_list args;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            if (*format == '\0')
                return (-1); // Handle case when '%' is at the end of the format string

            if (*format == 'c')
            {
                p += print_char((char)va_arg(args, int));
            }
            else if (*format == 's')
            {
                p += print_string(va_arg(args, char *));
            }
            else if (*format == '%')
            {
                p += print_char('%');
            }
            else
            {
                p += print_char('%');
                p += print_char(*format);
            }
        }
        else
        {
            p += print_char(*format);
        }

        format++;
    }

    va_end(args);
    return (p);
}

