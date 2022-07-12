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
	int indexA = 0, indexB = 0, prtCount = 0;

	while (format && format[indexA])
	{
		if (format[indexA] == '%' && format[indexA + 1] == '\0')
			return (-1);
		if (format[indexA] == '%' && (format[indexA + 1] == ' ' || format[indexA + 1] != '%'))
                {
			if (format[indexA + 1] == ' ')
			{
				while (format[indexA + 1] == ' ')
					indexA++;
			}
			while (indexB < 7)
			{
				if (specStruct[indexB].specifier[0] == format[indexA + 1])
				{
					prtCount += specStruct[indexB].print_func(arg);
					indexA++;
					break;
				} indexB++;
			}
			if (indexB == 6)
				prtCount += _putchar('%');
		}
		else if (format[indexA] == '%' && format[indexA + 1] == '%')
		{
			prtCount += _putchar('%');
			indexA++;
		}
		else
		{
			prtCount += _putchar(format[indexA]);
		} indexA++, indexB = 0;
	}
	return (prtCount);
}
