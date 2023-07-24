#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */

int print_char(char *buffer, va_list arg, int buff_count) {
    char c = va_arg(arg, int);
    buffer[buff_count] = c;
    return (buff_count + 1);
}

int print_str(char *buffer, va_list arg, int buff_count) {
    char *str = va_arg(arg, char *);
    int i = 0;
    while (str[i] != '\0') {
        buffer[buff_count + i] = str[i];
        i++;
    }
    return (buff_count + i);
}

int print_int(char *buffer, va_list arg, int buff_count) {
    return (buff_count + snprintf(buffer + buff_count, 12, "%d", va_arg(arg, int)));
}

int print_perc(char *buffer, va_list arg, int buff_count) {
    buffer[buff_count] = '%';
    return (buff_count + 1);
}

void print_buff(char *buffer, int buff_count) {
    for (int i = 0; i < buff_count; i++)
        _putchar(buffer[i]);
}

int _printf(const char *format, ...) {
    int i = 0, j = 0, buff_count = 0, prev_buff_count = 0;
    char buffer[2000];
    va_list arg;
    call_t container[] = {
        {'c', print_char}, {'s', print_str}, {'i', print_int}, {'d', print_int},
        {'%', print_perc}, // Add other conversion specifiers here if needed...
        {'\0', NULL}
    };

    if (!format)
        return (-1);

    va_start(arg, format);

    while (format && format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            prev_buff_count = buff_count;

            for (j = 0; container[j].t != '\0'; j++) {
                if (format[i] == '\0')
                    break;

                if (format[i] == container[j].t) {
                    buff_count = container[j].f(buffer, arg, buff_count);
                    break;
                }
            }

            if (buff_count == prev_buff_count && format[i]) {
                i--;
                buffer[buff_count] = format[i];
                buff_count++;
            }
        } else {
            buffer[buff_count] = format[i];
            buff_count++;
        }

        i++;
    }

    va_end(arg);

    buffer[buff_count] = '\0';
    print_buff(buffer, buff_count);

    return (buff_count);
}

