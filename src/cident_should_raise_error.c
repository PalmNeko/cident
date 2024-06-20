
#include <stdbool.h>

extern int	g_cident_error;

bool	cident_should_raise_error(void)
{
	return (g_cident_error == 1);
}
