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
