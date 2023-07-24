#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    char ch;
    char *str;

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
            format++; 

            switch (*format)
            {
                case 'c':
                    ch = (char)va_arg(args, int);
                    write(1, &ch, 1);
                    printed_chars++;
                    break;
                case 's':
                    str = va_arg(args, char *);
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

