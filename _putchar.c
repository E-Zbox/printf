#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: char
 *
 * Return: int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
