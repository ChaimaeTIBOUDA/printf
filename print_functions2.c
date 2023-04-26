#include "main.h"
/**
 * print_pointer- Function that prints the value of a pointer
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;/* length=2, for '0x' */
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (addrs == NULL)
return (write(1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
num_addrs = (unsigned long)addrs;
while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;
ind++;
/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
return (write_pointer(buffer, ind, length,
width, flags, padd, extra_c, padd_start));
}
/**
 * print_non_printable - Fcuntion that prints ascii codes in hexadecimal
 * of non printable chars
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int n = 0, m = 0;
char *o = va_arg(types, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (o == NULL)
return (write(1, "(null)", 6));
while (o[n] != '\0')
{
if (is_printable(o[n]))
buffer[n + m] = o[n];
else
m += append_hexa_code(o[n], buffer, n + m);
n++;
}
buffer[n + m] = '\0';
return (write(1, buffer, n + m));
}
/**
 * print_reverse - Function that prints reverse string
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int i, count = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
str = va_arg(types, char *);
if (str == NULL)
{
UNUSED(precision);
str = ")Null(";
}
for (i = 0 ; str[i] ; i++)
{
for (i = i - 1 ; i >= 0 ; i--)
{
char z = str[i];
write(1, &z, 1);
count++;
}
}
return (count);
}
/**
 * print_rot13string - Funcction that prints a string in rot13
 * @types: 1st list of arguments
 * @buffer: Buffer array to print
 * @flags: Calculates all active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: The number of chars printed
 */
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char n;
char *s;
unsigned int m, o;
int p = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
s = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (s == NULL)
s = "(AHYY)";
for (m = 0 ; s[m] ; m++)
{
for (o = 0 ; in[o] ; o++)
{
if (in[o] == s[m])
{
n = out[o];
write(1, &n, 1);
p++;
break;
}
}
if (!in[o])
{
n = s[m];
write(1, &n, 1);
p++;
}
}
return (p);
}
