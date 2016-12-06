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

$(TARGET):	build/main.o build/operations_container.o build/word.o
		$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

build/main.o:	src/main.c
		$(CC) $(CFLAGS) -c -o $@ $^

build/operations_container.o: src/operations_container.c src/operations_container.h
		$(CC) $(CFLAGS) -c -o $@ src/operations_container.c

build/word.o:	lib/word.c lib/word.h
		$(CC) $(CFLAGS) -c -o $@ lib/word.c
		
test: testWord

testWord:	
		$(CC) $(CFLAGS) -o test/testWord test/wordTests.c lib/word.c
		test/testWord

clean:
		find $(BUILDDIR) -type f -not -name 'readme.txt' -delete
		find $(TESTDIR) -executable -type f -delete
		$(RM) $(TARGET)
