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

$(TARGET):	build/main.o build/operations_container.o build/word.o build/womp.o build/running_config.o
		$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

build/main.o:	src/main.c src/womp_defines.h
		$(CC) $(CFLAGS) -c -o $@ src/main.c

build/running_config.o:	src/running_config.h src/running_config.c
		$(CC) $(CFLAGS) -c -o $@ src/running_config.c
		

build/operations_container.o: src/operations_container.h src/operations_container.c
		$(CC) $(CFLAGS) -c -o $@ src/operations_container.c

build/word.o:	lib/word.h lib/word.c
		$(CC) $(CFLAGS) -c -o $@ lib/word.c
		
build/womp.o:	src/womp.h src/womp.c
		$(CC) $(CFLAGS) -c -o $@ src/womp.c
		
test: testWord

testWord:	
		$(CC) $(CFLAGS) -o test/testWord test/wordTests.c lib/word.c
		test/testWord

clean:
		find $(BUILDDIR) -type f -not -name 'readme.txt' -delete
		find $(TESTDIR) -executable -type f -delete
		$(RM) $(TARGET)
