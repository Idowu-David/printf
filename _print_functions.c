#include "main.h"

/**
 * print_char - Print character (char)
 * @argument: Argument character to be printed
 *
 * Return: Number of characters printed
 */

int print_char(va_list argument)
{
        int charPrintCount = 0;

        charPrintCount = _putchar(va_arg(argument, int));

        return (charPrintCount);
}
