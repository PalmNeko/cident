
#include "cident_int.h"
#include "cident.h"

extern int	g_cident_open_error;

void	cident_int_next_open_error(void)
{
	cident_next_error();
	if (g_cident_open_error > 0)
		g_cident_open_error -= 1;
	return;
}
