#include "main.h"

/**
 * check_format - Checks if format specifier is valid
 * @spec: format specifier
 *
 * Return: 1 (SUCCESS), 0 (FAIL)
 **/
int check_format(char spec)
{
	int i;
	char *fmtspec = "csdiuoxXSprR";

	for (i = 0; fmtspec[i]; i++)
	{
		if (fmtspec[i] == spec)
			return (1);
	}
	return (0);
}

/**
 * get_fmt - Handles format specifiers
 * @spec: specifier
 *
 * Return: number of characters printed
 **/
int (*get_fmt(char spec))(va_list *, char *, int *)
{
	format_t formats[] = {
		{"c", handle_c}, {"s", handle_s}, {"d", handle_d}, {"i", handle_d},
		{"b", handle_b}, {"u", handle_u}, {"o", handle_o}, {"x", handle_x},
		{"X", handle_X}, {"S", NULL}, {"p", NULL}, {"r", NULL},
		{"R", NULL}, {NULL, NULL}
	};
	int i = 0;

	while (formats[i].spec != NULL)
	{
		if (spec == formats[i].spec[0])
			return (formats[i].handle);
		i++;
	}
	return (NULL);
}
