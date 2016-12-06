DIR = `pwd`
CC  = gcc
CFLAGS = -Wall -Werror
LD = gcc
LDFLAGS =
LIBS =
OBJS =
TARGET = womp

BUILDDIR = $(DIR)/build
SRCDIR = $(DIR)/src
TESTDIR = $(DIR)/test

all:	$(TARGET)

$(TARGET):	build/main.o
		$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

build/main.o:	src/main.c
		$(CC) $(CFLAGS) -c -o $@ $^

clean:
		find $(BUILDDIR) -type f -not -name 'readme.txt' -delete
		rm -f $(TARGET)
