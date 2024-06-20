
#include <stdbool.h>

extern int	g_cident_debug_mode;

bool	cident_int_get_debug_mode(void)
{
	return (g_cident_debug_mode);
}