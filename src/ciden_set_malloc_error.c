
#include "ciden_int.h"

extern int	g_ciden_malloc_error;
/**
 * @brief set next error timing.
 * @param next_error Number of calls until next error. If set a zero, don't raise error.
 * If set a one, raise error at next call.
 */
void	ciden_set_malloc_error(int next_error)
{
	g_ciden_malloc_error = next_error;
}
