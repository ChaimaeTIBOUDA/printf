#include "main.h"
/**
 * get_size - Function that calculates the size to cast the arguments
 * @format: Formatted string where the aguments are printed
 * @i: List of arguments to be printed
 * Return: Precision
 */
int get_size(cont char *format, int *i)
{
int a = *i + 1;
int b = 0;
if (format[a] == 'l'
b = S_LONG;
else if (format[a] == 'h')
b = S_SHORT;
if (b == 0)
*i = a - 1;
else
*i = a;
return (b);
}
