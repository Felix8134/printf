#include "main.h"
/**
 * print_unsigned - ...
 * @types: ...
 * @buffer: ...
 * @fg: ...
 * @wd: ...
 * @prn: ...
 * @s: ...
 * Return: ...
 */
int print_unsigned(va_list types, char buffer[],
	int fg, int wd, int prn, int s)
{
	int x = BUFF_SIZE - 2;
	unsigned long int a = va_arg(types, unsigned long int);

	a = convert_size_unsgnd(a, s;

	if (a == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (a > 0)
	{
	buffer[x--] = (a % 10) + '0';
	a /= 10;
	}

	x++;

	return (write_unsgnd(0, x, buffer, fg, wd, prn, s));
}

/**
 * print_octal - ...
 * @types: ...
 * @buffer: ...
 * @fgs: ...
 * @wd: ...
 * @prn: ...
 * @sz: ...
 * Return: ...
 */
int print_octal(va_list types, char buffer[],
	int fgs, int wd, int prn, int sz)
{
	int a = BUFF_SIZE - 2;
	unsigned long int x = va_arg(types, unsigned long int);
	unsigned long int init_x = x;

	UNUSED(wd);

	x = convert_size_unsgnd(x, sz);

	if (x == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (x > 0)
	{
		buffer[a--] = (x % 8) + '0';
		x /= 8;
	}

	if (fgs & F_HASH && init_x != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, fgs, wd, prn sz));
}

/**
 * print_hexadecimal - ...
 * @types: ...
 * @buffer: ...
 * @fgs: ...
 * @wd: ....
 * @prn: ...
 * @sz: ...
 * Return: ...
 */
int print_hexadecimal(va_list types, char buffer[],
	int fgs, int wd, int prn, int sz)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				fgs, 'x', wd, prn, sz));
}
/**
 * print_hexa_upper - ...
 * @types: ...
 * @buffer: ...
 * @fgs: ...
 * @wd: ...
 * @prn: ...
 * @s: ...
 * Return: ...
 */
int print_hexa_upper(va_list types, char buffer[],
	int fgs, int wd, int prn, int s)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		fgs, 'X', wd, prn, sz));
}
/**
 * print_hexa - ...
 * @types: ...
 * @map_to: ...
 * @buffer: ...
 * @fgs: ...
 * @fg_ch: ...
 * @wd: ...
 * @prn: ...
 * @size: ...
 * Return: ...
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int fgs, char fg_ch, int wd, int prn, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int y = va_arg(types, unsigned long int);
	unsigned long int init_y = y;

	UNUSED(wd);

	y = convert_size_unsgnd(y, size);

	if (y == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (y > 0)
	{
		buffer[x--] = map_to[y % 16];
		y /= 16;
	}

	if (fgs & F_HASH && init_y != 0)
	{
		buffer[x--] = fg_ch;
		buffer[x--] = '0';
	}

	x++;

	return (write_unsgnd(0, x, buffer, fgs, wd, prn, size));
}
