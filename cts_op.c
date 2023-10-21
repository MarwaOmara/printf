#include "main.h"

/**
 * find_precis - gets precision from string
 * @p: string
 * @flags: struct of parameter
 * @ap: pointer to argument
 * Return: pointer
 */

char *find_precis(char *p, flags_type *flags, va_list ap)
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
			Y = Y * 10 + (*p++ - '0');
	}
	flags->precis = Y;
	return (p);
}
