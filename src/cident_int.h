
#ifndef CIDENT_INT_H
# define CIDENT_INT_H

# include <stdbool.h>

void	cident_int_next_malloc_error(void);
bool	cident_int_should_raise_malloc_error(void);
bool	cident_int_get_debug_mode(void);
bool	cident_int_should_raise_read_error(void);
void	cident_int_next_read_error(void);
bool	cident_int_should_raise_open_error(void);
void	cident_int_next_open_error(void);
bool	cident_int_should_raise_close_error(void);
void	cident_int_next_close_error(void);

#endif
