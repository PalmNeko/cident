
#include <stdbool.h>

extern int	g_cident_malloc_error;
extern int	g_cident_error;

bool	cident_int_should_raise_malloc_error(void)
{
	return (
		g_cident_malloc_error == 1
		|| g_cident_error == 1
	);
}
