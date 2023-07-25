#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct convert - ....
 * @sym: .....
 * @f: ......
 */
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

int _printf(const char *format, ...);
int resolve(const char *format, conver_t f_list[], va_list arg_list);
int put_char(char);
int print_char(va_list);
int print_str(va_list);
int rot13(va_list);
int print_int(va_list);
int print_num(va_list);
int un_int(va_list);
int print_rev(va_list arg);
char *rev_str(char *);
int print_un_num(unsigned int);
char *_memcpy(char *dest, char *str, unsigned int n);

#endif
