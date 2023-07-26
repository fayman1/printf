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
            {
                p += _putchar('%');
                break;
            }

            switch (*format)
            {
                case 'c':
                    p += _putchar((char)va_arg(args, int));
                    break;
                case 's': {
                    char *str = va_arg(args, char *);
                    if (str == NULL) {
                        p += _putchar('(');
                        p += _putchar('n');
                        p += _putchar('u');
                        p += _putchar('l');
                        p += _putchar('l');
                        p += _putchar(')');
                    } else {
                        int i = 0;
                        while (str[i]) {
                            p += _putchar(str[i]);
                            i++;
                        }
                    }
                    break;
                }
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

