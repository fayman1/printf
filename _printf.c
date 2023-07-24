#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */


int _printf(const char *format, ...)
{
    if (!format)
        return -1;

    int buff_count = 0;
    char buffer[2000];
    va_list arg;
    va_start(arg, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            char specifier = *format;

            switch (specifier)
            {
                case 'c': buff_count = print_char(buffer, arg, buff_count); break;
                case 's': buff_count = print_str(buffer, arg, buff_count); break;
                case 'i': case 'd': buff_count = print_int(buffer, arg, buff_count); break;
                case '%': buff_count = print_perc(buffer, arg, buff_count); break;
                case 'b': buff_count = print_bin(buffer, arg, buff_count); break;
                case 'o': buff_count = print_oct(buffer, arg, buff_count); break;
                case 'x': buff_count = print_hex(buffer, arg, buff_count); break;
                case 'X': buff_count = print_X(buffer, arg, buff_count); break;
                case 'u': buff_count = print_uint(buffer, arg, buff_count); break;
                case 'R': buff_count = print_R13(buffer, arg, buff_count); break;
                case 'r': buff_count = print_rev(buffer, arg, buff_count); break;
                default:
                    buffer[buff_count++] = '%';
                    if (*format)
                        buffer[buff_count++] = *format;
                    break;
            }
        }
        else
        {
            buffer[buff_count++] = *format;
        }

        format++;
    }

    va_end(arg);
    buffer[buff_count] = '\0';
    print_buff(buffer, buff_count);
    return (buff_count);
}

