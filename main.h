#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

#define NULL_STRING "(null)"
#define LOCAL_BUFFER_SIZE 1024
// mandated in Task4 "Use a local buffer of 1024 chars in order to call write as little as possible." //
#define BUFFER_FLUSH -1

#define PARAMETERS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
//used for typedef struct,  Either set the value 0 at start, or Use again to resset value//


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - gives struct that flags a specific specifier
 * @unsigned: unsigned, which can be negative
 * @plus_flag: returns 1   if plus_flag specified
 * @space_flag: returns 1 if _flag specified
 * @hashtag_flag: returns 1 if hashtag_flag 
 * @zero_flag: returns 1 if _flag specified
 * @minus_flag: returns 1 if _flag specified
 * l_modifier: returns 1 if it's modifier specified
 * @h_modifier: returns 1 if _flag specified
 *
 * @width: if width specified
 * @precision: if precision specified
 */

typedef struct parameters
{
	unsinged int unsign		: 1;
	unsinged int plus_flag		: 1;	/* task #7  */
	unsinged int space_flag		: 1;
	unsinged int hashtag_flag	: 1;
	unsinged int zero_flag		: 1;	/* task#11 */
	unsinged int minus_flag		: 1;	/* task#12*/
	unsinged int h_modifier		: 1;	/* task #8 */
	unsinged int l_modifier		: 1;
	unsinged int width;			/* task #9 */
	unsinged int precision;			/* task#10*/
} parameters_token

/**
 * struct specifier - struct token
 * @specifier: token format
 * @f: pointer to function
 */

type struct specifier
{
	char *specifier;
	int (*f)(va_list, parameters_token *);
} specifier_type;

/** Splitting different function into multiple files for easier access, will also mention which task
// each function is related to**/

/* functions for _put.c */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c */
int print_char(va_list ap, parameters_token *para); /* Task #0 */ 
int print_int(va_list ap, parameters_token *para);   /* task #1 */
int print_string(va_list ap, parameters_token *para); /* task #0 */
int print_percent(va_list ap, params_t *para);     /* task #0 */
int print_S(va_list ap, parameters_token *para);  /* task #5 */

/* numbers.c functions */
char *convert (long int number, int base, int flags, parameters_token *para);
int print_unsigned(va_list ap, parameters_token *para);  /* task #3 */
int print_address(va_list ap, parameters_token *para);   /* task #6 */

/* specifiers.c CHECKS WHICH SPECIFIER, Used almost in all task functions ! */

int (*get_specifier(char *s))(va_list ap, parameters_token *para);
int get_print_function(char *s, va_list ap,parameters_token *para);
int get_flag(char *s, parameters_token *para);
int get_modifier(char *s, parameters_token *para);
char *get_width(char *s, parameters_token *para, va_list ap);

/* number_convert */

int print_binary(valist ap, parameters_token *para);	/* task #2 */
int print_HEX(va_list ap, parameters_token *para);	/*task#3*/
int print_hex(va_list ap. parameters_token *para);	/*task#3*/
int print_octal(va_list ap, parameters_t *para);	/*task#3*/

/* sim_printers.c */
int print_from_to(char *start, char *stop, char excelude);
int print_rev(va_list ap, parameters_token *para);	/*task#13*/
int print_rot12(va_list ap, parameters_token *para);	/*task#14*/

/*print_number */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, parameters_token *para);
int print_number_right_shift(char *str, parameters_token *para);
int print_number_left_shift(char *str, parameters_token *para);

/* para.c */
void init_para(parameters_token *para, va_list ap);

/* string_fields.c */
char *get_pres(char *p, parameters_token *para, va_list ap);

/* _printf.c */
int _printf(const char *format, ...);

#endif
