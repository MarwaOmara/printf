#include "main.h"

/**
 * find_specifier - checks which format is included within the function
 * @s: string
 * Return: number of size in bytes printed
 */

int (*find_specifier(char *s))(va_list ap, flags_type *flags)
{
	spec_type specifiers[] = {
		{"r", prev},
		{"S", print_S},
		{"c", printC},
		{"d", printT},
		{"i", printT},
		{"s", printSt},
		{"%", print_P},
		{"b", pbinary},
		{"o", poctal},
		{"u", print_unsigned},
		{"x", hex_p},
		{"X", HEX_p},
		{"p", print_address},
		{"R", prot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * find_print_function - finds function format
 * @s: string
 * @ap: pointer to argument
 * @flags: struct parameter
 * return: how many bytes printed
 */

int find_print_function(char *s, va_list ap, flags_type *flags)
{
	int (*f)(va_list, flags_type *) = find_specifier(s);

	if (f)
		return (f(ap, flags));
	return (0);
}

/**
 * find_flag - checks for a flag in the function
 * @s: string
 * @flags: struct parameter
 * Return: true or false
 */

int find_flag(char *s, flags_type *flags)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = flags->plus = 1;
			break;
		case '0':
			i = flags->zero = 1;
			break;
		case ' ':
			i = flags->space = 1;
			break;
		case '#':
			i = flags->hashtag = 1;
			break;
		case '-':
			i = flags->minus = 1;
			break;
	}
	return (i);
}

/**
 * find_width - checks width from string
 * @s: string
 * @flags: struct parameter
 * @ap: pointer to argument
 * Return: new pointer
 */

char *find_width(char *s, flags_type *flags, va_list ap)
{
	int Y = 0;

	if (*s == '*')
	{
		Y = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_Digit(*s))
			Y = Y * 10 + (*s++ - '0');
	}
	flags->width = Y;
	return (s);
}

/**
 * find_mod - finds modifier func
 * @s: string
 * @flags: parameter
 * Return:int on success
 */

int find_mod(char *s, flags_type *flags)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = flags->h_mod = 1;
		break;
	case 'l':
		i = flags->l_mod = 1;
		break;
	}
	return (i);
}
