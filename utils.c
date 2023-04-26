#include "main.h"

/**
 * is_printable - ...
 * @c: ...
 * Return: ...
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - ...
 * @buffer: ...
 * @i: ...
 * @ascii_code: ...
 * Return: ...
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char python[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = python[ascii_code / 16];
	buffer[i] = python[ascii_code % 16];

	return (3);
}

/**
 * is_digit - ...
 * @c: ...
 * Return: ...
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - ...
 * @num: ...
 * @size: ...
 * Return: ...
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - ...
 * @num: ...
 * @size: ...
 * Return: ...
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
