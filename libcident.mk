
NAME	= libcident.a
SRC_DIR	= src
SRCS	= $(shell find $(SRC_DIR) -name "cident*.c" -o -name "__wrap*.c")
OBJS	= $(SRCS:.c=.o)
DEPS	= $(OBJS:.o=.d)
CFLAGS += -Wall -Werror -Wextra -MMD -MP -I.

all: $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

show:
	@echo "CFLAGS: $(CFLAGS)"
	@echo "SRCS:"
	@echo "$(SRCS)"
	@echo "OBJS:"
	@echo "$(OBJS)"

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

-include $(DEPS)
