#include "main.h"

/**
 * print_octal - A function that prints an octal number
 * @n: unsigned integer to print in octal
 *
 * Return: number of characters printed
 */

int print_octal(unsigned int n)
{
	int count = 0;
	char *octal = convert_base(n, 8);

	while (octal[count])
	{
		_write(octal[count]);
		count++;
	}

	free(octal);
	return (count);
}

/**
 * print_hexadecimal - A function that prints a hexadecimal number
 * @n: unsigned integer to print in hexadecimal
 * @uppercase: flag to indicate whether to print in uppercase
 *
 * Return: number of characters printed
 */

int print_hexadecimal(unsigned int n, int uppercase)
{
	int count = 0;
	char *hex = convert_base(n, 16);

	if (uppercase)
		hex = convert_to_uppercase(hex);

	while (hex[count])
	{
		_write(hex[count]);
		count++;
	}

	free(hex);
	return (count);
}

/**
 * rot13 - Encodes a string using the ROT13 cipher.
 * @args: A va_list pointing to the string to be encoded.
 *
 * Return: The number of characters printed.
 */
int rot13(va_list args)
{
	int i, j;
	int count = 0;
	char *str = va_arg(args, char *);
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; input[j] != '\0'; j++)
		{
			if (str[i] == input[j])
			{
				_write(output[j]);
				count++;
				break;
			}
		}
		if (input[j] == '\0')
		{
			_write(str[i]);
			count++;
		}
	}
	return (count);
}
/**
 * convert_base - converts an unsigned int to a given base
 * @num: the number to convert
 * @base: the base to convert to
 *
 * Return: a pointer to a string containing the converted number
 */
char *convert_base(unsigned int num, int base)
{
	char *str = malloc(sizeof(char) * 33);
	char *digits = "0123456789abcdef";
	int i = 0;

	if (str == NULL)
		return (NULL);

	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	while (num != 0)
	{
		str[i++] = digits[num % base];
		num /= base;
	}

	str[i] = '\0';

	reverse_string(str);

	return (str);
}
/**
 * convert_to_uppercase - Converts a string to all uppercase characters
 * @str: The string to convert
 *
 * Return: A pointer to the converted string
 */
char *convert_to_uppercase(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}

	return (str);
}
