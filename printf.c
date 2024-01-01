#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - function which produces output
 * @format: pointer to a string of formats
 * Return: count of chars
 */
int _printf(const char *format, ...)
{
	int c = 0;
	va_list argus;

	va_start(argus, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(*format);
			c++;
		}
		else
		{
			while (*format++)
			{
				if (*format == '%')
				{
					format++;
				}
				else if (*format == 'c')
				{
					c += fprintf(stdout, "%c", va_arg(argus, int));
					break;
				}
				else if (*format == 's')
				{
					c += fprintf(stdout, "%s", va_arg(argus, char *));
					break;
				}
				_putchar('%');
				_putchar(*format);
				c += 2;
				break;
			}
		}
		format++;
	}
	va_end(argus);
	return (c);
}
