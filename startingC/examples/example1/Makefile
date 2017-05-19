# A simple makefile to compile hello.c

CC=gcc
OBJS=hello.o
EXE=hello.exe
CFLAGS=-Wall

all: $(EXE)

$(EXE) : $(OBJS)
	$(CC) $^ -o $@

$(OBJS) : %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean spotless

clean:
	\rm -f $(OBJS)

spotless: clean
	\rm -f $(EXE)
