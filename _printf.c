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
	parameters_token para = PARAMETERS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (PP = (char *)format; *PP; PP++)   /*checks if the pointer value exists or not*/
	{
		init_para(&para, ap);
		if (*PP != '%')
		{
			result += _putchar(*PP);
			continue;
		}
		Stt = PP;
		PP++;
		while (get_flag(PP, &para))	/*checks if the char is Flag character"check main.h" */
		{
			PP++;	/*iterate to next char */
		}
		PP = get_width(PP, &para, ap);
		PP = get_pres(PP, &para, ap);
		if  (get_modifier(PP, &para))
			PP++;
		if (get_specifier(p))
			result += print_from_to(Stt, PP, para.l_modifier ||para.h_modifier ? PP - 1 : 0);
		else
			result += get_print_func(PP, ap, &para);
	}
	_putchar(BUFFER_FLUSH);
	va_end(ap);
	return(result);
}
