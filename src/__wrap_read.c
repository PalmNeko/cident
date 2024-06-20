
#include <errno.h>
#include <unistd.h>
#include "cident_int.h"
#include "cident.h"

ssize_t	__real_read(int fildes, void *buf, size_t nbyte);

ssize_t	__wrap_read(int fildes, void *buf, size_t nbyte)
{
	ssize_t	result;

	if (cident_int_should_raise_read_error())
	{
		errno = EIO;
		result = -1;
	}
	else {
		result = __real_read(fildes, buf, nbyte);
	}
	cident_int_next_read_error();
	cident_printf_debug("read: ret: %zd fd: %d buf: %p byte: %zd\n",
			result, fildes, buf, nbyte);
	return (result);
}
