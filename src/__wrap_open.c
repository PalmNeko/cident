

#include <errno.h>
#include <stdarg.h>
#include <fcntl.h>
#include "cident_int.h"
#include "cident.h"

int	__real_open(const char *path, int oflag, ...);

int	__wrap_open(const char *path, int oflag, ...)
{
	va_list arg;
	int		fd;
    int		mode;

	mode = 0;
	if (cident_int_should_raise_open_error())
	{
        errno = EIO;
		fd = -1;
	}
	else if (__OPEN_NEEDS_MODE (oflag))
    {
    	va_start (arg, oflag);
    	mode = va_arg (arg, int);
    	va_end (arg);
		fd = __real_open(path, oflag, mode);
		cident_printf_debug("open: fd: %d path: %s oflag: %d mode: %d\n",
			fd, path, oflag, mode);
    }
	else
	{
		fd = __real_open(path, oflag);
		cident_printf_debug("open: fd: %d path: %s oflag: %d\n",
			fd, path, oflag);
	}
	cident_int_next_open_error();
	return (fd);
}

