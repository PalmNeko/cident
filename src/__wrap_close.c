

#include <errno.h>
#include "cident_int.h"
#include "cident.h"

int	__real_close(int fildes);

int	__wrap_close(int fildes)
{
	int result;

	if (cident_int_should_raise_close_error())
	{
        errno = EIO;
		result = -1;
	}
	else {
		result = __real_close(fildes);
	}
	cident_int_next_close_error();
	cident_printf_debug("close: ret: %d fd: %d\n", result, fildes);
	return (result);
}

