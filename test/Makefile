
NAME		= tester
CC			= cc
SRC_DIR		= src
SRCS		= $(shell find $(SRC_DIR) -name "*.c")
OBJS		= $(SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)
CFLAGS		= -Wall -Werror -Wextra -MMD -MP -I.. -Ityctest
LDFLAGS 	= -Ltyctest -L.. -Wl,--wrap=malloc -Wl,--wrap=read,--wrap=open,--wrap=close
LDLIBS		= -ltyctest -ltyctest_main -lcident

LIBCIDEN	= cident
LIBTYCTEST	= tyctest

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	make -C .. clean

fclean: clean
	$(RM) $(NAME)
	make -C .. fclean

re: fclean all

debug: CFLAGS += -g -O0
debug: re

show:
	@echo "SRCS:"
	@echo "$(SRCS)"
	@echo "OBJS:"
	@echo "$(OBJS)"
	@echo "CFLAGS: $(OBJS)"

$(NAME): $(LIBCIDEN) $(LIBTYCTEST) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

$(LIBCIDEN):
	CFLAGS="$(CFLAGS)" make -C ..

$(LIBTYCTEST):
	@bash -c "$$(curl https://raw.githubusercontent.com/PalmNeko/tyCtest_tool/master/install.sh)"

-include $(DEPS)
