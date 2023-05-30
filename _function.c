#include "main.h"

/**
 * print_char - A program that prints its character
 * @ap: argument pointers
 * @params: Parameters
 *
 * Return: number of chars to be printed
 *
 */

int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - A program that prints an integer
 * @ap: argument pointers
 * @params: Parameters
 *
 * Return: number of chars to be printed
 *
 */

int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - A Program that prints a string
 * @ap: argument pointers
 * @params: Parameters
 *
 * Return: number of chars to be printed
 *
 */

int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, add = 0, index = 0, k;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	k = pad = _strlen(str);
	if (params->precision < pad)
		k = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (index = 0; index < pad; index++)
				add += _putchar(*str++);
		else
			add += _puts(str);
	}
	while (k++ < params->width)
		add += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (index = 0; index < pad; index++)
				add += _putchar(*str++);
		else
			add += _puts(str);
	}
	return (add);
}

/**
 * print_percent - A program that prints a string
 * @ap: argument pointers
 * @params: Parameters
 *
 * Return: number of chars to be printed
 *
 */

int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - A program that produces the custom format specifier
 * @ap: argument pointers
 * @params: Parameters
 *
 * Return: number of chars to be printed
 *
 */

int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
