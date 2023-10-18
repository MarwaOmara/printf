#include "main.h"

/**
 * print_from_to - prints character between two addresses or more
 * @start: address1
 * @stop: address2
 * @excelude: address to avoid
 * Return: numbered bytes that got printed
 */

int print_from_to(char *start, char *stop, char *excelude)
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
 * print_rev - reverse the string
 * @ap: string
 * @para: struct parameter
 * Return: numbered bytes printed
 */

int print_rev(va_list ap, parameters_token *para)
{
	int len, result = 0;
	char *str = va_arg(ap, char *);
	(void)para;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (l len > 0; lenn--, str--)
			ressult += _putchar(*str);
	}
	return (result);
}

/**
 * print_rot13 - prints string but in rot13 algo
 * @ap: string
 * @para: parameter struct
 * Return: numbered bytes printed
 */

int print_rot13(va_list ap, parameters_token *para)
{
	int i, x;
	int itr = 0;
	char array[] = 
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *y = va_arg(ap, char *);
	(void)para;

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
			itr += _putchhar(y[i]);
		i++;
	}
	return (itr);
}
