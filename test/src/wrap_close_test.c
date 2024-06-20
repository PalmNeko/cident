
#include "tyctest.h"
#include "cident.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

TEST(wrap_close, basic)
{
	int		fd;

	fd = open("resource/for_wrap_close.txt", O_RDONLY);

	cident_set_error(1);
	EXPECT_EQ(close(fd), -1);
	cident_set_error(3);
	EXPECT_EQ(close(fd), 0);

	fd = open("resource/for_wrap_close.txt", O_RDONLY);
	
    EXPECT_EQ(close(fd), -1);
	EXPECT_EQ(close(fd), 0);

	fd = open("resource/for_wrap_close.txt", O_RDONLY);
    
	cident_set_close_error(1);
	EXPECT_EQ(close(fd), -1);
	cident_set_close_error(2);
	EXPECT_EQ(close(fd), 0);

	fd = open("resource/for_wrap_close.txt", O_RDONLY);

	EXPECT_EQ(close(fd), -1);
	EXPECT_EQ(close(fd), 0);
}
