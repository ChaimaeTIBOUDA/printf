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
char n = 0, m = ' ';
int o = BUFF_SIZE - 2, p = 2, q = 1; /* p=2, for '0x' */
unsigned long i;
char map_to[] = "0123456789abcdef";
void *r = va_arg(types, void *);
UNUSED(width);
UNUSED(size);
if (r == NULL)
return (write(1, "(nil)", 5));
buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);
i = (unsigned long)r;
while (i > 0)
{
buffer[o--] = map_to[i % 16];
i /= 16;
p++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
m = '0';
if (flags & F_PLUS)
n = '+', p++;
else if (flags & F_SPACE)
n = ' ', p++;
o++;
/* return (write(1, &buffer[l], BUFF_SIZE - l - 1));*/
return (write_pointer(buffer, o, p, width, flags, m, n, q));
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
char *s;
int n, m = 0;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);
s = va_arg(types, char *);
if (s == NULL)
{
UNUSED(precision);
s = ")Null(";
}
for (n = 0 ; s[n] ; n++)
;
for (n = n - 1 ; n >= 0 ; n--)
{
char o = s[n];
write(1, &o, 1);
}
return (m);
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
