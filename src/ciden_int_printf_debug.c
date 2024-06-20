#include <stdio.h>
#include <stdarg.h>
#include "ciden_int.h"

int	ciden_int_printf_debug(const char *format, ...)
{
	va_list	ap;
	int		print_cnt;

	if (ciden_int_get_debug_mode() == false)
		return (0);
	va_start(ap, format);
	print_cnt = vfprintf(stderr, format, ap);
	va_end(ap);
	return (print_cnt);
}
