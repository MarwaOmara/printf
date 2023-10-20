#include "main.h"

/**
 * init_flags - function used to resset buffer
 * @flags: struct parameter
 * @ap: pointer to argument
 * Return: void
 */

void init_flags(flags_type *flags, va_list ap)
{
	flags->unsign = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hashtag = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->precis = UINT_MAX;
	flags->h_mod = 0;
	flags->l_mod = 0;
	(void)ap;
}
