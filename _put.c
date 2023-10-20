#include "main.h"

/**
 * _puts - print string and a \n
 * @str: string pointer
 * Return: void
 */
int _puts(char *cts)
{
	char *P = cts;

	while (*cts)
		_putchar(*cts++);
	return (cts - P);	/*address of last byte of string minus first byte will give  lenght*/
}

/**
 * _putchar - writes character  c to stdout
 * @c: character
 * Return: 1
 */

int _putchar(int c)
{
	static int P;
	static char buffer[LOCAL_BUFFER_SIZE];

	if (c == BUFFER_FLUSH || P >= LOCAL_BUFFER_SIZE)
	{
		write(1, buffer, P);
		P = 0;
	}
	if (c != BUFFER_FLUSH)
		buffer[P++] = c;
	return (1);
}
