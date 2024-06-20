
#include "cident_int.h"
#include "cident.h"

extern int	g_cident_malloc_error;

void	cident_int_next_malloc_error(void)
{
	cident_next_error();
	if (g_cident_malloc_error > 0)
		g_cident_malloc_error -= 1;
	return;
}
