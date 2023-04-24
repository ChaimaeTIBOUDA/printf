#include "main.h"
/**
 * get_flags - Function that calculates active flags
 * @format: Formatted string where the arguments are printed
 * @i: Take a parameter
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
/* - + 0 # ' ' */
/* 1 2 4 8  16 */
int a, b;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0}
for (b = *i + 1 ; format[b] != '\0' ; b++)
{
for (a = 0 ; FLAGS_CH[a] != '\0' ; a++)
if (format[b] == FLAGS_CH[a])
{
flags |= FLAGS_ARR[a];
break;
}
if (FLAGS_CH[a] == 0)
break;
}
*i = b - 1;
return (flags);
}
