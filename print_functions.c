#include "main.h"

/**
 * printT - prints int
 * @ap: pointer to argument
 * @flags: parameters
 * Return: int
 */

int printT(va_list ap, flags_type *flags)
{
	long L;

	if (flags->l_mod)
		L = va_arg(ap, long);
	else if (flags->h_mod)
		L = (short int)va_arg(ap, int);
	else
		L = (int)va_arg(ap, int);
	return (pnumber(conv(L, 10, 0, flags), flags));
}

/**
 * printC - prints characters
 * @ap: pointer to arguments
 * @flags: parameters
 * Return: int
 */

int printC(va_list ap, flags_type *flags)
{
	char C = ' ';
	unsigned int K = 1, result = 0, cs = va_arg(ap, int);

	if (flags->minus)
		result += _putchar(cs);
	while (K++ < flags->width)
		result += _putchar(C);
	if (!flags->minus)
		result += _putchar(cs);
	return (result);
}

/**
 * printSt - prints string
 * @ap: pointer to argument
 * @flags: parameters
 * Return: int
 */

int printSt(va_list ap, flags_type *flags)
{
	char *cts = va_arg(ap, char *), C = ' ';
	unsigned int K = 0, result = 0, i = 0 , j;

	(void)flags;
	switch ((int)(!cts))
	case 1:
		cts = NULL_STRING;
	
		j = K = _len(cts);
		if (flags->precis < K)
			j = K = flags->precis;

		if (flags->minus)
		{
			if (flags->precis != UINT_MAX)
				for (i = 0; i < K; i++)
					result += _putchar(*cts++);
			else
				result += _puts(cts);
		}
		while (j++ < flags->width)
			result += _putchar(C);
		if (!flags->minus)
		{
			if (flags->precis != UINT_MAX)
				for (i = 0; i < K; i++)
					result += _putchar(*cts++);
			else result += _puts(cts);
		}
		return (result);
}

/**
 * print_P - prints percent character
 * @ap: pointer to argument
 * @flags: parameters
 * Return: int
 */

int print_P(va_list ap, flags_type *flags)
{
	(void)ap;
	(void)flags;
	return (_putchar('%'));
}

/**
 * print_S special print format
 * @ap: pointer to argument
 * @flags: parameters
 * Return: int
 */

int print_S(va_list ap, flags_type *flags)
{
	char *cts = va_arg(ap, char *);
	char *hex;
	int result = 0;

	if ((int)(!cts))
		return (_puts(NULL_STRING));
	for (; *cts; cts++)
	{
		if ((*cts > 0 && *cts < 32) || *cts >= 127)
		{
			result += _putchar('\\');
			result += _putchar('x');
			hex = conv(*cts, 16 , 0, flags);
			if (!hex[1])
				result += _putchar('0');
			result += _puts(hex);
		}
		else
		{
			result += _putchar(*cts);
		}
	}
	return (result);
}
