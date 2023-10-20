#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

#define NULL_STRING "(null)"
#define LOCAL_BUFFER_SIZE 1024

/* mandated in Task4"Use a local buffer of 1024" */

#define BUFFER_FLUSH -1

#define FLAGS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
/*typedef struct, set the value 0 at start, or resset value*/

#define CONV_LOW	1
#define CONV_UN		2

/**
 * struct flag - gives struct that flags a specific specifier
 * @unsign: unsigned, which can be negative
 * @plus: returns 1   if plus_flag specified
 * @space: returns 1 if _flag specified
 * @hashtag: returns 1 if hashtag_flag
 * @zero: returns 1 if _flag specified
 * @minus: returns 1 if _flag specified
 * @l_mod: returns 1 if it's modifier specified
 * @h_mod: returns 1 if _flag specified
 *
 * @width: if width specified
 * @precis: if precision specified
 */

typedef struct flag
{
	unsigned int unsign		: 1;

	unsigned int plus		: 1;	/* task #7  */
	unsigned int space		: 1;
	unsigned int hashtag		: 1;
	unsigned int zero		: 1;	/* task#11 */
	unsigned int minus		: 1;	/* task#12*/

	unsigned int width;			/* task #8 */
	unsigned int precis;

	unsigned int h_mod		: 1;	/* task #9 */
	unsigned int l_mod		: 1;	/* task#10*/
} flags_type;

/**
 * struct specifier - struct token
 * @specifier: token format
 * @f: pointer to function
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, flags_type *);
} spec_type;

/*Splitting different function into multiple files for easier access*/

/* functions for _put.c */
int _puts(char *cts);
int _putchar(int c);

/* print_functions.c */
int printC(va_list ap, flags_type *flags); /* Task #0 */
int printT(va_list ap, flags_type *flags);  /* task #1 */
int printSt(va_list ap, flags_type *flags); /* task #0 */
int print_P(va_list ap, flags_type *flags); /* task #0 */
int print_S(va_list ap, flags_type *flags); /* task #5 */

/* numbers.c functions */
char *conv(long int number, int base, int tags, flags_type *flags);
int print_unsigned(va_list ap, flags_type *flags); /* task #3 */
int print_address(va_list ap, flags_type *flags);  /* task #6 */

/* specifiers.c CHECKS WHICH SPECIFIER, Used almost in all task functions ! */

int (*find_specifier(char *s))(va_list ap, flags_type *flags);
int find_print_function(char *s, va_list ap, flags_type *flags);
int find_flag(char *s, flags_type *flags);
int find_mod(char *s, flags_type *flags);
char *find_width(char *s, flags_type *flags, va_list ap);

/* number_convert */

int pbinary(va_list ap, flags_type *flags);	/* task #2 */
int HEX_p(va_list ap, flags_type *flags);	/*task#3*/
int hex_p(va_list ap, flags_type *flags);	/*task#3*/
int poctal(va_list ap, flags_type *flags);	/*task#3*/

/* sim_printers.c */
int p_from_to(char *start, char *stop, char *excelude);
int prev(va_list ap, flags_type *flags);	/*task#13*/
int prot13(va_list ap, flags_type *flags);	/*task#14*/
int find_ascii(char c);

/*print_number */
int _Digit(int c);
int _len(char *s);
int pnumber(char *cts, flags_type *flags);
int pn_right_sft(char *cts, flags_type *flags);
int pn_left_sft(char *cts, flags_type *flags);

/* para.c */
void init_flags(flags_type *flags, va_list ap);

/* string_fields.c */
char *find_precis(char *p, flags_type *flags, va_list ap);

/* _printf.c */
int _printf(const char *format, ...);

#endif
