#include "main.h"
#include <unistd.h>
/**
 * handle_write_char - print string
 * @c: type
 * @buffer: array
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: num of printed chars
 */
int handle_write_char(char c, char buffer[], int flags,
int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);
	if (flags & F_ZERO)
	padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;
		if (flags & F_MINUS)
			return (write(1, &buffer[BUFF_SIZE - i - 1],
						width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1],
						width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/**
 * write_number - print string
 * @is_negative: arguments
 * @ind: types
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @size: size
 * @precision: precision
 * Return: number of chars
 */
int write_number(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size)
{
	int l = BUFF_SIZE - ind - 1;
	char padd = ' ', extra = 0;

	UNUSED(size);
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra = '-';
	if (flags & F_PLUS)
		extra = '+';
	if (flags & F_SPACE)
		extra = ' ';
	return (write_num(ind, buffer, flags, width,
				precision, l, padd, extra));
}
/**
 * write_num - write number with buffer
 * @ind: index
 * @buffer: buffer
 * @flags: flags
 * @width: width
 * @prec: precision
 * @length: length
 * @padd: padding
 * @extra: extra char
 * Return: printf chars
 */
int write_num(int ind, char buffer[], int flags,
int width, int prec, int length,
char padd, char extra)
{
int i, padd_st = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 &&
buffer[ind] == '0' && width == 0)
return (0);
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' ';
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra != 0)
length++;
if (width > length)
{
for (i = 1; i < width - length + 1; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
{
if (extra)
buffer[--ind] = extra;
return (write(1, &buffer[ind], length) + write(1, &buffer[i], i - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
if (extra)
buffer[--ind] = extra;
return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra)
buffer[--padd_st] = extra;
return (write(1, &buffer[padd_st], i - padd_st) +
write(1, &buffer[ind], length - (1 - padd_st)));
}
}
if (extra)
buffer[--ind] = extra;
return (write(1, &buffer[ind], length));
}
/**
 * write_unsgnd - write unsigned num
 * @is_negative: num negative or not
 * @ind: index
 * @buffer: buffer
 * @width: width
 * @flags: flags
 * @size: size
 * @precision: precision
 * Return: num of chars
 */
int write_unsgnd(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS)
			return (write(1, &buffer[ind], length) +
					write(1, &buffer[0], i));
		else
			return (write(1, &buffer[0], i) +
					write(1, &buffer[ind], length));
	}
	return (write(1, &buffer[ind], length));
}
/**
 * write_pointer - write memory address
 * @buffer: array
 * @ind: index
 * @width: width
 * @flags: flag
 * @padd: padding
 * @extra_c: extra char
 * @padd_start: starting index
 * @length: length
 * Return: num of chars
 */
int write_pointer(char buffer[], int ind, int length, int width,
int flags, char padd, char extra_c, int padd_start)
{
int i;
if (width > length)
{
for (i = 3; i < width - length + 3; i++)
buffer[i] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
{
buffer[--ind] = 'X';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
}
if (!(flags & F_MINUS) && padd == ' ')
{
buffer[--ind] = 'X';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
}
if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'X';
return (write(1, &buffer[padd_start], i -
padd_start) + write(1, &buffer[ind],
length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'X';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
