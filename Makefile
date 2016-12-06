DIR = `pwd`
CC  = gcc
CFLAGS = -Wall -Werror
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

$(TARGET):	build/main.o
		$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

build/main.o:	src/main.c
		$(CC) $(CFLAGS) -c -o $@ $^

test: testWord

testWord:	
		$(CC) $(CFLAGS) -o test/testWord test/wordTests.c lib/word.c
		test/testWord

clean:
		find $(BUILDDIR) -type f -not -name 'readme.txt' -delete
		find $(TESTDIR) -executable -type f -delete
		$(RM) $(TARGET)
