#include "main.h"

/**
 * print_from_to - A program that prints a char address range
 * @start: start address
 * @stop: stop address
 * @except: except address
 *
 * Return: number of bytes printed
 *
 */

int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - A program that prints a string in reverse
 * @ap: The string
 * @params: Parameters
 *
 * Return: number of bytes printed
 *
 */

int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - A program that prints a string
 * @ap: string
 * @params: Parameters
 *
 * Return: number of bytes printed
 *
 */

int print_rot13(va_list ap, params_t *params)
{
	int j, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	j = 0;
	index = 0;
	while (a[j])
	{
		if ((a[j] >= 'A' && a[j] <= 'Z')
		    || (a[j] >= 'a' && a[j] <= 'z'))
		{
			index = a[j] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[j]);
		j++;
	}
	return (count);
}
