#include "main.h"

/**
 * _printf - Prints to standard output like printf function
 * @format: Format to be printed
 *
 * Return: Always 0
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int printCount;

	formatType specStruct[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_int},
		{"d", print_int},
		{"b", print_bin},
		{"r", print_revStr},
		{"R", print_rot13},
	};
	printCount = 0;
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	printCount = validate_format(format, arg, specStruct);
	va_end(arg);

	return (printCount);
}
