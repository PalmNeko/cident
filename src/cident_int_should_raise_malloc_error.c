
#include <stdbool.h>
#include "cident.h"

extern int	g_cident_malloc_error;

bool	cident_int_should_raise_malloc_error(void)
{
	return (cident_should_raise_error()
		|| g_cident_malloc_error == 1
	);
}
