#include "main.h"

int _printf(const char *format, ...)
{
    int i, printed_chars = 0;
    int buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format && format[i] != '\0'; i++)
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
            /* Rest of your code to handle format specifiers and arguments... */
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);

    return (printed_chars);
}

void print_buffer(char buffer[], int *buff_ind)
{
    /* Update the function to check if the buffer is not empty */
    if (*buff_ind > 0)
    {
        /* Add a while loop to handle printing the buffer in chunks of BUFF_SIZE */
        int i = 0;
        while (i < *buff_ind)
        {
            int chars_to_print = (*buff_ind - i) > BUFF_SIZE ? BUFF_SIZE : (*buff_ind - i);
            write(1, &buffer[i], chars_to_print);
            i += chars_to_print;
        }
    }

    *buff_ind = 0;
}

