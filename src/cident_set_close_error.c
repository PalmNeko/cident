
#include "cident_int.h"

extern int	g_cident_close_error;
/**
 * @brief set next error timing.
 * @param next_error Number of calls until next error. If set a zero, don't raise error.
 * If set a one, raise error at next call.
 */
void	cident_set_close_error(int next_error)
{
	g_cident_close_error = next_error;
}
