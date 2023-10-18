#include "main.h"

/**
 * init_para - function used to resset buffer
 * @para: struct
 * @ap: pointer to argument
 * Return: voi
 */

void init_para(parameters_token *para, va_list ap)
{
	para->unsign = 0;
	para->plus_flag = 0;
	para->space_flag = 0;
	para->hashtag_flag = 0;
	para->zero_flag = 0;
	para->minus_flag = 0;
	para->width = 0;
	para->precision = UNIT_MAX;
	para->h_modifier = 0;
	para->l_modifier = 0;
	(void)ap;
}
