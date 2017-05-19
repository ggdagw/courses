
# This is a comment line

CC=gcc
OBJS=macros.o
EXE=macros.exe

CFLAGS=-Wall
#CFLAGS+=-DDEBUG

all: $(EXE)

$(EXE) : $(OBJS)
	$(CC) $^ -o $@

$(OBJS) : %.o : %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean spotless

clean:
	\rm -f $(OBJS)

spotless: clean
	\rm -f $(EXE)
