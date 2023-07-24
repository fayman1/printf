#include "main.h"

/**
 * print_char - returns the character
 * @buff_dest: buffer
 * @arg: list of arguments
 * @buff_count: index of buffer pointer
 * Return: buffer index
 */
int print_char(char *buff_dest, va_list arg, int buff_count)
{
    char c;

    while ((c = va_arg(arg, int)) != '\0')
    {
        if (c == 'd' || c == 'i')
        {
            int num = va_arg(arg, int);
            int num_length = 0;
            char temp_buff[12];

            if (num < 0)
            {
                buff_dest[buff_count] = '-';
                buff_count++;
                num = -num;
            }

            do {
                temp_buff[num_length++] = '0' + (num % 10);
                num /= 10;
            } while (num > 0);

            for (int i = num_length - 1; i >= 0; i--)
            {
                buff_dest[buff_count] = temp_buff[i];
                buff_count++;
            }
        }
        else
        {
            buff_dest[buff_count] = c;
            buff_count++;
        }
    }

    return (buff_count);
}

