
LIBCIDEN = src/libciden.a
all: $(LIBCIDEN)

$(LIBCIDEN):
	make -C src
