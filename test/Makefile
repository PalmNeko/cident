
NAME		= tester
CC			= cc
SRC_DIR		= src
SRCS		= $(shell find $(SRC_DIR) -name "*.c")
OBJS		= $(SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)
CFLAGS		= -Wall -Werror -Wextra -MMD -MP -I../src -Iincludes/tyctest
LDLIBS		= -Llibs -L../src -ltyctest_main -ltyctest -lcident
LDFLAGS 	= -Wl,--wrap=malloc -Wl,--wrap=read

LIBCIDEN	= cident
LIBTYCTEST	= libs/libtyctest_main.a

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	make -C ../src clean

fclean: clean
	$(RM) $(NAME)
	make -C ../src fclean

uninstall:
	rm -rf includes libs bin
	rm -rf cident

re: fclean all

debug: CFLAGS += -g -O0
debug: re

$(NAME): $(LIBCIDEN) $(LIBTYCTEST) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

$(LIBCIDEN):
	CFLAGS="$(CFLAGS)" make -C ../src

$(LIBTYCTEST):
	@bash -c "$$(curl https://raw.githubusercontent.com/PalmNeko/tyCtest_tool/master/install.sh)"

-include $(DEPS)
