#include "main.h"
/**
 * get_precision - Function that calculates the precision for printing
 * @format: Formatted string where the arguments are printed
 * @i: List of arguments to be printed
 * @list: List of arguments
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list list)
{
int a = *i + 1;
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
precision = va_arg(list, int);
break;
}
else
break;
}
*i = a - 1;
return (precision);
}

