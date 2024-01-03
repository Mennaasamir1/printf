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
	int j, i = 0, m, num = 58;
	va_list argus;
	char ftr[1000], var1;

	va_start(argus, format);
	for (j = 0; format[j] != '\0'; j++)
	{
		ftr[i++] = format[j];
		if (format[j + 1] == '%' || format[j + 1] == '\0')
		{
			ftr[i] = '\0';
			i = 0;

			if (ftr[0] != '%')
			{
				fprintf(stdout, "%s", ftr);
			}
			else
			{
				m = 1;
				var1 = 0;
				while ((var1 = ftr[m++]) < num)
					;
				if (var1 == 'c')
				{
					fprintf(stdout, ftr, va_arg(argus, int));
				}
				else if (var1 == 's')
				{
					fprintf(stdout, ftr, va_arg(argus, char *));
				}
				else
				{
					fprintf(stdout, "%s", ftr);
				}
				
			}
		}
	}
	va_end(argus);
	return (0);
}
