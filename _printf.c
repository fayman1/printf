#include <stdarg.h>
#include <stdio.h>

int print_char(char *buffer, va_list arg, int buff_count)
{
	char c = va_arg(arg, int);
	
	buffer[buff_count] = c;
	return (buff_count + 1);
}

int print_str(char *buffer, va_list arg, int buff_count)
{
	char *str = va_arg(arg, char *);
	int i = 0;
	
	while (str[i] != '\0') {
		buffer[buff_count + i] = str[i];
		i++;
	}
	return (buff_count + i);
}

int print_int(char *buffer, va_list arg, int buff_count)
{
	return (buff_count + snprintf(buffer + buff_count, 12, "%d", va_arg(arg, int)));
}

int print_perc(char *buffer, va_list arg, int buff_count)
{
	buffer[buff_count] = '%';
	return (buff_count + 1);
}

int print_bin(char *buffer, va_list arg, int buff_count)
{
	unsigned int num = va_arg(arg, unsigned int);
	int i = 0;
	
	if (num == 0)
		buffer[buff_count] = '0';
	else {
		while (num > 0) {
			buffer[buff_count + i] = (num & 1) + '0';
			num >>= 1;
			i++;
		}
	}
	return (buff_count + i);
}

int print_oct(char *buffer, va_list arg, int buff_count)
{
	unsigned int num = va_arg(arg, unsigned int);
	int i = 0;
	
	if (num == 0)
		buffer[buff_count] = '0';
	else {
		while (num > 0) {
			buffer[buff_count + i] = (num & 7) + '0';
			num >>= 3;
			i++;
		}
	}
	return (buff_count + i);
}

int print_hex(char *buffer, va_list arg, int buff_count)
{
	unsigned int num = va_arg(arg, unsigned int);
	int i = 0;
	
	if (num == 0)
		buffer[buff_count] = '0';
	else {
		while (num > 0) {
			
			int rem = num % 16;
			
			buffer[buff_count + i] = (rem < 10) ? (rem + '0') : (rem - 10 + 'a');
			num /= 16;
			i++;
		}
	}
	return (buff_count + i);
}

int print_X(char *buffer, va_list arg, int buff_count)
{
	unsigned int num = va_arg(arg, unsigned int);
	int i = 0;
	
	if (num == 0)
		buffer[buff_count] = '0';
	else {
		while (num > 0) {
			int rem = num % 16;
			buffer[buff_count + i] = (rem < 10) ? (rem + '0') : (rem - 10 + 'A');
			num /= 16;
			i++;
        }
    }
    return (buff_count + i);
}

int print_uint(char *buffer, va_list arg, int buff_count) {
    unsigned int num = va_arg(arg, unsigned int);
    int i = 0;
    if (num == 0)
        buffer[buff_count] = '0';
    else {
        while (num > 0) {
            buffer[buff_count + i] = (num % 10) + '0';
            num /= 10;
            i++;
        }
    }
    return (buff_count + i);
}

int print_R13(char *buffer, va_list arg, int buff_count) {
    char *str = va_arg(arg, char *);
    int i = 0;
    char rot13[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char ROT13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    while (str[i] != '\0') {
        char c = str[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            int index = (c >= 'a' && c <= 'z') ? c - 'a' : c - 'A';
            c = (c >= 'a' && c <= 'z') ? ROT13[index] : rot13[index];
        }
        buffer[buff_count + i] = c;
        i++;
    }
    return (buff_count + i);
}

int print_rev(char *buffer, va_list arg, int buff_count) {
    char *str = va_arg(arg, char *);
    int i = 0, len = 0;
    while (str[len] != '\0')
        len--;
    while (len >= 0) {
        buffer[buff_count + i] = str[len];
        i++;
        len--;
    }
    return (buff_count + i);
}

void print_buff(char *buffer, int buff_count) {
    for (int i = 0; i < buff_count; i++)
        putchar(buffer[i]);
}

int _printf(const char *format, ...) {
    int i = 0, j = 0, buff_count = 0, prev_buff_count = 0;
    char buffer[2000];
    va_list arg;
    call_t container[] = {
        {'c', print_char}, {'s', print_str}, {'i', print_int}, {'d', print_int},
        {'%', print_perc}, {'b', print_bin}, {'o', print_oct}, {'x', print_hex},
        {'X', print_X}, {'u', print_uint}, {'R', print_R13}, {'r', print_rev},
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

