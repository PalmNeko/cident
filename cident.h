
#ifndef LIBCIDENT_H
# define LIBCIDENT_H

# include <stdbool.h>

void	cident_set_debug(bool is_debug);
bool	cident_should_raise_error(void);
void	cident_next_error(void);
void	cident_set_malloc_error(int next_error);
void	cident_set_error(int next_error);
int		cident_printf_debug(const char *format, ...);
void	cident_set_read_error(int next_error);
void	cident_set_open_error(int next_error);

#endif
