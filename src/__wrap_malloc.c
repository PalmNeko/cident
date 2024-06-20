
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include "cident_int.h"
#include "cident.h"

void	*__real_malloc(size_t size);

void	*__wrap_malloc(size_t size)
{
	void	*ptr;

	if (cident_int_should_raise_malloc_error())
	{
		errno = ENOMEM;
		ptr = NULL;
	}
	else
		ptr = __real_malloc(size);
	cident_int_next_malloc_error();
	cident_printf_debug("malloc: %p\n", ptr);
	return (ptr);
}
