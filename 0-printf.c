#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * _printf - implements standard printf
 * @format: string to write on screen
 *
 * Return: number of charecters printed
 */

int _printf(const char *format, ...)
{
	va_list ls;
	char buff[100] = {0};
	char *str;
	int i, j;

	i = 0;
	j = 0;

	va_start(ls, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(ls);
				return (-1);
			}
			else if (format[i] == '%')
			{
				buff[j] = format[i];
				j++;
			}
			else if (format[i] == 'c')
			{
				buff[j] = (char)va_arg(ls, int);
				j++;
			}
			else if (format[j] == 's')
			{
				str = va_arg(ls, char *);
				strcpy(&buff[j], str);
				j = j + strlen(str);
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout);
	va_end(ls);
	return (j);
}
