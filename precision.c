#include "main.h"
/**
 * get_precision - Function that calculates the precision for printing
 * @format: Formatted string where the arguments are printed
 * @n: List of arguments to be printed
 * @l: List of arguments
 * Return: Precision
 */
int get_precision(const char *format, int *n, va_list l)
{
int a = *n + 1;
int precision = -1;
if (format[a] != '.')
return (precision);
precision = 0;
for (a += 1 ; format[a] != '\0' ; a++)
{
if (is_digit(format[a]))
{
precision *= 10;
precision += format[a] - '0';
}
else if (format[a] == '*')
{
a++;
precision = va_arg(l, int);
break;
}
else
break;
}
*n = a - 1;
return (precision);
}

