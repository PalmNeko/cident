
#include "tyctest.h"
#include "cident.h"
#include <stdlib.h>

TEST(wrap_malloc, basic)
{
	void	*ptr;

	cident_set_error(1);
	ptr = malloc(10);
	EXPECT_EQ(ptr, NULL);
	cident_set_error(2);
	ptr = malloc(10);
	EXPECT_NE(ptr, NULL);
	free(ptr);
	ptr = malloc(10);
	EXPECT_EQ(ptr, NULL);
	ptr = malloc(10);
	EXPECT_NE(ptr, NULL);
	free(ptr);

	cident_set_malloc_error(1);
	ptr = malloc(10);
	EXPECT_EQ(ptr, NULL);
	cident_set_malloc_error(2);
	ptr = malloc(10);
	EXPECT_NE(ptr, NULL);
	free(ptr);
	ptr = malloc(10);
	EXPECT_EQ(ptr, NULL);
	ptr = malloc(10);
	EXPECT_NE(ptr, NULL);
	free(ptr);
}