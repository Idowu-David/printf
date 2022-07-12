#include "main.h"

/**
 * _putchar - Prints an ASCII character
 * @c: Character to be printed
 *
 * Return: Zero(0) upon success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
