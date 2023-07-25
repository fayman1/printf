#include "main.h"

/* Function prototypes */
void print_buffer(char buffer[], int *buff_ind);
int handle_char(const char *format, int *index, va_list args, char buffer[], int flags, int width, int precision, int size);
int handle_string(const char *format, int *index, va_list args, char buffer[], int flags, int width, int precision, int size);
int handle_percent(const char *format, int *index, va_list args, char buffer[], int flags, int width, int precision, int size);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    int i, printed_chars = 0, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            ++i;

            int (*handler)(const char*, int*, va_list, char[], int, int, int, int) = NULL;
            switch (format[i])
            {
                case 'c':
                    handler = handle_char;
                    break;
                case 's':
                    handler = handle_string;
                    break;
                case '%':
                    handler = handle_percent;
                    break;
                
                default:
                   
                    break;
            }

            if (handler != NULL)
            {
                int printed = handler(format, &i, list, buffer, 0, 0, 0, 0);
                if (printed == -1)
                {
                    va_end(list);
                    return (-1);
                }
                printed_chars += printed;
            }
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);

    return (printed_chars);
}
