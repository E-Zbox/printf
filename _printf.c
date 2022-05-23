#include "main.h"
#include <stdio.h>

/**
 * check_for_specifiers - checks if there is a valid format specifier
 * @format: const char * (possible format specifier)
 *
 * Return: static int *
 */
static int (*check_for_specifiers(const char *format))(va_list)
{
	unsigned int i;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"u", print_u},
		{"b", print_b},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

	for (i = 0; p[i].t != NULL; i++)
		if (*(p[i].t == *format))
			break;

	return (p[i].f);
}

/**
 * _printf - alternative to printf
 * @format - char * (list of argument types passed to the function)
 *
 * Return: int (number of characters printed)
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list args_list;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(args_list, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!format[i])
			return (count);
		f = check_for_specifiers(&format[i + 1]);
		if (f != NULL)
		{
			count += f(args_list);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(formt[i]);
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
		count++;
	}
	va_end(args_list);
	return (count);
}
