
#include <stdbool.h>
#include "cident.h"

extern int	g_cident_open_error;

bool	cident_int_should_raise_open_error(void)
{
	return (cident_should_raise_error()
		|| g_cident_open_error == 1
	);
}
