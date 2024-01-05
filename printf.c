#include "main.h"
/**
 * _printf - function which produces output
 * @format: pointer to a string of formats
 * Return: count of chars
 */
int _printf(const char *format, ...)
{
	va_list argus;
	int num_char = 0;

	va_start(argus, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			putchar(*format);
			num_char++;
		}
		else
		{
			while (*++format)
			{
				if (*format == '%')
					format++;
				else if (*format == 'c')
				{
					num_char += fprintf(stdout, "%c", va_arg(argus, int));
					break;
				}
				else if (*format == 's')
				{
					num_char += fprintf(stdout, "%s", va_arg(argus, char *));
					break;
				}
				else if (*format == 'd' || *format == 'i')
				{
					num_char += fprintf(stdout, "%d", va_arg(argus, int));
					break;
				}
				putchar('%');
				putchar(*format);
				num_char += 2;
				break;
			}
		}
		format++;
	}
	va_end(argus);
	return (num_char);
}
