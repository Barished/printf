#include <unistd.h>
/**
 *write - writes a char to stdout
 *@c: character
 *Return: the character
 */

int _write(char c)
{
	return (write(1, &c, 1));
}
