#include "main.h"

/**
 * get_precision - A program that gets the precision from the format string
 * @p: the format string itself
 * @params: Parameters
 * @ap: the argument pointer
 *
 * Return: void
 *
 */

char *get_precision(char *p, params_t *params, va_list ap)
{
	int i = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		i = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			i = i * 10 + (*p++ - '0');
	}
	params->precision = i;
	return (p);
}
