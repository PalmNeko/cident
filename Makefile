
LIBCIDEN = src/libciden.a
all: $(LIBCIDEN)

clean:
	make -f libcident.mk clean

fclean:
	make -f libcident.mk fclean

re: fclean all

$(LIBCIDEN):
	make -f libcident.mk
