#include "main.h"

/**
 * handle_write_char - ...
 * @c: ...
 * @buffer: ...
 * @flags:  ...
 * @width: ...
 * @precision: ..
 * @size: ...
 * Return: ...
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = 0;
	char b = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		b = '0';

	buffer[a++] = c;
	buffer[a] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			buffer[BUFF_SIZE - a - 2] = b;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - a - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - a - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - ...
 * @is_negative: ...
 * @ind: ...
 * @buffer: ...
 * @flags:  ...
 * @width: ...
 * @precision: ...
 * @size: ...
 * Return: ...
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - ind - 1;
	char b = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		b = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		a, b, extra_ch));
}

/**
 * write_num - ...
 * @ind: ...
 * @buffer: ...
 * @flags: ...
 * @width: ...
 * @prec: ...
 * @length: ...
 * @padd: ...
 * @extra_c: ...
 * Return: ...
 */
int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int a, b = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (a = 1; a < width - length + 1; a++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], a - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], a - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--b] = extra_c;
			return (write(1, &buffer[b], a - b) +
				write(1, &buffer[ind], length - (1 - b)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - ...
 * @is_negative: ...
 * @ind: ...
 * @buffer: ...
 * @flags: ...
 * @width: ...
 * @precision: ...
 * @size: ...
 * Return: ...
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - ind - 1, b = 0;
	char x = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < a)
		x = ' ';

	while (precision > a)
	{
		buffer[--ind] = '0';
		a++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		x = '0';

	if (width > a)
	{
		for (b = 0; b < width - a; b++)
			buffer[i] = x;

		buffer[b] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], a) + write(1, &buffer[0], b));
		}
		else
		{
			return (write(1, &buffer[0], b) + write(1, &buffer[ind], a));
		}
	}

	return (write(1, &buffer[ind], a));
}

/**
 * write_pointer - ...
 * @buffer: ...
 * @ind: ...
 * @length: ...
 * @width: ...
 * @flags: ...
 * @padd: ...
 * @extra_c: ...
 * @padd_start: ...
 * Return: ...
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int a;

	if (width > length)
	{
		for (a = 3; a < width - length + 3; a++)
			buffer[a] = padd;
		buffer[a] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], a - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], a - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], a - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
