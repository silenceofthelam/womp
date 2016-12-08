DIR = `pwd`
CC  = gcc
CFLAGS = -Wall -Werror -g
LD = gcc
LDFLAGS =
RM = rm -r -f
LIBS =
OBJS =
TARGET = womp

BUILDDIR = $(DIR)/build
SRCDIR = $(DIR)/src
TESTDIR = $(DIR)/test

all:	$(TARGET)

$(TARGET):	build/main.o build/operations_container.o build/string_manipulations.o build/womp.o build/running_config.o build/io.o
		$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

build/main.o:	src/main.c src/womp_defines.h
		$(CC) $(CFLAGS) -c -o $@ src/main.c

build/running_config.o:	src/running_config.h src/running_config.c
		$(CC) $(CFLAGS) -c -o $@ src/running_config.c

build/operations_container.o:	src/operations_container.h src/operations_container.c
		$(CC) $(CFLAGS) -c -o $@ src/operations_container.c

build/string_manipulations.o:	lib/string_manipulations.h lib/string_manipulations.c
		$(CC) $(CFLAGS) -c -o $@ lib/string_manipulations.c

build/io.o:	lib/io.c lib/io.h
		$(CC) $(CFLAGS) -c -o $@ lib/io.c

build/womp.o:	src/womp.h src/womp.c
		$(CC) $(CFLAGS) -c -o $@ src/womp.c

test: testStringMan

testStringMan:	
		$(CC) $(CFLAGS) -o test/testStringMan test/string_manipulationTests.c lib/string_manipulations.c
		test/testStringMan

clean:
		find $(BUILDDIR) -type f -not -name 'readme.txt' -delete
		find $(TESTDIR) -executable -type f -delete
		$(RM) $(TARGET)
