
#include <stdbool.h>
#include "cident.h"

extern int	g_cident_read_error;

bool	cident_int_should_raise_read_error(void)
{
	return (cident_should_raise_error()
		|| g_cident_read_error == 1
	);
}
