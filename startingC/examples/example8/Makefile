
# This is a comment line

CC=gcc
OBJS=main.o calcs.o io.o
HDRS=calcs.h io.h main.h
EXE=structures.exe
CFLAGS=-Wall
LDFLAGS=-lm


all: $(EXE)

$(EXE) : $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJS) : %.o : %.c $(HDRS) 
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean spotless

clean:
	\rm -f $(OBJS)

spotless: clean
	\rm -f $(EXE)
