
#include <stdlib.h>
#include "cident.h"

int	main(void)
{
	cident_set_debug(true);
	free(malloc(30));
	return (0);
}
