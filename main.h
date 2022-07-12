#ifndef _MAIN_H
#define _MAIN_H
/* All Standard Libraries */
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>

/* Type Definition of Structure */
/**
 * struct format - Data type of a structured format
 * @specifier: Specifier formats
 * @print_func: Print functions
 */

typedef struct format
{
        char *specifier;
        int (*print_func)(va_list arg);
} formatType;

/* General Functions */
int _putchar(char c);
int _printf(const char *format, ...);

/* General Functions */
int _putchar(char c);
int _printf(const char *format, ...);

/* Other Functions */
int validate_format(const char *format, va_list arg, formatType *specStruct);

/* Type Print Functions */
int print_char(va_list argument);
int print_str(va_list argument);
int print_int(va_list argument);
#endif
