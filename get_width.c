#include "main.h"
/**
 * get_width - ...
 * @fmt: ...
 * @a: ...
 * @ls: ...
 * Return: width
 */
int get_width(const char *fmt, int *a, va_list ls)
{
	int curr_a;
	int width = 0;

	for (curr_a = *a + 1; fmt[curr_a] != '\0'; curr_a++)
	{
		if (is_digit(fmt[curr_a]))
		{
			width *= 10;
			width += fmt[curr_a] - '0';
		}
		else if (fmt[curr_a] == '*')
		{
			curr_a++;
			width = va_arg(ls, int);
			break;
		}
		else
			break;
	}

	*a = curr_a - 1;

	return (width);
}
