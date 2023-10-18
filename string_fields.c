#include "main.h"

/**
 * get_pres - gets precision from string
 * @p: string
 * @para: struct of parameter
 * @ap: pointer to argument
 * Return: pointer
 */

char *get_pres(char *p, parameters_token *para, va_list ap)
{
	int Y = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		Y = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			Y = Y * 10 (*p++ - '0');
	}
	para->precision = Y;
	return (p);
}
