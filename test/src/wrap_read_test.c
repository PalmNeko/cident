
#include "tyctest.h"
#include "cident.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

TEST(wrap_read, basic)
{
	int		fd;
	char	buf[32];

	fd = open("resource/for_wrap_read.txt", O_RDONLY);

	cident_set_error(1);
	EXPECT_EQ(read(fd, buf, 1), -1);
	cident_set_error(2);
	EXPECT_EQ(read(fd, buf, 1), 1);
	EXPECT_EQ(read(fd, buf, 1), -1);
	EXPECT_EQ(read(fd, buf, 1), 1);
	EXPECT_EQ(buf[0], '2');

	cident_set_read_error(1);
	EXPECT_EQ(read(fd, buf, 1), -1);
	cident_set_read_error(2);
	EXPECT_EQ(read(fd, buf, 1), 1);
	EXPECT_EQ(read(fd, buf, 1), -1);
	EXPECT_EQ(read(fd, buf, 1), 1);
	EXPECT_EQ(buf[0], '4');
	close(fd);
}