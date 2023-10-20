#include "main.h"

/**
 * conv - same as itoa
 * @num: number
 * @base: base
 * @tags: argument tags
 * @flags: structure of parameter
 * Return: string
 */

char *conv(long int num, int base, int tags, flags_type *flags)
{
	char *P;
	char sign = 0;
	unsigned long C = num;
	static char *array;
	static char buffer[50];
	(void)flags;

	if (!(tags & CONV_UN) && num < 0)
	{
		C = -num;
		sign = '-';
	}
	array = tags & CONV_LOW ? "0123456789abcdef" : "0123456789ABCDEF";
	P = &buffer[49];
	*P = '\0';

	do {
		*--P = array[C % base];
		C /= base;
	} while (C != 0);

	if (sign)
		*--P = sign;
	return (P);
}

/**
 * print_unsigned - prints unsigned integer
 * @ap: argument pointer
 * @flags: parameters
 * Return: written bytes
 */

int print_unsigned(va_list ap, flags_type *flags)
{
	unsigned long L;

	if (flags->l_mod)
		L = (unsigned long)va_arg(ap, unsigned long);
	else if (flags->h_mod)
		L = (unsigned short int)va_arg(ap, unsigned int);
	else
		L = (unsigned int)va_arg(ap, unsigned int);
	flags->unsign = 1;
	return (pnumber(conv(L, 10, CONV_UN,flags), flags));
}

/**
 * print_address - write address
 * @ap: argument pointer
 * @flags: parameters
 * Return: written bytes
 */

int print_address(va_list ap, flags_type *flags)
{
	unsigned long int V = va_arg(ap, unsigned long int);
		char *cts;

	if (!V)
		return (_puts("(nil)"));

	cts = conv(V, 16, CONV_UN | CONV_LOW, flags);
	*--cts = 'x';
	*--cts = '0';
	return (pnumber(cts, flags));
}
