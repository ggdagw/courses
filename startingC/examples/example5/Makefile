# A simple makefile to compile hello.c

CC=gcc
CFLAGS=-Wall
LDFLAGS=-lm

OBJS1=funcs1.o
OBJS2=fibonacci.o
OBJS=$(OBJS1) $(OBJS2)
EXE1=fibonacci.exe
EXE2=funcs1.exe
EXES=$(EXE1) $(EXE2)

all: $(EXES)

$(EXES) : %.exe : %.o
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJS) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean spotless

clean:
	\rm -f $(OBJS)

spotless: clean
	\rm -f $(EXES)
