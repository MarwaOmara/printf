#include "main.h"

/**
 * _printf - prints anything
 * @format: string
 * Return: result
 */

int _printf(const char *format, ...)
{
	int result = 0;
	va_list ap;
	char *PP, *Stt;
	flags_type flags = FLAGS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (PP = (char *)format; *PP; PP++)   /*checks if the pointer value exists or not*/
	{
		init_flags(&flags, ap);
		if (*PP != '%')
		{
			result += _putchar(*PP);
			continue;
		}
		Stt = PP;
		PP++;
		while (find_flag(PP, &flags))	/*checks if the char is Flag character"check main.h" */
		{
			PP++;	/*iterate to next char */
		}
		PP = find_width(PP, &flags, ap);
		PP = find_precis(PP, &flags, ap);
		if  (find_mod(PP, &flags))
			PP++;
		if (!find_specifier(PP))
			result += p_from_to(Stt, PP, flags.l_mod || flags.h_mod ? PP - 1 : (0));
		else
			result += find_print_function(PP, ap, &flags);
	}
	_putchar(BUFFER_FLUSH);
	va_end(ap);
	return(result);
}
