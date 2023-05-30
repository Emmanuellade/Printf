#include "main.h"

/**
 * _puts -A program that prints a string with a newline outputted
 * @str: Print string
 *
 * Return: Always void
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the character
 * @c: The char
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is being set appropriately.
 */
int _putchar(int c)
{
	static int index;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || index >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, index);
		index = 0;
	}
	if (c != BUF_FLUSH)
		buf[index++] = c;
	return (1);
}
