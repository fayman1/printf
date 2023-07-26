#include <stdio.h>
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
 * print_address - Helper function to print the address in hexadecimal
 * @ptr: Pointer to be printed as an address
 * Return: Number of characters printed
 */
int print_address(void *ptr)
{
    char hex_chars[] = "0123456789abcdef";
    uintptr_t address = (uintptr_t)ptr;
    int len = 0;

    if (address == 0)
    {
        return (_putchar('0'));
    }

    while (address)
    {
        int index = address & 0xf;
        len += _putchar(hex_chars[index]);
        address >>= 4;
    }

    return (len);
}

/**
 * _printf - Printf function
 * @format: Format string
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
                case 'p': {
                    void *ptr = va_arg(args, void *);
                    p += _putchar('0');
                    p += _putchar('x');
                    p += print_address(ptr);
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
