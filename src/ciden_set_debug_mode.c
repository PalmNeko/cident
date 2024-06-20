
#include <stdbool.h>

extern int	g_ciden_debug_mode;

void	ciden_set_debug(bool debug_mode)
{
	g_ciden_debug_mode = debug_mode;
}
