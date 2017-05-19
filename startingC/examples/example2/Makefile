# A simple makefile to compile hello.c

CC=gcc
CFLAGS=
LDFLAGS=-lm

OBJS1=types.o
OBJS2=operations.o
OBJS=$(OBJS1) $(OBJS2)
EXE1=types.exe
EXE2=operations.exe
EXES=$(EXE1) $(EXE2)

all: $(EXES)

$(EXES) : %.exe : %.o
	$(CC) $^ $(LDFLAGS) -o $@

$(OBJS) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean spotless

clean:
	\rm -f $(OBJS)

spotless: clean
	\rm -f $(EXES)
