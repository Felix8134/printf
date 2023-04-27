#include "main.h"


/**
 * print_char - ...
 * @types: ...
 * @buffer: ...
 * @a:  ...
 * @b: ...
 * @d: ...
 * @e: ...
 * Return: ...
 */
int print_char(va_list types, char buffer[],
	int a, int b, int d, int e)
	;
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, a, b, d, e));
}

/**
 * print_string - ..
 * @types: ...
 * @buffer: ...
 * @a:  ...
 * @b: ...
 * @d: ...
 * @e: ...
 * Return: ...
 */
int print_string(va_list types, char buffer[],
	int a, int b, int d, int e)
{
	int x = 0, y;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(a);
	UNUSED(b);
	UNUSED(d);
	UNUSED(e);
	if (str == NULL)
	{
		str = "(null)";
		if (d >= 6)
			str = "      ";
	}

	while (str[x] != '\0')
		x++;

	if (d >= 0 && d < x)
		x = d;

	if (b > x)
	{
		if (a & F_MINUS)
		{
			write(1, &str[0], x);
			for (y = b - x; i > 0; y--)
				write(1, " ", 1);
			return (b);
		}
		else
		{
			for (y = b - x; y > 0; y--)
				write(1, " ", 1);
			write(1, &str[0], x);
			return (b);
		}
	}

	return (write(1, str, x));
/*
 * print_percent - ...
 * @types: ...
 * @buffer: ...
 * @a: ...
 * @b: ....
 * @d: ...
 * @e: ...
 * Return: ...
 */
int print_percent(va_list types, char buffer[],
	int a, int b, int d, int e)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(a);
	UNUSED(b);
	UNUSED(d);
	UNUSED(e);
	return (write(1, "%%", 1));
}

/**
 * print_int - ...
 * @types: ...
 * @buffer: ...
 * @flags:  ...
 * @width: ...
 * @precision: ...
 * @size: ...
 * Return: ...
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}


/**
 * print_binary - ...
 * @types: ...
 * @buffer: ...
 * @a:  ...
 * @b: ...
 * @d: ...
 * @e: ...
 * Return: ...
 */
int print_binary(va_list types, char buffer[],
	int a, int b, int d, int e)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(a);
	UNUSED(b);
	UNUSED(d);
	UNUSED(e);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

