
#include "cident.h"

extern int	g_cident_read_error;

void	cident_int_next_read_error(void)
{
	cident_next_error();
	if (g_cident_read_error > 0)
		g_cident_read_error -= 1;
	return;
}
