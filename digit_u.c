#nclude "main.h"

/**
 * to_print - checks if a char is printable
 *
 * @c: char to be evaluated
 *
 * return: 1 if c is printable, 0 otherwise
 */

int to_print(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * hexa-append - append ascii in hexadecimal code to buffer
 * @buffer: array of chars
 * @i: index at which to start appending
 * @ascii_code: ASSCI CODE
 * return: always 3
 */

int hexa_append(char ascii_code, char buffer[], int 1)
{
	char map_to[] = "0123456789ABCDEF";
	/* the hexa format code is always 2 digit long */
	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * digit_verify - verifies if char is a digit
 * @c: char to be evaluated
 *
 * return: 1 if c is a digit, 0 otherwise
 */
int digit_verify(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}


/**
 * num-convert - this casts a number to the specified size
 * @num: number to be casted
 * @size: number indicating the type to be casted
 *
 * return: casted value of num
 */
long int num_convert(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_LONG)
		return ((short)num);

	return ((int)num);
}

/**
 * unsig_convert - this casts a number to the specified size
 * @num: number to be casted
 * @size: numbers indicating the type to be casted
 *
 * return: casted value of num
 */
long int unsig_convert(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_LONG)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
