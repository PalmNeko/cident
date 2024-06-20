
#include "tyctest.h"
#include "cident.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

TEST(wrap_open, basic)
{
	int fd;

	cident_set_error(1);
	fd = open("resource/for_wrap_read.txt", O_RDONLY);
	EXPECT_EQ(fd, -1);
	cident_set_error(2);
	fd = open("resource/for_wrap_read.txt", O_RDONLY);
	EXPECT_NE(fd, -1);
	close(fd);
	fd = open("resource/for_wrap_read.txt", O_RDONLY);
	EXPECT_EQ(fd, -1);
	fd = open("resource/for_wrap_read.txt", O_RDONLY);
	EXPECT_NE(fd, -1);
	close(fd);

	cident_set_open_error(1);
	fd = open("resource/for_wrap_read.txt", O_RDONLY);
	EXPECT_EQ(fd, -1);
	cident_set_open_error(2);
	fd = open("resource/for_wrap_read.txt", O_RDONLY);
	EXPECT_NE(fd, -1);
	close(fd);
	fd = open("resource/for_wrap_read.txt", O_RDONLY);
	EXPECT_EQ(fd, -1);
	fd = open("resource/for_wrap_read.txt", O_RDONLY);
	EXPECT_NE(fd, -1);
	close(fd);
}