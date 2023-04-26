#ifndef MAIN_H
#define MAIN_H

#define BUFSIZE 1024

/* Importing Libraries */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/* Type Definitions */

/**
 * struct printer - structure for printing various types
 * @symbol: type to print
 * @func_t: function to print
 */

typedef struct printer
{
	const char symbol;
	int (*func_t)(va_list);
} printer_t;

/* Function Prototypes */

int _write(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(__attribute__((unused))va_list args);
int print_i(va_list args);
int print_d(va_list args);
int (*specifier(const char s))(va_list);
int print_integer(va_list args);
int print_decimal(va_list args);
int binary_recursive(unsigned int num, int lenght);
int print_binary(va_list count);
int print_unint(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
int print_octal(va_list args);
int rot13(va_list args);
char *_memcpy(char *dest, char *src, unsigned int n);
char *rev_str(char *s);
int print_reversed(va_list args);
int (*func_t)(va_list);

#endif /* _MAIN_H_ */
