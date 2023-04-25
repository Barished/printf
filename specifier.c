#include "main.h"

int (*specifier(char c))(va_list)
{
	if (c == 'd' || c == 'i')
		return (print_integer);
	else if (c == 's')
		return (print_string);
	else if (c == 'c')
		return (print_char);
	else if (c == '%')
		return (print_percent);
	else
		return (NULL);
}
