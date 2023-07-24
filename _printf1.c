#include "main.h"
#include <unistd.h> // Include this for the write function

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
            write(1, format, 1); // Write to stdout
            printed_chars++;
        }
        else
        {
            format++; // Move past the '%'

            // Check for the conversion specifiers
            switch (*format)
            {
                case 'c':
                    ch = (char)va_arg(args, int);
                    write(1, &ch, 1); // Write the character to stdout
                    printed_chars++;
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (str != NULL)
                    {
                        int len = 0;
                        while (str[len])
                            len++;
                        write(1, str, len); // Write the string to stdout
                        printed_chars += len;
                    }
                    else
                    {
                        write(1, "(null)", 6); // Write "(null)" to stdout
                        printed_chars += 6;
                    }
                    break;
                case '%':
                    write(1, "%", 1); // Write "%" to stdout
                    printed_chars++;
                    break;
                default:
                    write(1, format - 1, 2); // Write "%" and the character following "%" to stdout
                    printed_chars += 2;
                    break;
            }
        }

        format++;
    }

    va_end(args);

    return (printed_chars);
}

