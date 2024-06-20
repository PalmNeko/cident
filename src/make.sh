
SYMBOL="$1"
cd $(dirname $0)

echo '
bool	cident_int_should_raise_'$SYMBOL'_error(void);
void	cident_int_next_'$SYMBOL'_error(void);
' >> cident_int.h

echo '
void	cident_set_'$SYMBOL'_error(int next_error);
' >> ../cident.h

echo '
int	g_cident_'$SYMBOL'_error = 0;
' >> ./cident_int_global.c

echo '

#include <errno.h>
#include "cident_int.h"
#include "cident.h"

__real_'$SYMBOL'();

__wrap_'$SYMBOL'()
{
	result;

	if (cident_int_should_raise_'$SYMBOL'_error())
	{
        errno = ;
		result = -1;
	}
	else {
		result = __real_'$SYMBOL'();
	}
	cident_int_next_'$SYMBOL'_error();
	cident_printf_debug("'$SYMBOL': ret: %zd\n", result);
	return (result);
}
' > __wrap_${SYMBOL}.c

NEW_NEXT="cident_int_next_${SYMBOL}_error.c"
NEW_RAISE="cident_int_should_raise_${SYMBOL}_error.c"
NEW_SET="cident_set_${SYMBOL}_error.c"

cp cident_int_next_malloc_error.c "$NEW_NEXT"
cp cident_int_should_raise_malloc_error.c "$NEW_RAISE"
cp cident_set_malloc_error.c "$NEW_SET"

sed -i "s/malloc/$SYMBOL/g" $NEW_NEXT
sed -i "s/malloc/$SYMBOL/g" $NEW_RAISE
sed -i "s/malloc/$SYMBOL/g" $NEW_SET
