#include "main.h"

/**
 * var_point - prints value of a pointer variable
 *
 * @types: list type of arguments
 * @buffer: handle the buffer array
 * @flags: calculates active flags
 * @width: get width option
 * @precision: precision format specification
 * @size: size format specifier
 * return: number of chars printed
 */
int var_point(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;

	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
	return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (num_pointer(buffer, ind, lenght,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - prints ascii codes in hexa of non printable chars
 * @types: list types of arguments
 * @buffer: handle the buffer array
 * @flags: calculates active flags
 * @width: gets width options
 * @precision: precision format specification
 * @size: size format specifier
 * return: number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (to_print(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += hexa_append(str[i], buffer, i = offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - print reverse string
 * @types: list types of arguments
 * @buffer: handle buffer array
 * @flags: calculate active flags
 * @width: get width option
 * @precision: precision format specification
 * @size: size format specifier
 * return: number of chars printed
 */
int print_reverse(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
	char *str;
        int i, count = 0;

        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str == "NULL";
	}
	for (i = 0; str[i]; i++);
	for (i = i - 1; i >= 0; i--)
	{
	       	char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * rotstr13_p - print a string in rot13
 * @types: list types of arguments
 * @buffer: handle buffer array
 * @flags: calculate active flags
 * @width: get width option
 * @precision: precision format specification
 * @size: size format specifier
 * return: number of chars printed
 */

int rotstr13(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
	char x;
        char *str;
	unsigned int i, j;
        int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
	char out[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

	str = va_arg(types, char *);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

        if (str == NULL)
		str = "(null)";
	for (i = 0; str(i); i++)
	{
		if (in[j] == str[i])
		{
			x = out[j];
			write(1, &x, 1);
			count++;
			break;
		}
	}
	if (!in[j])
	{
		x = str[i];
		write(1, &x, 1);
		count++;
	}
	} 
	return (count);
}
