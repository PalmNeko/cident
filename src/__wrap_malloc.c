
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include "ciden_int.h"

void	*__real_malloc(size_t size);

void	*__wrap_malloc(size_t size)
{
	void	*ptr;

	if (ciden_int_should_raise_malloc_error())
	{
		ciden_int_next_malloc_error();
		errno = ENOMEM;
		return (NULL);
	}
	ptr = __real_malloc(size);
	if (ptr == NULL)
		return (NULL);
	ciden_int_printf_debug("malloc: %p\n", ptr);
	return (ptr);
}