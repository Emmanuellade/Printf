#include "main.h"

/**
 * _isdigit - checks character in digit
 * @c: checks character
 *
 * Return: 1 if digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the string in length
 * @s: check the string length
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int j = 0;

	while (*s++)
		j++;
	return (j);
}

/**
 * print_number - prints a numbeer
 * @str: string base number
 * @params: struct paramenter
 *
 * Return: chars printed
 */
int print_number(char *str, params_t *params)
{
	unsigned int j = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		j--;
	}
	if (params->precision != UINT_MAX)
		while (j++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number
 * @str: string ase number
 * @params: struct parameters
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int s = 0, neg, neg2, j = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && j < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		j++;
	if (neg && pad_char == '0')
		s += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		s += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		s += _putchar(' ');
	while (j++ < params->width)
		s += _putchar(pad_char);
	if (neg && pad_char == ' ')
		s += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		s += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		s += _putchar(' ');
	s += _puts(str);
	return (s);
}

/**
 * print_number_left_shift - prints a number
 * @str: string base number
 * @params: struct parameter
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int s = 0, neg, neg2, j = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && j < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		s += _putchar('+'), j++;
	else if (params->space_flag && !neg2 && !params->unsign)
		s += _putchar(' '), j++;
	s += _puts(str);
	while (j++ < params->width)
		s += _putchar(pad_char);
	return (s);
}
