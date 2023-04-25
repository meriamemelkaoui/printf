#include "main.h"

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
