#include "main.h"

/**
 * p_from_to - prints character between two addresses or more
 * @start: address1
 * @stop: address2
 * @excelude: address to avoid
 * Return: numbered bytes that got printed
 */

int p_from_to(char *start, char *stop, char *excelude)
{
	int result = 0;

	while (start <= stop)
	{
		if (start != excelude)
			result += _putchar(*start);
		start++;
	}
	return (result);
}

/**
 * prev - reverse the string
 * @ap: string
 * @flags: struct parameter
 * Return: numbered bytes printed
 */

int prev(va_list ap, flags_type *flags)
{
	int lenn, result = 0;
	char *cts = va_arg(ap, char *);
	(void)flags;

	if (cts)
	{
		for (lenn = 0; *cts; cts++)
			lenn++;
		cts--;
		for (; lenn > 0; lenn--, cts--)
			result += _putchar(*cts);
	}
	return (result);
}

/**
 * prot13 - prints string but in rot13 algo
 * @ap: string
 * @flags: parameter struct
 * Return: int
 */

int prot13(va_list ap, flags_type *flags)
{
	int i, x;
	int itr = 0;
	char array[] = 
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *y = va_arg(ap, char *);
	(void)flags;

	i = 0;
	x = 0;
	while (y[i])
	{
		if (y[i] >= "A" && y[i] <='Z' || (y[i] >= 'a' && y[i] <= 'z'))
		{
			x = y[i] - 65;
			itr += _putchar(array[x]);
		}
		else
			itr += _putchar(y[i]);
		i++;
	}
	return (itr);
}
