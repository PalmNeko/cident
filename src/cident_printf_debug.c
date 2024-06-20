#include <stdio.h>
#include <stdarg.h>
#include "cident_int.h"

int	cident_printf_debug(const char *format, ...)
{
	va_list	ap;
	int		print_cnt;

	if (cident_int_get_debug_mode() == false)
		return (0);
	va_start(ap, format);
	print_cnt = vfprintf(stderr, format, ap);
	va_end(ap);
	return (print_cnt);
}
