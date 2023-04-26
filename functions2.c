#include "main.h"
/**
 * print_pointer - ...
 * @types: ...
 * @buffer: ...
 * @fgs: ...
 * @wd: ...
 * @precsn: ...
 * @sz: ...
 * Return: ...
 */
int print_pointer(va_list types, char buffer[],
	int fgs, int wd, int precsn, int sz)
{
	char extra_x = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_start = 1;
	unsigned long y_addrs;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(wd);
	UNUSED(sz);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precsn);

	y_address = (unsigned long)address;

	while (y_address > 0)
	{
		buffer[ind--] = map_to[y_address % 16];
		y_address /= 16;
		len++;
	}

	if ((fgs & F_ZERO) && !(fgs & F_MINUS))
		padd = '0';
	if (fgs & F_PLUS)
		extra_c = '+', len++;
	else if (fgs & F_SPACE)
		extra_c = ' ', len++;

	ind++;

	return (write_pointer(buffer, ind, len,
		wd, fgs, padd, extra_c, padd_start));
}

/**
 * print_non_printable - ...
 * @types: ...
 * @buffer: ...
 * @fgs: ...
 * @wd: ...
 * @precsn: ...
 * @size: ...
 * Return: ...
 */
int print_non_printable(va_list types, char buffer[],
	int fgs, int wd, int precsn, int size)
{
	int y = 0, offset = 0;
	char *c = va_arg(types, char *);

	UNUSED(fgs);
	UNUSED(wd);
	UNUSED(precsn);
	UNUSED(size);

	if (c == NULL)
		return (write(1, "(null)", 6));

	while (c[y] != '\0')
	{
		if (is_printable(c[y]))
			buffer[y + offset] = c[y];
		else
			offset += append_hexa_code(c[y], buffer, y + offset);

		y++;
	}

	buffer[y + offset] = '\0';

	return (write(1, buffer, y + offset));
}

/**
 * print_reverse - ...
 * @typ: ...
 * @b: ...
 * @f: ...
 * @w: ...
 * @precisn: ...
 * @size: ...
 * Return: ...
 */

int print_reverse(va_list typ, char b[],
	int f, int w, int precisn, int size)
{
	char *c;
	int x, count = 0;

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(size);

	c = va_arg(typ, char *);

	if (c == NULL)
	{
		UNUSED(precisn);

		c = ")Null(";
	}
	for (x = 0; c[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		char z = c[x];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * print_rot13string - ...
 * @typ: ...
 * @bufr: ...
 * @f: ...
 * @w: ...
 * @precsn: ...
 * @size: ...
 * Return: ...
 */
int print_rot13string(va_list typ, char bufr[],
	int f, int w, int precsn, int size)
{
	char a;
	char *c;
	unsigned int b, d;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	c = va_arg(typ, char *);
	UNUSED(bufr);
	UNUSED(f);
	UNUSED(w);
	UNUSED(precsn);
	UNUSED(size);

	if (c == NULL)
		c = "(AHYY)";
	for (b = 0; c[b]; b++)
	{
		for (d = 0; in[d]; d++)
		{
			if (in[d == c[b]])
			{
				a = out[d];
				write(1, &a, 1);
				count++;
				break;
			}
		}
		if (!in[d])
		{
			a = c[b];
			write(1, &a, 1);
			count++;
		}
	}
	return (count);
}
