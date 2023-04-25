#include "main.h"
/**
 * print_unsigned - Function that prints an unsigned number
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int n = BUFF_SIZE - 2;
unsigned long int m = va_arg(types, unsigned long int);
m = convert_size_unsgnd(m, size);
if (m == 0)
buffer[n--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (m > 0)
{
buffer[n--] = (m % 10) + '0';
m /= 10;
}
n++;
return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}
/**
 * print_octal - Fucntion that prints an unsigned number in octal notation
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int n = BUFF_SIZE - 2;
unsigned long int m = va_arg(types, unsigned long int);
unsigned long int o = m;
UNUSED(width);
m = convert_size_unsgnd(m, size);
if (m == 0)
buffer[n--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (m > 0)
{
buffer[n--] = (m % 8) + '0';
m /= 8;
}
if (flags & F_HASH && o != 0)
buffer[n--] = '0';
n++;
return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - Function that prints an unsigned number in
 * hexadecimal notation
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer, flags,
'x', width, precision, size));
}
/**
 * print_hexa_upper - Function that prints an unsigned number in upper
 * hexadecimal notation
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer, flags,
'X', width, precision, size));
}
/**
 * print_hexa - Function that prints an hexadecimal number in lower or upper
 * @types: 1st list of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @flag_ch: Calculates active flags
 * @width: Width
 * @precision: Precision
 * @size: Size specifier
 * @size: Size specification
 * Return: The number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int n = BUFF_SIZE - 2;
unsigned long int m = va_arg(types, unsigned long int);
unsigned long int o = m;
UNUSED(width);
m = convert_size_unsgnd(m, size);
if (m == 0)
buffer[n--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (m > 0)
{
buffer[n--] = map_to[m % 16];
m /= 16;
}
if (flags & F_HASH && o != 0)
{
buffer[n--] = flag_ch;
buffer[n--] = '0';
}
n++;
return (write_unsgnd(0, n, buffer, flags, width, precision, size));
}
