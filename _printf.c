#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - ...
 * @format: ...
 * Return: ...
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int fl, wd, pr, s, buff_ind = 0;
	va_list l;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(l, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			fl = get_fl(format, &a);
			wd = get_wd(format, &a, list);
			pr = get_pr(format, &a, list);
			size = get_size(format, &a);
			++a;
			printed = handle_print(format, &a, list, buffer,
				fl, wd, pr, s);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - ...
 * @buffer: ...
 * @buff_ind: ...
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
