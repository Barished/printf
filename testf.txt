#include "main.h"

/**
 * print_octal - prints an unsigned integer as octal
 * @args: va_list containing the unsigned integer to print
 *
 * Return: number of digits printed
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int i, count = 0;
	int octal[100];

	if (num == 0)
	{
		_write('0');
		return (1);
	}

	while (num > 0)
	{
		octal[count] = num % 8;
		num /= 8;
		count++;
	}

	for (i = count - 1; i >= 0; i--)
		_write(octal[i] + '0');

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
