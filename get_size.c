#include "main.h"
/**
 * get_size - ...
 * @fmt: ...
 * @l: ...
 * Return: Precision.
 */
int get_size(const char *fmt, int *l)
{
	int curr_l = *l + 1;
	int size = 0;

	if (fmt[curr_l] == 'l')
		size = S_LONG;
	else if (fmt[curr_l] == 'h')
		size = S_SHORT;

	if (size == 0)
		*l = curr_l - 1;
	else
		*l = curr_l;

	return (size);
}
