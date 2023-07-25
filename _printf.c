#include <unistd.h>
#include <stdarg.h>

/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 * Return: 1 on success, -1 on error.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _puts - prints a string to stdout
 * @str: The string to print
 * Return: The number of characters printed (excluding the null terminator)
 */
int _puts(char *str)
{
    int i = 0;

    if (str == NULL)
    {
        _putchar('(');
        _putchar('n');
        _putchar('u');
        _putchar('l');
        _putchar('l');
        _putchar(')');
        return (6);
    }

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }

    return (i);
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

            switch (*format)
            {
                case 'c':
                    p += _putchar((char)va_arg(args, int));
                    break;
                case 's':
                    p += _puts(va_arg(args, char *));
                    break;
                case '%':
                    p += _putchar('%');
                    break;
                default:
                    p += _putchar('%');
                    p += _putchar(*format);
                    break;
            }
        }
        else
        {
            p += _putchar(*format);
        }

        format++;
    }
    va_end(args);
    return (p);
}

