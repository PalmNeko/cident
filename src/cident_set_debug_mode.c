
#include <stdbool.h>

extern int	g_cident_debug_mode;

void	cident_set_debug(bool debug_mode)
{
	g_cident_debug_mode = debug_mode;
}
