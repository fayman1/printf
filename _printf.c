#include <unistd.h>
#include <stdarg.h>

/*;*
 * print_char - Print a single character to stdout
 * @c: The character to print
 * Return: Number of characters printed (always 1)
 */
int print_char(char c)
{
    write(1, &c, 1);
    return (1);
}

/**
 * print_string - Print a string to stdout
 * @str: The string to print
 * Return: Number of characters printed (excluding the null byte used to end output to strings)
 */
int print_string(char *str)
{
    if (str == NULL) {
        write(1, "(null)", 6);
        return (6);
    }

    int len = 0;
    while (str[len])
        len++;

    write(1, str, len);
    return (len);
}

/**
 * _printf - Printf function
 * @format: Format string.
 * Return: Number of characters printed (excluding the null byte used to end output to strings)
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

            switch (*format)
            {
                case 'c':
                    p += print_char((char)va_arg(args, int));
                    break;
                case 's':
                    p += print_string(va_arg(args, char *));
                    break;
                case '%':
                    p += print_char('%');
                    break;
                default:
                    p += print_char('%');
                    p += print_char(*format);
                    break;
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

