
#include <stdbool.h>

extern int	g_ciden_malloc_error;
extern int	g_ciden_error;

bool	ciden_int_should_raise_malloc_error(void)
{
	return (
		g_ciden_malloc_error == 1
		|| g_ciden_error == 1
	);
}
