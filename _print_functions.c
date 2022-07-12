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

/**
 * print_int - Print integer numbers (int)
 * @argument: Argument integers to be printed
 *
 * Return: Number of integers printed
 */
int print_int(va_list argument)
{
	int integer, div, intPrintCount;
	unsigned int number;

	integer = va_arg(argument, int);
	div = 1;
	intPrintCount = 0;
	if (integer < 0)
	{
		intPrintCount += _putchar('-');
		number = (-1) * integer;
	}
	else
	{
		number = integer;
	}

	while (number / div > 9)
	{
		div *= 10;
	}

	while (div != 0)
	{
		intPrintCount += _putchar('0' + number / div);
		number %= div;
		div /= 10;
	}

	return (intPrintCount);
}
