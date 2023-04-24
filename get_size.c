#include "main.h"
/**
 * get_size - size to cast argument
 * @format: string to print arguments
 * @i: list of arguments
 * Return: precision
 */
int get_size(const char *format, int *i)
{
	int c = *i + 1;
	int size = 0;

	if (format[c] == 'I')
		size = S_LONG;
	else if (format[c] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = c - 1;
	else
		*i = c;
	return (size);
}
