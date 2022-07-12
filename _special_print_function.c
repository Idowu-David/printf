#include "main.h"

/**
 * print_bin - Prints binary form of unsigned int
 * @argument: Argument unsigned int to be converted to bin
 *
 * Return: Number of binary bits printed
 */
int print_bin(va_list argument)
{
	int locIndex, biNum, numSize, binPrtCount;
	unsigned long int msb;

	biNum = va_arg(argument, int);
	numSize = (sizeof(int) * 8) - 1;
	binPrtCount = 0;
	msb = 1;
	msb = msb << numSize;

	for (locIndex = numSize; locIndex >= 0; locIndex--)
	{
		if ((msb & biNum) == msb)
			break;

		msb = msb >> 1;
	}

	if (msb == 0)
	{
		_putchar('0');
		return (1);
	}

	while (msb != 0)
	{
		if ((msb & biNum) == msb)
			_putchar('1');

		else
			_putchar('0');

		msb = msb >> 1;

		binPrtCount++;
	}

	return (binPrtCount);
}

/**
 * print_revStr - Print string in reverse (rev)
 * @argument: Argument string to be revered
 *
 * Return: Number of reversed strings printed
 */
int  print_revStr(va_list argument)
{
	int locIndex, revStrPrtCount;
	char *string;

	string = va_arg(argument, char *);
	locIndex = revStrPrtCount = 0;
	while (string[locIndex] != '\0')
	{
		locIndex++;
	}
	revStrPrtCount = locIndex;
	locIndex--;
	while (locIndex >= 0)
	{
		_putchar(string[locIndex]);
		locIndex--;
	}

	return (revStrPrtCount);
}
