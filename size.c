#include "main.h"
/**
 * get_size - Function that calculates the size to cast the arguments
 * @format: Formatted string where the aguments are printed
 * @i: List of arguments to be printed
 * Return: Precision
 */
int get_size(const char *format, int *i)
{
int a = *i + 1;
int size = 0;
if (format[a] == 'l')
size = S_LONG;
else if (format[a] == 'h')
size = S_SHORT;
if (size == 0)
*i = a - 1;
else
*i = a;
return (size);
}
