
#ifndef CIDEN_INT_H
# define CIDEN_INT_H

# include <stdbool.h>

void	ciden_int_next_error(void);
void	ciden_int_next_malloc_error(void);
bool	ciden_int_should_raise_malloc_error(void);
int		ciden_int_printf_debug(const char *format, ...);
bool	ciden_int_get_debug_mode(void);

#endif
