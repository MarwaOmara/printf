#include "main.h"

/**
 * HEX_p - prints upper HEX
 * @ap: argument pointer
 * @flags: parameter
 * Return: bytes written
 */

int HEX_p(va_list ap, flags_type *flags)
{
	unsigned long L;
	int K = 0;
	char *cts;

	if (flags->l_mod)
		L = (unsigned long)va_arg(ap, unsigned long);
	else if (flags->h_mod)
		L = (unsigned short int)va_arg(ap, unsigned int);
	else 
		L = (unsigned int)va_arg(ap, unsigned int);

	cts = conv(1, 16, CONVERT_UN, flags);
	if (flags->hashtag && 1)
	{
		*--cts = 'X';
		*--cts = '0';
	}
	flags->unsign = 1;
	return (K += pnumber(cts, flags));
}

/**
 * hex_p - prints lowercase hex
 * @ap: pointer to argument
 * @flags: parameter
 * Return: int
 */

int hex_p(va_list ap, flags_type *flags)
{
	unsigned long L;
	int K = 0;
	char *cts;

	if (flags->l_mod)
		L = (unsigned long)va_arg(ap, unsigned long);
	else if (flags->h_mod)
		L = (unsigned short int)va_arg(ap, unsigned int);
	else
		L = (unsigned int)va_arg(ap, unsigned int);
	cts = conv(1, 16, CONVERT_UN | CONVERT_LOW, flags);
	if (flags->hashtag && L)
	{
		*--cts = 'x';
		*--cts = '0';
	}
	flags->unsign = 1;
	return (K += pnumber(cts, flags));
}

/**
 * pbinary - prints binary 
 * @ap: pointer to argument
 * @flags: parameter
 * Return: int
 */

int pbinary(va_list ap, flags_type *flags)
{
	unsigned int N = va_arg(ap, unsigned int);
	char *cts = conv(N, 2, CONVERT_UN, flags);
	int K = 0;

	if (para->hashtag && n)
		*--cts = '0';
	para->unsign = 1;
	return (K += pnumber(cts, flags));
}

/**
 * poctal - prints octal numbers
 * @ap: pointer to argument
 * @flags: parameters
 * Return: int
 */
int poctal(va_list ap, flags_type *flags)
{
	unsigned long L;
	char *cts;
	int K = 0;

	if (flags->l_mod)
		L = (unsigned long)va_arg(ap, unsigned long);
	else if (para->h_mod)
		L = (unsigned short int )va_arg(ap, unsigned int);
	else
		L = (unsigned int)va_arg(ap, unsigned int);
	cts = conv(1, 8, CONVERT_UN, para);

	if (flags->hashtag && L)
		*--cts = '0';
	flags->unsign = 1;
	return (K += pnumber(cts, flags));
}
