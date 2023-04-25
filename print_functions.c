#include "main.h"
/**
 * print_char - Function that prints a char
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char n = va_arg(types, int);
return (handle_write_char(n, buffer, flags, width, precision, size));
}
/**
 * print_string - Function that print a string
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int length = 0, m;
char *str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
str = "(null)";
if (precision >= 6)
str = "      ";
}
while (str[length] != '\0')
length++;
if (precision >= 0 && precision < length)
length = precision;
if (width > length)
{
if (flags & F_MINUS)
{
write(1, &str[0], length);
for (m = width - length ; m > 0 ; m--)
write(1, " ", 1);
return (width);
}
else
{
for (m = width - length ; m > 0 ; m--)
write(1, " ", 1);
write(1, &str[0], length);
return (width);
}
}
return (write(1, str, length));
}
/**
 * print_percent - Function that prints a percent sign
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
return (write(1, "%%", 1));
}
/**
 * print_int - Function that prints int
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int n = BUFF_SIZE - 2;
int i = 0;
long int m = va_arg(types, long int);
unsigned long int o;
m = convert_size_number(m, size);
if (m == 0)
buffer[n--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
o = (unsigned long int)m;
if (n < 0)
{
o = (unsigned long int)((-1) * m);
i = 1;
}
while (o > 0)
{
buffer[n--] = (o % 10) + '0';
o /= 10;
}
n++;
return (write_number(i, n, buffer, flags, width, precision, size));
}
/**
 * print_binary - Function that prints an unsigned number
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
unsigned int n, m, o, p;
unsigned int q[32];
int r;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
n = va_arg(types, unsigned int);
m = 2147483648 ; /* (2 ^31) */
q[0] = n / m;
for (o = 1 ; o < 32 ; o++)
{
m /= 2;
q[o] = (n / m) % 2;
}
for (o = 0, p = 0, r = 0 ; o < 32 ; o++)
{
p += q[o];
if (p || o == 31)
{
char s = '0' + q[o];
write(1, &s, 1);
r++;
}
}
return (r);
}
