
#include "ciden_int.h"

extern int	g_ciden_malloc_error;

void	ciden_int_next_malloc_error(void)
{
	ciden_int_next_error();
	if (g_ciden_malloc_error > 0)
		g_ciden_malloc_error -= 1;
	return;
}
