
NAME		= cident_sample
SRC_DIR		= .
SRCS		= cident_sample.c
OBJS		= $(SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)
CFLAGS		= -Wall -Werror -Wextra -MMD -MP -Icident/src
LDLIBS		= -Lcident/src -lcident
LDFLAGS 	= -Wl,--wrap=malloc

LIBCIDEN	= cident

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

install: $(LIBCIDEN)

$(NAME): $(OBJS)

$(LIBCIDEN):
	git clone git@github.com:PalmNeko/cident.git cident
	cd cident \
	&& make

-include $(DEPS)
