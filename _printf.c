#include "main.h"

/**
 * _printf - main function to print in consle
 * @format: char * (array to print and check type)
 *
 * Return: int (number of character printed)
 */
int _printf(const char *format, ...)
{
int count = -1;
int i __attribute__((unused));
va_list args_list __attribute__((unused));
int (*getFunc)(va_list) __attribute__((unused));

if (format != NULL)
{
va_start(args_list, format);

if (format[0] == '%' && format[1] == '\0')
return (-1);

count = 0;
for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
if (format[i +1] == '%')
{
count += _putchar(format[i]);
i++;
}
else if (format[i +1] != '\0')
{
getFunc = get_func(format[i +1]);
count += (getFunc ? getFunc(args_list) :
_putchar(format[i]) + _putchar(format[i +1]));
i++;
}
}
else
count += _putchar(format[i]);
}
va_end(args_list);
}
return (count);
}
