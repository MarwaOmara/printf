#include "main.h"

/**
 * get_specifier - checks which format is included within the function
 * @s: string
 * Return: number of size in bytes printed
 */

int (*get_specifier(char *s))(va_list ap, parameters_token *para)
{
	specifier_type specifiers[] = {
		{"r", print_rev},
		{"S", print_S},
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"R", print_rot13},
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
 * get_print_function - finds function format
 * @s: string
 * @ap: pointer to argument
 * @para: struct parameter
 * return: how many bytes printed
 */

int get_print_function(char *s, va_list ap, parameters_token *para)
{
	int (*f)(va_list, parameters_token *) = get_specifier(s);

	if (f)
		return (f(ap, para));
	return (0);
}

/**
 * get_flag - checks for a flag in the function
 * @s: string
 * @para: struct parameter
 * Return: true or false
 */

int get_flag(char *s, parameters_token *para)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = para->plus_flag = 1;
			break;
		case '0':
			i = para->zero_flag = 1;
			break;
		case ' ':
			i = para->space_flag = 1;
			break;
		case '#':
			i = para->hashtag_flag = 1;
			break;
		case '-':
			i = para->minus_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_wiidth - checks width from string
 * @s: string
 * @para: struct parameter
 * @ap: pointer to argument
 * Return: new pointer
 */

char *get_width(char *s, parameters_token *para, va_list ap)
{
	int Y = 0;

	if (*s == '*')
	{
		Y = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			Y = Y * 10 + (*s++ - '0');
	}
	para->width = Y;
	return (s);
}
