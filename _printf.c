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

/**
 * validate_format - Function that produces output according to a format.
 * @format: Pointer
 * @arg: va_list
 * @specStruct: struct
 * Return: Always 0
 */
int validate_format(const char *format, va_list arg, formatType *specStruct)
{
	int i = 0, indexB = 0, prtCount = 0;

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%' && (format[i + 1] == ' ' || format[i + 1] != '%'))
		{
			if (format[i + 1] == ' ')
			{
				while (format[i + 1] == ' ')
					i++;
			}
			while (indexB < 7)
			{
				if (specStruct[indexB].specifier[0] == format[i + 1])
				{
					prtCount += specStruct[indexB].print_func(arg);
					i++;
					break;
				} indexB++;
			}
			if (indexB == 6)
				prtCount += _putchar('%');
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			prtCount += _putchar('%');
			i++;
		}
		else
		{
			prtCount += _putchar(format[i]);
		} i++, indexB = 0;
	}
	return (prtCount);
}
