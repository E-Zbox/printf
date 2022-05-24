#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/**
 * struct op - various structure types
 * @c: char (type to print)
 * @f: int *(va_list) (function to handle print)
 *
 */
typedef struct op
{
	char *c;
	int (*f)(va_list);
} op_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list c);
int print_s(va_list s);
int print_i(va_list i);
int print_d(va_list d);
int print_u(va_list u);
int print_b(va_list b);
int print_o(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int (*get_func(char s))(va_list args_list);
/* int print_p(va_list p);
int print_S(va_list S);
int print_r(va_list r);
int print_R(va_list RA);
*/

#endif
