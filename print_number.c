#include "main.h"

/**
 * _Digit - true if char is digit
 * @c: character to analyze
 * Return: 1 if digit, 0 if not
 */

int _Digit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _len - lenght of string
 * @s: string to analyze
 * Return: int
 */

int _len(char *s)
{
	int i = 0;

		while (*s++)
			i++;
	return (i);
}		/* can use recursive func as well,*/

/**
 * pnumber - prints variaty of numbers
 * @cts: number but in ASCII as string
 * @flags: parameter
 * Return: int
 */

int pnumber(char *cts, flags_type *flags)
{
	unsigned int N = _len(cts);
	int Negative = (!flags->unsign && *cts == '-');

	if (!flags->precis && *cts == '0' && !cts[1])
		cts = "";
	if (Negative)
	{
		cts++;
		N--;
	}
	if (flags->precis != UINT_MAX)
		while (N++ < flags->precis)
			*--cts = '0';
	if (Negative)
		*--cts = '-';

	if (!flags->minus)
		return (pn_right_sft(cts, flags));
	else
		return (pn_left_sft(cts, flags));
}

/**
 * pn_right_sft - variaty of number prints
 * @cts: string but numbers
 * @flags: parameter struct
 * Return: chars
 */

int pn_right_sft(char *cts, flags_type *flags)
{
	unsigned int N = 0, minus, minus2, i = _len(cts);
	char C = ' ';

	if (flags->zero && !flags->minus)
		C = '0';
	minus = minus2 = (!flags->unsign && *cts == '-');
	if (minus && i < flags->width && C == '0' && !flags->minus)
		cts++;
	else
		minus = 0;
	if ((flags->plus && !minus2) || (!flags->plus && flags->space && !minus2))
		i++;
	if (minus && C == '0')
		N += _putchar('-');
	if (flags->plus && !minus2 && C == '0' && !flags->unsign)
		N += _putchar('+');
	else if (!flags->plus && flags->space &&
			!minus2 && !flags->unsign && flags->zero)
		N += _putchar(' ');
	while (i++ < flags->width)
		N += _putchar(C);
	if (minus && C == ' ')
		N += _putchar('-');
	if (flags->plus && !minus2 && C == ' ' && !flags->unsign)
		N += _putchar('+');
	else if (!flags->plus && flags->space
			&& !minus2 && !flags->unsign && !flags->zero)
		N += _putchar(' ');
	N += _puts(cts);
	return (N);
}

/**
 * pn_left_sft - prints a number with options
 * @cts: the base number as a string
 * @flags: parameter
 * Return: characters in int
 */

int pn_left_sft(char *cts, flags_type *flags)
{
	unsigned int N, minus, minus2, i = _len(cts);
	char C = ' ';

	N = 0;
	if (flags->zero && !flags->minus)
		C = '0';
	minus = minus2 = (!flags->unsign && *cts == '-');
	if (minus && i < flags->width && C == '0' && !flags->minus)
		cts++;
	else
		minus = 0;

	if (flags->plus && !minus2 && !flags->unsign)
		N += _putchar ('+'), i++;
	else if (flags->space && !minus && !flags->unsign)
		N += _putchar(' '), i++;
	N += _puts(cts);
	while (i++ < flags->width)
		N += _putchar(C);
	return (N);
}
