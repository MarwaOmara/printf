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
	int i = 0, itr = 0, ascii, c;
	char *s;

	if (flags == NULL)
		return (0);
	s = va_arg(ap, char *);
	if (!s)
		return (0);
	while (s[i])
	{
		ascii = find_ascii(s[i]);
		if (ascii)
		{
			c = (s[i] - ascii) + 13;
			c = (c % 26);
			c = (c + ascii);
			write(1, &c, 1);
			itr++;
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			itr++;
			i++;
		}
	}
	return (itr);
}
/**
 * find_ascii - changes char to int
 * @c: character
 * Return: Int
 */
int find_ascii(char c)
{
	int low, up;

	low = ('a' * (c >= 'a' && c <= 'z'));
	up = ('A' * (c >= 'A' && c <= 'Z'));

	return (low + up);
}
