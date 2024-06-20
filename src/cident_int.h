
#ifndef CIDENT_INT_H
# define CIDENT_INT_H

# include <stdbool.h>

void	cident_int_next_error(void);
void	cident_int_next_malloc_error(void);
bool	cident_int_should_raise_malloc_error(void);
int		cident_int_printf_debug(const char *format, ...);
bool	cident_int_get_debug_mode(void);

#endif
