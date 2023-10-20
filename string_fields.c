#include "main.h"

/**
 * get_pres - gets precision from string
 * @p: string
 * @para: struct of parameter
 * @ap: pointer to argument
 * Return: pointer
 */

char *get_pres(char *p, flags_type *flags, va_list ap)
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
		while (_Digit(*p))
			Y = Y * 10 (*p++ - '0');
	}
	flags->precis = Y;
	return (p);
}
