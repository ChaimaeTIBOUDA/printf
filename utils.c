#include "main.h"
/**
 * is_printable - char is printable or not
 * @c: char
 * Return: 1 or 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/**
 * append_hexa_code - ascii hexa code to buffer
 * @buffer: array
 * @i: index
 * @ascii_code: ascii
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char table[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascuii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'X';
	buffer[i++] = table[ascii_code / 16];
	buffer[i] = table[ascii_code % 16];
	return (3);
}
/**
 * convert_size_number - pair num to size
 * @n: number
 * @size: size
 * Return: value
 */
long int convert_size_number(long int n, int size)
{
	if (size == S_LONG)
		return (n);
	else if (size == S_SHORT)
		return ((short)n);
	return ((int)n);
}
/**
 * convert_size_unsgnd - pair number to size
 * @n: number
 * @size: size
 * Return: value
 */
long int convert_size_unsgnd(unsigned long int n, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)n);
	return ((unsigned int)n);
}
