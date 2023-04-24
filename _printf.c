#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - function
 * @format: format
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	int i, p = 0, p_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list lsit;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			p_char++;
		}
		else
		{
			print_buffer(buff, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			p = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (p == -1)
				return (-1);
			p_char += p;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (p_char);
}
