#include "main.h"
#include <limits.h>
#include <stdio.h>

int no_struct(char c, int count, va_list argu)
{
	int j;
	char *s;

	switch (c)/* A */
	{
		case 'c':/* B */
			j = va_arg(argu, int);
			count += _putchar(j);
			break;
		case 's':/* C */
			s = va_arg(argu, char *);
			if (!s)
			{
				_putchar('(');
				_putchar('n');
				_putchar('u');
				_putchar('l');
				_putchar('l');
				_putchar(')');
				count += 6;
			}
			else
				count += _putstring(s);
			break;
		case 'i':/* D */
		case 'd':
			j = va_arg(argu, int);
			if (!j)
			{
				count++;
				_putchar('0');
			}
			else
				count += print_number(j);
			break;
		case '%':/* E */
			count += _putchar('%');
			break;
		case 'b':/* F */
			j = va_arg(argu, int);
			count += dec_to_binary(j);
			break;
		case 'r': /* G */
			s = va_arg(argu, char *);
			count += rev_str(s);
			break;
		case 'R': /* H */
			s = va_arg(argu, char *);
			count += rot13(s);
			break;
		default:/* H */
			count += 2;
			_putchar('%');
			_putchar(c);
	}
	return (count);
}

/**
* _printf - our own printf function
* @format: A character string, composed of zero of more directives
*
* Description: Writes a formatted string to the standard output
* Return: an integer. The number of characters printed excluding the null byte
* A: if format is null then we return -1
* B: as long as format of index is not null, we increment
* C: if the index is not a percentage then we puts and count++
* D: ERASED THE DEEEE
* E: if it is not a null then we scan that letter. pass it into helper func
* F: its prob a null so we return -1
*/

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list argu;

	va_start(argu, format);

	if (!format)/* A */
		return (-1);

	for (i = 0; format[i]; i++)/* B */
	{
		if (format[i] != '%')/* C */
		{
			count++;
			_putchar(format[i]);
		}
		else if (format[i + 1])/* E */
		{
			i++;
			count = no_struct(format[i], count, argu);
		}
		else/* F */
			return (-1);
	}
	va_end(argu);
	return (count);
}
