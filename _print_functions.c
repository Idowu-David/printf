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

/**
 * print_str - Print string (str)
 * @argument: Argument string to be printed
 *
 * Return: Number of characters in string printed
 */

int print_str(va_list argument)
{
	int locIndex, strPrintCount;
	char *string;

	string = va_arg(argument, char *);
	if (string == NULL)
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	locIndex = strPrintCount = 0;
	while (string[locIndex])
	{
		strPrintCount += _putchar(string[locIndex]);
		locIndex++;
	}

	return (strPrintCount);
}
