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

/**
 * print_rot13 - Print Integer
 * @argument: Argument rot13 to be processed
 *
 * Return: Number of rot13 characters printed
 */

int print_rot13(va_list argument)
{
	int rot13PrtCount;
	size_t index;
	char *string;
	char encrypt;

	string = va_arg(argument, char *);
	rot13PrtCount = 0;
	for (index = 0; index < strlen(string); index++)
	{
		encrypt = rotate(string[index], 13);
		rot13PrtCount += _putchar(encrypt);
	}
	return (rot13PrtCount);
}

/**
 * rotate - Encrypt a character by rotation
 * @c: Character to be encrypted
 * @key: Key to encrypt or rotate the character
 *
 * Return: Encrypted character
 */

char rotate(char c, int key)
{
	if (islower(c))
	{
		if (c + key > 'z')
		{
			return (((c + key) - 'z') + 96);
		}
		return (c + key);
	}
	else if (isupper(c))
	{
		if (c + key > 'Z')
		{
			return (((c + key) - 'Z') + 64);
		}
		return (c + key);
	}
	else
	{
		return (c);
	}
}
