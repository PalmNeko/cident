
# Installation

## Requirements

 * You must installed make for build.
 * You can link with ld by `--wrap` option.

## Download and Compile
 If you can installed `git`, can use bellow script.
```
bash -c $(curl https://raw.githubusercontent.com/PalmNeko/cident/main/install.sh)
```
This script compile this project and create `libcident.a`.

# Usage

## Requirements

Please install along [Installation](#installation).

## Build and Link

You have to append options.
manual:
	for build: `-Icident`
	for link: `-Lcident -lcident -Wl,--wrap=malloc,--wrap=open,--wrap=close,--wrap=read`
You will have any projects.
If you build with clang and gcc, you can build it as follow:
### for GCC example
ex.directories:
main.c
you_some.c
cident
```
CFLAGS="-Icident"
LDFLAGS="-Lcident -Wl,--wrap=malloc,--wrap=open,--wrap=close,--wrap=read"
LDLIBS="-lcident"
gcc -c $CFLAGS -o main.o main.c
gcc -c $CFLAGS -o you_some.o you_some.c
gcc -o a.out $LDFLAGS main.o you_some.o $LDLIBS
```
more sample here: `sample` directory.

## Getting Started

This section explain simple usage with this library.

First sample.
```
#include <stdlib.h>
#include "ciden.h"

int	main(void)
{
	ciden_set_debug(true); # enable debug
	free(malloc(30));
	return (0);
}
```
